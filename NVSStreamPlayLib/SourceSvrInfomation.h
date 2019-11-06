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
	
	/*!< 视频播放线程池 */
	vector<CStreamProcess*> m_vVideoProcessPool;
private:
	//针对每个资源使用一个临界区对象，解决出现锁错误的情况
	CRITICAL_SECTION m_Lock_VideoProcessPool;
	ServerInfo		 m_svrInfo;
};
