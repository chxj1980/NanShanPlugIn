#pragma once
#include ".\ztthread.h"

#include <deque>
#include <vector>
using namespace std;

class NVSCoreBiz;
class NVSStampCheck :	
	public ZTThread
{
public:
	NVSStampCheck(void);
	~NVSStampCheck(void);

public:
	//! �߳̿���
	/*!
	\return ��
	*/
	//void Start();
	//! �߳̽���
	/*!
	\return ��
	*/
	//void End();
	//! �̺߳���

	virtual unsigned long Main(void * pParam);

	/*!< �Ƿ���Ҫ�ƻ� */
	bool m_bDestroy;
	/*!< ������� */
	HANDLE m_hSuspend;
	NVSCoreBiz* m_pNVSCoreBiz;

};

