#pragma once
#include "idvrhandler_x64.h"

class NetInit
{
public:
	NetInit(void);
public:
	~NetInit(void);
public:
	bool Init();
	void UnInit();
	IDVRHandler *GetHandler();
	void FreeHandler(IDVRHandler *pHandler);
public:
	char m_szDllpath[256];
	char m_szConfig[256];
	HMODULE m_hModule;
	typedef IDVRHandler * (*getHandlerFun)();
	getHandlerFun m_getHandler;
};
