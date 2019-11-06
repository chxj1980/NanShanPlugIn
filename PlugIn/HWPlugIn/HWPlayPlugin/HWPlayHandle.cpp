#include "StdAfx.h"
#include "HWPlayHandle.h"
#include "AudioPlay.h"

LPDecCBFun m_pDecCBCallBack = NULL;
vector<DHPlayHandle::PLAYERINFO> DHPlayHandle::m_vPlayChan;
char * DHPlayHandle::mFileName = NULL;
int DHPlayHandle::m_PlayPort = -1; //���ھ�̬������

CRITICAL_SECTION DHPlayHandle::m_Lock;

DHPlayHandle::DHPlayHandle(void)
{
    m_nDecodeType = 0 ;
    m_bHasSendInit = false;
    m_nPlayerPort = 0;
    m_bHasOpenStream = false;
    m_nDeviceNum = 0;
    m_CountBag = 0 ;

    m_nLocPlayPort = -1;
	m_fSpeed = 1.0;
    m_nFilePlayerPort = -1;
    m_hStreamFile = INVALID_HANDLE_VALUE;
    m_nFileHead = 0;
    m_nFileOffset = 0;

    m_read = true;
    m_nPuse = false;

    mFileName =NULL;

	//m_log.SetLogLevel(LOG_CLOSE);
    m_log.SetFileName("C:\\NVSLog\\SDKEngine\\HWPlayPlugIn.log");
    m_log.SetFileSize(1024);//1M��С
   
	m_hWnd	= NULL;
	m_pDrawCallBack = NULL;
	m_pUserDraw	    = NULL;

	m_bOpenSound = false;
	m_pAudioHandle = NULL;
	m_aout = NULL;

	m_nSrcWind = 0;
	m_nSrcWidth = 0;
	m_nSrcHight = 0;
	m_Xlpoit = 0;
	m_Xrpoit = 0;
	m_Ytpoit = 0;
	m_Ydpoit = 0;
}

DHPlayHandle::~DHPlayHandle(void)
{
	//DeleteCriticalSection(&m_Lock);
}

bool DHPlayHandle::initialPlayer( int nPort,int nDecodeType,BYTE* buff, int nSize, int nStreamType )
{
	
	char szPath[256] = {0};
	GetModuleFileName(NULL,szPath,sizeof(szPath));
	strrchr(szPath, '\\')[1] = '\0';
	strcat(szPath, "DecodeEngine.ini");
	int nLoglevel = GetPrivateProfileInt("LOG", "Log", 1, szPath);
	m_nDecodeType = GetPrivateProfileInt("DECODE", "Engine",0,szPath);
	int nRenderType = GetPrivateProfileInt("DECODE", "Render", 0, szPath);
	UINT nBufferSize = GetPrivateProfileInt("DECODE", "BufferSize", 1024*1024, szPath);

	m_log.SetLogLevel(nLoglevel);

    m_bHasSendInit = false;

	m_nStreamType = nStreamType;

    PLAY_GetFreePort((LONG *)&nPort);
    m_nPlayerPort = nPort;


    m_log.LogInfoEx(LOG_WARNING , "initialPlayer nPort = %d,nDecodeType = %d,StreamType = %d\r\n",nPort,m_nDecodeType,nStreamType);

    bool bRe;

	//if (nStreamType > 1)
	//{
	//	nStreamType = STREAME_FILE;
	//}
	//else
	//{
	//	nStreamType = STREAME_REALTIME;
	//}

    bRe = PLAY_SetStreamOpenMode(nPort, nStreamType);//ʵʱ��

    bRe = PLAY_OpenStream(nPort, NULL, 0,nBufferSize);

    
    if(!bRe)
    {
        m_log.LogInfoEx(LOG_ERROR ,"��ʼ������ʧ��!!PLAY_SetStreamOpenMode");
        return false;
    }

    //bRe = PLAY_SetDisplayBuf(nPort,10);
	DecodeType nDecode = DECODE_SW;
	if (m_nDecodeType == 1)
	{
		nDecode = DECODE_HW;
	}
	else if (m_nDecodeType == 2)
	{
		nDecode = DECODE_HW_FAST;
	}
	RenderType nRender = RENDER_NOTSET;
	if (nRenderType == 1)
	{
		nRender = RENDER_D3D;
	}
	else if (nRenderType == 2)
	{
		nRender = RENDER_DDRAW;
	}
	else if (nRenderType == 3)
	{
		nRender = RENDER_WGL;
	}

	bRe = PLAY_SetEngine(nPort,nDecode,nRender);
	

    m_nPlayerPort = nPort;
	m_nLocPlayPort = nPort;
    m_bHasOpenStream = true;

	m_bOpenSound = true;
	m_pAudioHandle = AudioOpen(AUDIO_PCMU);
	//m_aout = fopen("test.pcm", "ab+");
    m_log.LogInfoEx(LOG_WARNING ,"��ʼ�����ųɹ�!!");
    return true;
}

bool DHPlayHandle::startPlayer( HWND hWnd )
{
	PLAY_SetPicQuality(m_nPlayerPort, FALSE);
    if(!PLAY_Play(m_nPlayerPort,hWnd))
    {
        PLAY_ResetSourceBuffer(m_nPlayerPort);
        return false;
    }
	//RECT rt;
	//GetClientRect(hWnd,&rt);
	//if (rt.right < 1000)
	//{
	//	PLAY_SetPicQuality(m_nPlayerPort,FALSE);
	//}
	m_hWnd = hWnd;
	return true;
}

void  DHPlayHandle::DrawFunCallBack(long nPort,HDC hDc,void *nUser)
{
	DHPlayHandle* pHandler = (DHPlayHandle*)nUser;

	try
	{
		if(NULL == pHandler || 
			NULL == pHandler->m_pDrawCallBack || 
			!AfxIsValidAddress(pHandler,4) || 
			!AfxIsValidAddress(pHandler->m_pDrawCallBack,4) //||
			)
		{
			//pHandler->m_log.LogInfoEx(LOG_ERROR , "DrawFunCallBack! ��Чָ��");
			return;
		}
	}
	catch (...){
		pHandler->m_log.LogInfoEx(LOG_ERROR , "DrawFunCallBack Exception!");
		return;
	}
	pHandler->m_pDrawCallBack((LONG)pHandler, nPort, (DWORD) hDc, pHandler->m_pUserDraw);
}

bool DHPlayHandle::startPlayer2( HWND hWnd, LPDRAWCBCALLLBACK lpDrawCBFun, void *pUser )
{
    m_log.LogInfoEx(LOG_INFO ,"startplayer2\r\n");

	m_pDrawCallBack = lpDrawCBFun;
	m_pUserDraw		= pUser;
	BOOL bRe = PLAY_RigisterDrawFun(m_nPlayerPort,DrawFunCallBack,(void *)this);


    return startPlayer(hWnd);
}

bool DHPlayHandle::startPlayer4Standard( HWND hWnd,LPDecCBFun lpDecCBFun, int nCameraID )
{
	if (hWnd)
	{
		return true;
	}
    if(lpDecCBFun == NULL)
        return false;

    m_pDecCBCallBack = lpDecCBFun; 

    bool bRe = PLAY_SetDecCallBack(m_nPlayerPort,DecCBFun4Standard);
	//BOOL bRe = PLAY_SetDecodeCallBack(m_nPlayerPort, DecCBDecode, (void *)this);
    if (!bRe)
    {
        return bRe;
    }

    PLAYERINFO tPlayInfo;
    tPlayInfo.nPlayerPort = m_nPlayerPort;
    tPlayInfo.nCameraID = nCameraID;
	EnterCriticalSection(&m_Lock);
	m_vPlayChan.push_back(tPlayInfo);
	LeaveCriticalSection(&m_Lock);
   

    bRe = PLAY_Play(m_nPlayerPort,hWnd);
    if(!bRe)
    {
        DWORD ttt= PLAY_GetLastError(m_nPlayerPort);
        if(ttt==0)
            return true;

        return false;
    }

    return bRe;
}

bool DHPlayHandle::addData( BYTE* buff, int nSize )
{

   // m_log.LogInfoEx(LOG_INFO , "[addData][%d], size=%d, countsize=%d", this, nSize, m_CountBag+=nSize);

    if(buff && nSize>0)
    {
        try
        {
			if (buff[0] == 0 && buff[1] == 0 && buff[2] == 0 && buff[3] == 1)
			{
				if(FALSE==PLAY_InputData(m_nPlayerPort,buff,nSize))
				{
					//ʧ��
					DWORD dwResult = PLAY_GetLastError(m_nPlayerPort);

					//m_log.LogInfoEx(LOG_INFO , "[addData][PLAY_InputData] Error, ErrorCode=%d", dwResult);

				}
				if(1 == m_nStreamType)
				{
					DWORD nBufSize = PLAY_GetBufferValue(m_nPlayerPort, BUF_VIDEO_SRC);
					if(nBufSize > BUFFERMAXSIZE * 2 / 3)
					{
						Sleep(100);
					}
				}
			}
			else
			{
				if (m_aout)
				{
					fwrite(buff,nSize,1,m_aout);
				}
				if (m_pAudioHandle)
				{
					if (m_bOpenSound)
					{
						AudioPlay(m_pAudioHandle,buff,nSize);
					}
					
				}
			}

        }
        catch(...){}
    }
    else
    {
   	 	PLAY_ResetSourceBuffer(m_nPlayerPort);
    	PLAY_ResetBuffer(m_nPlayerPort, BUF_VIDEO_RENDER);
    }
   // m_log.LogInfoEx(LOG_INFO , "[addData_end][%d]", this);
    return true;
}

bool DHPlayHandle::stopPlayer()
{
    m_bHasOpenStream = false;
    m_bHasSendInit = false;

	if (m_aout)
	{
		fclose(m_aout);
		m_aout = NULL;
	}
	if (m_pAudioHandle)
	{
		AudioClose(m_pAudioHandle);
		m_pAudioHandle = NULL;
	}
	EnterCriticalSection(&m_Lock);
	vector<PLAYERINFO>::iterator it = m_vPlayChan.begin(); //û�ܱ���
	for(;it!=m_vPlayChan.end();++it)
	{
		if((*it).nPlayerPort == m_nPlayerPort)
		{
			m_vPlayChan.erase(it);
			break;
		}
	}
	LeaveCriticalSection(&m_Lock);

    //PLAY_Pause(m_nLocPlayPort,FALSE);
    //Sleep(50);
	PLAY_Stop(m_nPlayerPort);
	PLAY_CloseStream(m_nPlayerPort);
	PLAY_ReleasePort(m_nPlayerPort);

	m_pDrawCallBack = NULL;
	m_pUserDraw = NULL;
	m_pDecCBCallBack = NULL;

    return true;
}

bool DHPlayHandle::controlPTZSpeed(int nCmd, bool bEnable,int nSpeed)
{
	return controlPTZSpeedWithChannel(nCmd, bEnable, nSpeed, 0);
}

bool DHPlayHandle::controlPTZSpeedWithChannel(int nCmd, bool bEnable, int nSpeed, int nChannel)
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
		int pleft = 0, ptop = 0, pright = 0, pdow = 0;//ԭ����������
		int nleft = 0, ntop = 0, nright = 0, ndow = 0;//��ѡ��������
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
			m_log.LogInfoEx(LOG_ERROR, "src:%d,%d,%d,%d dst:%d,%d,%d,%d\n", pleft, ptop, pright, pdow, nleft, ntop, nright, ndow);
			if (PLAY_GetPictureSize(m_nPlayerPort, &m_nSrcWidth, &m_nSrcHight))
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
		DISPLAYRECT rect;
		rect.bottom = m_Ydpoit;
		rect.top = m_Ytpoit;
		rect.left = m_Xlpoit;
		rect.right = m_Xrpoit;
		if (!PLAY_SetDisplayRegion(m_nPlayerPort, 0, &rect, m_hWnd, true))
		{
			return false;
		}
	}
	return true;
}

void CALLBACK FileRefDone(DWORD nReserved, BOOL bIndexCreated, void *nUser)
{

}

void CALLBACK EncTypeChangeFunc(long nPort, void *nUser)
{

}


bool DHPlayHandle::locPlay_OpenFile( int nPort,int nDecodeType, HWND hWnd,char* fileName )
{
	m_hStreamFile = CreateFile(fileName,GENERIC_READ,FILE_SHARE_READ,NULL,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,NULL);
	if(INVALID_HANDLE_VALUE == m_hStreamFile)
	{
		CloseHandle(m_hStreamFile);
		m_log.LogInfoEx(LOG_ERROR , "CreateFile fileName %s ʧ��",fileName);
		return false;
	}

    if(!PLAY_OpenFile(nPort,fileName))
    {
		CloseHandle(m_hStreamFile);
		DWORD err = PLAY_GetLastError(nPort);
		m_log.LogInfoEx(LOG_ERROR , "PLAY_GetLastError fileName %s ʧ��,err = %d",fileName,err);
        return false;
    }
	PLAY_SetEncTypeChangeCallBack(nPort, EncTypeChangeFunc, (void *)this);
	PLAY_SetFileRefCallBackEx(nPort, FileRefDone, (void *)this);
    m_nLocPlayPort = nPort;
	m_hWnd		   = (HWND)hWnd;

    if(!PLAY_Play(m_nLocPlayPort,(HWND)hWnd))
	{
		CloseHandle(m_hStreamFile);
		DWORD err = PLAY_GetLastError(nPort);
		m_log.LogInfoEx(LOG_ERROR , "PLAY_Play fileName %s ʧ��,err = %d",fileName,err);
		return false;
	}

	if(!PLAY_Pause(m_nLocPlayPort, FALSE))
	{
		CloseHandle(m_hStreamFile);
		DWORD err = PLAY_GetLastError(nPort);
		m_log.LogInfoEx(LOG_ERROR , "PLAY_Pause fileName %s ʧ��,err = %d",fileName,err);
		return false;
	}

    return true;
}

bool DHPlayHandle::locPlay_Control( int nCmd,int nInValue,int* outValue )
{
	char szLog[256] = {0};
	sprintf_s(szLog,"%s,%d,Port:%d",__FUNCTION__,__LINE__,m_nLocPlayPort);
	m_log.LogInfoEx(LOG_INFO,"%s,%d",szLog,nCmd);
	BOOL bRet = FALSE;

    switch(nCmd)
    {
    case LOCPLAY_CTRL_PLAYPAUSE://��ͣ����
        {
			bRet = PLAY_Pause(m_nLocPlayPort,TRUE);
			break;
		} 
    case LOCPLAY_CTRL_PLAYRESTART://�ָ�����
		{
			bRet = PLAY_Pause(m_nLocPlayPort,FALSE);
			break;
		} 
    case LOCPLAY_CTRL_PLAYFAST://���
		{
			 bRet =   PLAY_Fast(m_nLocPlayPort);
			 break;
		}	
    case LOCPLAY_CTRL_PLAYSLOW://����
		{
			 bRet =  PLAY_Slow(m_nLocPlayPort);
			 break;
		}	       
    case LOCPLAY_CTRL_PLAYNORMAL://�����ٶ�
		{
			bRet =  PLAY_Play(m_nLocPlayPort,m_hWnd);
			break;
		}	        
    case LOCPLAY_CTRL_PLAYFRAME://��֡��
		{
			bRet =  PLAY_OneByOne(m_nLocPlayPort);
			break;
		}	
    case LOCPLAY_CTRL_PLAYSTARTAUDIO://������
        return PLAY_PlaySound(m_nLocPlayPort);
    case LOCPLAY_CTRL_PLAYSTOPAUDIO://�ر�����
        return PLAY_StopSound();//m_nLocPlayPort
    case LOCPLAY_CTRL_PLAYAUDIOVOLUME://��������
        return PLAY_SetVolume(m_nLocPlayPort,(WORD) nInValue);
	case LOCPLAY_CTRL_PLAYSETPOS://�ı��ļ��طŵĽ���
		{
			bRet =  PLAY_SetPlayPos(m_nLocPlayPort,(float)((float) nInValue/100));
			break;
		} 
    case LOCPLAY_CTRL_PLAYGETPOS://��ȡ�ļ��طŵĽ���
        {
            float fPos = 0.;
            fPos = PLAY_GetPlayPos(m_nLocPlayPort);
            *outValue = (int)(fPos*100);
            return true;
        }
    case LOCPLAY_CTRL_PLAYGETTIME://��ȡ��ǰ�Ѿ����ŵ�ʱ��
        {
            *outValue = (int)PLAY_GetPlayedTime(m_nLocPlayPort);
            return true;
        }
    case LOCPLAY_CTRL_PLAYGETFRAME://��ȡ��ǰ�Ѿ����ŵ�֡��
        {
            *outValue = (int)PLAY_GetCurrentFrameNum(m_nLocPlayPort);
            return true;
        }
    case LOCPLAY_CTRL_GETTOTALFRAMES://��ȡ��ǰ�����ļ��ܵ�֡��
        {
            *outValue = (int)PLAY_GetFileTotalFrames(m_nLocPlayPort);
            return true;
        }
    case LOCPLAY_CTRL_GETTOTALTIME://��ȡ��ǰ�����ļ��ܵ�ʱ��
        {
            *outValue = (int)PLAY_GetFileTime(m_nLocPlayPort);
            return true;
        }
	case LOCPLAY_CTRL_PLAYSETFRAME://���õ�ǰ�����ļ�֡��
		{
			int nFrame = nInValue;
			*outValue = PLAY_SetCurrentFrameNum(m_nLocPlayPort,nFrame);
			DWORD dwRe1 = PLAY_GetLastError(m_nLocPlayPort);
			m_log.LogInfoEx(LOG_WARNING , "locPlay_Control nCmd :%d,nInValue :%d,m_nDecodeType:%d,m_nPlayerPort:%d bRet = %d,lasterror =  %d",nCmd,nInValue,m_nDecodeType,m_nLocPlayPort,*outValue,(int)dwRe1);
			return true;
		}
    }
	DWORD dwRe = PLAY_GetLastError(m_nLocPlayPort);
	if(bRet == FALSE)
		m_log.LogInfoEx(LOG_WARNING , "locPlay_Control nCmd :%d,nInValue :%d,m_nDecodeType:%d,m_nPlayerPort:%d bRet = %d,lasterror =  %d",nCmd,nInValue,m_nDecodeType,m_nLocPlayPort,bRet,(int)dwRe);
	return bRet;
}

bool DHPlayHandle::locPlay_Stop()
{
    PLAY_Stop(m_nLocPlayPort);
    PLAY_CloseFile(m_nLocPlayPort);
	if(m_hStreamFile && m_hStreamFile != INVALID_HANDLE_VALUE)
	{
		CloseHandle(m_hStreamFile);
	}
    ///PLAY_Free();
    return true;
}

bool DHPlayHandle::convertToBmpFile( char * pBuf,LONG nSize,LONG nWidth,LONG nHeight,LONG nType,char *sFileName )
{
    bool bRe = (bool)PLAY_ConvertToBmpFile(pBuf,nSize,nWidth,nHeight,nType,sFileName);
    return bRe;

}

bool DHPlayHandle::oneByOneBack( LONG nPort )
{
    bool bRe = (bool)PLAY_OneByOneBack(nPort);
    return bRe;
}

bool DHPlayHandle::oneByOne( LONG nPort )
{
    bool bRe = (bool)PLAY_OneByOne(nPort);
    return bRe;
}

bool DHPlayHandle::setPlayedTimeEx( LONG nPort,DWORD nTime )
{
    bool bRe = (bool)PLAY_SetPlayedTimeEx(nPort,nTime);
    return bRe;
}

void DHPlayHandle::reSetDDrawDevice( HWND hWnd )
{
    PLAY_RefreshPlay(m_nPlayerPort);
}

bool DHPlayHandle::controlCameraSound( bool bOpenSound )
{
    if(bOpenSound)
	{
		m_bOpenSound = true;
		if (m_pAudioHandle == NULL)
		{
			m_pAudioHandle = AudioOpen(AUDIO_PCMU);
		}
        //return PLAY_PlaySound(m_nPlayerPort);
	}
    else
	{
		m_bOpenSound = false;
		if (m_pAudioHandle)
		{
			AudioClose(m_pAudioHandle);
			m_pAudioHandle = NULL;
		}
        //return PLAY_StopSound();
	}
	return true;
}

intptr_t DHPlayHandle::openVideoFile( char *sFileName )
{
    m_bDvrFile = false;
    long lPort = -1;
    BOOL bRe =	PLAY_GetFreePort(&lPort);
    if(!bRe)
    {
        DWORD dwRe1 = PLAY_GetLastError(lPort);
        return -8;
    }

    m_nFilePlayerPort = lPort;
    PLAY_SetFileRefCallBack(m_nFilePlayerPort,DecCBFunc, (void *)this);


    if(!PLAY_OpenFile(m_nFilePlayerPort,sFileName))
    {
        m_log.LogInfoEx(LOG_ERROR ,"�ļ���ʧ��");
        DWORD dwRe1 = PLAY_GetLastError(lPort);
        m_log.LogInfoEx(LOG_ERROR ,"PLAY_GetLastError ʧ��! ������=%d\n", dwRe1);

        PLAY_ReleasePort(m_nFilePlayerPort);
        return -9;
    }

    m_hStreamFile = CreateFile(sFileName,GENERIC_READ,FILE_SHARE_READ,NULL,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,NULL);
    if(INVALID_HANDLE_VALUE == m_hStreamFile)
    {
        closeVideoFile();
        return -10;
    }

	m_read = true;

    return (long)m_hStreamFile;
}

int DHPlayHandle::readVideoFile( char *buff,int len, int *streamType )
{
    DWORD nRealRead = 0;
    if(INVALID_HANDLE_VALUE == m_hStreamFile)
    {
#ifdef _DEBUG
        m_log.LogInfoEx(LOG_INFO ,"File handle error. m_hStreamFile = INVALID_HANDLE_VALUE\r\n");
#endif
        return 0;
    }

    if(0 == m_nFileHead)
    {
        m_fileTotalTime = PLAY_GetFileTime(m_nFilePlayerPort);
        m_nFileTotalSize = ::GetFileSize(m_hStreamFile,NULL);
        *streamType = DVR_DATA_INIT;                //DVR_DATA_STREAM
        strcpy(buff,"|DH|α��Ĵ�ͷ");

        m_nFileHead = 1;
        return 40;
    }
    else 
    {
        if(m_nFileOffset >= m_nFileTotalSize)
        {
            return -1;     //�ļ���ȡ���
        }

        if(m_read == false)
        {
            return -1;    //�ļ���ȡ����
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
            return -2;   //�ļ���ͣ
        }
    }
    m_nFileOffset += nRealRead;
    return nRealRead;
}

bool DHPlayHandle::closeVideoFile()
{
    m_read = false;
    if(m_hStreamFile)
    {
        CloseHandle(m_hStreamFile);
        m_hStreamFile = NULL;
    }
    if (m_nFilePlayerPort != -1)
    {
        PLAY_CloseFile(m_nFilePlayerPort);
        PLAY_ReleasePort(m_nFilePlayerPort);
        m_nPlayerPort = -1;
    }

    m_nFileOffset = 0;
    m_nFileTotalSize = 0;
    m_fileTotalTime = 0;
    return true;
}

bool DHPlayHandle::controlPlay( int nCmd,int param, int *outValue )
{
	if (m_nFilePlayerPort < 0)
	{
		return false;
	}

   /* if(m_hStreamFile)
    {
        CloseHandle(m_hStreamFile);
        m_hStreamFile = NULL;
    }
    if (m_nFilePlayerPort != -1)
    {
        PLAY_CloseFile(m_nFilePlayerPort);
        PLAY_ReleasePort(m_nFilePlayerPort);
        m_nPlayerPort = -1;
    }*/

	int nErr;
	switch(nCmd)                                  //�ļ���ý����ƽӿ�2014-01-14
	{
	case REPLAY_CTRL_PLAYRESTART:                 //��������
		*outValue = 0;
		m_nPuse = false;
		return true;
	case REPLAY_CTRL_PLAYFAST:                    //���
		*outValue = 0;
		return true;
	case REPLAY_CTRL_PLAYSLOW:                    //����
		*outValue = 0;
		return true;
	case REPLAY_CTRL_PLAYNORMAL:                  //�����ٶ�
		*outValue = 0;
		return true;
	case REPLAY_CTRL_PLAYFRAME:                   //��֡����
		*outValue = 0;
		return false;
	case REPLAY_CTRL_PLAYPAUSE:                    //��ͣ
		*outValue = 0;
		m_nPuse = true;
		return true; 
	case REPLAY_CTRL_PLAYSETPOS:                   //�ı����
		break;
	case REPLAY_CTRL_PLAYGETPOS:                   //��ȡ����
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
	case REPLAY_CTRL_GETFILESIZE:                 //�ļ��ܴ�С
		*outValue = m_nFileTotalSize/1024;
		return true;
	case REPLAY_CTRL_GETTOTALTIME:                //��ȡ�ļ�����ʱ��
		*outValue = PLAY_GetFileTime(m_nFilePlayerPort);
		return true;
	case REPLAY_CTRL_GETTOTALFRAMES:
		{
			*outValue = PLAY_GetFileTotalFrames(m_nFilePlayerPort);
			nErr = PLAY_GetLastError(m_nFilePlayerPort);
		}
		
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

	if(PLAY_GetKeyFramePos(m_nFilePlayerPort,param,BY_FRAMENUM,&currentPos))
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

void DHPlayHandle::ClearPlayBuffer()
{
    if (m_nPlayerPort>=0)
    {
        PLAY_ResetSourceBuffer(m_nPlayerPort);		
    }
}

void DHPlayHandle::pusePlayDecode( bool bPuse )
{
    if (m_nLocPlayPort>=0)
    {
        if (bPuse)
        {
            PLAY_Pause(m_nLocPlayPort,TRUE);	
        }
        else
            PLAY_Pause(m_nLocPlayPort,FALSE);	

    }  
}

bool DHPlayHandle::setFileRefCallBack( LONG nPort,void (__stdcall *pFileRefDone) (DWORD nPort,void *nUser),void *nUser )
{
    //bool bRe = (bool)PLAY_SetFileRefCallBackEx(nPort, pFileRefDone, nUser);
    return false;
}

void CALLBACK DisplayCallBack(long nPort,char * pBuf,long nSize,long nWidth,long nHeight,long nStamp,long nType,void *nReserved)
{
	DHPlayHandle *pHandle = (DHPlayHandle *)nReserved;
	char szType[256] = "DH";
	nReserved = szType;
	if(pHandle->m_pFileRefDone != NULL)
		pHandle->m_pFileRefDone( nPort, pBuf, nSize, nWidth, nHeight, nStamp, nType, nReserved);
}

bool DHPlayHandle::setDisplayCallBack( LONG nPort, void (__stdcall *pFileRefDone)(long nPort,char * pBuf,long nSize,long nWidth,long nHeight,long nStamp,long nType,void *nReserved) )
{
	BOOL bRe;
	m_log.LogInfoEx(LOG_INFO , "setDisplayCallBack: %d .�ɹ�",this);
	if(pFileRefDone == NULL)
	{
		PLAY_Pause(nPort,TRUE);
		bRe = PLAY_SetDisplayCallBack(nPort,NULL,(void *)this);
	}
	else
	{
		PLAY_Pause(nPort,FALSE);
		bRe = PLAY_SetDisplayCallBack(nPort,(fDisplayCBFun)DisplayCallBack,(void *)this);
	}
	m_pFileRefDone = pFileRefDone;		
	if(bRe == FALSE)
		return false;

	return true;
}

bool DHPlayHandle::capturePicture( char* sFilePath )
{

    int len = strlen(sFilePath);
    mFileName = new char[len+1];
    strcpy(mFileName ,sFilePath);
    m_PlayPort = m_nPlayerPort;
    PLAY_CatchPic(m_PlayPort,mFileName);
    delete mFileName;
    mFileName = NULL;
    return true;
}

void CALLBACK DHPlayHandle::DecCBFun4Standard( long nPort,char * pBuf,long nSize,FRAME_INFO * pFrameInfo, void *nReserved1,long nReserved2 )
{
    int nChanID = -1;
    FRAME_INFO_D mFrameInfo;
	if (pFrameInfo == NULL || pFrameInfo->nType != T_IYUV || nSize != (long)(pFrameInfo->nHeight * pFrameInfo->nWidth * 1.5))
	{
		return;
	}
    EnterCriticalSection(&m_Lock);
    try
    {

        mFrameInfo.nFrameRate = pFrameInfo->nFrameRate;
        mFrameInfo.nHeight = pFrameInfo->nHeight;
        mFrameInfo.nStamp = pFrameInfo->nStamp;
        mFrameInfo.nType = T_IYUV;
        mFrameInfo.nWidth = pFrameInfo->nWidth;


        vector<PLAYERINFO>::iterator it = m_vPlayChan.begin(); //û�ܱ���
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

	char *yv12 = new char[nSize + 1];
	memset(yv12,0,nSize +1);
	int ylen = pFrameInfo->nHeight * pFrameInfo->nWidth;
	int ulen = pFrameInfo->nHeight * pFrameInfo->nWidth / 4;
	memcpy(yv12,pBuf, ylen);
	memcpy(yv12+ylen, pBuf+ylen+ulen, ulen);
	memcpy(yv12+ylen+ulen, pBuf+ylen, ulen);
    if (nChanID!=-1 && m_pDecCBCallBack)
    {
        m_pDecCBCallBack(nPort,yv12,nSize,&mFrameInfo, nChanID);
    }
	delete[] yv12;
	yv12 = NULL;
}

void CALLBACK DHPlayHandle::DecCBDecode(LONG nPort, FRAME_DECODE_INFO* pFrameDecodeInfo, FRAME_INFO_EX* pFrameInfo, void* pUser)
{
	int nChanID = -1;
	FRAME_INFO_D mFrameInfo;
	if (pFrameInfo  == NULL || pFrameInfo->nFrameType == FRAME_TYPE_AUDIO)
	{
		return;
	}
	EnterCriticalSection(&m_Lock);
	try
	{

		mFrameInfo.nFrameRate = pFrameInfo->nFrameRate;
		mFrameInfo.nHeight = pFrameInfo->nHeight;
		mFrameInfo.nStamp = pFrameInfo->nStamp;
		mFrameInfo.nType = 3;
		mFrameInfo.nWidth = pFrameInfo->nWidth;


		vector<PLAYERINFO>::iterator it = m_vPlayChan.begin(); //û�ܱ���
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

	int nSize = pFrameDecodeInfo->nStride[0]+pFrameDecodeInfo->nStride[1]+pFrameDecodeInfo->nStride[2];
	char *pBuf = new char[nSize+1];
	memset(pBuf,0,nSize+1);
	memcpy(pBuf, pFrameDecodeInfo->pVideoData[0], pFrameDecodeInfo->nStride[0]);
	memcpy(pBuf+pFrameDecodeInfo->nStride[0], pFrameDecodeInfo->pVideoData[2], pFrameDecodeInfo->nStride[2]);
	memcpy(pBuf+pFrameDecodeInfo->nStride[0]+pFrameDecodeInfo->nStride[2], pFrameDecodeInfo->pVideoData[1], pFrameDecodeInfo->nStride[1]);
	if (nChanID!=-1 && m_pDecCBCallBack)
	{
		m_pDecCBCallBack(nPort,pBuf,nSize,&mFrameInfo, nChanID);
	}

	delete[] pBuf;
	pBuf = NULL;
}

void CALLBACK DHPlayHandle::DecCBFunc( DWORD nPort,void *user )
{
    DHPlayHandle * phand = (DHPlayHandle *) user;
}

bool DHPlayHandle::initialPlayerEx( PINITPY_PARAM pIParam )
{
    if (NULL == pIParam)
    {
        return false;
    }
    return initialPlayer(pIParam->nPort , pIParam->nDecodeType , pIParam->buff , pIParam->nSize , pIParam->nType);
}

bool DHPlayHandle::startPlayer4StandardEx( PSTARTPYS_PARAM pParam )
{
    if (NULL == pParam)
    {
        return false;
    }
    return startPlayer4Standard(pParam->hWnd , pParam->lpDecCBFun , pParam->nCameraID);
}

bool DHPlayHandle::locPlay_OpenFileEx( PLOCPY_OPENF_PARAM_PARAM pParam )
{
	char szLog[256] = {0};
	sprintf_s(szLog,"%s,%d",__FUNCTION__,__LINE__);
	m_log.LogInfoEx(LOG_INFO,"%s",szLog);
    if (NULL == pParam)
    {
        return false;
    }
	
	bool bRe;
	long lPort = -1;
	bRe = PLAY_GetFreePort((LONG *)&lPort);
	m_log.LogInfoEx(LOG_INFO,"%s,%d",szLog,lPort);
	if(bRe == false)
		return false;
	pParam->nPort = lPort;
	bRe =  locPlay_OpenFile(pParam->nPort , pParam->nDecodeType , pParam->hWnd , pParam->fileName);
	//bRe = locPlay_Control(LOCPLAY_CTRL_PLAYSETPOS,10,(int*)&lPort);
	return bRe;
}


bool DHPlayHandle::SetCropArea( bool bFlag, int x1, int y1, int x2, int y2)
{
	BOOL bRet = FALSE;
	DISPLAYRECT rct;
	rct.left = x1;
	rct.top  = y1;
	rct.right = x2;
	rct.bottom = y2;
	bRet = PLAY_SetDisplayRegion(m_nLocPlayPort,0,&rct,NULL,bFlag);
	if(bRet == FALSE)
	{
		return false;
	}	
	return true;
}
//��Ƶ�������ܵ���
// Parameter: nCmd: ���ܵ��ڵ�����, 1Ϊȥ��, 2Ϊ��ɫ, 3Ϊ��, 4Ϊ���ȵ���
//			  bFlag: trueΪִ�����ܵ���, falseΪȡ��
//			  x1, y1: ȥ��ʱ��ʾ��ʼ������, �߶ȵ���ʱΪ����
//			  x2, y2: ���ȵ��ڱ�ʾ�ս������.

bool DHPlayHandle::SetDecodeParam( int nCmd, bool bFlag, int x1, int y1, int x2, int y2)
{
	BOOL bRet = FALSE;
	int nModuleType = 0;
	//PLAY_VIE_PARACONFIG param = {0};
	switch (nCmd)
	{
	case 1://ȥ��
		{
			//nModuleType = PLAY_VIE_MODU_DEHAZE;
			//bRet = PLAY_VIE_SetModuConfig(m_nPlayerPort,bFlag,nModuleType);
			//if(bRet == TRUE)
			//{
			//	bRet = PLAY_VIE_GetParaConfig(m_nPlayerPort,&param);
			//}
			//if(bRet == TRUE)
			//{
			//	bRet = PLAY_VIE_SetParaConfig(m_nPlayerPort,&param);
			//}
			//if(bRet == FALSE)
			//{
			//	return false;
			//}	
			break;
		}
	case 2://��ɫ
		{
			return false;
			break;
		}
	case 3://��
		{	
			//nModuleType = PLAY_VIE_MODU_SHARPEN;
			//bRet = PLAY_VIE_SetModuConfig(m_nPlayerPort,bFlag,nModuleType);
			//if(bRet == TRUE)
			//{
			//	bRet = PLAY_VIE_GetParaConfig(m_nPlayerPort,&param);
			//}
			//if(bRet == TRUE)
			//{
			//	bRet = PLAY_VIE_SetParaConfig(m_nPlayerPort,&param);
			//}
			//if(bRet == FALSE)
			//{
			//	return false;
			//}	
			break;
		}
	case 4://���ȵ���
		{
			int nBrightlevel = 0;
			bRet = PLAY_GetColor(m_nLocPlayPort,NULL,&nBrightlevel,&y1,&x2,&y2); 
			if(bRet == TRUE)
			{
				bRet = PLAY_SetColor(m_nLocPlayPort,NULL,x1,y1,x2,y2); 
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

bool DHPlayHandle::SetYUVCallBack( LPYUVCALLBACK pCallBack)
{
	return true;
}
bool DHPlayHandle::SetStreamSaveTime( int nSaveTime)
{
	return true;
}
bool DHPlayHandle::PlayBackSaveStream( HWND hWnd)
{
	return true;
}
bool DHPlayHandle::StopPlayBackSaveStream( )
{
	return true;
}

//2013 0927 pzm add
bool DHPlayHandle::SetRenderMode( int nMode)
{
	return false;
}

bool DHPlayHandle::SetPosByFrameNum(DWORD nFrameNum)
{
	FRAME_POS pos;
	BOOL bRet =  PLAY_GetKeyFramePos(m_nLocPlayPort,nFrameNum,BY_FRAMENUM,&pos);
	if(bRet == FALSE)
		return false;

	int nKeyFrame = pos.nFrameNum;
	bRet =  PLAY_SetCurrentFrameNum(m_nLocPlayPort,nKeyFrame);
	if(bRet == FALSE)
		return false;

	return true;
}

void CALLBACK ZCutProgressFunc(DWORD nPort, int iProgress, DWORD dwUser)
{

}

bool DHPlayHandle::GetVideoCut( DWORD beginFrame, DWORD endFrame, LPSTR filename)
{
	if(beginFrame > endFrame)
		return false;

/*	LONG lBeginTime;
	LONG lEndTime;
	BOOL bRet = FALSE; 

	FRAME_POS pos;
	bRet = PLAY_GetKeyFramePos(m_nLocPlayPort,beginFrame,BY_FRAMETIME,&pos);
	if(bRet == FALSE)
	{
		DWORD err = PLAY_GetLastError(m_nLocPlayPort);
		return false;
	}	
	lBeginTime = pos.nFrameTime;

	bRet = PLAY_GetNextKeyFramePos(m_nLocPlayPort,endFrame,BY_FRAMETIME,&pos);
	if(bRet == FALSE)
	{
		DWORD err = PLAY_GetLastError(m_nLocPlayPort);
		return false;
	}	
	lEndTime = pos.nFrameTime;

	bRet = PLAY_CutFileSegment(m_nLocPlayPort,8000,30000,ZCutProgressFunc,filename,(DWORD)this);
	if(bRet == FALSE)
	{
		DWORD err = PLAY_GetLastError(m_nPlayerPort);
		return false;
	}*/		

	DWORD dwStartFrame = 0; 
	DWORD dwEndFrame = 0; 
	string strSaveFileName;
	FRAME_POS	strRealBegin;
	FRAME_POS	strRealEnd;
	int		    nPort = m_nLocPlayPort;
	int			nType = BY_FRAMENUM;
	HANDLE		hPlayFile = m_hStreamFile;

	dwStartFrame = beginFrame;
	dwEndFrame	 = endFrame;
	strSaveFileName = filename;
	{
		DWORD		nMaxFrameNum;
		DWORD		nMaxTime;
		nMaxTime     = PLAY_GetFileTime(nPort);
		nMaxFrameNum = PLAY_GetFileTotalFrames(nPort);

		memset(&strRealBegin,0,sizeof(FRAME_POS));
		memset(&strRealEnd,0,sizeof(FRAME_POS));

		BOOL bRet=PLAY_GetKeyFramePos(nPort, dwStartFrame, nType, &strRealBegin);
		int nError = PLAY_GetLastError(nPort);

		if(!PLAY_GetNextKeyFramePos(nPort, dwEndFrame, nType, &strRealEnd))
		{
			int ret = PLAY_GetLastError(nPort);
			strRealEnd.nFilePos   = SetFilePointer(hPlayFile, 0, 0, FILE_END);
			strRealEnd.nFrameNum  = nMaxFrameNum;
			strRealEnd.nFrameTime = nMaxTime*1000;
		}

		int nNewFileLen = int(strRealEnd.nFilePos - strRealBegin.nFilePos);
		HANDLE hNewFile = INVALID_HANDLE_VALUE;
		DWORD nSize = 2048;		//Per 2k data;
		PBYTE pBuf  = NULL;
		//DWORD nFileHeadLen = PLAY_GetFileHeadLength();
		DWORD nFileHeadLen = 0;
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

bool DHPlayHandle::StopCutVideo()
{
	return false;
}

struct DHPlayHandleS
{
	DHPlayHandle *pHandle;
	void *pUser;
};

void DHPlayHandle::pDHFileOverCB(DWORD nPort, void *pUser)
{
	DHPlayHandleS *pInfo = (DHPlayHandleS *)pUser;
	if(pInfo != NULL)
	{
		pInfo->pHandle->m_pFileOverCB(pInfo->pUser);
	}
	//delete pInfo;
}

bool DHPlayHandle::SetFileEndCallback( void *pUser,pFileOverCB pCallBack)
{
	DHPlayHandleS *pInfo = new DHPlayHandleS;
	m_pFileOverCB = pCallBack;
	pInfo->pUser   = pUser;
	pInfo->pHandle = this;
	BOOL bRet =  PLAY_SetFileEndCallBack(m_nLocPlayPort,pDHFileOverCB,(void*)pInfo);
	if(bRet == FALSE)
		return false;

	return true;
}

bool DHPlayHandle::GetMediaInfo(MediaInf &mInf)
{
	return false;
}

bool DHPlayHandle::GetDecodeParam( int nCmd, int &x1, int &y1, int &x2, int &y2)
{
	BOOL bRet = FALSE;
	int nModuleType = 0;
	switch (nCmd)
	{
	case 1://ȥ��
		{
			//bRet = PLAY_VIE_GetModuConfig(m_nLocPlayPort,&nModuleType);
			//if(bRet == FALSE || nModuleType != PLAY_VIE_MODU_DEHAZE)
			//{
			//	return false;
			//}	
			return false;
			break;
		}
	case 2://��ɫ
		{
			return false;
			break;
		}
	case 3://��
		{	
/*			bRet = PLAY_VIE_GetModuConfig(m_nLocPlayPort,&nModuleType);
			if(bRet == FALSE || nModuleType != PLAY_VIE_MODU_DEHAZE)
			{
				return false;
			}*/	
			return false;
			break;
		}
	case 4://���ȵ���
		{
			bRet = PLAY_GetColor(m_nLocPlayPort,NULL,&x1,&y1,&x2,&y2); 			
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

int  DHPlayHandle::AllpurposeI(int nCmd,char *pInPutPara,char *pOutPutPara)
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

