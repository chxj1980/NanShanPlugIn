
#ifndef _NVSSTREAMPLAYSDK_H
#define _NVSSTREAMPLAYSDK_H

#if defined NVSSTREAMPLAYLIB_EXPORTS
#define NVSSTREAMPLAY_API extern "C" __declspec(dllexport)
#else
#define NVSSTREAMPLAY_API extern "C" __declspec(dllimport)
#endif
#ifndef CALLBACK
#define CALLBACK   __stdcall
#endif // !CALLBACK

//! ������Ƶ���Ŵ��󷵻���
#define XY_REQ_PLAY_SUCCESS 		 1  //����ľ�ͷ�Ѵ��ڲ��Ŷ���ֱ�ӵ���Plugin���ųɹ�
#define XY_REQ_SUCCESS 				 0  //����ý��������Ƶ���ݳɹ�
#define XY_REQ_FAIL_GET_ADAPTER 	-1  //��ȡ��ý��������ʧ��
#define XY_REQ_USED_WINDOW 			-2  //���봰���ѱ�ռ�ã�����ʧ��
#define XY_REQ_UNCONTROL_DVR 		-3  //��ǰ��ý����񲻿������Ӳ��¼���
#define XY_REQ_NOT_FIND_CHANNEL		-4  //��ǰ��ý�����������Ӳ��¼�����û���ҵ���Ӧͨ��
#define XY_REQ_OVER_MAXLINK			-5  //��ý������ؿͻ���������
#define XY_REQ_STREAM_NORIGHT 		-6  //��ý�����û����Ȩ
#define XY_REQ_DVR_NOT_CONNECT		-7  //��ý�������Ӳ��¼�����û���Ӻ�
#define XY_REQ_ERR_VIDEOPROCESS		-8  //��Ƶ���Ŷ�������ý��������Ƶ�쳣
#define XY_REQ_NOT_RECEIVE_DATA		-9  //������Ƶ�ɹ���δ�յ�ͷ����
#define XY_REQ_NOT_WNDINUSE         -10 //���Ŵ����ѱ�ʹ��

//����6��ͬΪ�ص����Ž����
#define XY_PLAY_SUCCESS		    	 0	//���ųɹ�
#define XY_PLAY_FAIL_GET_PORT    	-10	//��ȡ���Ŷ˿�ʧ��
#define XY_PLAY_NULL_HEADDATA		-11 //ͷ����Ϊ��
#define XY_PLAY_FAIL_PLUGIN_INIT	-12 //��ʼ��PlugInʧ��
#define XY_PLAY_FAIL_PLUGIN_PLAY	-13 //����PlugIn������Ƶʧ��
#define XY_FAIL_DISCONNECT_INDEX	-14 //��������������Ͽ���
#define XY_FAIL_DISCONNECT_STREAM	-15 //����ý���������ӶϿ���

#define XY_REQ_STREAM_UNREGISTER	-16 //δ�������������ý��ע���ע��ʧ��
#define XY_REQ_FAIL_GET_PLAYOBJ 	-17 //��ȡ���Ŷ���ʧ��
#define XY_REQ_ERROR_GET_PLAYOBJ	-18 //NVSStreamManager::playVideo4ICE�����쳣
#define XY_REQ_FAIL_ASKFOR_STREAM   -19 //��ʾ��ý�����ʧ��
#define XY_REQ_INDEX_UNREGISTER	    -20 //δ����������ע�� 
#define XY_REQ_UNSET_CALLBACK	    -21 //�ص�����δ����
#define XY_REQ_UNSET_STDCALLBACK	-22 //��׼���ص�����δ����
#define XY_PLAY_H3C_FAIL			-23 //���Ż�����ͷʧ��

//2011-7-27 ����
#define XY_PLAY_FAIL_SETBODYCALLBACK -24 //������ΪNULLʱ������������ն���ʧ��

//����3��ΪӲ��ר��
#define XY_PLAY_ERR_CARD_OPENSTREAM -26 //�򿪽��뿨�����Ŷ˿�ʧ��
#define XY_PLAY_FAIL_CARD_PLAY		-27 //Ӳ�ⲥ��ʧ��
#define XY_REQ_USED_DECODE_CHANNEL  -28 //�������ͨ���ѱ�ռ�ã�����ʧ��

//���д洢
#define XY_RECORD_WRITEHEAD_FAILURE	-29 //���д洢¼��д��ͷ����ʧ��


//��������
#define XY_REQ_RE_PLAY				   -40 //ǰ���豸δ�����������������������󲥷�
#define XY_REQ_STREAM_NOT_FIND_CHANNEL -41 //�Ҳ���ͨ����DVR��Ϣ
#define XY_REQ_STREAM_NOT_REGISTER     -42 //�ͻ���δ����ý��ע��,��ȴ����������������ͻ���
#define XY_REQ_STREAM_QUERYVISFAIL     -43 //����VISʧ��
#define XY_REQ_STREAM_SOURCEFULL       -44 //��ý������Դ����
#define XY_REQ_STREAM_SINKFULL         -45 //��ý���������

#define XY_PLAY_NOT_RECEIVE_CLOSE	   -46 //�ͻ���δ����ý��ע��,��ȴ����������������ͻ���


#define XY_REQ_INDEX_NOT_FIND_DVRINFO -180 //��ͷ����DVR������,������ͷ��Ϣʧ��,��˶�	//2011-7-28 �޸�
#define XY_REQ_INDEX_NOT_FIND_STREAM  -181 //û���ҵ�������ý��
#define XY_REQ_INDEX_MAX_LOAD		  -182 //��Ӧ��ý���ѳ����ɣ���������
#define XY_REQ_INDEX_NOT_FIND_GRADE	  -183 //û�п������߼�����ý��
#define XY_REQ_INDEX_NOT_QUERYVIS	  -184 //�����л�VISʧ��
#define XY_REQ_INDEX_QUERY_TIMEOUT    -185 //����ͷ������ý���ַ��ʱ

//2013-2-21 ��Ե��ýӿ������ӿ��쳣�����ӵĺ�
#define XY_EXP_INDEX_GETSTREAMINFO	  -186 //����ͷ������ý���ַ�쳣
#define XY_EXP_INDEX_GETDVRINFO		  -187 //����ͷ����DVR��ַ�쳣


//2011-7-28 ��Ի�����Ƶ�궨��
#define XY_REQ_INDEX_NOT_FIND_DVRPARA -190 //��ͷ����DVR����,����ȡ�豸��Ϣʧ��
#define XY_REQ_INDEX_FALSE_GETCHACODE -191 //��ȡ��ͷͳһ�����쳣,ȡ������
#define XY_REQ_INDEX_FALSE_GETHSUSER  -192 //��ȡ�����û���Ϣʧ��

#define XY_UNKNOWN -999    //δ����

//2012-10-12 ������
#define  ERROR_SOURCEPARA		 -70
#define  ERROR_SOURCERETURN		 -71
#define  ERROR_SOURCEFIND		 -72
#define  ERROR_SOURCEEXCEPTION	 -73

/*! \file NVSStreamPlaySDK.h
*   \brief �û���Ƶ�ͻ�������������ý���ͨѶ���ſ��ƿ�
*   \author �ﾸ��
*   \version 1.0
*   \date    2008-03-20
*/

/*! ����ICEģʽ����Ϊ0 */
#define BY_ICE		0
/*! ����Socketģʽ����Ϊ1 */
#define BY_SOCKET	1

/*! ��ⲥ�Ž���ص�ָ�� */ 
//typedef void (CALLBACK * PlayResult)(char Des[256]);
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

/*! ��Ƶ���л�֪ͨ�ص�ָ��
\param nCameraID;     //��ͷID
*/
typedef void (CALLBACK *NoticeSwitchedCallBack)(int nUserID,int nPriorCameraID,int nCameraID,char* pDesc);


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
typedef void (CALLBACK *LPVedioBodyStreamCBFun)(BYTE * pBuf, long nSizeint, int  nCameraID);

/*! Ԥ����������ַ���ͼ��
\param lRealHandle NET_DVR_RealPlay()��NET_DVR_RealPlay_V30()�ķ���ֵ 
\param hDc ��ͼ���
\param nCameraID ��ͷID
*/
typedef void (CALLBACK *LPDrawCBFun)(intptr_t lRealHandle, DWORD hDc, int nCameraID);

//! [01] ��ʼ��ҵ���߼�����ģ��
/*!
\param pAddress ���������ַ.
\param nPort ��������˿�.
\param type ICEͨѶ��ʽ.
\param nRight Ȩ��ֵ.
\return ��ʼ���ɹ����
*/
NVSSTREAMPLAY_API bool nvs_initEnviroment(const char* pAddress,unsigned short nPort,int nRight, char type = BY_ICE);
//! [02] ����ҵ���߼����Ļ���.
/*!
\return ��
*/
NVSSTREAMPLAY_API void nvs_cleanEnviroment();
//! [03] �ͻ���ע������������.
/*!
\return ע����
*/
NVSSTREAMPLAY_API bool nvs_registerOnIndex();
/*! ���ûص����� */
NVSSTREAMPLAY_API void nvs_setDecordCardCallBack(PlayResultByDecordCard pFun);
NVSSTREAMPLAY_API void nvs_setRealPlayCallBack(RealPlayCallBack pFun);
NVSSTREAMPLAY_API void nvs_setRealDecodeCallBack(LPDecCBFun pFun);
NVSSTREAMPLAY_API void nvs_setIndexNoticeCallBack(IndexNoticeCallBack pFun);
NVSSTREAMPLAY_API void nvs_setDVRNoticeCallBack(DVRNoticeCallBack pFun);


//! [07] �ͻ�����ⲥ��
/*!
\param nCameraID ����ͷID
\param hWnd ���ŵĴ��ھ��
\param bUseDecode ��ȡ��׼����ʶ
\return ���󲥷Ž�� 0-���󲥷ųɹ� -1��ý���ȡ������ʧ�� -2�ô����ѱ�ռ�� -3������ý��ʧ�� -4���ų����쳣 -5���ڵȴ�ͷ���� -6δע���������� -7δ���ñ�׼���ص�
*/
NVSSTREAMPLAY_API int nvs_playVideo(int nCameraID,HWND hWnd, bool bUseDecode/*��ȡ��׼����ʶ*/);


NVSSTREAMPLAY_API int nvs_playVideo2(int nCameraID,HWND hWnd, bool bUseDecode/*��ȡ��׼����ʶ*/, bool bIsExternalDvr);


NVSSTREAMPLAY_API int xs_playVideo(int nCameraID,HWND hWnd, bool bUseDecode, bool bIsExternalDvr,const char* pCameraID,void *pUsr);
//! [08] �ͻ��˹ر�ĳ���ڵĲ���
/*!
\param hWnd ���ŵĴ��ھ��
\return ��
*/
NVSSTREAMPLAY_API bool nvs_stopPlayVideo(HWND hWnd, int nCardIndex, int nCameraID);

NVSSTREAMPLAY_API bool nvs_stopPlayByCameraID(int nCameraID);

NVSSTREAMPLAY_API int xs_stopPlayVideo(HWND hWnd,int nCameraID,const char* pCameraID);

NVSSTREAMPLAY_API int xs_stopPlayByCameraID(int nCameraID,const char* pCameraID);
//! [09] �ͻ��˹ر����д��ڲ���
/*!
\return ��
*/
NVSSTREAMPLAY_API void nvs_stopAll();
//! [11] �ͻ��˿�������ͷ(�������ٶ�)
/*!
\param nCameraID ������Ƶ�����ͷID
\param nCmd ���Ʊ�־
\param bControl ��ͣ
\return ���ؿ��Ƴɹ����
\nSpeed �����ٶ�ֵ1-15����
*/
NVSSTREAMPLAY_API bool nvs_controlCameraSpeed(int nCameraID,int nCmd,bool bControl,int nSpeed);
//! [12] �Զ�ע��PTZ����Ȩ��
NVSSTREAMPLAY_API bool nvs_cancelControlCamera(HWND hWnd,int nCameraID);

//! [13] ץͼ
NVSSTREAMPLAY_API bool nvs_capturePictureEx(int nCameraID, char* pFileName);
//! [14] Ԥ��λ
NVSSTREAMPLAY_API bool nvs_TransPTZ(int nCameraID, int nCmd, int nTransPTZIndex);
//! [15] ��ȡͨ������������������������Ƶ������
NVSSTREAMPLAY_API bool nvs_getCompress(int nCameraID, char **lpOutBuffer);
//! [16] ����ͨ������
NVSSTREAMPLAY_API bool nvs_setCompress(int nCameraID, char* pCompressInfo);
//! [17] ��ȡ��Ƶ���������ȡ�ɫ�ȡ����Ͷȵȣ�
NVSSTREAMPLAY_API bool nvs_getVideoEffect(int nCameraID, int* pBrightValue,int* pContrastValue, int* pSaturationValue,int* pHueValue);
//! [18] ������Ƶ����
NVSSTREAMPLAY_API bool nvs_setVideoEffect(int nCameraID, DWORD dwBrightValue,DWORD dwContrastValue, DWORD dwSaturationValue,DWORD dwHueValue);
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
NVSSTREAMPLAY_API int  nvs_startRecord(int nCameraID, char* pFileName);
//! [20] ֹͣ����¼��
NVSSTREAMPLAY_API bool nvs_stopRecord(int nCameraID);
//! [21] ʹ��͸��ͨ��
NVSSTREAMPLAY_API bool nvs_serialSend(int nCameraID, char* cmd1, DWORD nLen1, char* cmd2, DWORD nLen2);
//! [22] ˢ��������Ƶ����ʹ�ü�����
NVSSTREAMPLAY_API void nvs_reSetDDrawDevice(int nCameraID);
//! [23] �ָ�¼���ļ�
//NVSSTREAMPLAY_API HANDLE nvs_splitFile(HWND hWnd,char * sFileName);
NVSSTREAMPLAY_API int nvs_splitFile(int nCameraID, char* sFileName, int nPriorTime,  bool bIsExternalDvr= false);
//! [26] ��������ͷ��Ƶ����
/*!
\param nCameraID ��ͷID.
\param bOpenSound ����״̬ 0-�ر����� 1-������
\return ���������Ƿ�ɹ�
*/
NVSSTREAMPLAY_API bool nvs_controlCameraSound(int nCameraID, bool bOpenSound);
//! [27]�ͻ���֪ͨ�ص����������
/*!
*/
NVSSTREAMPLAY_API bool nvs_clientNotice();
//! [28]��ȡ��ý�幤��״̬
/*!
\param CameraIDArray (In)��Ҫ��ȡ��ͷ������ý�幤��״̬�ľ�ͷ����
\param nCameraCount (In)��ͷ����
\param outSize (Out)��ý��״̬�������
\return StreamServerWorkState�ṹ
*/

NVSSTREAMPLAY_API intptr_t nvs_getStreamServerWorkState(int nCameraID, int nCameraCount, int *outSize );
//! [29]��ȡ��ͷ��Ӧ����ý���IP��ַ
/*!
*/
NVSSTREAMPLAY_API char * nvs_getStreamServerIP( int nCameraID);
//! [30]�����Ƿ�Ϊ�����ͻ���
/*!
\param bIsExternal: ����ͻ�����������������Ϊtrue
*/
NVSSTREAMPLAY_API void nvs_SetExternalClient(bool bIsExternal);

//! [31]����ʵʱ��Ƶͷ�ص�����
NVSSTREAMPLAY_API void nvs_SetVedioHeadStreamCallBack(LPVedioHeadStreamCBFun pFun);
//! [32]����ʵʱ��Ƶ���ص�����
NVSSTREAMPLAY_API void nvs_SetVedioBodyStreamCallBack(LPVedioBodyStreamCBFun pFun);
//! [33]����Ԥ����������ַ���ͼ��ص�������
NVSSTREAMPLAY_API void nvs_SetDrawFun(LPDrawCBFun pFun);
////////////////////////////////////////////////////
//! ���µĽӿ���ֱ�Ӵ�DVR�ϻ�ȡ��Ƶ (���ڻ���)

//! [1]����DVR.
/*!
\param sIP ��ַ.
\param nPort �˿�.
\param sUser �û���.
\param sPwd ����.
\return ���Ӿ��
*/
NVSSTREAMPLAY_API intptr_t nvs_loginDVR(char* sIP, int nPort, char* sUser, char* sPwd);
//! [2]�ͷ�����.
/*!
\param identify ����ʱ�ľ��
\return ��
*/
NVSSTREAMPLAY_API void nvs_logoutDVR(intptr_t identify);
//! [3]�ͻ�����ⲥ��.
/*!
\param identify ����ʱ�ľ��
\param nCameraID ����ͷID
\param hWnd ���ŵĴ��ھ��
\return ���Ž��
*/
NVSSTREAMPLAY_API bool nvs_playVideoByDVR(intptr_t identify,int nCameraID,HWND hWnd);
//! [4]�ͻ��˹ر�ĳ���ڵĲ���
/*!
\param identify ����ʱ�ľ��
\param hWnd ���ŵĴ��ھ��.
\return �������
*/
NVSSTREAMPLAY_API bool nvs_stopPlayVideoByDVR(intptr_t identify,HWND hWnd);
//! [5]�ͻ��˿�������ͷ(�������ٶ�)
/*!
\param identify ����ʱ�ľ��
\param nCameraID ������Ƶ�����ͷID
\param nCmd ���Ʊ�־
\param bControl ��ͣ
\nSpeed �����ٶ�ֵ
\return ���ؿ��Ƴɹ����
*/
NVSSTREAMPLAY_API bool nvs_controlCameraSpeedByDVR(intptr_t identify,int nCameraID,int nCmd,bool bControl,int nSpeed,int nChannel);
//! [6]Ԥ��λ
/*!
\param identify ����ʱ�ľ��
\param nCameraID ������Ƶ�����ͷID
\param nCmd ��������.
\param nIndex Ԥ�õ�����
\return �������
*/
NVSSTREAMPLAY_API bool nvs_presetPTZByDVR(intptr_t identify,int nCameraID, int nCmd, int nTransPTZIndex, int nChannel);
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
NVSSTREAMPLAY_API intptr_t nvs_getCameraInfo(intptr_t identify,int *nSize);
//! [8]���ò��Ŵ��ھ��
/*!
\param palyWindow���Ŵ�������
\param nMaxCount����������������16��
\return INFOCAMERA�ṹ����ָ��.(��nvssdkdef.h����)
*/
NVSSTREAMPLAY_API int nvs_setPlayWindow(HWND palyWindow[], int nMaxCount);

//! [9]���û�������IP�Ͷ˿�
//����false,�޷�����HSServer��ȡ�ʺ�
NVSSTREAMPLAY_API bool nvs_InitHSServer(char *strIP, int nPort);

;//! ��ȡ�ô�����Ϣ
//nErrorCode; nvs_playVideo�ķ���ֵ(����0��1�Ĵ�����)��
//����: NULL=δ����
NVSSTREAMPLAY_API const char* nvs_GetErrorMessage(int nErrorCode);

//���ܷ�����ѡ��
//! [] ����֪ͨ�ص�����
/*!
\param pFun �ص�����ָ��
*/
NVSSTREAMPLAY_API void nvs_setNoticeSwitchedCallBack(NoticeSwitchedCallBack pFun);
//
//! [04] ���ò���ģʽ.
/*!
\param nPlayModel /0-��ⲥ�� 1-Ӳ�ⲥ�� 2-���д洢.
\return ��
*/
NVSSTREAMPLAY_API void nvs_setPlayModel(int nPlayModel = 0);
//! [05] �ͻ���Ӳ�ⲥ��
/*!
\param nCameraID ������Ƶ�����ͷID
\param nCardIndex Ӳ�ⲥ�ŵĿ����
\return ���󲥷Ž�� 0-���ųɹ� -1��ý���ȡ������ʧ�� -2�ô����ѱ�ռ�� -3������ý��ʧ�� -4���ų����쳣 -5���ڵȴ�ͷ����
*/
NVSSTREAMPLAY_API int nvs_playVideoByDecordCard(int nCameraID,int nCardIndex, HANDLE* hStreamPlayHandle, bool bIsExternalDvr = false);

//! [24] ���д洢����
/*!
\param nCameraID ����ͷID
\param sFileName �洢�ļ���
\return ���󲥷Ž�� 0-���󲥷ųɹ� -1��ý���ȡ������ʧ�� -2�ô����ѱ�ռ�� -3������ý��ʧ�� -4���ų����쳣 -5���ڵȴ�ͷ���� -6δע���������� -7δ���ñ�׼���ص�
*/
NVSSTREAMPLAY_API int nvs_play4Storage(int nCameraID,char* sFileName,int nPriorTime, bool bIsExternalDvr = false);
//! [25] ���д洢����ֹͣ
/*!
\param nCameraID ����ͷID
*/
NVSSTREAMPLAY_API bool nvs_stopPlay4Storage(int nCameraID);
;//! ����������־
//bIsNeedRePlay; ������־
//����: 
NVSSTREAMPLAY_API void nvs_SetRePlayFlag(bool bIsNeedRePlay);


NVSSTREAMPLAY_API int nvs_GetRecordFile(intptr_t lHandle,RECORDQUERYTYPE nType,char* startTime,char* endTime,RECORDFILE pRecordFile[],int nMaxFileCount);

NVSSTREAMPLAY_API intptr_t nvs_ReplayRecordFile(intptr_t lHandle,HWND hWnd,char* fileName,char* startTime, char* endTime,int nFileSize);

NVSSTREAMPLAY_API int nvs_ControlReplayRecordFile(intptr_t lHandle,intptr_t lRePlayhandle,int nCmd,int nInValue);

NVSSTREAMPLAY_API bool nvs_StopReplayRecordFile(intptr_t lHandle,intptr_t lRePlayhandle);

NVSSTREAMPLAY_API intptr_t nvs_DownloadRecordFile(intptr_t lHandle,char* fileName,char* startTime, char* endTime,int nFileSize,char* saveFile);

NVSSTREAMPLAY_API int nvs_GetDownloadPos(intptr_t lHandle,intptr_t ldownloadHandle);
NVSSTREAMPLAY_API bool nvs_StopDownloadRecordFile(intptr_t lHandle,intptr_t ldownloadHandle);

NVSSTREAMPLAY_API intptr_t nvs_CaptureStream(int CameraID, LPCAPTURESTREAMCALLBACK pCaptuerStreamFuc, void* pUser, int nGetVideoType = 0);

NVSSTREAMPLAY_API bool nvs_StopCaptureStream(intptr_t lHandle);

NVSSTREAMPLAY_API bool nvs_GetDecodeType(int nCameraID,char*sType);
NVSSTREAMPLAY_API intptr_t nvs_ConnectDVR(int nCameraID);
NVSSTREAMPLAY_API void nvs_disConnectDVR(intptr_t lHandle);



#endif
