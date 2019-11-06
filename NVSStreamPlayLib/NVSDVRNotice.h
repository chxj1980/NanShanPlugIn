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
	//线程函数
	virtual void run();
	//加入消息对象
	void add(DVRNoticeData pDVRNoticeData);
	//停止
	void stop();

private:
	//响应消息
	CommDataBuf<DVRNoticeData> m_DVRNoticeDataBuf;
	//是否退出
	bool m_bExit;
};

typedef IceUtil::Handle<NVSDVRNotice> NVSDVRNoticePtr;
