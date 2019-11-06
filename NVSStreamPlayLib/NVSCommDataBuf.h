#pragma once

#include <IceUtil/Monitor.h>
#include <list>
using namespace std;

//DVR通知消息
typedef struct tagDVRNoticeData
{
	int nCameraID;
	int nErr;

	tagDVRNoticeData()
	{
		//镜头ID
		nCameraID = 0;
		//错误值
		nErr = 0;
	}

}DVRNoticeData;

//后台用户权限变化时的通知信息
typedef struct __tagRightNotice
{
	int nUserID;
	int nChangeType;
	int nLimitTime;

	__tagRightNotice()
	{
		nUserID = 0;
		nChangeType = 0;
		nLimitTime = 0;
	}
}RightNotice;



//通知抢占信息
typedef struct __tagNoticeMsg
{
	int nIndexID; //用户ID
	int nPriorCameraID; //原有的镜头ID
	int nCameraID; //现在的镜头ID
	string sDescrip; //消息描述

	__tagNoticeMsg()
	{
		nIndexID = 0; //用户ID
		nPriorCameraID = 0; //原有的镜头ID
		nCameraID = 0; //现在的镜头ID
		sDescrip = ""; //消息描述  
	}
}NoticeMsg;


//不要将.h和.cpp分离。编译会有问题
template<class T> class CommDataBuf : public IceUtil::Monitor<IceUtil::Mutex>
{
public:
	CommDataBuf()
	{
		m_bExit = false;
	}
	~CommDataBuf(){}
public:
	void put(const T& item)
	{
		IceUtil::Monitor<IceUtil::Mutex>::Lock lock(*this);
		_q.push_back(item);
		if (_q.size() == 1)
			notify();
	}
	T get()
	{
		IceUtil::Monitor<IceUtil::Mutex>::Lock lock(*this);
		while (!m_bExit && _q.size() == 0)
			wait();
		if (m_bExit)
		{
			T nullitem;
			return nullitem;
		}
		T item = _q.front();
		_q.pop_front();
		return item;
	}
	void getoff()
	{
		IceUtil::Monitor<IceUtil::Mutex>::Lock lock(*this);
		m_bExit = true;
		notify();
	}
	int getsize()
	{
		IceUtil::Monitor<IceUtil::Mutex>::Lock lock(*this);
		return _q.size();
	}
private:
	list<T> _q;
	bool m_bExit;
};