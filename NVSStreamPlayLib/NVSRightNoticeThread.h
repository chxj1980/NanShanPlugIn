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
	//线程函数
	virtual void run();
	//加入消息对象
	void add(RightNotice pRightMess);
	//停止
	void stop();

private:
	//响应消息
	CommDataBuf<RightNotice> m_RightNoticeBuf;
	//是否退出
	bool m_bExit;
};

typedef IceUtil::Handle<NVSRightNoticeThread> NVSRightNoticeThreadPtr;