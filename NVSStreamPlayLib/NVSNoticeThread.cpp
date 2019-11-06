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
			//�ڱ������û���ռʱ������Ҫ���¾�ͷ��Ϣ������Ҳû������ lixq 20110523
			if (notice.nPriorCameraID != 0 && notice.nCameraID != 0 && notice.sDescrip == "��Ƶͨ������ռ")
			{
				//VIS��ͷ����ռʱ�����¾�ͷ��Ϣ
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
	m_NoticeMsgBuf.getoff(); //ֹͣ�ڻ����еȴ�����
	this->getThreadControl().join();
	return;
}