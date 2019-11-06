#pragma once

#include <string>
#include <map>
//#include "LogRecorder.h"

using namespace std;


#define ERROR_TIMEOUT_CONNECT 5
#define INFO_WAIT_LOGIN -10002

class StreamHandlerManager
{
public:
	StreamHandlerManager(void);
	~StreamHandlerManager(void);
public:
	map<string,pair<LONG,LONG> > m_vDVRPool;
	CRITICAL_SECTION m_Lock;
	map<string,time_t> m_vErrorDVRPool;
    map<string , bool> m_vBeConnecting;//唐五
public:
	LONG getStreamLoginIdentify(char* sIP,int nPort,char* sUser,char* sPwd,ServerInfo svrinfo);
	bool freeStreamLoginIdentify(string);
	bool freeLoginStreamInfo(string sKey);

    string GetLogConfgFileName();//获取log配置文件
private:
    bool EnterConnect(string sKey);//进入注册流程
    void QuitConnect(string sKey);//退出注册流程
    

private:
    //CLogRecorder *m_log;//唐五_日志
};
