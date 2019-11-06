#pragma once
#include ".\ztthread.h"

class NVSCoreBiz;
/*! \class NVSErrorManage
*   \brief ��Ƶ�쳣�����߳���
*   \author �ﾸ��
*   \version 1.0
*   \date    2008-04-09
*	\sa NVSCoreBiz,ZTThread
*/
class NVSErrorManage : public ZTThread
{
public:
	//! ���캯��
	/*!
	\return ��
	*/
	NVSErrorManage(void);
	//! ��������
	/*!
	\return ��
	*/
	~NVSErrorManage(void);
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

	/*!< ���ž�� */
	HWND m_hWnd;
	/*!< ����ͨ�� */
	int m_nCardIndex;
	/*!< ��ͷID */
	int m_nCameraID;
	/*!< ���ڼ��ʱ����*/
	int m_nCheckTime;
};
