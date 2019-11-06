#include "StdAfx.h"
#include "NetPlugIn.h"
#include "NetInit.h"

NetInit G_NetInit;


NetPlugIn::NetPlugIn(void)
{
	m_nHWHandle = -1;
	m_nPlatPlayId = 0;
	m_nPlatRePlayId = 0;
	m_nPlayId = 0;
	m_nPlaybackId = 0;
	m_nDownloadId = 0;
	m_hPlayWnd = 0;
	m_nCameraID = 0;
	memset(m_szDomainID,0,sizeof(m_szDomainID));
	memset(m_szCameraID,0,sizeof(m_szCameraID));
	m_pKeyFrameBuf = new BYTE[2*1024*1024];
	memset(m_pKeyFrameBuf,0,2*1024*1024);
	m_nKeyFramelen = 0;
	m_vTimeStamp = 0;
	m_pStreamCb = NULL;
	m_pUser = NULL;
	m_pDecCb = NULL;
	m_pDecUser = NULL;
	m_pDrawCb = NULL;
	m_pDrawCb  =NULL;
	m_nSrcWind = 0;
	m_nNewWind = 0;
	m_nWidth = 0;
	m_nHight = 0;
	m_Xlpoit = 0;
	m_Xrpoit = 0;
	m_Ytpoit = 0;
	m_Ydpoit = 0;
	m_bFirstData = false;
	m_bSavefile = false;
	m_vfile = NULL;
	m_log = NULL;
	m_fReplayNormal = 0.5;
	m_fReplaySpeed = 0.5;
	m_nRecTotalTime = 0;
	m_nRecTimeTick = 0;
	m_nRecPos = 0;
	m_nDownloadPos = 0;
	m_nDownloadCount = 0;
	memset(m_szShowString,0,sizeof(m_szShowString));

	m_bVCNStorage = 0;
	m_nEngineType = 0;
	m_nRenderType = 0;
	m_nStreamType = STREAM_TYPE_MAIN;
	m_nProtocolType = 2;
	m_nPlayMode = 1;
	m_nRecodeType = 1;
	m_nWatermark = 1;
	m_nDecodeType = 0;
	m_nBufferSize = SOURCE_BUF_MIN;
	
	m_bLog = 1;
	m_bRts = 0;
	m_bHEToAVC = 0;
	m_nScale = 0;
	m_nScaling = 0;
	m_nDestWidth = 0;
	m_nDestHeight = 0;
	m_nDestBitrate = 0;
	m_nCodec = 0;
	m_nTimeStamp = 0;
	m_nTimeinterval = 0;
}

NetPlugIn::~NetPlugIn(void)
{
	if (m_pKeyFrameBuf)
	{
		delete[] m_pKeyFrameBuf;
		m_pKeyFrameBuf = NULL;
	}
}

void NetPlugIn::WriteLog(const char *sFormat, ...)
{
	if (m_bLog)
	{
		m_log = fopen("C:\\NVSLog\\SDKEngine\\HWPlatPlugIn.log", "a+");
		if (m_log)
		{
			char szLog[1024] = {0};
			va_list args;
			va_start(args, sFormat);
			vsprintf(szLog, sFormat, args);
			va_end(args);
			strcat(szLog,"\r\n");
			fwrite(szLog,strlen(szLog),1,m_log);
			fclose(m_log);
		}
	}
}

bool NetPlugIn::connectDVR(char* sIP,int nPort,char* sUser,char* sPwd,int nChannel)
{
	WriteLog("connectDVR:[ip:%s][port:%d][user:%s][pwd:%s][ch:%d]", sIP, nPort, sUser, sPwd, nChannel);

	G_NetInit.Init();

	m_nChannel = nChannel;

	m_bLog = GetPrivateProfileInt("LOG","Log",0,G_NetInit.m_szDecodeEngine);

	m_nDecodeType = GetPrivateProfileInt("DECODE","Decode",1,G_NetInit.m_szDecodeEngine);
	m_nEngineType = GetPrivateProfileInt("DECODE","Engine",0,G_NetInit.m_szDecodeEngine);
	m_nRenderType = GetPrivateProfileInt("DECODE","Render",3,G_NetInit.m_szDecodeEngine);
	m_nBufferSize = GetPrivateProfileInt("DECODE","BufferSize",SOURCE_BUF_MIN,G_NetInit.m_szDecodeEngine);

	//m_bVCNStorage = GetPrivateProfileInt("DECODE","VCNStorage",0,G_NetInit.m_szDecodeEngine);

	if (m_nEngineType == 1)
	{
		m_nDecodeType = 1;
	}

	if (m_bVCNStorage) //走VCN
	{
		WriteLog("跳转VCN存储模式");
		return true;
	}

	m_nHWHandle = G_NetInit.Login(sIP,nPort,sUser,sPwd);
	if (m_nHWHandle == -1)
	{
		printf("登陆华为平台失败!\n");
		m_nHWHandle = -1;
		return false;
	}
	
	//printf("登陆华为平台成功 handle:%d!\n", m_nHWHandle);
	return true;
}

void NetPlugIn::disconnectDVR()
{
	//WriteLog("disconnectDVR");
	if (m_nHWHandle != -1)
	{
		stopCaptureStream();
		G_NetInit.LogOut();
		m_nHWHandle = -1;
	}
}

void NetPlugIn::setCurrentCameraCode(char* sCameraCode)
{
	WriteLog("setCurrentCameraCode:[%s]", sCameraCode);
	memset(m_szCameraID,0,sizeof(m_szCameraID));
	strcpy(m_szCameraID,sCameraCode);
	
	if (m_bVCNStorage) //走VCN
	{
		char szInfo[1024] = {0};
		GetPrivateProfileString("info",m_szCameraID,"",szInfo,sizeof(szInfo),G_NetInit.m_szConfig);
		if (szInfo[0] != '\0')
		{
			char *sIP = strtok(szInfo,";");
			char *sPort = strtok(NULL,";");
			char *sUser = strtok(NULL,";");
			char *sPwd = strtok(NULL,";");
			char *sCode = strtok(NULL,";");
			int nPort = atoi(sPort);
			m_nHWHandle = G_NetInit.Login(sIP,nPort,sUser,sPwd);
			if (m_nHWHandle != -1)
			{
				memset(m_szCameraID,0,sizeof(m_szCameraID));
				strcpy(m_szCameraID,sCode);
				WriteLog("setCurrentCameraCode:[%s]", m_szCameraID);
			}
			else
			{
				WriteLog("login %s %s %s %s %s",sIP,sPort,sUser,sPwd,sCode);
			}
		}
		else
		{
			WriteLog("当前镜头没有在VCN有存储计划");
		}
	}
}

bool NetPlugIn::captureStream(LPCAPTURESTREAMCALLBACK lpCallBack, void* pUser, int nGetVideoType)
{
	m_pStreamCb = lpCallBack;
	m_pUser = pUser;

	IVS_REALPLAY_PARAM RealPlayInfo = {0};
	RealPlayInfo.uiStreamType = m_nStreamType;
	RealPlayInfo.uiProtocolType = m_nProtocolType;
	RealPlayInfo.bDirectFirst = 0;
	RealPlayInfo.bMultiCast = 0;

	IVS_INT32 nErrCode = IVS_SDK_StartRealPlayCBRaw(m_nHWHandle,&RealPlayInfo,m_szCameraID,RealPlayCBRaw,this,&m_nPlayId);
	if(nErrCode != IVS_SUCCEED)
	{
		WriteLog("播放华为平台镜头[%s]失败 error:%d!\n",m_szCameraID,nErrCode);
		printf("播放华为平台镜头[%s]失败 error:%d!\n",m_szCameraID,nErrCode);
		m_nPlayId = 0; 
		return false;
	}
	WriteLog("播放华为平台镜头[%s]成功! handle[%d]\n",m_szCameraID,m_nPlayId);
	printf("播放华为平台镜头[%s]成功! handle[%d]\n",m_szCameraID,m_nPlayId);
	return true;
}

void NetPlugIn::AVCFrameCBFun(unsigned char * pBuf, long nSize, long tv_sec, long tv_usec, void* pUser)
{
	NetPlugIn *pThis = (NetPlugIn*)pUser;
	if (pThis == NULL || pThis->m_pStreamCb == NULL)
	{
		return;
	}
	//pThis->WriteLog("nSize:%d [%x][%x][%x][%x][%x]回调H264数据", nSize,pBuf[0],pBuf[1],pBuf[2],pBuf[3],pBuf[4]);
	pThis->m_pStreamCb(0, DVR_DATA_STREAM, pBuf, nSize, pThis->m_pUser);
}

IVS_VOID NetPlugIn::RealPlayCBRaw(IVS_ULONG ulHandle,IVS_RAW_FRAME_INFO* pRawFrameInfo,IVS_VOID* pBuf,IVS_UINT32 uiBufSize,IVS_VOID* pUserData)
{
	//unsigned char *p = (unsigned char *)pBuf;
	//printf("frame type:%d naul:%d len:%d   %02x %02x %02x %02x %02x\n",pRawFrameInfo->uiStreamType,pRawFrameInfo->uiFrameType,uiBufSize,p[0],p[1],p[2],p[3],p[4]);
	NetPlugIn *pThis = (NetPlugIn*)pUserData;
	if (pThis == NULL || pThis->m_nPlayId == 0 || pThis->m_pStreamCb == NULL)
	{
		//pThis->WriteLog("%d %p %p\n",pThis->m_nPlayId,pThis,pThis->m_pStreamCb);
		//printf("%d %p %p\n",pThis->m_nPlayId,pThis,pThis->m_pStreamCb);
		return;
	}
	if (!pThis->m_bRts)
	{
		if (!pThis->m_bFirstData)
		{

			pThis->m_pStreamCb((long)pThis, DVR_DATA_INIT, (BYTE*)pBuf, uiBufSize, pThis->m_pUser);
			pThis->m_bFirstData = true;
		}
		pThis->m_pStreamCb((long)pThis, DVR_DATA_STREAM, (BYTE*)pBuf, uiBufSize, pThis->m_pUser);
		return;
	}
	//if (pRawFrameInfo->uiStreamType == PAY_LOAD_TYPE_H264)	//视频
	//{
	//	//pThis->WriteLog("H264,StreamType:%d FrameType %d", pRawFrameInfo->uiStreamType, pRawFrameInfo->uiFrameType);
	//	if (!pThis->m_bFirstData)
	//	{
	//		printf("发送数据头H264\n");
	//		pThis->m_pStreamCb(-1, 96, (BYTE*)"H264", 0, pThis->m_pUser);
	//		pThis->m_bFirstData = true;
	//	}
	//	if (pRawFrameInfo->uiFrameType == 6) {}
	//	else if (pRawFrameInfo->uiFrameType == 9) {}
	//	else if (pRawFrameInfo->uiFrameType == 7 || pRawFrameInfo->uiFrameType == 8)
	//	{
	//		memcpy(pThis->m_pKeyFrameBuf + pThis->m_nKeyFramelen, pBuf, uiBufSize);
	//		pThis->m_nKeyFramelen += uiBufSize;
	//	}
	//	else if (pRawFrameInfo->uiFrameType == 5)	//关键帧
	//	{
	//		memcpy(pThis->m_pKeyFrameBuf + pThis->m_nKeyFramelen, pBuf, uiBufSize);
	//		pThis->m_nKeyFramelen += uiBufSize;
	//		pThis->m_pStreamCb(0, DVR_DATA_STREAM, pThis->m_pKeyFrameBuf, pThis->m_nKeyFramelen, pThis->m_pUser);
	//		pThis->m_nKeyFramelen = 0;
	//	}
	//	else										//非关键帧
	//	{
	//		pThis->m_pStreamCb(0, DVR_DATA_STREAM, (BYTE*)pBuf, uiBufSize, pThis->m_pUser);
	//	}
	//}
	//else if (pRawFrameInfo->uiStreamType == PAY_LOAD_TYPE_H265)
	//{
	//	//pThis->WriteLog("H265,StreamType:%d FrameType %d", pRawFrameInfo->uiStreamType, pRawFrameInfo->uiFrameType);
	//	if (pRawFrameInfo->uiFrameType == 39) {}
	//	else if (pRawFrameInfo->uiFrameType == 32 || pRawFrameInfo->uiFrameType == 33 || pRawFrameInfo->uiFrameType == 34)
	//	{
	//		memcpy(pThis->m_pKeyFrameBuf + pThis->m_nKeyFramelen, pBuf, uiBufSize);
	//		pThis->m_nKeyFramelen += uiBufSize;
	//	}
	//	else if (pRawFrameInfo->uiFrameType == 19)	//关键帧
	//	{
	//		if (!pThis->m_bFirstData)
	//		{
	//			printf("发送H265转H264\n");
	//			pThis->m_nCodec = hevc2avc_init(CODEC_TYPE_H265, pRawFrameInfo->uiWidth, pRawFrameInfo->uiHeight, pThis->m_nDestWidth, pThis->m_nDestHeight, pThis->m_nDestBitrate);
	//			if (pThis->m_nCodec > 0)
	//			{
	//				hevc2avc_setcb(pThis->m_nCodec, AVCFrameCBFun, pThis);
	//			}
	//			pThis->m_pStreamCb(-1, 96, (BYTE*)"H264", 0, pThis->m_pUser);
	//			pThis->m_bFirstData = true;
	//		}
	//		memcpy(pThis->m_pKeyFrameBuf + pThis->m_nKeyFramelen, pBuf, uiBufSize);
	//		pThis->m_nKeyFramelen += uiBufSize;
	//		if (pThis->m_nCodec > 0)
	//		{
	//			hevc2avc_input(pThis->m_nCodec, pThis->m_pKeyFrameBuf, pThis->m_nKeyFramelen);
	//		}
	//		pThis->m_nKeyFramelen = 0;
	//		//printf("I TimeStamp:%u\n", pRawFrameInfo->uiTimeStamp);
	//	}
	//	else										//非关键帧
	//	{
	//		if (pThis->m_bFirstData && pThis->m_nCodec > 0)
	//		{
	//			hevc2avc_input(pThis->m_nCodec, (BYTE*)pBuf, uiBufSize);
	//		}
	//	}
	//}
	//else													//音频
	//{
	//}
}

bool NetPlugIn::stopCaptureStream()
{
	if (m_nPlaybackId != 0)
	{
		IVS_SDK_StopPlatformPlayBack(m_nHWHandle,m_nPlaybackId);
		m_nPlaybackId = 0;
		m_nRecTotalTime = 0;
		m_nRecTimeTick = 0;
		m_nRecPos = 0;
	}
	if (m_nPlayId != 0)
	{
		IVS_SDK_StopRealPlay(m_nHWHandle, m_nPlayId);
		m_nPlayId = 0;
	}
	m_bFirstData = false;
	m_pStreamCb = NULL;
	m_pUser = NULL;
	m_nTimeStamp = 0;
	m_nTimeinterval = 0;
	printf("关闭播放成功\n");
	return true;
}

bool NetPlugIn::EXACTGOTO()
{
	unsigned char prec[4]={0};
	unsigned char nrec[4]={0};

	memcpy(prec,&m_nSrcWind,sizeof(m_nSrcWind));
	memcpy(nrec,&m_nNewWind,sizeof(m_nNewWind));

	int pleft=0,ptop=0,pright=0,pdow=0;//原来窗口坐标
	int nleft=0,ntop=0,nright=0,ndow=0;//框选窗口坐标

	pleft	=	prec[0]*10;				
	ptop	=	prec[1]*10;				
	pright	=	prec[2]*10;			
	pdow	=	prec[3]*10;

	nleft	=	nrec[0]*10;				
	ntop	=	nrec[1]*10;				
	nright	=	nrec[2]*10;				
	ndow	=	nrec[3]*10;
	
	WriteLog("srcwindows[%d][%d][%d][%d]", pleft,ptop,pright,pdow);
	WriteLog("newwindows[%d][%d][%d][%d]", nleft,ntop,nright,ndow);

	if (m_nDecodeType == 0)
	{
		RECT rect;
		if((m_nWidth == 0 && m_nHight == 0) || (nleft == 0 && ntop == 0))
		{
			IVS_MEDIA_INFO  MediaInfo = {0};
			IVS_INT32 iRet = IVS_SDK_GetMediaInfo(m_nHWHandle, m_nPlatPlayId, &MediaInfo);
			if (IVS_SUCCEED == iRet)
			{
				/*获取图像尺寸*/
				m_nWidth = MediaInfo.uiVideoWidth;
				m_nHight = MediaInfo.uiVideoHeight;

				m_Xlpoit=m_nWidth*nleft/(pright-pleft);
				m_Xrpoit=m_nWidth*nright/(pright-pleft);
				m_Ytpoit=m_nHight*ntop/(pdow-ptop);
				m_Ydpoit=m_nHight*ndow/(pdow-ptop);
				WriteLog("IVS_SDK_GetMediaInfo ok[%d]x[%d]", m_nWidth,m_nHight);
			}
			else
			{
				WriteLog("IVS_SDK_GetMediaInfo Err[%d]", iRet);
				return false;
			}
		}
		else
		{
			int nWidth,nHight;
			int x=m_Xlpoit;
			int y=m_Ytpoit;
			nWidth=m_Xrpoit-m_Xlpoit;
			nHight=m_Ydpoit-m_Ytpoit;

			m_Xlpoit=(nWidth*nleft/(pright-pleft))+x;
			m_Xrpoit=(nWidth*nright/(pright-pleft))+x;
			m_Ytpoit=(nHight*ntop/(pdow-ptop))+y;
			m_Ydpoit=(nHight*ndow/(pdow-ptop))+y;

		}
		/* bottom top left right是需要放大区域的矩形坐标*/
		rect.bottom = m_Ydpoit*100/m_nHight;
		rect.top = m_Ytpoit*100/m_nHight;	
		rect.left = m_Xlpoit*100/m_nWidth;
		rect.right = m_Xrpoit*100/m_nWidth;
		//WriteLog("IVS_SDK_UpdateWindowPartial start");
		IVS_INT32 iRet = IVS_SDK_UpdateWindowPartial(m_nHWHandle, m_nPlatPlayId, m_hPlayWnd, &rect);
		if(IVS_SUCCEED != iRet)
		{
			WriteLog("IVS_SDK_UpdateWindowPartial Err[%d]", iRet);
			return false;
		}
	}
	else if (m_nDecodeType == 1)
	{
		DISPLAYRECT rect;
		if((m_nWidth == 0 && m_nHight == 0) || (nleft == 0 && ntop == 0))
		{
			if (PLAY_GetPictureSize(m_nPlayerPort, &m_nWidth, &m_nHight))
			{
				m_Xlpoit=m_nWidth*nleft/(pright-pleft);
				m_Xrpoit=m_nWidth*nright/(pright-pleft);
				m_Ytpoit=m_nHight*ntop/(pdow-ptop);
				m_Ydpoit=m_nHight*ndow/(pdow-ptop);
				WriteLog("PLAY_GetPictureSize ok[%d]x[%d]", m_nWidth,m_nHight);
			}
			else
			{
				WriteLog("PLAY_GetPictureSize Err[%d]", PLAY_GetLastErrorEx());
				return false;
			}
		}
		else
		{
			int nWidth,nHight;
			int x=m_Xlpoit;
			int y=m_Ytpoit;
			nWidth=m_Xrpoit-m_Xlpoit;
			nHight=m_Ydpoit-m_Ytpoit;

			m_Xlpoit=(nWidth*nleft/(pright-pleft))+x;
			m_Xrpoit=(nWidth*nright/(pright-pleft))+x;
			m_Ytpoit=(nHight*ntop/(pdow-ptop))+y;
			m_Ydpoit=(nHight*ndow/(pdow-ptop))+y;

		}
		rect.bottom = m_Ydpoit;
		rect.top = m_Ytpoit;
		rect.left = m_Xlpoit;
		rect.right = m_Xrpoit;
		BOOL bRet = PLAY_SetDisplayRegion(m_nPlayerPort,0,&rect,m_hPlayWnd,true);
		return bRet?true:false;
	}
	return true;
}

bool NetPlugIn::controlPTZSpeedWithChannel(int nCmd, bool bEnable, int nSpeed, int nChannel)
{
	//WriteLog("controlPTZSpeedWithChannel[%d][%d][%d][%d]",nCmd,bEnable,nSpeed,nChannel);
	if (m_nHWHandle == -1)
	{
		return false;
	}
	IVS_INT32 nErrCode = 0;
	IVS_PTZ_CONTROL_INFO nLockStatus = {0};
	IVS_PTZ_CODE nPTZCode =  PTZ_STOP;
	if (!bEnable)
	{
		switch(nCmd)
		{
		case CAMERA_PAN_UP://云台向上
			nPTZCode = PTZ_UP;
			break;
		case CAMERA_PAN_DOWN://云台向下
			nPTZCode = PTZ_DOWN;
			break;
		case CAMERA_PAN_LEFT://云台向左
			nPTZCode = PTZ_LEFT;
			break;
		case CAMERA_PAN_RIGHT://云台向右
			nPTZCode = PTZ_RIGHT;
			break;
		case CAMERA_FOCUS_IN://焦点前调
			nPTZCode = PTZ_LENS_FOCAL_NEAT;
			break;
		case CAMERA_FOCUS_OUT://焦点后调
			nPTZCode = PTZ_LENS_FOCAL_FAR;
			break;
		case CAMERA_IRIS_IN://光圈调大
			nPTZCode = PTZ_LENS_APERTURE_OPEN;
			break;
		case CAMERA_IRIS_OUT://光圈调小
			nPTZCode = PTZ_LENS_APERTURE_CLOSE;
			break;
		case CAMERA_ZOOM_IN://倍率调大
			nPTZCode = PTZ_LENS_ZOOM_IN;
			break;
		case CAMERA_ZOOM_OUT://倍率调小
			nPTZCode = PTZ_LENS_ZOOM_OUT;
			break;
		case CAMERA_LOCK:
			nPTZCode = PTZ_LOCK;
			break;
		case CAMERA_UNLOCK:
			nPTZCode = PTZ_UNLOCK;
			break;
		case CAMERA_LIGHT_CTRL://灯控制
			nErrCode= IVS_SDK_PtzControl(m_nHWHandle, m_szCameraID, NULL, PTZ_AUX_OPEN, "2", "", &nLockStatus);
			return true;
		case CAMERA_BRUSH_CTRL://雨刷控制
			nErrCode= IVS_SDK_PtzControl(m_nHWHandle, m_szCameraID, NULL, PTZ_AUX_OPEN, "1", "", &nLockStatus);
			return true;
		case CAMERA_HEATER_CTRL://加热器控制
			break;
		case CAMERA_SETP:
			m_nSrcWind = nSpeed;
			return true;
		case CAMERA_SETN:
			m_nNewWind = nSpeed;
			return EXACTGOTO();
		default:
			return false;
		}
	}
	char pSpeed[4] = {0};
	sprintf_s(pSpeed, sizeof(pSpeed), "%d", nSpeed);
	nErrCode = IVS_SDK_PtzControl(m_nHWHandle, m_szCameraID, NULL, nPTZCode, "2", pSpeed, &nLockStatus);
	if (nErrCode != IVS_SUCCEED)
	{
		return false;
	}
	return true;
}

bool NetPlugIn::controlPTZSpeed(int nCmd, bool bEnable,int nSpeed)
{
	return controlPTZSpeedWithChannel(nCmd,bEnable,nSpeed,m_nChannel);
}

bool NetPlugIn::presetPTZWithChannel(int nCmd, int nIndex, int nChannel)
{
	if (m_nHWHandle == -1)
	{
		return false;
	}
    IVS_INT32 nErrCode = 0;
	IVS_UINT32 uiIndex = 0;
    char pPTZPresetName[64] = {0};
    sprintf_s(pPTZPresetName, sizeof(pPTZPresetName), "PTZPreset%03d", nIndex);
    switch(nCmd)
    {
    case PTZ_PRESET_SET: 
        nErrCode = IVS_SDK_AddPTZPreset(m_nHWHandle, m_szCameraID, pPTZPresetName, &uiIndex);
        break;
    case PTZ_PRESET_DELETE:
		uiIndex = GetHWPreset(nIndex);
        if(uiIndex == 0)    //未找到指定预置位
        {
            return false;
        }
        nErrCode = IVS_SDK_DelPTZPreset(m_nHWHandle, m_szCameraID, uiIndex);
        break;
    case PTZ_PRESET_GOTO:
		{
			IVS_UINT32 uiIndex = GetHWPreset(nIndex);
			if(uiIndex == 0)    //未找到指定预置位
			{
				return false;
			};
			IVS_PTZ_CONTROL_INFO nLockStatus = { 0 }; 
			char pIndex[10] = {0};
			sprintf_s(pIndex, sizeof(pIndex), "%u", uiIndex);
			nErrCode = IVS_SDK_PtzControl(m_nHWHandle, m_szCameraID, NULL, PTZ_PREFAB_BIT_RUN, pIndex, "", &nLockStatus);
		}
        break;
    default:
        return false;
    }
	return true;
}

bool NetPlugIn::presetPTZ(int nCmd, int nIndex)
{
	return presetPTZWithChannel(nCmd, nIndex, m_nChannel);
}

int NetPlugIn::GetHWPreset(int nIndex)
{
	char pPTZPresetName[64] = {0};
	sprintf_s(pPTZPresetName, sizeof(pPTZPresetName), "PTZPreset%03d", nIndex);
	IVS_UINT32 uiIndex = 0;
	IVS_UINT32 uiPresetNum = 0;
	IVS_PTZ_PRESET  PresetList[128] = {0};
	IVS_INT32 nErrCode = IVS_SDK_GetPTZPresetList(m_nHWHandle, m_szCameraID, PresetList, sizeof(PresetList), &uiPresetNum);
	if(nErrCode != IVS_SUCCEED)
	{
		return 0;
	}
	else
	{
		for(int i = 0; i < (int)uiPresetNum; i ++)
		{
			if(strcmp(PresetList[i].cPresetName, pPTZPresetName) == 0)
			{
				uiIndex = PresetList[i].uiPresetIndex;
				break;
			}
		}
		if(uiIndex == 0)
		{
			return 0;
		}
	}
	return uiIndex;
}

RECORDFILE* NetPlugIn::getRecordFile(int nType,char* startTime,char* endTime,int* nFileCount)
{
	//WriteLog("getRecordFile:[type:%d][st:%s][et:%s]", nType,startTime,endTime);
	RECORDFILE recinfo[100] = {0};
	int nCount = getRecordFileEx(nType,startTime,endTime,recinfo,100);
	if (nCount > 0)
	{
		RECORDFILE *pInfo = new RECORDFILE[nCount+1];
		memcpy(pInfo, &recinfo, sizeof(RECORDFILE)*nCount);
		*nFileCount = nCount;
		return pInfo;
	}
	return NULL;
}

int NetPlugIn::getRecordFileEx(int nType,char* startTime,char* endTime,RECORDFILE pRecordFile[],int nMaxFileCount)
{
	WriteLog("getRecordFileEx:[type:%d][st:%s][et:%s][max:%d]", nType,startTime,endTime,nMaxFileCount);
	char szBeginTime[20] = {0};
	char szStopTime[20] = {0};
	int y1=0,m1=0,d1=0,h1=0,n1=0,s1=0,y2=0,m2=0,d2=0,h2=0,n2=0,s2=0;
	if (strlen(startTime) == 19)		//1234-67-90 23:56:89
	{
		if (m_bRts)
		{
			sscanf(startTime,"%04d-%02d-%02dt%02d:%02d:%02d",&y1,&m1,&d1,&h1,&n1,&s1);
			sscanf(endTime,"%04d-%02d-%02dt%02d:%02d:%02d",&y2,&m2,&d2,&h2,&n2,&s2);
		}
		else
		{
			sscanf(startTime,"%04d-%02d-%02d %02d:%02d:%02d",&y1,&m1,&d1,&h1,&n1,&s1);
			sscanf(endTime,"%04d-%02d-%02d %02d:%02d:%02d",&y2,&m2,&d2,&h2,&n2,&s2);
		}
		sprintf(szBeginTime,"%04d%02d%02d%02d%02d%02d",y1,m1,d1,h1,n1,s1);
		sprintf(szStopTime,"%04d%02d%02d%02d%02d%02d",y2,m2,d2,h2,n2,s2);
	}
	else if (strlen(startTime) == 14)	//20180101235959
	{
		sscanf(startTime,"%04d%02d%02d%02d%02d%02d",&y1,&m1,&d1,&h1,&n1,&s1);
		sscanf(endTime,"%04d%02d%02d%02d%02d%02d",&y2,&m2,&d2,&h2,&n2,&s2);
	}
	tm time1 = {0};
	time1.tm_year = y1 - 1900;
	time1.tm_mon = m1 - 1;
	time1.tm_mday = d1;
	time1.tm_hour = h1;
	time1.tm_min = n1;
	time1.tm_sec = s1;
	tm time2 = {0};
	time2.tm_year = y2 - 1900;
	time2.tm_mon = m2 - 1;
	time2.tm_mday = d2;
	time2.tm_hour = h2;
	time2.tm_min = n2;
	time2.tm_sec = s2;
	time_t st = mktime(&time1);
	time_t et = mktime(&time2);
	st -= 8*60*60;
	et -= 8*60*60;
	memcpy(&time1,localtime(&st),sizeof(tm));
	memcpy(&time2,localtime(&et),sizeof(tm));
	memset(pRecordFile,0,sizeof(RECORDFILE)*nMaxFileCount);
	if (m_nRecodeType == 1)
	{
		nType = 1;
	}
	if (nType == 0)		//按文件查询
	{
		IVS_TIME_SPAN TimeSpan;
		memset(&TimeSpan,0,sizeof(IVS_TIME_SPAN));
		sprintf(TimeSpan.cStart,"%04d%02d%02d%02d%02d%02d",time1.tm_year+1900,time1.tm_mon+1,time1.tm_mday,time1.tm_hour,time1.tm_min,time1.tm_sec);
		sprintf(TimeSpan.cEnd,"%04d%02d%02d%02d%02d%02d",time2.tm_year+1900,time2.tm_mon+1,time2.tm_mday,time2.tm_hour,time2.tm_min,time2.tm_sec);

		IVS_INDEX_RANGE IndexRange = {1, nMaxFileCount};
		IVS_UINT32 uiBufSize = sizeof(IVS_RECORD_INFO_LIST) + (nMaxFileCount - 1) * sizeof(IVS_RECORD_INFO);
		IVS_RECORD_INFO_LIST* pRecordList = (IVS_RECORD_INFO_LIST*)(new IVS_CHAR[uiBufSize]); 
		memset(pRecordList, 0 ,uiBufSize); 

		IVS_INT32 iRet = IVS_SDK_GetRecordList(m_nHWHandle, m_szCameraID, NULL, 0, &TimeSpan, &IndexRange, pRecordList, uiBufSize); 
		if (IVS_SUCCEED == iRet) 
		{ 
			 IVS_UINT32 uiNum = (pRecordList->stIndexRange.uiToIndex - pRecordList->stIndexRange.uiFromIndex) + 1; 
			 uiNum = (uiNum > pRecordList->uiTotal) ? pRecordList->uiTotal : uiNum;

			 for (IVS_UINT32 i=0; i<uiNum; i++) 
			 { 
				sscanf(pRecordList->stRecordInfo[i].stTime.cStart,"%04d%02d%02d%02d%02d%02d",&y1,&m1,&d1,&h1,&n1,&s1);
				sscanf(pRecordList->stRecordInfo[i].stTime.cEnd,"%04d%02d%02d%02d%02d%02d",&y2,&m2,&d2,&h2,&n2,&s2);
				time1.tm_year = y1 - 1900;
				time1.tm_mon = m1 - 1;
				time1.tm_mday = d1;
				time1.tm_hour = h1;
				time1.tm_min = n1;
				time1.tm_sec = s1;
				time2.tm_year = y2 - 1900;
				time2.tm_mon = m2 - 1;
				time2.tm_mday = d2;
				time2.tm_hour = h2;
				time2.tm_min = n2;
				time2.tm_sec = s2;
				st = mktime(&time1);
				et = mktime(&time2);
				st += 8*60*60;
				et += 8*60*60;
				memcpy(&time1,localtime(&st),sizeof(tm));
				memcpy(&time2,localtime(&et),sizeof(tm));
				sprintf(pRecordFile[i].startTime,"%04d-%02d-%02d %02d:%02d:%02d",time1.tm_year+1900,time1.tm_mon+1,time1.tm_mday,time1.tm_hour,time1.tm_min,time1.tm_sec);
				sprintf(pRecordFile[i].endTime,"%04d-%02d-%02d %02d:%02d:%02d",time2.tm_year+1900,time2.tm_mon+1,time2.tm_mday,time2.tm_hour,time2.tm_min,time2.tm_sec);
				if (pRecordList->stRecordInfo[i].cNvrCode[0] != '\0')
				{
					memcpy(pRecordFile[i].sFileName,pRecordList->stRecordInfo[i].cNvrCode,IVS_NVR_CODE_LEN);
				}
				else
				{
					memcpy(pRecordFile[i].sFileName,pRecordList->stRecordInfo[i].cRecordFileName,IVS_FILE_NAME_LEN);
				}
				pRecordFile[i].nSize = (int)(et-st) * 8 * 1024;
				pRecordFile[i].nType = 0;
			 } 
			 delete[] pRecordList;
			 pRecordList = NULL;
			 return uiNum;
		} 
		delete[] pRecordList;
		pRecordList = NULL; 
	}
	else				//按时间查询
	{
		strcpy(pRecordFile[0].startTime,startTime);
		strcpy(pRecordFile[0].endTime,endTime);
		sprintf(pRecordFile[0].sFileName,"HWRecFile_%s_%s",szBeginTime,szStopTime);
		pRecordFile[0].nSize = (int)(et-st) * 1024;
		if (m_nRecodeType == 1)
		{
			pRecordFile[0].nType = 0;
		}
		else
		{
			pRecordFile[0].nType = 1;
		}
		WriteLog("getRecordFileEx return 1:[%s][%s][%s][%d]",pRecordFile[0].sFileName,pRecordFile[0].startTime, pRecordFile[0].endTime,pRecordFile[0].nSize);
		return 1;
	}
	return 0;
}

intptr_t NetPlugIn::captureFileStream(LPCAPTURESTREAMCALLBACK lpCallBack, void* pUser, int nStreamType, RECORDFILE FileInfo, char* sType)
{
	printf("历史回放请求[%s][%s]\n",FileInfo.startTime,FileInfo.endTime);
	char *sStart = FileInfo.startTime;
	char *sEnd = FileInfo.endTime;
	int y1=0,m1=0,d1=0,h1=0,n1=0,s1=0,y2=0,m2=0,d2=0,h2=0,n2=0,s2=0;
	if (strlen(sStart) == 19)
	{
		if (m_bRts)
		{
			sscanf(sStart,"%04d-%02d-%02dt%02d:%02d:%02d",&y1,&m1,&d1,&h1,&n1,&s1);
			sscanf(sEnd,"%04d-%02d-%02dt%02d:%02d:%02d",&y2,&m2,&d2,&h2,&n2,&s2);
		}
		else
		{
			sscanf(sStart,"%04d-%02d-%02dt%02d:%02d:%02d",&y1,&m1,&d1,&h1,&n1,&s1);
			sscanf(sEnd,"%04d-%02d-%02dt%02d:%02d:%02d",&y2,&m2,&d2,&h2,&n2,&s2);
		}
	}
	else if (strlen(sStart) == 14)
	{
		sscanf(sStart,"%04d%02d%02d%02d%02d%02d",&y1,&m1,&d1,&h1,&n1,&s1);
		sscanf(sEnd,"%04d%02d%02d%02d%02d%02d",&y2,&m2,&d2,&h2,&n2,&s2);
	}
	else
	{
		return -1;
	}
	tm time1 = {0};	
	time1.tm_year = y1 - 1900;
	time1.tm_mon = m1 - 1;
	time1.tm_mday = d1;
	time1.tm_hour = h1;
	time1.tm_min = n1;
	time1.tm_sec = s1;
	tm time2 = {0};
	time2.tm_year = y2 - 1900;
	time2.tm_mon = m2 - 1;
	time2.tm_mday = d2;
	time2.tm_hour = h2;
	time2.tm_min = n2;
	time2.tm_sec = s2;
	time_t st = mktime(&time1);
	time_t et = mktime(&time2);
	st -= 8*60*60;
	et -= 8*60*60;
	m_nRecTotalTime = et - st;
	memcpy(&time1,localtime(&st),sizeof(tm));
	memcpy(&time2,localtime(&et),sizeof(tm));
	sprintf(sStart,"%04d%02d%02d%02d%02d%02d",time1.tm_year+1900,time1.tm_mon+1,time1.tm_mday,time1.tm_hour,time1.tm_min,time1.tm_sec);
	sprintf(sEnd,"%04d%02d%02d%02d%02d%02d",time2.tm_year+1900,time2.tm_mon+1,time2.tm_mday,time2.tm_hour,time2.tm_min,time2.tm_sec);

	m_pStreamCb = lpCallBack;
	m_pUser = pUser;

	IVS_PLAYBACK_PARAM PlayBackInfo;
	memset(&PlayBackInfo, 0, sizeof(IVS_PLAYBACK_PARAM));
	PlayBackInfo.uiProtocolType = m_nProtocolType;
	PlayBackInfo.fSpeed = 0.5;
	strcpy(PlayBackInfo.stTimeSpan.cStart,sStart);
	strcpy(PlayBackInfo.stTimeSpan.cEnd,sEnd);

	IVS_INT32 nErrCode = IVS_SDK_StartPlatformPlayBackCBRaw(m_nHWHandle, m_szCameraID, &PlayBackInfo, PlaBackCBRaw, this, &m_nPlaybackId);
	if(nErrCode != IVS_SUCCEED)
	{
		printf("播放华为平台镜头历史回放[%s][%s-%s]失败 error:%d!\n",m_szCameraID,PlayBackInfo.stTimeSpan.cStart,PlayBackInfo.stTimeSpan.cEnd,nErrCode);
		m_nPlaybackId = 0; 
		return -1;
	}
	printf("播放华为平台镜头历史回放[%s][%s-%s]成功! handle[%d]\n",m_szCameraID,PlayBackInfo.stTimeSpan.cStart,PlayBackInfo.stTimeSpan.cEnd,m_nPlaybackId);
	m_fReplayNormal = 0.5;
	m_fReplaySpeed = 0.5;
	m_nRecPosConunt = 0;
	return m_nPlaybackId;
}

IVS_VOID NetPlugIn::PlaBackCBRaw(IVS_ULONG ulHandle,IVS_RAW_FRAME_INFO* pRawFrameInfo,IVS_VOID* pBuf,IVS_UINT32 uiBufSize,IVS_VOID* pUserData)
{
	NetPlugIn *pThis = (NetPlugIn*)pUserData;
	if (pThis == NULL || pThis->m_nPlaybackId == 0 || pThis->m_pStreamCb == NULL)
	{
		return;
	}
	if (pThis->m_nRecTimeTick == 0)
	{
		pThis->m_nRecTimeTick = pRawFrameInfo->ullTimeTick;
	}
	pThis->m_nRecPos = (pRawFrameInfo->ullTimeTick - pThis->m_nRecTimeTick) / (pThis->m_nRecTotalTime * 10);

	if (!pThis->m_bRts)
	{
		if (!pThis->m_bFirstData)
		{
			pThis->m_pStreamCb((long)pThis, DVR_DATA_INIT, (BYTE*)pBuf, uiBufSize, pThis->m_pUser);
			pThis->m_bFirstData = true;
		}
		pThis->m_pStreamCb((long)pThis, DVR_DATA_STREAM, (BYTE*)pBuf, uiBufSize, pThis->m_pUser);
		return;
	}
	//if (pRawFrameInfo->uiStreamType == PAY_LOAD_TYPE_H264)
	//{
	//	if (!pThis->m_bFirstData)
	//	{
	//		pThis->m_pStreamCb(-1, 96, (BYTE*)"H264", 4, pThis->m_pUser);
	//		pThis->m_bFirstData = true;
	//	}
	//	if (pRawFrameInfo->uiFrameType == 6)
	//	{
	//	}
	//	else if (pRawFrameInfo->uiFrameType == 9)
	//	{
	//	}
	//	else if (pRawFrameInfo->uiFrameType == 7 || pRawFrameInfo->uiFrameType == 8)
	//	{
	//		memcpy(pThis->m_pKeyFrameBuf + pThis->m_nKeyFramelen, pBuf, uiBufSize);
	//		pThis->m_nKeyFramelen += uiBufSize;
	//	}
	//	else if (pRawFrameInfo->uiFrameType == 5)
	//	{
	//		memcpy(pThis->m_pKeyFrameBuf + pThis->m_nKeyFramelen, pBuf, uiBufSize);
	//		pThis->m_nKeyFramelen += uiBufSize;
	//		pThis->m_pStreamCb(0, DVR_DATA_STREAM, pThis->m_pKeyFrameBuf, pThis->m_nKeyFramelen, pThis->m_pUser);
	//		pThis->m_nKeyFramelen = 0;
	//	}
	//	else
	//	{
	//		pThis->m_pStreamCb(0, DVR_DATA_STREAM, (BYTE*)pBuf, uiBufSize, pThis->m_pUser);
	//	}
	//}
	//else if (pRawFrameInfo->uiStreamType == PAY_LOAD_TYPE_H265)
	//{
	//	if (pRawFrameInfo->uiFrameType == 39)
	//	{
	//	}
	//	else if (pRawFrameInfo->uiFrameType == 32 || pRawFrameInfo->uiFrameType == 33 || pRawFrameInfo->uiFrameType == 34)
	//	{
	//		memcpy(pThis->m_pKeyFrameBuf + pThis->m_nKeyFramelen, pBuf, uiBufSize);
	//		pThis->m_nKeyFramelen += uiBufSize;
	//	}
	//	else if (pRawFrameInfo->uiFrameType == 19)	//关键帧
	//	{
	//		if (!pThis->m_bFirstData)
	//		{
	//			pThis->m_nCodec = hevc2avc_init(CODEC_TYPE_H265, pRawFrameInfo->uiWidth, pRawFrameInfo->uiHeight, pThis->m_nDestWidth, pThis->m_nDestHeight, pThis->m_nDestBitrate);
	//			if (pThis->m_nCodec > 0)
	//			{
	//				hevc2avc_setcb(pThis->m_nCodec, AVCFrameCBFun, pThis);
	//			}
	//			pThis->m_pStreamCb(-1, 96, (BYTE*)"H264", 4, pThis->m_pUser);
	//			pThis->m_bFirstData = true;
	//		}
	//		memcpy(pThis->m_pKeyFrameBuf + pThis->m_nKeyFramelen, pBuf, uiBufSize);
	//		pThis->m_nKeyFramelen += uiBufSize;
	//		if (pThis->m_nCodec > 0)
	//		{
	//			hevc2avc_input(pThis->m_nCodec, pThis->m_pKeyFrameBuf, pThis->m_nKeyFramelen);
	//		}
	//		pThis->m_nKeyFramelen = 0;
	//	}
	//	else										//非关键帧
	//	{
	//		if (pThis->m_bFirstData && pThis->m_nCodec > 0)
	//		{
	//			hevc2avc_input(pThis->m_nCodec, (BYTE*)pBuf, uiBufSize);
	//		}
	//	}
	//}
	//else
	//{
	//}
}

bool NetPlugIn::controlReplayRecordFile(intptr_t lReplayHandle,int nCmd,int nInValue,int* outValue)
{
	//WriteLog("controlReplayRecordFile:[%d][cmd:%d][%d]", lReplayHandle,nCmd,nInValue);
	if (m_nHWHandle == -1 || lReplayHandle == -1)
	{
		return false;
	}

    bool bRet = true;
	switch(nCmd)
	{
	case REPLAY_CTRL_PLAYSTART:
		{
			return true;
		}
	case REPLAY_CTRL_PLAYPAUSE://暂停播放
		{
			IVS_INT32 nStatus = IVS_SDK_PlayBackPause(m_nHWHandle, lReplayHandle);  
			break;
		}
	case REPLAY_CTRL_PLAYRESTART://恢复播放
		{
			IVS_INT32 nStatus = IVS_SDK_PlayBackResume(m_nHWHandle, lReplayHandle);
			break;
		}
	case REPLAY_CTRL_PLAYNORMAL://正常播放
		{
			IVS_INT32 nStatus = IVS_SDK_SetPlayBackSpeed(m_nHWHandle, lReplayHandle, m_fReplayNormal);
			m_fReplaySpeed = m_fReplayNormal;
			break;
		}
	case REPLAY_CTRL_PLAYFRAME://单帧放
		{
			if (nInValue == 0)
			{
				IVS_INT32 nStatus = IVS_SDK_PlayBackFrameStepForward(m_nHWHandle, lReplayHandle); 
			}
			else
			{
				IVS_INT32 nStatus = IVS_SDK_PlayBackFrameStepBackward(m_nHWHandle, lReplayHandle);
			}
			break;
		}
	case REPLAY_CTRL_PLAYFAST://快放
		{	
			if (nInValue == 1)	//快退
			{
				if (m_fReplaySpeed == -4.0)
				{
                    bRet = false;
                    break;
				}
				if (m_fReplaySpeed > 0.0)
				{
					m_fReplaySpeed = -1.0;
				}
				else
				{
					m_fReplaySpeed *= 2;
				}
			}
			else
			{
				if (m_fReplaySpeed == 4.0)
				{
                    bRet = false;
                    break;
				}
				m_fReplaySpeed *= 2;
			}
			IVS_INT32 nStatus = IVS_SDK_SetPlayBackSpeed(m_nHWHandle, lReplayHandle, m_fReplaySpeed);
			break;
		}
	case REPLAY_CTRL_PLAYSLOW://慢放
		{
			if (nInValue == 1)	//慢退
			{
				if (m_fReplaySpeed == -0.25)
				{
                    bRet = false;
					break;
				}
				if (m_fReplaySpeed > 0.0)
				{
					m_fReplaySpeed = -1.0;
				}
				else
				{
					m_fReplaySpeed /= 2;
				}
			}
			else
			{
				if (m_fReplaySpeed == 0.0625)
				{
                    bRet = false;
                    break;
				}
				m_fReplaySpeed /= 2;
			}
			IVS_INT32 nStatus = IVS_SDK_SetPlayBackSpeed(m_nHWHandle, lReplayHandle, m_fReplaySpeed);
			break;
		}
	case REPLAY_CTRL_PLAYSTARTAUDIO://打开声音
		{
			IVS_SDK_PlaySound(m_nHWHandle, lReplayHandle);
			break;
		}
	case REPLAY_CTRL_PLAYSTOPAUDIO://关闭声音
		{
			IVS_SDK_StopSound(m_nHWHandle, lReplayHandle);
			break;
		}
	case REPLAY_CTRL_PLAYAUDIOVOLUME://调节音量
		{
			IVS_SDK_SetVolume(m_nHWHandle, lReplayHandle, nInValue);
			break;
		}
	case REPLAY_CTRL_PLAYSETPOS://改变文件回放的进度
		{
			IVS_UINT32 nTime = m_nRecTotalTime * nInValue / 100;
			IVS_INT32 nStatus = IVS_SDK_SetPlayBackTime(m_nHWHandle, lReplayHandle, nTime);
			break;
		}
	case REPLAY_CTRL_PLAYGETPOS://获取文件回放的进度
		{
			if (m_nPlaybackId != 0)
			{
				if (m_nRecPos >= 100)
				{
					if (m_nRecPosConunt >= 3)
					{
						*outValue =  100;
					}
					else
					{
						m_nRecPosConunt++;
						*outValue =  99;
					}
				}
				else
				{
					*outValue = m_nRecPos;
				}
			}
			else
			{
				IVS_PLAYBACK_TIME pPlaybackTime;
				IVS_INT32 nRet = IVS_SDK_GetPlayBackTime(m_nHWHandle, lReplayHandle, &pPlaybackTime);
				if (nRet == IVS_SUCCEED)
				{
					int y1=0,m1=0,d1=0,h1=0,n1=0,s1=0,y2=0,m2=0,d2=0,h2=0,n2=0,s2=0;
					sscanf(pPlaybackTime.cPlayBackStartTime,"%04d%02d%02d%02d%02d%02d",&y1,&m1,&d1,&h1,&n1,&s1);
					sscanf(pPlaybackTime.cPlayBackTime,"%04d%02d%02d%02d%02d%02d",&y2,&m2,&d2,&h2,&n2,&s2);
					tm time1 = {0};	
					time1.tm_year = y1 - 1900;
					time1.tm_mon = m1 - 1;
					time1.tm_mday = d1;
					time1.tm_hour = h1;
					time1.tm_min = n1;
					time1.tm_sec = s1;
					tm time2 = {0};
					time2.tm_year = y2 - 1900;
					time2.tm_mon = m2 - 1;
					time2.tm_mday = d2;
					time2.tm_hour = h2;
					time2.tm_min = n2;
					time2.tm_sec = s2;
					time_t st = mktime(&time1);
					time_t et = mktime(&time2);
					*outValue = (et-st) * 100 / m_nRecTotalTime;
				}
			}
			break;
		}
	case REPLAY_CTRL_PLAYGETTIME://获取当前已经播放的时间
		{
			IVS_PLAYBACK_TIME pPlaybackTime;
			IVS_INT32 nRet = IVS_SDK_GetPlayBackTime(m_nHWHandle, lReplayHandle, &pPlaybackTime);
			if (nRet == IVS_SUCCEED)
			{
				int y1=0,m1=0,d1=0,h1=0,n1=0,s1=0,y2=0,m2=0,d2=0,h2=0,n2=0,s2=0;
				sscanf(pPlaybackTime.cPlayBackStartTime,"%04d%02d%02d%02d%02d%02d",&y1,&m1,&d1,&h1,&n1,&s1);
				sscanf(pPlaybackTime.cPlayBackTime,"%04d%02d%02d%02d%02d%02d",&y2,&m2,&d2,&h2,&n2,&s2);
				tm time1 = {0};	
				time1.tm_year = y1 - 1900;
				time1.tm_mon = m1 - 1;
				time1.tm_mday = d1;
				time1.tm_hour = h1;
				time1.tm_min = n1;
				time1.tm_sec = s1;
				tm time2 = {0};
				time2.tm_year = y2 - 1900;
				time2.tm_mon = m2 - 1;
				time2.tm_mday = d2;
				time2.tm_hour = h2;
				time2.tm_min = n2;
				time2.tm_sec = s2;
				time_t st = mktime(&time1);
				time_t et = mktime(&time2);
				*outValue = et - st;
			}
			break;
		}
	case REPLAY_CTRL_PLAYSETTIME:
		{
			IVS_SDK_SetPlayBackTime(m_nHWHandle, lReplayHandle, nInValue);
		}
	case REPLAY_CTRL_GETTOTALTIME://获取当前播放文件总的时间
		{
			*outValue = m_nRecTotalTime;
			break;
		}
	case REPLAY_CTRL_PLAYGETFRAME://获取当前已经播放的帧数
		{
			return false;
		}
	case REPLAY_CTRL_GETTOTALFRAMES://获取当前播放文件总的帧数
		{
			return false;
		}
	default:
		return false;
	}
	return bRet;
}

IVS_VOID __SDK_CALL PlaBackDecodeCb(IVS_ULONG ulHandle, IVS_RAW_FRAME_INFO* pRawFrameInfo, IVS_VOID* pBuf, IVS_UINT32 uiBufSize, IVS_VOID* pUserData)
{
	NetPlugIn *pThis = (NetPlugIn *)pUserData;
	if (pThis == NULL || pThis->m_nPlatRePlayId == 0)
	{
		return;
	}
	if (pThis->m_bSavefile)
	{
		if (pThis->m_vfile)
		{
			fwrite(pBuf, uiBufSize, 1, pThis->m_vfile);
		}
	}
	if (pRawFrameInfo)
	{
		if (pRawFrameInfo->uiStreamType == PAY_LOAD_TYPE_PCMU || pRawFrameInfo->uiStreamType == PAY_LOAD_TYPE_PCMA)
		{

		}
		else
		{
			pThis->addData((BYTE *)pBuf, uiBufSize);
		}
	}
	
}

intptr_t NetPlugIn::replayRecordFile(HWND hWnd,char* fileName,char* startTime, char* endTime,int nFileSize)
{
	//WriteLog("replayRecordFile:[%s][%s][%s][%d]",fileName,startTime,endTime,nFileSize);
	if (startTime == NULL || endTime == NULL || startTime[0] == '\0' || endTime[0] == '\0')
	{
		WriteLog("replayRecordFile Param Error");
		return -1;
	}
	int y1=0,m1=0,d1=0,h1=0,n1=0,s1=0,y2=0,m2=0,d2=0,h2=0,n2=0,s2=0;
	if (strlen(startTime) == 19)
	{
		sscanf(startTime,"%04d-%02d-%02d %02d:%02d:%02d",&y1,&m1,&d1,&h1,&n1,&s1);
		sscanf(endTime,"%04d-%02d-%02d %02d:%02d:%02d",&y2,&m2,&d2,&h2,&n2,&s2);
	}
	else if (strlen(startTime) == 14)
	{
		sscanf(startTime,"%04d%02d%02d%02d%02d%02d",&y1,&m1,&d1,&h1,&n1,&s1);
		sscanf(endTime,"%04d%02d%02d%02d%02d%02d",&y2,&m2,&d2,&h2,&n2,&s2);
	}
	else
	{
		WriteLog("replayRecordFile TimeParam Error");
		return -1;
	}
	tm time1 = {0};	
	time1.tm_year = y1 - 1900;
	time1.tm_mon = m1 - 1;
	time1.tm_mday = d1;
	time1.tm_hour = h1;
	time1.tm_min = n1;
	time1.tm_sec = s1;
	tm time2 = {0};
	time2.tm_year = y2 - 1900;
	time2.tm_mon = m2 - 1;
	time2.tm_mday = d2;
	time2.tm_hour = h2;
	time2.tm_min = n2;
	time2.tm_sec = s2;
	time_t st = mktime(&time1);
	time_t et = mktime(&time2);
	st -= 8*60*60;
	et -= 8*60*60;
	m_nRecTotalTime = et - st;
	memcpy(&time1,localtime(&st),sizeof(tm));
	memcpy(&time2,localtime(&et),sizeof(tm));
	sprintf(startTime,"%04d%02d%02d%02d%02d%02d",time1.tm_year+1900,time1.tm_mon+1,time1.tm_mday,time1.tm_hour,time1.tm_min,time1.tm_sec);
	sprintf(endTime,"%04d%02d%02d%02d%02d%02d",time2.tm_year+1900,time2.tm_mon+1,time2.tm_mday,time2.tm_hour,time2.tm_min,time2.tm_sec);

	IVS_PLAYBACK_PARAM PlayBackInfo;
	memset(&PlayBackInfo,0,sizeof(IVS_PLAYBACK_PARAM));
	PlayBackInfo.uiProtocolType = m_nProtocolType;
	strcpy(PlayBackInfo.stTimeSpan.cStart,startTime);
	strcpy(PlayBackInfo.stTimeSpan.cEnd,endTime);
	
	if (m_nRecodeType == 0)
	{
		if (fileName != NULL && fileName[0] != '\0')
		{
			strcpy(PlayBackInfo.cNVRCode, fileName);
		}
	}

	WriteLog("replayRecordFile [%lld][%s][%s]", hWnd, startTime, endTime);
	if (m_nDecodeType == 0)
	{
		PlayBackInfo.fSpeed = 1.0;
		IVS_INT32 nErrCode = IVS_SDK_StartPlatformPlayBack(m_nHWHandle, m_szCameraID, &PlayBackInfo, hWnd, &m_nPlatRePlayId);
		if (nErrCode != IVS_SUCCEED)
		{
			WriteLog("播放华为平台镜头历史回放[%s][%s-%s]失败 error:%d!\n", m_szCameraID, PlayBackInfo.stTimeSpan.cStart, PlayBackInfo.stTimeSpan.cEnd, nErrCode);
			printf("播放华为平台镜头历史回放[%s][%s-%s]失败 error:%d!\n", m_szCameraID, PlayBackInfo.stTimeSpan.cStart, PlayBackInfo.stTimeSpan.cEnd, nErrCode);
			m_nPlatRePlayId = 0;
			return -1;
		}
		//RECT rect;
		//if (GetClientRect((HWND)hWnd,&rect))
		//{
		//	if ((rect.right-rect.top)<1024)
		//	{
		//		IVS_SDK_SetPlayQualityMode(m_nHWHandle, m_nPlatRePlayId,PLAY_QUALITY_FLUENCY);
		//	}
		//}
		IVS_SDK_SetDisplayScale(m_nHWHandle, m_nPlatRePlayId, 2);//铺满显示
		m_fReplayNormal = 1.0;
		m_fReplaySpeed = 1.0;
		m_nRecPosConunt = 0;
		WriteLog("replayRecordFile ok! return:[%lld] handle[%lld]", m_nPlatRePlayId, (intptr_t)this);
		IVS_SDK_PlaySound(m_nHWHandle, m_nPlatRePlayId);
	}
	else
	{
		PlayBackInfo.fSpeed = 0.5;
		IVS_INT32 nErrCode = IVS_SDK_StartPlatformPlayBackCBRaw(m_nHWHandle, m_szCameraID, &PlayBackInfo, PlaBackDecodeCb, this, &m_nPlatRePlayId);
		if (nErrCode != IVS_SUCCEED)
		{
			WriteLog("播放华为平台镜头历史回放[%s][%s-%s]失败 error:%d!\n", m_szCameraID, PlayBackInfo.stTimeSpan.cStart, PlayBackInfo.stTimeSpan.cEnd, nErrCode);
			printf("播放华为平台镜头历史回放[%s][%s-%s]失败 error:%d!\n", m_szCameraID, PlayBackInfo.stTimeSpan.cStart, PlayBackInfo.stTimeSpan.cEnd, nErrCode);
			m_nPlatRePlayId = 0;
			return -1;
		}
		initialPlayer(0, 0, NULL, 0, 0);
		startPlayer(hWnd);
		WriteLog("播放华为平台镜头历史回放[%s][%s-%s]成功! handle[%lld]\n", m_szCameraID, PlayBackInfo.stTimeSpan.cStart, PlayBackInfo.stTimeSpan.cEnd, m_nPlatRePlayId);
		m_fReplayNormal = 0.5;
		m_fReplaySpeed = 0.5;
		m_nRecPosConunt = 0;
	}
	return (intptr_t)m_nPlatRePlayId;
}

bool NetPlugIn::stopReplayRecordFile(intptr_t lReplayHandle)
{
	m_pDrawCb = NULL;
	m_pDrawUser = NULL;
	if (lReplayHandle > 0)
	{
		if (m_nDecodeType == 0)
		{
			IVS_SDK_StopSound(m_nHWHandle, lReplayHandle);
		}
		IVS_SDK_StopPlatformPlayBack(m_nHWHandle, lReplayHandle);
		m_nPlatRePlayId = 0;
	}
	return true;
}

bool NetPlugIn::playBackCaptureFile(intptr_t lReplayHandle, char *pFileName)
{
	WriteLog("录像截图[%s] intputhandle[%lld] srchandle[%lld] type[%d]", pFileName, lReplayHandle, m_nPlatRePlayId, m_nDecodeType);
	if (m_nDecodeType == 0)
	{
		if (lReplayHandle != 0)
		{
			IVS_UINT32 nPicType = 1;
			if (strstr(pFileName, ".bmp") || strstr(pFileName, ".BMP"))
			{
				nPicType = 2;
			}
			IVS_INT32 iRet = IVS_SDK_LocalSnapshot(m_nHWHandle, lReplayHandle, nPicType, pFileName);
			
			if (iRet != IVS_SUCCEED)
			{
				WriteLog("录像截图[%s] ret[%d]", pFileName, iRet);
				return false;
			}
		}
		else
			return false;
	}
	else
	{
		return PLAY_CatchPicEx(m_nPlayerPort, pFileName, PicFormat_JPEG) ? true : false;
	}
	return true;
}

bool NetPlugIn::playBackSaveData(intptr_t lReplayHandle,char *sFileName)
{
	if (m_nDecodeType == 0)
	{
		if (lReplayHandle > 0)
		{
			IVS_LOCAL_RECORD_PARAM RecordParam;
			memset(&RecordParam, 0, sizeof(IVS_LOCAL_RECORD_PARAM));
			RecordParam.uiRecordTime = 300;//300秒
			RecordParam.uiRecordFormat = IVS_FILE_MP4;
			RecordParam.uiSplitterType = RECORD_SPLITE_TIME;//按时间分割录像文件
			RecordParam.uiSplitterValue = 60;//每60分钟分割一个文件
			RecordParam.bEncryptRecord = false;
			RecordParam.uiNameRule = RULE_NAME_TIME_NUM;//命名规则
			strcpy(RecordParam.cSavePath, sFileName);
			char *p = strrchr(RecordParam.cSavePath, '\\');
			if (p)
			{
				p[1] = '\0';
			}
			IVS_INT32 iRet = IVS_SDK_StartLocalRecord(m_nHWHandle, &RecordParam, lReplayHandle, NULL); //绝对路径为空则根据命名规则命名
			if (IVS_SUCCEED == iRet)
			{
				return true;
			}
		}
	}
	else
	{
		m_vfile = fopen(sFileName, "ab+");
		if (m_vfile)
		{
			m_bSavefile = true;
			return true;
		}
	}
	return false;
}

bool NetPlugIn::stopPlayBackSave(intptr_t lReplayHandle)
{
	if (m_nDecodeType == 0)
	{
		if (lReplayHandle > 0)
		{
			IVS_SDK_StopLocalRecord(m_nHWHandle, lReplayHandle);
		}
	}
	else
	{
		m_bSavefile = false;
		if (m_vfile)
		{
			fclose(m_vfile);
			m_vfile = NULL;
		}
	}
	return true;
}

intptr_t NetPlugIn::downloadRecordFile(char* fileName,char* startTime, char* endTime,int nFileSize,char* saveFile,LPDOWNLOADRECORDFILECALLBACK lpCallBack,void* pUser)
{
	if (startTime == NULL || endTime == NULL || startTime[0] == '\0' || endTime[0] == '\0')
	{
		WriteLog("downloadRecordFile Time Error");
		return -1;
	}
	int y1=0,m1=0,d1=0,h1=0,n1=0,s1=0,y2=0,m2=0,d2=0,h2=0,n2=0,s2=0;
	if (strlen(startTime) == 19)
	{
		sscanf(startTime,"%04d-%02d-%02d %02d:%02d:%02d",&y1,&m1,&d1,&h1,&n1,&s1);
		sscanf(endTime,"%04d-%02d-%02d %02d:%02d:%02d",&y2,&m2,&d2,&h2,&n2,&s2);
	}
	else if (strlen(startTime) == 14)
	{
		sscanf(startTime,"%04d%02d%02d%02d%02d%02d",&y1,&m1,&d1,&h1,&n1,&s1);
		sscanf(endTime,"%04d%02d%02d%02d%02d%02d",&y2,&m2,&d2,&h2,&n2,&s2);
	}
	else
	{
		WriteLog("downloadRecordFile Time Error[%s][%s]",startTime,endTime);
		return -1;
	}
	tm time1 = {0};	
	time1.tm_year = y1 - 1900;
	time1.tm_mon = m1 - 1;
	time1.tm_mday = d1;
	time1.tm_hour = h1;
	time1.tm_min = n1;
	time1.tm_sec = s1;
	tm time2 = {0};
	time2.tm_year = y2 - 1900;
	time2.tm_mon = m2 - 1;
	time2.tm_mday = d2;
	time2.tm_hour = h2;
	time2.tm_min = n2;
	time2.tm_sec = s2;
	time_t st = mktime(&time1);
	time_t et = mktime(&time2);
	st -= 8*60*60;
	et -= 8*60*60;
	m_nRecTotalTime = et - st;
	memcpy(&time1,localtime(&st),sizeof(tm));
	memcpy(&time2,localtime(&et),sizeof(tm));
	sprintf(startTime,"%04d%02d%02d%02d%02d%02d",time1.tm_year+1900,time1.tm_mon+1,time1.tm_mday,time1.tm_hour,time1.tm_min,time1.tm_sec);
	sprintf(endTime,"%04d%02d%02d%02d%02d%02d",time2.tm_year+1900,time2.tm_mon+1,time2.tm_mday,time2.tm_hour,time2.tm_min,time2.tm_sec);


	IVS_DOWNLOAD_PARAM DownloadInfo;
	memset(&DownloadInfo, 0, sizeof(IVS_DOWNLOAD_PARAM));
	DownloadInfo.uiRecordFormat = IVS_FILE_MP4;
	DownloadInfo.uiSplitterType = RECORD_SPLITE_TIME;
	DownloadInfo.uiSplitterValue = 60;
	DownloadInfo.uiDiskWarningValue = 100;
	DownloadInfo.uiStopRecordValue = 30;
	DownloadInfo.uiDownloadSpeed = 255;
	DownloadInfo.bEncryptRecord = false;
	strcpy(DownloadInfo.stTimeSpan.cStart, startTime);
	strcpy(DownloadInfo.stTimeSpan.cEnd, endTime);
	//strcpy(DownloadInfo.cFileName,saveFile);
	DownloadInfo.uiNameRule = RULE_NAME_TIME_NUM;
	strcpy(DownloadInfo.cSavePath, saveFile);
	char *p = strrchr(DownloadInfo.cSavePath, '\\');
	if (p)
	{
		p[1] = '\0';
	}
	else
	{
		p = strrchr(DownloadInfo.cSavePath, '/');
		if (p)
		{
			p[1] = '\0';
		}
	}
	if (m_nRecodeType == 0)
	{
		if (fileName != NULL && fileName[0] != '\0')
		{
			strcpy(DownloadInfo.cNvrCode, fileName);
		}
	}

	memset(m_szFileName,0,sizeof(m_szFileName));
	memset(m_szSaveFileName,0,sizeof(m_szSaveFileName));
	sprintf(m_szFileName,"%s%s_%04d-%02d-%02d-%02d-%02d-%02d*.mp4", DownloadInfo.cSavePath,m_szCameraID,y1,m1,d1,h1,n1,s1);
	strcpy(m_szSaveFileName, saveFile);

	IVS_INT32 nStatus = IVS_SDK_StartPlatformDownload(m_nHWHandle, m_szCameraID, &DownloadInfo, &m_nDownloadId);

	if(nStatus != IVS_SUCCEED)
	{
		WriteLog("IVS_SDK_StartPlatformDownload error[%s][%d]", DownloadInfo.cSavePath, nStatus);
		return -1;
	}
	WriteLog("IVS_SDK_StartPlatformDownload ok[%s][%d]", saveFile, m_nDownloadId);
	return m_nDownloadId;
}

bool NetPlugIn::stopDownloadRecordFile(intptr_t ldownFileHandle)
{
	if (ldownFileHandle > 0)
	{
		IVS_SDK_StopPlatformDownload(m_nHWHandle, ldownFileHandle);
		renameFile(m_szFileName,m_szSaveFileName);
		m_nDownloadId = 0;
		m_nDownloadPos = 0;
		m_nDownloadCount = 0;
	}
	return true;
}


void NetPlugIn::renameFile(char *oldFileName, char *newFileName)
{
	WriteLog("renameFile[%s][%s]",oldFileName,newFileName);
	WIN32_FIND_DATA stFileInfo;
	HANDLE hFile = FindFirstFile(oldFileName,&stFileInfo);
	if (hFile == INVALID_HANDLE_VALUE)
	{
		return;
	}
	char szFilePath[256] = {0};
	strcpy(szFilePath,newFileName);
	(strrchr(szFilePath, '\\'))[1] = '\0';
	strcat(szFilePath,stFileInfo.cFileName);
	rename(szFilePath,newFileName);
}

int NetPlugIn::getDownloadPos(intptr_t lFileHandle)
{
	IVS_DOWNLOAD_INFO DownLoadInfo;
	memset(&DownLoadInfo, 0, sizeof(IVS_DOWNLOAD_INFO));
	IVS_INT32 nStatus = IVS_SDK_GetDownloadInfo(m_nHWHandle, lFileHandle, &DownLoadInfo);
	if(nStatus != IVS_SUCCEED)
	{
		WriteLog("IVS_SDK_GetDownloadInfo ok[%d]", nStatus);
		return 0;
	}
	

	if (m_nDownloadCount > 2)
	{
		return 100;
	}
	if (m_nDownloadPos == DownLoadInfo.uiDownloadSize && DownLoadInfo.uiDownloadSize != 0)
	{
		m_nDownloadCount++;
		return DownLoadInfo.uiProgress;
	}
	m_nDownloadPos = DownLoadInfo.uiDownloadSize;
	//WriteLog("IVS_SDK_GetDownloadInfo ok[%d][%d]", nStatus,DownLoadInfo.uiProgress);
	return DownLoadInfo.uiProgress;
}

void CALLBACK  DecodeCb(intptr_t identify,int nDataType,BYTE* pBuffer,int nBufferSize,void* pUser)
{
	NetPlugIn *pThis = (NetPlugIn *)pUser;
	if (pThis == NULL || pThis->m_nPlayId == 0)
	{
		return;
	}
	if (nDataType == DVR_DATA_INIT)
	{
		pThis->initialPlayer(0,0,pBuffer,nBufferSize,0);
		pThis->startPlayer(pThis->m_hPlayWnd);
	}
	else
	{
		if (pThis->m_bSavefile)
		{
			if (pThis->m_vfile)
			{
				fwrite(pBuffer,nBufferSize,1,pThis->m_vfile);
			}
		}
		pThis->addData(pBuffer,nBufferSize);
	}
}

bool NetPlugIn::startPlayer4Standard(HWND hWnd,LPDecCBFun lpDecCBFun, int nCameraID)
{
	m_pDecCb = lpDecCBFun;
	m_nCameraID = nCameraID;
	return startPlayerByCamera(hWnd,nCameraID);
}

bool NetPlugIn::startPlayerByCamera(HWND hwndPlay, int nCameraID)
{
	m_nCameraID = nCameraID;
	m_hPlayWnd = hwndPlay;
	if (m_nDecodeType == 0)
	{
		IVS_REALPLAY_PARAM RealPlayInfo = {0};
		RealPlayInfo.uiStreamType = m_nStreamType;
		RealPlayInfo.uiProtocolType = m_nProtocolType;
		RealPlayInfo.bDirectFirst = 0;
		RealPlayInfo.bMultiCast = 0;

		IVS_INT32 nErrCode = IVS_SDK_StartRealPlay(m_nHWHandle,&RealPlayInfo,m_szCameraID,hwndPlay,&m_nPlatPlayId);
		if(nErrCode != IVS_SUCCEED)
		{
			printf("播放华为平台镜头[%s]失败 error:%d!\n",m_szCameraID,nErrCode);
			m_nPlatPlayId = 0; 
			return false;
		}
		//RECT rect;
		//if (GetClientRect(hwndPlay,&rect))
		//{
		//	if ((rect.right-rect.left)<1024)
		//	{
		//		WriteLog("当前窗口大小:[%d][%d]",rect.right-rect.left, rect.bottom-rect.top);
		//		IVS_SDK_SetPlayQualityMode(m_nHWHandle,m_nPlatPlayId,PLAY_QUALITY_FLUENCY);
		//	}
		//}
		IVS_SDK_SetDisplayScale(m_nHWHandle,m_nPlatPlayId,2);
		WriteLog("startPlayerByCamera:PlayId[%d][%d]\n", m_nPlatPlayId,nCameraID);
	}
	else
	{
		return captureStream(DecodeCb,this,0);
	}
	return true;
}

bool NetPlugIn::stopPlayerByCamera(HWND hwndPlay, int nCameraID)
{
	m_pDecCb = NULL;
	m_pDecUser = NULL;
	m_pDrawCb = NULL;
	m_pDrawUser = NULL;
	m_nCameraID = 0;
	if (m_nPlatPlayId != 0)
	{
		IVS_SDK_StopRealPlay(m_nHWHandle, m_nPlatPlayId);
		m_nPlatPlayId = 0;
	}
	else if (m_nPlayId != 0)
	{
		stopPlayer();
		stopCaptureStream();
	}
	return true;
}

bool NetPlugIn::capturePicture(char* sFilePath)
{
	if (m_nDecodeType == 0)
	{
		IVS_UINT32 nPicType = 1;
		if (strstr(sFilePath, ".bmp") || strstr(sFilePath, ".BMP"))
		{
			nPicType = 2;
		}
		IVS_INT32 iRet = IVS_SDK_LocalSnapshot(m_nHWHandle,m_nPlatPlayId,nPicType,sFilePath);
		if (iRet != IVS_SUCCEED)
		{
			return false;
		}
	}
	else if (m_nDecodeType == 1)
	{
		PLAY_CatchPicEx(m_nPlayerPort,sFilePath,PicFormat_JPEG);
	}
	return true;
}

bool NetPlugIn::startRecord(char* saveFile)
{

	if (m_nDecodeType == 0)
	{
		IVS_LOCAL_RECORD_PARAM RecordParam;
		memset(&RecordParam,0,sizeof(IVS_LOCAL_RECORD_PARAM));
		RecordParam.uiRecordTime = 300;//300秒
		RecordParam.uiRecordFormat = IVS_FILE_MP4;
		RecordParam.uiSplitterType = RECORD_SPLITE_TIME;//按时间分割录像文件
		RecordParam.uiSplitterValue = 60;//每60分钟分割一个文件
		RecordParam.bEncryptRecord = false;
		RecordParam.uiNameRule = RULE_NAME_TIME_NUM;//命名规则
		strcpy(RecordParam.cSavePath, saveFile);
		char *p = strrchr(RecordParam.cSavePath, '\\');
		if (p)
		{
			p[1] = '\0';
		}
		IVS_INT32 iRet = IVS_SDK_StartLocalRecord(m_nHWHandle, &RecordParam, m_nPlatPlayId,NULL); //绝对路径为空则根据命名规则命名
		if (IVS_SUCCEED == iRet)
		{
			return true;
		}
	}
	else if (m_nDecodeType == 1)
	{
		m_vfile = fopen(saveFile, "ab+");
		if (m_vfile)
		{
			m_bSavefile = true;
			return true;
		}
		
	}
	return false;
}

bool NetPlugIn::stopRecord()
{
	if (m_nDecodeType == 0)
	{
		IVS_SDK_StopLocalRecord(m_nHWHandle, m_nPlatPlayId);
	}
	else if (m_nDecodeType == 1)
	{
		m_bSavefile = false;
		if (m_vfile)
		{
			fclose(m_vfile);
			m_vfile = NULL;
		}
	}
	return true;
}

IVS_VOID __SDK_CALL DrawCb(IVS_VOID *hDc, IVS_VOID *rc, IVS_UINT64 ullFrameID, IVS_VOID *pUser)
{
	NetPlugIn *pThis = (NetPlugIn *)pUser;
	if (pThis == NULL || pThis->m_pDrawCb == NULL)
	{
		return;
	}
	if (pThis->m_nPlatPlayId > 0)
	{
		//pThis->WriteLog("DrawCb:PlayId[%d][%d]\n", pThis->m_nPlatPlayId,pThis->m_nCameraID);
		pThis->m_pDrawCb(pThis->m_nCameraID,(LONG)pThis->m_nPlatPlayId,(DWORD)hDc,pThis->m_pDrawUser);
	}
	else
	{
		//pThis->WriteLog("DrawCb:RePlayId[%d][%d]\n", pThis->m_nPlatRePlayId,pThis->m_nCameraID);
		pThis->m_pDrawCb(pThis->m_nCameraID,(LONG)pThis->m_nPlatRePlayId,(DWORD)hDc,pThis->m_pDrawUser);
	}
	
}

void CALLBACK fDrawCb(LONG nPort,HDC hDc, void* pUserData)
{
	NetPlugIn* pThis = (NetPlugIn*)pUserData;
	if (pThis == NULL || pThis->m_pDrawCb == NULL)
	{
		return;
	}

	//RECT rect;
	//GetClientRect(pThis->m_hPlayWnd, &rect);
	//int nWidth = rect.right - rect.left;
	//int nHeight = rect.bottom-rect.top;
	//int x=nWidth/4;
	//int y=nHeight/4;

	//int nMode = SetGraphicsMode(hDc, GM_ADVANCED);
	//XFORM xform;
	//double fangle = (double)330/180 * 3.1415926;
	//xform.eM11 = (float)cos(fangle);
	//xform.eM12 = (float)sin(fangle);
	//xform.eM21 = (float)-sin(fangle);
	//xform.eM22 = (float)cos(fangle);
	//xform.eDx = (float)((nWidth/2) - cos(fangle)*(nWidth/2) + sin(fangle)*(nHeight/2));
	//xform.eDy = (float)((nHeight/2) - cos(fangle)*(nHeight/2) - sin(fangle)*(nWidth/2));
	//SetWorldTransform(hDc, &xform);

	//SetTextColor(hDc, RGB(255,255,255));
	//SetBkMode(hDc, TRANSPARENT);
	//TextOutA(hDc,x,y,pThis->m_szShowString,(int)strlen(pThis->m_szShowString));
	//TextOutA(hDc,x,y*3,pThis->m_szShowString,(int)strlen(pThis->m_szShowString));
	////TextOutA(hDc,x*3,y,pThis->m_szShowString,(int)strlen(pThis->m_szShowString));
	//TextOutA(hDc,x*3,y*3,pThis->m_szShowString,(int)strlen(pThis->m_szShowString));
	////pThis->m_pDrawCb((LONG)pThis, nPort, (DWORD)hDc, pThis->m_pDrawUser);
}

bool NetPlugIn::startPlayer2(HWND hWnd, LPDRAWCBCALLLBACK lpDrawCBFun, void *pUser)
{
	//WriteLog("startPlayer2:PlayId[%d]\n", hWnd);
	if (m_nWatermark == 0)
	{
		return false;
	}
	if (m_nDecodeType == 0)	//走华为内部
	{
		IVS_INT32 iRet = 0;
		if (m_nPlatPlayId > 0)
		{
			
			iRet = IVS_SDK_SetDrawCallBackEx(m_nHWHandle, m_nPlatPlayId, hWnd, DrawCb, this);
		}
		else
		{
			iRet = IVS_SDK_SetDrawCallBackEx(m_nHWHandle, m_nPlatRePlayId, hWnd, DrawCb, this);
		}
		if (iRet == IVS_SUCCEED)
		{
			m_pDrawCb = lpDrawCBFun;
			m_pDrawUser = pUser;
			WriteLog("IVS_SDK_SetDrawCallBackEx:PlayId[%d][%d][%p][%p]\n", m_nPlatPlayId,iRet,lpDrawCBFun,pUser);
			return true;
		}
	}
	else if (m_nDecodeType == 1) //走大华解码库
	{
		m_pDrawCb = lpDrawCBFun;
		m_pDrawUser	= pUser;
		return true;
	}
	return false;
}

bool NetPlugIn::setDVRConfig(DWORD dwCommand,LONG lChannel,LPVOID lpInBuffer,DWORD dwInBufferSize)
{
	switch (dwCommand)
	{
	case CONFIG_SET_SHOWSTRING:
		{
			sprintf(m_szShowString,"%s", (char *)lpInBuffer);
			break;	
		}
	default:
		return true;
	}
	return true;
}

bool NetPlugIn::getDVRConfig(DWORD dwCommand,LONG lChannel,LPVOID lpOutBuffer,DWORD dwOutBufferSize,LPDWORD lpBytesReturned)
{
	switch (dwCommand)
	{
	case CONFIG_GET_VIDEOOUTCFG:
		{
			long nWidth,nHeight;
			IVS_MEDIA_INFO MediaInfo = {0};
			if (m_nPlatPlayId != 0)
			{
				if (IVS_SDK_GetMediaInfo(m_nHWHandle,m_nPlatPlayId,&MediaInfo) != IVS_SUCCEED)
				{
					return false;
				}
				nWidth = MediaInfo.uiVideoWidth;
				nHeight = MediaInfo.uiVideoHeight;
			}
			else if (m_nPlayId != 0)
			{
				if (!PLAY_GetPictureSize(m_nPlayerPort,&nWidth, &nHeight))
				{
					return false;
				}
			}
			char szCfg[1024] = {0};
			sprintf(szCfg, "%d,%d", nHeight, nWidth);
			memcpy(lpOutBuffer,szCfg,strlen(szCfg));
			WriteLog("CONFIG_GET_VIDEOOUTCFG:%s\n", szCfg);
			if (lpBytesReturned)
			{
				*lpBytesReturned = (DWORD)strlen(szCfg);
			}
			break;
		}
	default:
		return false;
	}
	return true;
}

bool NetPlugIn::initialPlayer(int nPort,int nDecodeType,BYTE* buff, int nSize, int nStreamType)
{
	if (m_nDecodeType == 1)
	{
		m_nPlayerPort = 0;
		if (!PLAY_GetFreePort(&m_nPlayerPort))
		{
			return false;
		}
		PLAY_SetStreamOpenMode(m_nPlayerPort, m_nPlayMode);
		if (!PLAY_OpenStream(m_nPlayerPort,NULL,0,m_nBufferSize))
		{
			return false;
		}
		DecodeType nDecType = DECODE_SW;
		if (m_nDecodeType == 1)
		{
			nDecType = DECODE_HW;
		}
		RenderType nRenderType = RENDER_NOTSET;
		if (m_nRenderType == 1)
		{
			nRenderType = RENDER_D3D;
		}
		else if (m_nRenderType == 2)
		{
			nRenderType = RENDER_DDRAW;
		}
		else if (m_nRenderType == 3)
		{
			nRenderType = RENDER_WGL;
		}
		PLAY_SetEngine(m_nPlayerPort,nDecType,nRenderType);
	}
	return true;
}

bool NetPlugIn::startPlayer(HWND hWnd)
{
	if (m_nDecodeType == 1)
	{
		if (m_nWatermark == 1)
		{
			PLAY_RigisterDrawFun(m_nPlayerPort,fDrawCb,this);
		}
		//PLAY_SetDecodeStrategy(m_nPlayerPort,16);
		if (!PLAY_Play(m_nPlayerPort,hWnd))
		{
			return false;
		}
		//RECT rect;
		//if (GetClientRect(hWnd, &rect))
		//{
		//	if ((rect.right - rect.left) < 1024)
		//	{
		//		//WriteLog("当前窗口大小:[%d][%d]",rect.right-rect.left, rect.bottom-rect.top);
		//		PLAY_SetPicQuality(m_nPlayerPort,FALSE);
		//	}
		//}
		PLAY_PlaySound(m_nPlayerPort);
	}
	return true;
}

bool NetPlugIn::addData(BYTE* buff, int nSize)
{
	BOOL bRet;
	if (m_nDecodeType == 1)
	{
		if (buff && nSize > 0)
		{
			bRet = PLAY_InputData(m_nPlayerPort,buff,nSize);
			if (!bRet)
			{
				DWORD nBufSize = PLAY_GetBufferValue(m_nPlayerPort, BUF_VIDEO_SRC);
				if(nBufSize > m_nBufferSize * 2 / 3)
				{
					Sleep(10);
				}
			}
		}
	}
	return bRet?true:false;
}

bool NetPlugIn::stopPlayer()
{
	if (m_nDecodeType == 1)
	{
		stopRecord();
		PLAY_StopSound();
		PLAY_Stop(m_nPlayerPort);
		PLAY_CloseStream(m_nPlayerPort);
		PLAY_ReleasePort(m_nPlayerPort);
	}	
	return true;
}