#pragma once
#include "iceutil\thread.h"
#include "NVSCommDataBuf.h"

class NVSNoticeThread :
	public IceUtil::Thread,public IceUtil::Mutex
{
public:
	NVSNoticeThread(void);
public:
	~NVSNoticeThread(void);


public:
	//�̺߳���
	virtual void run();
	//������Ϣ����
	void add(NoticeMsg pRepMess);
	//ֹͣ
	void stop();

private:
	//��Ӧ��Ϣ
	CommDataBuf<NoticeMsg> m_NoticeMsgBuf;
	//�Ƿ��˳�
	bool m_bExit;
};

typedef IceUtil::Handle<NVSNoticeThread> NVSNoticeThreadPtr;
