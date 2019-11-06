#pragma once

#include "NVSIndex4Monitor.h"
#include "NVSNoticeThread.h"
#include "NVSRightNoticeThread.h"

class NVSIndexNoticeI :
	public NVSIndex::NVSIndexNotice
{
public:
	NVSIndexNoticeI(void);
	~NVSIndexNoticeI(void);

public:
	//用户权限发生变化通知消息
	virtual bool notifyClient(const ::NVSIndex::IndexNoticeInfo& NoticeInfo,const ::Ice::Current& = ::Ice::Current());
	//索引通知视频被切换
	virtual bool notifySwitched(::Ice::Int nMonitorID, ::Ice::Int nPriorCameraID, ::Ice::Int nCameraID, const ::std::string& sDescription, const ::Ice::Current& ct = ::Ice::Current());

private:
	//通知被抢占消息记录
	NVSNoticeThreadPtr m_NoticeMsgPtr;

	//通知权限变化消息记录
	NVSRightNoticeThreadPtr m_RightNoticePtr;
};

typedef IceUtil::Handle<NVSIndexNoticeI> NVSIndexNoticeIPtr;
