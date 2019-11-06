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
	string m_sProfileName;	//≈‰÷√¬∑æ∂

	int	 m_nLoglevel;	//»’÷æ
	int  m_nEngine;		//”≤Ω‚
	int	 m_nRender;		//‰÷»æ
	int  m_nBufSize;	//ª∫≥Â
};
