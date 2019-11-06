#pragma once
#include "NVSMonitorNotifier.h"
#include "NVSDVRNotice.h"

class NVSMonitorNotifierI : public NVSStreamService::NVSMonitorNotifier
{
public:
	NVSMonitorNotifierI(void);
	~NVSMonitorNotifierI(void);

public:
	virtual void monitorNotify(const ::NVSStreamService::NotifierData&,const ::Ice::Current&);

private:
	//通知DVR消息线程对象
	NVSDVRNoticePtr m_DVRNoticePtr;

};
typedef IceUtil::Handle<NVSMonitorNotifierI> NVSMonitorNotifierIPtr;