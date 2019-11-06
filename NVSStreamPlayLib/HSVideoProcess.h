#pragma once


#include "NVSIndexData.h"

struct PlayInfo
{
	string strDvrIP; //����DVR(����)
	int nPort;		 //�����˿�	
	int nHSCameraID; //����ʶ��ľ�ͷID
	int nCameraID;   //����ID
	intptr_t lPlayHandle; //���ž��
	HWND hWnd;  //���Ŵ��ھ��
	string sCameraCode; //��ͷ��Դ�� == ͳһ����
};

typedef vector <NVSIndex::NVSDVRInfo> NVSDVRInfoType;
typedef vector <PlayInfo> PalyCameraType;

const int MAXPLAYWINDOW = 16;
class CHSVideoProcess
{
public:
	CHSVideoProcess(void);
	~CHSVideoProcess(void);
public :
	int PlayHSVideo(NVSIndex::NVSIndex4MonitorPrx NVSIndex4MonitorPrx, int nCameraID, bool bUseDecode, HWND hWnd,::NVSIndex::NVSDVRInfo _DVRINFO);
	bool StopHSVideo(HWND hWnd, int nCameraID);
	void StopAllHSVideo();
	BOOL InitHSServer(string sUser, string sPasswrod);
	bool ControlCameraSpeed(int nCameraID,int nCmd,bool bControl,int nSpeed);
	bool TransPTZ(int nCameraID, int nCmd, int nTransPTZIndex);
	bool StartRecord(int nCameraID, char *pFileName);
	bool StopRecord(int nCameraID);
	BOOL SetPlayWindow( HWND palyWindow[], int nMaxCount); //���ò��Ŵ���
	bool capturePictureEx(int nCameraID,  char* pFileName); //����ͼƬ
	static  void  CALLBACK DrawFunCallBack(intptr_t  identify, intptr_t lRealHandle, DWORD hdc, void *pUser);
public:
	void AddHSDvr(NVSIndex::NVSDVRInfo &nvsDvrInfo);
	BOOL FindPlayInfo(int nCameraID, PlayInfo &playInfo);//�ڻ�����Ҹþ�ͷ�Ĳ�����Ϣ
	BOOL ConvertToPlayInfo(int nCameraID, NVSIndex::NVSDVRInfo &nvsDvrInfo, PlayInfo &playInfo);

	BOOL GetHSUser(int nCameraID,string &sUser, string &sPassWord); //��ȡ�����ʻ���Ϣ
	void ReleaseHSUser(string &sUser);
public:
	NVSDVRInfoType m_vetorDvrInfo;
	PalyCameraType m_vetorPlayCamera; //�ڲ��ŵ��б�
	//********
	/*!< ����ȡ��׼���ص�����ָ�� */
	LPDecCBFun m_pRealDecodeCallBack;
	//********
private:
	LONG m_identify;  //��½��ʶ
	string m_sDvrIp;  //����IP
	string m_sDvrPort;//����˿�
	string m_sUser;   //�û���
	string m_sPassWord;//����
	
	//LONG m_lPlayHandle;
	HWND m_palyWindow[MAXPLAYWINDOW];
	int  m_playWinNum; //���õĴ��ڸ���==0û������
	bool m_bIsSetWin;  //�Ƿ��豸�˲��Ŵ��� 
};
