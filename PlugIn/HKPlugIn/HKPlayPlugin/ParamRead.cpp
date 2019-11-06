#include "StdAfx.h"
#include "ParamRead.h"
#include <Winbase.h>

CParamRead::CParamRead(void)
: m_sProfileName("")
{
	GetDir();
    m_nEngine = 0;
}

CParamRead::~CParamRead(void)
{

}

bool CParamRead::GetDir()
{
	DWORD nBufferLenth = MAX_PATH;
	char szBuffer[MAX_PATH] = {0};
	DWORD dwRet = GetModuleFileNameA(NULL, szBuffer, nBufferLenth);
	if (dwRet == 0)
	{
		return false;
	}
	char *sPath = strrchr(szBuffer, '\\');
	memset(sPath, 0, strlen(sPath));
	m_sProfileName = szBuffer;
	m_sProfileName += "\\DecodeEngine.ini";
	return true;
}

void CParamRead::ReadParameter(string sSection, string sEntry, string &sValue, string sFileName)
{
	char szReturnedString[2048] = {0};
	GetPrivateProfileStringA(sSection.c_str(), sEntry.c_str(), "", szReturnedString, sizeof(szReturnedString), m_sProfileName.c_str());
	sValue = szReturnedString;
}

void CParamRead::ReadParameter(string sSection, string sEntry, int &nValue, string sFileName)
{
	nValue = GetPrivateProfileIntA(sSection.c_str(), sEntry.c_str(), 0, m_sProfileName.c_str());
}

bool CParamRead::ReadParameter(string sSection, string sEntry, void * pValue, int nSize, string sFileName)
{
	return false;
}

bool CParamRead::WriteParameter(string sSection, string sEntry, string sValue, string sFileName)
{
	return false;
}

bool CParamRead::WriteParameter(string sSection, string sEntry, int iValue, string sFileName)
{
	return false;
}

bool CParamRead::WriteParameter(string sSection, string sEntry, void * pValue, int nSize, string sFileName)
{
	return false;
}

bool CParamRead::InitParam()
{
	ReadParameter("LOG", "Log", m_nLoglevel);
	ReadParameter("DECODE", "Engine", m_nEngine);
	ReadParameter("DECODE", "Render", m_nRender);
	ReadParameter("DECODE", "BufferSize", m_nBufSize);
	return true;
}
