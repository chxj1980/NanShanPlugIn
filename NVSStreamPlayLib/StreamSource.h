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
	int    ConFlag;//-1 0  -1�����ж� 0���ӳɹ�
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
//�߼�������ȡICE����
	NVSStreamServiceAPIPrx GetPrx(ServerInfo info);//�߼�����

	Ice::ObjectAdapterPtr  GetAdapter(ServerInfo info);//�߼�����

	NVSStreamServiceAPIPrx CreatePrx(ServerInfo info);//�߼����� ����������ڻ����ICE����

	Ice::ObjectAdapterPtr  CreateAdapter(ServerInfo info);//�߼����� ����������ڻ����ICE����

//ICE ������
	int  CleanAdapterIdentity(ServerInfo info,Ice::Identity DataReceiverIdentity);//ICE�������������

	int  DestroyAdapter(ServerInfo info);//ICE�������������
//ICE�ӿڲ�����

	int  Heart(ServerInfo info);

	XY_BOOL  startPlayer(ServerInfo info,const ::NVSStreamService::DeviceInfo& connectInfo, const ::Ice::Identity& ident, ::std::string& sKey);

	XY_BOOL  stopVideo(ServerInfo info,::std::string& sKey);

	XY_BOOL  ControlCameraSpeed(ServerInfo info,int nMonitorID, string sKeyID,int nCmd,bool bControl,int nSpeed);

	bool  cancelControlCamera(ServerInfo info,int nMonitorID, string sKeyID);

	bool getWorkState(ServerInfo info,NVSStreamService::WorkState &wkState);

	//! Ԥ��λ
	bool TransPTZ(ServerInfo info,int nMonitorID, string sKeyID, int nCmd, int nTransPTZIndex);
	//! ��ȡͨ������������������������Ƶ������
	bool getCompress(ServerInfo info,int nMonitorID, string sKeyID, char **lpOutBuffer);
	//! ����ͨ������
	bool setCompress(ServerInfo info,int nMonitorID, string sKeyID, char* pCompressInfo);
	//! ��ȡ��Ƶ���������ȡ�ɫ�ȡ����Ͷȵȣ�
	bool getVideoEffect(ServerInfo info,int nMonitorID, string sKeyID, int* pBrightValue,int* pContrastValue, int* pSaturationValue,int* pHueValue);
	//! ������Ƶ����
	bool setVideoEffect(ServerInfo info,int nMonitorID, string sKeyID, DWORD dwBrightValue,DWORD dwContrastValue, DWORD dwSaturationValue,DWORD dwHueValue);


public:
//������ý����ѯ̨�߼�����
	CSourceSvrInfomation * GetSvrInfomation(ServerInfo info);

	int  ClearAllSvrInfomation();

	int  DoAllHeartCheck(vector<ServerInfo> &vecFailedSvr);
private:
	void GetKey(ServerInfo info,char *pKey,int nSize);

	NVSStreamServiceAPIPrx ReCreatePrx(ServerInfo info);//ICE�����������

	Ice::ObjectAdapterPtr  ReCreateAdapter(ServerInfo info);//ICE��������������
	
	Ice::CommunicatorPtr m_Communicator; 

	map<string,NVSStreamServiceAPIPrx>  m_mapPrx;
	map<string,Ice::ObjectAdapterPtr>	m_mapAdpPtr; 

	map<string,LinkInfo>				m_mapLinkInfo;

	map<string,CSourceSvrInfomation *>	m_mapSvrInfomation;
	CRITICAL_SECTION m_ConLock;//���m_mapSvrInfomation��Դ
	
};

#define CSOURCESTREAM    1