#pragma once
#include <vector>
using namespace std;
#include "StreamProcess.h"

class CSourceSvrInfomation
{
public:
	CSourceSvrInfomation(ServerInfo	svrInfo);
	~CSourceSvrInfomation(void);
public:	
	CStreamProcess * GetProcessInfo(int nCameraID,string sCameraID,int nCreateFlag = 0);
	int AddProcess(int nCameraID,string sCameraID);
	int DelProcess(int nCameraID,string sCameraID);
	int GetAllProcessInfo(vector<CStreamProcess*> &vProPool);
	int CleanAllProcessInfo();
	int GetSvrInfo(ServerInfo &svrInfo);
	
	/*!< ��Ƶ�����̳߳� */
	vector<CStreamProcess*> m_vVideoProcessPool;
private:
	//���ÿ����Դʹ��һ���ٽ������󣬽����������������
	CRITICAL_SECTION m_Lock_VideoProcessPool;
	ServerInfo		 m_svrInfo;
};
