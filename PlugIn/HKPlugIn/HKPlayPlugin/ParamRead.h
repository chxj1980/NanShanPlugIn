#pragma once
#include <string>
using namespace std;

class CParamRead
{
public:
	CParamRead(void);
public:
	~CParamRead(void);
public:
	bool InitParam();
	bool GetDir();
	void ReadParameter(string sSection, string sEntry, string &sValue, string sFileName = "");
	void ReadParameter(string sSection, string sEntry, int &nValue, string sFileName = "");
	bool ReadParameter(string sSection, string sEntry, void * pValue, int nSize, string sFileName = "");
	bool WriteParameter(string sSection, string sEntry, string sValue,  string sFileName = "");
	bool WriteParameter(string sSection, string sEntry, int iValue,  string sFileName = "");
	bool WriteParameter(string sSection, string sEntry, void * pValue, int nSize, string sFileName = "");
public:
	string m_sProfileName;	//����·��

	int	 m_nLoglevel;	//��־
	int  m_nEngine;		//Ӳ��
	int	 m_nRender;		//��Ⱦ
	int  m_nBufSize;	//����
};
