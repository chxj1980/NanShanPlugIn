#include "stdafx.h"
#include "NVSMonitorNotifierI.h"

extern NVSCoreBiz GL_CoreBiz;

NVSMonitorNotifierI::NVSMonitorNotifierI(void)
{
	m_DVRNoticePtr = new NVSDVRNotice();
	if(m_DVRNoticePtr)
	{
		m_DVRNoticePtr->start();
	}
}

NVSMonitorNotifierI::~NVSMonitorNotifierI(void)
{
	m_DVRNoticePtr->stop();
	m_DVRNoticePtr = 0;
}


void NVSMonitorNotifierI::monitorNotify(const ::NVSStreamService::NotifierData& nd, const ::Ice::Current&)
{
	DVRNoticeData NoticeMsg;

	if (m_DVRNoticePtr)
	{
		NoticeMsg.nCameraID = nd.nCameraID;
		NoticeMsg.nErr = nd.nErr;

		m_DVRNoticePtr->add(NoticeMsg);
	}
	return;
}