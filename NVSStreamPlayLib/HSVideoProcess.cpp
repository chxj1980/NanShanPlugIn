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

//���ò��Ŵ���
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
				
				NVSCoreBiz:: WriteSysLog("�ҵ����ؾ�ͷ��Ϣ");
				return TRUE;
			}
		}
	}
	//NVSCoreBiz:: WriteSysLog("�Ҳ������ؾ�ͷ��Ϣ");
	return FALSE;
}

BOOL CHSVideoProcess::ConvertToPlayInfo(int nCameraID, NVSIndex::NVSDVRInfo &nvsDvrInfo, PlayInfo &playInfo)
{
	
	//ֻ������DVR
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
			//NVSCoreBiz:: WriteSysLog("ת����ͷ��Ϣ�ɹ�");
			return TRUE;
		}
	}
	//NVSCoreBiz:: WriteSysLog("ת����ͷ��Ϣʧ��");
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
				//sprintf_s(strLog, sizeof(strLog), "�����û���:%s, �����û�����:%s", sUser.c_str(), sPassWord.c_str());
				//NVSCoreBiz:: WriteSysLog(strLog);
				return TRUE;
			}
		}

	}
	NVSCoreBiz:: WriteSysLog("��ȡ�����û�ʧ��");
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
			sprintf_s(szErrMsg, "���Żص�:���ž��[%d][%lld],CameraId[%d],ErrorCode[%d]", identify, lRealHandle, nCameraId, (int)identify);
			NVSCoreBiz:: WriteSysLog(szErrMsg);
			GL_CoreBiz.m_pPlayCallBack(nCameraId,(int)identify);
		}
		else
		{
			//NVSCoreBiz:: WriteSysLog("��ͼ�ص�");
			GL_CoreBiz.m_pDrawCB(lRealHandle, hdc, nCameraId);
		}
	}
}

int  CHSVideoProcess::PlayHSVideo(NVSIndex::NVSIndex4MonitorPrx NVSIndex4MonitorPrx, int nCameraID, bool bUseDecode, HWND hWnd,::NVSIndex::NVSDVRInfo _DVRINFO)
{
	//::NVSIndex::NVSDVRInfo nvsDvrInfo;
	PlayInfo playInfo;
	bool bRet = false;
	int bReturn =  0;  //����ֵ
	
	char strLog[256]={0};

	//��黪������,�Ƿ�Ϊ������ͷ
	
	if (FALSE == FindPlayInfo(nCameraID,playInfo))
	{
		
		//2 ���һ�ȡ��ͷ-�豸��Ϣ
		if (!ConvertToPlayInfo(nCameraID, _DVRINFO, playInfo)) 
		{
			sprintf_s(strLog, sizeof(strLog), "-190 ��ͷ����DVR����,����ȡ�豸��Ϣʧ��");
			NVSCoreBiz:: WriteSysLog(strLog);
			return XY_REQ_INDEX_NOT_FIND_DVRPARA;	//-190 ��ͷ����DVR����,����ȡ�豸��Ϣʧ��
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
			NVSCoreBiz:: WriteSysLog("Error:��ƽ̨½ϵͳʧ��!");
			return (int)lPlayHandle; //��½ʧ��(����ֵ0--9)
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
			NVSCoreBiz:: WriteSysLog("ConvertCameraID(): ��ȡͳһ�����쳣!");	
			disconnectDVR(lPlayHandle);

			return XY_REQ_INDEX_FALSE_GETCHACODE; //2011-7-28 ��ȡ��ͷͳһ�����쳣,ȡ������ ԭֵ0; 
		}

		//2011-7-28 ����ͳһ�ӿڲ㣬���þ�ͷ����
		setCurrentCameraCode(lPlayHandle, (LPSTR)(LPCTSTR)sCameraNo.c_str());

		char strLog[1024]={0};
		sprintf_s(strLog, "���[%lld]��ͷ[%d]setCurrentCameraCode = %s", lPlayHandle, nCameraID, sCameraNo.c_str());
		NVSCoreBiz::WriteSysLog(strLog);

		//2011-7-28 ��ʼ���ݾ�ͷ���벥����Ƶ
		playInfo.nCameraID = nCameraID;
		playInfo.lPlayHandle = lPlayHandle;
		playInfo.hWnd = hWnd;
		m_vetorPlayCamera.push_back(playInfo);
		bool bPaly = false;
		//�����ص�
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
			//NVSCoreBiz::WriteSysLog("startPlayerByCameraʧ��");
			disconnectDVR(lPlayHandle);
			
			return XY_PLAY_H3C_FAIL;		//2011-7-28 ���Ż�����ͷʧ��	ԭֵ return -11; //���Ż�����ͷʧ��
		}
	}
	else
	{
		return XY_REQ_INDEX_FALSE_GETHSUSER;  //2011-7-28 -192  //��ȡ�����û���Ϣʧ�� return -13;//��ȡ�����ʻ�ʧ��
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
			NVSCoreBiz::WriteSysLog("[CHSVideoProcess::StartRecord] ƽ̨��Ƶ");
			return ::startRecord((*it).lPlayHandle, pFileName);

		}
	}
	NVSCoreBiz::WriteSysLog("[CHSVideoProcess::StartRecord] ��ƽ̨��Ƶ");
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
//����ͼƬ
bool CHSVideoProcess::capturePictureEx(int nCameraID , char* pFileName)
{
	
	PalyCameraType::iterator it = m_vetorPlayCamera.begin();
	for (; it!=m_vetorPlayCamera.end(); it++)
	{
		if (nCameraID == (*it).nCameraID)
		{	
			NVSCoreBiz::WriteSysLog("���� capturePictureEx");
			return ::capturePictureEx((*it).lPlayHandle,pFileName);

		}
	}
	return false;

}
