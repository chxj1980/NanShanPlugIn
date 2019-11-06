#pragma once
class CSourceSvrInfomation;
#include "NVSStreamServiceAPI.h"
using namespace NVSStreamService;

class NVSStreamDataReceiverExI;


class CStreamProcess
{
public:
	CStreamProcess(int nCameraID,string sCameraID,CSourceSvrInfomation *pInfomation);
	~CStreamProcess(void);
public:
//�ӿڲ���
	int  RequestVideoICE(ServerInfo svrInfo,::NVSStreamService::DeviceInfo devinfo,::NVSIndex::NVSDVRInfo dvrInfo,HWND hWnd, 
		RealPlayCallBack pRealFun,bool bUseDecode, LPDecCBFun pDecFun, bool bIsExternalDvr);
	int  CaptureStream(ServerInfo svrInfo,::NVSStreamService::DeviceInfo devinfo, bool bIsExternalDvr);
	int  DoCaptureStream(ServerInfo svrInfo,::NVSStreamService::DeviceInfo devinfo, bool bIsExternalDvr);
	int  StopCaptureStream();
	int  SoftSolution(HWND hWnd);
	int  StopSoftSolution(HWND hWnd, int nCameraID=0);
	int  StopAllSoftSolution();
	int  ReconnectCaptureStream();
	int  GetKeyInfo(int nCameraID,string& sKey,ServerInfo& svrinfo);
//��������
	bool CapturePicture(char* pFileName);
	//! ��ʼ����¼��
	int startRecord(char* pFileName);
	//! ֹͣ����¼��
	bool stopRecord();

	int setFileHandle(char* sFileName);

	bool ControlCameraSound(bool bOpenSound);

	bool ControlCameraSpeed(int nCameraID,int nCmd,bool bControl,int nSpeed);

	void v_setPlayDrawDevice();

//�ص�����
	int  initHead(const StreamPiece& sd);
	int  inputData(const StreamPiece& sd);
	static  void  CALLBACK DrawFunCallBack(intptr_t  identify, intptr_t lRealHandle, DWORD hdc, void *pUser);

//�����ڲκ���
	//����ʹ��ʱ���
	int  SetUsedTimeStamp();
	int  CheckUsedTimeStamp();
	int  CheckCameraID(int nCameraID,string sCameraID);
	void SetStreamHeadData(const StreamPiece &pContent);
	int getCameraID();
	int updateCameraID(int nCameraID);
	//���ô�����Ϣ
	int  SetErrorManageInfo(HWND hWnd);
private:
	int m_nCameraID;
	string m_sCameraID;
	IceUtil::Time m_timeU;
	CSourceSvrInfomation *m_pInfomation;
//ICE ����
	/*!< ICE��ý����� */
	NVSStreamServiceAPIPrx m_LocalProxy;
	/*!< ICE��ý��ͻ��������� */
	Ice::ObjectAdapterPtr m_NVSSreamServiceAPIAdapter;
	/*!< ��ý����Ϣ */
	ServerInfo m_SvrInfo;
	/*!< ������Ƶ�ɹ�������δ�յ�ͷ���ݣ��ȴ�ͷ���ݱ�ʶ */
	bool m_bWaitHeadData;
	/*!< ������Ƶ�ɹ�������δ�յ�ͷ���ݣ��ȴ�ͷ�����¼� */
	HANDLE m_hWaitHead;
	/*!< ���ŷ��عؼ���,�ر�ʱʹ�� */
	string     m_sKey;
	/*!< ͨ��Ψһ��ʶ */
	Ice::Identity m_DataReceiverIdentity;
	/*!< ����ͨ��ָ�� */
	NVSStreamDataReceiverExI* m_pDataReceiver;
private:
//���ʹ�ò���
	/*!< ���ý����ȡ��׼����Ƶģʽ��ʶ */
	bool m_bUseDecodeMode;
	/*!< ��Ƶ��ͷ */
	NVSStreamService::StreamPiece m_vHead;
	/*!< ���õ�SDK */
	string m_sDllKey;
	/*!< ��������־ */
	bool m_bIsExternalDvr;
	/*!< �豸��Ϣ ��ý��ʹ�� */
	::NVSStreamService::DeviceInfo m_devinfo;
	/*!< �豸��Ϣ ��ý��ʹ�� */
	string m_sChanStrIndex;
	/*!< �������� */
	string m_sDeCodeType;
	/*!< �������� */
	string m_sOpenType;

	/*!< ��ⲥ�Ž���ص�����ָ�� */
	RealPlayCallBack m_pRealPlayCallBack;
	/*!< ��׼��Ƶ��ʽ�������ص�ָ�� */
	LPDecCBFun m_pStandardCallBack;
private:
	/*! \struct WINPORTPLAYHANDLE
	*   \brief ���岥�Žṹ
	*	\sa NVSVideoProcess
	*/
	struct WINPORTPLAYHANDLE
	{
		/*! ���ھ�� */
		HWND Wnd;
		/*! ��ͷID*/
		int nCameraID;
		/*! ���ž�� */
		intptr_t PlayHandle;
		/*! �˿� */
		int  Port;
		/*! ¼���ļ����� */
		char* pFileName;
		/*! ¼��״̬ 0-��¼�� 1-����¼�� 2-¼����ֹͣ*/
		int nRecordState;
		/*! ¼���ļ���� */
		HANDLE hFileHandle;

		WINPORTPLAYHANDLE()
		{
			Wnd = NULL;
			nCameraID = 0;
			PlayHandle = 0;
			Port = 0;
			pFileName  = NULL;
			nRecordState = 0;
			hFileHandle  = NULL;
		}
	};
	/*!< ���Ŵ��ڳ� */
	vector<WINPORTPLAYHANDLE> m_vWPPH;
	//���ÿ����Դʹ��һ���ٽ������󣬽����������������
	CRITICAL_SECTION m_Lock_WPPH;
	//���Ŵ��ڳز���
	int UpdatePlayInfo(HWND hWnd,intptr_t PlayHandle,int  Port);
public:
	int checkContainWnd(HWND hWnd);
	int getCameraPlayCount();
};
