#pragma once

#include <IceUtil/Monitor.h>
#include <list>
using namespace std;

//DVR֪ͨ��Ϣ
typedef struct tagDVRNoticeData
{
	int nCameraID;
	int nErr;

	tagDVRNoticeData()
	{
		//��ͷID
		nCameraID = 0;
		//����ֵ
		nErr = 0;
	}

}DVRNoticeData;

//��̨�û�Ȩ�ޱ仯ʱ��֪ͨ��Ϣ
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



//֪ͨ��ռ��Ϣ
typedef struct __tagNoticeMsg
{
	int nIndexID; //�û�ID
	int nPriorCameraID; //ԭ�еľ�ͷID
	int nCameraID; //���ڵľ�ͷID
	string sDescrip; //��Ϣ����

	__tagNoticeMsg()
	{
		nIndexID = 0; //�û�ID
		nPriorCameraID = 0; //ԭ�еľ�ͷID
		nCameraID = 0; //���ڵľ�ͷID
		sDescrip = ""; //��Ϣ����  
	}
}NoticeMsg;


//��Ҫ��.h��.cpp���롣�����������
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