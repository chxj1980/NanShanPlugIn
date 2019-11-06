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
	//线程函数
	virtual void run();
	//加入消息对象
	void add(NoticeMsg pRepMess);
	//停止
	void stop();

private:
	//响应消息
	CommDataBuf<NoticeMsg> m_NoticeMsgBuf;
	//是否退出
	bool m_bExit;
};

typedef IceUtil::Handle<NVSNoticeThread> NVSNoticeThreadPtr;
