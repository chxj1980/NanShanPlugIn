#pragma once

class CStreamProcess;
class NVSHeartThread;
class NVSErrorManage;
class NVSStampCheck;
class CHSVideoProcess;

typedef vector <STREAMSERVERWORKSTATE> STREAMSERVERWORKSTATELISTTYPE;

const int MAX_PLAYNUM = 64;

struct ErrorMsg
{
	int nErrorCode;
	string sErrorMsg; 
};

typedef vector<ErrorMsg> ErrorMsgVectorType;
typedef ErrorMsgVectorType::iterator ErrorMsgItType;


class NVSCoreBiz
{
public:
	NVSCoreBiz(void);
	virtual ~NVSCoreBiz(void);
public:	
	CIniFileParam m_IniFileParam;
	ErrorMsgVectorType m_vErrorMsg;
	void initErrorMsg();
	const char *c_getErrorMsg(int nErrorCode);
public:
	bool c_initEnviroment(const char* pAddress,unsigned short nPort,int nRight, char type = BY_ICE);
	void c_cleanEnviroment();
	bool c_registerOnIndex();

	int  c_playVideoEx(int nCameraID, HWND hWnd, bool bUseDecode, bool bIsExternalDvr,string &sCameraID,void *pUsr);	
	int  c_stopPlayVideoEx(HWND hWnd, int nCameraID,string &sCameraID);
	bool c_stopPlayByCameraID(int nCameraID);//bool 量可考虑修改
	void c_stopAll();
	void updateCameraID(int nPriorID,int nSwitchID);
	bool c_clientNotice();

//可废弃的接口
	int  c_playVideo(int nCameraID, HWND hWnd, bool bUseDecode, bool bIsExternalDvr);
	bool c_stopPlayVideo(HWND hWnd, int nCardIndex, int nCameraID);
	void c_setPlayModel(int nPlayModel = 0);
	int  c_startRecord(int nCameraID, char* pFileName);//本地录像
	bool c_stopRecord(int nCameraID);
	int  c_splitFile(int nCameraID,char * sFileName,int nPriorTime, bool bIsExternalDvr);//分割录像
	//LONG c_getStreamServerWorkState(REQUESTSTREAMSTATE CameraIDArray[], int nCameraCount, int *outSize );

//需要流媒体支持的接口
	bool c_controlCameraSpeed(int nCameraID,int nCmd,bool bControl,int nSpeed);
	bool c_cancelControlCamera(HWND hWnd,int nCameraID);
	//! 预置位
	bool c_TransPTZ(int nCameraID, int nCmd, int nTransPTZIndex);
	//通道参数（主码流、子码流视频参数）
	bool c_getCompress(int nCameraID, char **lpOutBuffer);
	bool c_setCompress(int nCameraID, char* pCompressInfo);
	//视频参数（亮度、色度、饱和度等）
	bool c_getVideoEffect(int nCameraID, int* pBrightValue,int* pContrastValue, int* pSaturationValue,int* pHueValue);
	bool c_setVideoEffect(int nCameraID, DWORD dwBrightValue,DWORD dwContrastValue, DWORD dwSaturationValue,DWORD dwHueValue);
	intptr_t c_getStreamServerWorkState(int nCameraId, int nCameraCount, int *outSize );
	
//统一接口层处理的接口
	bool c_capturePictureEx(int nCameraID, char* pFileName);
	bool c_controlCameraSound(int nCameraID,bool bOpenSound);
	bool c_serialSend(int nCameraID, char* cmd1, DWORD nLen1, char* cmd2, DWORD nLen2);
	void c_setPlayDrawDevice(int nCameraID);
//HS专用
	int v_setPlayWindow(HWND palyWindow[], int nMaxCount);
public:
	typedef struct CameraInfo
	{
		int  nCameraID;
		HWND hPlayHandle; //软解播放句柄
		bool bDisconnect; //掉线标志
		bool bUseDecode; //使用标准流解码播放标识
		bool bIsExternalDvr; //是否为外部DVR
	}CAMERA_INFO;
	/*!< 保存已打开视频信息 */
	vector<CAMERA_INFO*> m_vCameraPool;
	STREAMSERVERWORKSTATE *pDataArray;
	//是否停止重新播放事件
	HANDLE m_hStopRePlay;
	char m_strIP[20];
public:
	void updateCameraInfo(int nCameraID, HWND hPlayHandle, bool bDisconnect, bool bUseDecode ,bool bIsExternalDvr);
	void removeCameraInfo(int nCameraID, HWND hWnd);

public:
	int  c_getPlayPort();
	void c_releasePlayPort(int nPort);
	char * c_getStreamServerIP( int nCameraID);
	bool IsFinded(string sIP, STREAMSERVERWORKSTATELISTTYPE &list);
	int  c_getMonitorID();
	int  c_getMonitorRight();
	/*!< 客户端保持心跳 */
	void ping();
	/*!< 验证与索引心跳 */
	bool pingIndex(); 
	/*!< 记录异常日志 */
	static void WriteSysLog(char* sLogText);
	//! 获取当前目录路径
	bool getCurrentDirectory(char* pPath);
	/*!< 获取流处理对象 nCreateFlag 不存在即创建标志 0为无此标志 1为有此标志*/
	CStreamProcess *GetProcessPtr(int nCameraID,int nCreateFlag = 0);
	//重连接功能部分

	int c_GetRecordFile(intptr_t lHandle,RECORDQUERYTYPE nType,char* startTime,char* endTime,RECORDFILE pRecordFile[],int nMaxFileCount);
	intptr_t c_ReplayRecordFile(intptr_t lHandle,HWND hWnd,char* fileName,char* startTime, char* endTime,int nFileSize);
	int c_ControlReplayRecordFile(intptr_t lHandle, intptr_t lRePlayhandle,int nCmd,int nInValue);
	bool c_StopReplayRecordFile(intptr_t lHandle, intptr_t lRePlayhandle);

	intptr_t c_DownloadRecordFile(intptr_t lHandle,char* fileName,char* startTime, char* endTime,int nFileSize,char* saveFile);
	int c_GetDownloadPos(intptr_t lHandle, intptr_t ldownloadHandle);


	bool c_StopDownloadRecordFile(intptr_t lHandle, intptr_t ldownloadHandle);
	intptr_t c_CaptureStream(int nCameraID, LPCAPTURESTREAMCALLBACK pCaptuerStreamFuc, void* pUser, int nGetVideoType = 0);

	bool c_StopCaptureStream(intptr_t lHandle);

	//string c_GetDecodeType(int nCameraID);

	bool c_GetDecodeType(int& nCameraID,char* sType);
	intptr_t c_ConnectDVR(int nCameraID);
	void c_disConnectDVR(intptr_t lHandle);


	::Ice::Identity m_id;
public:
	/*!< 视频流接受状态检测线程 */
	NVSStampCheck* m_pStampCheck;
	typedef struct ChanStamp
	{
		int nCameraID; //镜头ID
		HWND hWnd;  //播放窗口
		int nPlayModel; //播放模式
		IceUtil::Time timeStamp; //时间值
		bool bIsExternalDvr; 
	}CHAN_STAMP;
	static vector<CHAN_STAMP> m_vChanStamp;
	
	static bool register4StampCheck(int nCameraID,HWND hWnd,int nPlayMode, bool bIsExternalDvr);
	static void heartBeat4Chan(int nCameraID,HWND hWnd);
	static void unregister4StampCheck(int nCameraID,HWND hWnd,int nPlayMode);
	//检测时间戳函数
	void CheckStampTime();
	//重新播放视频
	void rePlayVideo(int nCameraID,HWND hWnd, bool bIsExternalDvr);
	/*!< 静态同步锁 */
	static CRITICAL_SECTION m_LockVectorStatic;
    //静态同步锁使用计数
	static int m_nInitCs; 
	bool m_bConnIndex; //重连索引服务
	bool m_bConnStream; //重连流媒体服务
	bool  m_bIsExternalClient;
public:
	/*! 枚举心跳时间,更多细节描述如下 . */
	enum {
		HEARTBEAT = 20		/*!< 定义与索引服务之间心跳时间为20*100毫秒 */
	};
	/*!< 客户端个人信息 */
	NVSIndex::NVSMonitorInfo m_Monitor;
	/*!< 客户端原始ID */
	int m_nOrignID;
	/*!< 连接索引服务的通道指针 */
	NVSIndex::NVSIndex4MonitorPrx m_NVSIndex4MonitorPrx;
	/*!< 连接索引服务Stream的通道指针 *///new 
	NVSIndex::NVSIndex4StreamPrx  m_NVSIndex4StreamPrx;
	/*!< 是否注册上索引服务 */
	bool m_bRegisterOnIndex;
	/*!< 是否初始化环境 */
	bool m_bInitEnviroment;
	/*!< 索引服务连接字符串 */
	char m_sDynamicPath[256];
	/*!< 索引服务连接Stream字符串 */
	char m_sDynamicPathStream[256];
	/*!< 软解播放句柄集 */
	vector<int> m_vRealPlayPort;
public:
	/*!< 系统ICE连接对象 */
	static Ice::CommunicatorPtr m_Communicator;
	/*!< 工作类型 */
	char  m_nWorkStyle;
	/*!< 心跳线程 */
	NVSHeartThread* m_pHeartThread;
	/*!< 视频异常管理线程类 */
	NVSErrorManage* m_pErrorManage;
	/*!< 华三播放类 */
	CHSVideoProcess *m_pHSVideoProcss;
	/*!< 视频播放模式 */
	int  m_nSysPlayModel;
public:
	/*!< 软解播放回调函数指针 */
	RealPlayCallBack m_pPlayCallBack;
	/*!< 软解获取标准流回调函数指针 */
	LPDecCBFun m_pRealDecodeCallBack;
	/*!< 软解获取实时视频头回调函数指针 */
	LPVedioHeadStreamCBFun m_pVedioHeadStreamCB;
	/*!< 软解获取实时视频流回调函数指针 */
	LPVedioBodyStreamCBFun m_pVedioBodyStreamCB;
	/*!< 预览画面叠加字符和图像回调函数指针 */
	LPDrawCBFun m_pDrawCB;
	/*! 索引通知回调函数指针 */
	IndexNoticeCallBack m_IndexNoticeCallBack;
	/*! 登录DVDR通知回调函数指针 */
	DVRNoticeCallBack m_DVRNoticeCallBack;
	/*! VIS被切换通知回调函数指针 */
	NoticeSwitchedCallBack  m_NoticeSwitchedCallBack;
public:
	//针对每个资源使用一个临界区对象，解决出现锁错误的情况
	CRITICAL_SECTION m_Lock_RealPlayPort;
	CRITICAL_SECTION m_Lock_StreamServicePool;
    CRITICAL_SECTION m_Lock_ErrorStreamPool;
	CRITICAL_SECTION m_Lock_CameraPool;

	/*LONG m_nConnect;
	long m_lRePlayhandle;*/
	/*long m_ldownloadHandle;
	LONG m_nRealHandle;*/
	map<string, intptr_t> m_vDVRPool;
	CRITICAL_SECTION m_LockDVRPool;

};
