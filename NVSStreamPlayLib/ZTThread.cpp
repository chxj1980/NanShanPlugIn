#include "StdAfx.h"
#include <stdio.h>
#include ".\ztthread.h"
#include <process.h>


ZTThread::ZTThread(void):m_hThread(INVALID_HANDLE_VALUE),m_bExit(false)
{
}

ZTThread::~ZTThread(void)
{
	if(m_hThread!=0 && m_hThread!=INVALID_HANDLE_VALUE)
		CloseHandle(m_hThread);
}
void ZTThread::CreateThread(void * pParam,bool bSuspend)
{
	m_pParam = pParam;
	m_hThread = ::CreateThread(NULL,0,ThreadProc,this,bSuspend?CREATE_SUSPENDED:0,&m_dwThreadID);
}
void ZTThread::End()
{
	WaitForSingleObject(m_hThread, 10000);
}
unsigned long ZTThread::Main(void * pParam)
{
	return 0;
}
unsigned long __stdcall ZTThread::ThreadProc(LPVOID lpParameter)
{
	ZTThread * pThread = (ZTThread *) lpParameter;
	unsigned long dwReturnVal = pThread->Main(pThread->m_pParam);
	return dwReturnVal;
}
void ZTThread::Start()
{
	m_pParam = NULL;
	if (m_hThread == INVALID_HANDLE_VALUE)
	{
		m_hThread = ::CreateThread(0,0,ThreadProc,this,0,&m_dwThreadID);
		if(m_hThread == INVALID_HANDLE_VALUE || m_hThread == 0)
		{
			static int nCount = 0;
#ifdef _DEBUG
			printf("线程创建失败[%d]个,Error Code %d\r\n",++nCount,GetLastError());
#endif
		}
	}
	else
		ResumeThread(m_hThread);
}
