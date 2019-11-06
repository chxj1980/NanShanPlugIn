// SIPPlugIn.cpp : 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"
#include "SIPPlugIn.h"
#include "SipService.h"
#include "h264_sps_parse.h"
#ifdef _WIN32
#include "AdaptersInfo.h"
#endif


#define RTP_BUF_SIZE		1024*100
#define FRAME_BUF_SIZE		1024*1024*2

static bool __bInit = false;
SipService& sip = acl::singleton2<SipService>::get_instance();

class init_thread : public acl::thread
{
protected:
	virtual void *run()
	{
		//windows获取物理IP
		AdaptersInfo addr;
#ifdef _WIN32
		addr.getIp(sip.m_conf.local_addr);
#endif
		//根据IP生成SIP编号
		sockaddr_in saddr;
		acl_inet_pton(AF_INET, sip.m_conf.local_addr, (sockaddr *)&saddr);
		srand(saddr.sin_addr.s_addr);
		acl::string strLocalCode(sip.m_conf.local_code,14);
		strLocalCode.format_append("%06d", rand());
		memcpy(sip.m_conf.local_code, strLocalCode.c_str(), strLocalCode.size());
		//启动服务
		char szLocalAddr[128] = { 0 };
		sprintf(szLocalAddr, "%s:%d", sip.m_conf.local_addr, sip.m_conf.local_port);
		sip.m_conf.log(LOG_INFO, "绑定地址[%s]成功!", szLocalAddr);
		sip.run_alone(szLocalAddr, NULL, 0);
		delete this;
		return NULL;
	}
};

class reconect_thread : public acl::thread
{
public:
	reconect_thread(SIPHandler *pParam)
	{
		pHandle = pParam;
	}
	~reconect_thread() {}
protected:
	virtual void *run()
	{
		if (pHandle)
		{
			if (pHandle->m_pStramCallback)
			{
				LPCAPTURESTREAMCALLBACK pCb = pHandle->m_pStramCallback;
				void *pUser = pHandle->m_pStreamUser;
				pHandle->stopCaptureStream();
				pHandle->captureStream(pCb, pUser, 0);
			}
			else
			{
				HWND hWnd = pHandle->m_hWnd;
				int nChannel = pHandle->m_nChannel;
				LPDRAWCBCALLLBACK pCb = pHandle->m_pDrawCallback;
				void *pUser = pHandle->m_pDrawUser;
				pHandle->stopPlayerByCamera(hWnd, nChannel);
				pHandle->startPlayer2(hWnd, pCb, pUser);
				pHandle->startPlayerByCamera(hWnd, nChannel);
			}
		}
		delete this;
		return NULL;
	}
public:
	SIPHandler *pHandle;
};

#ifdef _FOR_RTS_USE
class analyze_thread : public acl::thread
{
public:
	analyze_thread(int nType, LPCAPTURESTREAMCALLBACK pCb, void *pUser)
	{
		pStreamCb = pCb;
		pStreamUser = pUser;
		nStreamType = nType;
		nTimestamp = 0;
		nfreq = 3600;
		pFifo = acl_fifo_new();
		pCodec = 0;
		nUsec = 0;
		b4K = false;
		bFirstData = true;
		bBuffer = false;
		bStop = false;
	}
	~analyze_thread()
	{
		stop();
	}
public:
	void add_data(unsigned char *buffer, size_t bufsize)
	{
		lockerFifo.lock();
		if (!bStop && pFifo)
		{
			if (nStreamType == -1)
			{
				lockerFifo.unlock();
				return;
			}
			unsigned char *pBuf = (unsigned char *)acl_mymalloc(bufsize + sizeof(size_t));
			memcpy(pBuf, &bufsize, sizeof(size_t));
			memcpy(pBuf + sizeof(size_t), buffer, bufsize);
			acl_fifo_push(pFifo, pBuf);
		}
		lockerFifo.unlock();
	}
	void stop()
	{
		bStop = true;
	}
	void analyze_h264(unsigned char *pBuffer, unsigned int nBufferSize)
	{
		//printf("frame packet:%x %x %x %x %x %x\n", (BYTE)pBuffer[0], (BYTE)pBuffer[1], (BYTE)pBuffer[2], (BYTE)pBuffer[3], (BYTE)pBuffer[4], (BYTE)pBuffer[5]);
		if ((BYTE)pBuffer[0] == 0 && (BYTE)pBuffer[1] == 0 && (BYTE)pBuffer[2] == 0 && (BYTE)pBuffer[3] == 1 && ((BYTE)pBuffer[4] & 0x1f) == 7) //SPS
		{
			if (nFrameSize > 0)
			{
				if (pStreamCb)
					pStreamCb(nTimestamp+=3600, 2, szFrameData, nFrameSize, pStreamUser);
				//printf("frame packet:%x %x %x %x %x %x len:%d\n", (BYTE)szFrameData[0], (BYTE)szFrameData[1], (BYTE)szFrameData[2], (BYTE)szFrameData[3], (BYTE)szFrameData[4], (BYTE)szFrameData[5], nFrameSize);
				nFrameSize = 0;
			}
			memcpy(szFrameData + nFrameSize, pBuffer, nBufferSize);
			nFrameSize += nBufferSize;
			if (nUsec == 0)
			{
				int nWidth, nHeight;
				float fFps = 25;
				h264_sps_parse(pBuffer + 4, nBufferSize - 4, nWidth, nHeight, fFps);
				printf("当前媒体流分辨率为%d x %d,帧率为:%d\n", nWidth, nHeight, (int)fFps);
				if (nWidth > 1920 && nHeight > 1080)
					b4K = true;
				nUsec = 1000 / fFps - 10;
				nfreq = 90000 / fFps;
			}
			sip_sleep(nUsec);

		}
		else if ((BYTE)pBuffer[0] == 0 && (BYTE)pBuffer[1] == 0 && (BYTE)pBuffer[2] == 0 && (BYTE)pBuffer[3] == 1 && ((BYTE)pBuffer[4] & 0x1f) == 8) //PPS
		{
			if (nFrameSize + nBufferSize >= FRAME_BUF_SIZE)
			{
				printf("组帧PPS时超出缓冲[%d],丢弃!\n", nFrameSize + nBufferSize);
				return;
			}
			memcpy(szFrameData + nFrameSize, pBuffer, nBufferSize);
			nFrameSize += nBufferSize;
		}
		else if ((BYTE)pBuffer[0] == 0 && (BYTE)pBuffer[1] == 0 && (BYTE)pBuffer[2] == 0 && (BYTE)pBuffer[3] == 1 && ((BYTE)pBuffer[4] & 0x1f) == 5) //IDR
		{
			if (nFrameSize + nBufferSize >= FRAME_BUF_SIZE)
			{
				printf("组帧IDR时超出缓冲[%d],丢弃!\n", nFrameSize + nBufferSize);
				nFrameSize = 0;
			}
			memcpy(szFrameData + nFrameSize, pBuffer, nBufferSize);
			nFrameSize += nBufferSize;
		}
		else if ((BYTE)pBuffer[0] == 0 && (BYTE)pBuffer[1] == 0 && (BYTE)pBuffer[2] == 0 && (BYTE)pBuffer[3] == 1 && ((BYTE)pBuffer[4] & 0x1f) == 1) //PDR
		{
			if (nFrameSize > 0)
			{
				if (pStreamCb)
					pStreamCb(nTimestamp += 3600, 2, szFrameData, nFrameSize, pStreamUser);
				//printf("frame packet:%x %x %x %x %x %x len:%d\n", (BYTE)szFrameData[0], (BYTE)szFrameData[1], (BYTE)szFrameData[2], (BYTE)szFrameData[3], (BYTE)szFrameData[4], (BYTE)szFrameData[5], nFrameSize);
				nFrameSize = 0;
			}
			memcpy(szFrameData + nFrameSize, pBuffer, nBufferSize);
			nFrameSize += nBufferSize;
			sip_sleep(nUsec);

		}
		else if ((BYTE)pBuffer[0] == 0 && (BYTE)pBuffer[1] == 0 && (BYTE)pBuffer[2] == 0 && (BYTE)pBuffer[3] == 1 && ((BYTE)pBuffer[4] & 0x1f) == 6) //SEI
		{
			return;
		}
		else if ((BYTE)pBuffer[0] == 0 && (BYTE)pBuffer[1] == 0 && (BYTE)pBuffer[2] == 0 && (BYTE)pBuffer[3] == 1 && ((BYTE)pBuffer[4] & 0x1f) == 9) //EOF
		{
			return;
		}
		else
		{
			if (nFrameSize + nBufferSize >= FRAME_BUF_SIZE)
			{
				printf("组帧PDR时超出缓冲[%d],丢弃!\n", nFrameSize + nBufferSize);
				return;
			}
			memcpy(szFrameData + nFrameSize, pBuffer, nBufferSize);
			nFrameSize += nBufferSize;
		}
	}

	void analyze_h265(unsigned char *pBuffer, unsigned int nBufferSize)
	{
		if ((BYTE)pBuffer[0] == 0 && (BYTE)pBuffer[1] == 0 && (BYTE)pBuffer[2] == 0 && (BYTE)pBuffer[3] == 1 && ((BYTE)pBuffer[4] & 0x7e) >> 1 == 32) //VPS
		{
			if (nFrameSize > 0)
			{
				if (pCodec > 0)
					hevc2avc_input(pCodec, szFrameData, nFrameSize);
				nFrameSize = 0;
			}
			memcpy(szFrameData + nFrameSize, pBuffer, nBufferSize);
			nFrameSize += nBufferSize;
		}
		else if ((BYTE)pBuffer[0] == 0 && (BYTE)pBuffer[1] == 0 && (BYTE)pBuffer[2] == 0 && (BYTE)pBuffer[3] == 1 && ((BYTE)pBuffer[4] & 0x7e) >> 1 == 33) //SPS
		{
			if (nFrameSize + nBufferSize >= FRAME_BUF_SIZE)
			{
				printf("组帧SPS时超出缓冲[%d]\n", nFrameSize + nBufferSize);
				nFrameSize = 0;
			}
			memcpy(szFrameData + nFrameSize, pBuffer, nBufferSize);
			nFrameSize += nBufferSize;
		}
		else if ((BYTE)pBuffer[0] == 0 && (BYTE)pBuffer[1] == 0 && (BYTE)pBuffer[2] == 0 && (BYTE)pBuffer[3] == 1 && ((BYTE)pBuffer[4] & 0x7e) >> 1 == 34) //PPS
		{
			if (nFrameSize + nBufferSize >= FRAME_BUF_SIZE)
			{
				printf("组帧PPS时超出缓冲[%d]\n", nFrameSize + nBufferSize);
				return;
			}
			memcpy(szFrameData + nFrameSize, pBuffer, nBufferSize);
			nFrameSize += nBufferSize;
		}
		else if ((BYTE)pBuffer[0] == 0 && (BYTE)pBuffer[1] == 0 && (BYTE)pBuffer[2] == 0 && (BYTE)pBuffer[3] == 1 && ((BYTE)pBuffer[4] & 0x7e) >> 1 == 19) //IDR
		{
			if (nFrameSize + nBufferSize >= FRAME_BUF_SIZE)
			{
				printf("组帧IDR时超出缓冲[%d]\n", nFrameSize + nBufferSize);
				nFrameSize = 0;
			}
			memcpy(szFrameData + nFrameSize, pBuffer, nBufferSize);
			nFrameSize += nBufferSize;
		}
		else if ((BYTE)pBuffer[0] == 0 && (BYTE)pBuffer[1] == 0 && (BYTE)pBuffer[2] == 0 && (BYTE)pBuffer[3] == 1 && ((BYTE)pBuffer[4] & 0x7e) >> 1 == 1) //PDR
		{
			if (nFrameSize > 0)
			{
				if (pCodec > 0)
					hevc2avc_input(pCodec, szFrameData, nFrameSize);
				nFrameSize = 0;
			}
			memcpy(szFrameData + nFrameSize, pBuffer, nBufferSize);
			nFrameSize += nBufferSize;
		}
		if ((BYTE)pBuffer[0] == 0 && (BYTE)pBuffer[1] == 0 && (BYTE)pBuffer[2] == 0 && (BYTE)pBuffer[3] == 1 && ((BYTE)pBuffer[4] & 0x7e) >> 1 == 39) //SEI
		{
			//丢弃
		}
		else
		{
			if (nFrameSize + nBufferSize >= FRAME_BUF_SIZE)
			{
				printf("组帧PDR时超出缓冲[%d]\n", nFrameSize + nBufferSize);
				return;
			}
			memcpy(szFrameData + nFrameSize, pBuffer, nBufferSize);
			nFrameSize += nBufferSize;;
		}
	}
protected:
	virtual void *run()
	{
		szFrameData = new unsigned char[FRAME_BUF_SIZE];
		nFrameSize = 0;
		unsigned char szPesBuf[RTP_BUF_SIZE] = { 0 };
		int	nPesBufCurSize = 0;
		while (!bStop && pFifo)
		{
			int nPackets = acl_fifo_size(pFifo);
			//if (nPackets > 1000)
			//{
			//	if (nUsec != 38)
			//		printf("网络收包[%d]缓冲太多,加速解码!\n", nPackets);
			//	nUsec = 38;
			//}
			//else if (nPackets < 100)
			//{
			//	if (nUsec != 40)
			//		printf("网络收包[%d]有点慢,先缓冲一会儿!\n", nPackets);
			//	nUsec = 40;
			//}
			unsigned char *pData = (unsigned char *)acl_fifo_pop(pFifo);
			if (pData == NULL)
			{
				sip_sleep(30);
				continue;
			}
			size_t buffsize = 0;
			memcpy(&buffsize, pData, sizeof(size_t));
			unsigned char *buffer = pData + sizeof(size_t);
			if (nPesBufCurSize + buffsize > RTP_BUF_SIZE)
			{
				printf("己超出一个PES包最大缓冲:%d\n", nPesBufCurSize + (int)buffsize);
				nPesBufCurSize = 0;
			}
			memcpy(szPesBuf + nPesBufCurSize, buffer, buffsize);
			nPesBufCurSize += (int)buffsize;
			acl_myfree(pData);
			pData = NULL;
			if (nStreamType == -1)
				continue;
			int i = 0;
			while (nPesBufCurSize > 9)
			{
				if (nStreamType == 0)
				{
					if ((BYTE)szPesBuf[i] == 0 && (BYTE)szPesBuf[i + 1] == 0 && (BYTE)szPesBuf[i + 2] == 1 && (BYTE)szPesBuf[i + 3] == 0xBC)
					{
						int nPeslen = 6 + szPesBuf[i + 4] * 256 + szPesBuf[i + 5];
						int nSteamTypePos = 10 + szPesBuf[i + 8] * 256 + szPesBuf[i + 9] + 2;
						if (nPeslen <= nSteamTypePos)
						{
							i++;
							nPesBufCurSize--;
							continue;
						}
						if (nPeslen + i > nPesBufCurSize)
							break;
						if (szPesBuf[i+nSteamTypePos] == 0x1B)
							nStreamType = 96;
						else if (szPesBuf[i+nSteamTypePos] == 0x24)
							nStreamType = 98;
						else
							nStreamType = -1;
						i += nPeslen;
						nPesBufCurSize -= nPeslen;
					}
					else
					{
						i++;
						nPesBufCurSize--;
						continue;
					}
				}
				if ((BYTE)szPesBuf[i] == 0 && (BYTE)szPesBuf[i + 1] == 0 && (BYTE)szPesBuf[i + 2] == 1 && ((BYTE)szPesBuf[i + 3] == 0xE0 || (BYTE)szPesBuf[i + 3] == 0xC0))
				{
					int nPeslen = 6 + szPesBuf[i + 4] * 256 + szPesBuf[i + 5];	//PES包长度
					int nPeshead = 9 + szPesBuf[i + 8];						//PES包头长度
					if (nPeslen <= nPeshead)
					{
						i++;
						nPesBufCurSize--;
						continue;
					}
					if (nPeslen  > nPesBufCurSize)
						break;
					if ((BYTE)szPesBuf[i + 3] == 0xE0)	//只处理视频
					{
						if (bFirstData)
						{
							if (pStreamCb)
								pStreamCb(-1, 96, (BYTE*)"H264", 0, pStreamUser);
							bFirstData = false;
							nTimestamp = GetTickCount();
							printf("开始传送流媒体数据,StreamType:%d\n", nStreamType);
						}
						if (nStreamType == 96)
							analyze_h264(szPesBuf + i + nPeshead, nPeslen - nPeshead);
						else if (nStreamType == 98)
						{
							if (pCodec == 0)
								pCodec = hevc2avc_init(CODEC_TYPE_H265, 0, 0, 1920, 1080, 1024*1024*4);
							if (pCodec == 0)
							{
								printf("获取转码句柄失败！内存不足！\n");
								nStreamType = -1;
							}
							analyze_h265(szPesBuf + i + nPeshead, nPeslen - nPeshead);
						}
					}
					i += nPeslen - 1;
					nPesBufCurSize -= nPeslen - 1;
				}
				i++;
				nPesBufCurSize--;
			}
			if (nPesBufCurSize > 0)
			{
				memcpy(szPesBuf, szPesBuf + i, nPesBufCurSize);
			}
		}
		nUsec = 0;
		b4K = false;
		bFirstData = true;
		if (pCodec > 0)
		{
			hevc2avc_uninit(pCodec);
			pCodec = 0;
		}
		if (szFrameData)
		{
			delete[] szFrameData;
			szFrameData = NULL;
		}
		nTimestamp = 0;
		nfreq = 0;
		nFrameSize = 0;
		lockerFifo.lock();
		if (pFifo)
		{
			acl_fifo_free(pFifo, acl_myfree_fn);
			pFifo = NULL;
		}
		lockerFifo.unlock();
		delete this;
		return NULL;
	}
public:
	unsigned char *			szFrameData;
	unsigned int			nFrameSize;
	unsigned int			nTimestamp;
	int						nfreq;
	LPCAPTURESTREAMCALLBACK pStreamCb;
	void*					pStreamUser;
	int						nStreamType;
	ACL_FIFO *				pFifo;
	acl::locker				lockerFifo;
	Long					pCodec;
	int						nUsec;
	bool					b4K;
	bool					bFirstData;
	bool					bBuffer;
	bool					bStop;
};
#endif

SIPHandler::SIPHandler(void)
{
	memset(m_szTerminalID, 0, sizeof(m_szTerminalID));
	memset(m_szDeviceID, 0, sizeof(m_szDeviceID));
	memset(m_szConnectKey, 0, sizeof(m_szConnectKey));
	m_szFrameData = NULL;
	//m_szFrameData = new unsigned char[FRAME_BUF_SIZE];
	//memset(m_szFrameData, 0, FRAME_BUF_SIZE);
	m_nFrameSize = 0;
	m_nTimestamp = 0;
	m_nStreamType = 0;
	m_nChannel = 0;
	m_cPTZCmd = 0;
	m_nInviteId = 0;
	m_pStramCallback = NULL;
	m_pStreamUser = NULL;
	m_pDecCallback = NULL;
	m_nDecUser = NULL;
	m_pDrawCallback = NULL;
	m_pDrawUser = NULL;
	m_hWnd = NULL;
	m_hDecModule = NULL;
	m_pDecHandle = NULL;
	m_getHandler = NULL;
	m_pAnalyzeThrd = NULL;
	m_fRecord = NULL;
	m_bFirstPacket = true;
	m_nWindlt = 0;
	m_nWindrb = 0;
	m_nSrcWidth = 0;
	m_nSrcHight = 0;
	m_nXl = 0;
	m_nYt = 0;
	m_nXr = 0;
	m_nYb = 0;
}

SIPHandler::~SIPHandler(void)
{
	if (m_szFrameData)
	{
		delete[] m_szFrameData;
		m_szFrameData = NULL;
	}
	disconnectDVR();
}


bool SIPHandler::connectDVR(char* sIP, int nPort, char* sUser, char* sPwd, int nChannel)
{
	if (__bInit == false)
	{
		init_thread *init_thd = new init_thread;
		init_thd->set_detachable(true);
		init_thd->start();
		__bInit = true;
	}
	sip.send_register(sIP, nPort, sUser, sPwd);
	sprintf(m_szConnectKey, "%s:%d", sIP, nPort);
	return true;
}

void SIPHandler::disconnectDVR()
{
	stopRecord();
	if (m_hWnd)
	{
		stopPlayerByCamera(m_hWnd, m_nChannel);
		m_hWnd = NULL;
	}
	else
	{
		stopCaptureStream();
	}
}

void SIPHandler::setCurrentCameraCode(char* sCameraCode)
{
	if (sCameraCode && strlen(sCameraCode) == 20)
	{
		int nType = sip_get_user_role(sCameraCode);
		if (nType == SIP_ROLE_CHANNEL)
		{
			memset(m_szDeviceID, 0, sizeof(m_szDeviceID));
			strcpy(m_szDeviceID, sCameraCode);
		}
		else if (nType == SIP_ROLE_MONITOR)
		{
			memset(m_szTerminalID, 0, sizeof(m_szTerminalID));
			strcpy(m_szTerminalID, sCameraCode);
		}
	}
}

bool SIPHandler::captureStream(LPCAPTURESTREAMCALLBACK lpCallBack, void* pUser, int nGetVideoType)
{
	m_pStramCallback = lpCallBack;
	m_pStreamUser = pUser;
	if (m_szTerminalID[0] != '\0')
	{
		m_nInviteId = sip.send_invite(m_szConnectKey, SIP_INVITE_PLAY, m_szDeviceID, m_szTerminalID, NULL, NULL, stream_cb, this);
	}
	else
	{
		m_nInviteId = sip.send_invite(m_szConnectKey, SIP_INVITE_PLAY, m_szDeviceID, NULL, NULL, NULL, stream_cb, this);
	}
	return m_nInviteId>0?true:false;
}

bool SIPHandler::stopCaptureStream()
{
	if (m_nInviteId > 0)
	{
		sip.send_bye(m_nInviteId);
		m_nInviteId = 0;
	}
#ifdef _FOR_RTS_USE
	if (m_pAnalyzeThrd)
	{
		((analyze_thread *)m_pAnalyzeThrd)->stop();
	}
#endif
	m_pStramCallback = NULL;
	m_pStreamUser = NULL;
	m_bFirstPacket = true;
	m_nFrameSize = 0;
	m_nTimestamp = 0;
	m_nStreamType = 0;
	return true;
}

bool SIPHandler::controlPTZSpeedWithChannel(int nCmd, bool bEnable, int nSpeed, int nChannel)
{
	unsigned char nParam1 = nSpeed&0xFF;
	unsigned short nParam2 = nSpeed >> 8;
	SIP_PTZ_RECT rect;
	memset(&rect, 0, sizeof(SIP_PTZ_RECT));
	unsigned char cPtzCmd = SIP_PTZCMD_STOP;
	switch (nCmd)
	{
	case CAMERA_PAN_UP:			//云台向上
		cPtzCmd = SIP_PTZCMD_UP;
		m_cPTZCmd = SIP_PTZCMD_STOP;
		break;
	case CAMERA_PAN_DOWN:		//云台向下
		cPtzCmd = SIP_PTZCMD_DOWN;
		m_cPTZCmd = SIP_PTZCMD_STOP;
		break;
	case CAMERA_PAN_LEFT:		//云台向左
		cPtzCmd = SIP_PTZCMD_LEFT;
		m_cPTZCmd = SIP_PTZCMD_STOP;
		break;
	case CAMERA_PAN_RIGHT:		//云台向右
		cPtzCmd = SIP_PTZCMD_RIGHT;
		m_cPTZCmd = SIP_PTZCMD_STOP;
		break;
	case CAMERA_FOCUS_IN:		//焦点前调
		cPtzCmd = SIP_PTZCMD_FI_FOCUS_IN;
		m_cPTZCmd = SIP_PTZCMD_FI_STOP;
		break;
	case CAMERA_FOCUS_OUT:		//焦点后调
		cPtzCmd = SIP_PTZCMD_FI_FOCUS_OUT;
		m_cPTZCmd = SIP_PTZCMD_FI_STOP;
		break;
	case CAMERA_IRIS_IN:        //光圈调大
		cPtzCmd = SIP_PTZCMD_FI_IRIS_IN;
		m_cPTZCmd = SIP_PTZCMD_FI_STOP;
		break;
	case CAMERA_IRIS_OUT:       //光圈调小
		cPtzCmd = SIP_PTZCMD_FI_IRIS_OUT;
		m_cPTZCmd = SIP_PTZCMD_FI_STOP;
		break;
	case CAMERA_ZOOM_IN:        //倍率调大
		cPtzCmd = SIP_PTZCMD_ZOOM_IN;
		m_cPTZCmd = SIP_PTZCMD_STOP;
		break;
	case CAMERA_ZOOM_OUT:       //倍率调小
		cPtzCmd = SIP_PTZCMD_ZOOM_OUT;
		m_cPTZCmd = SIP_PTZCMD_STOP;
		break;
	case CAMERA_BRUSH_CTRL:     //雨刷控制
		nParam1 = 1;
		cPtzCmd = SIP_PTZCMD_AUXIOPEN;
		m_cPTZCmd = SIP_PTZCMD_AUXICLOSE;
		break;
	case CAMERA_AUTO_TURN:      //自动旋转
		cPtzCmd = SIP_PTZCMD_AUTO_RUN;
		m_cPTZCmd = SIP_PTZCMD_STOP;
		break;
	case CAMERA_PAN_LU:			//云台左上
		cPtzCmd = SIP_PTZCMD_LU;
		m_cPTZCmd = SIP_PTZCMD_STOP;
		break;
	case CAMERA_PAN_LD:			//云台左下
		cPtzCmd = SIP_PTZCMD_LD;
		m_cPTZCmd = SIP_PTZCMD_STOP;
		break;
	case CAMERA_PAN_RU:			//云台右上
		cPtzCmd = SIP_PTZCMD_RU;
		m_cPTZCmd = SIP_PTZCMD_STOP;
		break;
	case CAMERA_PAN_RD:			//云台右下
		cPtzCmd = SIP_PTZCMD_RD;
		m_cPTZCmd = SIP_PTZCMD_STOP;
		break;
	case CAMERA_INITIAL:		//看守位开启
		cPtzCmd = SIP_PTZCMD_INITIAL;
		m_cPTZCmd = SIP_PTZCMD_NONE;
		break;
	case CAMERA_UNINITIAL:		//看守位关闭
		cPtzCmd = SIP_PTZCMD_UNINITIAL;
		m_cPTZCmd = SIP_PTZCMD_NONE;
		break;
	case CAMERA_LOCK:			//锁定云台
		cPtzCmd = SIP_PTZCMD_LOCK;
		m_cPTZCmd = SIP_PTZCMD_NONE;
		break;
	case CAMERA_UNLOCK:			//解锁云台
		cPtzCmd = SIP_PTZCMD_UNLOCK;
		m_cPTZCmd = SIP_PTZCMD_NONE;
		break;					
	case CAMERA_SETP:			//电子放大				
	case CAMERA_SETN:			//电子放大
		if (m_pDecHandle)
		{
			m_pDecHandle->controlPTZSpeedWithChannel(nCmd, bEnable, nSpeed, nChannel);
		}
		return true;
	case CAMERA_3D_FIRST:		//3D放大
		m_nWindlt = nSpeed;
		return true;
	case CAMERA_3D_SECOND:		//3D放大
		{
			if (m_nWindlt == 0)
			{
				return false;
			}
			unsigned char prec[4] = { 0 };
			unsigned char nrec[4] = { 0 };
			memcpy(prec, &m_nWindlt, sizeof(m_nWindlt));
			memcpy(nrec, &nSpeed, sizeof(nSpeed));
			int pl = 0, pt = 0, pr = 0, pb = 0;//原来窗口坐标
			int nl = 0, nt = 0, nr = 0, nb = 0;//框选窗口坐标
			pl = prec[0] * 10;
			pt = prec[1] * 10;
			pr = prec[2] * 10;
			pb = prec[3] * 10;
			nl = nrec[0] * 10;
			nt = nrec[1] * 10;
			nr = nrec[2] * 10;
			nb = nrec[3] * 10;
			if (m_nSrcWidth == 0 && m_nSrcHight == 0 || (nSpeed == m_nWindlt))
			{
				if (m_pDecHandle == NULL)
					return false;
				char szVideoOutCfg[32] = { 0 };
				DWORD dwOutSize = 0;
				if (!m_pDecHandle->getDVRConfig(CONFIG_GET_VIDEOOUTCFG, 0, szVideoOutCfg, sizeof(szVideoOutCfg), &dwOutSize))
					return false;
				sscanf(szVideoOutCfg, "%d,%d", &m_nSrcWidth, &m_nSrcHight);
				if (nSpeed == m_nWindlt)
				{
					cPtzCmd = SIP_PTZCMD_DRAGZOOM_OUT;
					m_nXl = 0;
					m_nYt = 0;
					m_nXr = m_nSrcWidth;
					m_nYb = m_nSrcHight;
				}
				else
				{
					cPtzCmd = SIP_PTZCMD_DRAGZOOM_IN;
					m_nXl = m_nSrcWidth*nl / (pr - pl);
					m_nYt = m_nSrcHight*nt / (pb - pt);
					m_nXr = m_nSrcWidth*nr / (pr - pl);
					m_nYb = m_nSrcHight*nb / (pb - pt);
				}
			}
			else
			{
				cPtzCmd = SIP_PTZCMD_DRAGZOOM_IN;
				int x = m_nXl;
				int y = m_nYt;
				int nWidth = m_nXr - m_nXl;
				int nHight = m_nYb - m_nYt;
				m_nXl = (nWidth*nl / (pr - pl)) + x;
				m_nYt = (nHight*nt / (pb - pt)) + y;
				m_nXr = (nWidth*nr / (pr - pl)) + x;
				m_nYb = (nHight*nb / (pb - pt)) + y;
			}
			rect.width = m_nSrcWidth;
			rect.height = m_nSrcHight;
			rect.left = m_nXl;
			rect.top = m_nYt;
			rect.right = m_nXr;
			rect.bottom = m_nYb;
		}
		break;
	default:
		break;
	}
	if (bEnable)	
	{
		cPtzCmd = m_cPTZCmd;
	}
	sip.send_ptzcmd(m_szConnectKey, m_szDeviceID, cPtzCmd, nParam1, nParam2, &rect);
	return true;
}

bool SIPHandler::controlPTZSpeedWithChannelEx(PCONTROL_PARAM pParam)
{
	return controlPTZSpeedWithChannel(pParam->nCmd, pParam->bEnable, pParam->nSpeed, pParam->nChannel);
}

bool SIPHandler::controlPTZSpeed(int nCmd, bool bEnable, int nSpeed)
{
	return controlPTZSpeedWithChannel(nCmd, bEnable, nSpeed, m_nChannel);
}

bool SIPHandler::presetPTZWithChannel(int nCmd, int nIndex, int nChannel)
{
	unsigned char nParam1 = nIndex & 0xFF;
	unsigned short nParam2 = nIndex >> 8;
	SIP_PTZ_RECT rect;
	memset(&rect, 0, sizeof(SIP_PTZ_RECT));
	unsigned char cPtzCmd = SIP_PTZCMD_STOP;
	switch (nCmd)
	{
	case PTZ_PRESET_SET:		//设置预置位
		cPtzCmd = SIP_PTZCMD_SET;
		break;
	case PTZ_PRESET_DELETE:		//删除预置位
		cPtzCmd = SIP_PTZCMD_DELETE;
		break;
	case PTZ_PRESET_GOTO:		//跳转预置位
		cPtzCmd = SIP_PTZCMD_GOTO;
		break;
	case PTZ_CRUISE_ADD:		//加入巡航点
		cPtzCmd = SIP_PTZCMD_CRUISE_ADD;
		break;
	case PTZ_CRUISE_DEL:		//删除巡航点
		cPtzCmd = SIP_PTZCMD_CRUISE_DEL;
		break;
	case PTZ_CRUISE_TIME:		//设置巡航停顿时间
		cPtzCmd = SIP_PTZCMD_CRUISE_DTIME;
		break;
	case PTZ_CRUISE_LOOP:        //开始巡航
		cPtzCmd = SIP_PTZCMD_CRUISE_RUN;
		break;
	case PTZ_CRUISE_STOPL:       //停止巡航
		cPtzCmd = SIP_PTZCMD_STOP;
		break;
	default:
		break;
	}
	sip.send_ptzcmd(m_szConnectKey, m_szDeviceID, cPtzCmd, nParam1,nParam2);
	return true;
}

bool SIPHandler::presetPTZ(int nCmd, int nIndex)
{
	return presetPTZWithChannel(nCmd, nIndex, m_nChannel);
}


RECORDFILE* SIPHandler::getRecordFile(int nType, char* startTime, char* endTime, int* nFileCount)
{

	return NULL;
}

int SIPHandler::getRecordFileEx(int nType, char* startTime, char* endTime, RECORDFILE pRecordFile[], int nMaxFileCount)
{
	return sip.send_recordinfo(m_szConnectKey, m_szDeviceID, nType, startTime, endTime, (record_info *)pRecordFile, nMaxFileCount);
}

LLONG SIPHandler::captureFileStream(LPCAPTURESTREAMCALLBACK lpCallBack, void* pUser, int nStreamType, RECORDFILE FileInfo, char* sType)
{

	return 0;
}



bool SIPHandler::controlReplayRecordFile(LLONG lReplayHandle, int nCmd, int nInValue, int* outValue)
{

	return true;
}

LLONG SIPHandler::replayRecordFile(LHWND hWnd, char* fileName, char* startTime, char* endTime, int nFileSize)
{

	return (LLONG)0;
}

bool SIPHandler::stopReplayRecordFile(LLONG lReplayHandle)
{

	return true;
}

bool SIPHandler::playBackCaptureFile(LLONG lReplayHandle, char *pFileName)
{

	return true;
}

bool SIPHandler::playBackSaveData(LLONG lReplayHandle, char *sFileName)
{

	return false;
}

bool SIPHandler::stopPlayBackSave(LLONG lReplayHandle)
{

	return true;
}

LLONG SIPHandler::downloadRecordFile(char* fileName, char* startTime, char* endTime, int nFileSize, char* saveFile, LPDOWNLOADRECORDFILECALLBACK lpCallBack, void* pUser)
{

	return 0;
}

bool SIPHandler::stopDownloadRecordFile(LLONG ldownFileHandle)
{

	return true;
}


int SIPHandler::getDownloadPos(LLONG lFileHandle)
{
	return 0;
}



bool SIPHandler::startPlayer4Standard(HWND hWnd, LPDecCBFun lpDecCBFun, int nCameraID)
{
	m_pDecCallback = lpDecCBFun;
	m_nDecUser = nCameraID;
	return startPlayerByCamera(hWnd, nCameraID);
}

bool SIPHandler::startPlayerByCamera(HWND hwndPlay, int nCameraID)
{
	m_hWnd = hwndPlay;
	m_nChannel = nCameraID;
	if (m_szTerminalID[0] != '\0')
	{
		m_nInviteId = sip.send_invite(m_szConnectKey, SIP_INVITE_PLAY, m_szDeviceID, m_szTerminalID, NULL, NULL, stream_cb, this);
	}
	else
	{
		m_nInviteId = sip.send_invite(m_szConnectKey, SIP_INVITE_PLAY, m_szDeviceID, NULL, NULL, NULL, stream_cb, this);
	}
	return m_nInviteId>0 ? true : false;;
}

bool SIPHandler::stopPlayerByCamera(HWND hwndPlay, int nCameraID)
{
	if (m_nInviteId > 0)
	{
		sip.send_bye(m_nInviteId);
		m_nInviteId = 0;
	}
	if (m_pDecHandle)
	{
		stopPlayer();
	}
	m_pDecCallback = NULL;
	m_nDecUser = NULL;
	return true;
}

bool SIPHandler::capturePicture(char* sFilePath)
{
	if (m_pDecHandle)
	{
		m_pDecHandle->capturePicture(sFilePath);
	}
	return true;
}

void SIPHandler::stream_cb(int bufType, unsigned char * buffer, unsigned int bufsize, void * user)
{
	SIPHandler *pHandle = (SIPHandler *)user;
	if (pHandle == NULL || IsBadReadPtr(pHandle, sizeof(SIPHandler)) ||pHandle->m_nInviteId == 0)
	{
		return;
	}
	if (bufType > 0)
	{
		int nErrorCode = 0;
		switch (bufType)
		{
		case 200:	//播放成功
			nErrorCode = 0;
			pHandle->m_nStreamType = bufsize;
			printf("播放[%s]成功\n", pHandle->m_szDeviceID);
			break;
		case 400:	//播放失败
			nErrorCode = -30;
			printf("播放[%s]失败,设备离线！\n", pHandle->m_szDeviceID);
			break;
		case 403:	//连接超时
			nErrorCode = -31;
			pHandle->reconnect();
			printf("播放[%s]失败,连接超时！\n", pHandle->m_szDeviceID);
			break;
		case 408:	//接收超时
			nErrorCode = -34;
			printf("播放[%s]失败,接收超时！\n", pHandle->m_szDeviceID);
			break;
		case 487:	//内部错误
#ifndef _ROR_RTS_USE
			nErrorCode = -32;
			pHandle->reconnect();
#endif
			printf("播放[%s]失败,码流己断开！\n", pHandle->m_szDeviceID);
			break;
		default:
			nErrorCode = -30;
			printf("播放[%s]失败\n", pHandle->m_szDeviceID);
			break;
		}
#ifdef _FOR_RTS_USE
		if (pHandle->m_pStramCallback)
			pHandle->m_pStramCallback(nErrorCode, 3, NULL, 0, pHandle->m_pStreamUser);
#endif
		if (pHandle->m_pDrawCallback)
			pHandle->m_pDrawCallback(nErrorCode, (LLONG)pHandle, 400, pHandle->m_pDrawUser);

	}
	if (bufType == 0 && buffer && bufsize > 0)
	{
		u_long timestamp = ntohl(*((u_long *)&buffer[4]));
		int rtplen = 12;
		if ((unsigned char)buffer[0] == 0x90)
		{
			//rtplen += 2 + 2 + ntohs(*((u_short *)&buffer[14])) * 4;
			rtplen += 2 + 2 + (buffer[14]*256+buffer[15]) * 4;
		}
		if (pHandle->m_fRecord)
		{
			fwrite(buffer + rtplen, bufsize - rtplen, 1, pHandle->m_fRecord);
		}
		if (pHandle->m_bFirstPacket)
		{
			pHandle->m_bFirstPacket = false;
			if (pHandle->m_pStramCallback)
			{
#ifdef _FOR_RTS_USE
				analyze_thread *pThrd = new analyze_thread(pHandle->m_nStreamType, pHandle->m_pStramCallback, pHandle->m_pStreamUser);
				pHandle->m_pAnalyzeThrd = pThrd;
				pThrd->set_detachable(true);
				pThrd->start();
				if (pHandle->m_szFrameData)
				{
					memcpy(pHandle->m_szFrameData, buffer + rtplen, bufsize - rtplen);
					pHandle->m_nFrameSize = bufsize - rtplen;
					pHandle->m_nTimestamp = timestamp;
				}
				else
					pThrd->add_data(buffer + rtplen, bufsize - rtplen);
#else
				pHandle->m_pStramCallback((LLONG)pHandle, DVR_DATA_INIT, buffer + rtplen, bufsize - rtplen, pHandle->m_pStreamUser);
#endif				
				return;
			}
			if ((unsigned char)buffer[1] == 0xA8)	//海康头
			{
				if (sip.m_conf.specify_declib == SIP_STREAM_DAHUA)
					pHandle->initialPlayer(0, SIP_STREAM_DAHUA, NULL, 0, 0);
				else
					pHandle->initialPlayer(0, SIP_STREAM_HIKVISION, buffer + rtplen, bufsize - rtplen, 0);
				if (pHandle->m_pDecCallback && pHandle->m_pDecHandle && pHandle->m_hWnd == NULL)
				{
					pHandle->m_pDecHandle->startPlayer4Standard(NULL, pHandle->m_pDecCallback, pHandle->m_nDecUser);
				}
				if (pHandle->m_pDrawCallback && pHandle->m_pDecHandle)
					pHandle->m_pDecHandle->startPlayer2(pHandle->m_hWnd, pHandle->m_pDrawCallback, pHandle->m_pDrawUser);
				else
					pHandle->startPlayer(pHandle->m_hWnd);
			}
			else
			{
				pHandle->initialPlayer(0, SIP_STREAM_DAHUA, NULL, 0, 0);
				if (pHandle->m_pDecCallback && pHandle->m_pDecHandle && pHandle->m_hWnd == NULL)
				{
					pHandle->m_pDecHandle->startPlayer4Standard(NULL, pHandle->m_pDecCallback, pHandle->m_nDecUser);
				}
				if (pHandle->m_pDrawCallback && pHandle->m_pDecHandle)
					pHandle->m_pDecHandle->startPlayer2(pHandle->m_hWnd, pHandle->m_pDrawCallback, pHandle->m_pDrawUser);
				else
					pHandle->startPlayer(pHandle->m_hWnd);
				pHandle->addData(buffer + rtplen, bufsize - rtplen);
			}
		}
		else
		{
			if (pHandle->m_pStramCallback)
			{
#ifdef _FOR_RTS_USE
				if (pHandle->m_szFrameData)
				{
					if (pHandle->m_nTimestamp != timestamp)
					{
						((analyze_thread *)pHandle->m_pAnalyzeThrd)->add_data(pHandle->m_szFrameData, pHandle->m_nFrameSize);
						pHandle->m_nFrameSize = 0;
					}
					else
					{
						pHandle->m_nTimestamp = timestamp;
						if (pHandle->m_nFrameSize + bufsize - rtplen > FRAME_BUF_SIZE)
						{
							printf("超出了一帧最大缓冲区[%d]!\n", pHandle->m_nFrameSize + bufsize - rtplen);
							((analyze_thread *)pHandle->m_pAnalyzeThrd)->add_data(pHandle->m_szFrameData, pHandle->m_nFrameSize);
							pHandle->m_nFrameSize = 0;
						}
						memcpy(pHandle->m_szFrameData + pHandle->m_nFrameSize, buffer + rtplen, bufsize - rtplen);
						pHandle->m_nFrameSize += bufsize - rtplen;
					}
				}
				else
					((analyze_thread *)pHandle->m_pAnalyzeThrd)->add_data(buffer + rtplen, bufsize - rtplen);
#else
				pHandle->m_pStramCallback((LLONG)pHandle, DVR_DATA_STREAM, buffer + rtplen, bufsize - rtplen, pHandle->m_pStreamUser);
#endif
			}
			else
				pHandle->addData(buffer + rtplen, bufsize - rtplen);
		}
	}
}

void SIPHandler::reconnect()
{
	reconect_thread *pThrd = new reconect_thread(this);
	pThrd->set_detachable(true);
	pThrd->start();
}

bool SIPHandler::startRecord(char* saveFile)
{
	m_fRecord = fopen(saveFile, "ab+");
	if (m_fRecord)
	{
		return true;
	}
	return false;
}

bool SIPHandler::stopRecord()
{
	if (m_fRecord)
	{
		fclose(m_fRecord);
		m_fRecord = NULL;
	}
	return true;
}


bool SIPHandler::startPlayer2(HWND hWnd, LPDRAWCBCALLLBACK lpDrawCBFun, void *pUser)
{
	m_pDrawCallback = lpDrawCBFun;
	m_pDrawUser = pUser;
	return true;
}

bool SIPHandler::setDVRConfig(DWORD dwCommand, LONG lChannel, LPVOID lpInBuffer, DWORD dwInBufferSize)
{
	return true;
}

bool SIPHandler::getDVRConfig(DWORD dwCommand, LONG lChannel, LPVOID lpOutBuffer, DWORD dwOutBufferSize, LPDWORD lpBytesReturned)
{
	return true;
}

bool SIPHandler::initialPlayer(int nPort, int nDecodeType, BYTE* buff, int nSize, int nStreamType)
{
	char szDllType[12] = { 0 };
	switch (nDecodeType)
	{
	case SIP_STREAM_HIKVISION:
		strcpy(szDllType, "HK");
		break;
	default:
		strcpy(szDllType, "DH");
		break;
	}
	char szDllPath[256] = { 0 };
	sprintf(szDllPath, "%s\\PlugIn\\%sPlugIn\\%sPlayPlugIn.dll", sip.m_conf.cwd, szDllType, szDllType);
	m_hDecModule = LoadLibraryEx(szDllPath, NULL, LOAD_WITH_ALTERED_SEARCH_PATH);
	if (m_hDecModule == NULL)
	{
		//sip.m_conf.log(LOG_ERROR, "Load PlayerDll false[%s]", szDllPath);
		sprintf(szDllPath, "%s\\PlugIn\\SIPPlugIn\\Player\\%s\\%sPlayPlugIn.dll", sip.m_conf.cwd, szDllType, szDllType);
		m_hDecModule = LoadLibraryEx(szDllPath, NULL, LOAD_WITH_ALTERED_SEARCH_PATH);
		if (m_hDecModule == NULL)
		{
			sip.m_conf.log(LOG_ERROR, "Load PlayerDll false[%s]", szDllPath);
			return false;
		}
	}
	m_getHandler = (getHandlerFun)GetProcAddress(m_hDecModule, "getHandler");
	if (m_getHandler == NULL)
	{
		return false;
	}
	m_pDecHandle = m_getHandler();
	if (m_getHandler == NULL)
	{
		return false;
	}
	return m_pDecHandle->initialPlayer(nPort, 0, buff, nSize, nStreamType);
}

bool SIPHandler::startPlayer(HWND hWnd)
{
	if (m_pDecHandle)
	{
		return m_pDecHandle->startPlayer(hWnd);
	}
	return false;
}

bool SIPHandler::addData(BYTE* buff, int nSize)
{
	if (m_pDecHandle)
	{
		return m_pDecHandle->addData(buff, nSize);
	}
	return false;
}

bool SIPHandler::stopPlayer()
{
	stopRecord();
	if (m_pDecHandle)
	{
		m_pDecHandle->stopPlayer();
		m_pDecHandle->releaseHandler();
		m_pDecHandle = NULL;
		m_getHandler = NULL;
		FreeLibrary(m_hDecModule);
		m_hDecModule = NULL;
		m_hWnd = NULL;
		m_bFirstPacket = true;
	}
	return true;
}