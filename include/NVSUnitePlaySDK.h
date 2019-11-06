#ifndef __NVSUNITEPLAYSDK_H__
#define __NVSUNITEPLAYSDK_H__

#include "nvssdkfunctions.h"
#include <vector>
using namespace std;

#ifdef _USRDLL
#define NVSUNITEPLAY_API extern "C" __declspec(dllexport)
#else
#define NVSUNITEPLAY_API extern "C" __declspec(dllimport)
#endif

/*! ����DLLģʽWindows����Ϊ0 */
#define PLAYLIB_WIN 0
/*! ����DLLģʽLinux  ����Ϊ1 */
#define PLAYLIB_LUX	1

/*! ��ⲥ�Ž���ص�ָ�� */ 
/*!
\param nCameraID ��Ӧ��ͷ
\param nRe �ص�����״̬ 0-���ųɹ� -1���ò��ſⲥ��ʧ�� -2��ʼ�����ſ�ʧ�� -3��ȡ���Ŷ˿�ʧ�� -4ͷ����Ϊ��
*/
typedef void (CALLBACK * RealPlayCallBack)(int nCameraID, int nRe/*ʵ�ʲ��Ž��*/);
/*! Ӳ�ⲥ�Ž���ص�ָ�� */
typedef void (CALLBACK * PlayResultByDecordCard)(int,int,int/* 0���ųɹ��� 1����ʧ�� 2����ʧ��*/);
typedef void (CALLBACK *LPDecCBFun)(long nPort,char * pBuf,long nSize,FRAME_INFO_D * pFrameInfo, int nCameraID);
/*! ����֪ͨ�ص�ָ��
\param nUserID;     //�û�ID
\param nChangeType; //��������
\param nLimitTime;  //��ʱ����ʱ��
*/
typedef void (CALLBACK *IndexNoticeCallBack)(int nUserID, int nChangeType, int nLimitTime);

/*! ��¼DVR֪ͨ�ص�ָ��
\param nCameraID;     //��ͷID
\param nErr;          //������
*/
typedef void (CALLBACK *DVRNoticeCallBack)(int nCameraID, int nErr);

//! ��3�û��ص�����.
/*!
\param sUser �û���.
\param sPass ����.
\param bGetUser Ϊtrueʱ��ȡ��3�û���Ϊfalseʱ���ͷŻ�3�û�.
\return �Ƿ�ɹ�
*/
typedef bool (CALLBACK* HsUserCallBack)(char* sUser,char* sPass,bool bGetUser);

/*! ʵʱ��Ƶͷ�ص�ָ��
\param  pBuf;     //����
\param  nSizeint  //�����С
\praram nCameraID //��ͷID
*/

typedef void (CALLBACK *LPVedioHeadStreamCBFun)(BYTE * pBuf,long nSizeint, int  nCameraID);

/*! ʵʱ��Ƶ���ص�ָ��
\param  pBuf;     //����
\param  nSizeint  //�����С
\praram nCameraID //��ͷID
*/
typedef void (CALLBACK *LPVedioBodyStreamCBFun)(BYTE * pBuf,long nSizeint, int  nCameraID);

/*! ��Ƶ���л�֪ͨ�ص�ָ��
\param nUserID;       //�û�ID
\param nCameraID;     //��ͷID
*/
/*! Ԥ����������ַ���ͼ��
\param lRealHandle NET_DVR_RealPlay()��NET_DVR_RealPlay_V30()�ķ���ֵ 
\param hDc ��ͼ���
\param nCameraID ��ͷID
*/
typedef void (CALLBACK *LPDrawCBFun)(intptr_t lRealHandle, DWORD hDc, int nCameraID);

typedef void (CALLBACK *NoticeSwitchedCallBack)(int nUserID,int nPriorCameraID,int nCameraID,char* pDesc);


//! [00] ѡ��DLLģʽ
/*!
\param cType 0-DLL Windows 1-Linux
\return ��
*/
NVSUNITEPLAY_API void nvs_selectLib(char cType = PLAYLIB_WIN);
//! [01] ��ʼ��ҵ���߼�����ģ��
/*!
\param pAddress ���������ַ.
\param nPort ��������˿�.
\param type ICEͨѶ��ʽ.
\param nRight Ȩ��ֵ.
\return ��ʼ���ɹ����
*/
NVSUNITEPLAY_API bool nvs_initEnviroment(const char* pAddress,unsigned short nPort,int nRight, char type);
//! [02] ����ҵ���߼����Ļ���.
/*!
\return ��
*/
NVSUNITEPLAY_API void nvs_cleanEnviroment();
//! [03] �ͻ���ע������������.
/*!
\return ע����
*/
NVSUNITEPLAY_API bool nvs_registerOnIndex();
//! [04] ���ò���ģʽ.
/*!
\param nPlayModel /0-��ⲥ�� 1-Ӳ�ⲥ�� 2-���д洢.
\return ��
*/
NVSUNITEPLAY_API void nvs_setPlayModel(int nPlayModel);
/*! ���ûص����� */
NVSUNITEPLAY_API void nvs_setDecordCardCallBack(PlayResultByDecordCard pFun);
NVSUNITEPLAY_API void nvs_setRealPlayCallBack(RealPlayCallBack pFun);
NVSUNITEPLAY_API void nvs_setRealDecodeCallBack(LPDecCBFun pFun);
NVSUNITEPLAY_API void nvs_setIndexNoticeCallBack(IndexNoticeCallBack pFun);
NVSUNITEPLAY_API void nvs_setDVRNoticeCallBack(DVRNoticeCallBack pFun);

//! [35] ����VIS�ص�����
/*!
\param pFun �ص�����ָ��
*/
NVSUNITEPLAY_API void nvs_setNoticeSwitchedCallBack(NoticeSwitchedCallBack pFun);

//! [05] �ͻ���Ӳ�ⲥ��
/*!
\param nCameraID ������Ƶ�����ͷID
\param nCardIndex Ӳ�ⲥ�ŵĿ����
\return ���󲥷Ž�� 0-���ųɹ� -1��ý���ȡ������ʧ�� -2�ô����ѱ�ռ�� -3������ý��ʧ�� -4���ų����쳣 -5���ڵȴ�ͷ����
*/
NVSUNITEPLAY_API int nvs_playVideoByDecordCard(int nCameraID,int nCardIndex, HANDLE* hStreamPlayHandle);
//! [07] �ͻ�����ⲥ��
/*!
\param nCameraID ����ͷID
\param hWnd ���ŵĴ��ھ��
\param bUseDecode ��ȡ��׼����ʶ
\return ���󲥷Ž�� 0-���󲥷ųɹ� -1��ý���ȡ������ʧ�� -2�ô����ѱ�ռ�� -3������ý��ʧ�� -4���ų����쳣 -5���ڵȴ�ͷ���� -6δע���������� -7δ���ñ�׼���ص�
*/
NVSUNITEPLAY_API int nvs_playVideo2(int nCameraID,HWND hWnd, bool bUseDecode/*��ȡ��׼����ʶ*/, bool bIsExternalDvr );

NVSUNITEPLAY_API int nvs_playVideo(int nCameraID,HWND hWnd, bool bUseDecode/*��ȡ��׼����ʶ*/);
//! [08] �ͻ��˹ر�ĳ���ڵĲ���
/*!
\param hWnd ���ŵĴ��ھ��
\return ��
*/
NVSUNITEPLAY_API bool nvs_stopPlayVideo(HWND hWnd, int nCardIndex, int nCameraID);

NVSUNITEPLAY_API bool nvs_stopPlayByCameraID(int nCameraID);
//! [09] �ͻ��˹ر����д��ڲ���
/*!
\return ��
*/
NVSUNITEPLAY_API void nvs_stopAll();
//! [11] �ͻ��˿�������ͷ(�������ٶ�)
/*!
\param nCameraID ������Ƶ�����ͷID
\param nCmd ���Ʊ�־
\param bControl ��ͣ
\return ���ؿ��Ƴɹ����
\nSpeed �����ٶ�ֵ1-15����
*/
NVSUNITEPLAY_API bool nvs_controlCameraSpeed(int nCameraID,int nCmd,bool bControl,int nSpeed);
//! [12] �Զ�ע��PTZ����Ȩ��
NVSUNITEPLAY_API bool nvs_cancelControlCamera(HWND hWnd,int nCameraID);

//! [13] ץͼ
NVSUNITEPLAY_API bool nvs_capturePictureEx(int nCameraID, char* pFileName);
//! [14] Ԥ��λ
NVSUNITEPLAY_API bool nvs_TransPTZ(int nCameraID, int nCmd, int nTransPTZIndex);
//! [15] ��ȡͨ������������������������Ƶ������
NVSUNITEPLAY_API bool nvs_getCompress(int nCameraID, char **lpOutBuffer);
//! [16] ����ͨ������
NVSUNITEPLAY_API bool nvs_setCompress(int nCameraID, char* pCompressInfo);
//! [17] ��ȡ��Ƶ���������ȡ�ɫ�ȡ����Ͷȵȣ�
NVSUNITEPLAY_API bool nvs_getVideoEffect(int nCameraID, int* pBrightValue,int* pContrastValue, int* pSaturationValue,int* pHueValue);
//! [18] ������Ƶ����
NVSUNITEPLAY_API bool nvs_setVideoEffect(int nCameraID, DWORD dwBrightValue,DWORD dwContrastValue, DWORD dwSaturationValue,DWORD dwHueValue);
//! [19] ��ʼ����¼��
/*!
\return [-1]δע������
[-2]������������ý��ʧ�ܻ��쳣
[-3]δע����ý�����
[-4]����VideoProcessʧ��
[-5]����ָ��������Ƶʧ��
[-6]����¼���ļ�ʧ��
[-7]�ļ�ͷΪ��,д��ͷ�ļ�ʧ��
[0]�ɹ�
[1]����¼��

*/
NVSUNITEPLAY_API int  nvs_startRecord(int nCameraID, char* pFileName);
//! [20] ֹͣ����¼��
NVSUNITEPLAY_API bool nvs_stopRecord(int nCameraID);
//! [21] ʹ��͸��ͨ��
NVSUNITEPLAY_API bool nvs_serialSend(int nCameraID, char* cmd1, DWORD nLen1, char* cmd2, DWORD nLen2);
//! [22] ˢ��������Ƶ����ʹ�ü�����
NVSUNITEPLAY_API void nvs_reSetDDrawDevice(int nCameraID);
//! [23] �ָ�¼���ļ�
//NVSSTREAMPLAY_API HANDLE nvs_splitFile(HWND hWnd,char * sFileName);
NVSUNITEPLAY_API int nvs_splitFile(int nCameraID,char* sFileName,int nPriorTime);
//! [24] ���д洢����
/*!
\param nCameraID ����ͷID
\param sFileName �洢�ļ���
\return ���󲥷Ž�� 0-���󲥷ųɹ� -1��ý���ȡ������ʧ�� -2�ô����ѱ�ռ�� -3������ý��ʧ�� -4���ų����쳣 -5���ڵȴ�ͷ���� -6δע���������� -7δ���ñ�׼���ص�
*/
NVSUNITEPLAY_API int nvs_play4Storage(int nCameraID,char* sFileName,int nPriorTime);
//! [25] ���д洢����ֹͣ
/*!
\param nCameraID ����ͷID
*/
NVSUNITEPLAY_API bool nvs_stopPlay4Storage(int nCameraID);
//! [26] ��������ͷ��Ƶ����
/*!
\param nCameraID ��ͷID.
\param bOpenSound ����״̬ 0-�ر����� 1-������
\return ���������Ƿ�ɹ�
*/
NVSUNITEPLAY_API bool nvs_controlCameraSound(int nCameraID, bool bOpenSound);
//! [27]�ͻ���֪ͨ�ص����������
/*!
*/
NVSUNITEPLAY_API bool nvs_clientNotice();
//! [28]��ȡ��ý�幤��״̬
/*!
\param nCameraID (In)��ͷID
\param nCameraCount (In)��ͷ����
\param outSize (Out)��ý��״̬�������
\return StreamServerWorkState�ṹ
*/

NVSUNITEPLAY_API intptr_t nvs_getStreamServerWorkState(int nCameraID, int nCameraCount, int *outSize );
//! [29]��ȡ
/*!
*/
NVSUNITEPLAY_API char * nvs_getStreamServerIP( int nCameraID);
//! [30]�����Ƿ�Ϊ�����ͻ���
/*!
\param bIsExternal: ����ͻ�����������������Ϊtrue
*/
NVSUNITEPLAY_API void nvs_SetExternalClient(bool bIsExternal);
//! [31]д��־רΪLinux���ӵĽӿ�
/*!
\param
*/
NVSUNITEPLAY_API void nvs_writeLog(char* logMsg, int level);

//! [31]����ʵʱ��Ƶͷ�ص�����
NVSUNITEPLAY_API void nvs_SetVedioHeadStreamCallBack(LPVedioHeadStreamCBFun pFun);

//! [32]����ʵʱ��Ƶ���ص�����
NVSUNITEPLAY_API void nvs_SetVedioBodyStreamCallBack(LPVedioBodyStreamCBFun pFun);
//! [33]����Ԥ����������ַ���ͼ��ص�������
NVSUNITEPLAY_API void nvs_SetDrawFun(LPDrawCBFun pFun);

//! [33]���û�3�û��ص�����.
/*!
\param CallbackFun ��3�ص�����ָ��.
\return ��
*/
NVSUNITEPLAY_API void nvs_SetHsCallBack(HsUserCallBack CallbackFun);

//! [34]�ͻ��˴��û�ID�����ID��Linux
/*!
\param nUserID �û�ID
\param nOrgID  ����ID
\return ��
*/
NVSUNITEPLAY_API void nvs_SetUserIDandOrgID(int nUserID,int OrgID);


///////////////////////////////////////////////////
//! ���µĽӿ���ֱ�Ӵ�DVR�ϻ�ȡ��Ƶ (���ڻ���)

//! [1]����DVR.
/*!
\param sIP ��ַ.
\param nPort �˿�.
\param sUser �û���.
\param sPwd ����.
\return ���Ӿ��
*/
NVSUNITEPLAY_API intptr_t nvs_loginDVR(char* sIP, int nPort, char* sUser, char* sPwd);
//! [2]�ͷ�����.
/*!
\param identify ����ʱ�ľ��
\return ��
*/
NVSUNITEPLAY_API void nvs_logoutDVR(intptr_t identify);
//! [3]�ͻ�����ⲥ��.
/*!
\param identify ����ʱ�ľ��
\param nCameraID ����ͷID
\param hWnd ���ŵĴ��ھ��
\return ���Ž��
*/
NVSUNITEPLAY_API bool nvs_playVideoByDVR(intptr_t identify,int nCameraID,HWND hWnd);
//! [4]�ͻ��˹ر�ĳ���ڵĲ���
/*!
\param identify ����ʱ�ľ��
\param hWnd ���ŵĴ��ھ��.
\return �������
*/
NVSUNITEPLAY_API bool nvs_stopPlayVideoByDVR(intptr_t identify,HWND hWnd);
//! [5]�ͻ��˿�������ͷ(�������ٶ�)
/*!
\param identify ����ʱ�ľ��
\param nCameraID ������Ƶ�����ͷID
\param nCmd ���Ʊ�־
\param bControl ��ͣ
\nSpeed �����ٶ�ֵ
\return ���ؿ��Ƴɹ����
*/
NVSUNITEPLAY_API bool nvs_controlCameraSpeedByDVR(intptr_t identify,int nCameraID,int nCmd,bool bControl,int nSpeed,int nChannel);
//! [6]Ԥ��λ
/*!
\param identify ����ʱ�ľ��
\param nCameraID ������Ƶ�����ͷID
\param nCmd ��������.
\param nIndex Ԥ�õ�����
\return �������
*/
NVSUNITEPLAY_API bool nvs_presetPTZByDVR(intptr_t identify,int nCameraID, int nCmd, int nTransPTZIndex, int nChannel);
//! [7]��ȡ����������ľ�ͷ��Ϣ
/*!
\param identify ����ʱ�ľ��
\param nSize �ṹ���鳤��,(�ṹ����)

\�ṹ����Ϊ INFOCAMERA InfoCamera[]
\  typedef struct _infoCamera
\  {
\   	DWORD cameraId ;	  //��ͷID	
\    char cameraName[50];  //��ͷ����
\  }INFOCAMERA;

\return ���ؽṹ(һά)����ָ��
*/
NVSUNITEPLAY_API intptr_t nvs_getCameraInfo(intptr_t identify,int *nSize);
//! [8]���ò��Ŵ��ھ��
/*!
\param palyWindow���Ŵ�������
\param nMaxCount����������������16��
\return INFOCAMERA�ṹ����ָ��.(��nvssdkdef.h����)
*/
NVSUNITEPLAY_API int nvs_setPlayWindow(HWND palyWindow[], int nMaxCount);

//! [9]���û�������IP�Ͷ˿�
//����false,�޷�����HSServer��ȡ�ʺ�
NVSUNITEPLAY_API bool nvs_InitHSServer(char *strIP, int nPort);

//! ��ȡ�ô�����Ϣ
//nErrorCode; nvs_playVideo�ķ���ֵ(����0��1�Ĵ�����)��
//����: NULL=δ����
NVSUNITEPLAY_API const char* nvs_GetErrorMessage(int nErrorCode);

//V3.0
//! [26] ��׼��Ƶ��Ϣ�ص���ʼ��
/*!
\param pCB		�ص�����ָ��
\param pUser	�û�����ָ��
*/
NVSUNITEPLAY_API int nvs_stdVideoinit(pNVSSipCallback pCB, void *pUser);
//! [27] ��׼��Ƶ����ֹͣ
/*!
\param sCameraID ����ͷ����
\param hWnd		 ���ھ��
\param sIP		 ����IP
\param nPort	 ����˿�
\param sUser	 �û���
\param sPwd		 ����
\param sDllType	 �豸����
\param LPREALSTREAMCALLBACK lpCallBack ʵʱ���ص�����
\param void* pUser                     ����
*/
NVSUNITEPLAY_API int nvs_playStdVideo(char* sCameraID,HWND hWnd ,char* sIP, int nPort, char* sUser, char* sPwd ,char* sDllType, LPREALSTREAMCALLBACK lpCallBack, void* pUser);
//! [28] ��׼��Ƶ����ֹͣ
/*!
\param sCameraID ����ͷ����
\param hWnd		 ���ھ��
*/
NVSUNITEPLAY_API int nvs_stopStdVideo(char* sCameraID,HWND hWnd);
//! [29] ��Ƶ��ǽ
/*!
\param sCameraID ����ͷ����
\param sMonitorCode		 ������ID
\param sIP		 ����IP
\param nPort	 ����˿�
\param sUser	 �û���
\param sPwd		 ����
\param sDllType	 �豸����
*/
NVSUNITEPLAY_API int nvs_startPlayMonitor(char* sCameraCode, char *sMonitorCode,char* sIP, int nPort, char* sUser, char* sPwd ,char* sDllType);
//! [30] ֹͣ��Ƶ��ǽ
/*!
\param sMonitorCode		 ������ID
*/
NVSUNITEPLAY_API int nvs_stopPlayMonitor(char *sMonitorCode);
// ץͼ.
/*
\param identify ��ʼ�����صľ��.
\param sFilePath �ļ�·��.
\return ץͼ���
*/
NVSUNITEPLAY_API bool nvs_capturePictureByCode(char* sCameraCode, char* sFilePath);
// �����ؼ�֡
/*
\param sCameraID ����ͷ����
\param identify ��ʼ�����صľ��.
\return ��
*/
NVSUNITEPLAY_API void nvs_makeKey(char* sCameraCode);
// ����DVR.
/*
\param sIP ��ַ.
\param nPort �˿�.
\param sUser �û���.
\param sPwd ����.
\param nChannel ͨ��.
\param sType ������.
\return ���Ӿ��
\-1:����PlugIn.dllʧ��
\-2:��ȡDVRHandler����ʧ��
\-3:��¼DVRʧ��
*/
NVSUNITEPLAY_API intptr_t nvs_connectDVR(char* sIP, int nPort, char* sUser, char* sPwd, int nChannel ,char* sDllType);
// �ͷ�����.
/*
\param identify ����ʱ�ľ��.
\return ��
*/
NVSUNITEPLAY_API void nvs_disconnectDVR(intptr_t identify);
//ִ����̨����_��ͨ��
/*
\param sCameraID ����ͷ����
\param identify ����ʱ�ľ��
\param nCmd ��������.
\param bEnable ����.
\param nSpeed �ٶ�
\return �������
*/
NVSUNITEPLAY_API bool nvs_controlPTZSpeedWithChannel(string sCameraID,intptr_t identify,int nCmd, bool bEnable, int nSpeed, int nChannel);
//ִ��Ԥ��λ_��ͨ��
/*
\param sCameraID ����ͷ����
\param identify ����ʱ�ľ��.
\param nCmd ��������.
\param bEnable ����.
\return �������
*/
NVSUNITEPLAY_API bool nvs_presetPTZWithChannel(string sCameraID,intptr_t identify, int nCmd, int nIndex, int nChannel);
// ������Ƶ����.
/*
\param identify ��ʼ�����صľ��.
\param nBrightValue ����(ȡֵΪ1-10).
\param nContrastValue �Աȶ�(ȡֵΪ1-10).
\param nSaturationValue ���Ͷ�(ȡֵΪ1-10).
\param nHueValue ɫ��(ȡֵΪ1-10).
\return �������
*/
NVSUNITEPLAY_API bool nvs_setVideoEffectByCode(string sCameraID,intptr_t identify,DWORD dwBrightValue,DWORD dwContrastValue, DWORD dwSaturationValue,DWORD dwHueValue);
// ��ȡ��Ƶ����.
/*
\param sCameraID ����ͷ����
\param identify ��ʼ�����صľ��.
\param nBrightValue ����(ȡֵΪ1-10).
\param nContrastValue �Աȶ�(ȡֵΪ1-10).
\param nSaturationValue ���Ͷ�(ȡֵΪ1-10).
\param nHueValue ɫ��(ȡֵΪ1-10).
\return �������
*/
NVSUNITEPLAY_API bool nvs_getVideoEffectByCode(string sCameraID,intptr_t identify,DWORD *pBrightValue,DWORD *pContrastValue, DWORD *pSaturationValue,DWORD *pHueValue);
// ��ȡ�豸�ṹ.
/*
\param sCameraID ����ͷ����
\param sCameraID ����ͷ����
\param identify ��ʼ�����صľ��.
\param dwCommand ����
\param lChannel ͨ��.
\param lpOutBuffer ��һ���������ַ���ָ�루byStreamType@byResolution@byBitrateType@byPicQuality@dwVideoBitrate@dwVideoFrameRate$byStreamType@byResolution@byBitrateType@byPicQuality@dwVideoBitrate@dwVideoFrameRate����$��������¼��ṹ��Ϣ��������Ϣ�ṹ,��@������Ϣ���ڸ������� ��һ����¼��ṹ��Ϣ  �ڶ���������ṹ��Ϣ
\param dwOutBufferSize ��������С.
\param lpBytesReturned ����״̬.
\return ��ȡ���
*/
NVSUNITEPLAY_API bool nvs_getDVRConfig(string sCameraID,intptr_t identify, DWORD dwCommand, LONG lChannel,LPVOID lpOutBuffer,DWORD dwOutBufferSize,LPDWORD lpBytesReturned);

// �����豸�ṹ.
/*
\param sCameraID ����ͷ����
\param identify ��ʼ�����صľ��.
\param dwCommand ����
\param lChannel ͨ��.
\param lpInBuffer ��һ��������ַ���ָ�루byStreamType@byResolution@byBitrateType@byPicQuality@dwVideoBitrate@dwVideoFrameRate$byStreamType@byResolution@byBitrateType@byPicQuality@dwVideoBitrate@dwVideoFrameRate����$��������¼��ṹ��Ϣ��������Ϣ�ṹ,��@������Ϣ���ڸ������� ��һ����¼��ṹ��Ϣ  �ڶ���������ṹ��Ϣ
\param dwInBufferSize ��������С.
\return ���ý��
*/

NVSUNITEPLAY_API bool nvs_setDVRConfig(string sCameraID,intptr_t identify, DWORD dwCommand,LONG lChannel,LPVOID lpInBuffer,DWORD dwInBufferSize);
// ��ȡ¼���ļ��б�.
/*
\param sCameraID ����ͷ����
\param identify ����ʱ�ľ��.
\param nType ��¼����.
\param startTime ����ʱ��.
\param endTime �ر�ʱ��.
\param pRecordFile ��������ַ.
\param nMaxFileCount ��������С.
\return ��¼�ļ�����   0:�޼�¼  -1����֧�ָò������� -2:ʧ��  -3:��δ��¼DVR
*/
NVSUNITEPLAY_API int  nvs_getRecordFileEx(string sCameraID,intptr_t identify,RECORDQUERYTYPE nType,char* startTime,char* endTime,RECORDFILE pRecordFile[],int nMaxFileCount);
// ����¼���ļ�.
/*
\param identify ����ʱ�ľ��.
\param fileName �ļ���.  ==�ļ�����Ϊ�գ����ļ������أ��ļ���Ϊ��ʱ��ʱ�����ء�==
\param startTime ����ʱ��.
\param endTime �ر�ʱ��.
\param nFileSize �ļ���С.
\param saveFile �洢�ļ�·��.
\param lpCallBack �ص�����ָ��. ==�˻ص�������Ϊ֪ͨ�ͻ������ؽ��ȵ�ʱ�����ã�
\                                 ���ڲ������ַ�ʽ��ʹ�õ��ǿͻ���������ȡ�ķ�ʽ��
\                                 ��������ص�����ָ����Ϊ�ռ��ɡ�==
\param pUser ���ض���ָ��.
\return ���ص����ؾ��
\-1:��ȡ�����ļ����ʧ��
\-2:��δ��¼DVR
*/
NVSUNITEPLAY_API intptr_t nvs_downloadRecordFile(string sCameraID,intptr_t identify,char* fileName,char* startTime, char* endTime,int nFileSize,char* saveFile,LPDOWNLOADRECORDFILECALLBACK lpCallBack,void* pUser);
// ֹͣ����¼���ļ�.
/*
\param identify ����ʱ�ľ��.
\param ldownFileHandle �����ļ����
\return �������
*/
NVSUNITEPLAY_API bool nvs_stopDownloadRecordFile(intptr_t identify,intptr_t ldownFileHandle);
// ��ȡ���صĽ���.
/*
\param identify ��ʼ�����صľ��.
\param lFileHandle �ļ����.

\return ��-1��ʾʧ�ܣ�0-100:���صĽ��ȣ�100��ʾ���ؽ�����>100: ��������ԭ���DVRæ,�����쳣��ֹ
\         -2:�����ļ������Ч
*/
NVSUNITEPLAY_API int nvs_getDownloadPos(intptr_t identify,intptr_t lFileHandle);

// Զ�̻ط�.
/*
\param identify ����ʱ�ľ��.
\param hWnd ���ھ��.
\param fileName �ļ�����. ==�ļ�����Ϊ��ʱ���ļ������ţ�����ʱ�䲥��==
\param startTime ��ʼʱ��.
\param endTime ����ʱ��.
\param nFileSize �ļ���С.
\return �طž��
*/
NVSUNITEPLAY_API intptr_t nvs_replayRecordFile(string sCameraID,intptr_t identify,int hWnd,char* fileName,char* startTime, char* endTime,int nFileSize);
// Զ�̻طſ���.
/*
\param identify ����ʱ�ľ��.
\param lReplayHandle �ز����.
\param nCmd ����.
\param nInValue �������.
\param outValue �������.
\return �������
*/
NVSUNITEPLAY_API bool nvs_controlReplayRecordFile(intptr_t identify,intptr_t lReplayHandle,int nCmd,int nInValue,int* outValue);
// ֹͣԶ�̻ط�.
/*
\param identify ����ʱ�ľ��.
\param lReplayHandle �ز����.
\return �������
*/
NVSUNITEPLAY_API bool nvs_stopReplayRecordFile(intptr_t identify,intptr_t lReplayHandle);

// ��ʼ�����Խ�.
/*
\param identify ����ʱ�ľ��.
\return �������
*/
NVSUNITEPLAY_API bool nvs_startTalk(string sCameraID,intptr_t identify);
// ֹͣ�����Խ�.
/*
\param identify ����ʱ�ľ��.
\return �������
*/
NVSUNITEPLAY_API bool nvs_stopTalk(string sCameraID,intptr_t identify);
//20140819


// ��ȡӲ��¼�������״̬.
/*
\param identify ��ʼ�����صľ��.
\param dvrWorkState ���صù���״̬�ַ���������
HK$0$1024000!1024000!0^1024000!1024000!0$0!0!0!50!2!2250004@2250008^0!0!0!50!2!2250004@2250008$0@0@0@0@0@0@0$0@0@0@0@0@0@0$0
��$������ÿ�α�ʾ����˼
HK									����
0										�豸��״̬,0-����,1-CPUռ����̫��,����85%,2-Ӳ������
1024000!1024000!0^1024000!1024000!0	��ʾ������Ӳ��,ÿ��Ӳ�̲���(Ӳ�̵����� Ӳ�̵�ʣ��ռ� Ӳ�̵�״̬,��λ 1-���ߣ�2-������)
0!0!0!50!2!2250004@2250008^0!0!0!50!2!2250004@2250008
��ʾ������ͨ��,ÿ��ͨ����Ϣ����
ͨ���Ƿ���¼��,0-��¼��,1-¼��
���ӵ��ź�״̬,0-����,1-�źŶ�ʧ
ͨ��Ӳ��״̬,0-����,1-�쳣,����DSP����
ʵ������
�ͻ������ӵĸ���(���������2��)
�ͻ��˵�IP��ַ(�����������ͻ���,�� @ ������IP��ַ����)
0@0@0@0@0@0@0							�����˿ڵ�״̬,0-û�б���,1-�б���,�� @ ��ÿ���˿�����
0@0@0@0@0@0@0							��������˿ڵ�״̬,0-û�����,1-�б������,�� @ ��ÿ���˿�����
0										������ʾ״̬,0-����,1-������
\param arrayLen ����������.
\return ��ȡ���
*/
NVSUNITEPLAY_API bool nvs_getDVRWorkState(intptr_t identify,char dvrWorkState[],int arrayLen);

//��ȡ�������
/*
\return DVR������
*/
NVSUNITEPLAY_API DWORD nvs_getLastError(string sCameraID,intptr_t identify);

//Զ�̻ط�ʱץͼ
/*
\param identify ��ʼ�����صľ��
\param lReplayHandle ���ž��
\param pFileName ����ͼƬ���ļ���
\return �ɹ����
*/
NVSUNITEPLAY_API  bool nvs_playBackCaptureFile(intptr_t identify , intptr_t  lReplayHandle, char *pFileName);

// ����طŵ�����.
/*
\param identify ��ʼ�����صľ��.
\param lReplayHandle �ز����
\param sFileName �ļ���
\return ��ȡ���
*/
NVSUNITEPLAY_API bool nvs_playBackSaveData(intptr_t identify,intptr_t lReplayHandle,char *sFileName);
// ֹͣ����طŵ�����.
/*
\param identify ��ʼ�����صľ��.
\param lReplayHandle �ز����
\return ��ȡ���
*/
NVSUNITEPLAY_API bool nvs_stopPlayBackSave(intptr_t identify,intptr_t lReplayHandle);

NVSUNITEPLAY_API bool nvs_startRecordByCode(string sCameraID,intptr_t identify, char* saveFile);

NVSUNITEPLAY_API bool nvs_stopRecordByCode(string sCameraID,intptr_t identify);

//�ֲ��Ŵ�(��Ӧ�����XY_SetCropArea()�ӿ�)
/*
Param:  identify: ���
bFlag: ������
x1, y1, x2, y2�ֱ�Ϊ����ڲ��Ŵ����ϵ����ϼ����µ�����, ȫ��Ϊ0ʱ��ʾֹͣ�ֲ��Ŵ�.
return:true �ɹ�, false ʧ��*/
NVSUNITEPLAY_API bool nvs_SetCropArea(string sCameraID,intptr_t identify, bool bFlag = false, int x1 = 0, int y1 = 0, int x2 = 0, int y2 = 0);

//��Ƶ�������ܵ���(����nCmd����, �ֱ��Ӧ�����XY_SetClearFogParam(), XY_OpenOrCloseClearFog(), XY_OpenOrCloseInvert(), XY_OpenOrCloseSharpen()�ӿ�)
/*
Param:  identify: ���
nCmd: ���ܵ��ڵ�����, 1Ϊȥ��, 2Ϊ��ɫ, 3Ϊ��, 4Ϊ���ȵ���
bFlag: trueΪִ�����ܵ���, falseΪȡ��
x1, y1: ȥ��ʱ��ʾ��ʼ������, �߶ȵ���ʱΪ����
x2, y2: ���ȵ��ڱ�ʾ�ս������.
return: 0�ɹ�, <0ʧ��*/
NVSUNITEPLAY_API bool nvs_SetDecodeParam(string sCameraID,intptr_t identify, int nCmd, bool bFlag = false, int x1 = 0, int y1 = 0, int x2 = 0, int y2 = 0);

/****���������ӿ���Ϊ��ʵ���ڿͻ��˲���ʵʱ��Ƶʱ��15����ٻط�****/

//����ʵʱ����ʱ���������ݵ�ʱ��, Ĭ��15��
/*
Param:  identify: ���
nSaveTime: �����ʱ��(��λ:�룩
return: true�ɹ�, falseʧ��*/
NVSUNITEPLAY_API bool nvs_SetStreamSaveTime(string sCameraID,intptr_t identify, int nSaveTime = 15);

//�طű������Ƶ��
/*
Param:  identify: ���;
hWnd: ���ھ��
return: true�ɹ�, falseʧ��*/
NVSUNITEPLAY_API bool nvs_PlayBackSaveStream(string sCameraID,intptr_t identify, HWND hWnd);

//ֹͣ�طű������Ƶ��
/*
Param:  identify: ���
return: true�ɹ�, falseʧ��*/
NVSUNITEPLAY_API bool nvs_StopPlayBackSaveStream(string sCameraID,intptr_t identify);
//����ͼ�����Ⱦģʽ��Ĭ��ΪD3D��Ⱦ
/*
Param:identify: ���;
OutParam:��
����ֵ���ɹ�����true�����򷵻�false
*/
NVSUNITEPLAY_API bool nvs_SetRenderMode(string sCameraID,intptr_t identify, int nMode = RENDER_BY_D3D);

//����֡�Ŷ�λ,��λ��nFrameNum����Ĺؼ�֡����ǰ���ң�
/*
Param:identify: �����nFrameNum ֡��
OutParam:��
����ֵ���ɹ�����true�����򷵻�false
*/
NVSUNITEPLAY_API bool nvs_SetPosByFrameNum(string sCameraID,intptr_t identify,DWORD nFrameNum);

//��ȡbeginTime��endTime֮���¼�񣬱�����filename��ָ����·����beginTime��endTimeΪ�뼶ʱ��
/*
Param:identify: ���;
beginFrame����ȡ��ʼ��ʱ�䣻
endFrame����ȡ������ʱ�䣻
filename��¼�񱣴�ľ���·��
OutParam:��
����ֵ���ɹ�����true�����򷵻�false
*/
NVSUNITEPLAY_API bool nvs_GetVideoCut(string sCameraID,intptr_t identify, DWORD beginFrame, DWORD endFrame, LPSTR filename);

//��ֹ�ļ�����
/*
Param:identify: ���;
OutParam:��
����ֵ���ɹ�����true�����򷵻�false
*/
NVSUNITEPLAY_API bool nvs_StopCutVideo(string sCameraID,intptr_t identify);

//�����ļ������ص�
/*
Param:identify: ���;
OutParam:��
����ֵ���ɹ�����true�����򷵻�false
*/
NVSUNITEPLAY_API bool nvs_SetFileEndCallback(string sCameraID,intptr_t identify, void *pUser, pFileOverCB pCallBack);// ֪ͨʹ�ã�Ϊ��ȷ����Ƶ�ļ��Ѿ�������ϣ���Ϊ������Ƶ�ļ��������ʱ����ǰ֡��������֡����

//��ȡý����Ϣ
/*
Param:identify: �����mInf������ȡý����Ϣ�Ľṹָ��
OutParam:��
����ֵ���ɹ�����true�����򷵻�false
*/
NVSUNITEPLAY_API bool nvs_GetMediaInfo(string sCameraID,intptr_t identify,MediaInf &mInf);
//��Ƶ�����ȡ���ò���
/*
Param:identify: ����� 
nCmd: ���ܵ��ڵ�����, 1Ϊȥ��, 2Ϊ��ɫ, 3Ϊ��, 4Ϊ���ȵ���
OutParam:
��nCmdΪ1ȥ�����ʱ:
x1				��ʼ��X����
y1				��ʼ��Y����
x2				������X����
y2				������Y����
��nCmdΪ4���ȵ���ʱ:
x1 Ϊgray1	���ȵ��ڲ����ĻҶ�ֵ1
y1 Ϊgray2	���ȵ��ڲ����ĻҶ�ֵ2
return: 0�ɹ�, <0ʧ��*/
NVSUNITEPLAY_API bool nvs_GetDecodeParam(string sCameraID,intptr_t identify, int nCmd, int &x1, int &y1, int &x2, int &y2);

// ��ʼ���Ų��һ�ȡ��׼��ʽ��Ƶ��.
/*
\param identify ��ʼ�����صľ��.
\param hWnd ���Ŵ��ھ��.
\return �������
*/
NVSUNITEPLAY_API bool nvs_startPlayer4Standard(string sCameraID,intptr_t identify,HWND hWnd,LPDecCBFun lpDecCBFun, int nCameraID);

//����YUV�ص�����(��Ӧ�����XY_SetStreamCallBackForVideo()�ӿ�)
/*
Param:  identify: ���
pCallBack: �ص�����, ���������.
return:true �ɹ�, false ʧ��*/
NVSUNITEPLAY_API bool nvs_SetYUVCallBack(string sCameraID,intptr_t identify, LPYUVCALLBACK pCallBack);

//������ƵԴ��ȡ��ʷ��Ƶ����Ϣ  ������ƵԴ��ȡ��ʷ��Ƶ����Ϣ, ���ҵ�����Ϣ��pSipMsgCallBack�з���
/*                
Parameter:  nType                             ��ʷ��Ƶ����
Parameter:  startTime                      ��Ƶ��ʼʱ��
Parameter:  endTime                        ��Ƶ����ʱ��
Parameter:  nRecordSource                     ��ƵԴ1:�豸2��ƽ̨
Returns:true �ɹ�, false ʧ��
*/
NVSUNITEPLAY_API bool nvs_getRecordFileBySource(string sCameraID,intptr_t identify,int nType, char* startTime, char* endTime, int nRecordSource);



//************************************
// Method:    downloadRecordFileBySource                 ������ʷ��Ƶ
// Returns:   intptr_t                                       С�ڱ�ʾʧ������Ϊ���ر�ʶ����ֹͣ����
// Parameter: char * fileName                            ��Ƶ��
// Parameter: char * startTime                           ��Ƶ��ʼʱ��
// Parameter: char * endTime                             ��Ƶ����ʱ��
// Parameter: int nFileSize                              �ļ���С��Ҳ�����ڴ���һЩ��������Ĳ�����
// Parameter: char * saveFile                            �����ļ�·��
// Parameter: LPDOWNLOADRECORDFILECALLBACK lpCallBack    ���ؽ��Ȼص�
// Parameter: void * pUser                               �û�ָ�룬�������ֵ������ĸ����������
// Parameter: int nRecordSource							 ��ƵԴ:�豸��ƽ̨
//************************************
NVSUNITEPLAY_API intptr_t nvs_downloadRecordFileBySource(string sCameraID,intptr_t identify,char* fileName,char* startTime, char* endTime,int nFileSize,char* saveFile,LPDOWNLOADRECORDFILECALLBACK lpCallBack,void* pUser, int nRecordSource);

//V3.0
#endif