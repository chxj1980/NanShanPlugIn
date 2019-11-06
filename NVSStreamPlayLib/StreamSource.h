#pragma once
//#include "StreamLib.h"
//#include "StreamLibDef.h"
#include "NVSStreamServiceAPI.h"
#include "SourceSvrInfomation.h"

using namespace NVSStreamService;

struct SourceParamStruct 
{
	string sIP;
	XY_INT nPort;
	string sUser;
	string sPwd;
	XY_INT nChannel;
	string sDllType;
	ServerInfo svrinfo;
};
class CStreamProcess;

class NVSStreamDataReceiverExI : public NVSStreamService::NVSStreamDataReceiver
{
public:
	NVSStreamDataReceiverExI(CStreamProcess *pthis);
	~NVSStreamDataReceiverExI();
public:
	virtual bool sendStreamHead(const ::NVSStreamService::StreamPiece& sd, const ::Ice::Current& = ::Ice::Current());
	virtual bool sendStreamBody(const ::NVSStreamService::StreamPiece& sd, const ::Ice::Current& = ::Ice::Current());
	
	bool  StopSend();
public:
	CStreamProcess *m_pProcess;
};

typedef struct _LinkInfo
{
	string svrInfoKey;
	IceUtil::Time  reconTime;
	int    ClientNum;
	int    ConFlag;//-1 0  -1连接中断 0连接成功
	int    ReconFlag;

	_LinkInfo::_LinkInfo()
	{
		svrInfoKey = "";
		reconTime  = IceUtil::Time::now();
		ClientNum  = 0;
		ConFlag	   = 0;	
		ReconFlag  = 0;
	}

	_LinkInfo operator =(_LinkInfo &linfo)
	{
		svrInfoKey = linfo.svrInfoKey;
		reconTime  = linfo.reconTime;
		ClientNum  = linfo.ClientNum;
		ConFlag    = linfo.ConFlag;
		ReconFlag  = linfo.ReconFlag; 	
		return *this;
	}
}LinkInfo;

class CStreamSourceAgent 
{
public:
	CStreamSourceAgent();
	
	~CStreamSourceAgent();
//逻辑操作获取ICE参数
	NVSStreamServiceAPIPrx GetPrx(ServerInfo info);//逻辑操作

	Ice::ObjectAdapterPtr  GetAdapter(ServerInfo info);//逻辑操作

	NVSStreamServiceAPIPrx CreatePrx(ServerInfo info);//逻辑操作 但如果不存在会调用ICE操作

	Ice::ObjectAdapterPtr  CreateAdapter(ServerInfo info);//逻辑操作 但如果不存在会调用ICE操作

//ICE 操作：
	int  CleanAdapterIdentity(ServerInfo info,Ice::Identity DataReceiverIdentity);//ICE清除反向代理操作

	int  DestroyAdapter(ServerInfo info);//ICE清除适配器操作
//ICE接口操作：

	int  Heart(ServerInfo info);

	XY_BOOL  startPlayer(ServerInfo info,const ::NVSStreamService::DeviceInfo& connectInfo, const ::Ice::Identity& ident, ::std::string& sKey);

	XY_BOOL  stopVideo(ServerInfo info,::std::string& sKey);

	XY_BOOL  ControlCameraSpeed(ServerInfo info,int nMonitorID, string sKeyID,int nCmd,bool bControl,int nSpeed);

	bool  cancelControlCamera(ServerInfo info,int nMonitorID, string sKeyID);

	bool getWorkState(ServerInfo info,NVSStreamService::WorkState &wkState);

	//! 预置位
	bool TransPTZ(ServerInfo info,int nMonitorID, string sKeyID, int nCmd, int nTransPTZIndex);
	//! 获取通道参数（主码流、子码流视频参数）
	bool getCompress(ServerInfo info,int nMonitorID, string sKeyID, char **lpOutBuffer);
	//! 设置通道参数
	bool setCompress(ServerInfo info,int nMonitorID, string sKeyID, char* pCompressInfo);
	//! 获取视频参数（亮度、色度、饱和度等）
	bool getVideoEffect(ServerInfo info,int nMonitorID, string sKeyID, int* pBrightValue,int* pContrastValue, int* pSaturationValue,int* pHueValue);
	//! 设置视频参数
	bool setVideoEffect(ServerInfo info,int nMonitorID, string sKeyID, DWORD dwBrightValue,DWORD dwContrastValue, DWORD dwSaturationValue,DWORD dwHueValue);


public:
//关联流媒体咨询台逻辑操作
	CSourceSvrInfomation * GetSvrInfomation(ServerInfo info);

	int  ClearAllSvrInfomation();

	int  DoAllHeartCheck(vector<ServerInfo> &vecFailedSvr);
private:
	void GetKey(ServerInfo info,char *pKey,int nSize);

	NVSStreamServiceAPIPrx ReCreatePrx(ServerInfo info);//ICE建立代理操作

	Ice::ObjectAdapterPtr  ReCreateAdapter(ServerInfo info);//ICE建立适配器操作
	
	Ice::CommunicatorPtr m_Communicator; 

	map<string,NVSStreamServiceAPIPrx>  m_mapPrx;
	map<string,Ice::ObjectAdapterPtr>	m_mapAdpPtr; 

	map<string,LinkInfo>				m_mapLinkInfo;

	map<string,CSourceSvrInfomation *>	m_mapSvrInfomation;
	CRITICAL_SECTION m_ConLock;//针对m_mapSvrInfomation资源
	
};

#define CSOURCESTREAM    1