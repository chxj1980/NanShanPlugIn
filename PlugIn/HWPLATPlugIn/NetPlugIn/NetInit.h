#pragma once

class NetInit
{
public:
	NetInit(void);
public:
	~NetInit(void);
public:
	void Init();
	int	 Login(char* sIP,int nPort,char* sUser,char* sPwd);
	void LogOut();
	void UnInit();
	void WriteLog(const char *sFormat, ...);
public:
	int m_nLogin;
	int m_nHWHandle;
	char m_szDecodeEngine[256];
	char m_szConfig[256];
	CRITICAL_SECTION m_lock;
};
