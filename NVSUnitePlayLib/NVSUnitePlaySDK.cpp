#include "stdafx.h"
#include "NVSUnitePlaySDK.h"
#include "NVSCore.h"

NVSCore G_Core;
#define XY_FAIL_PLAYLIB_OBJECT -30

void nvs_selectLib(char cType)
{
	G_Core.Init(cType);
}
bool nvs_initEnviroment(const char* pAddress,unsigned short nPort,int nRight, char type)
{
	if (!G_Core.m_pPlayLib) return false;
	return G_Core.m_pPlayLib->nvs_initEnviroment(pAddress, nPort, nRight, type);
}
void nvs_cleanEnviroment()
{
	if (!G_Core.m_pPlayLib) return;
	return G_Core.m_pPlayLib->nvs_cleanEnviroment();
}
bool nvs_registerOnIndex()
{
	if (!G_Core.m_pPlayLib) return false;
	return G_Core.m_pPlayLib->nvs_registerOnIndex();
}
void nvs_setPlayModel(int nPlayModel)
{
	if (!G_Core.m_pPlayLib) return;
	G_Core.m_pPlayLib->nvs_setPlayModel(nPlayModel);
}
void nvs_setDecordCardCallBack(PlayResultByDecordCard pFun)
{
	if (!G_Core.m_pPlayLib) return;
	G_Core.m_pPlayLib->nvs_setDecordCardCallBack(pFun);
}
void nvs_setRealPlayCallBack(RealPlayCallBack pFun)
{
	if (!G_Core.m_pPlayLib) return;
	G_Core.m_pPlayLib->nvs_setRealPlayCallBack(pFun);
}
void nvs_setRealDecodeCallBack(LPDecCBFun pFun)
{
	if (!G_Core.m_pPlayLib) return;
	G_Core.m_pPlayLib->nvs_setRealDecodeCallBack(pFun);
}
void nvs_setIndexNoticeCallBack(IndexNoticeCallBack pFun)
{
	if (!G_Core.m_pPlayLib) return;
	G_Core.m_pPlayLib->nvs_setIndexNoticeCallBack(pFun);
}
void nvs_setDVRNoticeCallBack(DVRNoticeCallBack pFun)
{
	if (!G_Core.m_pPlayLib) return;
	G_Core.m_pPlayLib->nvs_setDVRNoticeCallBack(pFun);
}
void nvs_setNoticeSwitchedCallBack(NoticeSwitchedCallBack pFun)
{
	if (!G_Core.m_pPlayLib) return;
	G_Core.m_pPlayLib->nvs_setNoticeSwitchedCallBack(pFun);
}
int  nvs_playVideoByDecordCard(int nCameraID,int nCardIndex, HANDLE* hStreamPlayHandle)
{
	if (!G_Core.m_pPlayLib) return XY_FAIL_PLAYLIB_OBJECT;
	return G_Core.m_pPlayLib->nvs_playVideoByDecordCard(nCameraID,nCardIndex,hStreamPlayHandle);
}
int nvs_playVideo2(int nCameraID,HWND hWnd, bool bUseDecode,bool bIsExternalDvr )
{
	if (!G_Core.m_pPlayLib) return XY_FAIL_PLAYLIB_OBJECT;
	return G_Core.m_pPlayLib->nvs_playVideo2(nCameraID,hWnd, bUseDecode,bIsExternalDvr);
}

int nvs_playVideo(int nCameraID,HWND hWnd, bool bUseDecode )
{
	if (!G_Core.m_pPlayLib) return XY_FAIL_PLAYLIB_OBJECT;
	return G_Core.m_pPlayLib->nvs_playVideo(nCameraID, hWnd, bUseDecode);
}
bool nvs_stopPlayVideo(HWND hWnd, int nCardIndex, int nCameraID)
{
	if (!G_Core.m_pPlayLib) return false;
	return G_Core.m_pPlayLib->nvs_stopPlayVideo(hWnd, nCardIndex, nCameraID);
}
bool nvs_stopPlayByCameraID(int nCameraID)
{
	if (!G_Core.m_pPlayLib) return false;
	return G_Core.m_pPlayLib->nvs_stopPlayByCameraID(nCameraID);
}
void nvs_stopAll()
{
	if (!G_Core.m_pPlayLib) return;
	G_Core.m_pPlayLib->nvs_stopAll();
}
bool nvs_controlCameraSpeed(int nCameraID,int nCmd,bool bControl,int nSpeed)
{
	if (!G_Core.m_pPlayLib) return false;
	return G_Core.m_pPlayLib->nvs_controlCameraSpeed(nCameraID,nCmd,bControl,nSpeed);
}
bool nvs_cancelControlCamera(HWND hWnd,int nCameraID)
{
	if (!G_Core.m_pPlayLib) return false;
	return G_Core.m_pPlayLib->nvs_cancelControlCamera(hWnd,nCameraID);
}
bool nvs_capturePictureEx(int nCameraID, char* pFileName)
{
	if (!G_Core.m_pPlayLib) return false;
	return G_Core.m_pPlayLib->nvs_capturePictureEx(nCameraID,pFileName);
}
bool nvs_TransPTZ(int nCameraID, int nCmd, int nTransPTZIndex)
{
	if (!G_Core.m_pPlayLib) return false;
	return G_Core.m_pPlayLib->nvs_TransPTZ(nCameraID,nCmd,nTransPTZIndex);
}
bool nvs_getCompress(int nCameraID, char **lpOutBuffer)
{
	if (!G_Core.m_pPlayLib) return false;
	return G_Core.m_pPlayLib->nvs_getCompress(nCameraID,lpOutBuffer);
}
bool nvs_setCompress(int nCameraID, char* pCompressInfo)
{
	if (!G_Core.m_pPlayLib) return false;
	return G_Core.m_pPlayLib->nvs_setCompress(nCameraID,pCompressInfo);
}
bool nvs_getVideoEffect(int nCameraID, int* pBrightValue,int* pContrastValue, int* pSaturationValue,int* pHueValue)
{
	if (!G_Core.m_pPlayLib) return false;
	return G_Core.m_pPlayLib->nvs_getVideoEffect(nCameraID,pBrightValue,pContrastValue,pSaturationValue,pHueValue);
}
bool nvs_setVideoEffect(int nCameraID, DWORD dwBrightValue,DWORD dwContrastValue, DWORD dwSaturationValue,DWORD dwHueValue)
{ 
	if (!G_Core.m_pPlayLib) return false;
	return G_Core.m_pPlayLib->nvs_setVideoEffect(nCameraID,dwBrightValue,dwContrastValue,dwSaturationValue,dwHueValue);
}
int nvs_startRecord(int nCameraID, char* pFileName)
{
	if (!G_Core.m_pPlayLib) return XY_FAIL_PLAYLIB_OBJECT;
	return G_Core.m_pPlayLib->nvs_startRecord(nCameraID,pFileName);
}
bool nvs_stopRecord(int nCameraID)
{
	if (!G_Core.m_pPlayLib) return false;
	return G_Core.m_pPlayLib->nvs_stopRecord(nCameraID);
}
bool nvs_serialSend(int nCameraID, char* cmd1, DWORD nLen1, char* cmd2, DWORD nLen2)
{
	if (!G_Core.m_pPlayLib) return false;
	return G_Core.m_pPlayLib->nvs_serialSend(nCameraID,cmd1,nLen1,cmd2,nLen2);
}
void nvs_reSetDDrawDevice(int nCameraID)
{
	if (!G_Core.m_pPlayLib) return;
	G_Core.m_pPlayLib->nvs_reSetDDrawDevice(nCameraID);
}

int nvs_splitFile(int nCameraID,char* sFileName,int nPriorTime)
{
	if (!G_Core.m_pPlayLib) return XY_FAIL_PLAYLIB_OBJECT;
	return G_Core.m_pPlayLib->nvs_splitFile(nCameraID,sFileName,nPriorTime);
}

int nvs_play4Storage(int nCameraID,char* sFileName,int nPriorTime)
{
	if (!G_Core.m_pPlayLib) return XY_FAIL_PLAYLIB_OBJECT;
	return G_Core.m_pPlayLib->nvs_play4Storage(nCameraID,sFileName,nPriorTime);
}

bool nvs_stopPlay4Storage(int nCameraID)
{
	if (!G_Core.m_pPlayLib) return false;
	return G_Core.m_pPlayLib->nvs_stopPlay4Storage(nCameraID);
}

bool nvs_controlCameraSound(int nCameraID, bool bOpenSound)
{
	if (!G_Core.m_pPlayLib) return false;
	return G_Core.m_pPlayLib->nvs_controlCameraSound(nCameraID,bOpenSound);
}

bool nvs_clientNotice()
{
	if (!G_Core.m_pPlayLib) return false;
	return G_Core.m_pPlayLib->nvs_clientNotice();
}

intptr_t nvs_loginDVR(char* sIP, int nPort, char* sUser, char* sPwd)
{
	if (!G_Core.m_pPlayLib) return XY_FAIL_PLAYLIB_OBJECT;
	return G_Core.m_pPlayLib->nvs_loginDVR(sIP, nPort, sUser, sPwd);
}

void nvs_logoutDVR(intptr_t identify)
{
	if (!G_Core.m_pPlayLib) return;
	G_Core.m_pPlayLib->nvs_logoutDVR(identify);
}

bool nvs_playVideoByDVR(intptr_t identify,int nCameraID,HWND hWnd)
{
	if (!G_Core.m_pPlayLib) return false;
	return G_Core.m_pPlayLib->nvs_playVideoByDVR(identify,nCameraID,hWnd);
}
bool nvs_stopPlayVideoByDVR(intptr_t identify,HWND hWnd)
{
	if (!G_Core.m_pPlayLib) return false;
	return G_Core.m_pPlayLib->nvs_stopPlayVideoByDVR(identify,hWnd);
}

bool nvs_controlCameraSpeedByDVR(intptr_t identify,int nCameraID,int nCmd, bool bControl, int nSpeed, int nChannel)
{
	if (!G_Core.m_pPlayLib) return false;
	return G_Core.m_pPlayLib->nvs_controlCameraSpeedByDVR(identify,nCameraID,nCmd,bControl,nSpeed,nChannel);
}

bool nvs_presetPTZByDVR(intptr_t identify,int nCameraID, int nCmd, int nTransPTZIndex, int nChannel)
{
	if (!G_Core.m_pPlayLib) return false;
	return G_Core.m_pPlayLib->nvs_presetPTZByDVR(identify,nCameraID,nCmd,nTransPTZIndex,nChannel);
}

intptr_t nvs_getCameraInfo(intptr_t identify,int *nSize)
{
	if (!G_Core.m_pPlayLib) return XY_FAIL_PLAYLIB_OBJECT;
	return G_Core.m_pPlayLib->nvs_getCameraInfo(identify,nSize);
}

int nvs_setPlayWindow(HWND palyWindow[], int nMaxCount)
{
	if (!G_Core.m_pPlayLib) return XY_FAIL_PLAYLIB_OBJECT;
	return G_Core.m_pPlayLib->nvs_setPlayWindow(palyWindow,nMaxCount);
}

bool nvs_InitHSServer(char *strIP, int nPort)
{
	if (!G_Core.m_pPlayLib) return false;
	return G_Core.m_pPlayLib->nvs_InitHSServer(strIP,nPort);
}

intptr_t nvs_getStreamServerWorkState(int nCameraID, int nCameraCount, int *outSize )
{
	if (!G_Core.m_pPlayLib) return XY_FAIL_PLAYLIB_OBJECT;
	return G_Core.m_pPlayLib->nvs_getStreamServerWorkState(nCameraID, nCameraCount, outSize );
}


char * nvs_getStreamServerIP( int nCameraID)
{
	if (!G_Core.m_pPlayLib) return NULL;
	return G_Core.m_pPlayLib->nvs_getStreamServerIP( nCameraID);
}

void nvs_SetExternalClient(bool bIsExternal)
{
	if (!G_Core.m_pPlayLib) return;
	G_Core.m_pPlayLib->nvs_SetExternalClient(bIsExternal);
}

void nvs_writeLog(char* logMsg, int level)
{
	if(!G_Core.m_pPlayLib) return;
	G_Core.m_pPlayLib->nvs_writeLog(logMsg,level);
}

void nvs_SetHsCallBack(HsUserCallBack CallbackFun)
{
	if (!G_Core.m_pPlayLib) return;
	G_Core.m_pPlayLib->nvs_SetHsCallBack(CallbackFun);
}

void nvs_SetVedioHeadStreamCallBack(LPVedioHeadStreamCBFun pFun)
{
	if (!G_Core.m_pPlayLib) return;
	G_Core.m_pPlayLib->nvs_SetVedioHeadStreamCallBack(pFun);
}

void nvs_SetVedioBodyStreamCallBack(LPVedioBodyStreamCBFun pFun)
{
	if (!G_Core.m_pPlayLib) return;
		G_Core.m_pPlayLib->nvs_SetVedioBodyStreamCallBack(pFun);
}

void nvs_SetDrawFun(LPDrawCBFun pFun)
{
	if (!G_Core.m_pPlayLib) return;
		G_Core.m_pPlayLib->nvs_SetDrawFun(pFun);	
}


void nvs_SetUserIDandOrgID(int nUserID,int OrgID)
{
	if(!G_Core.m_pPlayLib) return;
	G_Core.m_pPlayLib->nvs_SetUserIDandOrgID(nUserID,OrgID);
}

const char* nvs_GetErrorMessage(int nErrorCode)
{
	if(!G_Core.m_pPlayLib) return 0;
	return G_Core.m_pPlayLib->nvs_GetErrorMessage(nErrorCode);
}


int  nvs_stdVideoinit(pNVSSipCallback pCB, void *pUser)
{
	if(!G_Core.m_pPlayLib) return 0;
	return G_Core.m_pPlayLib->nvs_stdVideoinit(pCB,pUser);
}

int  nvs_playStdVideo(char* sCameraID,HWND hWnd ,char* sIP, int nPort, char* sUser, char* sPwd ,char* sDllType, LPREALSTREAMCALLBACK lpCallBack, void* pUser)
{
	if(!G_Core.m_pPlayLib) return 0;
	return G_Core.m_pPlayLib->nvs_playStdVideo(sCameraID,hWnd,sIP,nPort,sUser,sPwd,sDllType,lpCallBack,pUser);
}

int  nvs_stopStdVideo(char* sCameraID,HWND hWnd)
{
	if(!G_Core.m_pPlayLib) return 0;
	return G_Core.m_pPlayLib->nvs_stopStdVideo(sCameraID,hWnd);
}

int  nvs_startPlayMonitor(char* sCameraCode, char *sMonitorCode,char* sIP, int nPort, char* sUser, char* sPwd ,char* sDllType)
{
	if(!G_Core.m_pPlayLib) return 0;
	return G_Core.m_pPlayLib->nvs_startPlayMonitor(sCameraCode,sMonitorCode,sIP,nPort,sUser,sPwd,sDllType);
}

int  nvs_stopPlayMonitor(char* sMonitorCode)
{
	if(!G_Core.m_pPlayLib) return 0;
	return G_Core.m_pPlayLib->nvs_stopPlayMonitor(sMonitorCode);
}

bool nvs_capturePictureByCode(char* sCameraCode, char* sFilePath)
{
	if(!G_Core.m_pPlayLib) return 0;
	return G_Core.m_pPlayLib->nvs_capturePictureByCode(sCameraCode,sFilePath);
}

void nvs_makeKey(char* sCameraCode)
{
	if(!G_Core.m_pPlayLib) return;
	return G_Core.m_pPlayLib->nvs_makeKey(sCameraCode);
}

intptr_t nvs_connectDVR(char* sIP, int nPort, char* sUser, char* sPwd, int nChannel ,char* sDllType)
{
	if(!G_Core.m_pPlayLib) return 0;
	return G_Core.m_pPlayLib->nvs_connectDVR(sIP, nPort, sUser, sPwd ,nChannel ,sDllType);
}

void nvs_disconnectDVR(intptr_t identify)
{
	if(!G_Core.m_pPlayLib) return;
	return G_Core.m_pPlayLib->nvs_disconnectDVR(identify);
}

bool nvs_controlPTZSpeedWithChannel(string sCameraID,intptr_t identify,int nCmd, bool bEnable, int nSpeed, int nChannel)
{
	if(!G_Core.m_pPlayLib) return 0;
	return G_Core.m_pPlayLib->nvs_controlPTZSpeedWithChannel(sCameraID,identify, nCmd,  bEnable,  nSpeed,  nChannel);
}

bool nvs_presetPTZWithChannel(string sCameraID,intptr_t identify, int nCmd, int nIndex, int nChannel)
{
	if(!G_Core.m_pPlayLib) return 0;
	return G_Core.m_pPlayLib->nvs_presetPTZWithChannel( sCameraID, identify,  nCmd,  nIndex,  nChannel);
}

bool nvs_setVideoEffectByCode(string sCameraID,intptr_t identify,DWORD dwBrightValue,DWORD dwContrastValue, DWORD dwSaturationValue,DWORD dwHueValue)
{
	if(!G_Core.m_pPlayLib) return 0;
	return G_Core.m_pPlayLib->nvs_setVideoEffectByCode( sCameraID, identify,  dwBrightValue, dwContrastValue,  dwSaturationValue, dwHueValue);
}

bool nvs_getVideoEffectByCode(string sCameraID,intptr_t identify,DWORD *pBrightValue,DWORD *pContrastValue, DWORD *pSaturationValue,DWORD *pHueValue)
{
	if(!G_Core.m_pPlayLib) return 0;
	return G_Core.m_pPlayLib->nvs_getVideoEffectByCode( sCameraID, identify, pBrightValue, pContrastValue,  pSaturationValue, pHueValue);
}

bool nvs_getDVRConfig(string sCameraID,intptr_t identify, DWORD dwCommand,LONG lChannel,LPVOID lpOutBuffer,DWORD dwOutBufferSize,LPDWORD lpBytesReturned)
{
	if(!G_Core.m_pPlayLib) return 0;
	return G_Core.m_pPlayLib->nvs_getDVRConfig( sCameraID, identify,  dwCommand, lChannel, lpOutBuffer, dwOutBufferSize,lpBytesReturned);
}

bool nvs_setDVRConfig(string sCameraID,intptr_t identify, DWORD dwCommand,LONG lChannel,LPVOID lpInBuffer,DWORD dwInBufferSize)
{
	if(!G_Core.m_pPlayLib) return 0;
	return G_Core.m_pPlayLib->nvs_setDVRConfig( sCameraID, identify,  dwCommand, lChannel, lpInBuffer, dwInBufferSize);
}

int  nvs_getRecordFileEx(string sCameraID,intptr_t identify,RECORDQUERYTYPE nType,char* startTime,char* endTime,RECORDFILE pRecordFile[],int nMaxFileCount)
{
	if(!G_Core.m_pPlayLib) return 0;
	return G_Core.m_pPlayLib->nvs_getRecordFileEx( sCameraID, identify,  nType, startTime, endTime, pRecordFile,nMaxFileCount);
}

intptr_t nvs_downloadRecordFile(string sCameraID,intptr_t identify,char* fileName,char* startTime, char* endTime,int nFileSize,char* saveFile,LPDOWNLOADRECORDFILECALLBACK lpCallBack,void* pUser)
{
	if(!G_Core.m_pPlayLib) return 0;
	return G_Core.m_pPlayLib->nvs_downloadRecordFile(sCameraID, identify,fileName, startTime, endTime, nFileSize,saveFile,lpCallBack,pUser);
}

bool nvs_stopDownloadRecordFile(intptr_t identify,intptr_t ldownFileHandle)
{
	if(!G_Core.m_pPlayLib) return 0;
	return G_Core.m_pPlayLib->nvs_stopDownloadRecordFile(identify,ldownFileHandle);
}

int nvs_getDownloadPos(intptr_t identify,intptr_t lFileHandle)
{
	if(!G_Core.m_pPlayLib) return 0;
	return G_Core.m_pPlayLib->nvs_getDownloadPos(identify,lFileHandle);
}

intptr_t nvs_replayRecordFile(string sCameraID,intptr_t identify,int hWnd,char* fileName,char* startTime, char* endTime,int nFileSize)
{
	if(!G_Core.m_pPlayLib) return 0;
	return G_Core.m_pPlayLib->nvs_replayRecordFile( sCameraID, identify, hWnd, fileName, startTime,  endTime,nFileSize);
}

bool nvs_controlReplayRecordFile(intptr_t identify,intptr_t lReplayHandle,int nCmd,int nInValue,int* outValue)
{
	if(!G_Core.m_pPlayLib) return 0;
	return G_Core.m_pPlayLib->nvs_controlReplayRecordFile(identify,lReplayHandle,nCmd,nInValue,outValue);
}

bool nvs_stopReplayRecordFile(intptr_t identify,intptr_t lReplayHandle)
{
	if(!G_Core.m_pPlayLib) return 0;
	return G_Core.m_pPlayLib->nvs_stopReplayRecordFile( identify,lReplayHandle);
}

bool nvs_startTalk(string sCameraID,intptr_t identify)
{
	if(!G_Core.m_pPlayLib) return 0;
	return G_Core.m_pPlayLib->nvs_startTalk(sCameraID,identify);
}

bool nvs_stopTalk(string sCameraID,intptr_t identify)
{
	if(!G_Core.m_pPlayLib) return 0;
	return G_Core.m_pPlayLib->nvs_stopTalk( sCameraID,identify);
}

bool nvs_getDVRWorkState(intptr_t identify,char dvrWorkState[],int arrayLen)
{
	if(!G_Core.m_pPlayLib) return 0;
	return G_Core.m_pPlayLib->nvs_getDVRWorkState(identify,dvrWorkState,arrayLen);
}

DWORD nvs_getLastError(string sCameraID,intptr_t identify)
{
	if(!G_Core.m_pPlayLib) return 0;
	return G_Core.m_pPlayLib->nvs_getLastError(sCameraID,identify);
}

bool nvs_playBackCaptureFile(intptr_t identify , intptr_t  lReplayHandle, char *pFileName)
{
	if(!G_Core.m_pPlayLib) return 0;
	return G_Core.m_pPlayLib->nvs_playBackCaptureFile( identify ,lReplayHandle, pFileName);
}

bool nvs_playBackSaveData(intptr_t identify,intptr_t lReplayHandle,char *sFileName)
{
	if(!G_Core.m_pPlayLib) return 0;
	return G_Core.m_pPlayLib->nvs_playBackSaveData(identify, lReplayHandle,sFileName);
}

bool nvs_stopPlayBackSave(intptr_t identify,intptr_t lReplayHandle)
{
	if(!G_Core.m_pPlayLib) return 0;
	return G_Core.m_pPlayLib->nvs_stopPlayBackSave( identify, lReplayHandle);
}

bool nvs_startRecordByCode(string sCameraID,intptr_t identify,  char* saveFile)
{
	if(!G_Core.m_pPlayLib) return 0;
	return G_Core.m_pPlayLib->nvs_startRecordByCode( sCameraID, identify,   saveFile);
}

bool nvs_stopRecordByCode(string sCameraID,intptr_t identify)
{
	if(!G_Core.m_pPlayLib) return 0;
	return G_Core.m_pPlayLib->nvs_stopRecordByCode( sCameraID, identify);
}

bool nvs_SetCropArea(string sCameraID,intptr_t identify, bool bFlag, int x1, int y1, int x2 , int y2)
{
	if(!G_Core.m_pPlayLib) return 0;
	return G_Core.m_pPlayLib->nvs_SetCropArea( sCameraID, identify,  bFlag,  x1,  y1,  x2,  y2 );
}

bool nvs_SetDecodeParam(string sCameraID,intptr_t identify, int nCmd, bool bFlag, int x1, int y1, int x2 , int y2)
{
	if(!G_Core.m_pPlayLib) return 0;
	return G_Core.m_pPlayLib->nvs_SetDecodeParam( sCameraID, identify, nCmd,  bFlag,  x1,  y1,  x2,  y2 );
}

bool nvs_SetStreamSaveTime(string sCameraID,intptr_t identify, int nSaveTime )
{
	if(!G_Core.m_pPlayLib) return 0;
	return G_Core.m_pPlayLib->nvs_SetStreamSaveTime( sCameraID, identify,  nSaveTime );
}

bool nvs_PlayBackSaveStream(string sCameraID,intptr_t identify, HWND hWnd)
{
	if(!G_Core.m_pPlayLib) return 0;
	return G_Core.m_pPlayLib->nvs_PlayBackSaveStream( sCameraID, identify,  hWnd);
}

bool nvs_StopPlayBackSaveStream(string sCameraID,intptr_t identify)
{
	if(!G_Core.m_pPlayLib) return 0;
	return G_Core.m_pPlayLib->nvs_StopPlayBackSaveStream(sCameraID, identify);
}

bool nvs_SetRenderMode(string sCameraID,intptr_t identify, int nMode)
{
	if(!G_Core.m_pPlayLib) return 0;
	return G_Core.m_pPlayLib->nvs_SetRenderMode( sCameraID, identify,  nMode);
}

bool nvs_SetPosByFrameNum(string sCameraID,intptr_t identify,DWORD nFrameNum)
{
	if(!G_Core.m_pPlayLib) return 0;
	return G_Core.m_pPlayLib->nvs_SetPosByFrameNum( sCameraID, identify, nFrameNum);
}

bool nvs_GetVideoCut(string sCameraID,intptr_t identify, DWORD beginFrame, DWORD endFrame, LPSTR filename)
{
	if(!G_Core.m_pPlayLib) return 0;
	return G_Core.m_pPlayLib->nvs_GetVideoCut( sCameraID, identify,  beginFrame,  endFrame,  filename);
}

bool nvs_StopCutVideo(string sCameraID,intptr_t identify)
{
	if(!G_Core.m_pPlayLib) return 0;
	return G_Core.m_pPlayLib->nvs_StopCutVideo( sCameraID, identify);
}

bool nvs_SetFileEndCallback(string sCameraID,intptr_t identify, void *pUser, pFileOverCB pCallBack)
{
	if(!G_Core.m_pPlayLib) return 0;
	return G_Core.m_pPlayLib->nvs_SetFileEndCallback( sCameraID, identify, pUser, pCallBack);
}

bool nvs_GetMediaInfo(string sCameraID,intptr_t identify,MediaInf &mInf)
{
	if(!G_Core.m_pPlayLib) return 0;
	return G_Core.m_pPlayLib->nvs_GetMediaInfo( sCameraID, identify, mInf);
}

bool nvs_GetDecodeParam(string sCameraID,intptr_t identify, int nCmd, int &x1, int &y1, int &x2, int &y2)
{
	if(!G_Core.m_pPlayLib) return 0;
	return G_Core.m_pPlayLib->nvs_GetDecodeParam( sCameraID, identify,  nCmd,  x1, y1, x2, y2);
}

bool nvs_startPlayer4Standard(string sCameraID,intptr_t identify,HWND hWnd,LPDecCBFun lpDecCBFun, int nCameraID)
{
	if(!G_Core.m_pPlayLib) return 0;
	return G_Core.m_pPlayLib->nvs_startPlayer4Standard(sCameraID,identify,hWnd,lpDecCBFun,nCameraID);
}

bool nvs_SetYUVCallBack(string sCameraID,intptr_t identify, LPYUVCALLBACK pCallBack)
{
	if(!G_Core.m_pPlayLib) return 0;
	return G_Core.m_pPlayLib->nvs_SetYUVCallBack(sCameraID,identify,pCallBack);
}

bool nvs_getRecordFileBySource(string sCameraID,intptr_t identify,int nType, char* startTime, char* endTime, int nRecordSource)
{
	if(!G_Core.m_pPlayLib) return 0;
	return G_Core.m_pPlayLib->nvs_getRecordFileBySource(sCameraID,identify, nType,  startTime,  endTime, nRecordSource);
}

intptr_t nvs_downloadRecordFileBySource(string sCameraID,intptr_t identify,char* fileName,char* startTime, char* endTime,int nFileSize,char* saveFile,LPDOWNLOADRECORDFILECALLBACK lpCallBack,void* pUser, int nRecordSource)
{
	if(!G_Core.m_pPlayLib) return 0;
	return G_Core.m_pPlayLib->nvs_downloadRecordFileBySource(sCameraID,identify, fileName, startTime,  endTime, nFileSize, saveFile,lpCallBack, pUser, nRecordSource);
}