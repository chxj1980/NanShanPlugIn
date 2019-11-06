#include "StdAfx.h"
#include "StreamHandlerManager.h"
//#include ".\hkStreamHandler.h"
#include <time.h>
#include "StreamSource.h"
#include "NVSCoreBiz.h"

extern CStreamSourceAgent g_Agent;



StreamHandlerManager::StreamHandlerManager(void)
{
    InitializeCriticalSection(&m_Lock);
}

StreamHandlerManager::~StreamHandlerManager(void)
{
    m_vDVRPool.clear();
    DeleteCriticalSection(&m_Lock);
}
LONG StreamHandlerManager::getStreamLoginIdentify(char* sIP,int nPort,char* sUser,char* sPwd,ServerInfo svrinfo)
{
    char szKey[64] = {0};
    sprintf_s(szKey,sizeof(szKey),"%s:%d",sIP,nPort);
    string sKey;
    sKey = szKey;

    LONG nReturn = -1;
    EnterCriticalSection(&m_Lock);

    time_t lCurrentTime = 0;
    time( &lCurrentTime );

    map<string,time_t>::iterator itErrorFind = m_vErrorDVRPool.find(sKey);
    if(itErrorFind!=m_vErrorDVRPool.end())
    {
        if(lCurrentTime - itErrorFind->second <ERROR_TIMEOUT_CONNECT)
        {
            LeaveCriticalSection(&m_Lock);
            return nReturn;
        }
        else
        {
            m_vErrorDVRPool.erase(itErrorFind);
        }
    }

    map<string,pair<LONG,LONG> >::iterator it = m_vDVRPool.find(sKey);
    if(it!=m_vDVRPool.end())
    {
        nReturn = it->second.first;
        //++it->second.second;
    }
    else
    {
        //唐五
        if (!EnterConnect(sKey))
        {
            LeaveCriticalSection(&m_Lock);
            return INFO_WAIT_LOGIN;
        }
        LeaveCriticalSection(&m_Lock);
        //唐五
        //m_log->WriteDebugLogEx(__FUNCTION__,"注册代理[%s]登陆标志 IP[%s]-端口[%d]\r\n",szKey,sIP,nPort);//唐五

		NVSStreamServiceAPIPrx LocalProxy;
		Ice::ObjectAdapterPtr  NVSSreamServiceAPIAdapter;
		LocalProxy = g_Agent.CreatePrx(svrinfo);
		NVSSreamServiceAPIAdapter = g_Agent.CreateAdapter(svrinfo);
        //m_log->WriteDebugLogEx(__FUNCTION__,"注册结束[%s]登陆标志 IP[%s]-端口[%d]句柄为[%d]\r\n ",szKey,sIP,nPort,nReturn);//唐五

        EnterCriticalSection(&m_Lock);//唐五
        if(LocalProxy == NULL || NVSSreamServiceAPIAdapter == NULL)
        {
            map<string,time_t>::iterator itError = m_vErrorDVRPool.find(sKey);
            if(itError!=m_vErrorDVRPool.end())
            {
                time_t lTime = 0;
                time(&lTime);
                m_vErrorDVRPool[sKey] = lTime;
            }
            QuitConnect(sKey);//唐五
            LeaveCriticalSection(&m_Lock);
            return nReturn;
        }
		nReturn = XY_TRUE;
        pair<LONG,LONG> pairNew;
        m_vDVRPool[sKey] = pairNew;
        m_vDVRPool[sKey].first = nReturn;
        m_vDVRPool[sKey].second = 1;
    }
    QuitConnect(sKey);//唐五
    LeaveCriticalSection(&m_Lock);
    return nReturn;
}
bool StreamHandlerManager::freeStreamLoginIdentify(string sKey)
{
    bool bDisconnect = false;
    EnterCriticalSection(&m_Lock);
    map<string,pair<LONG,LONG> >::iterator it = m_vDVRPool.find(sKey);
    if(it!=m_vDVRPool.end())
    {
        --it->second.second;
        if(it->second.second <= 0)
        {
            if(it->second.first != -1)
			{
				//NET_DVR_Logout_V30(it->second.first);
			}   
            m_vDVRPool.erase(it);
            bDisconnect = true;
        }
    }

    map<string,time_t>::iterator itErrorFind = m_vErrorDVRPool.find(sKey);
    if(itErrorFind!=m_vErrorDVRPool.end())
        m_vErrorDVRPool.erase(itErrorFind);
    LeaveCriticalSection(&m_Lock);
    return bDisconnect;
}

bool StreamHandlerManager::freeLoginStreamInfo(string sKey)
{
    bool bDisconnect = false;
    EnterCriticalSection(&m_Lock);
    map<string,pair<LONG,LONG> >::iterator it = m_vDVRPool.find(sKey);
    if(it!=m_vDVRPool.end())
    {
        --it->second.second;
        if(it->second.second <= 0)
        {
            m_vDVRPool.erase(it);
            bDisconnect = true;
        }
    }
    map<string,time_t>::iterator itErrorFind = m_vErrorDVRPool.find(sKey);
    if(itErrorFind!=m_vErrorDVRPool.end())
        m_vErrorDVRPool.erase(itErrorFind);
    LeaveCriticalSection(&m_Lock);
    return bDisconnect;
}
bool StreamHandlerManager::EnterConnect(string sKey)
{
    map<string , bool>::iterator itConnecting = m_vBeConnecting.find(sKey);
    if (itConnecting == m_vBeConnecting.end())
    {
        m_vBeConnecting[sKey] = true;
        return true;
    }
    else
    {
        return false;
    }
}

void StreamHandlerManager::QuitConnect(string sKey)
{
    map<string , bool>::iterator itConnect = m_vBeConnecting.find(sKey);
    if (itConnect != m_vBeConnecting.end())
    {
        m_vBeConnecting.erase(itConnect);
    }
}

string StreamHandlerManager::GetLogConfgFileName()
{
    char sFilePath[256] = {0};

    if ( GetModuleFileName( NULL, sFilePath, 256 ) == 0 )
    {
        return false;
    }
    string sFileName = sFilePath;
    int nLen = (int)sFileName.find_last_of("\\");
    sFileName = sFileName.substr(0,nLen+1);

    sFileName += "LogConfig.properties";
    return sFileName;
}