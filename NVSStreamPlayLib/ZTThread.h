#pragma once
/*! \class ZTThread
*   \brief 线程基类
*   \author 郑峰
*   \version 1.0
*   \date    2007-2010
*/
class ZTThread
{
public:
	//! 构造函数
	/*!
	\return 无
	*/
	ZTThread(void);
	//! 析构函数
	/*!
	\return 无
	*/
	~ZTThread(void);
public:
	//! 创建线程
	/*!
	\param pParam 输入参数.
	\param bSuspend 创建线程之后是否挂起.
	\return 无
	*/
	void CreateThread(void * pParam = 0,bool bSuspend = false);
	//! 线程开启
	/*!
	\return 无
	*/
	void Start();
	//! 线程结束
	/*!
	\return 无
	*/
	void End();
	//! 线程函数
	/*!
	\param pParam 输入参数.
	\return 线程退出值
	*/
	virtual unsigned long Main(void * pParam);
	//! 等待
	/*!
	\param dwMilliseconds 等待事件最大秒数.
	\return 等待结果
	*/
	unsigned long  Wait(unsigned long dwMilliseconds = 0xFFFFFFFF) {
		return WaitForSingleObject(m_hThread,dwMilliseconds);
	}
	//! 线程恢复
	/*!
	\return 恢复结果
	*/
	unsigned long Resume() {
		return ResumeThread(m_hThread);
	}
	//! 线程挂起
	/*!
	\return 挂起结果
	*/
	unsigned long Suspend() {
		return SuspendThread(m_hThread);
	}
	/*!< 线程句柄 */
	HANDLE m_hThread;
	/*!< 线程ID */
	unsigned long m_dwThreadID;
	/*!< 输入参数 */
	void * m_pParam;
	/*!< 线程函数是否退出 */
	volatile bool m_bExit;

protected:
	//! 线程函数
	/*!
	\param lpParameter 输入参数.
	\return 执行完毕结果
	*/
	static unsigned long __stdcall ThreadProc(void* lpParameter);
	
};
