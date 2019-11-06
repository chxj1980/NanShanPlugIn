#include "StdAfx.h"
#include "NVSRightNoticeThread.h"

extern NVSCoreBiz GL_CoreBiz;

NVSRightNoticeThread::NVSRightNoticeThread(void)
{
	m_bExit = false;
}

NVSRightNoticeThread::~NVSRightNoticeThread(void)
{
	m_bExit = true;
}

void NVSRightNoticeThread::run()
{
	RightNotice notice;

	while (!m_bExit)
	{
		notice = m_RightNoticeBuf.get();

		if(GL_CoreBiz.m_IndexNoticeCallBack)
		{
			GL_CoreBiz.m_IndexNoticeCallBack(notice.nUserID,notice.nChangeType,notice.nLimitTime);
		}

		Sleep(10);
	}
}

void NVSRightNoticeThread::add(RightNotice pRightMess)
{
	m_RightNoticeBuf.put(pRightMess);
	return;
}

void NVSRightNoticeThread::stop()
{
	if (m_bExit)
		return;
	m_bExit = true;
	m_RightNoticeBuf.getoff(); //停止在缓存中等待数据
	this->getThreadControl().join();
	return;
}