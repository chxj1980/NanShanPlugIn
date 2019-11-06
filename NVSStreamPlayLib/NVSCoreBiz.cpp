#include "StdAfx.h"
#include <direct.h>
#include "NVSCoreBiz.h"
#include "NVSHeartThread.h"
#include "NVSErrorManage.h"
#include "NVSStampCheck.h"
#include "NVSIndexNoticeI.h"
#include "HSVideoProcess.h"
#include "LoggerFile.h"
#include "StreamSource.h"
#include "PaperForm.h"

#include <io.h>   
#include <fcntl.h>
extern unsigned short GL_VideoCount ;
extern CStreamSourceAgent g_Agent;

Ice::CommunicatorPtr NVSCoreBiz::m_Communicator = NULL;

NVSIndexNoticeIPtr   m_pDataReceiver = 0;

#ifdef _X_SIGHT //专用于XSight
const char* gpIndex4Monitorkey = "XSIndex4Monitor";
#else
const char* gpIndex4Monitorkey = "NVSIndex4Monitor";
#endif

#ifdef _X_SIGHT //专用于XSight
const char* gpIndex4Streamkey = "XSIndex4Stream";
#else
const char* gpIndex4Streamkey = "NVSIndex4Stream";
#endif

//const char* gpIndex4Monitorkey = "XSIndex4Monitor";
//const char* gpIndex4Streamkey = "XSIndex4Stream";



vector<NVSCoreBiz::CHAN_STAMP> NVSCoreBiz::m_vChanStamp;
CRITICAL_SECTION NVSCoreBiz::m_LockVectorStatic;
int NVSCoreBiz::m_nInitCs = 0;

//重新请求播放延时时间
const int GL_INTERVAL_TIME = 30;
int GL_Right = 0;

NVSCoreBiz::NVSCoreBiz(void):m_nWorkStyle(0),m_bInitEnviroment(false),m_bRegisterOnIndex(false),m_nSysPlayModel(0),m_pPlayCallBack(NULL),
m_pRealDecodeCallBack(NULL),m_nOrignID(0),m_bConnIndex(false),m_bConnStream(false)
{
	m_NVSIndex4MonitorPrx = NULL;
	m_pDrawCB = NULL;
	
	m_pHSVideoProcss = new CHSVideoProcess();

	if(!m_nInitCs++)
	{
		::InitializeCriticalSection(&NVSCoreBiz::m_LockVectorStatic);
	}   

 	for(int i=0; i<MAX_PLAYNUM;i++)
		m_vRealPlayPort.push_back(i);

#ifdef _DEBUG
	LoggerFile::CreateSysLog("StreamPlayLib","StreamPlayLibd");
#else
	LoggerFile::CreateSysLog("StreamPlayLib","StreamPlayLib");
#endif

	pDataArray = NULL;
	m_bIsExternalClient = false;

	m_pVedioHeadStreamCB = NULL;
	m_pVedioBodyStreamCB = NULL;

	m_hStopRePlay = ::CreateEvent(NULL,TRUE,FALSE,NULL);
	ResetEvent(m_hStopRePlay);

	initErrorMsg();
	::InitializeCriticalSection(&m_Lock_RealPlayPort);
	::InitializeCriticalSection(&m_Lock_StreamServicePool);
	::InitializeCriticalSection(&m_Lock_ErrorStreamPool);
	::InitializeCriticalSection(&m_Lock_CameraPool); 
	::InitializeCriticalSection(&m_LockDVRPool);

	CPaperForm::InitPaperFormS();

}

NVSCoreBiz::~NVSCoreBiz(void)
{
	m_NVSIndex4MonitorPrx = NULL;

	if (pDataArray!=NULL)
	{
		delete []pDataArray;
	}

	if( m_pHSVideoProcss!=NULL)
	{
		delete m_pHSVideoProcss;
		m_pHSVideoProcss = NULL;
	}

	if (m_hStopRePlay)
	{
		::CloseHandle(m_hStopRePlay);
	}

	c_cleanEnviroment();

	if(!--m_nInitCs)
	{
		::DeleteCriticalSection(&NVSCoreBiz::m_LockVectorStatic);
	} 

	::DeleteCriticalSection(&m_Lock_RealPlayPort);
	::DeleteCriticalSection(&m_Lock_StreamServicePool);
	::DeleteCriticalSection(&m_Lock_ErrorStreamPool);
	::DeleteCriticalSection(&m_Lock_CameraPool);
	::EnterCriticalSection(&m_Lock_RealPlayPort);
	m_vRealPlayPort.clear();
	::LeaveCriticalSection(&m_Lock_RealPlayPort);
	CPaperForm::UnInitPaperFormS();
}
int NVSCoreBiz::c_getPlayPort()
{
	EnterCriticalSection(&m_Lock_RealPlayPort);
	int nPlayPort = -1;
	vector<int>::iterator itFind = m_vRealPlayPort.begin();
	if(itFind!=m_vRealPlayPort.end() && (*itFind) != -1)
	{
		nPlayPort = (*itFind);
		m_vRealPlayPort.erase(itFind);
	}
	LeaveCriticalSection(&m_Lock_RealPlayPort);
	return nPlayPort;
}

void NVSCoreBiz::initErrorMsg()
{

	char strLog[256]={0};
	sprintf_s(strLog, "错误代码信息表路径:%s%s", m_IniFileParam.GetDirectory().c_str(), "PlayErrorMsg.ini");
	WriteSysLog(strLog);

	m_IniFileParam.SetIniFileName(m_IniFileParam.GetDirectory()+"PlayErrorMsg.ini");

	int nErrorNum=0;
	m_IniFileParam.ReadParameter("PlayStream", "ErrorNum", nErrorNum);
	for (int i=0; i<nErrorNum; i++)
	{
		ErrorMsg stutErrorMsg;

		char strEntry[256]={0};
		sprintf_s(strEntry, sizeof(strEntry), "ErrorCode%02d", i+1);
		m_IniFileParam.ReadParameter("PlayStream", strEntry, stutErrorMsg.nErrorCode);

		sprintf_s(strEntry, sizeof(strEntry), "ErrorMsg_%02d", i+1);
		m_IniFileParam.ReadParameter("PlayStream", strEntry, stutErrorMsg.sErrorMsg);

		m_vErrorMsg.push_back(stutErrorMsg);
	}

}

const char *NVSCoreBiz::c_getErrorMsg(int nErrorCode)
{
	ErrorMsgItType it = m_vErrorMsg.begin();
	for (; it!= m_vErrorMsg.end(); it++)
	{
		if ((*it).nErrorCode == nErrorCode)
		{
			WriteSysLog((char *)(*it).sErrorMsg.c_str());
			return (*it).sErrorMsg.c_str();
		}
	}
	return NULL;
}

void NVSCoreBiz::c_releasePlayPort(int nPort)
{
	if (nPort < 0  || nPort > MAX_PLAYNUM-1)
	{
		return ;
	}
	EnterCriticalSection(&m_Lock_RealPlayPort);
	vector<int>::iterator itFind = m_vRealPlayPort.begin();
	if(itFind!=m_vRealPlayPort.end() && (*itFind) == nPort)
	{
		LeaveCriticalSection(&m_Lock_RealPlayPort);
		return;
	}
	m_vRealPlayPort.push_back(nPort);
	LeaveCriticalSection(&m_Lock_RealPlayPort);
}

//查看与索引的心跳
bool NVSCoreBiz::pingIndex()
{
	bool bReturn = false;

	try
	{
		bReturn = m_NVSIndex4MonitorPrx->heartBeatRetVaule(m_Monitor.ID,GL_Right);
	}
	catch (...){}

	return bReturn;
}

//与索引、流媒体的心跳
void NVSCoreBiz::ping()
{
	int nTempID = 0; 
	try
	{
#ifdef _DEBUG	
		SYSTEMTIME timenow;
#endif
		if(m_NVSIndex4MonitorPrx)
		{
			try
			{
				if(!m_bRegisterOnIndex)
				{
					m_bConnIndex = false;
					m_nOrignID = m_Monitor.ID;
					m_bRegisterOnIndex = c_registerOnIndex();

					if(m_bRegisterOnIndex)
					{
#ifdef _DEBUG	
						GetLocalTime(&timenow);   
						printf("%4d-%02d-%02d   %02d:%02d:%02d 成功与索引服务重新连接上\r\n",
							timenow.wYear,timenow.wMonth,timenow.wDay,timenow.wHour,timenow.wMinute,timenow.wSecond);
#endif
						m_NVSIndex4MonitorPrx->UpdateClientID(c_getMonitorID(),m_nOrignID);
						WriteSysLog("成功与索引服务重新连接上");
						m_bConnIndex = true; //重连索引服务成功
					}

				}
				//使用有返回值的心跳
				if(!m_NVSIndex4MonitorPrx->heartBeatRetVaule(m_Monitor.ID,GL_Right))
				{
					m_bRegisterOnIndex = false;
				}
			}
			catch (...) 
			{
#ifdef _DEBUG
				GetLocalTime(&timenow);   
				printf("%4d-%02d-%02d   %02d:%02d:%02d 与索引服务网络断开了...\r\n",
					timenow.wYear,timenow.wMonth,timenow.wDay,timenow.wHour,timenow.wMinute,timenow.wSecond);
#endif
				WriteSysLog("与索引服务网络断开了.错误码[102]");

				if(m_pPlayCallBack)
					m_pPlayCallBack(0,XY_FAIL_DISCONNECT_INDEX); //-14 与索引服务网络断开了

				m_bRegisterOnIndex = false;
			}
			
			vector<ServerInfo> vecFailedSvr;
			g_Agent.DoAllHeartCheck(vecFailedSvr);
		}
	}
	catch (...)
	{
	}
	return;
}
bool NVSCoreBiz::c_initEnviroment(const char* pAddress,unsigned short nPort,int nRight, char type)
{
	if(m_bInitEnviroment)
		return true;
	
	memset(m_sDynamicPath,0,sizeof(m_sDynamicPath));
	sprintf_s(m_sDynamicPath,sizeof(m_sDynamicPath),"%s:tcp -h %s -p %d -t %d ",gpIndex4Monitorkey, pAddress, nPort,7000);

	sprintf_s(m_sDynamicPathStream,sizeof(m_sDynamicPathStream),"%s:tcp -h %s -p %d -t %d ",gpIndex4Streamkey, pAddress, nPort,7000);

	WriteSysLog(m_sDynamicPath);
	if(m_Communicator)
	{
		m_Communicator->destroy();
	}
	m_Communicator = NULL;

	Ice::PropertiesPtr properties = Ice::createProperties();
	properties->setProperty("Ice.Warn.AMICallback", "0");
	properties->setProperty("Ice.ACM.Client", "0");
	properties->setProperty("Ice.UseEventLog", "0");
	properties->setProperty("Ice.Logger.Timestamp", "0");
	properties->setProperty("Ice.ThreadPool.Client.Size", "50");
	properties->setProperty("Ice.ThreadPool.Server.Size","20");
	properties->setProperty("Ice.Trace.Network", "0");
	properties->setProperty("Ice.Trace.Protocol", "0");
	properties->setProperty("Ice.Warn.Connections", "0");

	Ice::InitializationData id;
	id.properties = properties;
	m_Communicator = Ice::initialize(id);

	bool bException = false;
	try
	{
		Ice::ObjectPrx base = m_Communicator->stringToProxy((string)m_sDynamicPath);
		Ice::ObjectPrx baseStream = m_Communicator->stringToProxy((string)m_sDynamicPathStream);
		if(base == NULL)
			return false;
		if(m_NVSIndex4MonitorPrx)
		{
			m_NVSIndex4MonitorPrx = 0;
		}
		// 可确保此代理，无需使用checkedCast
		m_NVSIndex4MonitorPrx = NVSIndex::NVSIndex4MonitorPrx::checkedCast(base->ice_twoway());//->ice_timeout(1000));
		//m_NVSIndex4MonitorPrx = NVSIndex::NVSIndex4MonitorPrx::uncheckedCast(base);
		m_NVSIndex4StreamPrx  = NVSIndex::NVSIndex4StreamPrx::checkedCast(baseStream->ice_twoway());//->ice_timeout(1000));
	}
	catch(Ice::Exception ex)
	{
		cerr <<ex << endl;

		bException = true;

	}
	if(bException || m_NVSIndex4MonitorPrx == NULL)
		return false;

	m_Monitor.Root = false;
	m_Monitor.Status = 0;
	m_Monitor.Right = nRight; //用户控制镜头权限
	GL_Right = nRight;
	m_Monitor.StartTime = 0;
	m_Monitor.ID = 0;
	m_Monitor.IPInline = 0;   //getLocalAddress(m_Monitor.IPInline);
	m_Monitor.IPOutline = 0;
	m_Monitor.DoorType = NVSIndex::UNKNOWN;
	m_Monitor.CurIncomingCount = 0;
	m_Monitor.CurOutgoingCount = 0;

	m_nWorkStyle = type;      //设置工作类型 0-By_ICE 1-Socket
	m_bInitEnviroment = true;
	WriteSysLog(m_sDynamicPath);

	m_pHeartThread = new NVSHeartThread();
	m_pHeartThread->m_pNVSCoreBiz = this;
	m_pHeartThread->Start();

	m_pErrorManage = new NVSErrorManage();
	m_pErrorManage->m_pNVSCoreBiz = this;
	m_pErrorManage->Start();

	m_pStampCheck = new NVSStampCheck();
	m_pStampCheck->m_pNVSCoreBiz = this;
	m_pStampCheck->Start();
	return true;
}
void NVSCoreBiz::c_cleanEnviroment()
{
	c_stopAll();
	Sleep(8);

	if (m_pHeartThread)
	{
		m_pHeartThread->m_bExit = true;
		m_pHeartThread->m_bDestroy = true;
		m_pHeartThread->End();
		delete m_pHeartThread;
		m_pHeartThread = 0;
	}

	if (m_pErrorManage)
	{
		m_pErrorManage->m_bExit = true;
		m_pErrorManage->m_bDestroy = true;
		ResetEvent(m_pErrorManage->m_hSuspend);
		m_pErrorManage->End();
		delete m_pErrorManage;
		m_pErrorManage = 0;
	}

	if (m_pStampCheck)
	{
		m_pStampCheck->m_bExit = true;
		m_pStampCheck->m_bDestroy = true;
		m_pStampCheck->End();
		delete m_pStampCheck;
		m_pStampCheck = NULL;

	}
	
	//关于屏蔽VIS
	if(m_pDataReceiver)
	{
		//delete m_pDataReceiver;
		m_pDataReceiver = 0;
	}
	m_NVSIndex4MonitorPrx = 0;

	try
	{
		m_Communicator = 0 ;
		//m_Communicator->destroy();
	}
	catch(const Ice::Exception& ex)
	{
		cerr << ex << endl;
	}
	m_Communicator = 0;
	m_bInitEnviroment = m_bRegisterOnIndex = false;

	::EnterCriticalSection(&m_Lock_CameraPool);
	m_vCameraPool.clear();
	::LeaveCriticalSection(&m_Lock_CameraPool);
	
	::EnterCriticalSection(&m_Lock_ErrorStreamPool);
	//m_vErrorStreamPool.clear();
	::LeaveCriticalSection(&m_Lock_ErrorStreamPool);

	
}

bool NVSCoreBiz::c_registerOnIndex()
{
	if(!m_bInitEnviroment || m_bRegisterOnIndex)
		return false;
	
	try
	{
		if(m_NVSIndex4MonitorPrx == NULL)
			return false;
		m_bRegisterOnIndex = m_NVSIndex4MonitorPrx->registerMe(m_Monitor,m_Monitor);
		if(m_bRegisterOnIndex)
		{
			if(NULL != m_pHeartThread)
			{
				m_pHeartThread->m_bExit = false;
				SetEvent(m_pHeartThread->m_hSuspend);
			}

			if(NULL != m_pErrorManage)
			{
				m_pErrorManage->m_bExit = false;
				SetEvent(m_pErrorManage->m_hSuspend);
			}
			
			if(NULL != m_pStampCheck)
			{
				m_pStampCheck->m_bExit = false;
				SetEvent(m_pStampCheck->m_hSuspend);
			}
		}
		return m_bRegisterOnIndex;
	}
	catch(...){}

	WriteSysLog("注册索引服务失败! 错误代码[100]\r\n");
	
	return false;
}
void NVSCoreBiz::c_setPlayModel(int nPlayModel)
{
	m_nSysPlayModel = nPlayModel;
}
//Private函数1
int NVSCoreBiz::c_playVideo(int nCameraID,HWND hWnd, bool bUseDecode /*标准流标识*/, bool bIsExternalDvr)
{
	char str[256] = {0};
	sprintf_s(str,"镜头[%d]c_playVideo(),Start, isExternalDvr=%s", nCameraID, bIsExternalDvr?"外部DVR":"内部DVR");
	WriteSysLog(str);

	if(!m_bRegisterOnIndex)
		return XY_REQ_INDEX_UNREGISTER; //-20 未向索引服务注册

	if(bUseDecode && m_pRealDecodeCallBack == NULL)
		return XY_REQ_UNSET_STDCALLBACK; //-22 标准流回调函数未设置
	else if(!bUseDecode && m_pPlayCallBack == NULL)
		return XY_REQ_UNSET_CALLBACK; //-21 回调函数未设置

	int Ret = 0;
	//NVSStreamManager* pStreamService = c_getStreamService(nCameraID, Ret);
	//if (pStreamService)
	//{
	//	int nRe = pStreamService->playVideo4ICE(nCameraID,hWnd, m_pPlayCallBack, bUseDecode, m_pRealDecodeCallBack, bIsExternalDvr);
	//	if(nRe == 0 || nRe == 1)
	//		updateCameraInfo(nCameraID,-1,hWnd,NULL,false,bUseDecode,NULL,0, bIsExternalDvr);

	//	sprintf_s(str,"镜头[%d]c_playVideo nRe=%d,end.\r\n", nCameraID,nRe);
	//	WriteSysLog(str);
	//	return nRe;
	//}else
	//{
	//	sprintf_s(str,"镜头[%d]获取流媒体地址失败 Error \r\n", nCameraID);
	//	WriteSysLog(str);
	//}

	//以下是请求流媒体失败后的处理操作 -2011-7-28
	if (Ret==XY_REQ_INDEX_NOT_FIND_STREAM)	//-181 没有绑定流媒体，则继续查找直连设备播放信息
	{
		/*2011-7-28 连接索引服务获取镜头对应DVRINFO by sjy 后续可以优化*/
		
		::NVSIndex::NVSDVRInfo _DvrInfo;
		if(m_NVSIndex4MonitorPrx->getDvrInfo(nCameraID, _DvrInfo))
		{
			sprintf_s(str,"获取镜头[%d]类型=%d\r\n", nCameraID, _DvrInfo.DVRType);
			WriteSysLog(str);
			switch(_DvrInfo.DVRType)
			{
			case 1: //海康
				break;
			case 2: //大华
				break;
			case 3: //图敏
				break;
			case 4: //大力
				break;
			case 5: //景阳
				break;
			case 6: //汉邦
				break;
			case 7: //安联
				break;
			case 8: //华三设备
			case 14://科达平台
			case 16://大华平台
			case 19://天视通平台
				{
					return  m_pHSVideoProcss->PlayHSVideo(m_NVSIndex4MonitorPrx, nCameraID, bUseDecode, hWnd, _DvrInfo);
				
				}
				break;
			case 9:	//博康设备
				break;

			default://设备类型未定义
				break;
			}
		}
		else
		{
			sprintf_s(str,"镜头[%d]关联DVR不存在，检索镜头信息失败 nRe=%d,end.\r\n", nCameraID, XY_REQ_INDEX_NOT_FIND_DVRINFO);
			WriteSysLog(str);
			return XY_REQ_INDEX_NOT_FIND_DVRINFO; //镜头关联DVR不存在,检索镜头信息失败,请核对	//2011-7-28 修改
		}
	}

	sprintf_s(str,"镜头[%d]c_playVideo nRe=%d,end.\r\n", nCameraID,Ret);
	WriteSysLog(str);

	m_pPlayCallBack(nCameraID,Ret);

	return Ret;
}

int  NVSCoreBiz::c_playVideoEx(int nCameraID, HWND hWnd, bool bUseDecode, bool bIsExternalDvr,string &sCameraID,void *pUsr)
{
	int nPlayRet = XY_TRUE;
	char str[256] = {0};
	sprintf_s(str,"CoreBiz::镜头[%d]c_playVideoEx()开始, bUseDecode=%d", nCameraID, bUseDecode);
	WriteSysLog(str);

	if(!m_bRegisterOnIndex)
	{
		nPlayRet = XY_REQ_INDEX_UNREGISTER;
	}	
	if(bUseDecode && m_pRealDecodeCallBack == NULL)
	{
		nPlayRet = XY_REQ_UNSET_STDCALLBACK;
	}	
	else if(!bUseDecode && m_pPlayCallBack == NULL)
	{
		nPlayRet = XY_REQ_UNSET_CALLBACK;
	}
	if(nPlayRet < 0)
	{
		sprintf_s(str,"CoreBiz::镜头[%d]返回错误值[%d].",nCameraID,nPlayRet);	
		WriteSysLog(str);
		if ( m_pPlayCallBack != nullptr ) {
			m_pPlayCallBack(nCameraID, nPlayRet);
		}
		
		return nPlayRet;
	}

	CPaperForm tform;
	ServerInfo svrInfo;
	//先检测后执行后续操作  如已存在窗口正在使用，则需要先关闭
	if(hWnd != NULL)
	{
		nPlayRet = tform.CheckHInfoExist(hWnd,nCameraID,sCameraID);
		if(XY_TRUE == nPlayRet)
		{
			WriteSysLog("CoreBiz::传入窗体已被占用，播放失败!");
			m_pPlayCallBack(nCameraID,XY_REQ_USED_WINDOW);
			return XY_REQ_USED_WINDOW;
		}
	}
	
	tform.PushParam(nCameraID,sCameraID,hWnd,svrInfo);//占据位置,先到者先播放
	::NVSStreamService::DeviceInfo devinfo;
	nPlayRet = tform.ParaseParam(nCameraID,sCameraID,bIsExternalDvr,svrInfo,devinfo);
	tform.PushParam(nCameraID,sCameraID,hWnd,svrInfo);//填充更新后的svrInfo

    try
    {
        devinfo.sChannel = m_NVSIndex4MonitorPrx->ConvertCameraID(nCameraID);
    }
    catch (...)
    {
        NVSCoreBiz:: WriteSysLog("ConvertCameraID(): 获取统一编码异常!");	
		m_pPlayCallBack(nCameraID,XY_REQ_INDEX_FALSE_GETCHACODE);
        return XY_REQ_INDEX_FALSE_GETCHACODE; //2011-7-28 获取镜头统一编码异常,取消播放 原值0; 
    }

	//根据基础设备信息的修改进行的修改 20121219
	//1.判断DVR接入方式:平台或设备
	//2.获取附加信息 字符通道信息，解码类型，编码类型
	::NVSIndex::NVSDVRInfo _DvrInfo;
	tform.GetDvrInfo(nCameraID, _DvrInfo);
    if(_DvrInfo.DVRTypeKey == "HS" || _DvrInfo.DVRTypeKey == "hs" || _DvrInfo.DVRTypeKey == "SIP" || _DvrInfo.DVRTypeKey == "sip")
    {
        _DvrInfo.SDVRAccessType = "Plat";
    }

	string sDVRAcessType = _DvrInfo.SDVRAccessType;    
	if(sDVRAcessType == "Plat")//平台或其他
	{
		m_pHSVideoProcss->m_pRealDecodeCallBack = m_pRealDecodeCallBack;
		tform.EraseParam(nCameraID,sCameraID,hWnd);
		nPlayRet = m_pHSVideoProcss->PlayHSVideo(m_NVSIndex4MonitorPrx, nCameraID, bUseDecode, hWnd, _DvrInfo);
		//m_pPlayCallBack(nCameraID,nPlayRet);	//默认返回成功
		return nPlayRet;
	}
	else
	{
		if(nPlayRet < 0 || svrInfo.strIp.size() < 7 || devinfo.sIP.size() < 7)
		{
			sprintf_s(str,"参数异常:svrInfo.strIp:%s,devinfo.sIP:%s.",svrInfo.strIp.c_str(),devinfo.sIP.c_str());	
			WriteSysLog(str);
			nPlayRet = XY_REQ_INDEX_NOT_FIND_STREAM;
			tform.EraseParam(nCameraID,sCameraID,hWnd);
			m_pPlayCallBack(nCameraID,nPlayRet);
			return nPlayRet;	
		}	
	}
	WriteSysLog("正常获取到参数，开始进行播放流程！");

	//参数判断并获取必要信息
	CSourceSvrInfomation *pSvrInfomation;
	pSvrInfomation = g_Agent.GetSvrInfomation(svrInfo);

	CStreamProcess *pProcess;
	pProcess = pSvrInfomation->GetProcessInfo(nCameraID,sCameraID,1/*如没有过程对象则建立之*/);
	if(pProcess != NULL)
	{
		//进入流处理流程并执行，返回结果
		nPlayRet = pProcess->RequestVideoICE(svrInfo,devinfo,_DvrInfo,hWnd,m_pPlayCallBack,bUseDecode,m_pRealDecodeCallBack,bIsExternalDvr);
	}
	else
	{
		nPlayRet = XY_REQ_FAIL_GET_PLAYOBJ;
	}

	if(XY_TRUE != nPlayRet && XY_REQ_PLAY_SUCCESS != nPlayRet)
	{
		pProcess->StopSoftSolution(hWnd, nCameraID);
		pProcess->StopCaptureStream();
		sprintf_s(str,"CoreBiz::镜头[%d]c_playVideoEx()完成失败,失败错误码%d,错误字符串;%s.",nCameraID,nPlayRet,c_getErrorMsg(nPlayRet));
	}
	else
	{
		sprintf_s(str,"CoreBiz::镜头[%d]c_playVideoEx()完成成功.",nCameraID);
		updateCameraInfo(nCameraID,hWnd,false,bUseDecode,bIsExternalDvr);
	}
	WriteSysLog(str);

	m_pPlayCallBack(nCameraID,nPlayRet);

	return nPlayRet;
}

//!< 关闭单路视频，一个Camera曾打开多次，但只关闭其中一个播放时，用这个
bool NVSCoreBiz::c_stopPlayVideo(HWND hWnd, int nCardIndex, int nCameraID)
{
	char str[256] = {0};
	sprintf_s(str, "[c_stopPlayVide] HWND=%d, nCardIndex=%d, nCameraID=%d",  hWnd, nCardIndex, nCameraID );
	WriteSysLog(str);

	if(m_pHSVideoProcss->StopHSVideo(hWnd, nCameraID))
	{
		WriteSysLog("[c_stopPlayVide] StopHSVideo成功");
		return true;
	}
	bool bRe = false;
	return bRe;
}

int NVSCoreBiz::c_stopPlayVideoEx(HWND hWnd, int nCameraID,string &sCameraID)
{
	int nPlayRet = XY_TRUE;
	char str[256] = {0};
	sprintf_s(str,"镜头[%d]关闭c_stopPlayVideoEx Start, hWnd %d.", nCameraID,hWnd);
	WriteSysLog(str);

	if(m_pHSVideoProcss->StopHSVideo(hWnd, nCameraID))//此镜头是华三镜头，则返回true
	{
		WriteSysLog("[c_stopPlayVideEx] StopHSVideo成功");
		return nPlayRet;
	}

	//先检测后执行后续操作  如不存在窗口正在使用，则无须关闭
	CPaperForm tform;
	nPlayRet = tform.CheckHInfoExist(hWnd,nCameraID,sCameraID);
	if(XY_TRUE != nPlayRet)
	{
		WriteSysLog("[c_stopPlayVideEx] [CheckHInfoExist] 失败");
		return nPlayRet;
	}

	CStreamProcess *pProcess = NULL;
	pProcess = GetProcessPtr(nCameraID);

	if(pProcess != NULL)
	{
		pProcess->StopSoftSolution(hWnd, nCameraID);//未处理返回值
		pProcess->StopCaptureStream();//未处理返回值
	}
	else
	{
		WriteSysLog("[c_stopPlayVideEx] [GetProcessPtr] 失败");
		nPlayRet = XY_FALSE;
		//tform.EraseParam(nCameraID,sCameraID,hWnd);//pzm 暂时去掉	
	}
	return nPlayRet;
}
//!< 关闭并清除一个Camera的所有播放对象时，用这个
bool NVSCoreBiz::c_stopPlayByCameraID(int nCameraID)
{
	int nPlayRet = 0;
	CPaperForm tform;
	ServerInfo svrInfo;

	::NVSStreamService::DeviceInfo devinfo;
	nPlayRet = tform.ParaseParam(nCameraID,svrInfo,devinfo);
	if(nPlayRet < 0)
	{
		return nPlayRet;
	}
	//参数判断并获取必要信息
	CSourceSvrInfomation *pSvrInfomation;
	pSvrInfomation = g_Agent.GetSvrInfomation(svrInfo);

	CStreamProcess *pProcess;
	pProcess = pSvrInfomation->GetProcessInfo(nCameraID,"");
	if(pProcess != NULL)
	{
		nPlayRet = pProcess->StopAllSoftSolution();
		nPlayRet = pProcess->StopCaptureStream();
	}
	return nPlayRet;
}
void NVSCoreBiz::c_stopAll()
{

	NVSCoreBiz::WriteSysLog("c_stopAll_begin");
	bool bEnter = false;
	bool bEnterStamp = false;

	::SetEvent(m_hStopRePlay);
	g_Agent.ClearAllSvrInfomation();
	CPaperForm::ClearAllSource();
	if(m_pHSVideoProcss)
		m_pHSVideoProcss->StopAllHSVideo();

	//通过索引向VIS服务发出释放清理用户通道记录对于没有VIS的项目的可以省略，
	try
	{
		if(m_NVSIndex4MonitorPrx)
			m_NVSIndex4MonitorPrx->NoticeReleaseUserAll(m_Monitor.ID);
	}
	catch(...)
	{

	}

	NVSCoreBiz::WriteSysLog("c_stopAll_end");
}
//! 云台控制
bool NVSCoreBiz::c_controlCameraSpeed(int nCameraID,int nCmd,bool bControl,int nSpeed)
{

	if(!m_bRegisterOnIndex)
		return false;

	char szLog[1024] = {0};
	sprintf_s(szLog,"c_controlCameraSpeed %d %d %d %d\n", nCameraID, nCmd, bControl, nSpeed);
	NVSCoreBiz::WriteSysLog(szLog);

	//华三镜头
	if(true == m_pHSVideoProcss->ControlCameraSpeed(nCameraID, nCmd, bControl, nSpeed))
		return true;

	if (nCmd == 24 || nCmd == 25) // 电子放大 by Kevin Ou 2019-05-21
	{
		CStreamProcess *pProcess;
		pProcess = GetProcessPtr(nCameraID);

		if(pProcess != NULL)
		{
			pProcess->ControlCameraSpeed(nCameraID, nCmd, bControl, nSpeed);
		}
		return true;
	}
	bool bRet = false;
	ServerInfo svrInfo;
	CStreamProcess *pPtr = GetProcessPtr(nCameraID,0);
	if(pPtr == NULL)
		return false;
	string sKey;
	pPtr->GetKeyInfo(nCameraID,sKey,svrInfo);
	int nRet =  g_Agent.ControlCameraSpeed(svrInfo,m_Monitor.ID,sKey, nCmd, bControl, nSpeed);
	if(XY_TRUE == nRet)
	{
		bRet  = true;
	}
	return bRet;
}

bool NVSCoreBiz::c_clientNotice()
{
	try {

		Ice::ObjectAdapterPtr adapter = m_Communicator->createObjectAdapter("NVSStreamPlay");
		adapter->activate();
		m_pDataReceiver = new NVSIndexNoticeI;

		m_id.name=::IceUtil::generateUUID();
		m_id.category="";
		adapter->add(m_pDataReceiver,m_id);

		m_NVSIndex4MonitorPrx->ice_getConnection()->setAdapter(adapter);
		if(m_NVSIndex4MonitorPrx == NULL)
			return false;
		m_NVSIndex4MonitorPrx->NoticeReady(c_getMonitorID(),m_id);

	} catch (const char * msg) {
		cerr << msg << endl;
		return false;
	}
	return true;
}


bool NVSCoreBiz::c_cancelControlCamera(HWND hWnd,int nCameraID)
{
	if(!m_bRegisterOnIndex)
		return false;

	bool bRet = false;
	ServerInfo svrInfo;
	CStreamProcess *pPtr = GetProcessPtr(nCameraID,0);
	if(pPtr == NULL)
		return false;
	string sKey;
	pPtr->GetKeyInfo(nCameraID,sKey,svrInfo);
	bRet =  g_Agent.cancelControlCamera(svrInfo,m_Monitor.ID,sKey);
	return bRet;
}
bool NVSCoreBiz::c_capturePictureEx(int nCameraID, char* pFileName)
{
	char strLog[256]={0};
	sprintf_s(strLog, sizeof(strLog), "c_capturePictureEx para id=[%d], filename=[%s]",nCameraID, pFileName );
	WriteSysLog(strLog);
	PlayInfo playInfo;
	if (m_pHSVideoProcss->FindPlayInfo(nCameraID, playInfo))
	{
		WriteSysLog("找到");
		return m_pHSVideoProcss->capturePictureEx(playInfo.nCameraID  , pFileName);
	}


	WriteSysLog("未找到");

	if(!m_bRegisterOnIndex)
		return false;

	bool bOK = false;
	//获取流处理对象
	CStreamProcess *pProcess;
	pProcess = GetProcessPtr(nCameraID);

	if(pProcess != NULL)
	{
		bOK = pProcess->CapturePicture(pFileName);
	}
	return bOK;
}
bool NVSCoreBiz::c_TransPTZ(int nCameraID, int nCmd, int nTransPTZIndex)
{
	if(!m_bRegisterOnIndex)
		return false;
	//华三镜头
	if (true == m_pHSVideoProcss->TransPTZ(nCameraID, nCmd, nTransPTZIndex))
		return true;

	bool bRet = false;
	ServerInfo svrInfo;
	CStreamProcess *pPtr = GetProcessPtr(nCameraID,0);
	if(pPtr == NULL)
		return false;
	string sKey;
	pPtr->GetKeyInfo(nCameraID,sKey,svrInfo);
	bRet =  g_Agent.TransPTZ(svrInfo,m_Monitor.ID,sKey, nCmd, nTransPTZIndex);

	return bRet;
}
bool NVSCoreBiz::c_getCompress(int nCameraID, char **lpOutBuffer)
{
	if(!m_bRegisterOnIndex)
		return false;

	bool bRet = false;
	ServerInfo svrInfo;
	CStreamProcess *pPtr = GetProcessPtr(nCameraID,0);
	if(pPtr == NULL)
		return false;
	string sKey;
	pPtr->GetKeyInfo(nCameraID,sKey,svrInfo);
	bRet =  g_Agent.getCompress(svrInfo,m_Monitor.ID,sKey,lpOutBuffer);

	return bRet;
}
bool NVSCoreBiz::c_setCompress(int nCameraID, char* pCompressInfo)
{
	if(!m_bRegisterOnIndex)
		return false;

	bool bRet = false;
	ServerInfo svrInfo;
	CStreamProcess *pPtr = GetProcessPtr(nCameraID,0);
	if(pPtr == NULL)
		return false;
	string sKey;
	pPtr->GetKeyInfo(nCameraID,sKey,svrInfo);
	bRet =  g_Agent.setCompress(svrInfo,m_Monitor.ID,sKey,pCompressInfo);
	return bRet;
}
bool NVSCoreBiz::c_getVideoEffect(int nCameraID, int* pBrightValue,int* pContrastValue, int* pSaturationValue,int* pHueValue)
{
	if(!m_bRegisterOnIndex)
		return false;

	bool bRet = false;
	ServerInfo svrInfo;
	CStreamProcess *pPtr = GetProcessPtr(nCameraID,0);
	if(pPtr == NULL)
		return false;
	string sKey;
	pPtr->GetKeyInfo(nCameraID,sKey,svrInfo);
	bRet =  g_Agent.getVideoEffect(svrInfo,m_Monitor.ID,sKey,pBrightValue,pContrastValue,pSaturationValue,pHueValue);
	return bRet;
}
bool NVSCoreBiz::c_setVideoEffect(int nCameraID, DWORD dwBrightValue,DWORD dwContrastValue, DWORD dwSaturationValue,DWORD dwHueValue)
{
	if(!m_bRegisterOnIndex)
		return false;

	bool bRet = false;
	ServerInfo svrInfo;
	CStreamProcess *pPtr = GetProcessPtr(nCameraID,0);
	if(pPtr == NULL)
		return false;
	string sKey;
	pPtr->GetKeyInfo(nCameraID,sKey,svrInfo);
	bRet =  g_Agent.setVideoEffect(svrInfo,m_Monitor.ID,sKey,dwBrightValue, dwContrastValue,  dwSaturationValue, dwHueValue);
	return bRet;
}
int  NVSCoreBiz::c_startRecord(int nCameraID, char* pFileName)
{
	char strLog[256]={0};
	sprintf_s(strLog, "startRecord: 镜头=%d, FileName = %s", nCameraID , pFileName);
	WriteSysLog(strLog);


	if(!m_bRegisterOnIndex)
		return -1;

	//华三镜头
	if(m_pHSVideoProcss->StartRecord(nCameraID, pFileName))
		return true;

	int nRet = -2;
	//获取流处理对象
	CStreamProcess *pProcess;
	pProcess = GetProcessPtr(nCameraID);

	if(pProcess != NULL)
	{
		nRet = pProcess->startRecord(pFileName);
	}
	return nRet;
}
bool NVSCoreBiz::c_stopRecord(int nCameraID)
{
	if(!m_bRegisterOnIndex)
		return false;

	//华三镜头
	if(m_pHSVideoProcss->StopRecord(nCameraID))
		return true;

	bool bRet = false;
	//获取流处理对象
	CStreamProcess *pProcess;
	pProcess = GetProcessPtr(nCameraID);

	if(pProcess != NULL)
	{
		bRet = pProcess->stopRecord();
	}
	return bRet;
}
bool NVSCoreBiz::c_serialSend(int nCameraID, char* cmd1, DWORD nLen1, char* cmd2, DWORD nLen2)
{
	if(!m_bRegisterOnIndex)
		return false;

	bool bRet = false;
	return bRet;
}
void NVSCoreBiz::c_setPlayDrawDevice(int nCameraID)
{
	if(!m_bRegisterOnIndex)
		return;

	ServerInfo svrInfo;
	CStreamProcess *pPtr = GetProcessPtr(nCameraID,0);
	if(pPtr == NULL)
		return;

	pPtr->v_setPlayDrawDevice();
}

//-----------------------------------------------------
int  NVSCoreBiz::c_getMonitorID(){return m_Monitor.ID;}
int  NVSCoreBiz::c_getMonitorRight(){return m_Monitor.Right;}

void NVSCoreBiz::updateCameraInfo(int nCameraID, HWND hPlayHandle, bool bDisconnect, bool bUseDecode ,bool bIsExternalDvr)
{
	bool bHad = false;
		
	::EnterCriticalSection(&m_Lock_CameraPool);
	vector<CameraInfo*>::iterator itFind = m_vCameraPool.begin();
	for(;itFind!=m_vCameraPool.end();++itFind)
	{
		if((*itFind)->nCameraID == nCameraID  && (*itFind)->hPlayHandle == hPlayHandle)
		{
			bHad = true;
			(*itFind)->bDisconnect = bDisconnect; 
			break;
		}
	}
	if(!bHad)
	{
		CameraInfo* ci = new CameraInfo();
		ci->nCameraID = nCameraID;
		ci->hPlayHandle = hPlayHandle;
		ci->bDisconnect = bDisconnect;
		ci->bUseDecode = bUseDecode;
		ci->bIsExternalDvr = bIsExternalDvr;
		m_vCameraPool.push_back(ci);
	}
	::LeaveCriticalSection(&m_Lock_CameraPool);
	register4StampCheck(nCameraID,hPlayHandle,m_nSysPlayModel,  bIsExternalDvr); /* 注册镜头备检测*/
}

void NVSCoreBiz::removeCameraInfo(int nCameraID,HWND hWnd)
{
	CameraInfo* pDel = 0;

	::EnterCriticalSection(&m_Lock_CameraPool);
	vector<CameraInfo*>::iterator itFind = m_vCameraPool.begin();
	for(;itFind!=m_vCameraPool.end();++itFind)
	{
		if((*itFind)->nCameraID == nCameraID && (*itFind)->hPlayHandle == hWnd)
		{
			pDel = (*itFind);
			break;
		}
	}
	if(itFind!=m_vCameraPool.end() && pDel)
	{
		m_vCameraPool.erase(itFind);
		delete pDel;
	}
	::LeaveCriticalSection(&m_Lock_CameraPool);
	unregister4StampCheck(nCameraID,hWnd,m_nSysPlayModel); /* 解除镜头注册*/
}
//!< 清理1个镜头的所有播放对象
void NVSCoreBiz::WriteSysLog(char* sLongText)
{
	::LoggerFile::WriteLogMsg(sLongText);
}

bool NVSCoreBiz::getCurrentDirectory(char* pDirectory)
{
	char* buffer = NULL;
	if( (buffer = _getcwd( NULL, 0 )) == NULL )
	{
		strcpy_s(pDirectory, 10, "c:/");
		return false;
	}
	strcpy_s(pDirectory,256,buffer);
	free(buffer);
	return true;
}

bool NVSCoreBiz::register4StampCheck(int nCameraID,HWND hWnd,int nPlayMode,bool bIsExternalDvr)
{
	bool bHad = false;

	EnterCriticalSection(&NVSCoreBiz::m_LockVectorStatic);
	vector<CHAN_STAMP>::iterator it = m_vChanStamp.begin();
	for(;it!= m_vChanStamp.end();++it)
	{
		if((*it).nCameraID == nCameraID && (*it).hWnd == hWnd)
		{
			bHad = true;
			break;
		}
	}
	if(it == m_vChanStamp.end())
	{
		CHAN_STAMP tStamp;
		tStamp.nCameraID = nCameraID;
		tStamp.hWnd = hWnd;
		tStamp.nPlayModel = nPlayMode;
		tStamp.timeStamp = IceUtil::Time::now();
		tStamp.bIsExternalDvr = bIsExternalDvr;
		m_vChanStamp.push_back(tStamp);
	}
	LeaveCriticalSection(&NVSCoreBiz::m_LockVectorStatic);

	return bHad;
}

void NVSCoreBiz::unregister4StampCheck(int nCameraID,HWND hWnd,int nPlayMode)
{
	char str[256]={0};

	EnterCriticalSection(&NVSCoreBiz::m_LockVectorStatic);
	vector<CHAN_STAMP>::iterator it = m_vChanStamp.begin();
	for(;it!= m_vChanStamp.end();)
	{
		if((*it).hWnd == hWnd)//更新实时镜头时间戳
		{
			it = m_vChanStamp.erase(it);
			break;
		}
		else
		{
			it++;
		}
	}
	LeaveCriticalSection(&NVSCoreBiz::m_LockVectorStatic);
}

void NVSCoreBiz::heartBeat4Chan(int nCameraID,HWND hWnd)
{
	EnterCriticalSection(&NVSCoreBiz::m_LockVectorStatic);
	vector<CHAN_STAMP>::iterator it = m_vChanStamp.begin();
	for(;it!= m_vChanStamp.end();)
	{
		if((*it).nCameraID == nCameraID && (*it).hWnd == hWnd)	//更新实时镜头时间戳
		{
			(*it).timeStamp = IceUtil::Time::now();
			break;
		}
		else
		{
			it++;
		}
	}
	LeaveCriticalSection(&NVSCoreBiz::m_LockVectorStatic);
}

int NVSCoreBiz::c_splitFile(int nCameraID,char * sFileName,int nPriorTime, bool bIsExternalDvr)
{
	int nRe = -1;
	try
	{
		//获取流处理对象
		CStreamProcess *pProcess;
		pProcess = GetProcessPtr(nCameraID);

		if(pProcess != NULL)
		{
			nRe = pProcess->setFileHandle(sFileName);
		}
		else 
		{
			nRe =-2; // 获取播放对象失败
		}
	}
	catch(...){}
	return nRe; 
}

bool NVSCoreBiz::c_controlCameraSound(int nCameraID,bool bOpenSound)
{
	if(!m_bRegisterOnIndex)
		return false;

	bool bOK = false;
	//获取流处理对象
	CStreamProcess *pProcess;
	pProcess = GetProcessPtr(nCameraID);

	if(pProcess != NULL)
	{
		bOK = pProcess->ControlCameraSound(bOpenSound);
	}
	return bOK;
}

intptr_t NVSCoreBiz::c_getStreamServerWorkState(int nCameraId, int nCameraCount, int *outSize )
{
	char strlog[256];
	sprintf_s(strlog, 256, "ID:%d, num:%d", nCameraId, nCameraCount);
	WriteSysLog(strlog);

	bool bRet = false;
	ServerInfo svrInfo;
	CStreamProcess *pPtr = GetProcessPtr(nCameraId,0);
	if(pPtr == NULL)
		return 0;
	try
	{
		string sKey;
		pPtr->GetKeyInfo(nCameraId,sKey,svrInfo);

		STREAMSERVERWORKSTATELISTTYPE workStateList;
		NVSStreamService::WorkState workState;
		ZeroMemory(&workState, sizeof(NVSStreamService::WorkState));

		if(g_Agent.getWorkState(svrInfo,workState))
		{
			WriteSysLog("(*it)->getWorkState(workState)_true");
			STREAMSERVERWORKSTATE data ;
			data.ChannelLoad = workState.ChannelLoad;
			data.MonitorLoad = workState.MonitorLoad;
			data.SendLoad = workState.SendLoad;
			data.MaxSendCount = workState.MaxSendCount; //最大发送路数 
			data.MaxChannel = workState.MaxChannel;   //最大通道连接数
			sprintf_s(data.sStreamServerIP, 20, "%s", svrInfo.strIp.c_str());

			sprintf_s(strlog, 256, "ChannelLoad :%d, MonitorLoad:%d, SendLoad:%d, MaxSendCount:%d, MaxChannel:%d ", 
				data.ChannelLoad, data.MonitorLoad, data.SendLoad, data.MaxSendCount, data.MaxChannel);
			WriteSysLog(strlog);//end_if
			workStateList.push_back(data);	
		}
		else
		{
			WriteSysLog("(*it)->getWorkState(workState)_false");//end_if
		}	

		*outSize = (int)workStateList.size();
		if (*outSize<=0)	
		{	
			WriteSysLog("获取流媒体状态_返回0");
			return 0;
		}

		if (pDataArray!=NULL)
		{
			delete []pDataArray;
			pDataArray = NULL;
		}

		pDataArray = new STREAMSERVERWORKSTATE[*outSize];
		int index=0;
		STREAMSERVERWORKSTATELISTTYPE::iterator it = workStateList.begin();
		for (; it!=workStateList.end(); it++)
		{
			pDataArray[index] = (*it);
		}
	} 
	catch(...)
	{
		
	}

	sprintf_s(strlog, 256, "Ret地址:%d, size=%d",(LONG) pDataArray, *outSize);
	WriteSysLog(strlog);
	return reinterpret_cast<intptr_t>(pDataArray);
}

bool NVSCoreBiz::IsFinded(string sIP, STREAMSERVERWORKSTATELISTTYPE &list)
{
	STREAMSERVERWORKSTATELISTTYPE::iterator it = list.begin();
	for (; it!=list.end(); it++)
	{
		string strIP = (*it).sStreamServerIP;
		if (sIP == strIP)
		{
			return true;
		}
	}
	return false;
}


char * NVSCoreBiz::c_getStreamServerIP( int nCameraID)
{
	bool bOK = false;
	CPaperForm tform;
	int nPlayRet;
	ServerInfo svrInfo;
	::NVSStreamService::DeviceInfo devinfo;
	nPlayRet = tform.ParaseParam(nCameraID,svrInfo,devinfo);
	if(nPlayRet < 0)
	{
		return NULL;
	}
	sprintf_s(m_strIP, sizeof(m_strIP), "%s", svrInfo.strIp.c_str());
	return m_strIP;
}

int NVSCoreBiz::v_setPlayWindow(HWND palyWindow[], int nMaxCount)
{
	return m_pHSVideoProcss->SetPlayWindow(palyWindow, nMaxCount);
}

void NVSCoreBiz::updateCameraID(int nPriorID,int nSwitchID)
{
	WriteSysLog("NVSCoreBiz::updateCameraID CAMERA BEGIN");
	CStreamProcess *pProcess = NULL;
	pProcess = GetProcessPtr(nPriorID);
	if(pProcess != NULL)
	{
		pProcess->updateCameraID(nSwitchID);
	}
	else
	{
		return;
	}

	::EnterCriticalSection(&m_Lock_CameraPool);
	vector<CameraInfo*>::iterator itCamera = m_vCameraPool.begin();
	for (;itCamera!=m_vCameraPool.end();itCamera++)
	{
		if ((*itCamera)->nCameraID == nPriorID)
		{
			(*itCamera)->nCameraID = nSwitchID;
		}
	}
	::LeaveCriticalSection(&m_Lock_CameraPool);

	//更新时间戳镜头
	EnterCriticalSection(&m_LockVectorStatic);
	vector<CHAN_STAMP>::iterator itStamp = m_vChanStamp.begin();
	for(;itStamp!=m_vChanStamp.end();itStamp++)
	{
		if ((*itStamp).nCameraID == nPriorID)
		{
			(*itStamp).nCameraID = nSwitchID;
		}
	}
	LeaveCriticalSection(&m_LockVectorStatic);
	WriteSysLog("NVSCoreBiz::updateCameraID CAMERA END");

}

void NVSCoreBiz::CheckStampTime()
{
	char str[256] = {0};
	CHAN_STAMP stStamp;
	vector<CHAN_STAMP> vRePlayCamera;
	
	bool bIndex = pingIndex();

	EnterCriticalSection(&m_LockVectorStatic);
	try
	{
		vector<CHAN_STAMP>::iterator it = m_vChanStamp.begin();
		for(;it!=m_vChanStamp.end();)
		{
			//检查时间戳
			IceUtil::Time now_check = IceUtil::Time::now();
			if (now_check.toSeconds() - (*it).timeStamp.toSeconds() > GL_INTERVAL_TIME)
			{
				//只针对软解播放时，在一定时间内无数据流先关闭后播放
				if (bIndex)
				{
					stStamp.hWnd = (*it).hWnd;
					stStamp.nCameraID = (*it).nCameraID;
					stStamp.bIsExternalDvr = (*it).bIsExternalDvr;
					vRePlayCamera.push_back(stStamp);
					// 不要删除，只要在规定的时间里无数据流就一直重连
					//it = m_vChanStamp.erase(it);
				}
				//不删除的话，就要更新时间,防止一直重连
				(*it).timeStamp = IceUtil::Time::now();
			}
			else
			{
				//当与索引断开时，需要更新时间以防止重连
				if (!bIndex)
				{
					(*it).timeStamp = IceUtil::Time::now();
				}

				it++;
			}
		}
	}
	catch (...){}
	LeaveCriticalSection(&m_LockVectorStatic);

	if (vRePlayCamera.size() > 0)
	{
		ResetEvent(m_hStopRePlay);
	}

	//防止延时时间会影响锁，用vRePlayCamera播放
	map<int,int> tmp;
	vector<CHAN_STAMP>::iterator itCamera = vRePlayCamera.begin();
	for(itCamera;itCamera!=vRePlayCamera.end();)
	{
		sprintf_s(str,"镜头[%d]在一定时间内未收到数据流，调用了重新播放函数，总共｛%d｝个镜头.",(*itCamera).nCameraID,vRePlayCamera.size());
		NVSCoreBiz::WriteSysLog(str);
		if(tmp.count((*itCamera).nCameraID) == 0)
		{
			rePlayVideo((*itCamera).nCameraID,(*itCamera).hWnd, (*itCamera).bIsExternalDvr);
		}
		tmp[(*itCamera).nCameraID] = 0;

		itCamera = vRePlayCamera.erase(itCamera);
	}

}

void NVSCoreBiz::rePlayVideo(int nCameraID,HWND hWnd, bool bIsExternalDvr)
{
	string sCameraID = "";	
	::Sleep(50);

	char str[256]={0};
	sprintf_s(str,"镜头[%d]准备判断是否要进行重新播放动作",nCameraID);
	NVSCoreBiz::WriteSysLog(str);

	if(WAIT_OBJECT_0 == WaitForSingleObject(m_hStopRePlay,0))
	{
		return;
	}
	sprintf_s(str,"镜头[%d]开始进行重新播放动作",nCameraID);
	NVSCoreBiz::WriteSysLog(str);

	if(m_pPlayCallBack)
		m_pPlayCallBack(nCameraID,XY_REQ_RE_PLAY); //-40 前端设备未传回数据流，正在重新请求播放

	{
		int nPlayRet = XY_TRUE;
		CStreamProcess *pProcess;
		pProcess = GetProcessPtr(nCameraID);
		if(pProcess != NULL)
		{
			nPlayRet = pProcess->ReconnectCaptureStream();
		}	
	}
}


CStreamProcess * NVSCoreBiz::GetProcessPtr(int nCameraID,int nCreateFlag)
{
	char str[256]={0};
	sprintf_s(str,"获取镜头[%d]流处理进程，nCreateFlag %d",nCameraID,nCreateFlag);
	NVSCoreBiz::WriteSysLog(str);

	int nPlayRet = 0;
	ServerInfo svrInfo;
	nPlayRet = CPaperForm::GetCheckedSvrInfo(svrInfo,nCameraID);
	if(XY_TRUE != nPlayRet)
	{
		return NULL;
	}
	
	//参数判断并获取必要信息
	CSourceSvrInfomation *pSvrInfomation;
	pSvrInfomation = g_Agent.GetSvrInfomation(svrInfo);
	NVSCoreBiz::WriteSysLog("获取镜头流处理进程GetSvrInfomation完成。");

	CStreamProcess *pProcess;
	pProcess = pSvrInfomation->GetProcessInfo(nCameraID,"",nCreateFlag);
	NVSCoreBiz::WriteSysLog("获取镜头流处理进程GetProcessInfo完成。");
	return pProcess;
}


int NVSCoreBiz::c_GetRecordFile(intptr_t lHandle,RECORDQUERYTYPE nType,char* startTime,char* endTime,RECORDFILE pRecordFile[],int nMaxFileCount)
{
	
	int nSize = getRecordFileEx(lHandle ,nType ,startTime , endTime ,pRecordFile, nMaxFileCount);
	return nSize;

}

intptr_t NVSCoreBiz::c_ReplayRecordFile(intptr_t lHandle,HWND hWnd,char* fileName,char* startTime, char* endTime,int nFileSize)
{
	char str[256]={0};
	sprintf_s(str,"开始远程回放，文件名[%s]",fileName);
	NVSCoreBiz::WriteSysLog(str);

	intptr_t  lRePlayhandle = replayRecordFile(lHandle , hWnd,fileName ,startTime, endTime, 0);
	if(lRePlayhandle < 0)
	{
		return -1;
	}
	 int iout = 0;
	 bool bRes = controlReplayRecordFile(lHandle,lRePlayhandle , REPLAY_CTRL_PLAYSTART , 0 , &iout);

	 return lRePlayhandle;
}

int NVSCoreBiz::c_ControlReplayRecordFile(intptr_t lHandle,intptr_t lRePlayhandle,int nCmd,int nInValue)
{
	if(lRePlayhandle < 0)
	{
		return -1;
	}
	int iout = 0;
	if (controlReplayRecordFile(lHandle,lRePlayhandle , nCmd , nInValue , &iout))
	{
		return iout;
	}
	return 0;
}

bool NVSCoreBiz::c_StopReplayRecordFile(intptr_t lHandle,intptr_t lRePlayhandle)
{
	return stopReplayRecordFile(lHandle , lRePlayhandle);
}

intptr_t NVSCoreBiz::c_DownloadRecordFile(intptr_t lHandle,char* fileName,char* startTime, char* endTime,int nFileSize,char* saveFile)
{
	intptr_t lDownloadhandle = downloadRecordFile(lHandle ,fileName , startTime, endTime, 0 , saveFile , NULL ,NULL);
	if (lDownloadhandle >=0 )
	{
		controlReplayRecordFile(lHandle,lDownloadhandle , REPLAY_CTRL_PLAYSTART , 0 , NULL);
	}
	return lDownloadhandle;
}
int NVSCoreBiz::c_GetDownloadPos(intptr_t lHandle,intptr_t ldownloadHandle)
{
 
	return getDownloadPos(lHandle,ldownloadHandle);
}
bool NVSCoreBiz::c_StopDownloadRecordFile(intptr_t lHandle,intptr_t ldownloadHandle)
{
	return stopDownloadRecordFile(lHandle,ldownloadHandle);
}

intptr_t NVSCoreBiz:: c_CaptureStream(int nCameraID, LPCAPTURESTREAMCALLBACK pCaptuerStreamFuc, void* pUser, int nGetVideoType )
{
	CPaperForm tform;
	::NVSStreamService::DeviceInfo devinfo;
	string sstate = "获取镜头的设备信息成功!";
	int nRet = tform.GetCameraIDDevInfoByIndex(nCameraID,false,devinfo,sstate);

	BOOL bRe = FALSE;
	intptr_t lRealHandle =connectDVR((char*)devinfo.sIP.c_str(),devinfo.nPort, (char*)devinfo.sUser.c_str(),(char*)devinfo.sPassword.c_str(), devinfo.nChannel ,(char*)devinfo.sType.c_str(),bRe);
	if(lRealHandle<0)
	{
		return false;
	}
	bool bRet = captureStream(lRealHandle, pCaptuerStreamFuc, this);
	return lRealHandle;

}

bool NVSCoreBiz::c_StopCaptureStream(intptr_t lHandle)
{
	if(lHandle>=0)
	{
		stopCaptureStream(lHandle);
		disconnectDVR(lHandle);
		
	}
	return true;

		

}



bool NVSCoreBiz::c_GetDecodeType(int &nCameraID,char*sType)
{
	CPaperForm tform;
	::NVSStreamService::DeviceInfo devinfo;
	string sstate = "";
	int nRet = tform.GetCameraIDDevInfoByIndex(nCameraID,false,devinfo,sstate);
	
	strcpy((sType),devinfo.sType.c_str());

	char str[256]={0};
	sprintf_s(str,"GetDecodeType 类型：[%s]",sType);
	NVSCoreBiz::WriteSysLog(str);
	return true;
}


intptr_t NVSCoreBiz::c_ConnectDVR(int nCameraID)
{
	CPaperForm tform;
	::NVSStreamService::DeviceInfo devinfo;
	string sstate = "获取镜头的设备信息成功!";
	int nRet = tform.GetCameraIDDevInfoByIndex(nCameraID,false,devinfo,sstate);

	intptr_t lConnect = -1;
	BOOL bRe = FALSE;
	lConnect =connectDVR((char*)devinfo.sIP.c_str(),devinfo.nPort, (char*)devinfo.sUser.c_str(),(char*)devinfo.sPassword.c_str(), devinfo.nChannel ,(char*)devinfo.sType.c_str(),bRe);

	if(lConnect<0)
	{
		return -1;
	}
	return lConnect;

}

void NVSCoreBiz:: c_disConnectDVR(intptr_t lHandle)
{
	disconnectDVR(lHandle);
}


