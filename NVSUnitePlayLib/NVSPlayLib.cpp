#include "StdAfx.h"
#include "NVSPlayLib.h"


//Windows version
NVSPlayLibWin::NVSPlayLibWin(void)
{

#ifdef _X_SIGHT //专用于XSight

	//#ifdef _DEBUG
	//	m_hDllWin = ::LoadLibrary("XSStreamPlayLibd.DLL");
	//#else
		m_hDllWin = ::LoadLibrary("XSStreamPlayLib.DLL");
	//#endif

#else

	//#ifdef _DEBUG
	//	m_hDllWin = ::LoadLibrary("NVSStreamPlayLibd.DLL");
	//#else
		m_hDllWin = ::LoadLibrary("NVSStreamPlayLib.DLL");
	//#endif
#endif

	if (m_hDllWin==nullptr) {
		char log[256] = { 0 };
		::_snprintf(log, sizeof(log),
			//#ifdef _DEBUG
			//"load XSStreamPlayLibd.dll err! %d\n"
			//#else
			"load XSStreamPlayLib.dll err! %d\n"
			//#endif
			, ::GetLastError()
		);
		OutputDebugString(log);
		//printf();
	}
	
	m_lp_nvs_initEnviroment = NULL;
	m_lp_nvs_cleanEnviroment = NULL;
	m_lp_nvs_registerOnIndex = NULL;
	m_lp_nvs_setPlayModel = NULL;
	m_lp_nvs_setDecordCardCallBack = NULL;
	m_lp_nvs_setRealPlayCallBack = NULL;
	m_lp_nvs_setRealDecodeCallBack = NULL;
	m_lp_nvs_setIndexNoticeCallBack = NULL;
	m_lp_nvs_setDVRNoticeCallBack = NULL;
	m_lp_nvs_playVideoByDecordCard = NULL;
	m_lp_nvs_playVideo = NULL;
	m_lp_nvs_playVideo2 = NULL;
	m_lp_nvs_stopPlayVideo = NULL;
	m_lp_nvs_stopPlayByCameraID = NULL;
	m_lp_nvs_stopAll = NULL;
	m_lp_nvs_controlCameraSpeed = NULL;
	m_lp_nvs_cancelControlCamera = NULL;
	m_lp_nvs_capturePictureEx = NULL;
	m_lp_nvs_TransPTZ = NULL;
	m_lp_nvs_getCompress = NULL;
	m_lp_nvs_setCompress = NULL;
	m_lp_nvs_getVideoEffect = NULL;
	m_lp_nvs_setVideoEffect = NULL;
	m_lp_nvs_startRecord = NULL;
	m_lp_nvs_stopRecord = NULL;
	m_lp_nvs_serialSend = NULL;
	m_lp_nvs_reSetDDrawDevice = NULL;
	m_lp_nvs_splitFile = NULL;
	m_lp_nvs_play4Storage = NULL;
	m_lp_nvs_stopPlay4Storage = NULL;
	m_lp_nvs_controlCameraSound = NULL;
	m_lp_nvs_clientNotice = NULL;
	m_lp_nvs_loginDVR = NULL;
	m_lp_nvs_logoutDVR = NULL;
	m_lp_nvs_playVideoByDVR = NULL;
	m_lp_nvs_stopPlayVideoByDVR = NULL;
	m_lp_nvs_controlCameraSpeedByDVR = NULL;
	m_lp_nvs_presetPTZByDVR = NULL;
	m_lp_nvs_getCameraInfo = NULL;
	m_lp_nvs_setPlayWindow = NULL;
	m_lp_nvs_getStreamServerWorkState = NULL;
	m_lp_nvs_getStreamServerIP = NULL;
	m_lp_nvs_SetExternalClient = NULL;
	m_lp_nvs_SetHsCallBack = NULL;
	m_lp_LPVedioHeadStreamCBFun = NULL;
	m_lp_LPVedioBodyStreamCBFun = NULL;
	m_lp_nvs_SetUserIDandOrgID = NULL;
	m_lp_nvs_setNoticeSwitchedCallBack = NULL;
	m_lp_nvs_SetDrawFun = NULL;
	m_lp_nvs_GetErrorMessage = NULL;
	m_lp_nvs_stdVideoinit = NULL;
	m_lp_nvs_playStdVideo = NULL;
	m_lp_nvs_stopStdVideo = NULL;
	m_lp_nvs_startPlayMonitor = NULL;
	m_lp_nvs_stopPlayMonitor  = NULL;

	m_lp_nvs_connectDVR  = NULL;
	m_lp_nvs_connectDVR  = NULL;
	m_lp_nvs_connectDVR  = NULL;
	m_lp_nvs_disconnectDVR  = NULL;
	m_lp_nvs_controlPTZSpeedWithChannel  = NULL;
	m_lp_nvs_presetPTZWithChannel  = NULL;
	m_lp_nvs_setVideoEffectByCode  = NULL;
	m_lp_nvs_getVideoEffectByCode  = NULL;
	m_lp_nvs_getDVRConfig  = NULL;
	m_lp_nvs_setDVRConfig  = NULL;
	m_lp_nvs_getRecordFileEx  = NULL;
	m_lp_nvs_downloadRecordFile  = NULL;
	m_lp_nvs_stopDownloadRecordFile  = NULL;
	m_lp_nvs_getDownloadPos  = NULL;
	m_lp_nvs_replayRecordFile  = NULL;
	m_lp_nvs_controlReplayRecordFile  = NULL;
	m_lp_nvs_stopReplayRecordFile  = NULL;
	m_lp_nvs_startTalk  = NULL;
	m_lp_nvs_stopTalk  = NULL;
	m_lp_nvs_getDVRWorkState  = NULL;
	m_lp_nvs_getLastError  = NULL;
	m_lp_nvs_playBackCaptureFile  = NULL;
	m_lp_nvs_playBackSaveData  = NULL;
	m_lp_nvs_stopPlayBackSave  = NULL;
	m_lp_nvs_startRecordByCode  = NULL;
	m_lp_nvs_stopRecordByCode  = NULL;
	m_lp_nvs_SetCropArea  = NULL;
	m_lp_nvs_SetDecodeParam  = NULL;
	m_lp_nvs_SetStreamSaveTime  = NULL;
	m_lp_nvs_PlayBackSaveStream  = NULL;
	m_lp_nvs_StopPlayBackSaveStream  = NULL;
	m_lp_nvs_SetRenderMode  = NULL;
	m_lp_nvs_SetPosByFrameNum  = NULL;
	m_lp_nvs_GetVideoCut  = NULL;
	m_lp_nvs_StopCutVideo  = NULL;
	m_lp_nvs_SetFileEndCallback  = NULL;
	m_lp_nvs_GetMediaInfo  = NULL;
	m_lp_nvs_GetDecodeParam  = NULL;
	m_lp_nvs_startPlayer4Standard  = NULL;
	m_lp_nvs_SetYUVCallBack  = NULL;
	m_lp_nvs_getRecordFileBySource  = NULL;
	m_lp_nvs_downloadRecordFileBySource  = NULL;
}

NVSPlayLibWin::~NVSPlayLibWin(void)
{
	if (m_hDllWin)
	{
		::FreeLibrary(m_hDllWin);
	}
}

bool NVSPlayLibWin::nvs_initEnviroment(const char* pAddress,unsigned short nPort,int nRight, char type)
{
	bool bRet = false;

	if (!m_hDllWin)	return false;
	
	if (!m_lp_nvs_initEnviroment)
	{
		m_lp_nvs_initEnviroment = (lp_nvs_initEnviroment)GetProcAddress(m_hDllWin,"nvs_initEnviroment");
	}
	if (!m_lp_nvs_initEnviroment) return false;
	
	bRet = m_lp_nvs_initEnviroment(pAddress,nPort,nRight,type);

	return bRet;
}

void NVSPlayLibWin::nvs_cleanEnviroment()
{
	if (!m_hDllWin)	return;

	if (!m_lp_nvs_cleanEnviroment)
	{
		m_lp_nvs_cleanEnviroment = (lp_nvs_cleanEnviroment)GetProcAddress(m_hDllWin,"nvs_cleanEnviroment");
	}
	if (!m_lp_nvs_cleanEnviroment) return;

	m_lp_nvs_cleanEnviroment();
}

bool NVSPlayLibWin::nvs_registerOnIndex()
{
	bool bRet = false;

	if (!m_hDllWin)	return false;

	if (!m_lp_nvs_registerOnIndex)
	{
		m_lp_nvs_registerOnIndex = (lp_nvs_registerOnIndex)GetProcAddress(m_hDllWin,"nvs_registerOnIndex");
	}
	if (!m_lp_nvs_registerOnIndex) return false;

	bRet = m_lp_nvs_registerOnIndex();

	return bRet;
}

void NVSPlayLibWin::nvs_setPlayModel(int nPlayModel)
{
	if (!m_hDllWin)	return;

	if (!m_lp_nvs_setPlayModel)
	{
		m_lp_nvs_setPlayModel = (lp_nvs_setPlayModel)GetProcAddress(m_hDllWin,"nvs_setPlayModel");
	}
	if (!m_lp_nvs_setPlayModel) return;

	m_lp_nvs_setPlayModel(nPlayModel);
}

void NVSPlayLibWin::nvs_setDecordCardCallBack(PlayResultByDecordCard pFun)
{
	if (!m_hDllWin)	return;

	if (!m_lp_nvs_setDecordCardCallBack)
	{
		m_lp_nvs_setDecordCardCallBack = (lp_nvs_setDecordCardCallBack)GetProcAddress(m_hDllWin,"nvs_setDecordCardCallBack");
	}
	if (!m_lp_nvs_setDecordCardCallBack) return;

	m_lp_nvs_setDecordCardCallBack(pFun);
}

void NVSPlayLibWin::nvs_setRealPlayCallBack(RealPlayCallBack pFun)
{
	if (!m_hDllWin)	return;

	if (!m_lp_nvs_setRealPlayCallBack)
	{
		m_lp_nvs_setRealPlayCallBack = (lp_nvs_setRealPlayCallBack)GetProcAddress(m_hDllWin,"nvs_setRealPlayCallBack");
	}
	if (!m_lp_nvs_setRealPlayCallBack) return;

	m_lp_nvs_setRealPlayCallBack(pFun);
}

void NVSPlayLibWin::nvs_setRealDecodeCallBack(LPDecCBFun pFun)
{
	if (!m_hDllWin)	return;

	if (!m_lp_nvs_setRealDecodeCallBack)
	{
		m_lp_nvs_setRealDecodeCallBack = (lp_nvs_setRealDecodeCallBack)GetProcAddress(m_hDllWin,"nvs_setRealDecodeCallBack");
	}
	if (!m_lp_nvs_setRealDecodeCallBack) return;

	m_lp_nvs_setRealDecodeCallBack(pFun);
}

void NVSPlayLibWin::nvs_setIndexNoticeCallBack(IndexNoticeCallBack pFun)
{
	if (!m_hDllWin)	return;

	if (!m_lp_nvs_setIndexNoticeCallBack)
	{
		m_lp_nvs_setIndexNoticeCallBack = (lp_nvs_setIndexNoticeCallBack)GetProcAddress(m_hDllWin,"nvs_setIndexNoticeCallBack");
	}
	if (!m_lp_nvs_setIndexNoticeCallBack) return;

	m_lp_nvs_setIndexNoticeCallBack(pFun);
}

void NVSPlayLibWin::nvs_setDVRNoticeCallBack(DVRNoticeCallBack pFun)
{
	if (!m_hDllWin)	return;

	if (!m_lp_nvs_setDVRNoticeCallBack)
	{
		m_lp_nvs_setDVRNoticeCallBack = (lp_nvs_setDVRNoticeCallBack)GetProcAddress(m_hDllWin,"nvs_setDVRNoticeCallBack");
	}
	if (!m_lp_nvs_setDVRNoticeCallBack) return;

	m_lp_nvs_setDVRNoticeCallBack(pFun);
}

int NVSPlayLibWin::nvs_playVideoByDecordCard(int nCameraID,int nCardIndex, HANDLE* hStreamPlayHandle)
{
	int nRet = -1;

	if (!m_hDllWin)	return -1;

	if (!m_lp_nvs_playVideoByDecordCard)
	{
		m_lp_nvs_playVideoByDecordCard = (lp_nvs_playVideoByDecordCard)GetProcAddress(m_hDllWin,"nvs_playVideoByDecordCard");
	}
	if (!m_lp_nvs_playVideoByDecordCard) return -1;

	nRet = m_lp_nvs_playVideoByDecordCard(nCameraID,nCardIndex,hStreamPlayHandle);

	return nRet;
}

int NVSPlayLibWin::nvs_playVideo2(int nCameraID,HWND hWnd, bool bUseDecode/*获取标准流标识*/, bool bIsExternalDvr)
{
	int nRet = -1;

	if (!m_hDllWin)	return -1;

	if (!m_lp_nvs_playVideo2)
	{
		m_lp_nvs_playVideo2 = (lp_nvs_playVideo2)GetProcAddress(m_hDllWin,"nvs_playVideo2");
	}
	if (!m_lp_nvs_playVideo2) return -1;

	nRet = m_lp_nvs_playVideo2(nCameraID,hWnd,bUseDecode,bIsExternalDvr);

	return nRet;
}
int NVSPlayLibWin::nvs_playVideo(int nCameraID,HWND hWnd, bool bUseDecode/*获取标准流标识*/)
{
	int nRet = -1;

	if (!m_hDllWin)	return -1;

	if (!m_lp_nvs_playVideo)
	{
		m_lp_nvs_playVideo = (lp_nvs_playVideo)GetProcAddress(m_hDllWin,"nvs_playVideo");
	}
	if (!m_lp_nvs_playVideo) return -1;

	nRet = m_lp_nvs_playVideo(nCameraID,hWnd,bUseDecode);

	return nRet;
}
bool NVSPlayLibWin::nvs_stopPlayVideo(HWND hWnd, int nCardIndex, int nCameraID)
{
	bool bRet = false;

	if (!m_hDllWin)	return false;

	if (!m_lp_nvs_stopPlayVideo)
	{
		m_lp_nvs_stopPlayVideo = (lp_nvs_stopPlayVideo)GetProcAddress(m_hDllWin,"nvs_stopPlayVideo");
	}
	if (!m_lp_nvs_stopPlayVideo) return false;

	bRet = m_lp_nvs_stopPlayVideo(hWnd,nCardIndex,nCameraID);

	return bRet;
}
bool NVSPlayLibWin::nvs_stopPlayByCameraID(int nCameraID)
{
	bool bRet = false;

	if (!m_hDllWin)	return false;

	if (!m_lp_nvs_stopPlayByCameraID)
	{
		m_lp_nvs_stopPlayByCameraID = (lp_nvs_stopPlayByCameraID)GetProcAddress(m_hDllWin,"nvs_stopPlayByCameraID");
	}
	if (!m_lp_nvs_stopPlayByCameraID) return false;

	bRet = m_lp_nvs_stopPlayByCameraID(nCameraID);

	return bRet;
}

void NVSPlayLibWin::nvs_stopAll()
{
	if (!m_hDllWin)	return;

	if (!m_lp_nvs_stopAll)
	{
		m_lp_nvs_stopAll = (lp_nvs_stopAll)GetProcAddress(m_hDllWin,"nvs_stopAll");
	}
	if (!m_lp_nvs_stopAll) return;

	m_lp_nvs_stopAll();
}

bool NVSPlayLibWin::nvs_controlCameraSpeed(int nCameraID,int nCmd,bool bControl,int nSpeed)
{
	bool bRet = false;

	if (!m_hDllWin)	
	{
		::MessageBoxA(NULL,"m_hDllWin fail","Cap",0);
		return false;
	}

	if (!m_lp_nvs_controlCameraSpeed)
	{
		m_lp_nvs_controlCameraSpeed = (lp_nvs_controlCameraSpeed)GetProcAddress(m_hDllWin,"nvs_controlCameraSpeed");
	}
	if (!m_lp_nvs_controlCameraSpeed) 
	{
		::MessageBoxA(NULL,"find nvs_controlCameraSpeed fail","Cap",0);
		return false;
	}

	bRet = m_lp_nvs_controlCameraSpeed(nCameraID,nCmd,bControl,nSpeed);

	return bRet;
}

bool NVSPlayLibWin::nvs_cancelControlCamera(HWND hWnd,int nCameraID)
{
	bool bRet = false;

	if (!m_hDllWin)	return false;

	if (!m_lp_nvs_cancelControlCamera)
	{
		m_lp_nvs_cancelControlCamera = (lp_nvs_cancelControlCamera)GetProcAddress(m_hDllWin,"nvs_cancelControlCamera");
	}
	if (!m_lp_nvs_cancelControlCamera) return false;

	bRet = m_lp_nvs_cancelControlCamera(hWnd,nCameraID);

	return bRet;
}

bool NVSPlayLibWin::nvs_capturePictureEx(int nCameraID, char* pFileName)
{
	bool bRet = false;

	if (!m_hDllWin)	return false;

	if (!m_lp_nvs_capturePictureEx)
	{
		m_lp_nvs_capturePictureEx = (lp_nvs_capturePictureEx)GetProcAddress(m_hDllWin,"nvs_capturePictureEx");
	}
	if (!m_lp_nvs_capturePictureEx) return false;

	bRet = m_lp_nvs_capturePictureEx(nCameraID,pFileName);

	return bRet;
}

bool NVSPlayLibWin::nvs_TransPTZ(int nCameraID, int nCmd, int nTransPTZIndex)
{
	bool bRet = false;

	if (!m_hDllWin)	return false;

	if (!m_lp_nvs_TransPTZ)
	{
		m_lp_nvs_TransPTZ = (lp_nvs_TransPTZ)GetProcAddress(m_hDllWin,"nvs_TransPTZ");
	}
	if (!m_lp_nvs_TransPTZ) return false;

	bRet = m_lp_nvs_TransPTZ(nCameraID,nCmd,nTransPTZIndex);

	return bRet;
}

bool NVSPlayLibWin::nvs_getCompress(int nCameraID, char **lpOutBuffer)
{
	bool bRet = false;

	if (!m_hDllWin)	return false;

	if (!m_lp_nvs_getCompress)
	{
		m_lp_nvs_getCompress = (lp_nvs_getCompress)GetProcAddress(m_hDllWin,"nvs_getCompress");
	}
	if (!m_lp_nvs_getCompress) return false;

	bRet = m_lp_nvs_getCompress(nCameraID,lpOutBuffer);

	return bRet;
}

bool NVSPlayLibWin::nvs_setCompress(int nCameraID, char* pCompressInfo)
{	
	bool bRet = false;

	if (!m_hDllWin)	return false;

	if (!m_lp_nvs_setCompress)
	{
		m_lp_nvs_setCompress = (lp_nvs_setCompress)GetProcAddress(m_hDllWin,"nvs_setCompress");
	}
	if (!m_lp_nvs_setCompress) return false;

	bRet = m_lp_nvs_setCompress(nCameraID,pCompressInfo);

	return bRet;
}

bool NVSPlayLibWin::nvs_getVideoEffect(int nCameraID, int* pBrightValue,int* pContrastValue, int* pSaturationValue,int* pHueValue)
{
	bool bRet = false;

	if (!m_hDllWin)	return false;

	if (!m_lp_nvs_getVideoEffect)
	{
		m_lp_nvs_getVideoEffect = (lp_nvs_getVideoEffect)GetProcAddress(m_hDllWin,"nvs_getVideoEffect");
	}
	if (!m_lp_nvs_getVideoEffect) return false;

	bRet = m_lp_nvs_getVideoEffect(nCameraID,pBrightValue,pContrastValue,pSaturationValue,pHueValue);

	return bRet;
}

bool NVSPlayLibWin::nvs_setVideoEffect(int nCameraID, DWORD dwBrightValue,DWORD dwContrastValue, DWORD dwSaturationValue,DWORD dwHueValue)
{
	bool bRet = false;

	if (!m_hDllWin)	return false;

	if (!m_lp_nvs_setVideoEffect)
	{
		m_lp_nvs_setVideoEffect = (lp_nvs_setVideoEffect)GetProcAddress(m_hDllWin,"nvs_setVideoEffect");
	}
	if (!m_lp_nvs_setVideoEffect) return false;

	bRet = m_lp_nvs_setVideoEffect(nCameraID,dwBrightValue,dwContrastValue,dwSaturationValue,dwHueValue);

	return bRet;
}

int NVSPlayLibWin::nvs_startRecord(int nCameraID, char* pFileName)
{
	int nRet = -1;

	if (!m_hDllWin)	return -1;

	if (!m_lp_nvs_startRecord)
	{
		m_lp_nvs_startRecord = (lp_nvs_startRecord)GetProcAddress(m_hDllWin,"nvs_startRecord");
	}
	if (!m_lp_nvs_startRecord) return -1;

	nRet = m_lp_nvs_startRecord(nCameraID,pFileName);

	return nRet;
}

bool NVSPlayLibWin::nvs_stopRecord(int nCameraID)
{
	bool bRet = false;

	if (!m_hDllWin)	return false;

	if (!m_lp_nvs_stopRecord)
	{
		m_lp_nvs_stopRecord = (lp_nvs_stopRecord)GetProcAddress(m_hDllWin,"nvs_stopRecord");
	}
	if (!m_lp_nvs_stopRecord) return false;

	bRet = m_lp_nvs_stopRecord(nCameraID);

	return bRet;
}

bool NVSPlayLibWin::nvs_serialSend(int nCameraID, char* cmd1, DWORD nLen1, char* cmd2, DWORD nLen2)
{
	bool bRet = false;

	if (!m_hDllWin)	return false;

	if (!m_lp_nvs_serialSend)
	{
		m_lp_nvs_serialSend = (lp_nvs_serialSend)GetProcAddress(m_hDllWin,"nvs_serialSend");
	}
	if (!m_lp_nvs_serialSend) return false;

	bRet = m_lp_nvs_serialSend(nCameraID,cmd1,nLen1,cmd2,nLen2);

	return bRet;
}

void NVSPlayLibWin::nvs_reSetDDrawDevice(int nCameraID)
{
	if (!m_hDllWin)	return;

	if (!m_lp_nvs_reSetDDrawDevice)
	{
		m_lp_nvs_reSetDDrawDevice = (lp_nvs_reSetDDrawDevice)GetProcAddress(m_hDllWin,"nvs_reSetDDrawDevice");
	}
	if (!m_lp_nvs_reSetDDrawDevice) return;

	m_lp_nvs_reSetDDrawDevice(nCameraID);
}

int NVSPlayLibWin::nvs_splitFile(int nCameraID,char* sFileName,int nPriorTime)
{
	int nRet = -1;

	if (!m_hDllWin)	return -1;

	if (!m_lp_nvs_splitFile)
	{
		m_lp_nvs_splitFile = (lp_nvs_splitFile)GetProcAddress(m_hDllWin,"nvs_splitFile");
	}
	if (!m_lp_nvs_splitFile) return -1;

	nRet = m_lp_nvs_splitFile(nCameraID,sFileName,nPriorTime);

	return nRet;
}

int NVSPlayLibWin::nvs_play4Storage(int nCameraID,char* sFileName,int nPriorTime)
{
	int nRet = -1;

	if (!m_hDllWin)	return -1;

	if (!m_lp_nvs_play4Storage)
	{
		m_lp_nvs_play4Storage = (lp_nvs_play4Storage)GetProcAddress(m_hDllWin,"nvs_play4Storage");
	}
	if (!m_lp_nvs_play4Storage) return -1;

	nRet = m_lp_nvs_play4Storage(nCameraID,sFileName,nPriorTime);

	return nRet;
}

bool NVSPlayLibWin::nvs_stopPlay4Storage(int nCameraID)
{
	bool bRet = false;

	if (!m_hDllWin)	return false;

	if (!m_lp_nvs_stopPlay4Storage)
	{
		m_lp_nvs_stopPlay4Storage = (lp_nvs_stopPlay4Storage)GetProcAddress(m_hDllWin,"nvs_stopPlay4Storage");
	}
	if (!m_lp_nvs_stopPlay4Storage) return false;

	bRet = m_lp_nvs_stopPlay4Storage(nCameraID);

	return bRet;
}

bool NVSPlayLibWin::nvs_controlCameraSound(int nCameraID, bool bOpenSound)
{
	bool bRet = false;

	if (!m_hDllWin)	return false;

	if (!m_lp_nvs_controlCameraSound)
	{
		m_lp_nvs_controlCameraSound = (lp_nvs_controlCameraSound)GetProcAddress(m_hDllWin,"nvs_controlCameraSound");
	}
	if (!m_lp_nvs_controlCameraSound) return false;

	bRet = m_lp_nvs_controlCameraSound(nCameraID,bOpenSound);

	return bRet;
}

bool NVSPlayLibWin::nvs_clientNotice()
{
	bool bRet = false;

	if (!m_hDllWin)	return false;

	if (!m_lp_nvs_clientNotice)
	{
		m_lp_nvs_clientNotice = (lp_nvs_clientNotice)GetProcAddress(m_hDllWin,"nvs_clientNotice");
	}
	if (!m_lp_nvs_clientNotice) return false;

	bRet = m_lp_nvs_clientNotice();

	return bRet;
}

intptr_t NVSPlayLibWin::nvs_loginDVR(char* sIP, int nPort, char* sUser, char* sPwd)
{
	intptr_t lRet = -1;

	if (!m_hDllWin)	return -1;

	if (!m_lp_nvs_loginDVR)
	{
		m_lp_nvs_loginDVR = (lp_nvs_loginDVR)GetProcAddress(m_hDllWin,"nvs_loginDVR");
	}
	if (!m_lp_nvs_loginDVR) return -1;

	lRet = m_lp_nvs_loginDVR(sIP,nPort,sUser,sPwd);

	return lRet;
}

void NVSPlayLibWin::nvs_logoutDVR(intptr_t identify)
{
	if (!m_hDllWin)	return;

	if (!m_lp_nvs_logoutDVR)
	{
		m_lp_nvs_logoutDVR = (lp_nvs_logoutDVR)GetProcAddress(m_hDllWin,"nvs_logoutDVR");
	}
	if (!m_lp_nvs_logoutDVR) return;

	m_lp_nvs_logoutDVR(identify);
}

bool NVSPlayLibWin::nvs_playVideoByDVR(intptr_t identify,int nCameraID,HWND hWnd)
{
	bool bRet = false;

	if (!m_hDllWin)	return false;

	if (!m_lp_nvs_playVideoByDVR)
	{
		m_lp_nvs_playVideoByDVR = (lp_nvs_playVideoByDVR)GetProcAddress(m_hDllWin,"nvs_playVideoByDVR");
	}
	if (!m_lp_nvs_playVideoByDVR) return false;

	bRet = m_lp_nvs_playVideoByDVR(identify,nCameraID,hWnd);

	return bRet;
}

bool NVSPlayLibWin::nvs_stopPlayVideoByDVR(intptr_t identify,HWND hWnd)
{
	bool bRet = false;

	if (!m_hDllWin)	return false;

	if (!m_lp_nvs_stopPlayVideoByDVR)
	{
		m_lp_nvs_stopPlayVideoByDVR = (lp_nvs_stopPlayVideoByDVR)GetProcAddress(m_hDllWin,"nvs_stopPlayVideoByDVR");
	}
	if (!m_lp_nvs_stopPlayVideoByDVR) return false;

	bRet = m_lp_nvs_stopPlayVideoByDVR(identify,hWnd);

	return bRet;
}

bool NVSPlayLibWin::nvs_controlCameraSpeedByDVR(intptr_t identify,int nCameraID,int nCmd,bool bControl,int nSpeed,int nChannel)
{
	bool bRet = false;

	if (!m_hDllWin)	return false;

	if (!m_lp_nvs_controlCameraSpeedByDVR)
	{
		m_lp_nvs_controlCameraSpeedByDVR = (lp_nvs_controlCameraSpeedByDVR)GetProcAddress(m_hDllWin,"nvs_controlCameraSpeedByDVR");
	}
	if (!m_lp_nvs_controlCameraSpeedByDVR) return false;

	bRet = m_lp_nvs_controlCameraSpeedByDVR(identify,nCameraID,nCmd,bControl,nSpeed,nChannel);

	return bRet;
}

bool NVSPlayLibWin::nvs_presetPTZByDVR(intptr_t identify,int nCameraID, int nCmd, int nTransPTZIndex, int nChannel)
{
	bool bRet = false;

	if (!m_hDllWin)	return false;

	if (!m_lp_nvs_presetPTZByDVR)
	{
		m_lp_nvs_presetPTZByDVR = (lp_nvs_presetPTZByDVR)GetProcAddress(m_hDllWin,"nvs_presetPTZByDVR");
	}
	if (!m_lp_nvs_presetPTZByDVR) return false;

	bRet = m_lp_nvs_presetPTZByDVR(identify,nCameraID,nCmd,nTransPTZIndex,nChannel);

	return bRet;
}

intptr_t NVSPlayLibWin::nvs_getCameraInfo(intptr_t identify,int *nSize)
{
	intptr_t lRet = -1;

	if (!m_hDllWin)	return -1;

	if (!m_lp_nvs_getCameraInfo)
	{
		m_lp_nvs_getCameraInfo = (lp_nvs_getCameraInfo)GetProcAddress(m_hDllWin,"nvs_getCameraInfo");
	}
	if (!m_lp_nvs_getCameraInfo) return -1;

	lRet = m_lp_nvs_getCameraInfo(identify,nSize);

	return lRet;
}

int NVSPlayLibWin::nvs_setPlayWindow(HWND palyWindow[], int nMaxCount)
{
	int nRet = -1;

	if (!m_hDllWin)	return -1;

	if (!m_lp_nvs_setPlayWindow)
	{
		m_lp_nvs_setPlayWindow = (lp_nvs_setPlayWindow)GetProcAddress(m_hDllWin,"nvs_setPlayWindow");
	}
	if (!m_lp_nvs_setPlayWindow) return -1;

	nRet = m_lp_nvs_setPlayWindow(palyWindow,nMaxCount);

	return nRet;
}

intptr_t NVSPlayLibWin::nvs_getStreamServerWorkState(int nCameraID, int nCameraCount, int *outSize )
{
	intptr_t lRet = -1;

	if (!m_hDllWin)	return -1;

	if (!m_lp_nvs_getStreamServerWorkState)
	{
		m_lp_nvs_getStreamServerWorkState = (lp_nvs_getStreamServerWorkState)GetProcAddress(m_hDllWin,"nvs_getStreamServerWorkState");
	}
	if (!m_lp_nvs_getStreamServerWorkState) return -1;

	lRet = m_lp_nvs_getStreamServerWorkState(nCameraID,nCameraCount,outSize);

	return lRet;
}

char* NVSPlayLibWin::nvs_getStreamServerIP( int nCameraID)
{
	if (!m_hDllWin)	return NULL;

	if (!m_lp_nvs_getStreamServerIP)
	{
		m_lp_nvs_getStreamServerIP = (lp_nvs_getStreamServerIP)GetProcAddress(m_hDllWin,"nvs_getStreamServerIP");
	}
	if (!m_lp_nvs_getStreamServerIP) return NULL;

	return m_lp_nvs_getStreamServerIP(nCameraID);
}

void NVSPlayLibWin::nvs_SetExternalClient(bool bIsExternal)
{
	if (!m_hDllWin)	return ;

	if (!m_lp_nvs_SetExternalClient)
	{
		m_lp_nvs_SetExternalClient = (lp_nvs_SetExternalClient)GetProcAddress(m_hDllWin,"nvs_SetExternalClient");
	}
	if (!m_lp_nvs_SetExternalClient) return;

	m_lp_nvs_SetExternalClient(bIsExternal);
}

void NVSPlayLibWin::nvs_writeLog(char* logMsg, int level)
{
	if (!m_hDllWin)	return ;

	if (!m_lp_nvs_writeLog)
	{
		m_lp_nvs_writeLog = (lp_nvs_writeLog)GetProcAddress(m_hDllWin,"nvs_writeLog");
	}
	if (!m_lp_nvs_writeLog) return;

	m_lp_nvs_writeLog(logMsg,level);
}

bool NVSPlayLibWin::nvs_InitHSServer(char *strIP, int nPort)
{
	bool bRet = false;

	if (!m_hDllWin)	return false;

	if (!m_lp_nvs_InitHSServer)
	{
		m_lp_nvs_InitHSServer = (lp_nvs_InitHSServer)GetProcAddress(m_hDllWin,"nvs_InitHSServer");
	}
	if (!m_lp_nvs_InitHSServer) return false;

	bRet = m_lp_nvs_InitHSServer(strIP,nPort);

	return bRet;
}

void NVSPlayLibWin::nvs_SetHsCallBack(HsUserCallBack CallbackFun)
{
	if (!m_hDllWin)	return ;

	if (!m_lp_nvs_SetHsCallBack)
	{
		m_lp_nvs_SetHsCallBack = (lp_nvs_SetHsCallBack)GetProcAddress(m_hDllWin,"nvs_SetHsCallBack");
	}
	if (!m_lp_nvs_SetHsCallBack) return;

	m_lp_nvs_SetHsCallBack(CallbackFun);
}

void NVSPlayLibWin::nvs_SetVedioHeadStreamCallBack(LPVedioHeadStreamCBFun pFun)
{
	if (!m_hDllWin) return;

	if (!m_lp_LPVedioHeadStreamCBFun)
	{
		m_lp_LPVedioHeadStreamCBFun = (lp_LPVedioHeadStreamCBFun)GetProcAddress(m_hDllWin,"nvs_SetVedioHeadStreamCallBack");
	}
	if (!m_lp_LPVedioHeadStreamCBFun) return;

	m_lp_LPVedioHeadStreamCBFun(pFun);
}

void NVSPlayLibWin::nvs_SetVedioBodyStreamCallBack(LPVedioBodyStreamCBFun pFun)
{
	if (!m_hDllWin) return;

	if (!m_lp_LPVedioBodyStreamCBFun)
	{
		m_lp_LPVedioBodyStreamCBFun = (lp_LPVedioBodyStreamCBFun)GetProcAddress(m_hDllWin,"nvs_SetVedioBodyStreamCallBack");
	}
	if (!m_lp_LPVedioBodyStreamCBFun) return;

	m_lp_LPVedioBodyStreamCBFun(pFun);
}

void NVSPlayLibWin::nvs_SetUserIDandOrgID(int nUserID,int OrgID)
{
	if (!m_hDllWin)	return ;

	if (!m_lp_nvs_SetUserIDandOrgID)
	{
		m_lp_nvs_SetUserIDandOrgID = (lp_nvs_SetUserIDandOrgID)GetProcAddress(m_hDllWin,"nvs_SetUserIDandOrgID");
	}
	if (!m_lp_nvs_SetUserIDandOrgID) return;

	m_lp_nvs_SetUserIDandOrgID(nUserID,OrgID);
}

void NVSPlayLibWin::nvs_setNoticeSwitchedCallBack(NoticeSwitchedCallBack pFun)
{
	if (!m_hDllWin)	return ;

	if (!m_lp_nvs_setNoticeSwitchedCallBack)
	{
		m_lp_nvs_setNoticeSwitchedCallBack = (lp_nvs_setNoticeSwitchedCallBack)GetProcAddress(m_hDllWin,"nvs_setNoticeSwitchedCallBack");
	}
	if (!m_lp_nvs_setNoticeSwitchedCallBack) return;

	m_lp_nvs_setNoticeSwitchedCallBack(pFun);
}
void  NVSPlayLibWin::nvs_SetDrawFun(LPDrawCBFun pFun)
{
	if (!m_hDllWin)	return ;

	if (!m_lp_nvs_SetDrawFun)
	{
		m_lp_nvs_SetDrawFun = (lp_nvs_SetDrawFun)GetProcAddress(m_hDllWin,"nvs_SetDrawFun");
	}
	if (!m_lp_nvs_SetDrawFun) return;

	m_lp_nvs_SetDrawFun(pFun);
}

const char* NVSPlayLibWin::nvs_GetErrorMessage(int nErrorCode)
{
	if (!m_hDllWin)	return NULL;

	if (!m_lp_nvs_GetErrorMessage)
	{
		m_lp_nvs_GetErrorMessage = (lp_nvs_GetErrorMessage)GetProcAddress(m_hDllWin,"nvs_GetErrorMessage");
	}
	if (!m_lp_nvs_GetErrorMessage) return NULL;

	return m_lp_nvs_GetErrorMessage(nErrorCode);
}

int  NVSPlayLibWin::nvs_stdVideoinit(pNVSSipCallback pCB, void *pUser)
{
	if (!m_hDllWin)	return NULL;

	if (!m_lp_nvs_stdVideoinit)
	{
		m_lp_nvs_stdVideoinit = (lp_nvs_stdVideoinit)GetProcAddress(m_hDllWin,"nvs_stdVideoinit");
	}
	DWORD err = ::GetLastError();
	if (!m_lp_nvs_stdVideoinit) return NULL;

	return m_lp_nvs_stdVideoinit(pCB,pUser);
}

int  NVSPlayLibWin::nvs_playStdVideo(char* sCameraID,HWND hWnd ,char* sIP, int nPort, char* sUser, char* sPwd ,char* sDllType, LPREALSTREAMCALLBACK lpCallBack, void* pUser)
{
	if (!m_hDllWin)	return NULL;

	if (!m_lp_nvs_playStdVideo)
	{
		m_lp_nvs_playStdVideo = (lp_nvs_playStdVideo)GetProcAddress(m_hDllWin,"nvs_playStdVideo");
	}
	if (!m_lp_nvs_playStdVideo) return NULL;

	return m_lp_nvs_playStdVideo(sCameraID,hWnd , sIP,  nPort, sUser,  sPwd , sDllType,lpCallBack,pUser);
}

int NVSPlayLibWin::nvs_stopStdVideo(char* sCameraID,HWND hWnd)
{
	if (!m_hDllWin)	return NULL;

	if (!m_lp_nvs_stopStdVideo)
	{
		m_lp_nvs_stopStdVideo = (lp_nvs_stopStdVideo)GetProcAddress(m_hDllWin,"nvs_stopStdVideo");
	}
	if (!m_lp_nvs_stopStdVideo) return NULL;

	return m_lp_nvs_stopStdVideo(sCameraID,hWnd);
}

int NVSPlayLibWin::nvs_startPlayMonitor(char* sCameraCode, char *sMonitorCode,char* sIP, int nPort, char* sUser, char* sPwd ,char* sDllType)
{
	if (!m_hDllWin)	return NULL;

	if (!m_lp_nvs_startPlayMonitor)
	{
		m_lp_nvs_startPlayMonitor = (lp_nvs_startPlayMonitor)GetProcAddress(m_hDllWin,"nvs_startPlayMonitor");
	}
	if (!m_lp_nvs_startPlayMonitor) return NULL;

	return m_lp_nvs_startPlayMonitor(sCameraCode,sMonitorCode , sIP,  nPort, sUser,  sPwd , sDllType);
}

int NVSPlayLibWin::nvs_stopPlayMonitor(char *sMonitorCode)
{
	if (!m_hDllWin)	return NULL;

	if (!m_lp_nvs_stopPlayMonitor)
	{
		m_lp_nvs_stopPlayMonitor = (lp_nvs_stopPlayMonitor)GetProcAddress(m_hDllWin,"nvs_stopPlayMonitor");
	}
	if (!m_lp_nvs_stopPlayMonitor) return NULL;

	return m_lp_nvs_stopPlayMonitor(sMonitorCode);
}

bool NVSPlayLibWin::nvs_capturePictureByCode(char* sCameraCode, char* sFilePath)
{
	if (!m_hDllWin)	return NULL;

	if (!m_lp_nvs_capturePictureByCode)
	{
		m_lp_nvs_capturePictureByCode = (lp_nvs_capturePictureByCode)GetProcAddress(m_hDllWin,"nvs_capturePictureByCode");
	}
	if (!m_lp_nvs_capturePictureByCode) return NULL;

	return m_lp_nvs_capturePictureByCode(sCameraCode,sFilePath);
}

void NVSPlayLibWin::nvs_makeKey(char* sCameraCode)
{
	if (!m_hDllWin)	return ;

	if (!m_lp_nvs_makeKey)
	{
		m_lp_nvs_makeKey = (lp_nvs_makeKey)GetProcAddress(m_hDllWin,"nvs_makeKey");
	}
	if (!m_lp_nvs_makeKey) return ;

	return m_lp_nvs_makeKey(sCameraCode);
}

intptr_t NVSPlayLibWin::nvs_connectDVR(char* sIP, int nPort, char* sUser, char* sPwd, int nChannel ,char* sDllType)
{
	if (!m_hDllWin)	return NULL;

	if (!m_lp_nvs_connectDVR)
	{
		m_lp_nvs_connectDVR = (lp_nvs_connectDVR)GetProcAddress(m_hDllWin,"nvs_connectDVR");
	}
	if (!m_lp_nvs_connectDVR) return NULL;

	return m_lp_nvs_connectDVR(sIP, nPort, sUser, sPwd ,nChannel ,sDllType);
}

void NVSPlayLibWin::nvs_disconnectDVR(intptr_t identify)
{
	if (!m_hDllWin)	return ;

	if (!m_lp_nvs_disconnectDVR)
	{
		m_lp_nvs_disconnectDVR = (lp_nvs_disconnectDVR)GetProcAddress(m_hDllWin,"nvs_disconnectDVR");
	}
	if (!m_lp_nvs_disconnectDVR) return ;

	return m_lp_nvs_disconnectDVR(identify);
}

bool NVSPlayLibWin::nvs_controlPTZSpeedWithChannel(string sCameraID,intptr_t identify,int nCmd, bool bEnable, int nSpeed, int nChannel)
{
	if (!m_hDllWin)	return NULL;

	if (!m_lp_nvs_controlPTZSpeedWithChannel)
	{
		m_lp_nvs_controlPTZSpeedWithChannel = (lp_nvs_controlPTZSpeedWithChannel)GetProcAddress(m_hDllWin,"nvs_controlPTZSpeedWithChannel");
	}
	if (!m_lp_nvs_controlPTZSpeedWithChannel) return NULL;

	return m_lp_nvs_controlPTZSpeedWithChannel(sCameraID,identify, nCmd,  bEnable,  nSpeed,  nChannel);
}

bool NVSPlayLibWin::nvs_presetPTZWithChannel(string sCameraID,intptr_t identify, int nCmd, int nIndex, int nChannel)
{
	if (!m_hDllWin)	return NULL;

	if (!m_lp_nvs_presetPTZWithChannel)
	{
		m_lp_nvs_presetPTZWithChannel = (lp_nvs_presetPTZWithChannel)GetProcAddress(m_hDllWin,"nvs_presetPTZWithChannel");
	}
	if (!m_lp_nvs_presetPTZWithChannel) return NULL;

	return m_lp_nvs_presetPTZWithChannel( sCameraID, identify,  nCmd,  nIndex,  nChannel);
}

bool NVSPlayLibWin::nvs_setVideoEffectByCode(string sCameraID,intptr_t identify,DWORD dwBrightValue,DWORD dwContrastValue, DWORD dwSaturationValue,DWORD dwHueValue)
{
	if (!m_hDllWin)	return NULL;

	if (!m_lp_nvs_setVideoEffectByCode)
	{
		m_lp_nvs_setVideoEffectByCode = (lp_nvs_setVideoEffectByCode)GetProcAddress(m_hDllWin,"nvs_setVideoEffectByCode");
	}
	if (!m_lp_nvs_setVideoEffectByCode) return NULL;

	return m_lp_nvs_setVideoEffectByCode( sCameraID, identify,  dwBrightValue, dwContrastValue,  dwSaturationValue, dwHueValue);
}

bool NVSPlayLibWin::nvs_getVideoEffectByCode(string sCameraID,intptr_t identify,DWORD *pBrightValue,DWORD *pContrastValue, DWORD *pSaturationValue,DWORD *pHueValue)
{
	if (!m_hDllWin)	return NULL;

	if (!m_lp_nvs_getVideoEffectByCode)
	{
		m_lp_nvs_getVideoEffectByCode = (lp_nvs_getVideoEffectByCode)GetProcAddress(m_hDllWin,"nvs_getVideoEffectByCode");
	}
	if (!m_lp_nvs_getVideoEffectByCode) return NULL;

	return m_lp_nvs_getVideoEffectByCode( sCameraID, identify, pBrightValue, pContrastValue,  pSaturationValue, pHueValue);
}

bool NVSPlayLibWin::nvs_getDVRConfig(string sCameraID,intptr_t identify, DWORD dwCommand,LONG lChannel,LPVOID lpOutBuffer,DWORD dwOutBufferSize,LPDWORD lpBytesReturned)
{
	if (!m_hDllWin)	return NULL;

	if (!m_lp_nvs_getDVRConfig)
	{
		m_lp_nvs_getDVRConfig = (lp_nvs_getDVRConfig)GetProcAddress(m_hDllWin,"nvs_getDVRConfig");
	}
	if (!m_lp_nvs_getDVRConfig) return NULL;

	return m_lp_nvs_getDVRConfig( sCameraID, identify,  dwCommand, lChannel, lpOutBuffer, dwOutBufferSize,lpBytesReturned);
}

bool NVSPlayLibWin::nvs_setDVRConfig(string sCameraID,intptr_t identify, DWORD dwCommand,LONG lChannel,LPVOID lpInBuffer,DWORD dwInBufferSize)
{
	if (!m_hDllWin)	return NULL;

	if (!m_lp_nvs_setDVRConfig)
	{
		m_lp_nvs_setDVRConfig = (lp_nvs_setDVRConfig)GetProcAddress(m_hDllWin,"nvs_setDVRConfig");
	}
	if (!m_lp_nvs_setDVRConfig) return NULL;

	return m_lp_nvs_setDVRConfig( sCameraID, identify,  dwCommand, lChannel, lpInBuffer, dwInBufferSize);
}

int  NVSPlayLibWin::nvs_getRecordFileEx(string sCameraID,intptr_t identify,RECORDQUERYTYPE nType,char* startTime,char* endTime,RECORDFILE pRecordFile[],int nMaxFileCount)
{
	if (!m_hDllWin)	return NULL;

	if (!m_lp_nvs_getRecordFileEx)
	{
		m_lp_nvs_getRecordFileEx = (lp_nvs_getRecordFileEx)GetProcAddress(m_hDllWin,"nvs_getRecordFileEx");
	}
	if (!m_lp_nvs_getRecordFileEx) return NULL;

	return m_lp_nvs_getRecordFileEx( sCameraID, identify,  nType, startTime, endTime, pRecordFile,nMaxFileCount);
}

intptr_t NVSPlayLibWin::nvs_downloadRecordFile(string sCameraID,intptr_t identify,char* fileName,char* startTime, char* endTime,int nFileSize,char* saveFile,LPDOWNLOADRECORDFILECALLBACK lpCallBack,void* pUser)
{
	if (!m_hDllWin)	return NULL;

	if (!m_lp_nvs_downloadRecordFile)
	{
		m_lp_nvs_downloadRecordFile = (lp_nvs_downloadRecordFile)GetProcAddress(m_hDllWin,"nvs_downloadRecordFile");
	}
	if (!m_lp_nvs_downloadRecordFile) return NULL;

	return m_lp_nvs_downloadRecordFile(sCameraID, identify,fileName, startTime, endTime, nFileSize,saveFile,lpCallBack,pUser);
}

bool NVSPlayLibWin::nvs_stopDownloadRecordFile(intptr_t identify,intptr_t ldownFileHandle)
{
	if (!m_hDllWin)	return NULL;

	if (!m_lp_nvs_stopDownloadRecordFile)
	{
		m_lp_nvs_stopDownloadRecordFile = (lp_nvs_stopDownloadRecordFile)GetProcAddress(m_hDllWin,"nvs_stopDownloadRecordFile");
	}
	if (!m_lp_nvs_stopDownloadRecordFile) return NULL;

	return m_lp_nvs_stopDownloadRecordFile(identify,ldownFileHandle);
}

int NVSPlayLibWin::nvs_getDownloadPos(intptr_t identify,intptr_t lFileHandle)
{
	if (!m_hDllWin)	return NULL;

	if (!m_lp_nvs_getDownloadPos)
	{
		m_lp_nvs_getDownloadPos = (lp_nvs_getDownloadPos)GetProcAddress(m_hDllWin,"nvs_getDownloadPos");
	}
	if (!m_lp_nvs_getDownloadPos) return NULL;

	return m_lp_nvs_getDownloadPos(identify,lFileHandle);
}

intptr_t NVSPlayLibWin::nvs_replayRecordFile(string sCameraID,intptr_t identify,int hWnd,char* fileName,char* startTime, char* endTime,int nFileSize)
{
	if (!m_hDllWin)	return NULL;

	if (!m_lp_nvs_replayRecordFile)
	{
		m_lp_nvs_replayRecordFile = (lp_nvs_replayRecordFile)GetProcAddress(m_hDllWin,"nvs_replayRecordFile");
	}
	if (!m_lp_nvs_replayRecordFile) return NULL;

	return m_lp_nvs_replayRecordFile( sCameraID, identify, hWnd, fileName, startTime,  endTime,nFileSize);
}

bool NVSPlayLibWin::nvs_controlReplayRecordFile(intptr_t identify,intptr_t lReplayHandle,int nCmd,int nInValue,int* outValue)
{
	if (!m_hDllWin)	return NULL;

	if (!m_lp_nvs_controlReplayRecordFile)
	{
		m_lp_nvs_controlReplayRecordFile = (lp_nvs_controlReplayRecordFile)GetProcAddress(m_hDllWin,"nvs_controlReplayRecordFile");
	}
	if (!m_lp_nvs_controlReplayRecordFile) return NULL;

	return m_lp_nvs_controlReplayRecordFile(identify,lReplayHandle,nCmd,nInValue,outValue);
}

bool NVSPlayLibWin::nvs_stopReplayRecordFile(intptr_t identify,intptr_t lReplayHandle)
{
	if (!m_hDllWin)	return NULL;

	if (!m_lp_nvs_stopReplayRecordFile)
	{
		m_lp_nvs_stopReplayRecordFile = (lp_nvs_stopReplayRecordFile)GetProcAddress(m_hDllWin,"nvs_stopReplayRecordFile");
	}
	if (!m_lp_nvs_stopReplayRecordFile) return NULL;

	return m_lp_nvs_stopReplayRecordFile( identify,lReplayHandle);
}

bool NVSPlayLibWin::nvs_startTalk(string sCameraID,intptr_t identify)
{
	if (!m_hDllWin)	return NULL;

	if (!m_lp_nvs_startTalk)
	{
		m_lp_nvs_startTalk = (lp_nvs_startTalk)GetProcAddress(m_hDllWin,"nvs_startTalk");
	}
	if (!m_lp_nvs_startTalk) return NULL;

	return m_lp_nvs_startTalk(sCameraID,identify);
}

bool NVSPlayLibWin::nvs_stopTalk(string sCameraID,intptr_t identify)
{
	if (!m_hDllWin)	return NULL;

	if (!m_lp_nvs_stopTalk)
	{
		m_lp_nvs_stopTalk = (lp_nvs_stopTalk)GetProcAddress(m_hDllWin,"nvs_stopTalk");
	}
	if (!m_lp_nvs_stopTalk) return NULL;

	return m_lp_nvs_stopTalk( sCameraID,identify);
}

bool NVSPlayLibWin::nvs_getDVRWorkState(intptr_t identify,char dvrWorkState[],int arrayLen)
{
	if (!m_hDllWin)	return NULL;

	if (!m_lp_nvs_getDVRWorkState)
	{
		m_lp_nvs_getDVRWorkState = (lp_nvs_getDVRWorkState)GetProcAddress(m_hDllWin,"nvs_getDVRWorkState");
	}
	if (!m_lp_nvs_getDVRWorkState) return NULL;

	return m_lp_nvs_getDVRWorkState(identify,dvrWorkState,arrayLen);
}

DWORD NVSPlayLibWin::nvs_getLastError(string sCameraID,intptr_t identify)
{
	if (!m_hDllWin)	return NULL;

	if (!m_lp_nvs_getLastError)
	{
		m_lp_nvs_getLastError = (lp_nvs_getLastError)GetProcAddress(m_hDllWin,"nvs_getLastError");
	}
	if (!m_lp_nvs_getLastError) return NULL;

	return m_lp_nvs_getLastError(sCameraID,identify);
}

bool NVSPlayLibWin::nvs_playBackCaptureFile(intptr_t identify , intptr_t  lReplayHandle, char *pFileName)
{
	if (!m_hDllWin)	return NULL;

	if (!m_lp_nvs_playBackCaptureFile)
	{
		m_lp_nvs_playBackCaptureFile = (lp_nvs_playBackCaptureFile)GetProcAddress(m_hDllWin,"nvs_playBackCaptureFile");
	}
	if (!m_lp_nvs_playBackCaptureFile) return NULL;

	return m_lp_nvs_playBackCaptureFile( identify ,lReplayHandle, pFileName);
}

bool NVSPlayLibWin::nvs_playBackSaveData(intptr_t identify,intptr_t lReplayHandle,char *sFileName)
{
	if (!m_hDllWin)	return NULL;

	if (!m_lp_nvs_playBackSaveData)
	{
		m_lp_nvs_playBackSaveData = (lp_nvs_playBackSaveData)GetProcAddress(m_hDllWin,"nvs_playBackSaveData");
	}
	if (!m_lp_nvs_playBackSaveData) return NULL;

	return m_lp_nvs_playBackSaveData(identify, lReplayHandle,sFileName);
}

bool NVSPlayLibWin::nvs_stopPlayBackSave(intptr_t identify,intptr_t lReplayHandle)
{
	if (!m_hDllWin)	return NULL;

	if (!m_lp_nvs_stopPlayBackSave)
	{
		m_lp_nvs_stopPlayBackSave = (lp_nvs_stopPlayBackSave)GetProcAddress(m_hDllWin,"nvs_stopPlayBackSave");
	}
	if (!m_lp_nvs_stopPlayBackSave) return NULL;

	return m_lp_nvs_stopPlayBackSave( identify, lReplayHandle);
}

bool NVSPlayLibWin::nvs_startRecordByCode(string sCameraID,intptr_t identify,  char* saveFile)
{
	if (!m_hDllWin)	return NULL;

	if (!m_lp_nvs_startRecordByCode)
	{
		m_lp_nvs_startRecordByCode = (lp_nvs_startRecordByCode)GetProcAddress(m_hDllWin,"nvs_startRecordByCode");
	}
	if (!m_lp_nvs_startRecordByCode) return NULL;

	return m_lp_nvs_startRecordByCode( sCameraID, identify,   saveFile);
}

bool NVSPlayLibWin::nvs_stopRecordByCode(string sCameraID,intptr_t identify)
{
	if (!m_hDllWin)	return NULL;

	if (!m_lp_nvs_stopRecordByCode)
	{
		m_lp_nvs_stopRecordByCode = (lp_nvs_stopRecordByCode)GetProcAddress(m_hDllWin,"nvs_stopRecordByCode");
	}
	if (!m_lp_nvs_stopRecordByCode) return NULL;

	return m_lp_nvs_stopRecordByCode( sCameraID, identify);
}

bool NVSPlayLibWin::nvs_SetCropArea(string sCameraID,intptr_t identify, bool bFlag, int x1, int y1, int x2 , int y2)
{
	if (!m_hDllWin)	return NULL;

	if (!m_lp_nvs_SetCropArea)
	{
		m_lp_nvs_SetCropArea = (lp_nvs_SetCropArea)GetProcAddress(m_hDllWin,"nvs_SetCropArea");
	}
	if (!m_lp_nvs_SetCropArea) return NULL;

	return m_lp_nvs_SetCropArea( sCameraID, identify,  bFlag,  x1,  y1,  x2,  y2 );
}

bool NVSPlayLibWin::nvs_SetDecodeParam(string sCameraID,intptr_t identify, int nCmd, bool bFlag, int x1, int y1, int x2 , int y2)
{
	if (!m_hDllWin)	return NULL;

	if (!m_lp_nvs_SetDecodeParam)
	{
		m_lp_nvs_SetDecodeParam = (lp_nvs_SetDecodeParam)GetProcAddress(m_hDllWin,"nvs_SetDecodeParam");
	}
	if (!m_lp_nvs_SetDecodeParam) return NULL;

	return m_lp_nvs_SetDecodeParam( sCameraID, identify, nCmd,  bFlag,  x1,  y1,  x2,  y2 );
}

bool NVSPlayLibWin::nvs_SetStreamSaveTime(string sCameraID,intptr_t identify, int nSaveTime )
{
	if (!m_hDllWin)	return NULL;

	if (!m_lp_nvs_SetStreamSaveTime)
	{
		m_lp_nvs_SetStreamSaveTime = (lp_nvs_SetStreamSaveTime)GetProcAddress(m_hDllWin,"nvs_SetStreamSaveTime");
	}
	if (!m_lp_nvs_SetStreamSaveTime) return NULL;

	return m_lp_nvs_SetStreamSaveTime( sCameraID, identify,  nSaveTime );
}

bool NVSPlayLibWin::nvs_PlayBackSaveStream(string sCameraID,intptr_t identify, HWND hWnd)
{
	if (!m_hDllWin)	return NULL;

	if (!m_lp_nvs_PlayBackSaveStream)
	{
		m_lp_nvs_PlayBackSaveStream = (lp_nvs_PlayBackSaveStream)GetProcAddress(m_hDllWin,"nvs_PlayBackSaveStream");
	}
	if (!m_lp_nvs_PlayBackSaveStream) return NULL;

	return m_lp_nvs_PlayBackSaveStream( sCameraID, identify,  hWnd);
}

bool NVSPlayLibWin::nvs_StopPlayBackSaveStream(string sCameraID,intptr_t identify)
{
	if (!m_hDllWin)	return NULL;

	if (!m_lp_nvs_StopPlayBackSaveStream)
	{
		m_lp_nvs_StopPlayBackSaveStream = (lp_nvs_StopPlayBackSaveStream)GetProcAddress(m_hDllWin,"nvs_StopPlayBackSaveStream");
	}
	if (!m_lp_nvs_StopPlayBackSaveStream) return NULL;

	return m_lp_nvs_StopPlayBackSaveStream(sCameraID, identify);
}

bool NVSPlayLibWin::nvs_SetRenderMode(string sCameraID,intptr_t identify, int nMode)
{
	if (!m_hDllWin)	return NULL;

	if (!m_lp_nvs_SetRenderMode)
	{
		m_lp_nvs_SetRenderMode = (lp_nvs_SetRenderMode)GetProcAddress(m_hDllWin,"nvs_SetRenderMode");
	}
	if (!m_lp_nvs_SetRenderMode) return NULL;

	return m_lp_nvs_SetRenderMode( sCameraID, identify,  nMode);
}

bool NVSPlayLibWin::nvs_SetPosByFrameNum(string sCameraID,intptr_t identify,DWORD nFrameNum)
{
	if (!m_hDllWin)	return NULL;

	if (!m_lp_nvs_SetPosByFrameNum)
	{
		m_lp_nvs_SetPosByFrameNum = (lp_nvs_SetPosByFrameNum)GetProcAddress(m_hDllWin,"nvs_SetPosByFrameNum");
	}
	if (!m_lp_nvs_SetPosByFrameNum) return NULL;

	return m_lp_nvs_SetPosByFrameNum( sCameraID, identify, nFrameNum);
}

bool NVSPlayLibWin::nvs_GetVideoCut(string sCameraID,intptr_t identify, DWORD beginFrame, DWORD endFrame, LPSTR filename)
{
	if (!m_hDllWin)	return NULL;

	if (!m_lp_nvs_GetVideoCut)
	{
		m_lp_nvs_GetVideoCut = (lp_nvs_GetVideoCut)GetProcAddress(m_hDllWin,"nvs_GetVideoCut");
	}
	if (!m_lp_nvs_GetVideoCut) return NULL;

	return m_lp_nvs_GetVideoCut( sCameraID, identify,  beginFrame,  endFrame,  filename);
}

bool NVSPlayLibWin::nvs_StopCutVideo(string sCameraID,intptr_t identify)
{
	if (!m_hDllWin)	return NULL;

	if (!m_lp_nvs_StopCutVideo)
	{
		m_lp_nvs_StopCutVideo = (lp_nvs_StopCutVideo)GetProcAddress(m_hDllWin,"nvs_StopCutVideo");
	}
	if (!m_lp_nvs_StopCutVideo) return NULL;

	return m_lp_nvs_StopCutVideo( sCameraID, identify);
}

bool NVSPlayLibWin::nvs_SetFileEndCallback(string sCameraID,intptr_t identify, void *pUser, pFileOverCB pCallBack)
{
	if (!m_hDllWin)	return NULL;

	if (!m_lp_nvs_SetFileEndCallback)
	{
		m_lp_nvs_SetFileEndCallback = (lp_nvs_SetFileEndCallback)GetProcAddress(m_hDllWin,"nvs_SetFileEndCallback");
	}
	if (!m_lp_nvs_SetFileEndCallback) return NULL;

	return m_lp_nvs_SetFileEndCallback( sCameraID, identify, pUser, pCallBack);
}

bool NVSPlayLibWin::nvs_GetMediaInfo(string sCameraID,intptr_t identify,MediaInf &mInf)
{
	if (!m_hDllWin)	return NULL;

	if (!m_lp_nvs_GetMediaInfo)
	{
		m_lp_nvs_GetMediaInfo = (lp_nvs_GetMediaInfo)GetProcAddress(m_hDllWin,"nvs_GetMediaInfo");
	}
	if (!m_lp_nvs_GetMediaInfo) return NULL;

	return m_lp_nvs_GetMediaInfo( sCameraID, identify, mInf);
}

bool NVSPlayLibWin::nvs_GetDecodeParam(string sCameraID,intptr_t identify, int nCmd, int &x1, int &y1, int &x2, int &y2)
{
	if (!m_hDllWin)	return NULL;

	if (!m_lp_nvs_GetDecodeParam)
	{
		m_lp_nvs_GetDecodeParam = (lp_nvs_GetDecodeParam)GetProcAddress(m_hDllWin,"nvs_GetDecodeParam");
	}
	if (!m_lp_nvs_GetDecodeParam) return NULL;

	return m_lp_nvs_GetDecodeParam( sCameraID, identify,  nCmd,  x1, y1, x2, y2);
}

bool NVSPlayLibWin::nvs_startPlayer4Standard(string sCameraID,intptr_t identify,HWND hWnd,LPDecCBFun lpDecCBFun, int nCameraID)
{
	if (!m_hDllWin)	return NULL;

	if (!m_lp_nvs_startPlayer4Standard)
	{
		m_lp_nvs_startPlayer4Standard = (lp_nvs_startPlayer4Standard)GetProcAddress(m_hDllWin,"nvs_startPlayer4Standard");
	}
	if (!m_lp_nvs_startPlayer4Standard) return NULL;

	return m_lp_nvs_startPlayer4Standard(sCameraID,identify,hWnd,lpDecCBFun,nCameraID);
}

bool NVSPlayLibWin::nvs_SetYUVCallBack(string sCameraID,intptr_t identify, LPYUVCALLBACK pCallBack)
{
	if (!m_hDllWin)	return NULL;

	if (!m_lp_nvs_SetYUVCallBack)
	{
		m_lp_nvs_SetYUVCallBack = (lp_nvs_SetYUVCallBack)GetProcAddress(m_hDllWin,"nvs_SetYUVCallBack");
	}
	if (!m_lp_nvs_SetYUVCallBack) return NULL;

	return m_lp_nvs_SetYUVCallBack(sCameraID,identify,pCallBack);
}

bool NVSPlayLibWin::nvs_getRecordFileBySource(string sCameraID,intptr_t identify,int nType, char* startTime, char* endTime, int nRecordSource)
{
	if (!m_hDllWin)	return NULL;

	if (!m_lp_nvs_getRecordFileBySource)
	{
		m_lp_nvs_getRecordFileBySource = (lp_nvs_getRecordFileBySource)GetProcAddress(m_hDllWin,"nvs_getRecordFileBySource");
	}
	if (!m_lp_nvs_getRecordFileBySource) return NULL;

	return m_lp_nvs_getRecordFileBySource(sCameraID,identify, nType,  startTime,  endTime, nRecordSource);
}

intptr_t NVSPlayLibWin::nvs_downloadRecordFileBySource(string sCameraID,intptr_t identify,char* fileName,char* startTime, char* endTime,int nFileSize,char* saveFile,LPDOWNLOADRECORDFILECALLBACK lpCallBack,void* pUser, int nRecordSource)
{
	if (!m_hDllWin)	return NULL;

	if (!m_lp_nvs_downloadRecordFileBySource)
	{
		m_lp_nvs_downloadRecordFileBySource = (lp_nvs_downloadRecordFileBySource)GetProcAddress(m_hDllWin,"nvs_downloadRecordFileBySource");
	}
	if (!m_lp_nvs_downloadRecordFileBySource) return NULL;

	return m_lp_nvs_downloadRecordFileBySource(sCameraID,identify, fileName, startTime,  endTime, nFileSize, saveFile,lpCallBack, pUser, nRecordSource);
}

//////////////////////////////////////////////////////////////
//Linux version

NVSPlayLibLux::NVSPlayLibLux(void)
{
	m_hDllLux = ::LoadLibrary("SysComPlay.dll");
	//DWORD dwErr = GetLastError();

	m_lp_nvs_initEnviroment = NULL;
	m_lp_nvs_cleanEnviroment = NULL;
	m_lp_nvs_registerOnIndex = NULL;
	m_lp_nvs_setPlayModel = NULL;
	m_lp_nvs_setDecordCardCallBack = NULL;
	m_lp_nvs_setRealPlayCallBack = NULL;
	m_lp_nvs_setRealDecodeCallBack = NULL;
	m_lp_nvs_setIndexNoticeCallBack = NULL;
	m_lp_nvs_setDVRNoticeCallBack = NULL;
	m_lp_nvs_playVideoByDecordCard = NULL;
	m_lp_nvs_playVideo = NULL;
	m_lp_nvs_playVideo2 = NULL;
	m_lp_nvs_stopPlayVideo = NULL;
	m_lp_nvs_stopPlayByCameraID = NULL;
	m_lp_nvs_stopAll = NULL;
	m_lp_nvs_controlCameraSpeed = NULL;
	m_lp_nvs_cancelControlCamera = NULL;
	m_lp_nvs_capturePictureEx = NULL;
	m_lp_nvs_TransPTZ = NULL;
	m_lp_nvs_getCompress = NULL;
	m_lp_nvs_setCompress = NULL;
	m_lp_nvs_getVideoEffect = NULL;
	m_lp_nvs_setVideoEffect = NULL;
	m_lp_nvs_startRecord = NULL;
	m_lp_nvs_stopRecord = NULL;
	m_lp_nvs_serialSend = NULL;
	m_lp_nvs_reSetDDrawDevice = NULL;
	m_lp_nvs_splitFile = NULL;
	m_lp_nvs_play4Storage = NULL;
	m_lp_nvs_stopPlay4Storage = NULL;
	m_lp_nvs_controlCameraSound = NULL;
	m_lp_nvs_clientNotice = NULL;
	m_lp_nvs_loginDVR = NULL;
	m_lp_nvs_logoutDVR = NULL;
	m_lp_nvs_playVideoByDVR = NULL;
	m_lp_nvs_stopPlayVideoByDVR = NULL;
	m_lp_nvs_controlCameraSpeedByDVR = NULL;
	m_lp_nvs_presetPTZByDVR = NULL;
	m_lp_nvs_getCameraInfo = NULL;
	m_lp_nvs_setPlayWindow = NULL;
	m_lp_nvs_getStreamServerWorkState = NULL;
	m_lp_nvs_getStreamServerIP = NULL;
	m_lp_nvs_SetExternalClient = NULL;
	m_lp_nvs_SetHsCallBack = NULL;
	m_lp_LPVedioHeadStreamCBFun = NULL;
	m_lp_LPVedioBodyStreamCBFun = NULL;
	m_lp_nvs_SetUserIDandOrgID = NULL;
	m_lp_nvs_setNoticeSwitchedCallBack = NULL;
	m_lp_nvs_SetDrawFun = NULL;
	m_lp_nvs_GetErrorMessage = NULL;
	m_lp_nvs_stdVideoinit = NULL;
	m_lp_nvs_playStdVideo = NULL;
	m_lp_nvs_stopStdVideo = NULL;
	m_lp_nvs_startPlayMonitor = NULL;
	m_lp_nvs_stopPlayMonitor  = NULL;

	m_lp_nvs_connectDVR  = NULL;
	m_lp_nvs_connectDVR  = NULL;
	m_lp_nvs_connectDVR  = NULL;
	m_lp_nvs_disconnectDVR  = NULL;
	m_lp_nvs_controlPTZSpeedWithChannel  = NULL;
	m_lp_nvs_presetPTZWithChannel  = NULL;
	m_lp_nvs_setVideoEffectByCode  = NULL;
	m_lp_nvs_getVideoEffectByCode  = NULL;
	m_lp_nvs_getDVRConfig  = NULL;
	m_lp_nvs_setDVRConfig  = NULL;
	m_lp_nvs_getRecordFileEx  = NULL;
	m_lp_nvs_downloadRecordFile  = NULL;
	m_lp_nvs_stopDownloadRecordFile  = NULL;
	m_lp_nvs_getDownloadPos  = NULL;
	m_lp_nvs_replayRecordFile  = NULL;
	m_lp_nvs_controlReplayRecordFile  = NULL;
	m_lp_nvs_stopReplayRecordFile  = NULL;
	m_lp_nvs_startTalk  = NULL;
	m_lp_nvs_stopTalk  = NULL;
	m_lp_nvs_getDVRWorkState  = NULL;
	m_lp_nvs_getLastError  = NULL;
	m_lp_nvs_playBackCaptureFile  = NULL;
	m_lp_nvs_playBackSaveData  = NULL;
	m_lp_nvs_stopPlayBackSave  = NULL;
	m_lp_nvs_startRecordByCode  = NULL;
	m_lp_nvs_stopRecordByCode  = NULL;
	m_lp_nvs_SetCropArea  = NULL;
	m_lp_nvs_SetDecodeParam  = NULL;
	m_lp_nvs_SetStreamSaveTime  = NULL;
	m_lp_nvs_PlayBackSaveStream  = NULL;
	m_lp_nvs_StopPlayBackSaveStream  = NULL;
	m_lp_nvs_SetRenderMode  = NULL;
	m_lp_nvs_SetPosByFrameNum  = NULL;
	m_lp_nvs_GetVideoCut  = NULL;
	m_lp_nvs_StopCutVideo  = NULL;
	m_lp_nvs_SetFileEndCallback  = NULL;
	m_lp_nvs_GetMediaInfo  = NULL;
	m_lp_nvs_GetDecodeParam  = NULL;
	m_lp_nvs_startPlayer4Standard  = NULL;
	m_lp_nvs_SetYUVCallBack  = NULL;
	m_lp_nvs_getRecordFileBySource  = NULL;
	m_lp_nvs_downloadRecordFileBySource  = NULL;
}

NVSPlayLibLux::~NVSPlayLibLux(void)
{
	if (m_hDllLux)
	{
		::FreeLibrary(m_hDllLux);
	}
}



bool NVSPlayLibLux::nvs_initEnviroment(const char* pAddress,unsigned short nPort,int nRight, char type)
{
	bool bRet = false;
	DWORD dwErr = 0;

	if (!m_hDllLux)	return false;
	
	if (!m_lp_nvs_initEnviroment)
	{
		m_lp_nvs_initEnviroment = (lp_nvs_initEnviroment)GetProcAddress(m_hDllLux,"nvs_initEnviroment");
	}

	if (!m_lp_nvs_initEnviroment) return false;


	bRet = m_lp_nvs_initEnviroment(pAddress,nPort,nRight,type);

	return bRet;
}

void NVSPlayLibLux::nvs_cleanEnviroment()
{
	if (!m_hDllLux)	return;

	if (!m_lp_nvs_cleanEnviroment)
	{
		m_lp_nvs_cleanEnviroment = (lp_nvs_cleanEnviroment)GetProcAddress(m_hDllLux,"nvs_cleanEnviroment");
	}
	if (!m_lp_nvs_cleanEnviroment) return;

	m_lp_nvs_cleanEnviroment();
}

bool NVSPlayLibLux::nvs_registerOnIndex()
{
	bool bRet = false;

	if (!m_hDllLux)	return false;

	if (!m_lp_nvs_registerOnIndex)
	{
		m_lp_nvs_registerOnIndex = (lp_nvs_registerOnIndex)GetProcAddress(m_hDllLux,"nvs_registerOnIndex");
	}
	if (!m_lp_nvs_registerOnIndex) return false;

	bRet = m_lp_nvs_registerOnIndex();

	return bRet;
}

void NVSPlayLibLux::nvs_setPlayModel(int nPlayModel)
{
	if (!m_hDllLux)	return;

	if (!m_lp_nvs_setPlayModel)
	{
		m_lp_nvs_setPlayModel = (lp_nvs_setPlayModel)GetProcAddress(m_hDllLux,"nvs_setPlayModel");
	}
	if (!m_lp_nvs_setPlayModel) return;

	m_lp_nvs_setPlayModel(nPlayModel);
}

void NVSPlayLibLux::nvs_setDecordCardCallBack(PlayResultByDecordCard pFun)
{
	if (!m_hDllLux)	return;

	if (!m_lp_nvs_setDecordCardCallBack)
	{
		m_lp_nvs_setDecordCardCallBack = (lp_nvs_setDecordCardCallBack)GetProcAddress(m_hDllLux,"nvs_setDecordCardCallBack");
	}
	if (!m_lp_nvs_setDecordCardCallBack) return;

	m_lp_nvs_setDecordCardCallBack(pFun);
}

void NVSPlayLibLux::nvs_setRealPlayCallBack(RealPlayCallBack pFun)
{
	if (!m_hDllLux)	return;

	if (!m_lp_nvs_setRealPlayCallBack)
	{
		m_lp_nvs_setRealPlayCallBack = (lp_nvs_setRealPlayCallBack)GetProcAddress(m_hDllLux,"nvs_setRealPlayCallBack");
	}
	if (!m_lp_nvs_setRealPlayCallBack) return;

	m_lp_nvs_setRealPlayCallBack(pFun);
}

void NVSPlayLibLux::nvs_setRealDecodeCallBack(LPDecCBFun pFun)
{
	if (!m_hDllLux)	return;

	if (!m_lp_nvs_setRealDecodeCallBack)
	{
		m_lp_nvs_setRealDecodeCallBack = (lp_nvs_setRealDecodeCallBack)GetProcAddress(m_hDllLux,"nvs_setRealDecodeCallBack");
	}
	if (!m_lp_nvs_setRealDecodeCallBack) return;

	m_lp_nvs_setRealDecodeCallBack(pFun);
}

void NVSPlayLibLux::nvs_setIndexNoticeCallBack(IndexNoticeCallBack pFun)
{
	if (!m_hDllLux)	return;

	if (!m_lp_nvs_setIndexNoticeCallBack)
	{
		m_lp_nvs_setIndexNoticeCallBack = (lp_nvs_setIndexNoticeCallBack)GetProcAddress(m_hDllLux,"nvs_setIndexNoticeCallBack");
	}
	if (!m_lp_nvs_setIndexNoticeCallBack) return;

	m_lp_nvs_setIndexNoticeCallBack(pFun);
}

void NVSPlayLibLux::nvs_setDVRNoticeCallBack(DVRNoticeCallBack pFun)
{
	if (!m_hDllLux)	return;

	if (!m_lp_nvs_setDVRNoticeCallBack)
	{
		m_lp_nvs_setDVRNoticeCallBack = (lp_nvs_setDVRNoticeCallBack)GetProcAddress(m_hDllLux,"nvs_setDVRNoticeCallBack");
	}
	if (!m_lp_nvs_setDVRNoticeCallBack) return;

	m_lp_nvs_setDVRNoticeCallBack(pFun);
}

int NVSPlayLibLux::nvs_playVideoByDecordCard(int nCameraID,int nCardIndex, HANDLE* hStreamPlayHandle)
{
	int nRet = -1;

	if (!m_hDllLux)	return -1;

	if (!m_lp_nvs_playVideoByDecordCard)
	{
		m_lp_nvs_playVideoByDecordCard = (lp_nvs_playVideoByDecordCard)GetProcAddress(m_hDllLux,"nvs_playVideoByDecordCard");
	}
	if (!m_lp_nvs_playVideoByDecordCard) return -1;

	nRet = m_lp_nvs_playVideoByDecordCard(nCameraID,nCardIndex,hStreamPlayHandle);

	return nRet;
}

int NVSPlayLibLux::nvs_playVideo2(int nCameraID,HWND hWnd, bool bUseDecode/*获取标准流标识*/, bool bIsExternalDvr)
{
	int nRet = -1;

	if (!m_hDllLux)	return -1;

	if (!m_lp_nvs_playVideo2)
	{
		m_lp_nvs_playVideo2 = (lp_nvs_playVideo2)GetProcAddress(m_hDllLux,"nvs_playVideo2");
	}
	if (!m_lp_nvs_playVideo2) return -1;

	nRet = m_lp_nvs_playVideo2(nCameraID,hWnd,bUseDecode, bIsExternalDvr);

	return nRet;
}
int NVSPlayLibLux::nvs_playVideo(int nCameraID,HWND hWnd, bool bUseDecode/*获取标准流标识*/)
{
	int nRet = -1;

	if (!m_hDllLux)	return -1;

	if (!m_lp_nvs_playVideo)
	{
		m_lp_nvs_playVideo = (lp_nvs_playVideo)GetProcAddress(m_hDllLux,"nvs_playVideo");
	}
	if (!m_lp_nvs_playVideo) return -1;

	nRet = m_lp_nvs_playVideo(nCameraID,hWnd,bUseDecode);

	return nRet;
}
bool NVSPlayLibLux::nvs_stopPlayVideo(HWND hWnd, int nCardIndex, int nCameraID)
{
	bool bRet = false;

	if (!m_hDllLux)	return false;

	if (!m_lp_nvs_stopPlayVideo)
	{
		m_lp_nvs_stopPlayVideo = (lp_nvs_stopPlayVideo)GetProcAddress(m_hDllLux,"nvs_stopPlayVideo");
	}
	if (!m_lp_nvs_stopPlayVideo) return false;

	bRet = m_lp_nvs_stopPlayVideo(hWnd,nCardIndex,nCameraID);

	return bRet;
}
bool NVSPlayLibLux::nvs_stopPlayByCameraID(int nCameraID)
{
	bool bRet = false;

	if (!m_hDllLux)	return false;

	if (!m_lp_nvs_stopPlayByCameraID)
	{
		m_lp_nvs_stopPlayByCameraID = (lp_nvs_stopPlayByCameraID)GetProcAddress(m_hDllLux,"nvs_stopPlayByCameraID");
	}
	if (!m_lp_nvs_stopPlayByCameraID) return false;

	bRet = m_lp_nvs_stopPlayByCameraID(nCameraID);

	return bRet;
}

void NVSPlayLibLux::nvs_stopAll()
{
	if (!m_hDllLux)	return;

	if (!m_lp_nvs_stopAll)
	{
		m_lp_nvs_stopAll = (lp_nvs_stopAll)GetProcAddress(m_hDllLux,"nvs_stopAll");
	}
	if (!m_lp_nvs_stopAll) return;

	m_lp_nvs_stopAll();
}

bool NVSPlayLibLux::nvs_controlCameraSpeed(int nCameraID,int nCmd,bool bControl,int nSpeed)
{
	bool bRet = false;

	if (!m_hDllLux)	return false;

	if (!m_lp_nvs_controlCameraSpeed)
	{
		m_lp_nvs_controlCameraSpeed = (lp_nvs_controlCameraSpeed)GetProcAddress(m_hDllLux,"nvs_controlCameraSpeed");
	}
	if (!m_lp_nvs_controlCameraSpeed) return false;

	bRet = m_lp_nvs_controlCameraSpeed(nCameraID,nCmd,bControl,nSpeed);

	return bRet;
}

bool NVSPlayLibLux::nvs_cancelControlCamera(HWND hWnd,int nCameraID)
{
	bool bRet = false;

	if (!m_hDllLux)	return false;

	if (!m_lp_nvs_cancelControlCamera)
	{
		m_lp_nvs_cancelControlCamera = (lp_nvs_cancelControlCamera)GetProcAddress(m_hDllLux,"nvs_cancelControlCamera");
	}
	if (!m_lp_nvs_cancelControlCamera) return false;

	bRet = m_lp_nvs_cancelControlCamera(hWnd,nCameraID);

	return bRet;
}

bool NVSPlayLibLux::nvs_capturePictureEx(int nCameraID, char* pFileName)
{
	bool bRet = false;

	if (!m_hDllLux)	return false;

	if (!m_lp_nvs_capturePictureEx)
	{
		m_lp_nvs_capturePictureEx = (lp_nvs_capturePictureEx)GetProcAddress(m_hDllLux,"nvs_capturePictureEx");
	}
	if (!m_lp_nvs_capturePictureEx) return false;

	bRet = m_lp_nvs_capturePictureEx(nCameraID,pFileName);

	return bRet;
}

bool NVSPlayLibLux::nvs_TransPTZ(int nCameraID, int nCmd, int nTransPTZIndex)
{
	bool bRet = false;

	if (!m_hDllLux)	return false;

	if (!m_lp_nvs_TransPTZ)
	{
		m_lp_nvs_TransPTZ = (lp_nvs_TransPTZ)GetProcAddress(m_hDllLux,"nvs_TransPTZ");
	}
	if (!m_lp_nvs_TransPTZ) return false;

	bRet = m_lp_nvs_TransPTZ(nCameraID,nCmd,nTransPTZIndex);

	return bRet;
}

bool NVSPlayLibLux::nvs_getCompress(int nCameraID, char **lpOutBuffer)
{
	bool bRet = false;

	if (!m_hDllLux)	return false;

	if (!m_lp_nvs_getCompress)
	{
		m_lp_nvs_getCompress = (lp_nvs_getCompress)GetProcAddress(m_hDllLux,"nvs_getCompress");
	}
	if (!m_lp_nvs_getCompress) return false;

	bRet = m_lp_nvs_getCompress(nCameraID,lpOutBuffer);

	return bRet;
}

bool NVSPlayLibLux::nvs_setCompress(int nCameraID, char* pCompressInfo)
{	
	bool bRet = false;

	if (!m_hDllLux)	return false;

	if (!m_lp_nvs_setCompress)
	{
		m_lp_nvs_setCompress = (lp_nvs_setCompress)GetProcAddress(m_hDllLux,"nvs_setCompress");
	}
	if (!m_lp_nvs_setCompress) return false;

	bRet = m_lp_nvs_setCompress(nCameraID,pCompressInfo);

	return bRet;
}

bool NVSPlayLibLux::nvs_getVideoEffect(int nCameraID, int* pBrightValue,int* pContrastValue, int* pSaturationValue,int* pHueValue)
{
	bool bRet = false;

	if (!m_hDllLux)	return false;

	if (!m_lp_nvs_getVideoEffect)
	{
		m_lp_nvs_getVideoEffect = (lp_nvs_getVideoEffect)GetProcAddress(m_hDllLux,"nvs_getVideoEffect");
	}
	if (!m_lp_nvs_getVideoEffect) return false;

	bRet = m_lp_nvs_getVideoEffect(nCameraID,pBrightValue,pContrastValue,pSaturationValue,pHueValue);

	return bRet;
}

bool NVSPlayLibLux::nvs_setVideoEffect(int nCameraID, DWORD dwBrightValue,DWORD dwContrastValue, DWORD dwSaturationValue,DWORD dwHueValue)
{
	bool bRet = false;

	if (!m_hDllLux)	return false;

	if (!m_lp_nvs_setVideoEffect)
	{
		m_lp_nvs_setVideoEffect = (lp_nvs_setVideoEffect)GetProcAddress(m_hDllLux,"nvs_setVideoEffect");
	}
	if (!m_lp_nvs_setVideoEffect) return false;

	bRet = m_lp_nvs_setVideoEffect(nCameraID,dwBrightValue,dwContrastValue,dwSaturationValue,dwHueValue);

	return bRet;
}

int NVSPlayLibLux::nvs_startRecord(int nCameraID, char* pFileName)
{
	int nRet = -1;

	if (!m_hDllLux)	return -1;

	if (!m_lp_nvs_startRecord)
	{
		m_lp_nvs_startRecord = (lp_nvs_startRecord)GetProcAddress(m_hDllLux,"nvs_startRecord");
	}
	if (!m_lp_nvs_startRecord) return -1;

	nRet = m_lp_nvs_startRecord(nCameraID,pFileName);

	return nRet;
}

bool NVSPlayLibLux::nvs_stopRecord(int nCameraID)
{
	bool bRet = false;

	if (!m_hDllLux)	return false;

	if (!m_lp_nvs_stopRecord)
	{
		m_lp_nvs_stopRecord = (lp_nvs_stopRecord)GetProcAddress(m_hDllLux,"nvs_stopRecord");
	}
	if (!m_lp_nvs_stopRecord) return false;

	bRet = m_lp_nvs_stopRecord(nCameraID);

	return bRet;
}

bool NVSPlayLibLux::nvs_serialSend(int nCameraID, char* cmd1, DWORD nLen1, char* cmd2, DWORD nLen2)
{
	bool bRet = false;

	if (!m_hDllLux)	return false;

	if (!m_lp_nvs_serialSend)
	{
		m_lp_nvs_serialSend = (lp_nvs_serialSend)GetProcAddress(m_hDllLux,"nvs_serialSend");
	}
	if (!m_lp_nvs_serialSend) return false;

	bRet = m_lp_nvs_serialSend(nCameraID,cmd1,nLen1,cmd2,nLen2);

	return bRet;
}

void NVSPlayLibLux::nvs_reSetDDrawDevice(int nCameraID)
{
	if (!m_hDllLux)	return;

	if (!m_lp_nvs_reSetDDrawDevice)
	{
		m_lp_nvs_reSetDDrawDevice = (lp_nvs_reSetDDrawDevice)GetProcAddress(m_hDllLux,"nvs_reSetDDrawDevice");
	}
	if (!m_lp_nvs_reSetDDrawDevice) return;

	m_lp_nvs_reSetDDrawDevice(nCameraID);
}

int NVSPlayLibLux::nvs_splitFile(int nCameraID,char* sFileName,int nPriorTime)
{
	int nRet = -1;

	if (!m_hDllLux)	return -1;

	if (!m_lp_nvs_splitFile)
	{
		m_lp_nvs_splitFile = (lp_nvs_splitFile)GetProcAddress(m_hDllLux,"nvs_splitFile");
	}
	if (!m_lp_nvs_splitFile) return -1;

	nRet = m_lp_nvs_splitFile(nCameraID,sFileName,nPriorTime);

	return nRet;
}

int NVSPlayLibLux::nvs_play4Storage(int nCameraID,char* sFileName,int nPriorTime)
{
	int nRet = -1;

	if (!m_hDllLux)	return -1;

	if (!m_lp_nvs_play4Storage)
	{
		m_lp_nvs_play4Storage = (lp_nvs_play4Storage)GetProcAddress(m_hDllLux,"nvs_play4Storage");
	}
	if (!m_lp_nvs_play4Storage) return -1;

	nRet = m_lp_nvs_play4Storage(nCameraID,sFileName,nPriorTime);

	return nRet;
}

bool NVSPlayLibLux::nvs_stopPlay4Storage(int nCameraID)
{
	bool bRet = false;

	if (!m_hDllLux)	return false;

	if (!m_lp_nvs_stopPlay4Storage)
	{
		m_lp_nvs_stopPlay4Storage = (lp_nvs_stopPlay4Storage)GetProcAddress(m_hDllLux,"nvs_stopPlay4Storage");
	}
	if (!m_lp_nvs_stopPlay4Storage) return false;

	bRet = m_lp_nvs_stopPlay4Storage(nCameraID);

	return bRet;
}

bool NVSPlayLibLux::nvs_controlCameraSound(int nCameraID, bool bOpenSound)
{
	bool bRet = false;

	if (!m_hDllLux)	return false;

	if (!m_lp_nvs_controlCameraSound)
	{
		m_lp_nvs_controlCameraSound = (lp_nvs_controlCameraSound)GetProcAddress(m_hDllLux,"nvs_controlCameraSound");
	}
	if (!m_lp_nvs_controlCameraSound) return false;

	bRet = m_lp_nvs_controlCameraSound(nCameraID,bOpenSound);

	return bRet;
}

bool NVSPlayLibLux::nvs_clientNotice()
{
	bool bRet = false;

	if (!m_hDllLux)	return false;

	if (!m_lp_nvs_clientNotice)
	{
		m_lp_nvs_clientNotice = (lp_nvs_clientNotice)GetProcAddress(m_hDllLux,"nvs_clientNotice");
	}
	if (!m_lp_nvs_clientNotice) return false;

	bRet = m_lp_nvs_clientNotice();

	return bRet;
}

intptr_t NVSPlayLibLux::nvs_loginDVR(char* sIP, int nPort, char* sUser, char* sPwd)
{
	intptr_t lRet = -1;

	if (!m_hDllLux)	return -1;

	if (!m_lp_nvs_loginDVR)
	{
		m_lp_nvs_loginDVR = (lp_nvs_loginDVR)GetProcAddress(m_hDllLux,"nvs_loginDVR");
	}
	if (!m_lp_nvs_loginDVR) return -1;

	lRet = m_lp_nvs_loginDVR(sIP,nPort,sUser,sPwd);

	return lRet;
}

void NVSPlayLibLux::nvs_logoutDVR(intptr_t identify)
{
	if (!m_hDllLux)	return;

	if (!m_lp_nvs_logoutDVR)
	{
		m_lp_nvs_logoutDVR = (lp_nvs_logoutDVR)GetProcAddress(m_hDllLux,"nvs_logoutDVR");
	}
	if (!m_lp_nvs_logoutDVR) return;

	m_lp_nvs_logoutDVR(identify);
}

bool NVSPlayLibLux::nvs_playVideoByDVR(intptr_t identify,int nCameraID,HWND hWnd)
{
	bool bRet = false;

	if (!m_hDllLux)	return false;

	if (!m_lp_nvs_playVideoByDVR)
	{
		m_lp_nvs_playVideoByDVR = (lp_nvs_playVideoByDVR)GetProcAddress(m_hDllLux,"nvs_playVideoByDVR");
	}
	if (!m_lp_nvs_playVideoByDVR) return false;

	bRet = m_lp_nvs_playVideoByDVR(identify,nCameraID,hWnd);

	return bRet;
}

bool NVSPlayLibLux::nvs_stopPlayVideoByDVR(intptr_t identify,HWND hWnd)
{
	bool bRet = false;

	if (!m_hDllLux)	return false;

	if (!m_lp_nvs_stopPlayVideoByDVR)
	{
		m_lp_nvs_stopPlayVideoByDVR = (lp_nvs_stopPlayVideoByDVR)GetProcAddress(m_hDllLux,"nvs_stopPlayVideoByDVR");
	}
	if (!m_lp_nvs_stopPlayVideoByDVR) return false;

	bRet = m_lp_nvs_stopPlayVideoByDVR(identify,hWnd);

	return bRet;
}

bool NVSPlayLibLux::nvs_controlCameraSpeedByDVR(intptr_t identify,int nCameraID,int nCmd,bool bControl,int nSpeed,int nChannel)
{
	bool bRet = false;

	if (!m_hDllLux)	return false;

	if (!m_lp_nvs_controlCameraSpeedByDVR)
	{
		m_lp_nvs_controlCameraSpeedByDVR = (lp_nvs_controlCameraSpeedByDVR)GetProcAddress(m_hDllLux,"nvs_controlCameraSpeedByDVR");
	}
	if (!m_lp_nvs_controlCameraSpeedByDVR) return false;

	bRet = m_lp_nvs_controlCameraSpeedByDVR(identify,nCameraID,nCmd,bControl,nSpeed,nChannel);

	return bRet;
}

bool NVSPlayLibLux::nvs_presetPTZByDVR(intptr_t identify,int nCameraID, int nCmd, int nTransPTZIndex, int nChannel)
{
	bool bRet = false;

	if (!m_hDllLux)	return false;

	if (!m_lp_nvs_presetPTZByDVR)
	{
		m_lp_nvs_presetPTZByDVR = (lp_nvs_presetPTZByDVR)GetProcAddress(m_hDllLux,"nvs_presetPTZByDVR");
	}
	if (!m_lp_nvs_presetPTZByDVR) return false;

	bRet = m_lp_nvs_presetPTZByDVR(identify,nCameraID,nCmd,nTransPTZIndex,nChannel);

	return bRet;
}

intptr_t NVSPlayLibLux::nvs_getCameraInfo(intptr_t identify,int *nSize)
{
	intptr_t lRet = -1;

	if (!m_hDllLux)	return -1;

	if (!m_lp_nvs_getCameraInfo)
	{
		m_lp_nvs_getCameraInfo = (lp_nvs_getCameraInfo)GetProcAddress(m_hDllLux,"nvs_getCameraInfo");
	}
	if (!m_lp_nvs_getCameraInfo) return -1;

	lRet = m_lp_nvs_getCameraInfo(identify,nSize);

	return lRet;
}

int NVSPlayLibLux::nvs_setPlayWindow(HWND palyWindow[], int nMaxCount)
{
	int nRet = -1;

	if (!m_hDllLux)	return -1;

	if (!m_lp_nvs_setPlayWindow)
	{
		m_lp_nvs_setPlayWindow = (lp_nvs_setPlayWindow)GetProcAddress(m_hDllLux,"nvs_setPlayWindow");
	}
	if (!m_lp_nvs_setPlayWindow) return -1;

	nRet = m_lp_nvs_setPlayWindow(palyWindow,nMaxCount);

	return nRet;
}

intptr_t NVSPlayLibLux::nvs_getStreamServerWorkState(int nCameraID, int nCameraCount, int *outSize )
{
	intptr_t lRet = -1;

	if (!m_hDllLux)	return -1;

	if (!m_lp_nvs_getStreamServerWorkState)
	{
		m_lp_nvs_getStreamServerWorkState = (lp_nvs_getStreamServerWorkState)GetProcAddress(m_hDllLux,"nvs_getStreamServerWorkState");
	}
	if (!m_lp_nvs_getStreamServerWorkState) return -1;

	lRet = m_lp_nvs_getStreamServerWorkState(nCameraID,nCameraCount,outSize);

	return lRet;
}

char* NVSPlayLibLux::nvs_getStreamServerIP( int nCameraID)
{
	if (!m_hDllLux)	return NULL;

	if (!m_lp_nvs_getStreamServerIP)
	{
		m_lp_nvs_getStreamServerIP = (lp_nvs_getStreamServerIP)GetProcAddress(m_hDllLux,"nvs_getStreamServerIP");
	}
	if (!m_lp_nvs_getStreamServerIP) return NULL;

	return m_lp_nvs_getStreamServerIP(nCameraID);
}

void NVSPlayLibLux::nvs_SetExternalClient(bool bIsExternal)
{
	if (!m_hDllLux)	return ;

	if (!m_lp_nvs_SetExternalClient)
	{
		m_lp_nvs_SetExternalClient = (lp_nvs_SetExternalClient)GetProcAddress(m_hDllLux,"nvs_SetExternalClient");
	}
	if (!m_lp_nvs_SetExternalClient) return;

	m_lp_nvs_SetExternalClient(bIsExternal);
}

void NVSPlayLibLux::nvs_writeLog(char* logMsg, int level)
{
	if (!m_hDllLux)	return ;

	if (!m_lp_nvs_writeLog)
	{
		m_lp_nvs_writeLog = (lp_nvs_writeLog)GetProcAddress(m_hDllLux,"nvs_writeLog");
	}
	if (!m_lp_nvs_writeLog) return;

	m_lp_nvs_writeLog(logMsg,level);
}

bool NVSPlayLibLux::nvs_InitHSServer(char *strIP, int nPort)
{
	bool bRet = false;

	if (!m_hDllLux)	return false;

	if (!m_lp_nvs_InitHSServer)
	{
		m_lp_nvs_InitHSServer = (lp_nvs_InitHSServer)GetProcAddress(m_hDllLux,"nvs_InitHSServer");
	}
	if (!m_lp_nvs_InitHSServer) return false;

	bRet = m_lp_nvs_InitHSServer(strIP,nPort);

	return bRet;
}

void NVSPlayLibLux::nvs_SetHsCallBack(HsUserCallBack CallbackFun)
{
	if (!m_hDllLux) return;
	
	if (!m_lp_nvs_SetHsCallBack)
	{
		m_lp_nvs_SetHsCallBack = (lp_nvs_SetHsCallBack)GetProcAddress(m_hDllLux,"nvs_SetHsCallBack");
	}
	if (!m_lp_nvs_SetHsCallBack) return;
	
	m_lp_nvs_SetHsCallBack(CallbackFun);
}

void NVSPlayLibLux::nvs_SetVedioHeadStreamCallBack(LPVedioHeadStreamCBFun pFun)
{
	if (!m_hDllLux) return;

	if (!m_lp_LPVedioHeadStreamCBFun)
	{
		m_lp_LPVedioHeadStreamCBFun = (lp_LPVedioHeadStreamCBFun)GetProcAddress(m_hDllLux,"nvs_SetVedioHeadStreamCallBack");
	}
	if (!m_lp_LPVedioHeadStreamCBFun) return;

	m_lp_LPVedioHeadStreamCBFun(pFun);
}

void NVSPlayLibLux::nvs_SetVedioBodyStreamCallBack(LPVedioBodyStreamCBFun pFun)
{
	if (!m_hDllLux) return;

	if (!m_lp_LPVedioBodyStreamCBFun)
	{
		m_lp_LPVedioBodyStreamCBFun = (lp_LPVedioBodyStreamCBFun)GetProcAddress(m_hDllLux,"nvs_SetVedioBodyStreamCallBack");
	}
	if (!m_lp_LPVedioBodyStreamCBFun) return;

	m_lp_LPVedioBodyStreamCBFun(pFun);
}

void NVSPlayLibLux::nvs_SetUserIDandOrgID(int nUserID,int OrgID)
{
	if (!m_hDllLux)	return ;

	if (!m_lp_nvs_SetUserIDandOrgID)
	{
		m_lp_nvs_SetUserIDandOrgID = (lp_nvs_SetUserIDandOrgID)GetProcAddress(m_hDllLux,"nvs_SetUserIDandOrgID");
	}
	if (!m_lp_nvs_SetUserIDandOrgID) return;

	m_lp_nvs_SetUserIDandOrgID(nUserID,OrgID);
}

void NVSPlayLibLux::nvs_setNoticeSwitchedCallBack(NoticeSwitchedCallBack pFun)
{
	if (!m_hDllLux)	return ;

	if (!m_lp_nvs_setNoticeSwitchedCallBack)
	{
		m_lp_nvs_setNoticeSwitchedCallBack = (lp_nvs_setNoticeSwitchedCallBack)GetProcAddress(m_hDllLux,"nvs_setNoticeSwitchedCallBack");
	}
	if (!m_lp_nvs_setNoticeSwitchedCallBack) return;

	m_lp_nvs_setNoticeSwitchedCallBack(pFun);
}

void  NVSPlayLibLux::nvs_SetDrawFun(LPDrawCBFun pFun)
{
	if (!m_hDllLux)	return ;

	if (!m_lp_nvs_SetDrawFun)
	{
		m_lp_nvs_SetDrawFun = (lp_nvs_SetDrawFun)GetProcAddress(m_hDllLux,"nvs_SetDrawFun");
	}
	if (!m_lp_nvs_SetDrawFun) return;

	m_lp_nvs_SetDrawFun(pFun);
}

const char* NVSPlayLibLux::nvs_GetErrorMessage(int nErrorCode)
{
	if (!m_hDllLux)	return NULL;

	if (!m_lp_nvs_GetErrorMessage)
	{
		m_lp_nvs_GetErrorMessage = (lp_nvs_GetErrorMessage)GetProcAddress(m_hDllLux,"nvs_GetErrorMessage");
	}
	if (!m_lp_nvs_GetErrorMessage) return NULL;

	return m_lp_nvs_GetErrorMessage(nErrorCode);
}


int  NVSPlayLibLux::nvs_stdVideoinit(pNVSSipCallback pCB, void *pUser)
{
	if (!m_hDllLux)	return NULL;

	if (!m_lp_nvs_stdVideoinit)
	{
		m_lp_nvs_stdVideoinit = (lp_nvs_stdVideoinit)GetProcAddress(m_hDllLux,"nvs_stdVideoinit");
	}
	if (!m_lp_nvs_stdVideoinit) return NULL;

	return m_lp_nvs_stdVideoinit(pCB,pUser);
}

int  NVSPlayLibLux::nvs_playStdVideo(char* sCameraID,HWND hWnd ,char* sIP, int nPort, char* sUser, char* sPwd ,char* sDllType, LPREALSTREAMCALLBACK lpCallBack, void* pUser)
{
	if (!m_hDllLux)	return NULL;

	if (!m_lp_nvs_playStdVideo)
	{
		m_lp_nvs_playStdVideo = (lp_nvs_playStdVideo)GetProcAddress(m_hDllLux,"nvs_playStdVideo");
	}
	if (!m_lp_nvs_playStdVideo) return NULL;

	return m_lp_nvs_playStdVideo(sCameraID, hWnd , sIP,  nPort, sUser,  sPwd , sDllType,lpCallBack,pUser);
}

int NVSPlayLibLux::nvs_stopStdVideo(char* sCameraID,HWND hWnd)
{
	if (!m_hDllLux)	return NULL;

	if (!m_lp_nvs_stopStdVideo)
	{
		m_lp_nvs_stopStdVideo = (lp_nvs_stopStdVideo)GetProcAddress(m_hDllLux,"nvs_stopStdVideo");
	}
	if (!m_lp_nvs_stopStdVideo) return NULL;

	return m_lp_nvs_stopStdVideo(sCameraID,hWnd);
}


int NVSPlayLibLux::nvs_startPlayMonitor(char* sCameraCode, char *sMonitorCode,char* sIP, int nPort, char* sUser, char* sPwd ,char* sDllType)
{
	if (!m_hDllLux)	return NULL;

	if (!m_lp_nvs_startPlayMonitor)
	{
		m_lp_nvs_startPlayMonitor = (lp_nvs_startPlayMonitor)GetProcAddress(m_hDllLux,"nvs_startPlayMonitor");
	}
	if (!m_lp_nvs_startPlayMonitor) return NULL;

	return m_lp_nvs_startPlayMonitor(sCameraCode,sMonitorCode , sIP,  nPort, sUser,  sPwd , sDllType);
}

int NVSPlayLibLux::nvs_stopPlayMonitor(char *sMonitorCode)
{
	if (!m_hDllLux)	return NULL;

	if (!m_lp_nvs_stopPlayMonitor)
	{
		m_lp_nvs_stopPlayMonitor = (lp_nvs_stopPlayMonitor)GetProcAddress(m_hDllLux,"nvs_stopPlayMonitor");
	}
	if (!m_lp_nvs_stopPlayMonitor) return NULL;

	return m_lp_nvs_stopPlayMonitor(sMonitorCode);
}

bool NVSPlayLibLux::nvs_capturePictureByCode(char* sCameraCode, char* sFilePath)
{
	if (!m_hDllLux)	return NULL;

	if (!m_lp_nvs_capturePictureByCode)
	{
		m_lp_nvs_capturePictureByCode = (lp_nvs_capturePictureByCode)GetProcAddress(m_hDllLux,"nvs_capturePictureByCode");
	}
	if (!m_lp_nvs_capturePictureByCode) return NULL;

	return m_lp_nvs_capturePictureByCode(sCameraCode,sFilePath);
}

void NVSPlayLibLux::nvs_makeKey(char* sCameraCode)
{
	if (!m_hDllLux)	return ;

	if (!m_lp_nvs_makeKey)
	{
		m_lp_nvs_makeKey = (lp_nvs_makeKey)GetProcAddress(m_hDllLux,"nvs_makeKey");
	}
	if (!m_lp_nvs_makeKey) return ;

	return m_lp_nvs_makeKey(sCameraCode);
}

intptr_t NVSPlayLibLux::nvs_connectDVR(char* sIP, int nPort, char* sUser, char* sPwd, int nChannel ,char* sDllType)
{
	if (!m_hDllLux)	return NULL;

	if (!m_lp_nvs_connectDVR)
	{
		m_lp_nvs_connectDVR = (lp_nvs_connectDVR)GetProcAddress(m_hDllLux,"nvs_connectDVR");
	}
	if (!m_lp_nvs_connectDVR) return NULL;

	return m_lp_nvs_connectDVR(sIP, nPort, sUser, sPwd ,nChannel ,sDllType);
}

void NVSPlayLibLux::nvs_disconnectDVR(intptr_t identify)
{
	if (!m_hDllLux)	return ;

	if (!m_lp_nvs_disconnectDVR)
	{
		m_lp_nvs_disconnectDVR = (lp_nvs_disconnectDVR)GetProcAddress(m_hDllLux,"nvs_disconnectDVR");
	}
	if (!m_lp_nvs_disconnectDVR) return ;

	return m_lp_nvs_disconnectDVR(identify);
}

bool NVSPlayLibLux::nvs_controlPTZSpeedWithChannel(string sCameraID,intptr_t identify,int nCmd, bool bEnable, int nSpeed, int nChannel)
{
	if (!m_hDllLux)	return NULL;

	if (!m_lp_nvs_controlPTZSpeedWithChannel)
	{
		m_lp_nvs_controlPTZSpeedWithChannel = (lp_nvs_controlPTZSpeedWithChannel)GetProcAddress(m_hDllLux,"nvs_controlPTZSpeedWithChannel");
	}
	if (!m_lp_nvs_controlPTZSpeedWithChannel) return NULL;

	return m_lp_nvs_controlPTZSpeedWithChannel(sCameraID,identify, nCmd,  bEnable,  nSpeed,  nChannel);
}

bool NVSPlayLibLux::nvs_presetPTZWithChannel(string sCameraID,intptr_t identify, int nCmd, int nIndex, int nChannel)
{
	if (!m_hDllLux)	return NULL;

	if (!m_lp_nvs_presetPTZWithChannel)
	{
		m_lp_nvs_presetPTZWithChannel = (lp_nvs_presetPTZWithChannel)GetProcAddress(m_hDllLux,"nvs_presetPTZWithChannel");
	}
	if (!m_lp_nvs_presetPTZWithChannel) return NULL;

	return m_lp_nvs_presetPTZWithChannel( sCameraID, identify,  nCmd,  nIndex,  nChannel);
}

bool NVSPlayLibLux::nvs_setVideoEffectByCode(string sCameraID,intptr_t identify,DWORD dwBrightValue,DWORD dwContrastValue, DWORD dwSaturationValue,DWORD dwHueValue)
{
	if (!m_hDllLux)	return NULL;

	if (!m_lp_nvs_setVideoEffectByCode)
	{
		m_lp_nvs_setVideoEffectByCode = (lp_nvs_setVideoEffectByCode)GetProcAddress(m_hDllLux,"nvs_setVideoEffectByCode");
	}
	if (!m_lp_nvs_setVideoEffectByCode) return NULL;

	return m_lp_nvs_setVideoEffectByCode( sCameraID, identify,  dwBrightValue, dwContrastValue,  dwSaturationValue, dwHueValue);
}

bool NVSPlayLibLux::nvs_getVideoEffectByCode(string sCameraID,intptr_t identify,DWORD *pBrightValue,DWORD *pContrastValue, DWORD *pSaturationValue,DWORD *pHueValue)
{
	if (!m_hDllLux)	return NULL;

	if (!m_lp_nvs_getVideoEffectByCode)
	{
		m_lp_nvs_getVideoEffectByCode = (lp_nvs_getVideoEffectByCode)GetProcAddress(m_hDllLux,"nvs_getVideoEffectByCode");
	}
	if (!m_lp_nvs_getVideoEffectByCode) return NULL;

	return m_lp_nvs_getVideoEffectByCode( sCameraID, identify, pBrightValue, pContrastValue,  pSaturationValue, pHueValue);
}

bool NVSPlayLibLux::nvs_getDVRConfig(string sCameraID,intptr_t identify, DWORD dwCommand,LONG lChannel,LPVOID lpOutBuffer,DWORD dwOutBufferSize,LPDWORD lpBytesReturned)
{
	if (!m_hDllLux)	return NULL;

	if (!m_lp_nvs_getDVRConfig)
	{
		m_lp_nvs_getDVRConfig = (lp_nvs_getDVRConfig)GetProcAddress(m_hDllLux,"nvs_getDVRConfig");
	}
	if (!m_lp_nvs_getDVRConfig) return NULL;

	return m_lp_nvs_getDVRConfig( sCameraID, identify,  dwCommand, lChannel, lpOutBuffer, dwOutBufferSize,lpBytesReturned);
}

bool NVSPlayLibLux::nvs_setDVRConfig(string sCameraID,intptr_t identify, DWORD dwCommand,LONG lChannel,LPVOID lpInBuffer,DWORD dwInBufferSize)
{
	if (!m_hDllLux)	return NULL;

	if (!m_lp_nvs_setDVRConfig)
	{
		m_lp_nvs_setDVRConfig = (lp_nvs_setDVRConfig)GetProcAddress(m_hDllLux,"nvs_setDVRConfig");
	}
	if (!m_lp_nvs_setDVRConfig) return NULL;

	return m_lp_nvs_setDVRConfig( sCameraID, identify,  dwCommand, lChannel, lpInBuffer, dwInBufferSize);
}

int  NVSPlayLibLux::nvs_getRecordFileEx(string sCameraID,intptr_t identify,RECORDQUERYTYPE nType,char* startTime,char* endTime,RECORDFILE pRecordFile[],int nMaxFileCount)
{
	if (!m_hDllLux)	return NULL;

	if (!m_lp_nvs_getRecordFileEx)
	{
		m_lp_nvs_getRecordFileEx = (lp_nvs_getRecordFileEx)GetProcAddress(m_hDllLux,"nvs_getRecordFileEx");
	}
	if (!m_lp_nvs_getRecordFileEx) return NULL;

	return m_lp_nvs_getRecordFileEx( sCameraID, identify,  nType, startTime, endTime, pRecordFile,nMaxFileCount);
}

intptr_t NVSPlayLibLux::nvs_downloadRecordFile(string sCameraID,intptr_t identify,char* fileName,char* startTime, char* endTime,int nFileSize,char* saveFile,LPDOWNLOADRECORDFILECALLBACK lpCallBack,void* pUser)
{
	if (!m_hDllLux)	return NULL;

	if (!m_lp_nvs_downloadRecordFile)
	{
		m_lp_nvs_downloadRecordFile = (lp_nvs_downloadRecordFile)GetProcAddress(m_hDllLux,"nvs_downloadRecordFile");
	}
	if (!m_lp_nvs_downloadRecordFile) return NULL;

	return m_lp_nvs_downloadRecordFile(sCameraID, identify,fileName, startTime, endTime, nFileSize,saveFile,lpCallBack,pUser);
}

bool NVSPlayLibLux::nvs_stopDownloadRecordFile(intptr_t identify,intptr_t ldownFileHandle)
{
	if (!m_hDllLux)	return NULL;

	if (!m_lp_nvs_stopDownloadRecordFile)
	{
		m_lp_nvs_stopDownloadRecordFile = (lp_nvs_stopDownloadRecordFile)GetProcAddress(m_hDllLux,"nvs_stopDownloadRecordFile");
	}
	if (!m_lp_nvs_stopDownloadRecordFile) return NULL;

	return m_lp_nvs_stopDownloadRecordFile(identify,ldownFileHandle);
}

int NVSPlayLibLux::nvs_getDownloadPos(intptr_t identify,intptr_t lFileHandle)
{
	if (!m_hDllLux)	return NULL;

	if (!m_lp_nvs_getDownloadPos)
	{
		m_lp_nvs_getDownloadPos = (lp_nvs_getDownloadPos)GetProcAddress(m_hDllLux,"nvs_getDownloadPos");
	}
	if (!m_lp_nvs_getDownloadPos) return NULL;

	return m_lp_nvs_getDownloadPos(identify,lFileHandle);
}

intptr_t NVSPlayLibLux::nvs_replayRecordFile(string sCameraID,intptr_t identify,int hWnd,char* fileName,char* startTime, char* endTime,int nFileSize)
{
	if (!m_hDllLux)	return NULL;

	if (!m_lp_nvs_replayRecordFile)
	{
		m_lp_nvs_replayRecordFile = (lp_nvs_replayRecordFile)GetProcAddress(m_hDllLux,"nvs_replayRecordFile");
	}
	if (!m_lp_nvs_replayRecordFile) return NULL;

	return m_lp_nvs_replayRecordFile( sCameraID, identify, hWnd, fileName, startTime,  endTime,nFileSize);
}

bool NVSPlayLibLux::nvs_controlReplayRecordFile(intptr_t identify,intptr_t lReplayHandle,int nCmd,int nInValue,int* outValue)
{
	if (!m_hDllLux)	return NULL;

	if (!m_lp_nvs_controlReplayRecordFile)
	{
		m_lp_nvs_controlReplayRecordFile = (lp_nvs_controlReplayRecordFile)GetProcAddress(m_hDllLux,"nvs_controlReplayRecordFile");
	}
	if (!m_lp_nvs_controlReplayRecordFile) return NULL;

	return m_lp_nvs_controlReplayRecordFile(identify,lReplayHandle,nCmd,nInValue,outValue);
}

bool NVSPlayLibLux::nvs_stopReplayRecordFile(intptr_t identify,intptr_t lReplayHandle)
{
	if (!m_hDllLux)	return NULL;

	if (!m_lp_nvs_stopReplayRecordFile)
	{
		m_lp_nvs_stopReplayRecordFile = (lp_nvs_stopReplayRecordFile)GetProcAddress(m_hDllLux,"nvs_stopReplayRecordFile");
	}
	if (!m_lp_nvs_stopReplayRecordFile) return NULL;

	return m_lp_nvs_stopReplayRecordFile( identify,lReplayHandle);
}

bool NVSPlayLibLux::nvs_startTalk(string sCameraID,intptr_t identify)
{
	if (!m_hDllLux)	return NULL;

	if (!m_lp_nvs_startTalk)
	{
		m_lp_nvs_startTalk = (lp_nvs_startTalk)GetProcAddress(m_hDllLux,"nvs_startTalk");
	}
	if (!m_lp_nvs_startTalk) return NULL;

	return m_lp_nvs_startTalk(sCameraID,identify);
}

bool NVSPlayLibLux::nvs_stopTalk(string sCameraID,intptr_t identify)
{
	if (!m_hDllLux)	return NULL;

	if (!m_lp_nvs_stopTalk)
	{
		m_lp_nvs_stopTalk = (lp_nvs_stopTalk)GetProcAddress(m_hDllLux,"nvs_stopTalk");
	}
	if (!m_lp_nvs_stopTalk) return NULL;

	return m_lp_nvs_stopTalk( sCameraID,identify);
}

bool NVSPlayLibLux::nvs_getDVRWorkState(intptr_t identify,char dvrWorkState[],int arrayLen)
{
	if (!m_hDllLux)	return NULL;

	if (!m_lp_nvs_getDVRWorkState)
	{
		m_lp_nvs_getDVRWorkState = (lp_nvs_getDVRWorkState)GetProcAddress(m_hDllLux,"nvs_getDVRWorkState");
	}
	if (!m_lp_nvs_getDVRWorkState) return NULL;

	return m_lp_nvs_getDVRWorkState(identify,dvrWorkState,arrayLen);
}

DWORD NVSPlayLibLux::nvs_getLastError(string sCameraID,intptr_t identify)
{
	if (!m_hDllLux)	return NULL;

	if (!m_lp_nvs_getLastError)
	{
		m_lp_nvs_getLastError = (lp_nvs_getLastError)GetProcAddress(m_hDllLux,"nvs_getLastError");
	}
	if (!m_lp_nvs_getLastError) return NULL;

	return m_lp_nvs_getLastError(sCameraID,identify);
}

bool NVSPlayLibLux::nvs_playBackCaptureFile(intptr_t identify , intptr_t  lReplayHandle, char *pFileName)
{
	if (!m_hDllLux)	return NULL;

	if (!m_lp_nvs_playBackCaptureFile)
	{
		m_lp_nvs_playBackCaptureFile = (lp_nvs_playBackCaptureFile)GetProcAddress(m_hDllLux,"nvs_playBackCaptureFile");
	}
	if (!m_lp_nvs_playBackCaptureFile) return NULL;

	return m_lp_nvs_playBackCaptureFile( identify ,lReplayHandle, pFileName);
}

bool NVSPlayLibLux::nvs_playBackSaveData(intptr_t identify,intptr_t lReplayHandle,char *sFileName)
{
	if (!m_hDllLux)	return NULL;

	if (!m_lp_nvs_playBackSaveData)
	{
		m_lp_nvs_playBackSaveData = (lp_nvs_playBackSaveData)GetProcAddress(m_hDllLux,"nvs_playBackSaveData");
	}
	if (!m_lp_nvs_playBackSaveData) return NULL;

	return m_lp_nvs_playBackSaveData(identify, lReplayHandle,sFileName);
}

bool NVSPlayLibLux::nvs_stopPlayBackSave(intptr_t identify,intptr_t lReplayHandle)
{
	if (!m_hDllLux)	return NULL;

	if (!m_lp_nvs_stopPlayBackSave)
	{
		m_lp_nvs_stopPlayBackSave = (lp_nvs_stopPlayBackSave)GetProcAddress(m_hDllLux,"nvs_stopPlayBackSave");
	}
	if (!m_lp_nvs_stopPlayBackSave) return NULL;

	return m_lp_nvs_stopPlayBackSave( identify, lReplayHandle);
}

bool NVSPlayLibLux::nvs_startRecordByCode(string sCameraID,intptr_t identify,  char* saveFile)
{
	if (!m_hDllLux)	return NULL;

	if (!m_lp_nvs_startRecordByCode)
	{
		m_lp_nvs_startRecordByCode = (lp_nvs_startRecordByCode)GetProcAddress(m_hDllLux,"nvs_startRecordByCode");
	}
	if (!m_lp_nvs_startRecordByCode) return NULL;

	return m_lp_nvs_startRecordByCode( sCameraID, identify,   saveFile);
}

bool NVSPlayLibLux::nvs_stopRecordByCode(string sCameraID,intptr_t identify)
{
	if (!m_hDllLux)	return NULL;

	if (!m_lp_nvs_stopRecordByCode)
	{
		m_lp_nvs_stopRecordByCode = (lp_nvs_stopRecordByCode)GetProcAddress(m_hDllLux,"nvs_stopRecordByCode");
	}
	if (!m_lp_nvs_stopRecordByCode) return NULL;

	return m_lp_nvs_stopRecordByCode( sCameraID, identify);
}

bool NVSPlayLibLux::nvs_SetCropArea(string sCameraID,intptr_t identify, bool bFlag, int x1, int y1, int x2 , int y2)
{
	if (!m_hDllLux)	return NULL;

	if (!m_lp_nvs_SetCropArea)
	{
		m_lp_nvs_SetCropArea = (lp_nvs_SetCropArea)GetProcAddress(m_hDllLux,"nvs_SetCropArea");
	}
	if (!m_lp_nvs_SetCropArea) return NULL;

	return m_lp_nvs_SetCropArea( sCameraID, identify,  bFlag,  x1,  y1,  x2,  y2 );
}

bool NVSPlayLibLux::nvs_SetDecodeParam(string sCameraID,intptr_t identify, int nCmd, bool bFlag, int x1, int y1, int x2 , int y2)
{
	if (!m_hDllLux)	return NULL;

	if (!m_lp_nvs_SetDecodeParam)
	{
		m_lp_nvs_SetDecodeParam = (lp_nvs_SetDecodeParam)GetProcAddress(m_hDllLux,"nvs_SetDecodeParam");
	}
	if (!m_lp_nvs_SetDecodeParam) return NULL;

	return m_lp_nvs_SetDecodeParam( sCameraID, identify, nCmd,  bFlag,  x1,  y1,  x2,  y2 );
}

bool NVSPlayLibLux::nvs_SetStreamSaveTime(string sCameraID,intptr_t identify, int nSaveTime )
{
	if (!m_hDllLux)	return NULL;

	if (!m_lp_nvs_SetStreamSaveTime)
	{
		m_lp_nvs_SetStreamSaveTime = (lp_nvs_SetStreamSaveTime)GetProcAddress(m_hDllLux,"nvs_SetStreamSaveTime");
	}
	if (!m_lp_nvs_SetStreamSaveTime) return NULL;

	return m_lp_nvs_SetStreamSaveTime( sCameraID, identify,  nSaveTime );
}

bool NVSPlayLibLux::nvs_PlayBackSaveStream(string sCameraID,intptr_t identify, HWND hWnd)
{
	if (!m_hDllLux)	return NULL;

	if (!m_lp_nvs_PlayBackSaveStream)
	{
		m_lp_nvs_PlayBackSaveStream = (lp_nvs_PlayBackSaveStream)GetProcAddress(m_hDllLux,"nvs_PlayBackSaveStream");
	}
	if (!m_lp_nvs_PlayBackSaveStream) return NULL;

	return m_lp_nvs_PlayBackSaveStream( sCameraID, identify,  hWnd);
}

bool NVSPlayLibLux::nvs_StopPlayBackSaveStream(string sCameraID,intptr_t identify)
{
	if (!m_hDllLux)	return NULL;

	if (!m_lp_nvs_StopPlayBackSaveStream)
	{
		m_lp_nvs_StopPlayBackSaveStream = (lp_nvs_StopPlayBackSaveStream)GetProcAddress(m_hDllLux,"nvs_StopPlayBackSaveStream");
	}
	if (!m_lp_nvs_StopPlayBackSaveStream) return NULL;

	return m_lp_nvs_StopPlayBackSaveStream(sCameraID, identify);
}

bool NVSPlayLibLux::nvs_SetRenderMode(string sCameraID,intptr_t identify, int nMode)
{
	if (!m_hDllLux)	return NULL;

	if (!m_lp_nvs_SetRenderMode)
	{
		m_lp_nvs_SetRenderMode = (lp_nvs_SetRenderMode)GetProcAddress(m_hDllLux,"nvs_SetRenderMode");
	}
	if (!m_lp_nvs_SetRenderMode) return NULL;

	return m_lp_nvs_SetRenderMode( sCameraID, identify,  nMode);
}

bool NVSPlayLibLux::nvs_SetPosByFrameNum(string sCameraID,intptr_t identify,DWORD nFrameNum)
{
	if (!m_hDllLux)	return NULL;

	if (!m_lp_nvs_SetPosByFrameNum)
	{
		m_lp_nvs_SetPosByFrameNum = (lp_nvs_SetPosByFrameNum)GetProcAddress(m_hDllLux,"nvs_SetPosByFrameNum");
	}
	if (!m_lp_nvs_SetPosByFrameNum) return NULL;

	return m_lp_nvs_SetPosByFrameNum( sCameraID, identify, nFrameNum);
}

bool NVSPlayLibLux::nvs_GetVideoCut(string sCameraID,intptr_t identify, DWORD beginFrame, DWORD endFrame, LPSTR filename)
{
	if (!m_hDllLux)	return NULL;

	if (!m_lp_nvs_GetVideoCut)
	{
		m_lp_nvs_GetVideoCut = (lp_nvs_GetVideoCut)GetProcAddress(m_hDllLux,"nvs_GetVideoCut");
	}
	if (!m_lp_nvs_GetVideoCut) return NULL;

	return m_lp_nvs_GetVideoCut( sCameraID, identify,  beginFrame,  endFrame,  filename);
}

bool NVSPlayLibLux::nvs_StopCutVideo(string sCameraID,intptr_t identify)
{
	if (!m_hDllLux)	return NULL;

	if (!m_lp_nvs_StopCutVideo)
	{
		m_lp_nvs_StopCutVideo = (lp_nvs_StopCutVideo)GetProcAddress(m_hDllLux,"nvs_StopCutVideo");
	}
	if (!m_lp_nvs_StopCutVideo) return NULL;

	return m_lp_nvs_StopCutVideo( sCameraID, identify);
}

bool NVSPlayLibLux::nvs_SetFileEndCallback(string sCameraID,intptr_t identify, void *pUser, pFileOverCB pCallBack)
{
	if (!m_hDllLux)	return NULL;

	if (!m_lp_nvs_SetFileEndCallback)
	{
		m_lp_nvs_SetFileEndCallback = (lp_nvs_SetFileEndCallback)GetProcAddress(m_hDllLux,"nvs_SetFileEndCallback");
	}
	if (!m_lp_nvs_SetFileEndCallback) return NULL;

	return m_lp_nvs_SetFileEndCallback( sCameraID, identify, pUser, pCallBack);
}

bool NVSPlayLibLux::nvs_GetMediaInfo(string sCameraID,intptr_t identify,MediaInf &mInf)
{
	if (!m_hDllLux)	return NULL;

	if (!m_lp_nvs_GetMediaInfo)
	{
		m_lp_nvs_GetMediaInfo = (lp_nvs_GetMediaInfo)GetProcAddress(m_hDllLux,"nvs_GetMediaInfo");
	}
	if (!m_lp_nvs_GetMediaInfo) return NULL;

	return m_lp_nvs_GetMediaInfo( sCameraID, identify, mInf);
}

bool NVSPlayLibLux::nvs_GetDecodeParam(string sCameraID,intptr_t identify, int nCmd, int &x1, int &y1, int &x2, int &y2)
{
	if (!m_hDllLux)	return NULL;

	if (!m_lp_nvs_GetDecodeParam)
	{
		m_lp_nvs_GetDecodeParam = (lp_nvs_GetDecodeParam)GetProcAddress(m_hDllLux,"nvs_GetDecodeParam");
	}
	if (!m_lp_nvs_GetDecodeParam) return NULL;

	return m_lp_nvs_GetDecodeParam( sCameraID, identify,  nCmd,  x1, y1, x2, y2);
}

bool NVSPlayLibLux::nvs_startPlayer4Standard(string sCameraID,intptr_t identify,HWND hWnd,LPDecCBFun lpDecCBFun, int nCameraID)
{
	if (!m_hDllLux)	return NULL;

	if (!m_lp_nvs_startPlayer4Standard)
	{
		m_lp_nvs_startPlayer4Standard = (lp_nvs_startPlayer4Standard)GetProcAddress(m_hDllLux,"nvs_startPlayer4Standard");
	}
	if (!m_lp_nvs_startPlayer4Standard) return NULL;

	return m_lp_nvs_startPlayer4Standard(sCameraID,identify,hWnd,lpDecCBFun,nCameraID);
}

bool NVSPlayLibLux::nvs_SetYUVCallBack(string sCameraID,intptr_t identify, LPYUVCALLBACK pCallBack)
{
	if (!m_hDllLux)	return NULL;

	if (!m_lp_nvs_SetYUVCallBack)
	{
		m_lp_nvs_SetYUVCallBack = (lp_nvs_SetYUVCallBack)GetProcAddress(m_hDllLux,"nvs_SetYUVCallBack");
	}
	if (!m_lp_nvs_SetYUVCallBack) return NULL;

	return m_lp_nvs_SetYUVCallBack(sCameraID,identify,pCallBack);
}

bool NVSPlayLibLux::nvs_getRecordFileBySource(string sCameraID,intptr_t identify,int nType, char* startTime, char* endTime, int nRecordSource)
{
	if (!m_hDllLux)	return NULL;

	if (!m_lp_nvs_getRecordFileBySource)
	{
		m_lp_nvs_getRecordFileBySource = (lp_nvs_getRecordFileBySource)GetProcAddress(m_hDllLux,"nvs_getRecordFileBySource");
	}
	if (!m_lp_nvs_getRecordFileBySource) return NULL;

	return m_lp_nvs_getRecordFileBySource(sCameraID,identify, nType,  startTime,  endTime, nRecordSource);
}

intptr_t NVSPlayLibLux::nvs_downloadRecordFileBySource(string sCameraID,intptr_t identify,char* fileName,char* startTime, char* endTime,int nFileSize,char* saveFile,LPDOWNLOADRECORDFILECALLBACK lpCallBack,void* pUser, int nRecordSource)
{
	if (!m_hDllLux)	return NULL;

	if (!m_lp_nvs_downloadRecordFileBySource)
	{
		m_lp_nvs_downloadRecordFileBySource = (lp_nvs_downloadRecordFileBySource)GetProcAddress(m_hDllLux,"nvs_downloadRecordFileBySource");
	}
	if (!m_lp_nvs_downloadRecordFileBySource) return NULL;

	return m_lp_nvs_downloadRecordFileBySource(sCameraID,identify, fileName, startTime,  endTime, nFileSize, saveFile,lpCallBack, pUser, nRecordSource);
}
