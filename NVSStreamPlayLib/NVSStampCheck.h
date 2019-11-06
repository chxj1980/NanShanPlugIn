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
	//! 线程开启
	/*!
	\return 无
	*/
	//void Start();
	//! 线程结束
	/*!
	\return 无
	*/
	//void End();
	//! 线程函数

	virtual unsigned long Main(void * pParam);

	/*!< 是否需要破坏 */
	bool m_bDestroy;
	/*!< 输入参数 */
	HANDLE m_hSuspend;
	NVSCoreBiz* m_pNVSCoreBiz;

};

