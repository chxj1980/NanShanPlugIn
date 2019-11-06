#include "StdAfx.h"
#include "NetInit.h"
#include "ivs_sdk.h"

static bool m_bInit = false;

NetInit::NetInit(void)
{
	m_bInit = false;
	memset(m_szDllpath,0,sizeof(m_szDllpath));
	memset(m_szConfig,0,sizeof(m_szConfig));
	m_hModule = NULL;
	m_getHandler = NULL;
}

NetInit::~NetInit(void)
{
	UnInit();
}

bool NetInit::Init()
{
	if (!m_bInit)
	{
		GetModuleFileName(NULL, m_szDllpath,sizeof(m_szDllpath));
		strrchr(m_szDllpath, '\\')[1] = '\0';
		strcpy(m_szConfig, m_szDllpath);
		strcat(m_szConfig, "camerainfo.ini");
		strcat(m_szDllpath, "PlugIn\\HWPLATPlugIn\\HWPlatNetPlugIn.dll");
		m_hModule = LoadLibraryEx(m_szDllpath, NULL, LOAD_WITH_ALTERED_SEARCH_PATH);
		if (m_hModule == NULL)
		{
			return false;
		}
		m_getHandler = (getHandlerFun)GetProcAddress(m_hModule, "getHandler");
		if (m_getHandler == NULL)
		{
			return false;
		}
		m_bInit = true;
	}
	return true;
}
void NetInit::UnInit()
{

	if (m_bInit)
	{
		if (m_hModule)
		{
			FreeLibrary(m_hModule);
			m_hModule = NULL;
		}
		m_bInit = false;
	}
}

IDVRHandler * NetInit::GetHandler()
{
	if (m_getHandler)
	{
		return m_getHandler();
	}
	return NULL;
}

void NetInit::FreeHandler(IDVRHandler * pHandler)
{
	if (pHandler)
	{
		pHandler->releaseHandler();
	}
}



