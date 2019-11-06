#include "StdAfx.h"
#include "NetInit.h"
#include "ivs_sdk.h"

static bool m_bInit = false;

NetInit::NetInit(void)
{
	m_bInit = false;
	m_nLogin = 0;
	m_nHWHandle = -1;
	memset(m_szDecodeEngine,0,sizeof(m_szDecodeEngine));
	memset(m_szConfig,0,sizeof(m_szConfig));
	InitializeCriticalSection(&m_lock);
	
}

NetInit::~NetInit(void)
{
	DeleteCriticalSection(&m_lock);
	UnInit();
}

void NetInit::Init()
{
	if (!m_bInit)
	{
		printf("IVS_SDK_Init\n");
		WriteLog("IVS_SDK_Init");
		IVS_SDK_Init();
		m_bInit = true;

		GetModuleFileName(NULL,m_szDecodeEngine,sizeof(m_szDecodeEngine));
		strrchr(m_szDecodeEngine, '\\')[1] = '\0';
		strcpy(m_szConfig, m_szDecodeEngine);
		strcat(m_szConfig, "camerainfo.ini");
		strcat(m_szDecodeEngine, "DecodeEngine.ini");
	}
}
void NetInit::UnInit()
{
	if (m_nHWHandle != -1)
	{
		WriteLog("IVS_SDK_Logout");
		IVS_SDK_Logout(m_nHWHandle);
		m_nHWHandle = -1;
	}
	if (m_bInit)
	{
		WriteLog("IVS_SDK_Cleanup");
		IVS_SDK_Cleanup();
		m_bInit = false;
	}
}

int	NetInit::Login(char* sIP,int nPort,char* sUser,char* sPwd)
{
	EnterCriticalSection(&m_lock);

	if (m_nHWHandle != -1)
	{
		m_nLogin++;
		printf("connect ok count:%d\n",m_nLogin);
		WriteLog("User Login count[%d]", m_nLogin);
		LeaveCriticalSection(&m_lock);
		return m_nHWHandle;
	}

	Init();

	IVS_LOGIN_INFO stuDevInfo;
	memset(&stuDevInfo,0,sizeof(IVS_LOGIN_INFO));
	stuDevInfo.stIP.uiIPType = IP_V4;
	memcpy(stuDevInfo.stIP.cIP,sIP,strlen(sIP));
	stuDevInfo.uiPort = nPort;
	memcpy(stuDevInfo.cUserName,sUser,strlen(sUser));
	memcpy(stuDevInfo.pPWD,sPwd,strlen(sPwd));
	IVS_CHAR szPlatformType[256] = { 0 };
	IVS_INT32 nErrCode = IVS_SDK_Login(&stuDevInfo,&m_nHWHandle, szPlatformType);

	if (nErrCode != IVS_SUCCEED)
	{
		WriteLog("登陆华为平台[%d]失败 error:%d!",m_nHWHandle,nErrCode);
		printf("登陆华为平台[%d]失败 error:%d!\n",m_nHWHandle,nErrCode);
		m_nHWHandle = -1;
		m_nLogin = 0;
		LeaveCriticalSection(&m_lock);
		return m_nHWHandle;
	}
	m_nLogin++;
	LeaveCriticalSection(&m_lock);
	printf("登陆华为平台成功[%d]\n",m_nHWHandle);
	WriteLog("User Login count[%d]", m_nLogin);
	WriteLog("IVS_SDK_Login");
	return m_nHWHandle;
}

void NetInit::LogOut()
{
	EnterCriticalSection(&m_lock);
	if (m_nLogin > 0)
	{
		m_nLogin--;
		printf("disconnect ok count:%d\n",m_nLogin);
		WriteLog("User Logout count[%d]", m_nLogin);
		if (m_nLogin <=0)
		{
			m_nLogin = 0;
			printf("IVS_SDK_Logout %d\n", m_nLogin);
			UnInit();
		}
	}
	LeaveCriticalSection(&m_lock);
}

void NetInit::WriteLog(const char *sFormat, ...)
{
	FILE *log = fopen("C:\\NVSLog\\SDKEngine\\HWPlatPlugIn.log", "a+");
	if (log)
	{
		char szLog[1024] = {0};
		va_list args;
		va_start(args, sFormat);
		vsprintf(szLog, sFormat, args);
		va_end(args);
		strcat(szLog,"\r\n");
		fwrite(szLog,strlen(szLog),1,log);
		fclose(log);
		log = NULL;
	}
}