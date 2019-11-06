// 
#include <StdAfx.h>
#include "NVSIndexNoticeI.h"
#include "NVSCoreBiz.h"

extern NVSCoreBiz GL_CoreBiz;

NVSIndexNoticeI::NVSIndexNoticeI(void)
{
	m_NoticeMsgPtr = new NVSNoticeThread();
	if (m_NoticeMsgPtr)
	{
		m_NoticeMsgPtr->start();
	}

	m_RightNoticePtr = new NVSRightNoticeThread();
	if (m_RightNoticePtr)
	{
		m_RightNoticePtr->start();
	}
}

NVSIndexNoticeI::~NVSIndexNoticeI(void)
{
	m_NoticeMsgPtr->stop();
	m_NoticeMsgPtr = 0;

	m_RightNoticePtr->stop();
	m_RightNoticePtr = 0;
}


bool NVSIndexNoticeI::notifyClient(const ::NVSIndex::IndexNoticeInfo& NoticeInfo, const ::Ice::Current&)
{   
	RightNotice RightInfo;

	if (m_RightNoticePtr)
	{
		RightInfo.nUserID = NoticeInfo.nUserID;
		RightInfo.nChangeType = NoticeInfo.nChangeType;
		RightInfo.nLimitTime = NoticeInfo.nLimitTime;

		m_RightNoticePtr->add(RightInfo);
	}
	return true;
}

bool NVSIndexNoticeI::notifySwitched(::Ice::Int nMonitorID, ::Ice::Int nPriorCameraID, ::Ice::Int nCameraID, const ::std::string& sDescription, const ::Ice::Current& ct)
{

	NoticeMsg mess;

	if (m_NoticeMsgPtr)
	{
		mess.nIndexID = nMonitorID;
		mess.nPriorCameraID = nPriorCameraID;
		mess.nCameraID = nCameraID;
		mess.sDescrip = sDescription;

		m_NoticeMsgPtr->add(mess);
	}

	return true;
}