#include "StdAfx.h"
#include "NVSStampCheck.h"
#include "NVSCoreBiz.h"
NVSStampCheck::NVSStampCheck(void)
{
	m_pNVSCoreBiz = 0;
	m_bDestroy = false;
	m_hSuspend = CreateEvent(NULL,TRUE,FALSE,NULL);
	ResetEvent(m_hSuspend);
}

NVSStampCheck::~NVSStampCheck(void)
{
	CloseHandle(m_hSuspend);
}
unsigned long NVSStampCheck::Main(void * pParam)
{
	while(!m_bDestroy)
	{
		if(WAIT_OBJECT_0 == WaitForSingleObject(m_hSuspend,100))
		{
			while(!m_bExit) 
			{
				m_pNVSCoreBiz->CheckStampTime();
				Sleep(1000);
			}
		}
	}
	return 0;
}