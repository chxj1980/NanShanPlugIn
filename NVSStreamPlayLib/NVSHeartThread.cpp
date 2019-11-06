#include "StdAfx.h"
#include "NVSHeartThread.h"
#include "NVSCoreBiz.h"

NVSHeartThread::NVSHeartThread(void)
{
	m_pNVSCoreBiz = 0;
	m_bDestroy = false;
	m_hSuspend = CreateEvent(NULL,TRUE,FALSE,NULL);
	ResetEvent(m_hSuspend);
}
NVSHeartThread::~NVSHeartThread(void)
{
	if (m_hSuspend)
	{
		CloseHandle(m_hSuspend);
		m_hSuspend = NULL;
	}
	
}
unsigned long NVSHeartThread::Main(void * pParam)
{
	int nSleepCount = 0;
	while(!m_bDestroy)
	{
		if(WAIT_OBJECT_0 == WaitForSingleObject(m_hSuspend,1000))
		{
			while(!m_bExit)
			{
				if(nSleepCount >= NVSCoreBiz::HEARTBEAT)
				{
					nSleepCount = 0;
					m_pNVSCoreBiz->ping();
				}
				else
				{
					++nSleepCount;
				}
				Sleep(100);
			}
			ResetEvent(m_hSuspend);
		}
	}
	return 0;
}
