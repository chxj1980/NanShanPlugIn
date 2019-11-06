#include "StdAfx.h"
#include "SourceSvrInfomation.h"

CSourceSvrInfomation::CSourceSvrInfomation(ServerInfo svrInfo)
{
	m_svrInfo = svrInfo;
	::InitializeCriticalSection(&m_Lock_VideoProcessPool);
}

CSourceSvrInfomation::~CSourceSvrInfomation(void)
{
	::DeleteCriticalSection(&m_Lock_VideoProcessPool);		
}

CStreamProcess * CSourceSvrInfomation::GetProcessInfo(int nCameraID,string sCameraID,int nCreateFlag)
{
	::EnterCriticalSection(&m_Lock_VideoProcessPool);
	int nSize = (int)m_vVideoProcessPool.size();
	CStreamProcess* pPrc = NULL;
	vector<CStreamProcess*>::iterator itPrc;

	if(nSize > 0)
	{
		for(itPrc = m_vVideoProcessPool.begin();itPrc != m_vVideoProcessPool.end();)
		{
			if((*itPrc) && (XY_TRUE <= (*itPrc)->CheckCameraID(nCameraID,sCameraID)))
			{
				(*itPrc)->SetUsedTimeStamp();
				::LeaveCriticalSection(&m_Lock_VideoProcessPool);
				return *itPrc;
			}

			if(XY_TRUE == (*itPrc)->CheckUsedTimeStamp() && (*itPrc)->getCameraPlayCount() == 0 && (*itPrc)->getCameraID() == -1)
			{
				delete *itPrc;
				itPrc = m_vVideoProcessPool.erase(itPrc);
			}
			else
			{
				itPrc++;
			}
		}
	}

	if(nCreateFlag)
	{
		pPrc = new CStreamProcess(nCameraID,sCameraID,this);
		if(pPrc != NULL)
		{
			m_vVideoProcessPool.push_back(pPrc);
		}
	}
	::LeaveCriticalSection(&m_Lock_VideoProcessPool);

	return pPrc;
}

int CSourceSvrInfomation::GetAllProcessInfo(vector<CStreamProcess*> &vProPool)
{
	int nSize = 0;
	::EnterCriticalSection(&m_Lock_VideoProcessPool);
	vector<CStreamProcess*>::iterator itPrc;
	for(itPrc = m_vVideoProcessPool.begin();itPrc != m_vVideoProcessPool.end();)
	{
		if(XY_TRUE == (*itPrc)->CheckUsedTimeStamp() && (*itPrc)->getCameraPlayCount() == 0)
		{
			delete *itPrc;
			itPrc = m_vVideoProcessPool.erase(itPrc);
		}
		else
		{
			(*itPrc)->SetUsedTimeStamp();
			itPrc++;
		}		
	}
	copy(m_vVideoProcessPool.begin(),m_vVideoProcessPool.end(),vProPool.begin());
	nSize = (int)m_vVideoProcessPool.size();
	::LeaveCriticalSection(&m_Lock_VideoProcessPool);
	return nSize;
}

int CSourceSvrInfomation::CleanAllProcessInfo()
{
	::EnterCriticalSection(&m_Lock_VideoProcessPool);
	
	vector<CStreamProcess*>::iterator itPrc;
	for(itPrc = m_vVideoProcessPool.begin();itPrc != m_vVideoProcessPool.end();)
	{
		CStreamProcess* pPrc = *itPrc;
		pPrc->StopAllSoftSolution();
		pPrc->StopCaptureStream();
		if(XY_TRUE == (*itPrc)->CheckUsedTimeStamp() && (*itPrc)->getCameraPlayCount() == 0 && (*itPrc)->getCameraID() == -1)
		{
			delete pPrc;
			itPrc = m_vVideoProcessPool.erase(itPrc);
		}
		else
		{
			itPrc++;
		}
	}
	int nSize = (int)m_vVideoProcessPool.size();
	::LeaveCriticalSection(&m_Lock_VideoProcessPool);
	return nSize;
}


int CSourceSvrInfomation::GetSvrInfo(ServerInfo &svrInfo)
{
	svrInfo = m_svrInfo;
	int nSize = 0;
	::EnterCriticalSection(&m_Lock_VideoProcessPool);
	vector<CStreamProcess*>::iterator itPrc;
	for(itPrc = m_vVideoProcessPool.begin();itPrc != m_vVideoProcessPool.end();)
	{
		if(XY_TRUE == (*itPrc)->CheckUsedTimeStamp() && (*itPrc)->getCameraPlayCount() == 0)
		{
			delete *itPrc;
			itPrc = m_vVideoProcessPool.erase(itPrc);
		}
		else
		{
			itPrc++;
		}		
	}
	nSize = (int)m_vVideoProcessPool.size();
	::LeaveCriticalSection(&m_Lock_VideoProcessPool);
	return nSize;
}