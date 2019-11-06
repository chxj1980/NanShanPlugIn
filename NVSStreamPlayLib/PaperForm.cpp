#include "StdAfx.h"
#include "PaperForm.h"
extern NVSCoreBiz GL_CoreBiz;

map<int,HWNDINFO>  CPaperForm::m_cMapCAMInfo;
map<HWND,HWNDINFO> CPaperForm::m_cMapHInfo;
CRITICAL_SECTION CPaperForm::m_Lock_MapHInfo;

CPaperForm::CPaperForm(void)
{
	m_nCameraID = -1;
}

CPaperForm::~CPaperForm(void)
{

}

void CPaperForm::InitPaperFormS()
{
	::InitializeCriticalSection(&m_Lock_MapHInfo);
}

void CPaperForm::UnInitPaperFormS()
{
	::DeleteCriticalSection(&m_Lock_MapHInfo);
}

void CPaperForm::ClearAllSource()
{
	EnterCriticalSection(&m_Lock_MapHInfo);
	m_cMapHInfo.clear();
	LeaveCriticalSection(&m_Lock_MapHInfo);	
}

int	CPaperForm::UpdateCameraID(int nPriorID,int nSwitchID,string sCameraID)//更新镜头20121225
{
	EnterCriticalSection(&m_Lock_MapHInfo);
	map<HWND,HWNDINFO>::iterator it_Find;
	it_Find = m_cMapHInfo.begin();
	for(;it_Find != m_cMapHInfo.end();it_Find++)
	{
		if((*it_Find).second.nCameraID == nPriorID)
		{
		   (*it_Find).second.nCameraID = nSwitchID;
			break;
		}
	}
	if(it_Find == m_cMapHInfo.end())
	{
		LeaveCriticalSection(&m_Lock_MapHInfo);	
	}	return XY_FALSE;
	LeaveCriticalSection(&m_Lock_MapHInfo);	
	return XY_TRUE;
	
}

int CPaperForm::CheckHInfoExist(HWND hWnd,int &nCameraID,string &sCameraID)
{
	XY_BOOL nRet = XY_FALSE;
	if(hWnd != NULL)
	{
		EnterCriticalSection(&m_Lock_MapHInfo);
		if(m_cMapHInfo.count(hWnd) != 0)
		{
			nCameraID   = m_cMapHInfo[hWnd].nCameraID;
			sCameraID   = m_cMapHInfo[hWnd].sCameraID;
			m_hInfo		= m_cMapHInfo[hWnd];
			m_sServerInfo =  m_cMapHInfo[hWnd].svrinfo;
			nRet = XY_TRUE;
		}
		LeaveCriticalSection(&m_Lock_MapHInfo);
	}
	else
	{
		EnterCriticalSection(&m_Lock_MapHInfo);
		if(m_cMapCAMInfo.count(nCameraID) != 0)
		{
			nCameraID   = m_cMapCAMInfo[nCameraID].nCameraID;
			sCameraID   = m_cMapCAMInfo[nCameraID].sCameraID;
			m_hInfo		= m_cMapCAMInfo[nCameraID];
			m_sServerInfo =  m_cMapCAMInfo[nCameraID].svrinfo;
			nRet = XY_TRUE;
		}
		LeaveCriticalSection(&m_Lock_MapHInfo);	
	}
	return nRet;
}

int CPaperForm::ParaseParam(int nCameraID,string sCameraID,bool bIsExternalDvr,
							ServerInfo &svrInfo,::NVSStreamService::DeviceInfo &devinfo)
{
	int nRet = XY_TRUE;
	m_nCameraID = nCameraID;
	nRet = GetStreamSvrInfoByIndex(nCameraID,svrInfo);
	//if(XY_TRUE == nRet)
	//{
		string sstate = "获取镜头的设备信息成功!";
		nRet = GetCameraIDDevInfoByIndex(nCameraID,bIsExternalDvr,devinfo,sstate);
		GL_CoreBiz.WriteSysLog((char *)sstate.c_str());
	//}
	return nRet;
}

int CPaperForm::ParaseParam(int nCameraID,ServerInfo &svrInfo,::NVSStreamService::DeviceInfo &devinfo)
{
	bool bIsExternalDvr = false;
	int nRet = ParaseParam(nCameraID,"",bIsExternalDvr,svrInfo,devinfo);
	return nRet;	
}

int CPaperForm::PushParam(int nCameraID,string sCameraID,HWND hWnd,ServerInfo svrInfo)
{
	int nRet = XY_TRUE;
	EnterCriticalSection(&m_Lock_MapHInfo);
	HWNDINFO info;
	info.hwnd = hWnd;
	info.nCameraID = nCameraID;
	info.sCameraID = sCameraID;
	info.svrinfo   = svrInfo;
	if(hWnd != NULL)
	{
		m_cMapHInfo[hWnd] = info;		
	}
	else
	{
		m_cMapCAMInfo[nCameraID] = info;
	}
	LeaveCriticalSection(&m_Lock_MapHInfo);
	return nRet;
}
int CPaperForm::EraseParam(int nCameraID,string sCameraID,HWND hWnd)
{
	int nRet = XY_TRUE;
	if(hWnd != NULL)
	{
		EnterCriticalSection(&m_Lock_MapHInfo);
		m_cMapHInfo.erase(hWnd);
		LeaveCriticalSection(&m_Lock_MapHInfo);
	}
	else
	{
		EnterCriticalSection(&m_Lock_MapHInfo);
		m_cMapCAMInfo.erase(nCameraID);
		LeaveCriticalSection(&m_Lock_MapHInfo);	
	}
	return nRet;
}


int  CPaperForm::GetCameraIDDevInfoByIndex(int nCameraID,bool bIsExternalDvr,::NVSStreamService::DeviceInfo& SourceInfo,string &sState)
{
	if(!GL_CoreBiz.m_bRegisterOnIndex)
	{
		return XY_FAIL_DISCONNECT_INDEX;
	}	

	::NVSIndex::NVSDVRInfo dvrinfo;
	::NVSIndex::NVSDVRInfoEx dvrinfoEx;
	string sDLLKey;
	bool bRet = false;
	try
	{				
		if(bIsExternalDvr)
		{
			bRet = GL_CoreBiz.m_NVSIndex4StreamPrx->getDvrInfoEx(nCameraID,dvrinfoEx);	
		}
		else
		{
			bRet = GL_CoreBiz.m_NVSIndex4StreamPrx->getDvrInfo(nCameraID,dvrinfo);	
		}
		
		if(!bRet)
		{
			sState = "getDvrInfo 返回错误值";
			return XY_REQ_INDEX_NOT_FIND_DVRINFO;//镜头关联DVR不存在,检索镜头信息失败,请核对	//2011-7-28 修改
		}
		if(bIsExternalDvr)
			dvrinfo = dvrinfoEx.dvrinfo;
		sDLLKey = dvrinfo.DVRTypeKey;
		//pzm del 20130702
//#ifdef _DEBUG
//		sDLLKey += "PlugInd.dll";
//#else
//		sDLLKey += "PlugIn.dll";
//#endif
		//pzm del 20130702
		if(bIsExternalDvr)
		{   
			dvrinfo.IP			= dvrinfoEx.ExternalIP;
			dvrinfo.Port		= dvrinfoEx.ExternalPort;
		}
		SourceInfo.sType		= sDLLKey;
		SourceInfo.sIP			= dvrinfo.IP;
		SourceInfo.nPort		= dvrinfo.Port;
		SourceInfo.sUser		= dvrinfo.UserName;
		SourceInfo.sPassword = dvrinfo.UserPwd;
		SourceInfo.nChannel = -1;
		m_dvrinfo = dvrinfo;

		vector<::NVSIndex::NVSCameraInfo>::iterator it = dvrinfo.CameraPool.begin();
		for(;it != dvrinfo.CameraPool.end();++it)
		{
			if((*it).CameraID == nCameraID)
			{
				SourceInfo.nChannel = it->ChannelID;
				SourceInfo.sChannel = it->ChannelStrID;
				break;
			}
		}

		if(SourceInfo.nChannel == -1)
		{
			sState = "从索引服务查找镜头失败";
			return XY_REQ_STREAM_NOT_FIND_CHANNEL;
		}	
	}
	catch(Ice::Exception &ex)
	{
		string strerr  = "getDvrInfo 调用接口失败";
		strerr		  += ex.ice_name();
		sState		   = strerr;
		return XY_EXP_INDEX_GETDVRINFO;
	}		
	return XY_TRUE;
}

int  CPaperForm::GetStreamSvrInfoByIndex(int nCameraID,ServerInfo& SourceSvrInfo)
{
	int Ret = XY_TRUE;

	std::string sProxy;
	int nServiceKey = 0;

	bool bAccessSuccess = false;
	byte by_Ret ;

	char strLog[256];
	sprintf_s(strLog, sizeof(strLog),"请求:[镜头%d] 的流媒体地址_begin", nCameraID);
	GL_CoreBiz.WriteSysLog(strLog);

	if(!GL_CoreBiz.m_bRegisterOnIndex)
	{
		return XY_FAIL_DISCONNECT_INDEX;
	}	
	try
	{
		if (GL_CoreBiz.m_bIsExternalClient==false)
		{
			by_Ret = GL_CoreBiz.m_NVSIndex4MonitorPrx->getStreamService( GL_CoreBiz.m_Monitor.ID, nCameraID,sProxy,nServiceKey);
		}
		else
		{
			by_Ret = GL_CoreBiz.m_NVSIndex4MonitorPrx->getExternalStreamService( GL_CoreBiz.m_Monitor.ID,nCameraID,sProxy,nServiceKey);
		}
	}
	catch (...)
	{
		sprintf_s(strLog, sizeof(strLog),"请求:[镜头%d] 的流媒体地址_异常_end", nCameraID);
		GL_CoreBiz.WriteSysLog(strLog);
		return XY_EXP_INDEX_GETSTREAMINFO; //当网络断开时，与索引的代理会出错。防止程序崩溃。
	}

	Ret = by_Ret;
	if(by_Ret == 0)
	{
		bAccessSuccess = true;
		sprintf_s(strLog, sizeof(strLog),"请求:[镜头%d] 的流媒体地址成功_end", nCameraID);
		GL_CoreBiz.WriteSysLog(strLog);
		ParseSvrInfo(sProxy,SourceSvrInfo.strInterFace,SourceSvrInfo.strIp,SourceSvrInfo.nPort);
	}
	else
	{
		char str[256] ={0};

		switch(by_Ret)
		{
		case 1:
			Ret = XY_REQ_INDEX_NOT_FIND_DVRINFO; // XY_REQ_INDEX_NOT_FIND_CHANNEL;
			sprintf_s(str,"传入镜头所属DVR不存在,错误码[103]");
			break;
		case 4:
			Ret = XY_REQ_INDEX_NOT_FIND_STREAM;
			sprintf_s(str,"没有找到关联流媒体 ,错误码[104]");
			break;
		case 5:
			Ret = XY_REQ_INDEX_MAX_LOAD;
			sprintf_s(str,"对应流媒体已超负荷，连接已满,错误码[105]");
			break;
		case 6:
			Ret = XY_REQ_INDEX_NOT_FIND_GRADE;
			sprintf_s(str,"没有空闲在线级联流媒体,错误码[106]");
			break;
		case 7:
			Ret = XY_REQ_INDEX_NOT_QUERYVIS;
			sprintf_s(str,"请求切换VIS失败,错误码[107]");
			break;
		case 8:
			Ret = XY_REQ_INDEX_QUERY_TIMEOUT;
			sprintf_s(str, "请求镜头关联流媒体地址超时");
			break;
		default:
			Ret = XY_UNKNOWN;
			sprintf_s(str, sizeof(str), "未知,错误码[%d]", by_Ret);
			break;

		}
		sprintf_s(strLog, sizeof(strLog),"请求:[镜头%d] 的流媒体地址失败,原因[%s]_end", nCameraID, str);
		GL_CoreBiz.WriteSysLog(strLog);	
	}

	return Ret;
}

int  CPaperForm::ParseSvrInfo(string sIndexKey,string &sKey,string &sIp,int &nPort)
{
	string sFind(":tcp");
	int nEnd = (int)sIndexKey.find(sFind);
	if(nEnd > -1)
	{
		sKey = sIndexKey.substr(0,nEnd);
		sFind = ":tcp -h ";
		int nStart = (int)sIndexKey.find(sFind);
		nStart += (int)sFind.length();
		sFind = " -p ";
		nEnd = (int)sIndexKey.find(sFind);
		if(nStart > -1 && nEnd > nStart)
		{
			sIp = sIndexKey.substr(nStart,nEnd-nStart+1);
			nEnd += (int)sFind.length();
			string sPort = sIndexKey.substr(nEnd,sIndexKey.length()-nEnd+1);
			nPort = atoi(sPort.c_str());
		}
	}	
	return XY_TRUE;
}

int CPaperForm::GetDvrInfo(int nCameraID,::NVSIndex::NVSDVRInfo &dvrinfo)
{
	XY_BOOL nRet = XY_FALSE;
	::NVSStreamService::DeviceInfo devinfo;
	string sstate = "获取镜头的设备信息成功!";
	//nRet = GetCameraIDDevInfoByIndex(nCameraID,devinfo,sstate);
	nRet = XY_TRUE;
	dvrinfo = m_dvrinfo;
	return nRet;
}

int  CPaperForm::GetCheckedSvrInfo(ServerInfo& SourceSvrInfo,int nCameraID)
{
	XY_BOOL nRet = XY_FALSE;
	EnterCriticalSection(&m_Lock_MapHInfo);
	map<HWND,HWNDINFO>::iterator it_Find;
	it_Find = m_cMapHInfo.begin();
	for(;it_Find != m_cMapHInfo.end();it_Find++)
	{
		if((*it_Find).second.nCameraID == nCameraID)
		{
			if((*it_Find).second.svrinfo.nPort > 0 && (*it_Find).second.svrinfo.strIp.size() > 0)
			{
				SourceSvrInfo = (*it_Find).second.svrinfo;
				nRet = XY_TRUE;
			}
			break;
		}
	}
	if(it_Find == m_cMapHInfo.end())
	{
		if(m_cMapCAMInfo.count(nCameraID) != 0)
		{
			SourceSvrInfo = m_cMapCAMInfo[nCameraID].svrinfo;
			nRet = XY_TRUE;
		}	
	}
	LeaveCriticalSection(&m_Lock_MapHInfo);
	return nRet;
}