#pragma once
/*! \class ZTThread
*   \brief �̻߳���
*   \author ֣��
*   \version 1.0
*   \date    2007-2010
*/
class ZTThread
{
public:
	//! ���캯��
	/*!
	\return ��
	*/
	ZTThread(void);
	//! ��������
	/*!
	\return ��
	*/
	~ZTThread(void);
public:
	//! �����߳�
	/*!
	\param pParam �������.
	\param bSuspend �����߳�֮���Ƿ����.
	\return ��
	*/
	void CreateThread(void * pParam = 0,bool bSuspend = false);
	//! �߳̿���
	/*!
	\return ��
	*/
	void Start();
	//! �߳̽���
	/*!
	\return ��
	*/
	void End();
	//! �̺߳���
	/*!
	\param pParam �������.
	\return �߳��˳�ֵ
	*/
	virtual unsigned long Main(void * pParam);
	//! �ȴ�
	/*!
	\param dwMilliseconds �ȴ��¼��������.
	\return �ȴ����
	*/
	unsigned long  Wait(unsigned long dwMilliseconds = 0xFFFFFFFF) {
		return WaitForSingleObject(m_hThread,dwMilliseconds);
	}
	//! �ָ̻߳�
	/*!
	\return �ָ����
	*/
	unsigned long Resume() {
		return ResumeThread(m_hThread);
	}
	//! �̹߳���
	/*!
	\return ������
	*/
	unsigned long Suspend() {
		return SuspendThread(m_hThread);
	}
	/*!< �߳̾�� */
	HANDLE m_hThread;
	/*!< �߳�ID */
	unsigned long m_dwThreadID;
	/*!< ������� */
	void * m_pParam;
	/*!< �̺߳����Ƿ��˳� */
	volatile bool m_bExit;

protected:
	//! �̺߳���
	/*!
	\param lpParameter �������.
	\return ִ����Ͻ��
	*/
	static unsigned long __stdcall ThreadProc(void* lpParameter);
	
};
