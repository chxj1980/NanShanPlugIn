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
	//�û�Ȩ�޷����仯֪ͨ��Ϣ
	virtual bool notifyClient(const ::NVSIndex::IndexNoticeInfo& NoticeInfo,const ::Ice::Current& = ::Ice::Current());
	//����֪ͨ��Ƶ���л�
	virtual bool notifySwitched(::Ice::Int nMonitorID, ::Ice::Int nPriorCameraID, ::Ice::Int nCameraID, const ::std::string& sDescription, const ::Ice::Current& ct = ::Ice::Current());

private:
	//֪ͨ����ռ��Ϣ��¼
	NVSNoticeThreadPtr m_NoticeMsgPtr;

	//֪ͨȨ�ޱ仯��Ϣ��¼
	NVSRightNoticeThreadPtr m_RightNoticePtr;
};

typedef IceUtil::Handle<NVSIndexNoticeI> NVSIndexNoticeIPtr;
