#include "StdAfx.h"
#include "NVSNoticeThread.h"

extern NVSCoreBiz GL_CoreBiz;

NVSNoticeThread::NVSNoticeThread(void)
{
	m_bExit = false;
}

NVSNoticeThread::~NVSNoticeThread(void)
{
	m_bExit = true;
}

void NVSNoticeThread::run()
{
	NoticeMsg notice;

	while (!m_bExit)
	{
		notice = m_NoticeMsgBuf.get();

		Sleep(1000);
		if(GL_CoreBiz.m_NoticeSwitchedCallBack)
		{
			GL_CoreBiz.WriteSysLog("NVSNoticeThread UPDATE CAMERA BEGIN");
			//在被键盘用户抢占时，不需要更新镜头信息，更新也没有意义 lixq 20110523
			if (notice.nPriorCameraID != 0 && notice.nCameraID != 0 && notice.sDescrip == "视频通道被抢占")
			{
				//VIS镜头被抢占时，更新镜头信息
				GL_CoreBiz.updateCameraID(notice.nPriorCameraID,notice.nCameraID);
			}
			GL_CoreBiz.m_NoticeSwitchedCallBack(notice.nIndexID,notice.nPriorCameraID,notice.nCameraID,(char*)notice.sDescrip.c_str());
			GL_CoreBiz.WriteSysLog("NVSNoticeThread UPDATE CAMERA END");
		}

		Sleep(10);
	}
}

void NVSNoticeThread::add(NoticeMsg pNoticeMess)
{
	m_NoticeMsgBuf.put(pNoticeMess);
	return;
}

void NVSNoticeThread::stop()
{
	if (m_bExit)
		return;
	m_bExit = true;
	m_NoticeMsgBuf.getoff(); //停止在缓存中等待数据
	this->getThreadControl().join();
	return;
}