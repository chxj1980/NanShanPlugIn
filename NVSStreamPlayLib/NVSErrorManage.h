#pragma once
#include ".\ztthread.h"

class NVSCoreBiz;
/*! \class NVSErrorManage
*   \brief 视频异常管理线程类
*   \author 孙靖宇
*   \version 1.0
*   \date    2008-04-09
*	\sa NVSCoreBiz,ZTThread
*/
class NVSErrorManage : public ZTThread
{
public:
	//! 构造函数
	/*!
	\return 无
	*/
	NVSErrorManage(void);
	//! 析构函数
	/*!
	\return 无
	*/
	~NVSErrorManage(void);
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

	/*!< 播放句柄 */
	HWND m_hWnd;
	/*!< 解码通道 */
	int m_nCardIndex;
	/*!< 镜头ID */
	int m_nCameraID;
	/*!< 定期检测时间间隔*/
	int m_nCheckTime;
};
