#pragma once
#include ".\ztthread.h"

class NVSCoreBiz;
/*! \class NVSHeartThread
*   \brief 心跳线程
*   \author 孙靖宇
*   \version 1.0
*   \date    2008-03-25
*	\sa NVSCoreBiz,ZTThread
*/
class NVSHeartThread :
	public ZTThread
{
public:
	//! 构造函数
	/*!
	\return 无
	*/
	NVSHeartThread(void);
	//! 析构函数
	/*!
	\return 无
	*/
	~NVSHeartThread(void);
public:
	//! 线程函数
	/*!
	\param pParam 输入参数.
	\return 线程退出值
	*/
	virtual unsigned long Main(void * pParam);
	/*!< 是否需要破坏 */
	bool m_bDestroy;
	/*!< 输入参数 */
	HANDLE m_hSuspend;
	/*!< 输入参数 */
	NVSCoreBiz* m_pNVSCoreBiz;
};
