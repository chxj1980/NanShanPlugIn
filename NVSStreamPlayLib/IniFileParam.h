#pragma once

#include <stdio.h>
#include <tchar.h>
/************************************************************************/
/*                    读INI文件工具类                                   */
/************************************************************************/
#ifdef _AFX

class CIniFileParam
{
public:
	CIniFileParam(CString strFileName = _T(""))
	{
		SetIniFileName(strFileName);
	}
protected:
	CString m_strFileName;

public:
	void SetIniFileName(CString strFileName) {m_strFileName = strFileName;};
	//inline SetIniFileName(CString strFileName) {m_strFileName = strFileName.Trim();};
	void ReadParameter(CString strSection, CString strEntry, int &iValue);
	void ReadParameter(CString strSection, CString strEntry, CString &strValue);
	BOOL WriteParameter(CString strSection, CString strEntry, int iValue);
	BOOL WriteParameter(CString strSection, CString strEntry, CString strValue);
	static CString GetDirectory();
};

#else



class CIniFileParam
{
public:
	CIniFileParam(string strFileName="")
	{
		SetIniFileName(strFileName);
	}
protected:
	string m_strFileName;

public:
	void SetIniFileName(string strFileName) {m_strFileName = strFileName;};
	void ReadParameter(string strSection, string strEntry, int &iValue);
	void ReadParameter(string strSection, string strEntry, string &strValue);
	BOOL WriteParameter(string strSection, string strEntry, int iValue);
	BOOL WriteParameter(string strSection, string strEntry, string strValue);
	static string GetDirectory();
};
#endif
