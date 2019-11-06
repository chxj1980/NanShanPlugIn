#include "StdAfx.h"
#include "NVSErrorManage.h"
#include "NVSCoreBiz.h"

NVSErrorManage::NVSErrorManage(void):m_nCheckTime(10000)
{
	m_pNVSCoreBiz = 0;
	m_bDestroy = false;
	m_hWnd = NULL; m_nCardIndex = -1; m_nCameraID = -1;
	m_hSuspend = CreateEvent(NULL,TRUE,FALSE,NULL);
	ResetEvent(m_hSuspend);
}
NVSErrorManage::~NVSErrorManage(void)
{
	CloseHandle(m_hSuspend);
}
unsigned long NVSErrorManage::Main(void * pParam)
{
	int nSleepCount = 0;
	while(!m_bDestroy)
	{
		if(WAIT_OBJECT_0 == WaitForSingleObject(m_hSuspend,1000))
		{
			while(!m_bExit)
			{
				if(m_pNVSCoreBiz->m_nSysPlayModel == 0 && m_nCameraID > 0 )
				{
					m_pNVSCoreBiz->c_stopPlayVideo(m_hWnd,m_nCardIndex, m_nCameraID);
					Sleep(200);
					m_hWnd = NULL; m_nCardIndex = -1; m_nCameraID = -1;
						m_nCheckTime = 10000;
				}
				//WaitForSingleObject(m_hSuspend,m_nCheckTime);
				//Sleep(m_nCheckTime);
				Sleep(1000);
			}
			ResetEvent(m_hSuspend);
		}
	}
	return 0;
}
