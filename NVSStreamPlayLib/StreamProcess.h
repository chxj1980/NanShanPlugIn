#pragma once
class CSourceSvrInfomation;
#include "NVSStreamServiceAPI.h"
using namespace NVSStreamService;

class NVSStreamDataReceiverExI;


class CStreamProcess
{
public:
	CStreamProcess(int nCameraID,string sCameraID,CSourceSvrInfomation *pInfomation);
	~CStreamProcess(void);
public:
//接口操作
	int  RequestVideoICE(ServerInfo svrInfo,::NVSStreamService::DeviceInfo devinfo,::NVSIndex::NVSDVRInfo dvrInfo,HWND hWnd, 
		RealPlayCallBack pRealFun,bool bUseDecode, LPDecCBFun pDecFun, bool bIsExternalDvr);
	int  CaptureStream(ServerInfo svrInfo,::NVSStreamService::DeviceInfo devinfo, bool bIsExternalDvr);
	int  DoCaptureStream(ServerInfo svrInfo,::NVSStreamService::DeviceInfo devinfo, bool bIsExternalDvr);
	int  StopCaptureStream();
	int  SoftSolution(HWND hWnd);
	int  StopSoftSolution(HWND hWnd, int nCameraID=0);
	int  StopAllSoftSolution();
	int  ReconnectCaptureStream();
	int  GetKeyInfo(int nCameraID,string& sKey,ServerInfo& svrinfo);
//非软解操作
	bool CapturePicture(char* pFileName);
	//! 开始本地录像
	int startRecord(char* pFileName);
	//! 停止本地录像
	bool stopRecord();

	int setFileHandle(char* sFileName);

	bool ControlCameraSound(bool bOpenSound);

	bool ControlCameraSpeed(int nCameraID,int nCmd,bool bControl,int nSpeed);

	void v_setPlayDrawDevice();

//回调传流
	int  initHead(const StreamPiece& sd);
	int  inputData(const StreamPiece& sd);
	static  void  CALLBACK DrawFunCallBack(intptr_t  identify, intptr_t lRealHandle, DWORD hdc, void *pUser);

//设置内参函数
	//设置使用时间戳
	int  SetUsedTimeStamp();
	int  CheckUsedTimeStamp();
	int  CheckCameraID(int nCameraID,string sCameraID);
	void SetStreamHeadData(const StreamPiece &pContent);
	int getCameraID();
	int updateCameraID(int nCameraID);
	//设置错误信息
	int  SetErrorManageInfo(HWND hWnd);
private:
	int m_nCameraID;
	string m_sCameraID;
	IceUtil::Time m_timeU;
	CSourceSvrInfomation *m_pInfomation;
//ICE 参数
	/*!< ICE流媒体代理 */
	NVSStreamServiceAPIPrx m_LocalProxy;
	/*!< ICE流媒体客户端适配器 */
	Ice::ObjectAdapterPtr m_NVSSreamServiceAPIAdapter;
	/*!< 流媒体信息 */
	ServerInfo m_SvrInfo;
	/*!< 请求视频成功，但还未收到头数据，等待头数据标识 */
	bool m_bWaitHeadData;
	/*!< 请求视频成功，但还未收到头数据，等待头数据事件 */
	HANDLE m_hWaitHead;
	/*!< 播放返回关键字,关闭时使用 */
	string     m_sKey;
	/*!< 通道唯一标识 */
	Ice::Identity m_DataReceiverIdentity;
	/*!< 接收通道指针 */
	NVSStreamDataReceiverExI* m_pDataReceiver;
private:
//软解使用参数
	/*!< 采用解码获取标准流视频模式标识 */
	bool m_bUseDecodeMode;
	/*!< 视频流头 */
	NVSStreamService::StreamPiece m_vHead;
	/*!< 所用的SDK */
	string m_sDllKey;
	/*!< 内外网标志 */
	bool m_bIsExternalDvr;
	/*!< 设备信息 流媒体使用 */
	::NVSStreamService::DeviceInfo m_devinfo;
	/*!< 设备信息 流媒体使用 */
	string m_sChanStrIndex;
	/*!< 解码类型 */
	string m_sDeCodeType;
	/*!< 编码类型 */
	string m_sOpenType;

	/*!< 软解播放结果回调函数指针 */
	RealPlayCallBack m_pRealPlayCallBack;
	/*!< 标准视频格式数据流回调指针 */
	LPDecCBFun m_pStandardCallBack;
private:
	/*! \struct WINPORTPLAYHANDLE
	*   \brief 定义播放结构
	*	\sa NVSVideoProcess
	*/
	struct WINPORTPLAYHANDLE
	{
		/*! 窗口句柄 */
		HWND Wnd;
		/*! 镜头ID*/
		int nCameraID;
		/*! 软播放句柄 */
		intptr_t PlayHandle;
		/*! 端口 */
		int  Port;
		/*! 录像文件名称 */
		char* pFileName;
		/*! 录像状态 0-无录像 1-正在录像 2-录像已停止*/
		int nRecordState;
		/*! 录像文件句柄 */
		HANDLE hFileHandle;

		WINPORTPLAYHANDLE()
		{
			Wnd = NULL;
			nCameraID = 0;
			PlayHandle = 0;
			Port = 0;
			pFileName  = NULL;
			nRecordState = 0;
			hFileHandle  = NULL;
		}
	};
	/*!< 播放窗口池 */
	vector<WINPORTPLAYHANDLE> m_vWPPH;
	//针对每个资源使用一个临界区对象，解决出现锁错误的情况
	CRITICAL_SECTION m_Lock_WPPH;
	//播放窗口池操作
	int UpdatePlayInfo(HWND hWnd,intptr_t PlayHandle,int  Port);
public:
	int checkContainWnd(HWND hWnd);
	int getCameraPlayCount();
};
