#pragma once
#include "iceutil\thread.h"
#include "NVSCommDataBuf.h"

class NVSDVRNotice :
	public IceUtil::Thread,public IceUtil::Mutex
{
public:
	NVSDVRNotice(void);
public:
	~NVSDVRNotice(void);

public:
	//�̺߳���
	virtual void run();
	//������Ϣ����
	void add(DVRNoticeData pDVRNoticeData);
	//ֹͣ
	void stop();

private:
	//��Ӧ��Ϣ
	CommDataBuf<DVRNoticeData> m_DVRNoticeDataBuf;
	//�Ƿ��˳�
	bool m_bExit;
};

typedef IceUtil::Handle<NVSDVRNotice> NVSDVRNoticePtr;
