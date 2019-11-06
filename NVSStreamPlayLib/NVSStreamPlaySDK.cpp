#include "NVSStreamPlaySDK.h"
#include "StdAfx.h"
#include "NVSCoreBiz.h"
#include "NVSProcessByDVR.h"

extern NVSCoreBiz GL_CoreBiz;
extern NVSProcessByDVR GL_ProcessByDVR;

bool nvs_initEnviroment(const char* pAddress,unsigned short nPort,int nRight, char type)
{
	//string sIndexIp = "10.235.97.148";//Tmp10.235.97.148 10.42.5.94
	//return GL_CoreBiz.c_initEnviroment(sIndexIp.c_str(), nPort, nRight, type);//Tmp
	return GL_CoreBiz.c_initEnviroment(pAddress, nPort, nRight, type);
}
void nvs_cleanEnviroment()
{
	GL_CoreBiz.c_cleanEnviroment();
}
bool nvs_registerOnIndex()
{
	return GL_CoreBiz.c_registerOnIndex();
}
void nvs_setPlayModel(int nPlayModel)
{
	GL_CoreBiz.c_setPlayModel(nPlayModel);
}
void nvs_setDecordCardCallBack(PlayResultByDecordCard pFun)
{
	//GL_CoreBiz.m_pDecordCardCallBack = pFun;
}
void nvs_setRealPlayCallBack(RealPlayCallBack pFun)
{
	NVSCoreBiz:: WriteSysLog("==设置播放通知回调==");
	GL_CoreBiz.m_pPlayCallBack = pFun;
}
void nvs_setRealDecodeCallBack(LPDecCBFun pFun) 
{
	NVSCoreBiz:: WriteSysLog("==设置解码回调==");
	GL_CoreBiz.m_pRealDecodeCallBack = pFun;
}
void nvs_setIndexNoticeCallBack(IndexNoticeCallBack pFun)
{
	GL_CoreBiz.m_IndexNoticeCallBack = pFun;
}
void nvs_setDVRNoticeCallBack(DVRNoticeCallBack pFun)
{
	GL_CoreBiz.m_DVRNoticeCallBack = pFun;
}
void nvs_setNoticeSwitchedCallBack(NoticeSwitchedCallBack pFun)
{
	GL_CoreBiz.m_NoticeSwitchedCallBack = pFun;
}
int  nvs_playVideoByDecordCard(int nCameraID,int nCardIndex, HANDLE* hStreamPlayHandle, bool bIsExternalDvr)
{
	//return GL_CoreBiz.c_playVideoByDecordCard(nCameraID, nCardIndex, hStreamPlayHandle, bIsExternalDvr);
	return 0;
}
int nvs_playVideo2(int nCameraID,HWND hWnd, bool bUseDecode, bool bIsExternalDvr)
{
	//return GL_CoreBiz.c_playVideo(nCameraID,hWnd, bUseDecode, bIsExternalDvr);
	string sCameraID = "";
	return GL_CoreBiz.c_playVideoEx(nCameraID,hWnd, bUseDecode, bIsExternalDvr,sCameraID,NULL);
}
int nvs_playVideo(int nCameraID,HWND hWnd, bool bUseDecode)
{
	//return GL_CoreBiz.c_playVideo(nCameraID,hWnd, bUseDecode, FALSE);
	string sCameraID = "";
	int nRet =   GL_CoreBiz.c_playVideoEx(nCameraID,hWnd, bUseDecode, FALSE,sCameraID,NULL);
	return nRet;
}

int xs_playVideo(int nCameraID,HWND hWnd, bool bUseDecode, bool bIsExternalDvr,const char* pCameraID,void *pUsr)
{
	string sCameraID = "";
	if(pCameraID != NULL)
		sCameraID = pCameraID;
	int nRet =  GL_CoreBiz.c_playVideoEx(nCameraID,hWnd, bUseDecode, bIsExternalDvr,sCameraID,NULL);
	return nRet;
}

bool nvs_stopPlayVideo(HWND hWnd, int nCardIndex, int nCameraID)
{
	//return GL_CoreBiz.c_stopPlayVideo(hWnd, nCardIndex, nCameraID);
	string sCameraID = "";
	int nRet =  GL_CoreBiz.c_stopPlayVideoEx(hWnd, nCameraID, sCameraID);
	bool bRet = true;
	if(nRet != XY_TRUE)
		bRet = false;
	return bRet;
}

bool nvs_stopPlayByCameraID(int nCameraID)
{
	int nRet =  GL_CoreBiz.c_stopPlayByCameraID(nCameraID);
	bool bRet = true;
	if(nRet != XY_TRUE)
		bRet = false;
	return bRet;
}

int xs_stopPlayVideo(HWND hWnd,int nCameraID,const char* pCameraID)
{
	string sCameraID = "";
	if(pCameraID != NULL)
		sCameraID = pCameraID;
	return GL_CoreBiz.c_stopPlayVideoEx(hWnd, nCameraID, sCameraID);
}

int xs_stopPlayByCameraID(int nCameraID,const char* pCameraID)
{
	string sCameraID = "";
	if(pCameraID != NULL)
		sCameraID = pCameraID;
	return GL_CoreBiz.c_stopPlayByCameraID(nCameraID);
}

void nvs_stopAll()
{
	GL_CoreBiz.c_stopAll();
}

bool nvs_controlCameraSpeed(int nCameraID,int nCmd,bool bControl,int nSpeed)
{
	return GL_CoreBiz.c_controlCameraSpeed(nCameraID,nCmd,bControl,nSpeed);
}
bool nvs_cancelControlCamera(HWND hWnd,int nCameraID)
{
	return GL_CoreBiz.c_cancelControlCamera(hWnd,nCameraID);
}
bool nvs_capturePictureEx(int nCameraID, char* pFileName)
{
	return GL_CoreBiz.c_capturePictureEx(nCameraID,pFileName);
}
bool nvs_TransPTZ(int nCameraID, int nCmd, int nTransPTZIndex)
{
	return GL_CoreBiz.c_TransPTZ(nCameraID,nCmd,nTransPTZIndex);
}
bool nvs_getCompress(int nCameraID, char **lpOutBuffer)
{
	return GL_CoreBiz.c_getCompress(nCameraID,lpOutBuffer);
}
bool nvs_setCompress(int nCameraID, char* pCompressInfo)
{
	return GL_CoreBiz.c_setCompress(nCameraID,pCompressInfo);
}
bool nvs_getVideoEffect(int nCameraID, int* pBrightValue,int* pContrastValue, int* pSaturationValue,int* pHueValue)
{
	return GL_CoreBiz.c_getVideoEffect(nCameraID,pBrightValue,pContrastValue,pSaturationValue,pHueValue);
}
bool nvs_setVideoEffect(int nCameraID, DWORD dwBrightValue,DWORD dwContrastValue, DWORD dwSaturationValue,DWORD dwHueValue)
{ 
	return GL_CoreBiz.c_setVideoEffect(nCameraID,dwBrightValue,dwContrastValue,dwSaturationValue,dwHueValue);
}
int  nvs_startRecord(int nCameraID, char* pFileName)
{
	return GL_CoreBiz.c_startRecord(nCameraID,pFileName);
}
bool nvs_stopRecord(int nCameraID)
{
	return GL_CoreBiz.c_stopRecord(nCameraID);
}
bool nvs_serialSend(int nCameraID, char* cmd1, DWORD nLen1, char* cmd2, DWORD nLen2)
{
	return GL_CoreBiz.c_serialSend(nCameraID,cmd1,nLen1,cmd2,nLen2);
}
void nvs_reSetDDrawDevice(int nCameraID)
{
	GL_CoreBiz.c_setPlayDrawDevice(nCameraID);
}

int nvs_splitFile(int nCameraID,char* sFileName,int nPriorTime, bool bIsExternalDvr)
{
	return GL_CoreBiz.c_splitFile(nCameraID,sFileName,nPriorTime, bIsExternalDvr);
}

int nvs_play4Storage(int nCameraID,char* sFileName,int nPriorTime,bool bIsExternalDvr)
{
	//return GL_CoreBiz.c_playVideoStorage(nCameraID,sFileName,nPriorTime, bIsExternalDvr);
	return 0;
}

bool nvs_stopPlay4Storage(int nCameraID)
{
	return GL_CoreBiz.c_stopPlayVideo(0,-1,nCameraID);
}

bool nvs_controlCameraSound(int nCameraID, bool bOpenSound)
{
	return GL_CoreBiz.c_controlCameraSound(nCameraID,bOpenSound);
}

bool nvs_clientNotice()
{
	return GL_CoreBiz.c_clientNotice();
	return true;
}

intptr_t nvs_loginDVR(char* sIP, int nPort, char* sUser, char* sPwd)
{
	return GL_ProcessByDVR.v_loginDVR(sIP, nPort, sUser, sPwd);
}

void nvs_logoutDVR(intptr_t identify)
{
	GL_ProcessByDVR.v_logoutDVR(identify);
}

bool nvs_playVideoByDVR(intptr_t identify,int nCameraID,HWND hWnd)
{
	return GL_ProcessByDVR.v_playVideoByDVR(identify,nCameraID,hWnd);
}
bool nvs_stopPlayVideoByDVR(intptr_t identify,HWND hWnd)
{
	return GL_ProcessByDVR.v_stopPlayVideoByDVR(identify,hWnd);
}

bool nvs_controlCameraSpeedByDVR(intptr_t identify,int nCameraID,int nCmd, bool bControl, int nSpeed, int nChannel)
{
	NVSCoreBiz:: WriteSysLog("==controlCameraSpeedByDVR==");
	return GL_ProcessByDVR.v_controlCameraSpeedByDVR(identify,nCameraID,nCmd,bControl,nSpeed,nChannel);
}

bool nvs_presetPTZByDVR(intptr_t identify,int nCameraID, int nCmd, int nTransPTZIndex, int nChannel)
{
	return GL_ProcessByDVR.v_presetPTZByDVR(identify,nCameraID,nCmd,nTransPTZIndex,nChannel);
}

intptr_t nvs_getCameraInfo(intptr_t identify,int *nSize)
{
	return GL_ProcessByDVR.v_getCameraInfo(identify,nSize);
}

 int nvs_setPlayWindow(intptr_t identify,HWND palyWindow[], int nMaxCount)
 {
	char strLog[256]={0};
	sprintf_s(strLog, "设置窗口个数%d", nMaxCount);
	NVSCoreBiz:: WriteSysLog(strLog);
	

	return GL_ProcessByDVR.v_setPlayWindow(identify,palyWindow,nMaxCount);
 }


 intptr_t nvs_getStreamServerWorkState(int nCameraID, int nCameraCount, int *outSize )
{
	return GL_CoreBiz.c_getStreamServerWorkState(nCameraID, nCameraCount, outSize );
}


char * nvs_getStreamServerIP( int nCameraID)
{
	return GL_CoreBiz.c_getStreamServerIP( nCameraID);
}

void nvs_SetExternalClient(bool bIsExternal)
{
	GL_CoreBiz.m_bIsExternalClient = bIsExternal;
}

int nvs_setPlayWindow(HWND palyWindow[], int nMaxCount)
{
	return GL_CoreBiz.v_setPlayWindow(palyWindow, nMaxCount);
}

//.设置华三服务IP和端口(用于华三)
//返回false,无法连接HSServer获取帐号
bool nvs_InitHSServer(char *strIP, int nPort)
{
	return true;
}

void nvs_SetVedioHeadStreamCallBack(LPVedioHeadStreamCBFun pFun)
{
	NVSCoreBiz:: WriteSysLog("==设置原始码流私有头回调==");
	GL_CoreBiz.m_pVedioHeadStreamCB = pFun;
}

void nvs_SetVedioBodyStreamCallBack(LPVedioBodyStreamCBFun pFun)
{
	NVSCoreBiz:: WriteSysLog("==设置原始码流回调==");
	GL_CoreBiz.m_pVedioBodyStreamCB = pFun;
}

void nvs_SetDrawFun(LPDrawCBFun pFun)
{
	NVSCoreBiz:: WriteSysLog("==设置画图回调==");
	GL_CoreBiz.m_pDrawCB = pFun;
}

const char* nvs_GetErrorMessage(int nErrorCode)
{
	return GL_CoreBiz.c_getErrorMsg(nErrorCode);	
}

void nvs_SetRePlayFlag(bool bIsNeedRePlay)
{
	return;	
}

 int nvs_GetRecordFile(intptr_t lHandle,RECORDQUERYTYPE nType,char* startTime,char* endTime,RECORDFILE pRecordFile[],int nMaxFileCount)
 {
	 return GL_CoreBiz.c_GetRecordFile(lHandle,nType,startTime,endTime,pRecordFile,nMaxFileCount);
 }

 intptr_t nvs_ReplayRecordFile(intptr_t lHandle,HWND hWnd,char* fileName,char* startTime, char* endTime,int nFileSize)
 {
	  return GL_CoreBiz.c_ReplayRecordFile(lHandle,hWnd,fileName,startTime,endTime,nFileSize);
 }

 int nvs_ControlReplayRecordFile(intptr_t lHandle, intptr_t lRePlayhandle,int nCmd,int nInValue)
 {
	return GL_CoreBiz.c_ControlReplayRecordFile(lHandle,lRePlayhandle,nCmd,nInValue);
 }

 bool nvs_StopReplayRecordFile(intptr_t lHandle, intptr_t lRePlayhandle)
 {
	 return GL_CoreBiz.c_StopReplayRecordFile(lHandle,lRePlayhandle);

 }

 intptr_t nvs_DownloadRecordFile(intptr_t lHandle,char* fileName,char* startTime, char* endTime,int nFileSize,char* saveFile)
 {
	 return GL_CoreBiz.c_DownloadRecordFile(lHandle,fileName,startTime,endTime,nFileSize,saveFile);
 }

 int nvs_GetDownloadPos(intptr_t lHandle, intptr_t ldownloadHandle)
 {
	 return GL_CoreBiz.c_GetDownloadPos(lHandle,ldownloadHandle);
 }

 bool nvs_StopDownloadRecordFile(intptr_t lHandle, intptr_t ldownloadHandle)
 {
	 return GL_CoreBiz.c_StopDownloadRecordFile(lHandle,ldownloadHandle);
 }

 intptr_t nvs_CaptureStream(int CameraID, LPCAPTURESTREAMCALLBACK pCaptuerStreamFuc, void* pUser, int nGetVideoType)
{
	return GL_CoreBiz.c_CaptureStream(CameraID,pCaptuerStreamFuc,pUser,nGetVideoType);
}

NVSSTREAMPLAY_API bool nvs_StopCaptureStream(intptr_t lHandle)
{
	return GL_CoreBiz.c_StopCaptureStream(lHandle);

}

bool nvs_GetDecodeType(int nCameraID,char* sType)
{
	return GL_CoreBiz.c_GetDecodeType(nCameraID,sType);
}

intptr_t nvs_ConnectDVR(int nCameraID)
{
	return GL_CoreBiz.c_ConnectDVR(nCameraID);
}

void nvs_disConnectDVR(intptr_t lHandle)
{
	return GL_CoreBiz.c_disConnectDVR(lHandle);
}