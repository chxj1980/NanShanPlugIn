#pragma once
#include "NVSCoreBiz.h"
#include "NVSStreamServiceAPI.h"

typedef struct  _HWNDINFO
{
	HWND hwnd;
	int  nCameraID;
	string sCameraID;
	ServerInfo svrinfo;

	_HWNDINFO()
	{
		hwnd = NULL;
		nCameraID = 0;
		sCameraID = "";
	}

	_HWNDINFO& operator =(_HWNDINFO info)
	{
		hwnd	  = info.hwnd;
		nCameraID = info.nCameraID;
		sCameraID = info.sCameraID;
		svrinfo   = info.svrinfo;
		return *this;
	}

}HWNDINFO;

class CPaperForm
{
public:
	CPaperForm(void);
	~CPaperForm(void);
public:
	static void  InitPaperFormS();
	static void  UnInitPaperFormS();

	static void ClearAllSource();
	static int	UpdateCameraID(int nPriorID,int nSwitchID,string sCameraID);//更新镜头20121225
	static int  GetCheckedSvrInfo(ServerInfo& SourceSvrInfo,int nCameraID);

	int ParaseParam(int nCameraID,string sCameraID,bool bIsExternalDvr,ServerInfo &svrInfo,::NVSStreamService::DeviceInfo &devinfo);
	int ParaseParam(int nCameraID,ServerInfo &svrInfo,::NVSStreamService::DeviceInfo &devinfo);
	static int EraseParam(int nCameraID,string sCameraID,HWND hWnd);
	int PushParam(int nCameraID,string sCameraID,HWND hWnd,ServerInfo svrInfo);

	int ParseSvrInfo(string sIndexKey,string &sKey,string &sIp,int &nPort);
	int CheckHInfoExist(HWND hWnd,int &nCameraID,string &sCameraID);

	int  GetCameraIDDevInfoByIndex(int nCameraID,bool bIsExternalDvr,::NVSStreamService::DeviceInfo& SourceInfo,string &sState);
	int  GetStreamSvrInfoByIndex(int nCameraID,ServerInfo& SourceSvrInfo);	
	int  GetDvrInfo(int nCameraID,::NVSIndex::NVSDVRInfo &dvrinfo);
	
public:
	HWNDINFO	m_hInfo;
	::NVSIndex::NVSDVRInfo m_dvrinfo;
	ServerInfo	m_sServerInfo;
	static map<HWND,HWNDINFO> m_cMapHInfo;
	static map<int,HWNDINFO>  m_cMapCAMInfo;
	//针对每个资源使用一个临界区对象，解决出现锁错误的情况
	static CRITICAL_SECTION m_Lock_MapHInfo;
	int		    m_nCameraID;
};
