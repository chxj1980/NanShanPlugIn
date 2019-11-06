#pragma once
#include "NVSSDKDef_x64.h"

typedef void (CALLBACK * RealPlayCallBack)(int nCameraID, int nRe/*ʵ�ʲ��Ž��*/);
typedef void (CALLBACK * PlayResultByDecordCard)(int,int,int/* 0���ųɹ��� 1����ʧ�� 2����ʧ��*/);
typedef void (CALLBACK *IndexNoticeCallBack)(int nUserID, int nChangeType, int nLimitTime);
typedef void (CALLBACK *DVRNoticeCallBack)(int nCameraID, int nErr);
typedef bool (CALLBACK *HsUserCallBack)(char* sUser,char* sPass,bool bGetUser);
typedef void (CALLBACK *LPVedioHeadStreamCBFun)(BYTE * pBuf,long nSizeint, int  nCameraID);
typedef void (CALLBACK *LPVedioBodyStreamCBFun)(BYTE * pBuf,long nSizeint, int  nCameraID);
typedef void (CALLBACK *NoticeSwitchedCallBack)(int nUserID,int nPriorCameraID,int nCameraID,char* pDesc);
typedef void (CALLBACK *LPDrawCBFun)(intptr_t lRealHandle, DWORD hDc, int nCameraID);


typedef bool (*lp_nvs_initEnviroment)(const char*,unsigned short,int,char);
typedef void (*lp_nvs_cleanEnviroment)();
typedef bool (*lp_nvs_registerOnIndex)();
typedef void (*lp_nvs_setPlayModel)(int);
typedef void (*lp_nvs_setDecordCardCallBack)(PlayResultByDecordCard);
typedef void (*lp_nvs_setRealPlayCallBack)(RealPlayCallBack);
typedef void (*lp_nvs_setRealDecodeCallBack)(LPDecCBFun);
typedef void (*lp_nvs_setIndexNoticeCallBack)(IndexNoticeCallBack);
typedef void (*lp_nvs_setDVRNoticeCallBack)(DVRNoticeCallBack);
typedef int (*lp_nvs_playVideoByDecordCard)(int,int,HANDLE*);
typedef int (*lp_nvs_playVideo2)(int,HWND,bool,bool);
typedef int (*lp_nvs_playVideo)(int,HWND,bool);
typedef bool (*lp_nvs_stopPlayVideo)(HWND,int,int);
typedef bool (*lp_nvs_stopPlayByCameraID)(int);
typedef void (*lp_nvs_stopAll)();
typedef bool (*lp_nvs_controlCameraSpeed)(int,int,bool,int);
typedef bool (*lp_nvs_cancelControlCamera)(HWND,int);
typedef bool (*lp_nvs_capturePictureEx)(int,char*);
typedef bool (*lp_nvs_TransPTZ)(int,int,int);
typedef bool (*lp_nvs_getCompress)(int,char**);
typedef bool (*lp_nvs_setCompress)(int,char*);
typedef bool (*lp_nvs_getVideoEffect)(int,int*,int*,int*,int*);
typedef bool (*lp_nvs_setVideoEffect)(int,DWORD,DWORD,DWORD,DWORD);
typedef int  (*lp_nvs_startRecord)(int,char*);
typedef bool (*lp_nvs_stopRecord)(int);
typedef bool (*lp_nvs_serialSend)(int,char*,DWORD,char*,DWORD);
typedef void (*lp_nvs_reSetDDrawDevice)(int);
typedef int (*lp_nvs_splitFile)(int,char*,int);
typedef int (*lp_nvs_play4Storage)(int,char*,int);
typedef bool (*lp_nvs_stopPlay4Storage)(int);
typedef bool (*lp_nvs_controlCameraSound)(int,bool);
typedef bool (*lp_nvs_clientNotice)();
typedef intptr_t(*lp_nvs_loginDVR)(char*,int,char*,char*);
typedef void (*lp_nvs_logoutDVR)(intptr_t);
typedef bool (*lp_nvs_playVideoByDVR)(intptr_t,int,HWND);
typedef bool (*lp_nvs_stopPlayVideoByDVR)(intptr_t,HWND);
typedef bool (*lp_nvs_controlCameraSpeedByDVR)(intptr_t,int,int,bool,int,int);
typedef bool (*lp_nvs_presetPTZByDVR)(intptr_t,int,int,int,int);
typedef intptr_t(*lp_nvs_getCameraInfo)(intptr_t, int*);
typedef int (*lp_nvs_setPlayWindow)(HWND[],int);
typedef intptr_t(*lp_nvs_getStreamServerWorkState)(int,int,int*);
typedef char* (*lp_nvs_getStreamServerIP)(int);
typedef void (*lp_nvs_SetExternalClient)(bool);
typedef void (*lp_nvs_writeLog)(char*,int);
typedef bool (*lp_nvs_InitHSServer)(char*,int);
typedef void (*lp_nvs_SetHsCallBack)(HsUserCallBack);
typedef void (*lp_LPVedioHeadStreamCBFun)(LPVedioHeadStreamCBFun);
typedef void (*lp_LPVedioBodyStreamCBFun)(LPVedioBodyStreamCBFun);
typedef void (*lp_nvs_SetUserIDandOrgID)(int,int);
typedef void (*lp_nvs_setNoticeSwitchedCallBack)(NoticeSwitchedCallBack);
typedef void (*lp_nvs_SetDrawFun)(LPDrawCBFun);
typedef const char* (*lp_nvs_GetErrorMessage)(int);
//V3.0
typedef int  (*lp_nvs_stdVideoinit)(pNVSSipCallback, void *);
typedef int  (*lp_nvs_playStdVideo)(char* ,HWND  ,char* , int , char* , char*  ,char* , LPREALSTREAMCALLBACK , void*);
typedef int  (*lp_nvs_stopStdVideo)(char* ,HWND );
typedef int  (*lp_nvs_startPlayMonitor)(char* ,char* ,char* , int , char* , char*  ,char* );
typedef int  (*lp_nvs_stopPlayMonitor)(char* );

typedef bool (*lp_nvs_capturePictureByCode)(char* , char* );
typedef void (*lp_nvs_makeKey)(char* );
typedef intptr_t (*lp_nvs_connectDVR)(char* , int , char* , char* , int  ,char* );
typedef void (*lp_nvs_disconnectDVR)(intptr_t identify);
typedef bool (*lp_nvs_controlPTZSpeedWithChannel)(string sCameraID, intptr_t identify,int nCmd, bool bEnable, int nSpeed, int nChannel);
typedef bool (*lp_nvs_presetPTZWithChannel)(string sCameraID, intptr_t identify, int nCmd, int nIndex, int nChannel);
typedef bool (*lp_nvs_setVideoEffectByCode)(string sCameraID, intptr_t identify,DWORD dwBrightValue,DWORD dwContrastValue, DWORD dwSaturationValue,DWORD dwHueValue);
typedef bool (*lp_nvs_getVideoEffectByCode)(string sCameraID, intptr_t identify,DWORD *pBrightValue,DWORD *pContrastValue, DWORD *pSaturationValue,DWORD *pHueValue);
typedef bool (*lp_nvs_getDVRConfig)(string sCameraID, intptr_t identify, DWORD dwCommand,LONG lChannel,LPVOID lpOutBuffer,DWORD dwOutBufferSize,LPDWORD lpBytesReturned);
typedef bool (*lp_nvs_setDVRConfig)(string sCameraID, intptr_t identify, DWORD dwCommand,LONG lChannel,LPVOID lpInBuffer,DWORD dwInBufferSize);
typedef int  (*lp_nvs_getRecordFileEx)(string sCameraID, intptr_t identify,RECORDQUERYTYPE nType,char* startTime,char* endTime,RECORDFILE pRecordFile[],int nMaxFileCount);
typedef intptr_t (*lp_nvs_downloadRecordFile)(string sCameraID, intptr_t identify,char* fileName,char* startTime, char* endTime,int nFileSize,char* saveFile,LPDOWNLOADRECORDFILECALLBACK lpCallBack,void* pUser);
typedef bool (*lp_nvs_stopDownloadRecordFile)(intptr_t identify,intptr_t ldownFileHandle);
typedef int (*lp_nvs_getDownloadPos)(intptr_t identify,intptr_t lFileHandle);
typedef intptr_t (*lp_nvs_replayRecordFile)(string sCameraID, intptr_t identify,int hWnd,char* fileName,char* startTime, char* endTime,int nFileSize);
typedef bool (*lp_nvs_controlReplayRecordFile)(intptr_t identify, intptr_t lReplayHandle,int nCmd,int nInValue,int* outValue);
typedef bool (*lp_nvs_stopReplayRecordFile)(intptr_t identify, intptr_t lReplayHandle);
typedef bool (*lp_nvs_startTalk)(string sCameraID, intptr_t identify);
typedef bool (*lp_nvs_stopTalk)(string sCameraID, intptr_t identify);
typedef bool (*lp_nvs_getDVRWorkState)(intptr_t identify,char dvrWorkState[],int arrayLen);
typedef DWORD (*lp_nvs_getLastError)(string sCameraID, intptr_t identify);
typedef bool (*lp_nvs_playBackCaptureFile)(intptr_t identify , intptr_t  lReplayHandle, char *pFileName);
typedef bool (*lp_nvs_playBackSaveData)(intptr_t identify, intptr_t lReplayHandle,char *sFileName);
typedef bool (*lp_nvs_stopPlayBackSave)(intptr_t identify, intptr_t lReplayHandle);
typedef bool (*lp_nvs_startRecordByCode)(string sCameraID, intptr_t identify, char* saveFile);
typedef bool (*lp_nvs_stopRecordByCode)(string sCameraID, intptr_t identify);
typedef bool (*lp_nvs_SetCropArea)(string sCameraID, intptr_t identify, bool bFlag, int x1, int y1, int x2, int y2);
typedef bool (*lp_nvs_SetDecodeParam)(string sCameraID, intptr_t identify, int nCmd, bool bFlag, int x1, int y1, int x2, int y2);
typedef bool (*lp_nvs_SetStreamSaveTime)(string sCameraID, intptr_t identify, int nSaveTime);
typedef bool (*lp_nvs_PlayBackSaveStream)(string sCameraID, intptr_t identify, HWND hWnd);
typedef bool (*lp_nvs_StopPlayBackSaveStream)(string sCameraID, intptr_t identify);
typedef bool (*lp_nvs_SetRenderMode)(string sCameraID, intptr_t identify, int nMode);
typedef bool (*lp_nvs_SetPosByFrameNum)(string sCameraID, intptr_t identify,DWORD nFrameNum);
typedef bool (*lp_nvs_GetVideoCut)(string sCameraID, intptr_t identify, DWORD beginFrame, DWORD endFrame, LPSTR filename);
typedef bool (*lp_nvs_StopCutVideo)(string sCameraID, intptr_t identify);
typedef bool (*lp_nvs_SetFileEndCallback)(string sCameraID, intptr_t identify, void *pUser, pFileOverCB pCallBack);
typedef bool (*lp_nvs_GetMediaInfo)(string sCameraID, intptr_t identify,MediaInf &mInf);
typedef bool (*lp_nvs_GetDecodeParam)(string sCameraID, intptr_t identify, int nCmd, int &x1, int &y1, int &x2, int &y2);
typedef bool (*lp_nvs_startPlayer4Standard)(string sCameraID, intptr_t identify,HWND hWnd,LPDecCBFun lpDecCBFun, int nCameraID);
typedef bool (*lp_nvs_SetYUVCallBack)(string sCameraID, intptr_t identify, LPYUVCALLBACK pCallBack);
typedef bool (*lp_nvs_getRecordFileBySource)(string sCameraID, intptr_t identify,int nType, char* startTime, char* endTime, int nRecordSource);
typedef intptr_t (*lp_nvs_downloadRecordFileBySource)(string sCameraID, intptr_t identify,char* fileName,char* startTime, char* endTime,int nFileSize,char* saveFile,LPDOWNLOADRECORDFILECALLBACK lpCallBack,void* pUser, int nRecordSource);

//V3.0

class NVSPlayLib
{
public:
	//! [01] ��ʼ��ҵ���߼�����ģ��
	virtual bool nvs_initEnviroment(const char* pAddress,unsigned short nPort,int nRight, char type)=0;
	//! [02] ����ҵ���߼����Ļ���.
	virtual void nvs_cleanEnviroment()=0;
	//! [03] �ͻ���ע������������.
	virtual bool nvs_registerOnIndex()=0;
	//! [04] ���ò���ģʽ.
	virtual void nvs_setPlayModel(int nPlayModel)=0;
	/*! ���ûص����� */
	virtual void nvs_setDecordCardCallBack(PlayResultByDecordCard pFun)=0;
	virtual void nvs_setRealPlayCallBack(RealPlayCallBack pFun)=0;
	virtual void nvs_setRealDecodeCallBack(LPDecCBFun pFun)=0;
	virtual void nvs_setIndexNoticeCallBack(IndexNoticeCallBack pFun)=0;
	virtual void nvs_setDVRNoticeCallBack(DVRNoticeCallBack pFun)=0;
	//! [05] �ͻ���Ӳ�ⲥ��
	virtual int nvs_playVideoByDecordCard(int nCameraID,int nCardIndex, HANDLE* hStreamPlayHandle)=0;
	//! [07] �ͻ�����ⲥ��
	virtual int nvs_playVideo2(int nCameraID,HWND hWnd, bool bUseDecode/*��ȡ��׼����ʶ*/, bool bIsExternalDvr)=0;
	virtual int nvs_playVideo(int nCameraID,HWND hWnd, bool bUseDecode/*��ȡ��׼����ʶ*/)=0;
	//! [08] �ͻ��˹ر�ĳ���ڵĲ���
	virtual bool nvs_stopPlayVideo(HWND hWnd, int nCardIndex, int nCameraID)=0;
	virtual bool nvs_stopPlayByCameraID(int nCameraID)=0;
	//! [09] �ͻ��˹ر����д��ڲ���
	virtual void nvs_stopAll()=0;
	//! [11] �ͻ��˿�������ͷ(�������ٶ�)
	virtual bool nvs_controlCameraSpeed(int nCameraID,int nCmd,bool bControl,int nSpeed)=0;
	//! [12] �Զ�ע��PTZ����Ȩ��
	virtual bool nvs_cancelControlCamera(HWND hWnd,int nCameraID)=0;
	//! [13] ץͼ
	virtual bool nvs_capturePictureEx(int nCameraID, char* pFileName)=0;
	//! [14] Ԥ��λ
	virtual bool nvs_TransPTZ(int nCameraID, int nCmd, int nTransPTZIndex)=0;
	//! [15] ��ȡͨ������������������������Ƶ������
	virtual bool nvs_getCompress(int nCameraID, char **lpOutBuffer)=0;
	//! [16] ����ͨ������
	virtual bool nvs_setCompress(int nCameraID, char* pCompressInfo)=0;
	//! [17] ��ȡ��Ƶ���������ȡ�ɫ�ȡ����Ͷȵȣ�
	virtual bool nvs_getVideoEffect(int nCameraID, int* pBrightValue,int* pContrastValue, int* pSaturationValue,int* pHueValue)=0;
	//! [18] ������Ƶ����
	virtual bool nvs_setVideoEffect(int nCameraID, DWORD dwBrightValue,DWORD dwContrastValue, DWORD dwSaturationValue,DWORD dwHueValue)=0;
	//! [19] ��ʼ����¼��
	virtual int  nvs_startRecord(int nCameraID, char* pFileName)=0;
	//! [20] ֹͣ����¼��
	virtual bool nvs_stopRecord(int nCameraID)=0;
	//! [21] ʹ��͸��ͨ��
	virtual bool nvs_serialSend(int nCameraID, char* cmd1, DWORD nLen1, char* cmd2, DWORD nLen2)=0;
	//! [22] ˢ��������Ƶ����ʹ�ü�����
	virtual void nvs_reSetDDrawDevice(int nCameraID)=0;
	//! [23] �ָ�¼���ļ�
	virtual int nvs_splitFile(int nCameraID,char* sFileName,int nPriorTime)=0;
	//! [24] ���д洢����
	virtual int nvs_play4Storage(int nCameraID,char* sFileName,int nPriorTime)=0;
	//! [25] ���д洢����ֹͣ
	virtual bool nvs_stopPlay4Storage(int nCameraID)=0;
	//! [26] ��������ͷ��Ƶ����
	virtual bool nvs_controlCameraSound(int nCameraID, bool bOpenSound)=0;
	//! [27]�ͻ���֪ͨ�ص����������
	virtual bool nvs_clientNotice()=0;
	//! [28]��ȡ��ý�幤��״̬
	virtual intptr_t nvs_getStreamServerWorkState(int nCameraID, int nCameraCount, int *outSize )=0;
	//! [29]��ȡ
	virtual char * nvs_getStreamServerIP( int nCameraID)=0;
	//! [30]�����Ƿ�Ϊ�����ͻ���
	virtual void nvs_SetExternalClient(bool bIsExternal)=0;
	//! [31]רΪlinux�ṩ����־�ӿ� 
	virtual void nvs_writeLog(char* logMsg, int level)=0;
	//! [32]���û�3�û��ص�����.
	virtual void nvs_SetHsCallBack(HsUserCallBack CallbackFun)=0;
	//! [33]����ʵʱ��Ƶͷ�ص�����
	virtual void nvs_SetVedioHeadStreamCallBack(LPVedioHeadStreamCBFun pFun)=0;
	//! [34]����ʵʱ��Ƶ���ص�����
	virtual void nvs_SetVedioBodyStreamCallBack(LPVedioBodyStreamCBFun pFun)=0;


	//! [35]�ͻ��˴��û�ID�����ID��Linux
	virtual void nvs_SetUserIDandOrgID(int nUserID,int OrgID)=0;
	//! [36] ����VIS֪ͨ�ص�����
    virtual void nvs_setNoticeSwitchedCallBack(NoticeSwitchedCallBack pFun)=0;
	//! [37] ���õ��ӻص�����
	virtual void  nvs_SetDrawFun(LPDrawCBFun pFun)=0;

	/////////////////////////////////////////////
	//! ���µĽӿ���ֱ�Ӵ�DVR�ϻ�ȡ��Ƶ(����)
	virtual intptr_t nvs_loginDVR(char* sIP, int nPort, char* sUser, char* sPwd)=0;
	//! [2]�ͷ�����.
	virtual void nvs_logoutDVR(intptr_t identify)=0;
	//! [3]�ͻ�����ⲥ��.
	virtual bool nvs_playVideoByDVR(intptr_t identify,int nCameraID,HWND hWnd)=0;
	//! [4]�ͻ��˹ر�ĳ���ڵĲ���
	virtual bool nvs_stopPlayVideoByDVR(intptr_t identify,HWND hWnd)=0;
	//! [5]�ͻ��˿�������ͷ(�������ٶ�)
	virtual bool nvs_controlCameraSpeedByDVR(intptr_t identify,int nCameraID,int nCmd,bool bControl,int nSpeed,int nChannel)=0;
	//! [6]Ԥ��λ
	virtual bool nvs_presetPTZByDVR(intptr_t identify,int nCameraID, int nCmd, int nTransPTZIndex,int nChannel)=0;
	//! [7]��ȡ����������ľ�ͷ��Ϣ
	virtual intptr_t nvs_getCameraInfo(intptr_t identify,int *nSize)=0;
	//! [8]���ò��Ŵ��ھ��
	virtual int nvs_setPlayWindow(HWND palyWindow[], int nMaxCount)=0;
	//! [9]���û�������IP�Ͷ˿�
	virtual bool nvs_InitHSServer(char *strIP, int nPort)=0;
	virtual const char* nvs_GetErrorMessage(int nErrorCode)=0;
	//V3.0
	//! [26] ��׼��Ƶ��Ϣ�ص���ʼ��
	virtual int  nvs_stdVideoinit(pNVSSipCallback pCB, void *pUser)=0;
	//! [27] ��׼��Ƶ����ֹͣ
	virtual int  nvs_playStdVideo(char* sCameraID,HWND hWnd ,char* sIP, int nPort, char* sUser, char* sPwd ,char* sDllType, LPREALSTREAMCALLBACK lpCallBack, void* pUser)=0;
	//! [28] ��׼��Ƶ����ֹͣ
	virtual int  nvs_stopStdVideo(char* sCameraID,HWND hWnd)=0;
	//! [29] ��Ƶ��ǽ
	virtual int nvs_startPlayMonitor(char* sCameraCode, char *sMonitorCode,char* sIP, int nPort, char* sUser, char* sPwd ,char* sDllType)=0;
	//! [30] ֹͣ��Ƶ��ǽ
	virtual int nvs_stopPlayMonitor(char *sMonitorCode)=0;


	// ץͼ.
	virtual bool nvs_capturePictureByCode(char* sCameraCode, char* sFilePath)=0;
	// �����ؼ�֡
	virtual void nvs_makeKey(char* sCameraCode)=0;
	// ����DVR.
	virtual intptr_t nvs_connectDVR(char* sIP, int nPort, char* sUser, char* sPwd, int nChannel ,char* sDllType)=0;
	// �ͷ�����.
	virtual void nvs_disconnectDVR(intptr_t identify)=0;
	//ִ����̨����_��ͨ��
	virtual bool nvs_controlPTZSpeedWithChannel(string sCameraID,intptr_t identify,int nCmd, bool bEnable, int nSpeed, int nChannel)=0;
	//ִ��Ԥ��λ_��ͨ��
	virtual bool nvs_presetPTZWithChannel(string sCameraID,intptr_t identify, int nCmd, int nIndex, int nChannel)=0;
	// ������Ƶ����.
	virtual bool nvs_setVideoEffectByCode(string sCameraID,intptr_t identify,DWORD dwBrightValue,DWORD dwContrastValue, DWORD dwSaturationValue,DWORD dwHueValue)=0;
	// ��ȡ��Ƶ����.
	virtual bool nvs_getVideoEffectByCode(string sCameraID,intptr_t identify,DWORD *pBrightValue,DWORD *pContrastValue, DWORD *pSaturationValue,DWORD *pHueValue)=0;
	// ��ȡ�豸�ṹ.
	virtual bool nvs_getDVRConfig(string sCameraID,intptr_t identify, DWORD dwCommand,LONG lChannel,LPVOID lpOutBuffer,DWORD dwOutBufferSize,LPDWORD lpBytesReturned)=0;

	// �����豸�ṹ.
	virtual bool nvs_setDVRConfig(string sCameraID,intptr_t identify, DWORD dwCommand,LONG lChannel,LPVOID lpInBuffer,DWORD dwInBufferSize)=0;
	// ��ȡ¼���ļ��б�.
	virtual int  nvs_getRecordFileEx(string sCameraID,intptr_t identify,RECORDQUERYTYPE nType,char* startTime,char* endTime,RECORDFILE pRecordFile[],int nMaxFileCount)=0;
	// ����¼���ļ�.
	virtual intptr_t nvs_downloadRecordFile(string sCameraID,intptr_t identify,char* fileName,char* startTime, char* endTime,int nFileSize,char* saveFile,LPDOWNLOADRECORDFILECALLBACK lpCallBack,void* pUser)=0;
	// ֹͣ����¼���ļ�.
	virtual bool nvs_stopDownloadRecordFile(intptr_t identify,intptr_t ldownFileHandle)=0;
	// ��ȡ���صĽ���.
	virtual int nvs_getDownloadPos(intptr_t identify,intptr_t lFileHandle)=0;

	// Զ�̻ط�.
	virtual intptr_t nvs_replayRecordFile(string sCameraID,intptr_t identify,int hWnd,char* fileName,char* startTime, char* endTime,int nFileSize)=0;
	// Զ�̻طſ���.
	virtual bool nvs_controlReplayRecordFile(intptr_t identify,intptr_t lReplayHandle,int nCmd,int nInValue,int* outValue)=0;
	// ֹͣԶ�̻ط�.
	virtual bool nvs_stopReplayRecordFile(intptr_t identify,intptr_t lReplayHandle)=0;

	// ��ʼ�����Խ�.
	virtual bool nvs_startTalk(string sCameraID,intptr_t identify)=0;
	// ֹͣ�����Խ�.
	virtual bool nvs_stopTalk(string sCameraID,intptr_t identify)=0;
	// ��ȡӲ��¼�������״̬.
	virtual bool nvs_getDVRWorkState(intptr_t identify,char dvrWorkState[],int arrayLen)=0;

	//��ȡ�������
	virtual DWORD nvs_getLastError(string sCameraID,intptr_t identify)=0;

	//Զ�̻ط�ʱץͼ
	virtual  bool nvs_playBackCaptureFile(intptr_t identify , intptr_t  lReplayHandle, char *pFileName)=0;

	// ����طŵ�����
	virtual bool nvs_playBackSaveData(intptr_t identify,intptr_t lReplayHandle,char *sFileName)=0;
	// ֹͣ����طŵ�����
	virtual bool nvs_stopPlayBackSave(intptr_t identify,intptr_t lReplayHandle)=0;

	virtual bool nvs_startRecordByCode(string sCameraID,intptr_t identify, char* saveFile)=0;

	virtual bool nvs_stopRecordByCode(string sCameraID,intptr_t identify)=0;

	//�ֲ��Ŵ�(��Ӧ�����XY_SetCropArea()�ӿ�)
	virtual bool nvs_SetCropArea(string sCameraID,intptr_t identify, bool bFlag = false, int x1 = 0, int y1 = 0, int x2 = 0, int y2 = 0)=0;

	//��Ƶ�������ܵ���(����nCmd����, �ֱ��Ӧ�����XY_SetClearFogParam(), XY_OpenOrCloseClearFog(), XY_OpenOrCloseInvert(), XY_OpenOrCloseSharpen()�ӿ�)
	virtual bool nvs_SetDecodeParam(string sCameraID,intptr_t identify, int nCmd, bool bFlag = false, int x1 = 0, int y1 = 0, int x2 = 0, int y2 = 0)=0;

	/****���������ӿ���Ϊ��ʵ���ڿͻ��˲���ʵʱ��Ƶʱ��15����ٻط�****/

	//����ʵʱ����ʱ���������ݵ�ʱ��, Ĭ��15��
	virtual bool nvs_SetStreamSaveTime(string sCameraID,intptr_t identify, int nSaveTime = 15)=0;

	//�طű������Ƶ��
	virtual bool nvs_PlayBackSaveStream(string sCameraID,intptr_t identify, HWND hWnd)=0;

	//ֹͣ�طű������Ƶ��
	virtual bool nvs_StopPlayBackSaveStream(string sCameraID,intptr_t identify)=0;
	//����ͼ�����Ⱦģʽ��Ĭ��ΪD3D��Ⱦ
	virtual bool nvs_SetRenderMode(string sCameraID,intptr_t identify, int nMode = RENDER_BY_D3D)=0;

	//����֡�Ŷ�λ,��λ��nFrameNum����Ĺؼ�֡����ǰ���ң�
	virtual bool nvs_SetPosByFrameNum(string sCameraID,intptr_t identify,DWORD nFrameNum)=0;

	//��ȡbeginTime��endTime֮���¼�񣬱�����filename��ָ����·����beginTime��endTimeΪ�뼶ʱ��
	virtual bool nvs_GetVideoCut(string sCameraID,intptr_t identify, DWORD beginFrame, DWORD endFrame, LPSTR filename)=0;

	//��ֹ�ļ�����
	virtual bool nvs_StopCutVideo(string sCameraID,intptr_t identify)=0;

	//�����ļ������ص�
	virtual bool nvs_SetFileEndCallback(string sCameraID,intptr_t identify, void *pUser, pFileOverCB pCallBack)=0;// ֪ͨʹ�ã�Ϊ��ȷ����Ƶ�ļ��Ѿ�������ϣ���Ϊ������Ƶ�ļ��������ʱ����ǰ֡��������֡����

	//��ȡý����Ϣ
	virtual bool nvs_GetMediaInfo(string sCameraID,intptr_t identify,MediaInf &mInf)=0;
	//��Ƶ�����ȡ���ò���
	virtual bool nvs_GetDecodeParam(string sCameraID,intptr_t identify, int nCmd, int &x1, int &y1, int &x2, int &y2)=0;

	// ��ʼ���Ų��һ�ȡ��׼��ʽ��Ƶ��.
	virtual bool nvs_startPlayer4Standard(string sCameraID,intptr_t identify,HWND hWnd,LPDecCBFun lpDecCBFun, int nCameraID)=0;

	//����YUV�ص�����(��Ӧ�����XY_SetStreamCallBackForVideo()�ӿ�)
	virtual bool nvs_SetYUVCallBack(string sCameraID,intptr_t identify, LPYUVCALLBACK pCallBack)=0;
	
	//������ƵԴ��ȡ��ʷ��Ƶ����Ϣ  ������ƵԴ��ȡ��ʷ��Ƶ����Ϣ, ���ҵ�����Ϣ��pSipMsgCallBack�з���
	virtual bool nvs_getRecordFileBySource(string sCameraID,intptr_t identify,int nType, char* startTime, char* endTime, int nRecordSource)=0;

	//����¼��
	virtual intptr_t nvs_downloadRecordFileBySource(string sCameraID,intptr_t identify,char* fileName,char* startTime, char* endTime,int nFileSize,char* saveFile,LPDOWNLOADRECORDFILECALLBACK lpCallBack,void* pUser, int nRecordSource)=0;

	//V3.0
};


//////////////////////////////////////////////////////////
//Windows version

class NVSPlayLibWin : public NVSPlayLib
{
public:
	NVSPlayLibWin(void);
public:
	~NVSPlayLibWin(void);
public:
	HMODULE m_hDllWin;
public:
	lp_nvs_initEnviroment m_lp_nvs_initEnviroment;
	lp_nvs_cleanEnviroment m_lp_nvs_cleanEnviroment;
	lp_nvs_registerOnIndex m_lp_nvs_registerOnIndex;
	lp_nvs_setPlayModel m_lp_nvs_setPlayModel;
	lp_nvs_setDecordCardCallBack m_lp_nvs_setDecordCardCallBack;
	lp_nvs_setRealPlayCallBack m_lp_nvs_setRealPlayCallBack;
	lp_nvs_setRealDecodeCallBack m_lp_nvs_setRealDecodeCallBack;
	lp_nvs_setIndexNoticeCallBack m_lp_nvs_setIndexNoticeCallBack;
	lp_nvs_setDVRNoticeCallBack m_lp_nvs_setDVRNoticeCallBack;
	lp_nvs_playVideoByDecordCard m_lp_nvs_playVideoByDecordCard;
	lp_nvs_playVideo m_lp_nvs_playVideo;
	lp_nvs_playVideo2 m_lp_nvs_playVideo2;
	lp_nvs_stopPlayVideo m_lp_nvs_stopPlayVideo;
	lp_nvs_stopPlayByCameraID m_lp_nvs_stopPlayByCameraID;
	lp_nvs_stopAll m_lp_nvs_stopAll;
	lp_nvs_controlCameraSpeed m_lp_nvs_controlCameraSpeed;
	lp_nvs_cancelControlCamera m_lp_nvs_cancelControlCamera;
	lp_nvs_capturePictureEx m_lp_nvs_capturePictureEx;
	lp_nvs_TransPTZ m_lp_nvs_TransPTZ;
	lp_nvs_getCompress m_lp_nvs_getCompress;
	lp_nvs_setCompress m_lp_nvs_setCompress;
	lp_nvs_getVideoEffect m_lp_nvs_getVideoEffect;
	lp_nvs_setVideoEffect m_lp_nvs_setVideoEffect;
	lp_nvs_startRecord m_lp_nvs_startRecord;
	lp_nvs_stopRecord m_lp_nvs_stopRecord;
	lp_nvs_serialSend m_lp_nvs_serialSend;
	lp_nvs_reSetDDrawDevice m_lp_nvs_reSetDDrawDevice;
	lp_nvs_splitFile m_lp_nvs_splitFile;
	lp_nvs_play4Storage m_lp_nvs_play4Storage;
	lp_nvs_stopPlay4Storage m_lp_nvs_stopPlay4Storage;
	lp_nvs_controlCameraSound m_lp_nvs_controlCameraSound;
	lp_nvs_clientNotice m_lp_nvs_clientNotice;
	lp_nvs_loginDVR m_lp_nvs_loginDVR;
	lp_nvs_logoutDVR m_lp_nvs_logoutDVR;
	lp_nvs_playVideoByDVR m_lp_nvs_playVideoByDVR;
	lp_nvs_stopPlayVideoByDVR m_lp_nvs_stopPlayVideoByDVR;
	lp_nvs_controlCameraSpeedByDVR m_lp_nvs_controlCameraSpeedByDVR;
	lp_nvs_presetPTZByDVR m_lp_nvs_presetPTZByDVR;
	lp_nvs_getCameraInfo m_lp_nvs_getCameraInfo;
	lp_nvs_setPlayWindow m_lp_nvs_setPlayWindow;
	lp_nvs_getStreamServerWorkState m_lp_nvs_getStreamServerWorkState;
	lp_nvs_getStreamServerIP m_lp_nvs_getStreamServerIP;
	lp_nvs_SetExternalClient m_lp_nvs_SetExternalClient;
	lp_nvs_writeLog m_lp_nvs_writeLog;
	lp_nvs_InitHSServer m_lp_nvs_InitHSServer;
	lp_nvs_SetHsCallBack m_lp_nvs_SetHsCallBack;
	lp_LPVedioHeadStreamCBFun m_lp_LPVedioHeadStreamCBFun;
	lp_LPVedioBodyStreamCBFun m_lp_LPVedioBodyStreamCBFun;
	lp_nvs_SetUserIDandOrgID m_lp_nvs_SetUserIDandOrgID;
	lp_nvs_setNoticeSwitchedCallBack m_lp_nvs_setNoticeSwitchedCallBack;
	lp_nvs_SetDrawFun m_lp_nvs_SetDrawFun;
	lp_nvs_GetErrorMessage m_lp_nvs_GetErrorMessage;
	lp_nvs_stdVideoinit	m_lp_nvs_stdVideoinit;	
	lp_nvs_playStdVideo	m_lp_nvs_playStdVideo;
	lp_nvs_stopStdVideo	m_lp_nvs_stopStdVideo;
	lp_nvs_startPlayMonitor m_lp_nvs_startPlayMonitor;
	lp_nvs_stopPlayMonitor  m_lp_nvs_stopPlayMonitor;

	lp_nvs_capturePictureByCode m_lp_nvs_capturePictureByCode;
	lp_nvs_makeKey m_lp_nvs_makeKey;
	lp_nvs_connectDVR m_lp_nvs_connectDVR;
	lp_nvs_disconnectDVR m_lp_nvs_disconnectDVR;
	lp_nvs_controlPTZSpeedWithChannel m_lp_nvs_controlPTZSpeedWithChannel;
	lp_nvs_presetPTZWithChannel m_lp_nvs_presetPTZWithChannel;
	lp_nvs_setVideoEffectByCode m_lp_nvs_setVideoEffectByCode;
	lp_nvs_getVideoEffectByCode m_lp_nvs_getVideoEffectByCode;
	lp_nvs_getDVRConfig m_lp_nvs_getDVRConfig;
	lp_nvs_setDVRConfig m_lp_nvs_setDVRConfig;
	lp_nvs_getRecordFileEx m_lp_nvs_getRecordFileEx;
	lp_nvs_downloadRecordFile m_lp_nvs_downloadRecordFile;
	lp_nvs_stopDownloadRecordFile m_lp_nvs_stopDownloadRecordFile;
	lp_nvs_getDownloadPos m_lp_nvs_getDownloadPos;
	lp_nvs_replayRecordFile m_lp_nvs_replayRecordFile;
	lp_nvs_controlReplayRecordFile m_lp_nvs_controlReplayRecordFile;
	lp_nvs_stopReplayRecordFile m_lp_nvs_stopReplayRecordFile;
	lp_nvs_startTalk m_lp_nvs_startTalk;
	lp_nvs_stopTalk m_lp_nvs_stopTalk;
	lp_nvs_getDVRWorkState m_lp_nvs_getDVRWorkState;
	lp_nvs_getLastError m_lp_nvs_getLastError;
	lp_nvs_playBackCaptureFile m_lp_nvs_playBackCaptureFile;
	lp_nvs_playBackSaveData m_lp_nvs_playBackSaveData;
	lp_nvs_stopPlayBackSave m_lp_nvs_stopPlayBackSave;
	lp_nvs_startRecordByCode m_lp_nvs_startRecordByCode;
	lp_nvs_stopRecordByCode m_lp_nvs_stopRecordByCode;
	lp_nvs_SetCropArea m_lp_nvs_SetCropArea;
	lp_nvs_SetDecodeParam m_lp_nvs_SetDecodeParam;
	lp_nvs_SetStreamSaveTime m_lp_nvs_SetStreamSaveTime;
	lp_nvs_PlayBackSaveStream m_lp_nvs_PlayBackSaveStream;
	lp_nvs_StopPlayBackSaveStream m_lp_nvs_StopPlayBackSaveStream;
	lp_nvs_SetRenderMode m_lp_nvs_SetRenderMode;
	lp_nvs_SetPosByFrameNum m_lp_nvs_SetPosByFrameNum;
	lp_nvs_GetVideoCut m_lp_nvs_GetVideoCut;
	lp_nvs_StopCutVideo m_lp_nvs_StopCutVideo;
	lp_nvs_SetFileEndCallback m_lp_nvs_SetFileEndCallback;
	lp_nvs_GetMediaInfo m_lp_nvs_GetMediaInfo;
	lp_nvs_GetDecodeParam m_lp_nvs_GetDecodeParam;
	lp_nvs_startPlayer4Standard m_lp_nvs_startPlayer4Standard;
	lp_nvs_SetYUVCallBack m_lp_nvs_SetYUVCallBack;
	lp_nvs_getRecordFileBySource m_lp_nvs_getRecordFileBySource;
	lp_nvs_downloadRecordFileBySource m_lp_nvs_downloadRecordFileBySource;


public:
	//! [01] ��ʼ��ҵ���߼�����ģ��
	virtual bool nvs_initEnviroment(const char* pAddress,unsigned short nPort,int nRight, char type);
	//! [02] ����ҵ���߼����Ļ���.
	virtual void nvs_cleanEnviroment();
	//! [03] �ͻ���ע������������.
	virtual bool nvs_registerOnIndex();
	//! [04] ���ò���ģʽ.
	virtual void nvs_setPlayModel(int nPlayModel);
	/*! ���ûص����� */
	virtual void nvs_setDecordCardCallBack(PlayResultByDecordCard pFun);
	virtual void nvs_setRealPlayCallBack(RealPlayCallBack pFun);
	virtual void nvs_setRealDecodeCallBack(LPDecCBFun pFun);
	virtual void nvs_setIndexNoticeCallBack(IndexNoticeCallBack pFun);
	virtual void nvs_setDVRNoticeCallBack(DVRNoticeCallBack pFun);
	//! [05] �ͻ���Ӳ�ⲥ��
	virtual int nvs_playVideoByDecordCard(int nCameraID,int nCardIndex, HANDLE* hStreamPlayHandle);
	//! [07] �ͻ�����ⲥ��
	virtual int nvs_playVideo2(int nCameraID,HWND hWnd, bool bUseDecode, bool bIsExternalDvr/*��ȡ��׼����ʶ*/);
	virtual int nvs_playVideo(int nCameraID,HWND hWnd, bool bUseDecode/*��ȡ��׼����ʶ*/);
	//! [08] �ͻ��˹ر�ĳ���ڵĲ���
	virtual bool nvs_stopPlayVideo(HWND hWnd, int nCardIndex, int nCameraID);
	virtual bool nvs_stopPlayByCameraID(int nCameraID);
	//! [09] �ͻ��˹ر����д��ڲ���
	virtual void nvs_stopAll();
	//! [11] �ͻ��˿�������ͷ(�������ٶ�)
	virtual bool nvs_controlCameraSpeed(int nCameraID,int nCmd,bool bControl,int nSpeed);
	//! [12] �Զ�ע��PTZ����Ȩ��
	virtual bool nvs_cancelControlCamera(HWND hWnd,int nCameraID);
	//! [13] ץͼ
	virtual bool nvs_capturePictureEx(int nCameraID, char* pFileName);
	//! [14] Ԥ��λ
	virtual bool nvs_TransPTZ(int nCameraID, int nCmd, int nTransPTZIndex);
	//! [15] ��ȡͨ������������������������Ƶ������
	virtual bool nvs_getCompress(int nCameraID, char **lpOutBuffer);
	//! [16] ����ͨ������
	virtual bool nvs_setCompress(int nCameraID, char* pCompressInfo);
	//! [17] ��ȡ��Ƶ���������ȡ�ɫ�ȡ����Ͷȵȣ�
	virtual bool nvs_getVideoEffect(int nCameraID, int* pBrightValue,int* pContrastValue, int* pSaturationValue,int* pHueValue);
	//! [18] ������Ƶ����
	virtual bool nvs_setVideoEffect(int nCameraID, DWORD dwBrightValue,DWORD dwContrastValue, DWORD dwSaturationValue,DWORD dwHueValue);
	//! [19] ��ʼ����¼��
	virtual int  nvs_startRecord(int nCameraID, char* pFileName);
	//! [20] ֹͣ����¼��
	virtual bool nvs_stopRecord(int nCameraID);
	//! [21] ʹ��͸��ͨ��
	virtual bool nvs_serialSend(int nCameraID, char* cmd1, DWORD nLen1, char* cmd2, DWORD nLen2);
	//! [22] ˢ��������Ƶ����ʹ�ü�����
	virtual void nvs_reSetDDrawDevice(int nCameraID);
	//! [23] �ָ�¼���ļ�
	virtual int nvs_splitFile(int nCameraID,char* sFileName,int nPriorTime);
	//! [24] ���д洢����
	virtual int nvs_play4Storage(int nCameraID,char* sFileName,int nPriorTime);
	//! [25] ���д洢����ֹͣ
	virtual bool nvs_stopPlay4Storage(int nCameraID);
	//! [26] ��������ͷ��Ƶ����
	virtual bool nvs_controlCameraSound(int nCameraID, bool bOpenSound);
	//! [27]�ͻ���֪ͨ�ص����������
	virtual bool nvs_clientNotice();
	//! [28]��ȡ��ý�幤��״̬
	virtual intptr_t nvs_getStreamServerWorkState(int nCameraID, int nCameraCount, int *outSize );
	//! [29]��ȡ
	virtual char * nvs_getStreamServerIP( int nCameraID);
	//! [30]�����Ƿ�Ϊ�����ͻ���
	virtual void nvs_SetExternalClient(bool bIsExternal);
	//! [31]רΪlinux�ṩ����־�ӿ� 
	virtual void nvs_writeLog(char* logMsg, int level);
	//! [32]���û�3�û��ص�����.
	virtual void nvs_SetHsCallBack(HsUserCallBack CallbackFun);
	//! [33]����ʵʱ��Ƶͷ�ص�����
	virtual void nvs_SetVedioHeadStreamCallBack(LPVedioHeadStreamCBFun pFun);
	//! [34]����ʵʱ��Ƶ���ص�����
	virtual void nvs_SetVedioBodyStreamCallBack(LPVedioBodyStreamCBFun pFun);
	//! [35]�ͻ��˴��û�ID�����ID��Linux
	virtual void nvs_SetUserIDandOrgID(int nUserID,int OrgID);
	//! [36] ����VIS֪ͨ�ص�����
    virtual void nvs_setNoticeSwitchedCallBack(NoticeSwitchedCallBack pFun);

	//! [37] ���õ��ӻص�����
	virtual void  nvs_SetDrawFun(LPDrawCBFun pFun);
	////////////////////////////////////////
	//! ���µĽӿ���ֱ�Ӵ�DVR�ϻ�ȡ��Ƶ(����)
	virtual intptr_t nvs_loginDVR(char* sIP, int nPort, char* sUser, char* sPwd);
	//! [2]�ͷ�����.
	virtual void nvs_logoutDVR(intptr_t identify);
	//! [3]�ͻ�����ⲥ��.
	virtual bool nvs_playVideoByDVR(intptr_t identify,int nCameraID,HWND hWnd);
	//! [4]�ͻ��˹ر�ĳ���ڵĲ���
	virtual bool nvs_stopPlayVideoByDVR(intptr_t identify,HWND hWnd);
	//! [5]�ͻ��˿�������ͷ(�������ٶ�)
	virtual bool nvs_controlCameraSpeedByDVR(intptr_t identify,int nCameraID,int nCmd,bool bControl,int nSpeed,int nChannel);
	//! [6]Ԥ��λ
	virtual bool nvs_presetPTZByDVR(intptr_t identify,int nCameraID, int nCmd, int nTransPTZIndex,int nChannel);
	//! [7]��ȡ����������ľ�ͷ��Ϣ
	virtual intptr_t nvs_getCameraInfo(intptr_t identify,int *nSize);
	//! [8]���ò��Ŵ��ھ��
	virtual int nvs_setPlayWindow(HWND palyWindow[], int nMaxCount);
	//! [9]���û�������IP�Ͷ˿�
	virtual bool nvs_InitHSServer(char *strIP, int nPort);
	//! ��ȡ������Ϣ
	virtual const char* nvs_GetErrorMessage(int nErrorCode);
	//V3.0
	//! [26] ��׼��Ƶ��Ϣ�ص���ʼ��
	virtual int  nvs_stdVideoinit(pNVSSipCallback pCB, void *pUser);
	//! [27] ��׼��Ƶ����ֹͣ
	virtual int  nvs_playStdVideo(char* sCameraID,HWND hWnd ,char* sIP, int nPort, char* sUser, char* sPwd ,char* sDllType, LPREALSTREAMCALLBACK lpCallBack, void* pUser);
	//! [28] ��׼��Ƶ����ֹͣ
	virtual int  nvs_stopStdVideo(char* sCameraID,HWND hWnd);
	//! [29] ��Ƶ��ǽ
	virtual int nvs_startPlayMonitor(char* sCameraCode, char *sMonitorCode,char* sIP, int nPort, char* sUser, char* sPwd ,char* sDllType);
	//! [30] ֹͣ��Ƶ��ǽ
	virtual int nvs_stopPlayMonitor(char *sMonitorCode);


	// ץͼ.
	virtual bool nvs_capturePictureByCode(char* sCameraCode, char* sFilePath);
	// �����ؼ�֡
	virtual void nvs_makeKey(char* sCameraCode);
	// ����DVR.
	virtual intptr_t nvs_connectDVR(char* sIP, int nPort, char* sUser, char* sPwd, int nChannel ,char* sDllType);
	// �ͷ�����.
	virtual void nvs_disconnectDVR(intptr_t identify);
	//ִ����̨����_��ͨ��
	virtual bool nvs_controlPTZSpeedWithChannel(string sCameraID,intptr_t identify,int nCmd, bool bEnable, int nSpeed, int nChannel);
	//ִ��Ԥ��λ_��ͨ��
	virtual bool nvs_presetPTZWithChannel(string sCameraID,intptr_t identify, int nCmd, int nIndex, int nChannel);
	// ������Ƶ����.
	virtual bool nvs_setVideoEffectByCode(string sCameraID,intptr_t identify,DWORD dwBrightValue,DWORD dwContrastValue, DWORD dwSaturationValue,DWORD dwHueValue);
	// ��ȡ��Ƶ����.
	virtual bool nvs_getVideoEffectByCode(string sCameraID,intptr_t identify,DWORD *pBrightValue,DWORD *pContrastValue, DWORD *pSaturationValue,DWORD *pHueValue);
	// ��ȡ�豸�ṹ.
	virtual bool nvs_getDVRConfig(string sCameraID,intptr_t identify, DWORD dwCommand,LONG lChannel,LPVOID lpOutBuffer,DWORD dwOutBufferSize,LPDWORD lpBytesReturned);

	// �����豸�ṹ.
	virtual bool nvs_setDVRConfig(string sCameraID,intptr_t identify, DWORD dwCommand,LONG lChannel,LPVOID lpInBuffer,DWORD dwInBufferSize);
	// ��ȡ¼���ļ��б�.
	virtual int  nvs_getRecordFileEx(string sCameraID,intptr_t identify,RECORDQUERYTYPE nType,char* startTime,char* endTime,RECORDFILE pRecordFile[],int nMaxFileCount);
	// ����¼���ļ�.
	virtual intptr_t nvs_downloadRecordFile(string sCameraID,intptr_t identify,char* fileName,char* startTime, char* endTime,int nFileSize,char* saveFile,LPDOWNLOADRECORDFILECALLBACK lpCallBack,void* pUser);
	// ֹͣ����¼���ļ�.
	virtual bool nvs_stopDownloadRecordFile(intptr_t identify,intptr_t ldownFileHandle);
	// ��ȡ���صĽ���.
	virtual int nvs_getDownloadPos(intptr_t identify,intptr_t lFileHandle);

	// Զ�̻ط�.
	virtual intptr_t nvs_replayRecordFile(string sCameraID,intptr_t identify,int hWnd,char* fileName,char* startTime, char* endTime,int nFileSize);
	// Զ�̻طſ���.
	virtual bool nvs_controlReplayRecordFile(intptr_t identify,intptr_t lReplayHandle,int nCmd,int nInValue,int* outValue);
	// ֹͣԶ�̻ط�.
	virtual bool nvs_stopReplayRecordFile(intptr_t identify,intptr_t lReplayHandle);

	// ��ʼ�����Խ�.
	virtual bool nvs_startTalk(string sCameraID,intptr_t identify);
	// ֹͣ�����Խ�.
	virtual bool nvs_stopTalk(string sCameraID,intptr_t identify);
	// ��ȡӲ��¼�������״̬.
	virtual bool nvs_getDVRWorkState(intptr_t identify,char dvrWorkState[],int arrayLen);

	//��ȡ�������
	virtual DWORD nvs_getLastError(string sCameraID,intptr_t identify);

	//Զ�̻ط�ʱץͼ
	virtual  bool nvs_playBackCaptureFile(intptr_t identify , intptr_t  lReplayHandle, char *pFileName);

	// ����طŵ�����
	virtual bool nvs_playBackSaveData(intptr_t identify,intptr_t lReplayHandle,char *sFileName);
	// ֹͣ����طŵ�����
	virtual bool nvs_stopPlayBackSave(intptr_t identify,intptr_t lReplayHandle);

	virtual bool nvs_startRecordByCode(string sCameraID,intptr_t identify, char* saveFile);

	virtual bool nvs_stopRecordByCode(string sCameraID,intptr_t identify);

	//�ֲ��Ŵ�(��Ӧ�����XY_SetCropArea()�ӿ�)
	virtual bool nvs_SetCropArea(string sCameraID,intptr_t identify, bool bFlag = false, int x1 = 0, int y1 = 0, int x2 = 0, int y2 = 0);

	//��Ƶ�������ܵ���(����nCmd����, �ֱ��Ӧ�����XY_SetClearFogParam(), XY_OpenOrCloseClearFog(), XY_OpenOrCloseInvert(), XY_OpenOrCloseSharpen()�ӿ�)
	virtual bool nvs_SetDecodeParam(string sCameraID,intptr_t identify, int nCmd, bool bFlag = false, int x1 = 0, int y1 = 0, int x2 = 0, int y2 = 0);

	/****���������ӿ���Ϊ��ʵ���ڿͻ��˲���ʵʱ��Ƶʱ��15����ٻط�****/

	//����ʵʱ����ʱ���������ݵ�ʱ��, Ĭ��15��
	virtual bool nvs_SetStreamSaveTime(string sCameraID,intptr_t identify, int nSaveTime = 15);

	//�طű������Ƶ��
	virtual bool nvs_PlayBackSaveStream(string sCameraID,intptr_t identify, HWND hWnd);

	//ֹͣ�طű������Ƶ��
	virtual bool nvs_StopPlayBackSaveStream(string sCameraID,intptr_t identify);
	//����ͼ�����Ⱦģʽ��Ĭ��ΪD3D��Ⱦ
	virtual bool nvs_SetRenderMode(string sCameraID,intptr_t identify, int nMode = RENDER_BY_D3D);

	//����֡�Ŷ�λ,��λ��nFrameNum����Ĺؼ�֡����ǰ���ң�
	virtual bool nvs_SetPosByFrameNum(string sCameraID,intptr_t identify,DWORD nFrameNum);

	//��ȡbeginTime��endTime֮���¼�񣬱�����filename��ָ����·����beginTime��endTimeΪ�뼶ʱ��
	virtual bool nvs_GetVideoCut(string sCameraID,intptr_t identify, DWORD beginFrame, DWORD endFrame, LPSTR filename);

	//��ֹ�ļ�����
	virtual bool nvs_StopCutVideo(string sCameraID,intptr_t identify);

	//�����ļ������ص�
	virtual bool nvs_SetFileEndCallback(string sCameraID,intptr_t identify, void *pUser, pFileOverCB pCallBack);// ֪ͨʹ�ã�Ϊ��ȷ����Ƶ�ļ��Ѿ�������ϣ���Ϊ������Ƶ�ļ��������ʱ����ǰ֡��������֡����

	//��ȡý����Ϣ
	virtual bool nvs_GetMediaInfo(string sCameraID,intptr_t identify,MediaInf &mInf);
	//��Ƶ�����ȡ���ò���
	virtual bool nvs_GetDecodeParam(string sCameraID,intptr_t identify, int nCmd, int &x1, int &y1, int &x2, int &y2);

	// ��ʼ���Ų��һ�ȡ��׼��ʽ��Ƶ��.
	virtual bool nvs_startPlayer4Standard(string sCameraID,intptr_t identify,HWND hWnd,LPDecCBFun lpDecCBFun, int nCameraID);

	//����YUV�ص�����(��Ӧ�����XY_SetStreamCallBackForVideo()�ӿ�)
	virtual bool nvs_SetYUVCallBack(string sCameraID,intptr_t identify, LPYUVCALLBACK pCallBack);

	//������ƵԴ��ȡ��ʷ��Ƶ����Ϣ  ������ƵԴ��ȡ��ʷ��Ƶ����Ϣ, ���ҵ�����Ϣ��pSipMsgCallBack�з���
	virtual bool nvs_getRecordFileBySource(string sCameraID,intptr_t identify,int nType, char* startTime, char* endTime, int nRecordSource);

	//����¼��
	virtual intptr_t nvs_downloadRecordFileBySource(string sCameraID,intptr_t identify,char* fileName,char* startTime, char* endTime,int nFileSize,char* saveFile,LPDOWNLOADRECORDFILECALLBACK lpCallBack,void* pUser, int nRecordSource);

	//V3.0
};


//////////////////////////////////////////////////////////////////
//Linux version

class NVSPlayLibLux : public NVSPlayLib
{
public:
	NVSPlayLibLux(void);
public:
	~NVSPlayLibLux(void);
public:
	HMODULE m_hDllLux;
public:
	lp_nvs_initEnviroment m_lp_nvs_initEnviroment;
	lp_nvs_cleanEnviroment m_lp_nvs_cleanEnviroment;
	lp_nvs_registerOnIndex m_lp_nvs_registerOnIndex;
	lp_nvs_setPlayModel m_lp_nvs_setPlayModel;
	lp_nvs_setDecordCardCallBack m_lp_nvs_setDecordCardCallBack;
	lp_nvs_setRealPlayCallBack m_lp_nvs_setRealPlayCallBack;
	lp_nvs_setRealDecodeCallBack m_lp_nvs_setRealDecodeCallBack;
	lp_nvs_setIndexNoticeCallBack m_lp_nvs_setIndexNoticeCallBack;
	lp_nvs_setDVRNoticeCallBack m_lp_nvs_setDVRNoticeCallBack;
	lp_nvs_playVideoByDecordCard m_lp_nvs_playVideoByDecordCard;
	lp_nvs_playVideo2 m_lp_nvs_playVideo2;
	lp_nvs_playVideo m_lp_nvs_playVideo;
	lp_nvs_stopPlayVideo m_lp_nvs_stopPlayVideo;
	lp_nvs_stopPlayByCameraID m_lp_nvs_stopPlayByCameraID;
	lp_nvs_stopAll m_lp_nvs_stopAll;
	lp_nvs_controlCameraSpeed m_lp_nvs_controlCameraSpeed;
	lp_nvs_cancelControlCamera m_lp_nvs_cancelControlCamera;
	lp_nvs_capturePictureEx m_lp_nvs_capturePictureEx;
	lp_nvs_TransPTZ m_lp_nvs_TransPTZ;
	lp_nvs_getCompress m_lp_nvs_getCompress;
	lp_nvs_setCompress m_lp_nvs_setCompress;
	lp_nvs_getVideoEffect m_lp_nvs_getVideoEffect;
	lp_nvs_setVideoEffect m_lp_nvs_setVideoEffect;
	lp_nvs_startRecord m_lp_nvs_startRecord;
	lp_nvs_stopRecord m_lp_nvs_stopRecord;
	lp_nvs_serialSend m_lp_nvs_serialSend;
	lp_nvs_reSetDDrawDevice m_lp_nvs_reSetDDrawDevice;
	lp_nvs_splitFile m_lp_nvs_splitFile;
	lp_nvs_play4Storage m_lp_nvs_play4Storage;
	lp_nvs_stopPlay4Storage m_lp_nvs_stopPlay4Storage;
	lp_nvs_controlCameraSound m_lp_nvs_controlCameraSound;
	lp_nvs_clientNotice m_lp_nvs_clientNotice;
	lp_nvs_loginDVR m_lp_nvs_loginDVR;
	lp_nvs_logoutDVR m_lp_nvs_logoutDVR;
	lp_nvs_playVideoByDVR m_lp_nvs_playVideoByDVR;
	lp_nvs_stopPlayVideoByDVR m_lp_nvs_stopPlayVideoByDVR;
	lp_nvs_controlCameraSpeedByDVR m_lp_nvs_controlCameraSpeedByDVR;
	lp_nvs_presetPTZByDVR m_lp_nvs_presetPTZByDVR;
	lp_nvs_getCameraInfo m_lp_nvs_getCameraInfo;
	lp_nvs_setPlayWindow m_lp_nvs_setPlayWindow;
	lp_nvs_getStreamServerWorkState m_lp_nvs_getStreamServerWorkState;
	lp_nvs_getStreamServerIP m_lp_nvs_getStreamServerIP;
	lp_nvs_SetExternalClient m_lp_nvs_SetExternalClient;
	lp_nvs_writeLog m_lp_nvs_writeLog;
	lp_nvs_InitHSServer m_lp_nvs_InitHSServer;
	lp_nvs_SetHsCallBack m_lp_nvs_SetHsCallBack;
	lp_LPVedioHeadStreamCBFun m_lp_LPVedioHeadStreamCBFun;
	lp_LPVedioBodyStreamCBFun m_lp_LPVedioBodyStreamCBFun;
	lp_nvs_SetUserIDandOrgID m_lp_nvs_SetUserIDandOrgID;
	lp_nvs_setNoticeSwitchedCallBack m_lp_nvs_setNoticeSwitchedCallBack;
	lp_nvs_SetDrawFun m_lp_nvs_SetDrawFun;
	lp_nvs_GetErrorMessage m_lp_nvs_GetErrorMessage;
	lp_nvs_stdVideoinit	m_lp_nvs_stdVideoinit;	
	lp_nvs_playStdVideo	m_lp_nvs_playStdVideo;
	lp_nvs_stopStdVideo	m_lp_nvs_stopStdVideo;
	lp_nvs_startPlayMonitor m_lp_nvs_startPlayMonitor;
	lp_nvs_stopPlayMonitor  m_lp_nvs_stopPlayMonitor;

	lp_nvs_capturePictureByCode m_lp_nvs_capturePictureByCode;
	lp_nvs_makeKey m_lp_nvs_makeKey;
	lp_nvs_connectDVR m_lp_nvs_connectDVR;
	lp_nvs_disconnectDVR m_lp_nvs_disconnectDVR;
	lp_nvs_controlPTZSpeedWithChannel m_lp_nvs_controlPTZSpeedWithChannel;
	lp_nvs_presetPTZWithChannel m_lp_nvs_presetPTZWithChannel;
	lp_nvs_setVideoEffectByCode m_lp_nvs_setVideoEffectByCode;
	lp_nvs_getVideoEffectByCode m_lp_nvs_getVideoEffectByCode;
	lp_nvs_getDVRConfig m_lp_nvs_getDVRConfig;
	lp_nvs_setDVRConfig m_lp_nvs_setDVRConfig;
	lp_nvs_getRecordFileEx m_lp_nvs_getRecordFileEx;
	lp_nvs_downloadRecordFile m_lp_nvs_downloadRecordFile;
	lp_nvs_stopDownloadRecordFile m_lp_nvs_stopDownloadRecordFile;
	lp_nvs_getDownloadPos m_lp_nvs_getDownloadPos;
	lp_nvs_replayRecordFile m_lp_nvs_replayRecordFile;
	lp_nvs_controlReplayRecordFile m_lp_nvs_controlReplayRecordFile;
	lp_nvs_stopReplayRecordFile m_lp_nvs_stopReplayRecordFile;
	lp_nvs_startTalk m_lp_nvs_startTalk;
	lp_nvs_stopTalk m_lp_nvs_stopTalk;
	lp_nvs_getDVRWorkState m_lp_nvs_getDVRWorkState;
	lp_nvs_getLastError m_lp_nvs_getLastError;
	lp_nvs_playBackCaptureFile m_lp_nvs_playBackCaptureFile;
	lp_nvs_playBackSaveData m_lp_nvs_playBackSaveData;
	lp_nvs_stopPlayBackSave m_lp_nvs_stopPlayBackSave;
	lp_nvs_startRecordByCode m_lp_nvs_startRecordByCode;
	lp_nvs_stopRecordByCode m_lp_nvs_stopRecordByCode;
	lp_nvs_SetCropArea m_lp_nvs_SetCropArea;
	lp_nvs_SetDecodeParam m_lp_nvs_SetDecodeParam;
	lp_nvs_SetStreamSaveTime m_lp_nvs_SetStreamSaveTime;
	lp_nvs_PlayBackSaveStream m_lp_nvs_PlayBackSaveStream;
	lp_nvs_StopPlayBackSaveStream m_lp_nvs_StopPlayBackSaveStream;
	lp_nvs_SetRenderMode m_lp_nvs_SetRenderMode;
	lp_nvs_SetPosByFrameNum m_lp_nvs_SetPosByFrameNum;
	lp_nvs_GetVideoCut m_lp_nvs_GetVideoCut;
	lp_nvs_StopCutVideo m_lp_nvs_StopCutVideo;
	lp_nvs_SetFileEndCallback m_lp_nvs_SetFileEndCallback;
	lp_nvs_GetMediaInfo m_lp_nvs_GetMediaInfo;
	lp_nvs_GetDecodeParam m_lp_nvs_GetDecodeParam;
	lp_nvs_startPlayer4Standard m_lp_nvs_startPlayer4Standard;
	lp_nvs_SetYUVCallBack m_lp_nvs_SetYUVCallBack;
	lp_nvs_getRecordFileBySource m_lp_nvs_getRecordFileBySource;
	lp_nvs_downloadRecordFileBySource m_lp_nvs_downloadRecordFileBySource;

public:
	//! [01] ��ʼ��ҵ���߼�����ģ��
	virtual bool nvs_initEnviroment(const char* pAddress,unsigned short nPort,int nRight, char type);
	//! [02] ����ҵ���߼����Ļ���.
	virtual void nvs_cleanEnviroment();
	//! [03] �ͻ���ע������������.
	virtual bool nvs_registerOnIndex();
	//! [04] ���ò���ģʽ.
	virtual void nvs_setPlayModel(int nPlayModel);
	/*! ���ûص����� */
	virtual void nvs_setDecordCardCallBack(PlayResultByDecordCard pFun);
	virtual void nvs_setRealPlayCallBack(RealPlayCallBack pFun);
	virtual void nvs_setRealDecodeCallBack(LPDecCBFun pFun);
	virtual void nvs_setIndexNoticeCallBack(IndexNoticeCallBack pFun);
	virtual void nvs_setDVRNoticeCallBack(DVRNoticeCallBack pFun);
	//! [05] �ͻ���Ӳ�ⲥ��
	virtual int nvs_playVideoByDecordCard(int nCameraID,int nCardIndex, HANDLE* hStreamPlayHandle);
	//! [07] �ͻ�����ⲥ��
	virtual int nvs_playVideo(int nCameraID,HWND hWnd, bool bUseDecode/*��ȡ��׼����ʶ*/);
	virtual int nvs_playVideo2(int nCameraID,HWND hWnd, bool bUseDecode/*��ȡ��׼����ʶ*/, bool bIsExternalDvr);
	//! [08] �ͻ��˹ر�ĳ���ڵĲ���
	virtual bool nvs_stopPlayVideo(HWND hWnd, int nCardIndex, int nCameraID);
	virtual bool nvs_stopPlayByCameraID(int nCameraID);
	//! [09] �ͻ��˹ر����д��ڲ���
	virtual void nvs_stopAll();
	//! [11] �ͻ��˿�������ͷ(�������ٶ�)
	virtual bool nvs_controlCameraSpeed(int nCameraID,int nCmd,bool bControl,int nSpeed);
	//! [12] �Զ�ע��PTZ����Ȩ��
	virtual bool nvs_cancelControlCamera(HWND hWnd,int nCameraID);
	//! [13] ץͼ
	virtual bool nvs_capturePictureEx(int nCameraID, char* pFileName);
	//! [14] Ԥ��λ
	virtual bool nvs_TransPTZ(int nCameraID, int nCmd, int nTransPTZIndex);
	//! [15] ��ȡͨ������������������������Ƶ������
	virtual bool nvs_getCompress(int nCameraID, char **lpOutBuffer);
	//! [16] ����ͨ������
	virtual bool nvs_setCompress(int nCameraID, char* pCompressInfo);
	//! [17] ��ȡ��Ƶ���������ȡ�ɫ�ȡ����Ͷȵȣ�
	virtual bool nvs_getVideoEffect(int nCameraID, int* pBrightValue,int* pContrastValue, int* pSaturationValue,int* pHueValue);
	//! [18] ������Ƶ����
	virtual bool nvs_setVideoEffect(int nCameraID, DWORD dwBrightValue,DWORD dwContrastValue, DWORD dwSaturationValue,DWORD dwHueValue);
	//! [19] ��ʼ����¼��
	virtual int  nvs_startRecord(int nCameraID, char* pFileName);
	//! [20] ֹͣ����¼��
	virtual bool nvs_stopRecord(int nCameraID);
	//! [21] ʹ��͸��ͨ��
	virtual bool nvs_serialSend(int nCameraID, char* cmd1, DWORD nLen1, char* cmd2, DWORD nLen2);
	//! [22] ˢ��������Ƶ����ʹ�ü�����
	virtual void nvs_reSetDDrawDevice(int nCameraID);
	//! [23] �ָ�¼���ļ�
	virtual int nvs_splitFile(int nCameraID,char* sFileName,int nPriorTime);
	//! [24] ���д洢����
	virtual int nvs_play4Storage(int nCameraID,char* sFileName,int nPriorTime);
	//! [25] ���д洢����ֹͣ
	virtual bool nvs_stopPlay4Storage(int nCameraID);
	//! [26] ��������ͷ��Ƶ����
	virtual bool nvs_controlCameraSound(int nCameraID, bool bOpenSound);
	//! [27]�ͻ���֪ͨ�ص����������
	virtual bool nvs_clientNotice();
	//! [28]��ȡ��ý�幤��״̬
	virtual intptr_t nvs_getStreamServerWorkState(int nCameraID, int nCameraCount, int *outSize );
	//! [29]��ȡ
	virtual char * nvs_getStreamServerIP( int nCameraID);
	//! [30]�����Ƿ�Ϊ�����ͻ���
	virtual void nvs_SetExternalClient(bool bIsExternal);
	//! [31]רΪlinux�ṩ����־�ӿ� 
	virtual void nvs_writeLog(char* logMsg, int level);
	//! [32]���û�3�û��ص�����.
	virtual void nvs_SetHsCallBack(HsUserCallBack CallbackFun);
	//! [33]����ʵʱ��Ƶͷ�ص�����
	virtual void nvs_SetVedioHeadStreamCallBack(LPVedioHeadStreamCBFun pFun);
	//! [34]����ʵʱ��Ƶ���ص�����
	virtual void nvs_SetVedioBodyStreamCallBack(LPVedioBodyStreamCBFun pFun);
	//! [35]�ͻ��˴��û�ID�����ID��Linux
	virtual void nvs_SetUserIDandOrgID(int nUserID,int OrgID);
	//! [36] ����VIS֪ͨ�ص�����
    virtual void nvs_setNoticeSwitchedCallBack(NoticeSwitchedCallBack pFun);
	//! [37] ���õ��ӻص�����
	virtual void  nvs_SetDrawFun(LPDrawCBFun pFun);

	///////////////////////////////////////
	//! ���µĽӿ���ֱ�Ӵ�DVR�ϻ�ȡ��Ƶ(����)
	virtual intptr_t nvs_loginDVR(char* sIP, int nPort, char* sUser, char* sPwd);
	//! [2]�ͷ�����.
	virtual void nvs_logoutDVR(intptr_t identify);
	//! [3]�ͻ�����ⲥ��.
	virtual bool nvs_playVideoByDVR(intptr_t identify,int nCameraID,HWND hWnd);
	//! [4]�ͻ��˹ر�ĳ���ڵĲ���
	virtual bool nvs_stopPlayVideoByDVR(intptr_t identify,HWND hWnd);
	//! [5]�ͻ��˿�������ͷ(�������ٶ�)
	virtual bool nvs_controlCameraSpeedByDVR(intptr_t identify,int nCameraID,int nCmd,bool bControl,int nSpeed,int nChannel);
	//! [6]Ԥ��λ
	virtual bool nvs_presetPTZByDVR(intptr_t identify,int nCameraID, int nCmd, int nTransPTZIndex,int nChannel);
	//! [7]��ȡ����������ľ�ͷ��Ϣ
	virtual intptr_t nvs_getCameraInfo(intptr_t identify,int *nSize);
	//! [8]���ò��Ŵ��ھ��
	virtual int nvs_setPlayWindow(HWND palyWindow[], int nMaxCount);
	//! [9]���û�������IP�Ͷ˿�
	virtual bool nvs_InitHSServer(char *strIP, int nPort);
	//! ��ȡ������Ϣ
	virtual const char* nvs_GetErrorMessage(int nErrorCode);
	//V3.0
	//! [26] ��׼��Ƶ��Ϣ�ص���ʼ��
	virtual int  nvs_stdVideoinit(pNVSSipCallback pCB, void *pUser);
	//! [27] ��׼��Ƶ����
	virtual int  nvs_playStdVideo(char* sCameraID,HWND hWnd ,char* sIP, int nPort, char* sUser, char* sPwd ,char* sDllType, LPREALSTREAMCALLBACK lpCallBack, void* pUser);
	//! [28] ��׼��Ƶ����ֹͣ
	virtual int  nvs_stopStdVideo(char* sCameraID,HWND hWnd);
	//! [29] ��Ƶ��ǽ
	virtual int nvs_startPlayMonitor(char* sCameraCode, char *sMonitorCode,char* sIP, int nPort, char* sUser, char* sPwd ,char* sDllType);
	//! [30] ֹͣ��Ƶ��ǽ
	virtual int nvs_stopPlayMonitor(char *sMonitorCode);

	// ץͼ.
	virtual bool nvs_capturePictureByCode(char* sCameraCode, char* sFilePath);
	// �����ؼ�֡
	virtual void nvs_makeKey(char* sCameraCode);
	// ����DVR.
	virtual intptr_t nvs_connectDVR(char* sIP, int nPort, char* sUser, char* sPwd, int nChannel ,char* sDllType);
	// �ͷ�����.
	virtual void nvs_disconnectDVR(intptr_t identify);
	//ִ����̨����_��ͨ��
	virtual bool nvs_controlPTZSpeedWithChannel(string sCameraID,intptr_t identify,int nCmd, bool bEnable, int nSpeed, int nChannel);
	//ִ��Ԥ��λ_��ͨ��
	virtual bool nvs_presetPTZWithChannel(string sCameraID,intptr_t identify, int nCmd, int nIndex, int nChannel);
	// ������Ƶ����.
	virtual bool nvs_setVideoEffectByCode(string sCameraID,intptr_t identify,DWORD dwBrightValue,DWORD dwContrastValue, DWORD dwSaturationValue,DWORD dwHueValue);
	// ��ȡ��Ƶ����.
	virtual bool nvs_getVideoEffectByCode(string sCameraID,intptr_t identify,DWORD *pBrightValue,DWORD *pContrastValue, DWORD *pSaturationValue,DWORD *pHueValue);
	// ��ȡ�豸�ṹ.
	virtual bool nvs_getDVRConfig(string sCameraID,intptr_t identify, DWORD dwCommand,LONG lChannel,LPVOID lpOutBuffer,DWORD dwOutBufferSize,LPDWORD lpBytesReturned);

	// �����豸�ṹ.
	virtual bool nvs_setDVRConfig(string sCameraID,intptr_t identify, DWORD dwCommand,LONG lChannel,LPVOID lpInBuffer,DWORD dwInBufferSize);
	// ��ȡ¼���ļ��б�.
	virtual int  nvs_getRecordFileEx(string sCameraID,intptr_t identify,RECORDQUERYTYPE nType,char* startTime,char* endTime,RECORDFILE pRecordFile[],int nMaxFileCount);
	// ����¼���ļ�.
	virtual intptr_t nvs_downloadRecordFile(string sCameraID,intptr_t identify,char* fileName,char* startTime, char* endTime,int nFileSize,char* saveFile,LPDOWNLOADRECORDFILECALLBACK lpCallBack,void* pUser);
	// ֹͣ����¼���ļ�.
	virtual bool nvs_stopDownloadRecordFile(intptr_t identify,intptr_t ldownFileHandle);
	// ��ȡ���صĽ���.
	virtual int nvs_getDownloadPos(intptr_t identify,intptr_t lFileHandle);

	// Զ�̻ط�.
	virtual intptr_t nvs_replayRecordFile(string sCameraID,intptr_t identify,int hWnd,char* fileName,char* startTime, char* endTime,int nFileSize);
	// Զ�̻طſ���.
	virtual bool nvs_controlReplayRecordFile(intptr_t identify,intptr_t lReplayHandle,int nCmd,int nInValue,int* outValue);
	// ֹͣԶ�̻ط�.
	virtual bool nvs_stopReplayRecordFile(intptr_t identify,intptr_t lReplayHandle);

	// ��ʼ�����Խ�.
	virtual bool nvs_startTalk(string sCameraID,intptr_t identify);
	// ֹͣ�����Խ�.
	virtual bool nvs_stopTalk(string sCameraID,intptr_t identify);
	// ��ȡӲ��¼�������״̬.
	virtual bool nvs_getDVRWorkState(intptr_t identify,char dvrWorkState[],int arrayLen);

	//��ȡ�������
	virtual DWORD nvs_getLastError(string sCameraID,intptr_t identify);

	//Զ�̻ط�ʱץͼ
	virtual  bool nvs_playBackCaptureFile(intptr_t identify , intptr_t  lReplayHandle, char *pFileName);

	// ����طŵ�����
	virtual bool nvs_playBackSaveData(intptr_t identify,intptr_t lReplayHandle,char *sFileName);
	// ֹͣ����طŵ�����
	virtual bool nvs_stopPlayBackSave(intptr_t identify,intptr_t lReplayHandle);

	virtual bool nvs_startRecordByCode(string sCameraID,intptr_t identify, char* saveFile);

	virtual bool nvs_stopRecordByCode(string sCameraID,intptr_t identify);

	//�ֲ��Ŵ�(��Ӧ�����XY_SetCropArea()�ӿ�)
	virtual bool nvs_SetCropArea(string sCameraID,intptr_t identify, bool bFlag = false, int x1 = 0, int y1 = 0, int x2 = 0, int y2 = 0);

	//��Ƶ�������ܵ���(����nCmd����, �ֱ��Ӧ�����XY_SetClearFogParam(), XY_OpenOrCloseClearFog(), XY_OpenOrCloseInvert(), XY_OpenOrCloseSharpen()�ӿ�)
	virtual bool nvs_SetDecodeParam(string sCameraID,intptr_t identify, int nCmd, bool bFlag = false, int x1 = 0, int y1 = 0, int x2 = 0, int y2 = 0);

	/****���������ӿ���Ϊ��ʵ���ڿͻ��˲���ʵʱ��Ƶʱ��15����ٻط�****/

	//����ʵʱ����ʱ���������ݵ�ʱ��, Ĭ��15��
	virtual bool nvs_SetStreamSaveTime(string sCameraID,intptr_t identify, int nSaveTime = 15);

	//�طű������Ƶ��
	virtual bool nvs_PlayBackSaveStream(string sCameraID,intptr_t identify, HWND hWnd);

	//ֹͣ�طű������Ƶ��
	virtual bool nvs_StopPlayBackSaveStream(string sCameraID,intptr_t identify);
	//����ͼ�����Ⱦģʽ��Ĭ��ΪD3D��Ⱦ
	virtual bool nvs_SetRenderMode(string sCameraID,intptr_t identify, int nMode = RENDER_BY_D3D);

	//����֡�Ŷ�λ,��λ��nFrameNum����Ĺؼ�֡����ǰ���ң�
	virtual bool nvs_SetPosByFrameNum(string sCameraID,intptr_t identify,DWORD nFrameNum);

	//��ȡbeginTime��endTime֮���¼�񣬱�����filename��ָ����·����beginTime��endTimeΪ�뼶ʱ��
	virtual bool nvs_GetVideoCut(string sCameraID,intptr_t identify, DWORD beginFrame, DWORD endFrame, LPSTR filename);

	//��ֹ�ļ�����
	virtual bool nvs_StopCutVideo(string sCameraID,intptr_t identify);

	//�����ļ������ص�
	virtual bool nvs_SetFileEndCallback(string sCameraID,intptr_t identify, void *pUser, pFileOverCB pCallBack);// ֪ͨʹ�ã�Ϊ��ȷ����Ƶ�ļ��Ѿ�������ϣ���Ϊ������Ƶ�ļ��������ʱ����ǰ֡��������֡����

	//��ȡý����Ϣ
	virtual bool nvs_GetMediaInfo(string sCameraID,intptr_t identify,MediaInf &mInf);
	//��Ƶ�����ȡ���ò���
	virtual bool nvs_GetDecodeParam(string sCameraID,intptr_t identify, int nCmd, int &x1, int &y1, int &x2, int &y2);

	// ��ʼ���Ų��һ�ȡ��׼��ʽ��Ƶ��.
	virtual bool nvs_startPlayer4Standard(string sCameraID,intptr_t identify,HWND hWnd,LPDecCBFun lpDecCBFun, int nCameraID);

	//����YUV�ص�����(��Ӧ�����XY_SetStreamCallBackForVideo()�ӿ�)
	virtual bool nvs_SetYUVCallBack(string sCameraID,intptr_t identify, LPYUVCALLBACK pCallBack);

	//������ƵԴ��ȡ��ʷ��Ƶ����Ϣ  ������ƵԴ��ȡ��ʷ��Ƶ����Ϣ, ���ҵ�����Ϣ��pSipMsgCallBack�з���
	virtual bool nvs_getRecordFileBySource(string sCameraID,intptr_t identify,int nType, char* startTime, char* endTime, int nRecordSource);

	//����¼��
	virtual intptr_t nvs_downloadRecordFileBySource(string sCameraID,intptr_t identify,char* fileName,char* startTime, char* endTime,int nFileSize,char* saveFile,LPDOWNLOADRECORDFILECALLBACK lpCallBack,void* pUser, int nRecordSource);
	//V3.0
};