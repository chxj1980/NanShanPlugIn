#include "StdAfx.h"
#include "HSVideoProcess.h"
#include "NVSCoreBiz.h"

extern NVSCoreBiz GL_CoreBiz;

CHSVideoProcess::CHSVideoProcess(void)
{
	//m_lPlayHandle = 0;
	m_playWinNum = 0; 
	m_bIsSetWin = false;
}

CHSVideoProcess::~CHSVideoProcess(void)
{

}


BOOL CHSVideoProcess::InitHSServer(string sUser, string sPasswrod)
{
	return TRUE;
}

//设置播放窗口
BOOL CHSVideoProcess::SetPlayWindow( HWND palyWindow[], int nMaxCount)
{
	for (int i=0; i<MAXPLAYWINDOW && i<nMaxCount; i++)
	{
		m_palyWindow[i] = palyWindow[i];
	}
	m_playWinNum = nMaxCount;
	return TRUE;
}


void CHSVideoProcess::AddHSDvr(NVSIndex::NVSDVRInfo &nvsDvrInfo)
{
	m_vetorDvrInfo.push_back(nvsDvrInfo);
}

BOOL CHSVideoProcess::FindPlayInfo(int nCameraID, PlayInfo &playInfo)
{
	NVSDVRInfoType::iterator it = m_vetorDvrInfo.begin();
	for (; it!=m_vetorDvrInfo.end(); it++)
	{
		::NVSIndex::NVSCameraPool::iterator itCamera = (*it).CameraPool.begin();
		for (; itCamera!=(*it).CameraPool.end(); itCamera++)
		{
			if (nCameraID == (*itCamera).CameraID)
			{
				playInfo.nHSCameraID = (*itCamera).ChannelID;
				playInfo.strDvrIP = (*it).IP;
				playInfo.nPort = (*it).Port;
				playInfo.nCameraID = nCameraID;
				playInfo.sCameraCode = (*itCamera).ChannelNO;
				
				NVSCoreBiz:: WriteSysLog("找到本地镜头信息");
				return TRUE;
			}
		}
	}
	//NVSCoreBiz:: WriteSysLog("找不到本地镜头信息");
	return FALSE;
}

BOOL CHSVideoProcess::ConvertToPlayInfo(int nCameraID, NVSIndex::NVSDVRInfo &nvsDvrInfo, PlayInfo &playInfo)
{
	
	//只处理华三DVR
	/*const int DVR_HS = 8 ;
	if (nvsDvrInfo.DVRType != DVR_HS)
	{
		return FALSE;	
	}*/

	::NVSIndex::NVSCameraPool::iterator it = nvsDvrInfo.CameraPool.begin();
	for (; it!=nvsDvrInfo.CameraPool.end(); it++)
	{
		if (nCameraID == (*it).CameraID)
		{
			playInfo.nHSCameraID = (*it).ChannelID;
			playInfo.strDvrIP = nvsDvrInfo.IP;
			playInfo.nPort = nvsDvrInfo.Port;
			playInfo.sCameraCode = (*it).ChannelNO;
			//NVSCoreBiz:: WriteSysLog("转换镜头信息成功");
			return TRUE;
		}
	}
	//NVSCoreBiz:: WriteSysLog("转换镜头信息失败");
	return FALSE;
}

BOOL CHSVideoProcess::GetHSUser(int nCameraID,string &sUser, string &sPassWord)
{
	char strLog[256]={0};

	NVSDVRInfoType::iterator it = m_vetorDvrInfo.begin();
	for (;it!=m_vetorDvrInfo.end();it++)
	{
		::NVSIndex::NVSCameraPool::iterator itCamera = (*it).CameraPool.begin();
		for(;itCamera != (*it).CameraPool.end();itCamera++)
		{
			if ((*itCamera).CameraID == nCameraID)
			{
				sUser = (*it).UserName ;
				sPassWord = (*it).UserPwd ;
				//sprintf_s(strLog, sizeof(strLog), "华三用户名:%s, 华三用户密码:%s", sUser.c_str(), sPassWord.c_str());
				//NVSCoreBiz:: WriteSysLog(strLog);
				return TRUE;
			}
		}

	}
	NVSCoreBiz:: WriteSysLog("获取华三用户失败");
	return FALSE;
}


void CHSVideoProcess::ReleaseHSUser(string &sUser)
{

}

void  CHSVideoProcess::DrawFunCallBack(intptr_t  identify, intptr_t lRealHandle, DWORD hdc, void *pUser)
{
	
	if(!pUser) return ;
	CHSVideoProcess *pVideoProcess = (CHSVideoProcess *)(pUser);
	if (GL_CoreBiz.m_pDrawCB)
	{
		int nCameraId = 0;
		for (int i=0; i<(int)pVideoProcess->m_vetorPlayCamera.size(); i++)
		{
			if (pVideoProcess->m_vetorPlayCamera[i].lPlayHandle == lRealHandle)
			{
				nCameraId = pVideoProcess->m_vetorPlayCamera[i].nCameraID;
				break;
			}
		}
		if (hdc == 400)
		{
			char szErrMsg[1024] = {0};
			sprintf_s(szErrMsg, "播放回调:播放句柄[%d][%lld],CameraId[%d],ErrorCode[%d]", identify, lRealHandle, nCameraId, (int)identify);
			NVSCoreBiz:: WriteSysLog(szErrMsg);
			GL_CoreBiz.m_pPlayCallBack(nCameraId,(int)identify);
		}
		else
		{
			//NVSCoreBiz:: WriteSysLog("画图回调");
			GL_CoreBiz.m_pDrawCB(lRealHandle, hdc, nCameraId);
		}
	}
}

int  CHSVideoProcess::PlayHSVideo(NVSIndex::NVSIndex4MonitorPrx NVSIndex4MonitorPrx, int nCameraID, bool bUseDecode, HWND hWnd,::NVSIndex::NVSDVRInfo _DVRINFO)
{
	//::NVSIndex::NVSDVRInfo nvsDvrInfo;
	PlayInfo playInfo;
	bool bRet = false;
	int bReturn =  0;  //返回值
	
	char strLog[256]={0};

	//检查华三缓冲,是否为华三镜头
	
	if (FALSE == FindPlayInfo(nCameraID,playInfo))
	{
		
		//2 查找获取镜头-设备信息
		if (!ConvertToPlayInfo(nCameraID, _DVRINFO, playInfo)) 
		{
			sprintf_s(strLog, sizeof(strLog), "-190 镜头关联DVR存在,但获取设备信息失败");
			NVSCoreBiz:: WriteSysLog(strLog);
			return XY_REQ_INDEX_NOT_FIND_DVRPARA;	//-190 镜头关联DVR存在,但获取设备信息失败
		}
		AddHSDvr(_DVRINFO);	//AddHSDvr(nvsDvrInfo);
	}
	
	string sUser, sPassWord;
	if (GetHSUser(nCameraID,sUser, sPassWord))
	{

		string sDLLKey = _DVRINFO.DVRTypeKey;
//#ifdef _DEBUG
//		sDLLKey += "PlugInd.dll";
//#else
//		sDLLKey += "PlugIn.dll";
//#endif
		sprintf_s(strLog, sizeof(strLog), "connectDvr IP=[%s], port=[%d], user=[%s], pass=[%s], dll=[%s]",
				(char*)playInfo.strDvrIP.c_str(), playInfo.nPort, (char *)sUser.c_str(), (char *)sPassWord.c_str(),  (char *)sDLLKey.c_str());
		NVSCoreBiz:: WriteSysLog(strLog);

		BOOL bRe = FALSE;
		intptr_t lPlayHandle = connectDVR((char*)playInfo.strDvrIP.c_str(), playInfo.nPort, (char *)sUser.c_str(), (char *)sPassWord.c_str(), 1, (char *)sDLLKey.c_str(),bRe);
		if (bRe == FALSE)
		{
			NVSCoreBiz:: WriteSysLog("Error:登平台陆系统失败!");
			return (int)lPlayHandle; //登陆失败(错误值0--9)
		}
		
		setPlayWindow(lPlayHandle, m_palyWindow, m_playWinNum);
		m_bIsSetWin = true;

		string sCameraNo("");
		try
		{
			sCameraNo = NVSIndex4MonitorPrx->ConvertCameraID(nCameraID);
		}
		catch (...)
		{
			NVSCoreBiz:: WriteSysLog("ConvertCameraID(): 获取统一编码异常!");	
			disconnectDVR(lPlayHandle);

			return XY_REQ_INDEX_FALSE_GETCHACODE; //2011-7-28 获取镜头统一编码异常,取消播放 原值0; 
		}

		//2011-7-28 调用统一接口层，设置镜头编码
		setCurrentCameraCode(lPlayHandle, (LPSTR)(LPCTSTR)sCameraNo.c_str());

		char strLog[1024]={0};
		sprintf_s(strLog, "句柄[%lld]镜头[%d]setCurrentCameraCode = %s", lPlayHandle, nCameraID, sCameraNo.c_str());
		NVSCoreBiz::WriteSysLog(strLog);

		//2011-7-28 开始根据镜头编码播放视频
		playInfo.nCameraID = nCameraID;
		playInfo.lPlayHandle = lPlayHandle;
		playInfo.hWnd = hWnd;
		m_vetorPlayCamera.push_back(playInfo);
		bool bPaly = false;
		//解码后回调
		if (bUseDecode)
		{
			NVSCoreBiz::WriteSysLog("startPlayer4Standard");
			if(m_pRealDecodeCallBack != NULL)
			{
				if (GL_CoreBiz.m_pDrawCB)
				{
					startPlayer2(lPlayHandle,hWnd,DrawFunCallBack,this);
				}
				bPaly = startPlayer4Standard(lPlayHandle , NULL, m_pRealDecodeCallBack ,/*playInfo.nHSCameraID*/nCameraID);
			}
		}
		else
		{
			NVSCoreBiz::WriteSysLog("startPlayerByCamera");
			if (GL_CoreBiz.m_pDrawCB)
			{
				//NVSCoreBiz::WriteSysLog("setDrawFunCallBack");
				startPlayer2(lPlayHandle,hWnd,DrawFunCallBack,this);
			}
			bPaly = startPlayerByCamera(lPlayHandle , hWnd, /*playInfo.nHSCameraID*/nCameraID);
		}
		if (!bPaly)
		{
			//NVSCoreBiz::WriteSysLog("startPlayerByCamera失败");
			disconnectDVR(lPlayHandle);
			
			return XY_PLAY_H3C_FAIL;		//2011-7-28 播放华三镜头失败	原值 return -11; //播放华三镜头失败
		}
	}
	else
	{
		return XY_REQ_INDEX_FALSE_GETHSUSER;  //2011-7-28 -192  //获取华三用户信息失败 return -13;//获取华三帐户失败
	}

	return XY_PLAY_SUCCESS;
}
void CHSVideoProcess::StopAllHSVideo()
{
	NVSCoreBiz::WriteSysLog("StopAllHSVideo");
	PalyCameraType::iterator it = m_vetorPlayCamera.begin();
	for (; it!=m_vetorPlayCamera.end(); it++)
	{
		char strLog[256]={0};
		sprintf_s(strLog, "hWnd =%p, nHsCameraID=%d",(*it).hWnd, /*(*it).nHSCameraID*/(*it).nCameraID);
		NVSCoreBiz::WriteSysLog(strLog);
		stopPlayerByCamera((*it).lPlayHandle, (*it).hWnd, /*(*it).nHSCameraID*/(*it).nCameraID);
		disconnectDVR((*it).lPlayHandle);
	}
	m_vetorPlayCamera.clear();
}

bool CHSVideoProcess::StopHSVideo(HWND hWnd, int nCameraID)
{
// 	if (m_lPlayHandle<=0)
// 	{
// 		return false;
// 	}
// 

	PalyCameraType::iterator it = m_vetorPlayCamera.begin();
	for (; it!=m_vetorPlayCamera.end(); it++)
	{
		if (nCameraID == (*it).nCameraID)
		{
			
			if(stopPlayerByCamera((*it).lPlayHandle, (*it).hWnd, /*(*it).nHSCameraID*/nCameraID))
			{
				disconnectDVR((*it).lPlayHandle);
				m_vetorPlayCamera.erase(it);
				return true;
			}else
				return false;
			
		}
	}
	return false;
}


bool CHSVideoProcess::ControlCameraSpeed(int nCameraID,int nCmd,bool bControl,int nSpeed)
{
	NVSCoreBiz::WriteSysLog("[CHSVideoProcess::ControlCameraSpeed] enter");
	PalyCameraType::iterator it = m_vetorPlayCamera.begin();
	for (; it!=m_vetorPlayCamera.end(); it++)
	{
		if (nCameraID == (*it).nCameraID)
		{
			NVSCoreBiz::WriteSysLog("[CHSVideoProcess::ControlCameraSpeed] come");
			return controlPTZSpeedWithChannel((*it).lPlayHandle,nCmd,bControl,nSpeed,(*it).nHSCameraID);
	
		}
	}
	return false;
}

bool CHSVideoProcess::TransPTZ(int nCameraID, int nCmd, int nTransPTZIndex)
{
	PalyCameraType::iterator it = m_vetorPlayCamera.begin();
	for (; it != m_vetorPlayCamera.end(); it++)
	{
		if (nCameraID == (*it).nCameraID)
		{
			return presetPTZWithChannel((*it).lPlayHandle, nCmd, nTransPTZIndex, (*it).nHSCameraID);
		}
	}
	return false;
}

bool CHSVideoProcess::StartRecord(int nCameraID, char *pFileName)
{
	PalyCameraType::iterator it = m_vetorPlayCamera.begin();
	for (; it!=m_vetorPlayCamera.end(); it++)
	{
		if (nCameraID == (*it).nCameraID)
		{
			NVSCoreBiz::WriteSysLog("[CHSVideoProcess::StartRecord] 平台视频");
			return ::startRecord((*it).lPlayHandle, pFileName);

		}
	}
	NVSCoreBiz::WriteSysLog("[CHSVideoProcess::StartRecord] 非平台视频");
	return false;
}
bool CHSVideoProcess::StopRecord(int nCameraID)
{
	PalyCameraType::iterator it = m_vetorPlayCamera.begin();
	for (; it!=m_vetorPlayCamera.end(); it++)
	{
		if (nCameraID == (*it).nCameraID)
		{
			return ::stopRecord((*it).lPlayHandle);

		}
	}
	return false;	
}
//捕获图片
bool CHSVideoProcess::capturePictureEx(int nCameraID , char* pFileName)
{
	
	PalyCameraType::iterator it = m_vetorPlayCamera.begin();
	for (; it!=m_vetorPlayCamera.end(); it++)
	{
		if (nCameraID == (*it).nCameraID)
		{	
			NVSCoreBiz::WriteSysLog("调用 capturePictureEx");
			return ::capturePictureEx((*it).lPlayHandle,pFileName);

		}
	}
	return false;

}
