#pragma once


#include "NVSIndexData.h"

struct PlayInfo
{
	string strDvrIP; //华三DVR(区域)
	int nPort;		 //华三端口	
	int nHSCameraID; //华三识别的镜头ID
	int nCameraID;   //信义ID
	intptr_t lPlayHandle; //播放句柄
	HWND hWnd;  //播放窗口句柄
	string sCameraCode; //镜头资源码 == 统一编码
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
	BOOL SetPlayWindow( HWND palyWindow[], int nMaxCount); //设置播放窗口
	bool capturePictureEx(int nCameraID,  char* pFileName); //捕获图片
	static  void  CALLBACK DrawFunCallBack(intptr_t  identify, intptr_t lRealHandle, DWORD hdc, void *pUser);
public:
	void AddHSDvr(NVSIndex::NVSDVRInfo &nvsDvrInfo);
	BOOL FindPlayInfo(int nCameraID, PlayInfo &playInfo);//在缓冲查找该镜头的播放信息
	BOOL ConvertToPlayInfo(int nCameraID, NVSIndex::NVSDVRInfo &nvsDvrInfo, PlayInfo &playInfo);

	BOOL GetHSUser(int nCameraID,string &sUser, string &sPassWord); //获取华三帐户信息
	void ReleaseHSUser(string &sUser);
public:
	NVSDVRInfoType m_vetorDvrInfo;
	PalyCameraType m_vetorPlayCamera; //在播放的列表
	//********
	/*!< 软解获取标准流回调函数指针 */
	LPDecCBFun m_pRealDecodeCallBack;
	//********
private:
	LONG m_identify;  //登陆标识
	string m_sDvrIp;  //区域IP
	string m_sDvrPort;//区域端口
	string m_sUser;   //用户名
	string m_sPassWord;//密码
	
	//LONG m_lPlayHandle;
	HWND m_palyWindow[MAXPLAYWINDOW];
	int  m_playWinNum; //设置的窗口个数==0没有设置
	bool m_bIsSetWin;  //是否设备了播放窗口 
};
