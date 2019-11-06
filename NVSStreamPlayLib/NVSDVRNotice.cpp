#include "StdAfx.h"
#include "NVSDVRNotice.h"

extern NVSCoreBiz GL_CoreBiz;

NVSDVRNotice::NVSDVRNotice(void)
{
	m_bExit = false;
}

NVSDVRNotice::~NVSDVRNotice(void)
{
	m_bExit = true;
}

void NVSDVRNotice::run()
{
	DVRNoticeData notice;

	while (!m_bExit)
	{
		notice = m_DVRNoticeDataBuf.get();

		if(GL_CoreBiz.m_DVRNoticeCallBack)
		{
			GL_CoreBiz.m_DVRNoticeCallBack(notice.nCameraID,notice.nErr);
		}

		Sleep(2);
	}
}

void NVSDVRNotice::add(DVRNoticeData pDVRNoticeData)
{
	m_DVRNoticeDataBuf.put(pDVRNoticeData);
	return;
}

void NVSDVRNotice::stop()
{
	if (m_bExit)
		return;
	m_bExit = true;
	m_DVRNoticeDataBuf.getoff(); //停止在缓存中等待数据
	this->getThreadControl().join();
	return;
}