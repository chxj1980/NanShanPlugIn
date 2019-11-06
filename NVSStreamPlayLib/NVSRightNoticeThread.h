#pragma once
#include "iceutil\thread.h"
#include "NVSCommDataBuf.h"

class NVSRightNoticeThread :
	public IceUtil::Thread
{
public:
	NVSRightNoticeThread(void);
public:
	~NVSRightNoticeThread(void);

public:
	//�̺߳���
	virtual void run();
	//������Ϣ����
	void add(RightNotice pRightMess);
	//ֹͣ
	void stop();

private:
	//��Ӧ��Ϣ
	CommDataBuf<RightNotice> m_RightNoticeBuf;
	//�Ƿ��˳�
	bool m_bExit;
};

typedef IceUtil::Handle<NVSRightNoticeThread> NVSRightNoticeThreadPtr;