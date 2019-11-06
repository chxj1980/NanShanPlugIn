#pragma once

class CStreamProcess;
class NVSHeartThread;
class NVSErrorManage;
class NVSStampCheck;
class CHSVideoProcess;

typedef vector <STREAMSERVERWORKSTATE> STREAMSERVERWORKSTATELISTTYPE;

const int MAX_PLAYNUM = 64;

struct ErrorMsg
{
	int nErrorCode;
	string sErrorMsg; 
};

typedef vector<ErrorMsg> ErrorMsgVectorType;
typedef ErrorMsgVectorType::iterator ErrorMsgItType;


class NVSCoreBiz
{
public:
	NVSCoreBiz(void);
	virtual ~NVSCoreBiz(void);
public:	
	CIniFileParam m_IniFileParam;
	ErrorMsgVectorType m_vErrorMsg;
	void initErrorMsg();
	const char *c_getErrorMsg(int nErrorCode);
public:
	bool c_initEnviroment(const char* pAddress,unsigned short nPort,int nRight, char type = BY_ICE);
	void c_cleanEnviroment();
	bool c_registerOnIndex();

	int  c_playVideoEx(int nCameraID, HWND hWnd, bool bUseDecode, bool bIsExternalDvr,string &sCameraID,void *pUsr);	
	int  c_stopPlayVideoEx(HWND hWnd, int nCameraID,string &sCameraID);
	bool c_stopPlayByCameraID(int nCameraID);//bool ���ɿ����޸�
	void c_stopAll();
	void updateCameraID(int nPriorID,int nSwitchID);
	bool c_clientNotice();

//�ɷ����Ľӿ�
	int  c_playVideo(int nCameraID, HWND hWnd, bool bUseDecode, bool bIsExternalDvr);
	bool c_stopPlayVideo(HWND hWnd, int nCardIndex, int nCameraID);
	void c_setPlayModel(int nPlayModel = 0);
	int  c_startRecord(int nCameraID, char* pFileName);//����¼��
	bool c_stopRecord(int nCameraID);
	int  c_splitFile(int nCameraID,char * sFileName,int nPriorTime, bool bIsExternalDvr);//�ָ�¼��
	//LONG c_getStreamServerWorkState(REQUESTSTREAMSTATE CameraIDArray[], int nCameraCount, int *outSize );

//��Ҫ��ý��֧�ֵĽӿ�
	bool c_controlCameraSpeed(int nCameraID,int nCmd,bool bControl,int nSpeed);
	bool c_cancelControlCamera(HWND hWnd,int nCameraID);
	//! Ԥ��λ
	bool c_TransPTZ(int nCameraID, int nCmd, int nTransPTZIndex);
	//ͨ������������������������Ƶ������
	bool c_getCompress(int nCameraID, char **lpOutBuffer);
	bool c_setCompress(int nCameraID, char* pCompressInfo);
	//��Ƶ���������ȡ�ɫ�ȡ����Ͷȵȣ�
	bool c_getVideoEffect(int nCameraID, int* pBrightValue,int* pContrastValue, int* pSaturationValue,int* pHueValue);
	bool c_setVideoEffect(int nCameraID, DWORD dwBrightValue,DWORD dwContrastValue, DWORD dwSaturationValue,DWORD dwHueValue);
	intptr_t c_getStreamServerWorkState(int nCameraId, int nCameraCount, int *outSize );
	
//ͳһ�ӿڲ㴦��Ľӿ�
	bool c_capturePictureEx(int nCameraID, char* pFileName);
	bool c_controlCameraSound(int nCameraID,bool bOpenSound);
	bool c_serialSend(int nCameraID, char* cmd1, DWORD nLen1, char* cmd2, DWORD nLen2);
	void c_setPlayDrawDevice(int nCameraID);
//HSר��
	int v_setPlayWindow(HWND palyWindow[], int nMaxCount);
public:
	typedef struct CameraInfo
	{
		int  nCameraID;
		HWND hPlayHandle; //��ⲥ�ž��
		bool bDisconnect; //���߱�־
		bool bUseDecode; //ʹ�ñ�׼�����벥�ű�ʶ
		bool bIsExternalDvr; //�Ƿ�Ϊ�ⲿDVR
	}CAMERA_INFO;
	/*!< �����Ѵ���Ƶ��Ϣ */
	vector<CAMERA_INFO*> m_vCameraPool;
	STREAMSERVERWORKSTATE *pDataArray;
	//�Ƿ�ֹͣ���²����¼�
	HANDLE m_hStopRePlay;
	char m_strIP[20];
public:
	void updateCameraInfo(int nCameraID, HWND hPlayHandle, bool bDisconnect, bool bUseDecode ,bool bIsExternalDvr);
	void removeCameraInfo(int nCameraID, HWND hWnd);

public:
	int  c_getPlayPort();
	void c_releasePlayPort(int nPort);
	char * c_getStreamServerIP( int nCameraID);
	bool IsFinded(string sIP, STREAMSERVERWORKSTATELISTTYPE &list);
	int  c_getMonitorID();
	int  c_getMonitorRight();
	/*!< �ͻ��˱������� */
	void ping();
	/*!< ��֤���������� */
	bool pingIndex(); 
	/*!< ��¼�쳣��־ */
	static void WriteSysLog(char* sLogText);
	//! ��ȡ��ǰĿ¼·��
	bool getCurrentDirectory(char* pPath);
	/*!< ��ȡ��������� nCreateFlag �����ڼ�������־ 0Ϊ�޴˱�־ 1Ϊ�д˱�־*/
	CStreamProcess *GetProcessPtr(int nCameraID,int nCreateFlag = 0);
	//�����ӹ��ܲ���

	int c_GetRecordFile(intptr_t lHandle,RECORDQUERYTYPE nType,char* startTime,char* endTime,RECORDFILE pRecordFile[],int nMaxFileCount);
	intptr_t c_ReplayRecordFile(intptr_t lHandle,HWND hWnd,char* fileName,char* startTime, char* endTime,int nFileSize);
	int c_ControlReplayRecordFile(intptr_t lHandle, intptr_t lRePlayhandle,int nCmd,int nInValue);
	bool c_StopReplayRecordFile(intptr_t lHandle, intptr_t lRePlayhandle);

	intptr_t c_DownloadRecordFile(intptr_t lHandle,char* fileName,char* startTime, char* endTime,int nFileSize,char* saveFile);
	int c_GetDownloadPos(intptr_t lHandle, intptr_t ldownloadHandle);


	bool c_StopDownloadRecordFile(intptr_t lHandle, intptr_t ldownloadHandle);
	intptr_t c_CaptureStream(int nCameraID, LPCAPTURESTREAMCALLBACK pCaptuerStreamFuc, void* pUser, int nGetVideoType = 0);

	bool c_StopCaptureStream(intptr_t lHandle);

	//string c_GetDecodeType(int nCameraID);

	bool c_GetDecodeType(int& nCameraID,char* sType);
	intptr_t c_ConnectDVR(int nCameraID);
	void c_disConnectDVR(intptr_t lHandle);


	::Ice::Identity m_id;
public:
	/*!< ��Ƶ������״̬����߳� */
	NVSStampCheck* m_pStampCheck;
	typedef struct ChanStamp
	{
		int nCameraID; //��ͷID
		HWND hWnd;  //���Ŵ���
		int nPlayModel; //����ģʽ
		IceUtil::Time timeStamp; //ʱ��ֵ
		bool bIsExternalDvr; 
	}CHAN_STAMP;
	static vector<CHAN_STAMP> m_vChanStamp;
	
	static bool register4StampCheck(int nCameraID,HWND hWnd,int nPlayMode, bool bIsExternalDvr);
	static void heartBeat4Chan(int nCameraID,HWND hWnd);
	static void unregister4StampCheck(int nCameraID,HWND hWnd,int nPlayMode);
	//���ʱ�������
	void CheckStampTime();
	//���²�����Ƶ
	void rePlayVideo(int nCameraID,HWND hWnd, bool bIsExternalDvr);
	/*!< ��̬ͬ���� */
	static CRITICAL_SECTION m_LockVectorStatic;
    //��̬ͬ����ʹ�ü���
	static int m_nInitCs; 
	bool m_bConnIndex; //������������
	bool m_bConnStream; //������ý�����
	bool  m_bIsExternalClient;
public:
	/*! ö������ʱ��,����ϸ���������� . */
	enum {
		HEARTBEAT = 20		/*!< ��������������֮������ʱ��Ϊ20*100���� */
	};
	/*!< �ͻ��˸�����Ϣ */
	NVSIndex::NVSMonitorInfo m_Monitor;
	/*!< �ͻ���ԭʼID */
	int m_nOrignID;
	/*!< �������������ͨ��ָ�� */
	NVSIndex::NVSIndex4MonitorPrx m_NVSIndex4MonitorPrx;
	/*!< ������������Stream��ͨ��ָ�� *///new 
	NVSIndex::NVSIndex4StreamPrx  m_NVSIndex4StreamPrx;
	/*!< �Ƿ�ע������������ */
	bool m_bRegisterOnIndex;
	/*!< �Ƿ��ʼ������ */
	bool m_bInitEnviroment;
	/*!< �������������ַ��� */
	char m_sDynamicPath[256];
	/*!< ������������Stream�ַ��� */
	char m_sDynamicPathStream[256];
	/*!< ��ⲥ�ž���� */
	vector<int> m_vRealPlayPort;
public:
	/*!< ϵͳICE���Ӷ��� */
	static Ice::CommunicatorPtr m_Communicator;
	/*!< �������� */
	char  m_nWorkStyle;
	/*!< �����߳� */
	NVSHeartThread* m_pHeartThread;
	/*!< ��Ƶ�쳣�����߳��� */
	NVSErrorManage* m_pErrorManage;
	/*!< ���������� */
	CHSVideoProcess *m_pHSVideoProcss;
	/*!< ��Ƶ����ģʽ */
	int  m_nSysPlayModel;
public:
	/*!< ��ⲥ�Żص�����ָ�� */
	RealPlayCallBack m_pPlayCallBack;
	/*!< ����ȡ��׼���ص�����ָ�� */
	LPDecCBFun m_pRealDecodeCallBack;
	/*!< ����ȡʵʱ��Ƶͷ�ص�����ָ�� */
	LPVedioHeadStreamCBFun m_pVedioHeadStreamCB;
	/*!< ����ȡʵʱ��Ƶ���ص�����ָ�� */
	LPVedioBodyStreamCBFun m_pVedioBodyStreamCB;
	/*!< Ԥ����������ַ���ͼ��ص�����ָ�� */
	LPDrawCBFun m_pDrawCB;
	/*! ����֪ͨ�ص�����ָ�� */
	IndexNoticeCallBack m_IndexNoticeCallBack;
	/*! ��¼DVDR֪ͨ�ص�����ָ�� */
	DVRNoticeCallBack m_DVRNoticeCallBack;
	/*! VIS���л�֪ͨ�ص�����ָ�� */
	NoticeSwitchedCallBack  m_NoticeSwitchedCallBack;
public:
	//���ÿ����Դʹ��һ���ٽ������󣬽����������������
	CRITICAL_SECTION m_Lock_RealPlayPort;
	CRITICAL_SECTION m_Lock_StreamServicePool;
    CRITICAL_SECTION m_Lock_ErrorStreamPool;
	CRITICAL_SECTION m_Lock_CameraPool;

	/*LONG m_nConnect;
	long m_lRePlayhandle;*/
	/*long m_ldownloadHandle;
	LONG m_nRealHandle;*/
	map<string, intptr_t> m_vDVRPool;
	CRITICAL_SECTION m_LockDVRPool;

};
