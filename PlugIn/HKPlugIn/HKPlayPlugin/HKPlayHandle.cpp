#include "StdAfx.h"
#include "HKPlayHandle.h"

#define MaxDisplayBuf  15

typedef struct __FileRecord
{
    int nPort;
    string sFile;
}FileRecord;
vector<FileRecord*> RecordList;


LPDecCBFun m_pDecCBCallBack = NULL;
CRITICAL_SECTION HKPlayHandle::m_Lock;
vector<HKPlayHandle::PLAYERINFO> HKPlayHandle::m_vPlayChan;
CRITICAL_SECTION HKPlayHandle::m_picLock;

DWORD WINAPI MyInputStreamThread( LPVOID lpParameter)
{
    HKPlayHandle* pOwner=(HKPlayHandle*)lpParameter;

    BYTE* pBuffer = NULL;
    int nSize = 0;

    BOOL bBufFull=FALSE;

    while(WAIT_OBJECT_0==WaitForSingleObject(pOwner->m_hEventInput,INFINITE))
    {
        ResetEvent(pOwner->m_hEventInput);
        int nSize = 0;
        BYTE* pBuffer = NULL;
        while(pBuffer == NULL)
        {
            pBuffer = pOwner->getData(nSize);
            if(pBuffer == NULL)
                Sleep(50);			
        }
        if(!PlayM4_InputData(pOwner->m_nPlayerPort,pBuffer,nSize))
        {
            if(PLAYM4_BUF_OVER == PlayM4_GetLastError(pOwner->m_nPlayerPort))
            {
                PlayM4_ResetSourceBuffer(pOwner->m_nPlayerPort);
            }
        }
        delete[] pBuffer;
    }

    return 1;
}


void CALLBACK fileRefDone(DWORD nReserved,void *nUser)
{
    HKPlayHandle* phandle = (HKPlayHandle*)nUser;
}

HKPlayHandle::HKPlayHandle(void)
{
    m_nDecodeType = -1;
    m_hThread = NULL;
    m_hEventInput = NULL;
    m_nPlayerPort = -1;

    m_hStreamPlayHandle = NULL;

    m_streamType = -1;

    m_nMaxDisplayBuf = MaxDisplayBuf;
    m_bHasOpenStream = false;

    m_hWnd = NULL;

    m_pUserDraw = NULL;

    m_pDrawCallBack = NULL;

    bStateIdentify = FALSE;  /*string _Path = "ChanVideo070520.mp4";*/

    m_hLocPlayHandle = NULL;//硬解码时的本地文件播放通道句柄

    m_nUseOne4MultScreen = 0;

    m_bDvrFile = false;

    m_nFilePlayerPort = -1;

    m_hStreamFile = NULL;
    m_nFileHead = 0;

    m_fileTotalTime = 0;  //文件总时间
    m_nFileTotalSize = 0; //文件大小
    m_nFileOffset = 0;

    m_nPuse = false;
    m_read = true;

	m_log.SetFileName("C:\\NVSLog\\SDKEngine\\HKPlayPlugIn.log");

    m_log.SetFileSize(1024);//1M大小
    m_log.SetLogLevel(LOG_INFO);
	m_pFileRefDone = NULL;

	m_nSrcWind = 0;
	m_nSrcWindEx = 0;
	m_nSrcWidth = 0;
	m_nSrcHight = 0;
	m_Xlpoit = 0;
	m_Xrpoit = 0;
	m_Ytpoit = 0;
	m_Ydpoit = 0;
}


HKPlayHandle::~HKPlayHandle(void)
{
    if(m_nPlayerPort!=-1)
    {
		PlayM4_StopSoundShare(m_nPlayerPort);
        PlayM4_Stop(m_nPlayerPort);
        PlayM4_CloseStream(m_nPlayerPort);
		PlayM4_CloseFile(m_nPlayerPort);
        PlayM4_FreePort(m_nPlayerPort); 	
        m_nPlayerPort = -1;
    }


    closeVideoFile();

    if(m_hThread)
    {
        TerminateThread(m_hThread,0);
        CloseHandle(m_hThread);
        m_hThread = NULL;
    }

    if(m_hEventInput)
    {
        CloseHandle(m_hEventInput);
        m_hEventInput = NULL;
    }
    if (m_listBuffer.size()!=0)
    {
        list<pair<BYTE*,int> >::iterator itb =  m_listBuffer.begin();
        list<pair<BYTE*,int> >::iterator ite =  m_listBuffer.end();

        for(;itb!=ite;itb++)
        {
            if((*itb).first != NULL)
            {
                BYTE* pBuffer = (BYTE*)((*itb).first);
                delete[] pBuffer;
                pBuffer = NULL;
            }
        }
    }
}

bool HKPlayHandle::initialPlayer( int nPort,int nDecodeType,BYTE* buff, int nSize, int nStreamType )
{
    if (!m_pam.InitParam())
    {
		m_log.SetLogLevel(m_pam.m_nLoglevel);
        m_log.LogInfoEx(LOG_ERROR, "读取配置文件时参数错误!");
        return false;
    }
    else
    {
		m_log.SetLogLevel(m_pam.m_nLoglevel);
        m_log.LogInfoEx(LOG_INFO, "读取配置文件时参数正确, Engine[%d].", m_pam.m_nEngine);
    }

    m_nDecodeType = m_pam.m_nEngine;
    m_hThread=NULL;
    m_hEventInput=NULL;
    if (nStreamType > 1)
    {
        nStreamType = STREAME_FILE;
    }
    m_streamType = nStreamType;

    BOOL bRe = FALSE;
    long lPort = -1;
    bRe = PlayM4_GetPort(&lPort);
    if(!bRe)
    {
        DWORD dwRe1 = PlayM4_GetLastError(lPort);
        m_log.LogInfoEx(LOG_ERROR , "PlayM4_GetPort失败");
        return false;
    }
    bRe = PlayM4_SetStreamOpenMode(lPort, nStreamType);//STREAME_REALTIME or STREAME_FILE
    if(!bRe)
    {
        DWORD dwRe1 = PlayM4_GetLastError(lPort);
        m_log.LogInfoEx(LOG_ERROR , "PlayM4_SetStreamOpenMode失败");
        return false;
    }

	m_log.LogInfoEx(LOG_INFO,"海康头[%d]",nSize);
	if (m_pam.m_nBufSize > 0)
	{
		bRe = PlayM4_OpenStream(lPort, buff, nSize, m_pam.m_nBufSize);
	}
	else
	{
		bRe = PlayM4_OpenStream(lPort, buff, nSize, 2 * 1024 * 1024);
	}
    
    if(!bRe)
    {
       DWORD dwRe2 = PlayM4_GetLastError(lPort);
       m_log.LogInfoEx(LOG_ERROR ,"PlayM4_OpenStream失败 nSize=%d, errcode:%d", nSize,dwRe2   );

       return false;
    }

    if (m_nDecodeType == 1)
    {
		m_log.LogInfoEx(LOG_INFO,"开启硬解模式");
		if (!PlayM4_SetDecodeEngineEx(lPort, HARD_DECODE_ENGINE))
		{
			DWORD dwRet= PlayM4_GetLastError(lPort);
			m_log.LogInfoEx(LOG_ERROR,"PlayM4_SetDecodeEngineEx Failed, Port[%d], ErrorCode[%d].", lPort, dwRet);
			m_nDecodeType = 0;
		}
	}
	else
	{
		m_log.LogInfoEx(LOG_INFO,"开启软解模式");
		PlayM4_SetDecodeEngineEx(lPort, SOFT_DECODE_ENGINE);
	}
	if (m_nDecodeType == 0)
	{
		bRe = PlayM4_SetDisplayBuf(lPort, MaxDisplayBuf);				//2007-12-17 sjy 修改参数
		bRe = PlayM4_SetDisplayCallBack(lPort, SaveToBmpFile); //设置抓图回调
		if (!bRe)
		{
			m_log.LogInfoEx(LOG_ERROR, "PlayM4_SetDisplayCallBack失败");
			return false;
		}
	}

	PlayM4_SetPicQuality(m_nPlayerPort, FALSE);

	m_nPlayerPort = lPort;
	m_bHasOpenStream = true;

  
//#if (WINVER > 0x0400) //If do not support multi monitor,may not call!
//	PlayM4_InitDDrawDevice();
//	//Hik_PlayM4_SetDDrawDevice(m_nPlayerPort,m_nDeviceNum);
//#endif
 
    m_log.LogInfoEx(LOG_INFO , "初始化成功");
    return true;	
}

bool HKPlayHandle::initialPlayerEx(PINITPY_PARAM pIParam)
{
    if (NULL == pIParam)
    {
        return false;
    }
    return initialPlayer(pIParam->nPort , pIParam->nDecodeType , pIParam->buff , pIParam->size , pIParam->nType);
}

bool HKPlayHandle::startPlayer( HWND hWnd )
{
    bool bRe = PlayM4_Play(m_nPlayerPort,hWnd);
    if(!bRe)
    {
        PlayM4_ResetSourceBuffer(m_nPlayerPort); //2008-08-25 播放失败清理流模式缓冲区数据
        DWORD dwError = PlayM4_GetLastError(m_nPlayerPort);
        m_log.LogInfoEx(LOG_ERROR , "PlayM4_Play失败:Port;%d, ErrorCode=%d",m_nPlayerPort, dwError);
        return false;
    }

	PlayM4_PlaySoundShare(m_nPlayerPort);

	//RECT rt;
	//GetClientRect(hWnd,&rt);
	//if (rt.right < 1000)
	//{
	//	PlayM4_SetPicQuality(m_nPlayerPort,FALSE);
	//}
    //reSetDDrawDevice(hWnd);

	m_hWnd = hWnd;
    return bRe;
}

bool HKPlayHandle::startPlayer2( HWND hWnd, LPDRAWCBCALLLBACK lpDrawCBFun, void *pUser )
{
	m_log.LogInfoEx(LOG_INFO, "startPlayer2 hWnd[%p]", hWnd);
    m_pUserDraw = pUser;
    m_pDrawCallBack = lpDrawCBFun;
    BOOL ret = PlayM4_RegisterDrawFun(m_nPlayerPort, DrawFunCallBack, this);

    return startPlayer(hWnd);
}

bool HKPlayHandle::startPlayer4Standard( HWND hWnd,LPDecCBFun lpDecCBFun, int nCameraID )
{
	m_log.LogInfoEx(LOG_INFO, "startPlayer4Standard hWnd[%p]", hWnd);
    bStateIdentify = false;
    m_pDecCBCallBack = lpDecCBFun; //Hik_PlayM4_Stop(m_nPlayerPort);
	PLAYERINFO tPlayInfo;
	tPlayInfo.nPlayerPort = m_nPlayerPort;
	tPlayInfo.nCameraID = nCameraID;
	EnterCriticalSection(&m_Lock);
	m_vPlayChan.push_back(tPlayInfo);
	LeaveCriticalSection(&m_Lock);

	if (hWnd == NULL)
	{

		bool isOK = PlayM4_SetDecCallBackMend(m_nPlayerPort, DecCBFun4Standard, this);
		if (!isOK)
		{
			return false;		
		
		}
	}
	else
	{
		if (!PlayM4_SetAdditionDataCallBack(m_nPlayerPort, 0x0804, AdditionData4SCBFun, this))
		{
			DWORD dwRe3 = PlayM4_GetLastError(m_nPlayerPort);
			m_log.LogInfoEx(LOG_ERROR, "PlayM4_SetAdditionDataCallBack, errcode:%d", dwRe3);
		}
	}
    return true;
}

void CALLBACK HKPlayHandle::AdditionData4SCBFun(long nPort, AdditionDataInfo *pstAddDataInfo, void  *pUser)
{
	int nChanID = -1;
	AdditionDataInfo_D pDataInfo;
	FRAME_INFO_D mFrameInfo;
	static int i = 0;
	static int nCount = 0;
	static bool bRet = false;
	char* pARData = pstAddDataInfo->pData + 48;   //
	char* pARLableID = NULL;
	string ArData;
	char ArDataTemp[128] = { 0 };
	EnterCriticalSection(&m_Lock);
	try
	{
		mFrameInfo.nType = 201;

		vector<PLAYERINFO>::iterator it = m_vPlayChan.begin(); //
		for (; it != m_vPlayChan.end(); ++it)
		{
			if ((*it).nPlayerPort == nPort)
			{
				nChanID = (*it).nCameraID;
				break;
			}
		}

		if (pstAddDataInfo->lDataType == 0x0804)
		{
			do
			{
				pARLableID = pARData + (i) * 28;
				//pDataInfo.id = *pARLableID;
				/*unsigned char a[28] = {0};
				for (int j=0;j<28;j++)
				{
				a[j] = pARData[j+((i) * 28)];
				}
				pDataInfo.id = a[0]+a[1]*0xff;
				pDataInfo.x = a[2]+a[3]*0xff;
				pDataInfo.y = a[4]+a[5]*0xff;
				pDataInfo.viewAngleH = a[8]+a[9]*0xff;
				pDataInfo.viewAngleV = a[10]+a[11]*0xff;
				pDataInfo.r =a[12]+a[13]*0xff;
				pDataInfo.north = a[16]+a[17]*0xff+a[18]*0xff*0xff+a[19]*0xff*0xff*0xff;
				i++;*/

				if (nChanID != -1 && m_pDecCBCallBack && *pARLableID > 0)
				{
					unsigned char a[28] = { 0 };
					for (int j = 0; j<28; j++)
					{
						a[j] = pARData[j + ((i) * 28)];
					}
					pDataInfo.id = a[0] + a[1] * 0xff;
					pDataInfo.x = a[2] + a[3] * 0xff;
					pDataInfo.y = a[4] + a[5] * 0xff;
					pDataInfo.viewAngleH = a[8] + a[9] * 0xff;
					pDataInfo.viewAngleV = a[10] + a[11] * 0xff;
					pDataInfo.r = a[12] + a[13] * 0xff;
					pDataInfo.north = a[16] + a[17] * 0xff + a[18] * 0xff * 0xff + a[19] * 0xff * 0xff * 0xff;
					i++;

					sprintf_s(ArDataTemp, sizeof(ArDataTemp), "%d,%d,%d,%d,%d,%d,%d;",
						pDataInfo.id, pDataInfo.x, pDataInfo.y, pDataInfo.viewAngleH, pDataInfo.viewAngleV, pDataInfo.r, pDataInfo.north);
					ArData = ArData + string(ArDataTemp);
					//m_pDecCBCallBack(nPort, (char *)&pDataInfo, (LONG)sizeof(pDataInfo), &mFrameInfo, nChanID);
				}
				else
				{
					if (ArData.size() == 0 && !bRet)
					{
						//static_cast<HKPlayHandle*>(pUser)->m_log.LogInfoEx(LOG_ERROR, "callback: ArData.size() == 0 && !bRet");
						ArData = "404 NOT FOUND";
						m_pDecCBCallBack(nPort, (char *)ArData.c_str(), (LONG)ArData.size(), &mFrameInfo, nChanID);
						ArData.clear();
						bRet = true;

					}
					if (ArData.size() > 3)
					{
						//static_cast<HKPlayHandle*>(pUser)->m_log.LogInfoEx(LOG_ERROR, "callback: ArData.size() > 3");
						m_pDecCBCallBack(nPort, (char *)ArData.c_str(), (LONG)ArData.size(), &mFrameInfo, nChanID);
						ArData.clear();
						bRet = true;
					}
					nCount++;
					if (nCount == 10)
					{
						i = 0;
						nCount = 0;
						bRet = false;
					}
				}
			} while (*pARLableID > 0);
		}
	}
	catch (...) {}
	LeaveCriticalSection(&m_Lock);
}

bool HKPlayHandle::startPlayer4StandardEx(PSTARTPYS_PARAM pParam)
{
    if (NULL == pParam)
    {
        return false;
    }
    return startPlayer4Standard(pParam->hWnd , pParam->lpDecCBFun , pParam->nCameraID);
}

bool HKPlayHandle::addData( BYTE* buff, int nSize )
{
    char str[128] = {0};

    int nCount =2;

    if(buff && nSize>0)
    {
        try
        {
            if(m_streamType != STREAME_REALTIME)
            {
                nCount = 100;
                //nCount = 5;
            }
            while(m_bHasOpenStream && m_nPlayerPort>=0 && nCount>0 && !PlayM4_InputData(m_nPlayerPort,buff,nSize) )
            {
                DWORD dwResult = PlayM4_GetLastError(m_nPlayerPort);


                if (m_streamType==STREAME_REALTIME) //实时播放时,为保证实时性，清除缓冲数据
                {
                    PlayM4_ResetSourceBuffer(m_nPlayerPort); //2008-08-25 播放失败清理流模式缓冲区数据
                }else
                {
                    Sleep(10);
                }


                --nCount;
            }
        }
        catch(...){}
    }

    //
    if (nCount==0)
    {
        return false;
    }
    return true;
}

bool HKPlayHandle::stopPlayer()
{
    m_bHasOpenStream = false;
    int nPort = m_nPlayerPort;
	if (m_nPlayerPort != -1)
	{
		PlayM4_StopSoundShare(m_nPlayerPort);
		PlayM4_Stop(m_nPlayerPort);
		m_log.LogInfoEx(LOG_INFO, "[PlayM4_Stop] 端口[%d] end。\r\n", m_nPlayerPort);
		PlayM4_ResetSourceBuffer(m_nPlayerPort);
		PlayM4_CloseStream(m_nPlayerPort);
		m_log.LogInfoEx(LOG_INFO, "[PlayM4_CloseStream] 端口[%d] end。\r\n", m_nPlayerPort);
		PlayM4_FreePort(m_nPlayerPort);
		m_log.LogInfoEx(LOG_INFO, "[PlayM4_FreePort] 端口[%d] end。\r\n", m_nPlayerPort);
		m_nPlayerPort = -1;
	}

	EnterCriticalSection(&m_Lock);
    vector<PLAYERINFO>::iterator it = m_vPlayChan.begin();
    for(;it!=m_vPlayChan.end();++it)
    {
        if((*it).nPlayerPort == nPort)
        {
            break;
        }
    }
    if(it!=m_vPlayChan.end())
    {
        m_vPlayChan.erase(it);
        //nFreeCount++;
    }
	LeaveCriticalSection(&m_Lock);
//#if (WINVER > 0x0400)
//    Hik_PlayM4_ReleaseDDrawDevice();
//#endif
    return true;
}

bool HKPlayHandle::controlPTZSpeed(int nCmd, bool bEnable,int nSpeed)
{
	return controlPTZSpeedWithChannel(nCmd, bEnable, nSpeed, 0);
}

bool HKPlayHandle::controlPTZSpeedWithChannel(int nCmd, bool bEnable, int nSpeed, int nChannel)
{
	if (nCmd == 24)
	{
		m_nSrcWind = nSpeed;
	}
	else if (nCmd == 25)
	{
		if (m_nSrcWind == 0)
		{
			return false;
		}
		unsigned char prec[4] = { 0 };
		unsigned char nrec[4] = { 0 };
		memcpy(prec, &m_nSrcWind, sizeof(m_nSrcWind));
		memcpy(nrec, &nSpeed, sizeof(nSpeed));
		int pleft = 0, ptop = 0, pright = 0, pdow = 0;//原来窗口坐标
		int nleft = 0, ntop = 0, nright = 0, ndow = 0;//框选窗口坐标
		pleft = prec[0] * 10;
		ptop = prec[1] * 10;
		pright = prec[2] * 10;
		pdow = prec[3] * 10;
		nleft = nrec[0] * 10;
		ntop = nrec[1] * 10;
		nright = nrec[2] * 10;
		ndow = nrec[3] * 10;
		if ((m_nSrcWidth == 0 && m_nSrcHight == 0) || (nSpeed == m_nSrcWind))
		{
			m_log.LogInfoEx(LOG_INFO, "src:%d,%d,%d,%d dst:%d,%d,%d,%d\n", pleft, ptop, pright, pdow, nleft, ntop, nright, ndow);
			if (PlayM4_GetPictureSize(m_nPlayerPort, &m_nSrcWidth, &m_nSrcHight))
			{
				m_Xlpoit = m_nSrcWidth*nleft / (pright - pleft);
				m_Xrpoit = m_nSrcWidth*nright / (pright - pleft);
				m_Ytpoit = m_nSrcHight*ntop / (pdow - ptop);
				m_Ydpoit = m_nSrcHight*ndow / (pdow - ptop);
			}
			else
			{
				return false;
			}
		}
		else
		{
			int x = m_Xlpoit;
			int y = m_Ytpoit;
			int nWidth = m_Xrpoit - m_Xlpoit;
			int nHight = m_Ydpoit - m_Ytpoit;
			m_Xlpoit = (nWidth*nleft / (pright - pleft)) + x;
			m_Xrpoit = (nWidth*nright / (pright - pleft)) + x;
			m_Ytpoit = (nHight*ntop / (pdow - ptop)) + y;
			m_Ydpoit = (nHight*ndow / (pdow - ptop)) + y;
		}
		RECT rect;
		rect.bottom = m_Ydpoit;
		rect.top = m_Ytpoit;
		rect.left = m_Xlpoit;
		rect.right = m_Xrpoit;
		if (!PlayM4_SetDisplayRegion(m_nPlayerPort, 0, &rect, NULL, FALSE))
		{
			return false;
		}
	}
	return true;
}

bool HKPlayHandle::getDVRConfig(DWORD dwCommand, LONG lChannel, LPVOID lpOutBuffer, DWORD dwOutBufferSize, LPDWORD lpBytesReturned)
{
	switch (dwCommand)
	{
	case CONFIG_GET_VIDEOOUTCFG:
		{
			if (PlayM4_GetPictureSize(m_nPlayerPort, &m_nSrcWidth, &m_nSrcHight))
				sprintf((char *)lpOutBuffer, "%d,%d", m_nSrcWidth, m_nSrcHight);
			else
				return false;
		}
		break;
	default:
		return false;
	}
	return true;
}

bool HKPlayHandle::locPlay_OpenFile( int nPort,int nDecodeType, HWND hWnd,char* fileName )
{
 
	m_hStreamFile = CreateFile(fileName,GENERIC_READ,FILE_SHARE_READ,NULL,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,NULL);
	if(INVALID_HANDLE_VALUE == m_hStreamFile)
	{
		m_log.LogInfoEx(LOG_ERROR , "CreateFile fileName %s 失败",fileName);
		return false;
	}
	PlayM4_SetFileRefCallBack(nPort,fileRefDone,this);
    bool bRe = PlayM4_OpenFile(nPort,fileName);
    if(!bRe)
    {
		CloseHandle(m_hStreamFile);
		DWORD err = PlayM4_GetLastError(nPort);
		m_log.LogInfoEx(LOG_ERROR , "PlayM4_OpenFile fileName %s 失败,err = %d",fileName,err);
        return bRe;
    }
    m_nPlayerPort = nPort;
	m_hWnd = (HWND)hWnd;

    bRe = PlayM4_Play(m_nPlayerPort,(HWND)hWnd);
    if(!bRe)
    {
		CloseHandle(m_hStreamFile);
		DWORD err = PlayM4_GetLastError(nPort);
		m_log.LogInfoEx(LOG_ERROR , "PlayM4_Play fileName %s 失败,err = %d",fileName,err);
        return bRe;
    }

    bRe = PlayM4_PlaySound(m_nPlayerPort);
    if(!bRe)
    {
		CloseHandle(m_hStreamFile);
		DWORD err = PlayM4_GetLastError(nPort);
		m_log.LogInfoEx(LOG_ERROR , "PlayM4_PlaySound fileName %s 失败,err = %d",fileName,err);
        return bRe;
    }

    return true;
  
}

bool HKPlayHandle::locPlay_OpenFileEx( PLOCPY_OPENF_PARAM_PARAM pParam )
{
    if (NULL == pParam)
    {
        return false;
    }
	bool bRe;
	long lPort = -1;
	bRe = PlayM4_GetPort(&lPort);
	if(bRe == false)
		return false;
	pParam->nPort = lPort;
    bRe =  locPlay_OpenFile(pParam->nPort , pParam->nDecodeType , pParam->hWnd , pParam->fileName);
	return bRe;
}

bool HKPlayHandle::locPlay_Control( int nCmd,int nInValue,int* outValue )
{
	m_log.LogInfoEx(LOG_INFO , "locPlay_Control nCmd :%d,nInValue :%d,m_nDecodeType:%d,m_nPlayerPort:%d",nCmd,nInValue,m_nDecodeType,m_nPlayerPort);
/*    if(m_nDecodeType != 0)
	{
		m_log.LogInfoEx(LOG_ERROR , "locPlay_Control DecodeType != 0");
		return false;
	} */  

	BOOL bRet = FALSE;

    switch(nCmd)
    {
    case LOCPLAY_CTRL_PLAYPAUSE://暂停播放
		{
			bRet =  PlayM4_Pause(m_nPlayerPort,TRUE);
			break;
		}  
    case LOCPLAY_CTRL_PLAYRESTART://恢复播放
		{
			bRet =  PlayM4_Pause(m_nPlayerPort,FALSE);
			break;
		}     
    case LOCPLAY_CTRL_PLAYFAST://快放
		{
			bRet =  PlayM4_Fast(m_nPlayerPort);
			break;
		}  
    case LOCPLAY_CTRL_PLAYSLOW://慢放
		{
			bRet =  PlayM4_Slow(m_nPlayerPort);
			break;
		}  
    case LOCPLAY_CTRL_PLAYNORMAL://正常速度
		{
			bRet =  PlayM4_Play(m_nPlayerPort,m_hWnd);
			break;
		}  
    case LOCPLAY_CTRL_PLAYFRAME://单帧放
		{
			bRet =  PlayM4_OneByOne(m_nPlayerPort);
			break;
		}  
    case LOCPLAY_CTRL_PLAYSTARTAUDIO://打开声音
        return PlayM4_PlaySound(m_nPlayerPort);
    case LOCPLAY_CTRL_PLAYSTOPAUDIO://关闭声音
        return PlayM4_StopSound();
    case LOCPLAY_CTRL_PLAYAUDIOVOLUME://调节音量
        return PlayM4_SetVolume(m_nPlayerPort,(WORD) nInValue);
    case LOCPLAY_CTRL_PLAYSETPOS://改变文件回放的进度
		{
			bRet =  PlayM4_SetPlayPos(m_nPlayerPort,(float)((float) nInValue/100));
			break;
		}   
    case LOCPLAY_CTRL_PLAYGETPOS://获取文件回放的进度
        {
			float temp = PlayM4_GetPlayPos(m_nPlayerPort);
			*outValue = temp*100;
            //*outValue = PlayM4_GetPlayPos(m_nPlayerPort);
            return true;
        }
    case LOCPLAY_CTRL_PLAYGETTIME://获取当前已经播放的时间
        {
            *outValue = (int)PlayM4_GetPlayedTime(m_nPlayerPort);
            return true;
        }
    case LOCPLAY_CTRL_PLAYGETFRAME://获取当前已经播放的帧数
        {
			*outValue = (int)PlayM4_GetCurrentFrameNum(m_nPlayerPort);
            //*outValue = (int)PlayM4_GetPlayedFrames(m_nPlayerPort);
            return true;
        }
    case LOCPLAY_CTRL_GETTOTALFRAMES://获取当前播放文件总的帧数
        {
            *outValue = (int)PlayM4_GetFileTotalFrames(m_nPlayerPort);
            return true;
        }
    case LOCPLAY_CTRL_GETTOTALTIME://获取当前播放文件总的时间
        {
            *outValue = (int)PlayM4_GetFileTime(m_nPlayerPort);
            return true;
        }
	case LOCPLAY_CTRL_PLAYSETFRAME://设置当前播放文件帧数
		{
			int nFrame = nInValue;
			*outValue = PlayM4_SetCurrentFrameNum(m_nPlayerPort,nFrame);
			return true;
		}
    }
	DWORD dwRe = PlayM4_GetLastError(m_nPlayerPort);
	if(bRet == FALSE)
		m_log.LogInfoEx(LOG_ERROR , "locPlay_Control nCmd :%d,nInValue :%d,m_nDecodeType:%d,m_nPlayerPort:%d bRet = %d,lasterror =  %d",nCmd,nInValue,m_nDecodeType,m_nPlayerPort,bRet,(int)dwRe);
	return bRet;
}

bool HKPlayHandle::locPlay_Stop()
{

	PlayM4_StopSound();
	PlayM4_CloseFile(m_nPlayerPort);
	PlayM4_Stop(m_nPlayerPort);	
	PlayM4_FreePort(m_nPlayerPort);
	if(m_hStreamFile && m_hStreamFile != INVALID_HANDLE_VALUE)
	{
		CloseHandle(m_hStreamFile);
	}
    return true;
}

bool HKPlayHandle::convertToBmpFile( char * pBuf,LONG nSize,LONG nWidth,LONG nHeight,LONG nType,char *sFileName )
{
    bool bRe = (bool)PlayM4_ConvertToBmpFile(pBuf,nSize,nWidth,nHeight,nType,sFileName);
    return bRe;
}

bool HKPlayHandle::oneByOneBack( LONG nPort )
{
    bool bRe = (bool)PlayM4_OneByOneBack(nPort);
    return bRe;
}

bool HKPlayHandle::oneByOne( LONG nPort )
{
    bool bRe = (bool)PlayM4_OneByOne(nPort);
    return bRe;
}

bool HKPlayHandle::setPlayedTimeEx( LONG nPort,DWORD nTime )
{
    bool bRe = (bool)PlayM4_SetPlayedTimeEx(nPort,nTime);
    return bRe;
}

void HKPlayHandle::reSetDDrawDevice( HWND hWnd )
{
    if(m_nUseOne4MultScreen == 0)
        return;

    PlayM4_InitDDrawDevice();

    DWORD m_dwScreenWidth  = GetSystemMetrics(SM_CXSCREEN);
    DWORD m_dwScreenHeight = GetSystemMetrics(SM_CYSCREEN);

    RECT		m_rcWindow;	
    GetWindowRect(hWnd, &m_rcWindow);
    DWORD dwNewDeviceNum;

    if(m_rcWindow.left < 0)
        return;

    if( (DWORD)m_rcWindow.right + (DWORD)m_rcWindow.left > 2 * m_dwScreenWidth )
    {
        if( (DWORD)m_rcWindow.top + (DWORD)m_rcWindow.bottom > 2 * m_dwScreenHeight)
        {
            dwNewDeviceNum = 3;
        }
        else
        {
            if((DWORD)m_rcWindow.right + (DWORD)m_rcWindow.left >5500)
                dwNewDeviceNum = 2;
            else dwNewDeviceNum = 1;     //Hikvision guobin 8131 15867107477
        }
    }
    else
    {
        if( (DWORD)m_rcWindow.top + (DWORD)m_rcWindow.bottom > 2 * m_dwScreenHeight)
        {
            dwNewDeviceNum = 2;
        }
        else
        {
            dwNewDeviceNum = 0;
        }
    }
    //#if (WINVER > 0x0400)
    PlayM4_SetDDrawDevice(m_nPlayerPort, dwNewDeviceNum + 1);
    //#endif

    PlayM4_RefreshPlay(m_nPlayerPort);
}

bool HKPlayHandle::controlCameraSound( bool bOpenSound )
{
    if(bOpenSound)
    {
        return PlayM4_PlaySound(m_nPlayerPort);
    }
    else 
    {
        return PlayM4_StopSound();
    }
}

intptr_t HKPlayHandle::openVideoFile( char *sFileName )
{
    m_bDvrFile = false;
    long lPort = -1;
    BOOL bRe = PlayM4_GetPort(&lPort);
    if(!bRe)
    {
        DWORD dwRe1 = PlayM4_GetLastError(lPort);
        return -8;
    }

    m_nFilePlayerPort = lPort;
    PlayM4_SetFileRefCallBack(m_nFilePlayerPort,fileRefDone,this);

    if(!PlayM4_OpenFile(m_nFilePlayerPort,sFileName))
    {
        DWORD dwRe1 = PlayM4_GetLastError(lPort);
        m_log.LogInfoEx(LOG_ERROR , "Hik_PlayM4_OpenFile 失败! 错误码=%d\n", dwRe1);
        PlayM4_FreePort(m_nFilePlayerPort);
        return -9;
    }

    m_hStreamFile = CreateFile(sFileName,GENERIC_READ,FILE_SHARE_READ,NULL,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,NULL);
    if(INVALID_HANDLE_VALUE == m_hStreamFile)
    {
        closeVideoFile();
        return -10;
    }
    return (long)m_hStreamFile;
}

int HKPlayHandle::readVideoFile( char *buff,int len, int *streamType )
{
    DWORD nRealRead = 0;
    if(INVALID_HANDLE_VALUE == m_hStreamFile)
    {
        m_log.LogInfoEx(LOG_ERROR ,"File handle error. m_hStreamFile = INVALID_HANDLE_VALUE\r\n");
        return 0;
    }

    if(0 == m_nFileHead)
    {
        m_fileTotalTime = PlayM4_GetFileTime(m_nFilePlayerPort);
        m_nFileTotalSize = ::GetFileSize(m_hStreamFile,NULL);
        *streamType = DVR_DATA_INIT;                //DVR_DATA_STREAM
        int headSize = PlayM4_GetFileHeadLength();
        if(!ReadFile(m_hStreamFile,buff,headSize,&nRealRead,NULL))
        {
            m_log.LogInfoEx(LOG_ERROR ,"The Function ReadFile is error   DVR_DATA_INIT\r\n");
            return 0;
        }
        if(headSize != nRealRead)
        {
            return 0;
        }
        m_nFileHead = 1;
    }
    else 
    {
        if(m_nFileOffset >= m_nFileTotalSize)
        {
            return -1;     //文件读取完毕
        }

        if(m_read == false)
        {
            return -1;    //文件读取结束
        }
        *streamType = DVR_DATA_STREAM;
        if(false == m_nPuse)
        {
            if(!ReadFile(m_hStreamFile,buff,len,&nRealRead,NULL))
            {
                m_log.LogInfoEx(LOG_ERROR ,"The Function ReadFile is error  DVR_DATA_STREAM \r\n");
                return 0;   
            }
        }
        else
        {
            return -2;   //文件暂停
        }
    }
    m_nFileOffset += nRealRead;
    return nRealRead;
}

bool HKPlayHandle::closeVideoFile()
{
    m_read = false;
    if(m_hStreamFile)
    {
        CloseHandle(m_hStreamFile);
        m_hStreamFile = NULL;
    }

    if (m_nFilePlayerPort != -1)
    {
        PlayM4_CloseFile(m_nFilePlayerPort);
        PlayM4_FreePort(m_nFilePlayerPort);
        m_nPlayerPort = -1;
    }
    m_nFileOffset = 0;
    m_nFileTotalSize = 0;
    m_fileTotalTime = 0;
    return true;
}

bool HKPlayHandle::controlPlay( int nCmd,int param, int *outValue )
{
    if(m_nFilePlayerPort < 0)
    {
        return false;
    }

    switch(nCmd)
    {
    case REPLAY_CTRL_PLAYRESTART:                 //正常播放
        *outValue = 0;
        m_nPuse = false;
        return true;
    case REPLAY_CTRL_PLAYFAST:                    //快进
        *outValue = 0;
        return true;
    case REPLAY_CTRL_PLAYSLOW:                    //慢放
        *outValue = 0;
        return true;
    case REPLAY_CTRL_PLAYNORMAL:                  //正常速度
        *outValue = 0;
        return true;
    case REPLAY_CTRL_PLAYFRAME:                   //单帧播放
        *outValue = 0;
        return false;
    case REPLAY_CTRL_PLAYPAUSE:                    //暂停
        *outValue = 0;
        m_nPuse = true;
        return true; 
    case REPLAY_CTRL_PLAYSETPOS:                   //改变进度
        break;
    case REPLAY_CTRL_PLAYGETPOS:                   //获取进度
        if(m_nFileOffset <= 0 || m_nFileTotalSize <= 0)
        {
            *outValue = 0;
        }
        else
        {
            DWORD n = m_nFileTotalSize/100;
            *outValue = m_nFileOffset/n;  
        }

        if(m_nFileOffset == m_nFileTotalSize &&  m_nFileTotalSize != 0)
        {
            *outValue = 100;
        }
        return true;
    case REPLAY_CTRL_GETFILESIZE:                 //文件总大小
        *outValue = m_nFileTotalSize/1024;
        return true;
    case REPLAY_CTRL_GETTOTALTIME:                //获取文件的总时间
        *outValue = PlayM4_GetFileTime(m_nFilePlayerPort);
        return true;
	case REPLAY_CTRL_GETTOTALFRAMES:               //???????,LM-2014-1-7
		*outValue = PlayM4_GetFileTotalFrames(m_nFilePlayerPort);
		return true;
    default:
        *outValue = 0;
        return false;
    }

    if(param == 0)
    {
        ::SetFilePointer(m_hStreamFile,0,0,FILE_BEGIN);
        *outValue = 0;
        return true;
    }
    else if(param == 100)
    {
        ::SetFilePointer(m_hStreamFile,0,0,FILE_END);
        *outValue = 100;
        return true;
    }

    FRAME_POS currentPos;
    memset(&currentPos,0,sizeof(FRAME_POS));

    if(PlayM4_GetKeyFramePos(m_nFilePlayerPort,param,BY_FRAMENUM,&currentPos)) //????????,LM-2014-1-7
    {
        ::SetFilePointer(m_hStreamFile,currentPos.nFilePos,0,FILE_BEGIN);
        m_nFileOffset = currentPos.nFilePos;
		*outValue = currentPos.nFrameNum;
    }
    if(m_nFileOffset >= m_nFileTotalSize)
    {
        *outValue = 100;
        return false;
    }
    return true;
}

void HKPlayHandle::ClearPlayBuffer()
{
    if (m_nPlayerPort>=0)
    {
        PlayM4_ResetSourceBuffer(m_nPlayerPort);
    }
}

void HKPlayHandle::pusePlayDecode( bool bPuse )
{
    if (m_nPlayerPort>=0)
    {
        if (bPuse)
        {
            PlayM4_Pause(m_nPlayerPort,true);
        }
        else
            PlayM4_Pause(m_nPlayerPort,false);

    }
}

bool HKPlayHandle::setFileRefCallBack( LONG nPort,void (__stdcall *pFileRefDone) (DWORD nPort,void *nUser),void *nUser )
{
    BOOL bRe = PlayM4_SetFileRefCallBack(nPort,pFileRefDone,nUser);
	if(bRe == FALSE)
	{
		DWORD err = PlayM4_GetLastError(nPort);
		m_log.LogInfoEx(LOG_INFO , "setFileRefCallBack: %d .失败 err :%d .",nPort,err);
		return false;
	}	
	
	return true;
}

void CALLBACK DisplayCallBack(DISPLAY_INFO *pstDisplayInfo)
{
	HKPlayHandle *pHandle = (HKPlayHandle *)pstDisplayInfo->nUser;
	char szType[256] = "HK";
	pstDisplayInfo->nUser = szType;
	if(pHandle->m_pFileRefDone != NULL)
		pHandle->m_pFileRefDone(pstDisplayInfo->nPort,pstDisplayInfo->pBuf,pstDisplayInfo->nBufLen,pstDisplayInfo->nWidth,pstDisplayInfo->nHeight,pstDisplayInfo->nStamp,pstDisplayInfo->nType,pstDisplayInfo->nUser);
}

bool HKPlayHandle::setDisplayCallBack( LONG nPort, void (__stdcall *pFileRefDone)(long nPort,char * pBuf,long nSize,long nWidth,long nHeight,long nStamp,long nType,void *nReserved) )
{
    //BOOL bRe = PlayM4_SetDisplayCallBack(nPort,pFileRefDone);
	BOOL bRe;
	m_log.LogInfoEx(LOG_INFO , "setDisplayCallBack: %d .成功",this);
	if(pFileRefDone == NULL)
	{
		bRe = PlayM4_SetDisplayCallBackEx(nPort,NULL,this);
	}
	else
	{
		bRe = PlayM4_SetDisplayCallBackEx(nPort,DisplayCallBack,this);
	}
	m_pFileRefDone = pFileRefDone;		
	if(bRe == FALSE)
		return false;

    return true;
}

bool HKPlayHandle::capturePicture( char* sFilePath )
{
	if (m_nDecodeType == 1)
	{
		long nWidth,nHeight;
		
		if (!PlayM4_GetPictureSize(m_nPlayerPort,&nWidth, &nHeight))
		{
			m_log.LogInfoEx(LOG_INFO , "capturePicture: %d x %d",nWidth, nHeight);
			return false;
		}
		DWORD njszie;
		DWORD nSize = nWidth*nHeight*3/2;
		PBYTE pBuf = new BYTE[nSize];
		if (PlayM4_GetJPEG(m_nPlayerPort,pBuf,nSize,&njszie))
		{
			FILE *fpic = fopen(sFilePath, "wb+");
			if (fpic)
			{
				fwrite(pBuf,njszie,1,fpic);
				fclose(fpic);
			}
			delete[] pBuf;
			return true;
		}
		delete[] pBuf;
		return false;
	}
	EnterCriticalSection(&HKPlayHandle::m_picLock);
    vector<FileRecord*>::iterator it = RecordList.begin();
    for (;it!=RecordList.end();it++)
    {
        if ((*it)->sFile == sFilePath && (*it)->nPort == m_nPlayerPort)
        {
            break;
        }
    }

    if (it==RecordList.end())
    {
        FileRecord *record = new FileRecord;
        record->nPort = m_nPlayerPort;
        record->sFile = sFilePath;
        RecordList.push_back(record);
    }
	LeaveCriticalSection(&HKPlayHandle::m_picLock);
    return true;
}

BYTE* HKPlayHandle::getData( int& nSize )
{
    nSize = 0;
    if(m_listBuffer.size() == 0)
    {
        return NULL;
    }

    pair<BYTE*,int> p1 = m_listBuffer.front();//make_pair(myBuffer,nSize);


    BYTE* pBuffer = p1.first;
    nSize = p1.second;

    m_listBuffer.pop_front();
    return pBuffer;
}

void CALLBACK HKPlayHandle::SaveToBmpFile( LONG nPort,char * pBuf,long nSize,long nWidth,long nHeight,long nStamp,long nType,void *nReserved )
{
    //有风险RecordList没受保护,效率
	EnterCriticalSection(&HKPlayHandle::m_picLock);
    vector<FileRecord*>::iterator it = RecordList.begin();
    for (;it!=RecordList.end();it++)
    {
        if ((*it)->nPort == nPort)
        {
            break;
        }
    }

    if (it!=RecordList.end())
    {
        FileRecord *record = *it;
        PlayM4_ConvertToBmpFile(pBuf,nSize,nWidth,nHeight,nType,(char*)record->sFile.c_str());

        Sleep(10);

        delete record;
        record = NULL;
        RecordList.erase(it);
    }
	LeaveCriticalSection(&HKPlayHandle::m_picLock);
}

void  CALLBACK HKPlayHandle::DrawFunCallBack( long lRealHandle,HDC hDc, void *dwUser )
{
    HKPlayHandle* pHandler = (HKPlayHandle*)dwUser;

    try
    {
        if(NULL == pHandler || 
            NULL == pHandler->m_pDrawCallBack || 
            !AfxIsValidAddress(pHandler,4) || 
            !AfxIsValidAddress(pHandler->m_pDrawCallBack,4) //||
            )
        {
            //pHandler->m_log.LogInfoEx(LOG_ERROR , "DrawFunCallBack! 无效指针");
            return;
        }
    }
    catch (...){
        pHandler->m_log.LogInfoEx(LOG_ERROR , "DrawFunCallBack Exception!");
        return;
    }
    pHandler->m_pDrawCallBack((LONG)pHandler, lRealHandle, (DWORD) hDc, pHandler->m_pUserDraw);

}

void CALLBACK HKPlayHandle::DecCBFun4Standard( long nPort, char * pBuf, long nSize, FRAME_INFO * pFrameInfo, void *nReserved1,void *nReserved2 )
{
    int nChanID = -1;
    FRAME_INFO_D mFrameInfo;
    EnterCriticalSection(&m_Lock);
    try
    {
        mFrameInfo.nFrameRate = pFrameInfo->nFrameRate;
        mFrameInfo.nHeight = pFrameInfo->nHeight;
        mFrameInfo.nStamp = pFrameInfo->nStamp;
        mFrameInfo.nType = pFrameInfo->nType;
        mFrameInfo.nWidth = pFrameInfo->nWidth;

        vector<PLAYERINFO>::iterator it = m_vPlayChan.begin(); //没受保护
        for(;it!=m_vPlayChan.end();++it)
        {
            if((*it).nPlayerPort == nPort)
            {
                nChanID = (*it).nCameraID;
                break;
            }
        }
    }
    catch(...){}
    LeaveCriticalSection(&m_Lock);

    if (nChanID!=-1 && m_pDecCBCallBack)
    {
        m_pDecCBCallBack(nPort,pBuf,nSize,&mFrameInfo, nChanID);
    }
}

bool HKPlayHandle::queryPorperySupport( XYPROPROPERTY propery)
{
    int nPropery = (int)propery;
    switch(nPropery)
    {
    case XY_PROPERTY_ISSUPPORT_PACK: ////查询是需要发送原始包(即不可分包) ,返回true:是  false:否
        return true;
    case XY_PROPERTY_ISHAVEHEAD: ////查询是有包头 true:是  false:否
        return true;
    default:
        return false;
    }
    return false;
}

bool HKPlayHandle::SetCropArea( bool bFlag, int x1, int y1, int x2, int y2)
{
	BOOL bRet = FALSE;
	RECT rct;
	rct.left = x1;
	rct.top  = y1;
	rct.right = x2;
	rct.bottom = y2;
	bRet = PlayM4_SetDisplayRegion(m_nPlayerPort,0,&rct,NULL,bFlag);
	if(bRet == FALSE)
	{
		return false;
	}	
	return true;
}
//视频解码智能调节
// Parameter: nCmd: 智能调节的类型, 1为去雾, 2为反色, 3为锐化, 4为亮度调节
//			  bFlag: true为执行智能调节, false为取消
//			  x1, y1: 去雾时表示起始点坐标, 高度调节时为参数
//			  x2, y2: 亮度调节表示终结点坐标.

bool HKPlayHandle::SetDecodeParam( int nCmd, bool bFlag, int x1, int y1, int x2, int y2)
{
	BOOL bRet = FALSE;
	int nModuleType = 0;
	PLAYM4_VIE_PARACONFIG param = {0};
	switch (nCmd)
	{
	case 1://去雾
		{
			nModuleType = PLAYM4_VIE_MODU_DEHAZE;
			bRet = PlayM4_VIE_SetModuConfig(m_nPlayerPort,bFlag,nModuleType);
			if(bRet == TRUE)
			{
				bRet = PlayM4_VIE_GetParaConfig(m_nPlayerPort,&param);
			}
			if(bRet == TRUE)
			{
				bRet = PlayM4_VIE_SetParaConfig(m_nPlayerPort,&param);
			}
			if(bRet == FALSE)
			{
				return false;
			}	
			break;
		}
	case 2://反色
		{
			return false;
			break;
		}
	case 3://锐化
		{	
			nModuleType = PLAYM4_VIE_MODU_SHARPEN;
			bRet = PlayM4_VIE_SetModuConfig(m_nPlayerPort,bFlag,nModuleType);
			if(bRet == TRUE)
			{
				bRet = PlayM4_VIE_GetParaConfig(m_nPlayerPort,&param);
			}
			if(bRet == TRUE)
			{
				bRet = PlayM4_VIE_SetParaConfig(m_nPlayerPort,&param);
			}
			if(bRet == FALSE)
			{
				return false;
			}	
			break;
		}
	case 4://亮度调节
		{
			int nBrightlevel = 0;
			bRet = PlayM4_GetColor(m_nPlayerPort,NULL,&nBrightlevel,&y1,&x2,&y2); 
			if(bRet == TRUE)
			{
				bRet = PlayM4_SetColor(m_nPlayerPort,NULL,x1,y1,x2,y2); 
			}			
			if(bRet == FALSE)
			{
				return false;
			}			
			break;
		}
	default:
		{
			return false;
		}
	}
	return true;
}

bool HKPlayHandle::SetYUVCallBack(LPYUVCALLBACK pCallBack)
{
	return true;
}
bool HKPlayHandle::SetStreamSaveTime( int nSaveTime)
{
	return true;
}
bool HKPlayHandle::PlayBackSaveStream( HWND hWnd)
{
	return true;
}
bool HKPlayHandle::StopPlayBackSaveStream( )
{
	return true;
}

//2013 0927 pzm add
bool HKPlayHandle::SetRenderMode( int nMode)
{
	return false;
}

bool HKPlayHandle::SetPosByFrameNum(DWORD nFrameNum)
{
	FRAME_POS pos;
	BOOL bRet =  PlayM4_GetKeyFramePos(m_nPlayerPort,nFrameNum,BY_FRAMENUM,&pos);
	if(bRet == FALSE)
		return false;

	int nKeyFrame = pos.nFrameNum;
	bRet =  PlayM4_SetCurrentFrameNum(m_nPlayerPort,nKeyFrame);
	if(bRet == FALSE)
		return false;

	return true;
}

bool HKPlayHandle::GetVideoCut( DWORD beginFrame, DWORD endFrame, LPSTR filename)
{
	DWORD dwStartFrame = 0; 
	DWORD dwEndFrame = 0; 
	string strSaveFileName;
	FRAME_POS	strRealBegin;
	FRAME_POS	strRealEnd;
	int		    nPort = m_nPlayerPort;
	int			nType = BY_FRAMENUM;
	HANDLE		hPlayFile = m_hStreamFile;

	dwStartFrame = beginFrame;
	dwEndFrame	 = endFrame;
	strSaveFileName = filename;
	{
		DWORD		nMaxFrameNum;
		DWORD		nMaxTime;
		nMaxTime     = PlayM4_GetFileTime(nPort);
		nMaxFrameNum = PlayM4_GetFileTotalFrames(nPort);
		//PlayM4_SetOverlayMode(nPort, TRUE, RGB(255,0,255));
		//PlayM4_ThrowBFrameNum(nPort,0) ;
		//doSetFileName(strFileName);

		//if (nType == BY_FRAMETIME)
		//{
		//	dwStartFrame *= 1000;
		//	dwEndFrame   *= 1000;
		//}


		memset(&strRealBegin,0,sizeof(FRAME_POS));
		memset(&strRealEnd,0,sizeof(FRAME_POS));

		BOOL bRet=PlayM4_GetKeyFramePos(nPort, dwStartFrame, nType, &strRealBegin);
		int nError = PlayM4_GetLastError(nPort);

		if(!PlayM4_GetNextKeyFramePos(nPort, dwEndFrame, nType, &strRealEnd))
		{
			int ret = PlayM4_GetLastError(nPort);
			strRealEnd.nFilePos   = SetFilePointer(hPlayFile, 0, 0, FILE_END);
			strRealEnd.nFrameNum  = nMaxFrameNum;
			strRealEnd.nFrameTime = nMaxTime*1000;
		}

		int nNewFileLen = int(strRealEnd.nFilePos - strRealBegin.nFilePos);
		HANDLE hNewFile = INVALID_HANDLE_VALUE;
		DWORD nSize = 2048;		//Per 2k data;
		PBYTE pBuf  = NULL;
		DWORD nFileHeadLen = PlayM4_GetFileHeadLength();
		DWORD nRet;
		DWORD nBlock  = nNewFileLen / nSize;
		DWORD nRemain = nNewFileLen % nSize;
		DWORD nCount;

		try
		{
			hNewFile = CreateFile(
				strSaveFileName.c_str(),
				GENERIC_WRITE,
				FILE_SHARE_READ | FILE_SHARE_WRITE,
				NULL,
				CREATE_ALWAYS,
				FILE_ATTRIBUTE_NORMAL,
				NULL );
			if(hNewFile == INVALID_HANDLE_VALUE)
			{
				return 0 ;
			}


			pBuf = new BYTE [nSize];
			if(NULL == pBuf)
			{
				return 0 ;
			}

			//file header
			SetFilePointer(hPlayFile, 0, 0, FILE_BEGIN);
			if(!ReadFile(hPlayFile, pBuf, nFileHeadLen, &nRet, NULL))
			{
				return 0 ;
			}
			else
			{
				if(!WriteFile(hNewFile, pBuf, nFileHeadLen, &nRet, NULL))
				{
					return 0 ;
				}
			}
			SetFilePointer(hPlayFile, strRealBegin.nFilePos, 0, FILE_BEGIN);


			for(nCount = 0; nCount < nBlock; nCount ++)
			{
				if(!ReadFile(hPlayFile, pBuf, nSize, &nRet, NULL))
				{
					return 0 ;
				}
				if(!WriteFile(hNewFile, pBuf, nSize, &nRet, NULL))
				{
					return 0 ;
				}
			}

			if(!ReadFile(hPlayFile, pBuf, nRemain, &nRet, NULL))
			{
				return 0 ;
			}
			else
			{
				if(!WriteFile(hNewFile, pBuf, nRemain, &nRet, NULL))
					return 0 ;
			}

		}

		catch(...)
		{
		}
		if(pBuf != NULL)
		{
			delete []pBuf;
			pBuf = NULL;
		}

		if(hNewFile != INVALID_HANDLE_VALUE)
		{
			CloseHandle(hNewFile);
			hNewFile = INVALID_HANDLE_VALUE;
		}
		return 0 ;
	}
	return true;
}

bool HKPlayHandle::StopCutVideo( )
{
	return true;
}

struct HKPlayHandleS
{
	HKPlayHandle *pHandle;
	void *pUser;
};

void HKPlayHandle::pHKFileOverCB(long nPort, void *pUser)
{
	HKPlayHandleS *pInfo = (HKPlayHandleS *)pUser;
	if(pInfo != NULL)
	{
		pInfo->pHandle->m_pFileOverCB(pInfo->pUser);
	}
	//delete pInfo;
}

bool HKPlayHandle::SetFileEndCallback( void *pUser,pFileOverCB pCallBack)
{
	HKPlayHandleS *pInfo = new HKPlayHandleS;
	m_pFileOverCB = pCallBack;
	pInfo->pUser   = pUser;
	pInfo->pHandle = this;
	BOOL bRet =  PlayM4_SetFileEndCallback(m_nPlayerPort,pHKFileOverCB,pInfo);
	if(bRet == FALSE)
		return false;

	return true;
}

bool HKPlayHandle::GetMediaInfo(MediaInf &mInf)
{
	return false;
}

bool HKPlayHandle::GetDecodeParam( int nCmd, int &x1, int &y1, int &x2, int &y2)
{
	BOOL bRet = FALSE;
	int nModuleType = 0;
	PLAYM4_VIE_PARACONFIG param = {0};
	switch (nCmd)
	{
	case 1://去雾
		{
			bRet = PlayM4_VIE_GetModuConfig(m_nPlayerPort,&nModuleType);
			if(bRet == FALSE || nModuleType != PLAYM4_VIE_MODU_DEHAZE)
			{
				return false;
			}	
			break;
		}
	case 2://反色
		{
			return false;
			break;
		}
	case 3://锐化
		{	
			bRet = PlayM4_VIE_GetModuConfig(m_nPlayerPort,&nModuleType);
			if(bRet == FALSE || nModuleType != PLAYM4_VIE_MODU_DEHAZE)
			{
				return false;
			}	
			break;
		}
	case 4://亮度调节
		{
			bRet = PlayM4_GetColor(m_nPlayerPort,NULL,&x1,&y1,&x2,&y2); 			
			if(bRet == FALSE)
			{
				return false;
			}			
			break;
		}
	default:
		{
			return false;
		}
	}
	return true;
}

int  HKPlayHandle::AllpurposeI(int nCmd,char *pInPutPara,char *pOutPutPara)
{
	if(pInPutPara == NULL || pOutPutPara == NULL)
	{
		return 0;
	}

	switch(nCmd)
	{
	case 1:
		{
			return 1;
		}
	default:
		return 0;
	}
}