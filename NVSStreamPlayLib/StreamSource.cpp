#include "StdAfx.h"
#include "nvssdkdef_x64.h"
#include "StreamSource.h"
#include "StreamHandlerManager.h"
#include "StreamProcess.h"
#include "NVSCoreBiz.h"

CStreamSourceAgent g_Agent;
//extern CLogRecorder g_LogRecorder;
StreamHandlerManager GL_StreamHandlerManager;

#define  CON_DISCONNECT 0
#define  CON_RECONNECT  1
#define  CON_CONNECTED  2
#define  CON_NONEEDRECONNECT  3


///////////////////////////////////////////////////////////////////
//数据接收类

NVSStreamDataReceiverExI::NVSStreamDataReceiverExI(CStreamProcess *pthis)
{
	m_pProcess = pthis;
}
NVSStreamDataReceiverExI::~NVSStreamDataReceiverExI()
{

}

bool NVSStreamDataReceiverExI::sendStreamHead(const ::NVSStreamService::StreamPiece& sd, const ::Ice::Current& current)
{
	if(m_pProcess != NULL)
	{
		m_pProcess->initHead(sd);
	}	
	return true;
}

bool NVSStreamDataReceiverExI::sendStreamBody(const ::NVSStreamService::StreamPiece& sd, const ::Ice::Current& current)
{
	if(m_pProcess != NULL)
	{
		m_pProcess->inputData(sd);
	}	
	
	return true;
}


bool  NVSStreamDataReceiverExI::StopSend()
{
	//m_pSSource = NULL;
	return XY_TRUE;
}
///////////////////////////////////////////////////////////////////
//机构类

CStreamSourceAgent::CStreamSourceAgent()
{
	InitializeCriticalSection(&m_ConLock);
	Ice::PropertiesPtr properties = Ice::createProperties();
	properties->setProperty("Ice.Warn.AMICallback", "0");
	properties->setProperty("Ice.ACM.Client", "0");
	properties->setProperty("Ice.UseEventLog", "0");
	properties->setProperty("Ice.Logger.Timestamp", "0");
	properties->setProperty("Ice.ThreadPool.Client.Size", "50");
	properties->setProperty("Ice.Trace.Network", "0");
	properties->setProperty("Ice.Trace.Protocol", "0");


	Ice::InitializationData id;
	id.properties = properties;
	m_Communicator = Ice::initialize(id);  //建立通讯器;
}

CStreamSourceAgent::~CStreamSourceAgent()
{
	DeleteCriticalSection(&m_ConLock);
}

//逻辑操作获取ICE参数
NVSStreamServiceAPIPrx CStreamSourceAgent::GetPrx(ServerInfo info)
{
	char szConnect[256] = {0};
	GetKey(info,szConnect,sizeof(szConnect));
	
	if(m_mapPrx.count(szConnect) != 0)
	{
		return m_mapPrx[szConnect];
	}

	NVSCoreBiz::WriteSysLog("CStreamSourceAgent::GetPrx 代理为空");

	return NULL;
}

Ice::ObjectAdapterPtr CStreamSourceAgent::GetAdapter(ServerInfo info)
{
	char szConnect[256] = {0};
	GetKey(info,szConnect,sizeof(szConnect));

	if(m_mapAdpPtr.count(szConnect) != 0)
	{
		return m_mapAdpPtr[szConnect];
	}

	return NULL;
}


NVSStreamServiceAPIPrx CStreamSourceAgent::CreatePrx(ServerInfo info)
{
	char szConnect[256] = {0};
	GetKey(info,szConnect,sizeof(szConnect));

	NVSStreamServiceAPIPrx tmpprx = GetPrx(info);
	if(tmpprx != NULL)
	{
		return tmpprx;	
	}

	LinkInfo linfo;
	linfo.svrInfoKey = szConnect;
	if(ReCreatePrx(info) == NULL)
	{
		m_mapLinkInfo[szConnect] = linfo;
		return NULL;
	}

	linfo.ConFlag = 1;
	m_mapLinkInfo[szConnect] = linfo;

	return m_mapPrx[szConnect];
}

Ice::ObjectAdapterPtr  CStreamSourceAgent::CreateAdapter(ServerInfo info)
{
	char szConnect[256] = {0};
	GetKey(info,szConnect,sizeof(szConnect));

	Ice::ObjectAdapterPtr tmpAdpt = GetAdapter(info); 
	if(tmpAdpt != 0)
	{
		return tmpAdpt;
	}

	if(ReCreateAdapter(info) == NULL)
	{
		return NULL;
	}	

	return m_mapAdpPtr[szConnect];
}



void CStreamSourceAgent::GetKey(ServerInfo info,char *pKey,int nSize)
{
	//sprintf_s(pKey,nSize,"%s:tcp -h %s -p %d -t %d",info.strInterFace.c_str(), info.strIp.c_str(), info.nPort,10000);
	sprintf_s(pKey,nSize,"%s:tcp -h %s -p %d",info.strInterFace.c_str(), info.strIp.c_str(), info.nPort);

}

//ICE 操作：
int  CStreamSourceAgent::CleanAdapterIdentity(ServerInfo info,Ice::Identity DataReceiverIdentity)
{

	char szConnect[256] = {0};
	GetKey(info,szConnect,sizeof(szConnect));

	if(GetAdapter(info) == 0)
	{
		return 0;
	}

	Ice::ObjectAdapterPtr NVSSreamServiceAPIAdapter;
	NVSSreamServiceAPIAdapter = m_mapAdpPtr[szConnect];

	try
	{
		NVSSreamServiceAPIAdapter->remove(DataReceiverIdentity);
	}
	catch(Ice::Exception &ex)
	{
		string strerr = ex.ice_name();
	}
	catch(...)
	{

	}
	return 1;
}

int  CStreamSourceAgent::DestroyAdapter(ServerInfo info)
{
	char szConnect[256] = {0};
	GetKey(info,szConnect,sizeof(szConnect));

	if(GetAdapter(info) == 0)
	{
		return 0;
	}

	Ice::ObjectAdapterPtr NVSSreamServiceAPIAdapter;
	NVSSreamServiceAPIAdapter = m_mapAdpPtr[szConnect];
	
	m_mapPrx[szConnect] = NULL;
	m_mapPrx.erase(szConnect);
	m_mapAdpPtr[szConnect] = NULL;
	m_mapAdpPtr.erase(szConnect);
	try
	{
		NVSSreamServiceAPIAdapter->deactivate();
		NVSSreamServiceAPIAdapter->waitForDeactivate();
	}
	catch(Ice::Exception &ex)
	{
		string strerr = ex.ice_name();
		return 0;
	}
	catch(...)
	{
		return 0;
	}
	return 1;
}

NVSStreamServiceAPIPrx CStreamSourceAgent::ReCreatePrx(ServerInfo info)
{
	char szLogInfo[256] = {0};
	char szConnect[256] = {0};
	GetKey(info,szConnect,sizeof(szConnect));

	Ice::ObjectPrx base;
	NVSStreamServiceAPIPrx Agentproxy = GetPrx(info);
	if(Agentproxy != NULL)
	{
		return Agentproxy;
	}

	try
	{
		base = m_Communicator->stringToProxy(szConnect);
		if (!base)
		{
			sprintf_s(szLogInfo,"获得流媒体代理失败: %s",szConnect);
			NVSCoreBiz:: WriteSysLog(szLogInfo);
			return NULL;
		}
		/*!< 与流媒体服务交互指针 */

		Agentproxy = ::NVSStreamService::NVSStreamServiceAPIPrx::checkedCast(base->ice_twoway());
		if(Agentproxy != NULL)
		{
			m_mapPrx[szConnect] = Agentproxy;
		}
	}
	catch (const Ice::Exception & ex)
	{
		string strerr = ex.ice_name();
		sprintf_s(szLogInfo,"建立流媒体代理失败 : %s",strerr.c_str());
		NVSCoreBiz:: WriteSysLog(szLogInfo);
		return NULL;
	}
	return m_mapPrx[szConnect];
}

Ice::ObjectAdapterPtr  CStreamSourceAgent::ReCreateAdapter(ServerInfo info)
{
	char szLogInfo[256] = {0};
	char szConnect[256] = {0};
	GetKey(info,szConnect,sizeof(szConnect));

	/*!< 与流媒体服务交互指针 */
	NVSStreamServiceAPIPrx Agentproxy;
	if(m_mapPrx.count(szConnect) == 0)
	{
		sprintf_s(szLogInfo,"获得流媒体代理失败: %s",szConnect);
		NVSCoreBiz:: WriteSysLog(szLogInfo);
		return NULL;
	}

	if(XY_FALSE == m_mapLinkInfo[szConnect].ConFlag)
	{
		sprintf_s(szLogInfo,"流媒体心跳失败，无须进行继续操作！");
		NVSCoreBiz:: WriteSysLog(szLogInfo);
		return NULL;	
	}

	Agentproxy = m_mapPrx[szConnect];
	XY_BOOL bRet = Heart(info);

	if(bRet != XY_TRUE)
	{
		sprintf_s(szLogInfo,"代理网络[%s]未连接成功,用心跳验证。",szConnect);
		NVSCoreBiz:: WriteSysLog(szLogInfo);
		return NULL;
	}	


	Ice::ObjectAdapterPtr NVSSreamServiceAPIAdapter ;

	try
	{
		NVSSreamServiceAPIAdapter = m_Communicator->createObjectAdapter(szConnect);
		NVSSreamServiceAPIAdapter->activate();
		Agentproxy->ice_getConnection()->setAdapter(NVSSreamServiceAPIAdapter);
		m_mapAdpPtr[szConnect] = NVSSreamServiceAPIAdapter;
	}
	catch(Ice::Exception &ex)
	{
		string strerr = ex.ice_name();
		sprintf_s(szLogInfo,"建立流媒体反向适配器失败 : %s",strerr.c_str());
		NVSCoreBiz:: WriteSysLog(szLogInfo);
	}
	NVSCoreBiz:: WriteSysLog("建立流媒体反向适配器成功。");

	return m_mapAdpPtr[szConnect];
}

int  CStreamSourceAgent::DoAllHeartCheck(vector<ServerInfo> &vecFailedSvr)
{
	int nSize = 0;
	vector<ServerInfo> tmp;
	EnterCriticalSection(&m_ConLock);
	map<string,CSourceSvrInfomation *>::iterator itFind = m_mapSvrInfomation.begin();
	for(;itFind != m_mapSvrInfomation.end();)
	{
		int nSize = 0;
		ServerInfo svrinfo;
		nSize = (*itFind).second->GetSvrInfo(svrinfo);	
		if(nSize == 0)
		{
			char szKey[256] = {0};
			sprintf_s(szKey,sizeof(szKey),"%s:%d",svrinfo.strIp.c_str(),svrinfo.nPort);
			GL_StreamHandlerManager.freeStreamLoginIdentify(szKey);
			DestroyAdapter(svrinfo);
			itFind = m_mapSvrInfomation.erase(itFind);
			continue;
		}
		tmp.push_back(svrinfo);
		itFind++;
	}
	LeaveCriticalSection(&m_ConLock);

	vector<ServerInfo>::iterator it_info = tmp.begin();
	for(;it_info!=tmp.end();it_info++)
	{
		ServerInfo svrinfo = *it_info;
		XY_BOOL nRet = Heart(svrinfo);
		char szConnect[256] = {0};
		GetKey(svrinfo,szConnect,sizeof(szConnect));
		m_mapLinkInfo[szConnect].ConFlag = nRet;
		if(nRet != XY_TRUE)
		{
			vecFailedSvr.push_back(svrinfo);
		}
	}
	nSize = (int)vecFailedSvr.size();
	return nSize;//均正常，无连接失败的服务
}

//ICE接口操作：
int  CStreamSourceAgent::Heart(ServerInfo info)
{
	char szConnect[256] = {0};
	GetKey(info,szConnect,sizeof(szConnect));

	/*!< 与流媒体服务交互指针 */
	NVSStreamServiceAPIPrx Agentproxy;
	if(m_mapPrx.count(szConnect) == 0)
	{
		return XY_FALSE;
	}
	Agentproxy = m_mapPrx[szConnect];

	try
	{
		Agentproxy->HeartBeat();
	}
	catch(Ice::Exception &ex)
	{
		string strerr = ex.ice_name();
		return XY_FALSE;
	}

	return XY_TRUE;
}


XY_BOOL  CStreamSourceAgent::startPlayer(ServerInfo info,const ::NVSStreamService::DeviceInfo& connectInfo, const ::Ice::Identity& ident, ::std::string& sKey)
{
	NVSCoreBiz::WriteSysLog(__FUNCTION__);
	XY_BOOL bRet = XY_FALSE;
	char szLogInfo[256] = {0};
	
	NVSStreamServiceAPIPrx tmpprx = GetPrx(info);
	if(tmpprx == NULL)
	{
		return XY_FALSE;	
	}
	
	char szConnect[256] = {0};
	GetKey(info,szConnect,sizeof(szConnect));
	if(XY_FALSE == m_mapLinkInfo[szConnect].ConFlag)
	{
		sprintf_s(szLogInfo,"流媒体心跳失败，无须进行继续操作！");
		NVSCoreBiz::WriteSysLog(szLogInfo);
		return XY_FALSE;	
	}

	try
	{	
		bRet = tmpprx->startPlayer(connectInfo,ident,sKey);
	}
	catch(Ice::Exception &ex)
	{
		string strerr = ex.ice_name();
		sprintf_s(szLogInfo,"流媒体播放接口失败 : %s.",strerr.c_str());
		NVSCoreBiz:: WriteSysLog(szLogInfo);
		bRet = XY_FALSE;
	}
	return bRet;
}

XY_BOOL  CStreamSourceAgent::stopVideo(ServerInfo info,::std::string& sKey)
{
	NVSCoreBiz::WriteSysLog(__FUNCTION__);
	NVSStreamServiceAPIPrx tmpprx = GetPrx(info);
	if(tmpprx == NULL)
	{	
		return XY_FALSE;	
	}

	char szLogInfo[256] = {0};
	char szConnect[256] = {0};
	GetKey(info,szConnect,sizeof(szConnect));
	if(XY_FALSE == m_mapLinkInfo[szConnect].ConFlag)
	{
		sprintf_s(szLogInfo,"流媒体心跳失败，无须进行继续操作！");
		NVSCoreBiz:: WriteSysLog(szLogInfo);
		return XY_FALSE;	
	}

	try
	{
		tmpprx->stopVideo(sKey);
	}
	catch(Ice::Exception &ex)
	{
		string strerr = ex.ice_name();
		sprintf_s(szLogInfo,"流媒体停止播放接口失败 : %s.",strerr.c_str());
		NVSCoreBiz:: WriteSysLog(szLogInfo);
		return XY_FALSE;
	}
	catch(...)
	{
		NVSCoreBiz:: WriteSysLog("流媒体停止播放接口失败 其他失败原因。");
		return XY_FALSE;
	}
	NVSCoreBiz::WriteSysLog("CStreamSourceAgent::stopVideo end");
	return XY_TRUE;
}

XY_BOOL  CStreamSourceAgent::ControlCameraSpeed(ServerInfo info,int nMonitorID, string sKeyID,int nCmd,bool bControl,int nSpeed)
{
	NVSStreamServiceAPIPrx tmpprx = GetPrx(info);
	if(tmpprx == NULL)
	{
		return XY_FALSE;	
	}

	char szLogInfo[256] = {0};
	char szConnect[256] = {0};
	GetKey(info,szConnect,sizeof(szConnect));
	if(XY_FALSE == m_mapLinkInfo[szConnect].ConFlag)
	{
		sprintf_s(szLogInfo,"流媒体心跳失败，无须进行继续操作！");
		NVSCoreBiz:: WriteSysLog(szLogInfo);
		return XY_FALSE;	
	}

	XY_BOOL nRet = XY_TRUE;
	try
	{
		nRet = tmpprx->controlCameraSpeed(sKeyID,nCmd,bControl,nSpeed);
	}
	catch (...)
	{
		char str[256] = {0};
		sprintf_s(str,"向流媒体请求控制云台出现异常.");
		NVSCoreBiz::WriteSysLog(str);
	}
	return nRet;
}

bool CStreamSourceAgent::cancelControlCamera(ServerInfo info,int nMonitorID, string sKeyID)
{
	NVSStreamServiceAPIPrx tmpprx = GetPrx(info);
	if(tmpprx == NULL)
	{
		return false;	
	}
	bool bRet = false;
	char szLogInfo[256] = {0};
	char szConnect[256] = {0};
	GetKey(info,szConnect,sizeof(szConnect));
	if(XY_FALSE == m_mapLinkInfo[szConnect].ConFlag)
	{
		sprintf_s(szLogInfo,"流媒体心跳失败，无须进行继续操作！");
		NVSCoreBiz:: WriteSysLog(szLogInfo);
	}
	else 
	{	
		XY_BOOL nRet = XY_FALSE;
		try
		{
			bRet = tmpprx->cancelControlCamera(sKeyID);
		}
		catch (...)
		{
			char str[256] = {0};
			sprintf_s(str,"向流媒体请求停止控制云台出现异常.");
			NVSCoreBiz::WriteSysLog(str);
		}
		if(nRet == XY_TRUE)
			bRet = true;
	}
	return bRet;
}

//! 预置位
bool CStreamSourceAgent::TransPTZ(ServerInfo info,int nMonitorID, string sKeyID, int nCmd, int nTransPTZIndex)
{
	NVSStreamServiceAPIPrx tmpprx = GetPrx(info);
	if(tmpprx == NULL)
	{
		return false;		
	}

	char szLogInfo[256] = {0};
	char szConnect[256] = {0};
	GetKey(info,szConnect,sizeof(szConnect));
	if(XY_FALSE == m_mapLinkInfo[szConnect].ConFlag)
	{
		sprintf_s(szLogInfo,"流媒体心跳失败，无须进行继续操作！");
		NVSCoreBiz:: WriteSysLog(szLogInfo);
		return false;		
	}

	try
	{
		tmpprx->presetPTZ(sKeyID, nCmd, nTransPTZIndex);
		return true;
	}
	catch (...)
	{
		char str[256] = {0};
		sprintf_s(str,"向流媒体请求设置预置位出现异常.");
		NVSCoreBiz::WriteSysLog(str);
	}
	return false;
}
//! 获取通道参数（主码流、子码流视频参数）
bool CStreamSourceAgent::getCompress(ServerInfo info,int nMonitorID, string sKeyID, char **lpOutBuffer)
{
	NVSStreamServiceAPIPrx tmpprx = GetPrx(info);
	if(tmpprx == NULL)
	{
		return false;	
	}

	char szLogInfo[256] = {0};
	char szConnect[256] = {0};
	GetKey(info,szConnect,sizeof(szConnect));
	if(XY_FALSE == m_mapLinkInfo[szConnect].ConFlag)
	{
		sprintf_s(szLogInfo,"流媒体心跳失败，无须进行继续操作！");
		NVSCoreBiz:: WriteSysLog(szLogInfo);
		return false;		
	}

	try
	{
		std::string sCompressInfo;
		XY_BOOL bRet = tmpprx->getCompress(sKeyID,sCompressInfo);
		if(bRet == XY_TRUE)
		{
			sprintf_s((*lpOutBuffer),sizeof(sCompressInfo),"%s",sCompressInfo.c_str());
			return true;
		}
	}
	catch (...)
	{
		char str[256] = {0};
		sprintf_s(str,"向流媒体请求获取通道参数出现异常.");
		NVSCoreBiz::WriteSysLog(str);
	}
	return false;
}
//! 设置通道参数
bool CStreamSourceAgent::setCompress(ServerInfo info,int nMonitorID, string sKeyID, char* pCompressInfo)
{
	NVSStreamServiceAPIPrx tmpprx = GetPrx(info);
	if(tmpprx == NULL)
	{
		return false;		
	}

	char szLogInfo[256] = {0};
	char szConnect[256] = {0};
	GetKey(info,szConnect,sizeof(szConnect));
	if(XY_FALSE == m_mapLinkInfo[szConnect].ConFlag)
	{
		sprintf_s(szLogInfo,"流媒体心跳失败，无须进行继续操作！");
		NVSCoreBiz:: WriteSysLog(szLogInfo);
		return false;	
	}

	try
	{
		tmpprx->setCompress(sKeyID,pCompressInfo);
		return true;
	}
	catch (...)
	{
		char str[256] = {0};
		sprintf_s(str,"向流媒体请求设置通道参数出现异常.");
		NVSCoreBiz::WriteSysLog(str);
	}
	return false;
}
//! 获取视频参数（亮度、色度、饱和度等）
bool CStreamSourceAgent::getVideoEffect(ServerInfo info,int nMonitorID, string sKeyID, int* pBrightValue,int* pContrastValue, int* pSaturationValue,int* pHueValue)
{
	NVSStreamServiceAPIPrx tmpprx = GetPrx(info);
	if(tmpprx == NULL)
	{
		return false;	
	}

	char szLogInfo[256] = {0};
	char szConnect[256] = {0};
	GetKey(info,szConnect,sizeof(szConnect));
	if(XY_FALSE == m_mapLinkInfo[szConnect].ConFlag)
	{
		sprintf_s(szLogInfo,"流媒体心跳失败，无须进行继续操作！");
		NVSCoreBiz:: WriteSysLog(szLogInfo);
		return false;		
	}

	bool bOK = false;
	try
	{
		int pB1,pC1,pS1,pH1;
		XY_BOOL bRet = tmpprx->getVideoEffect(sKeyID,pB1,pC1,pS1,pH1);
		if(bRet == XY_TRUE)
		{
			*pBrightValue = pB1;
			*pContrastValue = pC1;
			*pSaturationValue = pS1;
			*pHueValue = pH1;
			bOK = true;
		}
	}
	catch (...)
	{
		char str[256] = {0};
		sprintf_s(str,"向流媒体获取视频参数出现异常.");
		NVSCoreBiz::WriteSysLog(str);
	}
	return bOK;
}
//! 设置视频参数
bool CStreamSourceAgent::setVideoEffect(ServerInfo info,int nMonitorID, string sKeyID, DWORD dwBrightValue,DWORD dwContrastValue, DWORD dwSaturationValue,DWORD dwHueValue)
{
	NVSStreamServiceAPIPrx tmpprx = GetPrx(info);
	if(tmpprx == NULL)
	{
		return false;	
	}

	char szLogInfo[256] = {0};
	char szConnect[256] = {0};
	GetKey(info,szConnect,sizeof(szConnect));
	if(XY_FALSE == m_mapLinkInfo[szConnect].ConFlag)
	{
		sprintf_s(szLogInfo,"流媒体心跳失败，无须进行继续操作！");
		NVSCoreBiz:: WriteSysLog(szLogInfo);
		return false;		
	}

	try
	{
		tmpprx->setVideoEffect(sKeyID,dwBrightValue,dwContrastValue,dwSaturationValue,dwHueValue);
		return true;
	}
	catch (...)
	{
		char str[256] = {0};
		sprintf_s(str,"向流媒体请求设置视频参数出现异常.");
		NVSCoreBiz::WriteSysLog(str);
	}
	return false;
}
bool  CStreamSourceAgent::getWorkState(ServerInfo info,NVSStreamService::WorkState &wkState)
{
	bool bRet = true;
	NVSStreamServiceAPIPrx tmpprx = GetPrx(info);
	if(tmpprx == NULL)
	{
		return false;		
	}

	char szLogInfo[256] = {0};
	char szConnect[256] = {0};
	GetKey(info,szConnect,sizeof(szConnect));
	if(XY_FALSE == m_mapLinkInfo[szConnect].ConFlag)
	{
		sprintf_s(szLogInfo,"流媒体心跳失败，无须进行继续操作！");
		NVSCoreBiz:: WriteSysLog(szLogInfo);
		return false;		
	}

	try
	{
		tmpprx->getWorkState(wkState);
		bRet = true;
	}
	catch (...) 
	{
		char str[256] = {0};
		sprintf_s(str,"向流媒体请求获取流媒体状态参数出现异常.");
		NVSCoreBiz::WriteSysLog(str);
	}
	return bRet;
}
//关联流媒体咨询台逻辑操作 begin
CSourceSvrInfomation * CStreamSourceAgent::GetSvrInfomation(ServerInfo info)
{
	char szConnect[256] = {0};
	GetKey(info,szConnect,sizeof(szConnect));
	//连接
	int nRet = GL_StreamHandlerManager.getStreamLoginIdentify((char *)info.strIp.c_str(),info.nPort,"","",info);
	int i = 0;
	while(nRet == INFO_WAIT_LOGIN)
	{
		nRet = GL_StreamHandlerManager.getStreamLoginIdentify((char *)info.strIp.c_str(),info.nPort,"","",info);
		Sleep(1000);
		if(i >= 3)
			break;
		i++;
	}

	EnterCriticalSection(&m_ConLock);
	if(m_mapSvrInfomation.count(szConnect) != 0)
	{
		LeaveCriticalSection(&m_ConLock);
		return m_mapSvrInfomation[szConnect];
	}
	else
	{
		CSourceSvrInfomation  *pInfomation = new CSourceSvrInfomation(info);
		m_mapSvrInfomation[szConnect] = pInfomation;
	}
	LeaveCriticalSection(&m_ConLock);
	
	return m_mapSvrInfomation[szConnect];
}
int  CStreamSourceAgent::ClearAllSvrInfomation()
{
	EnterCriticalSection(&m_ConLock);
	map<string,CSourceSvrInfomation *>::iterator itFind = m_mapSvrInfomation.begin();
	for(;itFind != m_mapSvrInfomation.end();)
	{
		CSourceSvrInfomation *pInfo = (*itFind).second;
		int nRet = pInfo->CleanAllProcessInfo();
		if(nRet == 0)
		{
			delete pInfo;
			itFind = m_mapSvrInfomation.erase(itFind);
		}
		else
		{
			itFind++;
		}
	}
	LeaveCriticalSection(&m_ConLock);
	return 0;
}
//关联流媒体咨询台逻辑操作 end