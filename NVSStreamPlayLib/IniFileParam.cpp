/////////////////////////////////////////////////////////////////////////////
//Project:      
//Discription:  Ini�����ļ�����
//Written By:   JERRY
//Date:         2006-06-26
//Version:      1.0

//Modified by:
//Modified Date:
//Version:
////////////////////////////////////////////////////////////////////////////
#include "StdAfx.h"
#include "IniFileParam.h"
#pragma warning(disable:4996)


#ifdef _AFX

///////////////////////////////////////////////////////////////////////////
//����: ��Ini�ļ��ж�Int����
//
///////////////////////////////////////////////////////////////////////////
void CIniFileParam::ReadParameter(CString strSection, CString strEntry, int &iValue)
{
	iValue = GetPrivateProfileInt(LPCTSTR(strSection), LPCTSTR(strEntry), 0, LPCTSTR(m_strFileName));
}

///////////////////////////////////////////////////////////////////////////
//����: ��Ini�ļ��ж�string����
//
///////////////////////////////////////////////////////////////////////////
void CIniFileParam::ReadParameter(CString strSection, CString strEntry, CString &strValue)
{
	char szRead[2048] = {0};
	GetPrivateProfileString(LPCTSTR(strSection), LPCTSTR(strEntry), "", szRead, sizeof(szRead), LPCTSTR(m_strFileName));
	strValue = szRead;
}

///////////////////////////////////////////////////////////////////////////
//����: ��Int����ֵд��Ini�ļ���
//
///////////////////////////////////////////////////////////////////////////
BOOL CIniFileParam::WriteParameter(CString strSection, CString strEntry, int iValue)
{
	CString strValue;
	strValue.Format("%d", iValue);
	return WriteParameter(strSection, strEntry, strValue);
}

///////////////////////////////////////////////////////////////////////////
//����: ��string����ֵд��Ini�ļ���
//
///////////////////////////////////////////////////////////////////////////
BOOL CIniFileParam::WriteParameter(CString strSection, CString strEntry, CString strValue)
{
	return WritePrivateProfileString(LPCTSTR(strSection), LPCTSTR(strEntry), LPCTSTR(strValue), LPCTSTR(m_strFileName));
}


CString CIniFileParam::GetDirectory()
{
		//ȡ�õ�ǰĿ¼
	TCHAR fileName[MAX_PATH];
	GetModuleFileName( NULL, fileName, MAX_PATH );
	TCHAR drive[MAX_PATH],dir[MAX_PATH],fname[MAX_PATH],ext[MAX_PATH];
	_tsplitpath( fileName,drive,dir,fname,ext );
	strcpy( fileName, drive );
	strcat( fileName, dir );

	char szDirectory[MAX_PATH] = {0};
	strcpy(szDirectory,fileName);
	
	return CString(szDirectory);

	
}

#else

///////////////////////////////////////////////////////////////////////////
//����: ��Ini�ļ��ж�Int����
//
///////////////////////////////////////////////////////////////////////////
void CIniFileParam::ReadParameter(string strSection, string strEntry, int &iValue)
{
	iValue = GetPrivateProfileInt(strSection.c_str(), strEntry.c_str(), 0, m_strFileName.c_str());
}

///////////////////////////////////////////////////////////////////////////
//����: ��Ini�ļ��ж�string����
//
///////////////////////////////////////////////////////////////////////////
void CIniFileParam::ReadParameter(string strSection, string strEntry, string &strValue)
{
	char szRead[2048] = {0};
	GetPrivateProfileString(strSection.c_str(), strEntry.c_str(), "", szRead, sizeof(szRead), m_strFileName.c_str());
	strValue = szRead;
}

///////////////////////////////////////////////////////////////////////////
//����: ��Int����ֵд��Ini�ļ���
//
///////////////////////////////////////////////////////////////////////////
BOOL CIniFileParam::WriteParameter(string strSection, string strEntry, int iValue)
{
	char strValue[256];
	sprintf_s(strValue, 256, "%d", iValue);
	
	return WriteParameter(strSection, strEntry, strValue);
}

///////////////////////////////////////////////////////////////////////////
//����: ��string����ֵд��Ini�ļ���
//
///////////////////////////////////////////////////////////////////////////
BOOL CIniFileParam::WriteParameter(string strSection, string strEntry, string strValue)
{
	return WritePrivateProfileString(strSection.c_str(), strEntry.c_str(), strValue.c_str(), m_strFileName.c_str());
}


string CIniFileParam::GetDirectory()
{
	//ȡ�õ�ǰĿ¼
	TCHAR fileName[MAX_PATH];
	GetModuleFileName( NULL, fileName, MAX_PATH );
	TCHAR drive[MAX_PATH],dir[MAX_PATH],fname[MAX_PATH],ext[MAX_PATH];
	_tsplitpath( fileName,drive,dir,fname,ext );
	strcpy( fileName, drive );
	strcat( fileName, dir );

	char szDirectory[MAX_PATH] = {0};
	strcpy(szDirectory,fileName);

	return string(szDirectory);

}
#endif