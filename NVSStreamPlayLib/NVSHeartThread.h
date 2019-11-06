#pragma once
#include ".\ztthread.h"

class NVSCoreBiz;
/*! \class NVSHeartThread
*   \brief �����߳�
*   \author �ﾸ��
*   \version 1.0
*   \date    2008-03-25
*	\sa NVSCoreBiz,ZTThread
*/
class NVSHeartThread :
	public ZTThread
{
public:
	//! ���캯��
	/*!
	\return ��
	*/
	NVSHeartThread(void);
	//! ��������
	/*!
	\return ��
	*/
	~NVSHeartThread(void);
public:
	//! �̺߳���
	/*!
	\param pParam �������.
	\return �߳��˳�ֵ
	*/
	virtual unsigned long Main(void * pParam);
	/*!< �Ƿ���Ҫ�ƻ� */
	bool m_bDestroy;
	/*!< ������� */
	HANDLE m_hSuspend;
	/*!< ������� */
	NVSCoreBiz* m_pNVSCoreBiz;
};
