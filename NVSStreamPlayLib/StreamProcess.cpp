#include "StdAfx.h"
#include "StreamProcess.h"
#include "StreamSource.h"
#include "PaperForm.h"

#define  MAXTIME   15
extern CStreamSourceAgent g_Agent;

#include "NVSCoreBiz.h"
extern NVSCoreBiz GL_CoreBiz;
static int m_nUsedPort = 0;

CStreamProcess::CStreamProcess(int nCameraID,string sCameraID,CSourceSvrInfomation *pInfomation)
{
	m_nCameraID		= nCameraID;
	m_sCameraID		= sCameraID;
	m_pInfomation	= pInfomation;
	m_bWaitHeadData	= false;
	m_bUseDecodeMode = false;
	::InitializeCriticalSection(&m_Lock_WPPH);
	m_hWaitHead = CreateEvent(NULL,TRUE,FALSE,NULL);
	SetUsedTimeStamp();
	m_bIsExternalDvr	= false;
	m_sChanStrIndex = "";
	m_sOpenType		= "";
	m_sDeCodeType   = "";
}

CStreamProcess::~CStreamProcess(void)
{
	::DeleteCriticalSection(&m_Lock_WPPH);
	CloseHandle(m_hWaitHead);
}


int  CStreamProcess::SetUsedTimeStamp()
{
	m_timeU = IceUtil::Time::now();
	return XY_TRUE;
}

int  CStreamProcess::CheckUsedTimeStamp()
{
	//检查时间戳
	IceUtil::Time now_check = IceUtil::Time::now();
	__int64 nNowSeconds = now_check.toSeconds();
	__int64 nUSeconds = m_timeU.toSeconds();
	__int64 nSeconds  = nNowSeconds -  nUSeconds;
	if(nSeconds > MAXTIME)
	{
		return XY_TRUE;
	}
	return XY_FALSE;
}
int  CStreamProcess::CheckCameraID(int nCameraID,string sCameraID)
{
	if(m_nCameraID >= 0 && m_nCameraID == nCameraID)
	{
		return XY_TRUE;//数字镜头编号匹配
	}	

	if(m_sCameraID != "" && m_sCameraID == sCameraID)
	{
		return 1;//字符镜头编号匹配
	}

	return XY_FALSE;
}


void CStreamProcess::SetStreamHeadData(const StreamPiece &pContent)
{
	::EnterCriticalSection(&m_Lock_WPPH);
	m_vHead.Data.clear();
	m_vHead.Data.resize(pContent.Data.size());
	std::copy(pContent.Data.begin(),pContent.Data.end(),m_vHead.Data.begin());
	SetEvent(m_hWaitHead);
	::LeaveCriticalSection(&m_Lock_WPPH);
}

int CStreamProcess::getCameraID()
{
	return m_nCameraID;
}

int CStreamProcess::updateCameraID(int nCameraID)
{
	if(nCameraID > 0)
	{
		GL_CoreBiz.WriteSysLog("CStreamProcess::updateCameraID BEGIN	");
		int nPriorID,nSwitchID;
		nPriorID  = m_nCameraID;
		nSwitchID = nCameraID;
		CPaperForm::UpdateCameraID(nPriorID,nSwitchID,"");
		m_nCameraID = nCameraID;
		GL_CoreBiz.WriteSysLog("CStreamProcess::updateCameraID END	");
	}
	return nCameraID;
}

int  CStreamProcess::SetErrorManageInfo(HWND hWnd)
{
	if (hWnd == NULL)
	{
		return 0;
	}
	if(NULL != GL_CoreBiz.m_pErrorManage)
	{
		GL_CoreBiz.m_pErrorManage->m_hWnd = hWnd;
		GL_CoreBiz.m_pErrorManage->m_nCameraID  = m_nCameraID;
		GL_CoreBiz.m_pErrorManage->m_nCardIndex = -1;
		GL_CoreBiz.m_pErrorManage->m_nCheckTime = 100;
	}
	return 0;
}
int  CStreamProcess::RequestVideoICE(ServerInfo svrInfo,::NVSStreamService::DeviceInfo devinfo,::NVSIndex::NVSDVRInfo dvrInfo,HWND hWnd, 
									 RealPlayCallBack pRealFun,bool bUseDecode, LPDecCBFun pDecFun, bool bIsExternalDvr)
{
	GL_CoreBiz.WriteSysLog("CStreamProcess::请求视频播放,开始进行...RequestVideoICE。");
	int nRet = XY_TRUE;	
	::EnterCriticalSection(&m_Lock_WPPH);
	nRet = checkContainWnd(hWnd);
	if(XY_TRUE == nRet)
	{
		::LeaveCriticalSection(&m_Lock_WPPH);
		return XY_REQ_USED_WINDOW;	
	}
	
	WINPORTPLAYHANDLE playHandle;
	playHandle.Wnd = hWnd;
	playHandle.nCameraID = m_nCameraID;
	playHandle.PlayHandle = NULL;
	m_vWPPH.push_back(playHandle);
	::LeaveCriticalSection(&m_Lock_WPPH);

	//20121220 获取额外的信息 字符通道信息 解码类型 编码类型
	vector<::NVSIndex::NVSCameraInfo>::iterator it = dvrInfo.CameraPool.begin();
	for(;it != dvrInfo.CameraPool.end();++it)
	{
		if((*it).CameraID == m_nCameraID)
		{
			m_sChanStrIndex = (*it).ChannelStrID;
			m_sOpenType		= (*it).sOpenType;
			m_sDeCodeType   = (*it).sDecodeType;
			break;
		}
	}

	m_pRealPlayCallBack  = pRealFun;
	m_sDllKey  = devinfo.sType;
	m_bUseDecodeMode = bUseDecode;
	m_pStandardCallBack = pDecFun;

	nRet = CaptureStream(svrInfo,devinfo,bIsExternalDvr);
	if(nRet >= 2 && nRet < 20)
	{
		GL_CoreBiz.WriteSysLog("请求视频流播放,已完成...直接解码。");
		nRet = SoftSolution(hWnd);
	}
	return nRet;
}

int  CStreamProcess::CaptureStream(ServerInfo svrInfo,::NVSStreamService::DeviceInfo devinfo, bool bIsExternalDvr)
{
	GL_CoreBiz.WriteSysLog(__FUNCTION__);
	char szLogInfo[256] = {0};

	if(m_bWaitHeadData && m_vHead.Data.size() == 0) //请求视频成功，但还未收到头数据，等待头数据标识
	{
		if(WAIT_TIMEOUT == WaitForSingleObject(m_hWaitHead,0))
		{
			sprintf_s(szLogInfo, "正在等待头数据, 错误码[209]");
			GL_CoreBiz.WriteSysLog(szLogInfo);
			return XY_REQ_NOT_RECEIVE_DATA; //-9 请求视频成功但未收到头数据
		}
	}

	int nPlayCnt = getCameraPlayCount();
	if(nPlayCnt > 1 && m_bWaitHeadData)
	{
		GL_CoreBiz.WriteSysLog("流请求已经成功,无需请求，只需直接播放即可!");
		return nPlayCnt;
	}

	m_SvrInfo = svrInfo;
	m_bIsExternalDvr = bIsExternalDvr;
	m_devinfo		 = devinfo;
	XY_BOOL  bRet = XY_TRUE;
	bRet = DoCaptureStream(m_SvrInfo,m_devinfo,m_bIsExternalDvr);
	return bRet;
}

int  CStreamProcess::DoCaptureStream(ServerInfo svrInfo,::NVSStreamService::DeviceInfo devinfo, bool bIsExternalDvr)
{
	GL_CoreBiz.WriteSysLog(__FUNCTION__);
	XY_BOOL  bRet = XY_TRUE;
	char szLogInfo[256] = {0};
	if(m_vHead.Data.size() == 0)
	{
		try
		{
			m_pDataReceiver = NULL;
			m_pDataReceiver = new NVSStreamDataReceiverExI(this);

			m_NVSSreamServiceAPIAdapter = g_Agent.GetAdapter(svrInfo);
			m_DataReceiverIdentity.name = IceUtil::generateUUID();
			m_DataReceiverIdentity.category = "";
			m_NVSSreamServiceAPIAdapter->add(m_pDataReceiver,m_DataReceiverIdentity);

			NVSStreamServiceAPIPrx Agentproxy =  g_Agent.GetPrx(svrInfo);
			Agentproxy->ice_getConnection()->setAdapter(m_NVSSreamServiceAPIAdapter);
		}
		catch(Ice::Exception &ex)
		{
			string strerr = ex.ice_name();
			sprintf_s(szLogInfo,"流媒体反向适配器添加数据接收类失败 : %s.",strerr.c_str());
			GL_CoreBiz.WriteSysLog(szLogInfo);
			bRet = XY_FALSE;
			return bRet;
		}

		bRet = g_Agent.startPlayer(svrInfo,devinfo,m_DataReceiverIdentity,m_sKey);
		sprintf_s(szLogInfo, "CStreamProcess::向流媒体请求播放返回结果[%d]",bRet);
		GL_CoreBiz.WriteSysLog(szLogInfo);
		if(bRet == XY_TRUE)
		{
			m_bWaitHeadData = true;	
		}	
	}
	return bRet;
}

int  CStreamProcess::StopCaptureStream()
{
	GL_CoreBiz.WriteSysLog(__FUNCTION__);
	XY_BOOL nRet = XY_FALSE;
	int nPlayCnt = getCameraPlayCount();
	if(nPlayCnt == 0 && CheckCameraID(m_nCameraID,m_sCameraID) != XY_FALSE)
	{
		GL_CoreBiz.WriteSysLog(__FUNCTION__);
		::EnterCriticalSection(&m_Lock_WPPH);
		ResetEvent(m_hWaitHead);
		m_vHead.Data.clear();
		::LeaveCriticalSection(&m_Lock_WPPH);
		
		if(m_bWaitHeadData == true)
			nRet = g_Agent.stopVideo(m_SvrInfo,m_sKey);
		m_bWaitHeadData = false;
		{
			m_pDataReceiver = NULL;
			g_Agent.CleanAdapterIdentity(m_SvrInfo,m_DataReceiverIdentity);
		}
		try
		{
			if (GL_CoreBiz.m_NVSIndex4MonitorPrx)
			{
				GL_CoreBiz.m_NVSIndex4MonitorPrx->NoticeReleaseUser(GL_CoreBiz.m_Monitor.ID, m_nCameraID);
			}
		}
		catch (...)
		{
		}

		SetUsedTimeStamp();
		m_nCameraID = -1;
		m_sCameraID = "";	
	}	
	GL_CoreBiz.WriteSysLog("StopCaptureStream  end");
	return nRet;
}

int  CStreamProcess::ReconnectCaptureStream()
{
	GL_CoreBiz.WriteSysLog(__FUNCTION__);
	XY_BOOL nRet = XY_FALSE;
	::EnterCriticalSection(&m_Lock_WPPH);
	int nPlayCnt = getCameraPlayCount();
	if(nPlayCnt > 0)
	{	
		vector<WINPORTPLAYHANDLE>::iterator itFind = m_vWPPH.begin();
		for(;itFind!=m_vWPPH.end();)
		{
			//在有解码返回的时候，才能调用停止解码
			if ((*itFind).PlayHandle > 0)
			{
				stopPlayer((*itFind).PlayHandle);
			}
			(*itFind).PlayHandle = NULL;	
			GL_CoreBiz.c_releasePlayPort((*itFind).Port); //释放所占用的播放通道
			*itFind++;
		}	

		m_pDataReceiver = NULL;
		g_Agent.CleanAdapterIdentity(m_SvrInfo,m_DataReceiverIdentity);
		m_bWaitHeadData = false;
		ResetEvent(m_hWaitHead);
		m_vHead.Data.clear();
		::LeaveCriticalSection(&m_Lock_WPPH);

		nRet = DoCaptureStream(m_SvrInfo,m_devinfo,m_bIsExternalDvr);	
	}	
	else
	{
		::LeaveCriticalSection(&m_Lock_WPPH);
	}
	GL_CoreBiz.WriteSysLog("ReconnectCaptureStream end");
	return nRet;
}
int  CStreamProcess::SoftSolution(HWND hWnd)
{
	GL_CoreBiz.WriteSysLog(__FUNCTION__);
	if (hWnd == NULL && m_pStandardCallBack == NULL)
	{
		if(m_pRealPlayCallBack)
			m_pRealPlayCallBack(m_nCameraID, XY_PLAY_SUCCESS); //0 回调播放结果_播放成功

		return XY_REQ_PLAY_SUCCESS; //1  传入的镜头已存在播放对象，直接调用Plugin播放成功
	}
	m_nUsedPort = GL_CoreBiz.c_getPlayPort();
	if(m_nUsedPort == -1)
	{
		if(m_pRealPlayCallBack)
			m_pRealPlayCallBack(m_nCameraID, XY_PLAY_FAIL_GET_PORT); //-10 获取播放端口失败

		GL_CoreBiz.WriteSysLog("获取播放端口失败，错误码[307]");
		SetErrorManageInfo(hWnd);
		return XY_PLAY_FAIL_GET_PORT; //-10 获取播放端口失败
	}
	int nVideoPort = m_nUsedPort;

	if(m_vHead.Data.size() <= 0) //如果头数据为空 则退出
	{
		if(m_pRealPlayCallBack)
			m_pRealPlayCallBack(m_nCameraID, XY_PLAY_NULL_HEADDATA);  //-11 头数据为空

		GL_CoreBiz.WriteSysLog("头数据,播放结构体容量等于0，错误码[310]");
		SetErrorManageInfo(hWnd);
		return XY_PLAY_NULL_HEADDATA; //-11 头数据为空
	}

    /*BYTE pHead[40] = {0x34, 0x48, 0x4B, 0X48, 0XFE, 0XB3, 0XD0, 0XD6,
        0X08, 0X03, 0X04, 0X20, 0X00, 0X00, 0X00, 0X00,
        0x03, 0x10, 0x01, 0x10, 0x01, 0x10, 0x10, 0x00,
        0x80, 0x3E, 0x00, 0x00, 0xC0, 0x02, 0x40, 0x02,
        0x11, 0x10, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00};

        BYTE pHead[40] = 
        {0x49, 0x4D, 0x4B, 0X48, 0X01, 0X01, 0X00, 0X00,
        0X02, 0X00, 0X00, 0X01, 0X10, 0X71, 0X01, 0X10,
        0x40, 0x1F, 0x00, 0x00, 0x00, 0xFA, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

    long lPlayerHandle = initialPlayer(const_cast<char*>(m_sDeCodeType.c_str()), nVideoPort, 0,
        (unsigned char*)pHead, 40,0);*/
    intptr_t lPlayerHandle = initialPlayer(const_cast<char*>(m_sDeCodeType.c_str()), nVideoPort, 0, (unsigned char*)&m_vHead.Data[0], (int)m_vHead.Data.size(),0);

	if (lPlayerHandle > 0)
	{
		//收到头数据后更新数据
		XY_BOOL nRet = UpdatePlayInfo(hWnd,lPlayerHandle,nVideoPort);
		if(XY_FALSE == nRet)
		{		
			try
			{
				stopPlayer(lPlayerHandle);
			}
			catch(...)
			{

			}
			return XY_REQ_PLAY_SUCCESS; //1  传入的镜头已存在播放对象，直接调用Plugin播放成功
		}

		bool bPlayResult = false;
		if(!m_bUseDecodeMode) //正常视频播放
		{
			if (m_pStandardCallBack)
			{
				startPlayer4Standard(lPlayerHandle, hWnd, m_pStandardCallBack, m_nCameraID);
			}
			if (GL_CoreBiz.m_pDrawCB)
			{
				bPlayResult = startPlayer2(lPlayerHandle, hWnd,DrawFunCallBack, this);
			}
			else
			{
				bPlayResult = startPlayer(lPlayerHandle, hWnd);
			}
		}
		else 
		{
			bPlayResult = startPlayer4Standard(lPlayerHandle, NULL, m_pStandardCallBack, m_nCameraID);
			bPlayResult = startPlayer(lPlayerHandle, NULL);
		}

		if (bPlayResult/*软解播放结果*/)
		{
			if (m_pDataReceiver == NULL)	//2011-7-27 增加判断 Add By sjy
			{
				char str[255] = {0};
				sprintf_s(str,sizeof(str), "镜头[%d]接收器为NULL时设置数据体接收对象失败!", m_nCameraID);
				GL_CoreBiz.WriteSysLog(str);

				if(m_pRealPlayCallBack)
					m_pRealPlayCallBack(m_nCameraID, XY_PLAY_FAIL_SETBODYCALLBACK);		//-24 回调通知主程序异常
				
				return XY_PLAY_FAIL_SETBODYCALLBACK;	//-24 接收器为NULL时设置数据体接收对象失败
			}
			if(m_pRealPlayCallBack)
				m_pRealPlayCallBack(m_nCameraID, XY_PLAY_SUCCESS); //0 回调播放结果_播放成功		
			
			GL_CoreBiz.WriteSysLog("调用播放库播放成功(startPlayer)");
			return XY_REQ_PLAY_SUCCESS; //1  传入的镜头已存在播放对象，直接调用Plugin播放成功
		}
		else
		{
			if(m_pRealPlayCallBack)
				m_pRealPlayCallBack(m_nCameraID, XY_PLAY_FAIL_PLUGIN_PLAY); //-13 调用PlugIn播放视频失败

			SetErrorManageInfo(hWnd);
			GL_CoreBiz.WriteSysLog("调用播放库播放失败(startPlayer)，错误码[316]");
		}
		return XY_PLAY_FAIL_PLUGIN_PLAY; //-13 调用PlugIn播放视频失败
	}
	else
	{
		if(m_pRealPlayCallBack)
			m_pRealPlayCallBack(m_nCameraID, XY_PLAY_FAIL_PLUGIN_INIT); //-12 初始化PlugIn失败

		SetErrorManageInfo(hWnd);
		GL_CoreBiz.WriteSysLog("初始化PlugIn失败(InitPlayer)，错误码[315]");
		return XY_PLAY_FAIL_PLUGIN_INIT; //-12 初始化PlugIn失败
	}
}

int  CStreamProcess::StopSoftSolution(HWND hWnd, int nCameraID)
{
	GL_CoreBiz.WriteSysLog(__FUNCTION__);
	int nRet = XY_FALSE;
	::EnterCriticalSection(&m_Lock_WPPH);
	vector<WINPORTPLAYHANDLE>::iterator itFind = m_vWPPH.begin();
	for(;itFind!=m_vWPPH.end();++itFind)
	{
		if (hWnd == NULL)
		{
			if ((*itFind).nCameraID == nCameraID)
			{
				break;
			}
		}
		else
		{
			if((*itFind).Wnd == hWnd)
			{
				break;
			}
		}
	}
	if(itFind!=m_vWPPH.end())
	{
		GL_CoreBiz.removeCameraInfo(m_nCameraID,(*itFind).Wnd);
		CPaperForm::EraseParam(m_nCameraID,m_sCameraID,(*itFind).Wnd);
		GL_CoreBiz.c_releasePlayPort((*itFind).Port); //释放所占用的播放通道
		//在有解码返回的时候，才能调用停止解码
		intptr_t PlayHandle = (*itFind).PlayHandle;
		m_vWPPH.erase(itFind);	
		if (PlayHandle > 0)
		{
			try
			{
				stopPlayer(PlayHandle);
			}
			catch(...)
			{

			}			
		}	
		nRet = XY_TRUE;
	}
	::LeaveCriticalSection(&m_Lock_WPPH);
	GL_CoreBiz.WriteSysLog("StopSoftSolution end");
	return nRet;
}

int  CStreamProcess::StopAllSoftSolution()
{
	::EnterCriticalSection(&m_Lock_WPPH);
	vector<WINPORTPLAYHANDLE>::iterator itFind = m_vWPPH.begin();
	for(;itFind!=m_vWPPH.end();)
	{
		//在有解码返回的时候，才能调用停止解码
		if ((*itFind).PlayHandle > 0)
		{
			stopPlayer((*itFind).PlayHandle);
		}
		GL_CoreBiz.removeCameraInfo(m_nCameraID,(*itFind).Wnd);
		CPaperForm::EraseParam(m_nCameraID,m_sCameraID,(*itFind).Wnd);
		GL_CoreBiz.c_releasePlayPort((*itFind).Port); //释放所占用的播放通道
		itFind = m_vWPPH.erase(itFind);
	}
	::LeaveCriticalSection(&m_Lock_WPPH);
	return XY_TRUE;
}


//! 抓图
bool CStreamProcess::CapturePicture(char* pFileName)
{
	bool bRet = false;

	::EnterCriticalSection(&m_Lock_WPPH);
	vector<WINPORTPLAYHANDLE>::iterator it = m_vWPPH.begin();
	if (it==m_vWPPH.end())
	{
		::LeaveCriticalSection(&m_Lock_WPPH);
		return false;
	}
	bRet = capturePictureEx((*it).PlayHandle,pFileName);
	::LeaveCriticalSection(&m_Lock_WPPH);

	return bRet;
}


int  CStreamProcess::initHead(const StreamPiece& sd)
{
	::EnterCriticalSection(&m_Lock_WPPH);
	GL_CoreBiz.WriteSysLog("initHead begin !");
	SetStreamHeadData(sd);
	vector<WINPORTPLAYHANDLE>::iterator itFind = m_vWPPH.begin();
	for(;itFind!=m_vWPPH.end();++itFind)
	{
		if((*itFind).PlayHandle > 0)
			stopPlayer((*itFind).PlayHandle);
		SoftSolution(itFind->Wnd);
	}
	if(GL_CoreBiz.m_pVedioHeadStreamCB)
		GL_CoreBiz.m_pVedioHeadStreamCB((BYTE *)&sd.Data[0],(int)sd.Data.size(), m_nCameraID);
	::LeaveCriticalSection(&m_Lock_WPPH);
	return 0;
}

int  CStreamProcess::inputData(const StreamPiece& sd)
{
	::EnterCriticalSection(&m_Lock_WPPH);
	SetUsedTimeStamp();
	vector<WINPORTPLAYHANDLE>::iterator it = m_vWPPH.begin();
	for(;it!=m_vWPPH.end();++it)
	{
		if ((*it).PlayHandle > 0)// 取消判断 && (*it).Wnd != NULL
		{
			addData((*it).PlayHandle, (BYTE *)&sd.Data[0],(int)sd.Data.size());
		}
		if(m_vHead.Data.size() > 0)
			GL_CoreBiz.heartBeat4Chan(m_nCameraID,(*it).Wnd); /* <心跳>更新镜头时间戳备StampCheck线程*/
	}
	if(m_vWPPH.size() > 0)
	{
		it = m_vWPPH.begin();

		if((*it).nRecordState == 3) //准备停止录像
		{
			if((*it).hFileHandle != NULL)
			{
				CloseHandle((*it).hFileHandle);
			}
			(*it).nRecordState = 0; (*it).hFileHandle = NULL; (*it).pFileName = NULL;
		}
		else if((*it).nRecordState == 1 || (*it).nRecordState == 2)
		{
			if((*it).nRecordState == 1)
				(*it).nRecordState = 2;
			DWORD nWritten;
			::WriteFile((*it).hFileHandle, (BYTE *)&sd.Data[0], (DWORD)sd.Data.size(), &nWritten, NULL);	
		}
	}
	if(GL_CoreBiz.m_pVedioBodyStreamCB && m_vHead.Data.size() > 0)
	{
		GL_CoreBiz.m_pVedioBodyStreamCB((BYTE *)&sd.Data[0],(int)sd.Data.size(), m_nCameraID);
	}
	::LeaveCriticalSection(&m_Lock_WPPH);

	return 0;
}
void  CStreamProcess::DrawFunCallBack(intptr_t  identify, intptr_t lRealHandle, DWORD hdc, void *pUser)
{
	if(!pUser) return ;
	CStreamProcess *pVideoProcess = (CStreamProcess *)(pUser);

	if (GL_CoreBiz.m_pDrawCB)
	{
		GL_CoreBiz.m_pDrawCB( lRealHandle,hdc,pVideoProcess->getCameraID());
	}

}
int CStreamProcess::checkContainWnd(HWND hWnd)
{
	if (hWnd == NULL)
	{
		return XY_FALSE;
	}
	int nHas = XY_FALSE;
	::EnterCriticalSection(&m_Lock_WPPH);
	vector<WINPORTPLAYHANDLE>::iterator it = m_vWPPH.begin();
	for(;it!=m_vWPPH.end();++it)
	{
		if((*it).Wnd == hWnd)
		{
			nHas = XY_TRUE;
			break;
		}
	}
	::LeaveCriticalSection(&m_Lock_WPPH);
	return nHas;
}

int CStreamProcess::getCameraPlayCount()
{
	int nSize = 0;

	::EnterCriticalSection(&m_Lock_WPPH);
	nSize = (int)m_vWPPH.size();
	::LeaveCriticalSection(&m_Lock_WPPH);

	return nSize;
}
int CStreamProcess::UpdatePlayInfo(HWND hKeyWnd, intptr_t PlayHandle,int  Port)
{
	XY_BOOL nRet = XY_FALSE;
	::EnterCriticalSection(&m_Lock_WPPH);
	vector<WINPORTPLAYHANDLE>::iterator it = m_vWPPH.begin();
	for (;it!=m_vWPPH.end();it++)
	{
		if ((*it).Wnd == hKeyWnd)
		{
			break;
		}
	}
	if (it!=m_vWPPH.end() && (*it).PlayHandle != PlayHandle)
	{
		(*it).PlayHandle = PlayHandle;
		(*it).Port = Port;
		nRet = XY_TRUE;
	}
	::LeaveCriticalSection(&m_Lock_WPPH);
	return nRet;
}

//! 开始本地录像
int  CStreamProcess::startRecord(char* pFileName)
{
	int nRe = -5;
	char str[256]={0};

	::EnterCriticalSection(&m_Lock_WPPH);
	vector<WINPORTPLAYHANDLE>::iterator it = m_vWPPH.begin();
	for(;it != m_vWPPH.end();++it)
	{
		if(((*it).pFileName == pFileName) || (GL_CoreBiz.m_nSysPlayModel == 0))
			break;
	}
	if(it!=m_vWPPH.end())
	{
		if((*it).nRecordState != 0 /* 录像状态*/)
			nRe = 1;
		else if((*it).hFileHandle == NULL)
		{
			HANDLE pFileHandle = ::CreateFile(pFileName,GENERIC_WRITE,FILE_SHARE_WRITE,NULL,CREATE_ALWAYS,FILE_ATTRIBUTE_NORMAL,NULL);
			if(pFileHandle == INVALID_HANDLE_VALUE)
			{
				CloseHandle(pFileHandle);
				sprintf_s(str, "创建存储录像文件出错 Path:%s",pFileName);
				GL_CoreBiz.WriteSysLog(str);
				::LeaveCriticalSection(&m_Lock_WPPH);
				return -6;
			}
			SetFilePointer(pFileHandle,0,0,FILE_END);
			if(m_vHead.Data.size() > 0)
			{
				DWORD nWritten;
				::WriteFile(pFileHandle,(BYTE *)&m_vHead.Data[0], (int)m_vHead.Data.size(),&nWritten,NULL);

				(*it).nRecordState = 1; /* 写头完毕,启动录像*/	
				(*it).hFileHandle = pFileHandle;
				(*it).pFileName = pFileName;
				nRe = 0;
			}
			else
			{
				nRe = -7;
			}
		}
	}
	::LeaveCriticalSection(&m_Lock_WPPH);
	return nRe;
}

//! 停止本地录像
bool CStreamProcess::stopRecord()
{
	::EnterCriticalSection(&m_Lock_WPPH);
	vector<WINPORTPLAYHANDLE>::iterator it = m_vWPPH.begin();
	for(;it != m_vWPPH.end();++it)
	{
		if((*it).hFileHandle != NULL)
		{
			if((*it).nRecordState ==2 /* 正在录像*/)
			{
				(*it).nRecordState = 3; /* 准备停止录像*/
			}
			else if((*it).nRecordState == 1)
			{
				if((*it).hFileHandle != NULL)
					CloseHandle((*it).hFileHandle);
				(*it).nRecordState = 0; (*it).hFileHandle = NULL; (*it).pFileName = NULL;
			}
		}
	}
	::LeaveCriticalSection(&m_Lock_WPPH);

	return true;
}

int  CStreamProcess::setFileHandle(char* sFileName)
{
	bool bEnter = false;
	HANDLE hNewFile = NULL;
	int nRe = -1;
	char str[256]={0};

	try
	{
		::EnterCriticalSection(&m_Lock_WPPH);
		bEnter = true;
		vector<WINPORTPLAYHANDLE>::iterator it = m_vWPPH.begin();
		for(;it != m_vWPPH.end();++it)
		{
			if((*it).hFileHandle != NULL)
			{
				hNewFile=::CreateFile(sFileName,GENERIC_WRITE,FILE_SHARE_WRITE,NULL,CREATE_ALWAYS,FILE_ATTRIBUTE_NORMAL,NULL);
				if(hNewFile == INVALID_HANDLE_VALUE)
				{
					CloseHandle(hNewFile);
					sprintf_s(str, "创建分割录像文件出错 Path:%s",sFileName);
					GL_CoreBiz.WriteSysLog(str);
					::LeaveCriticalSection(&m_Lock_WPPH);
					bEnter = false;
					return -3; //分割文件句柄无效
				}
				::SetFilePointer(hNewFile,0,0,FILE_END);
				CloseHandle((*it).hFileHandle);

			}
			if(m_vHead.Data.size() > 0)
			{
				DWORD nWritten;
				::WriteFile(hNewFile,(BYTE *)&m_vHead.Data[0], (int)m_vHead.Data.size(),&nWritten,NULL);

				(*it).nRecordState = 1; /* 写头完毕,启动录像*/	
				(*it).hFileHandle = hNewFile;
				(*it).pFileName = sFileName;
				//SetEvent(m_hPriorRecord);
				nRe = 0; 
			}
			else
			{
				nRe = -4;//录像头数据为空
			}

		}
		::LeaveCriticalSection(&m_Lock_WPPH);
		bEnter = false;
	}
	catch (...)
	{
		if (bEnter)
		{
			::LeaveCriticalSection(&m_Lock_WPPH);
		}
	}
	return nRe;
}

//! 控制摄像头视频声音
bool CStreamProcess::ControlCameraSound(bool bOpenSound)
{
	bool bRet = false;

	::EnterCriticalSection(&m_Lock_WPPH);
	vector<WINPORTPLAYHANDLE>::iterator it = m_vWPPH.begin();
	if (it!=m_vWPPH.end() && (*it).PlayHandle > 0)
	{
		bRet = controlCameraSound((*it).PlayHandle,bOpenSound);
	}
	::LeaveCriticalSection(&m_Lock_WPPH);

	return bRet;
}

bool CStreamProcess::ControlCameraSpeed(int nCameraID,int nCmd,bool bControl,int nSpeed)
{
	bool bRet = false;
	::EnterCriticalSection(&m_Lock_WPPH);
	vector<WINPORTPLAYHANDLE>::iterator it = m_vWPPH.begin();
	if (it!=m_vWPPH.end() && (*it).PlayHandle > 0)
	{
		bRet = controlPTZSpeed((*it).PlayHandle,nCmd,bControl,nSpeed);
	}
	::LeaveCriticalSection(&m_Lock_WPPH);
	return bRet;
}

void CStreamProcess::v_setPlayDrawDevice()
{
	::EnterCriticalSection(&m_Lock_WPPH);
	vector<WINPORTPLAYHANDLE>::iterator it = m_vWPPH.begin();
	if (it!=m_vWPPH.end() && (*it).PlayHandle > 0 && (*it).Wnd != NULL)
	{
		char str[256] = {0};
		sprintf_s(str, "Func[%s] Line =%d..this :[%p],m_nCameraID[%d]", __FUNCTION__,__LINE__ ,this,m_nCameraID);
		GL_CoreBiz.WriteSysLog(str);
		//reSetDDrawDevice((*it).PlayHandle,(*it).Wnd);
		ClearPlayBuffer((*it).PlayHandle);
		sprintf_s(str, "Func[%s] Line =%d..this :[%p],m_nCameraID[%d]", __FUNCTION__,__LINE__ ,this,m_nCameraID);
		GL_CoreBiz.WriteSysLog(str);
		stopPlayer((*it).PlayHandle);
		(*it).PlayHandle = NULL;
		sprintf_s(str, "Func[%s] Line =%d..this :[%p],m_nCameraID[%d]", __FUNCTION__,__LINE__ ,this,m_nCameraID);
		GL_CoreBiz.WriteSysLog(str);
		GL_CoreBiz.c_releasePlayPort((*it).Port);
		int nRet = SoftSolution((*it).Wnd);
		if(nRet != XY_REQ_PLAY_SUCCESS)
		{
			Sleep(5000);
		}
	}
	::LeaveCriticalSection(&m_Lock_WPPH);
}


int  CStreamProcess::GetKeyInfo(int nCameraID,string& sKey,ServerInfo& svrinfo)
{
	sKey = m_sKey;
	svrinfo = m_SvrInfo;
	return XY_TRUE;
}