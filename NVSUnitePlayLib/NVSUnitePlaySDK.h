#ifndef __NVSUNITEPLAYSDK_H__
#define __NVSUNITEPLAYSDK_H__

#include "nvssdkfunctions.h"
#include <vector>
using namespace std;

#ifdef _USRDLL
#define NVSUNITEPLAY_API extern "C" __declspec(dllexport)
#else
#define NVSUNITEPLAY_API extern "C" __declspec(dllimport)
#endif

/*! 定义DLL模式Windows请求为0 */
#define PLAYLIB_WIN 0
/*! 定义DLL模式Linux  请求为1 */
#define PLAYLIB_LUX	1

/*! 软解播放结果回调指针 */ 
/*!
\param nCameraID 对应镜头
\param nRe 回调播放状态 0-播放成功 -1调用播放库播放失败 -2初始化播放库失败 -3获取播放端口失败 -4头数据为空
*/
typedef void (CALLBACK * RealPlayCallBack)(int nCameraID, int nRe/*实际播放结果*/);
/*! 硬解播放结果回调指针 */
typedef void (CALLBACK * PlayResultByDecordCard)(int,int,int/* 0播放成功； 1打开流失败 2播放失败*/);
typedef void (CALLBACK *LPDecCBFun)(long nPort,char * pBuf,long nSize,FRAME_INFO_D * pFrameInfo, int nCameraID);
/*! 索引通知回调指针
\param nUserID;     //用户ID
\param nChangeType; //更改类型
\param nLimitTime;  //限时重启时间
*/
typedef void (CALLBACK *IndexNoticeCallBack)(int nUserID, int nChangeType, int nLimitTime);

/*! 登录DVR通知回调指针
\param nCameraID;     //镜头ID
\param nErr;          //错误码
*/
typedef void (CALLBACK *DVRNoticeCallBack)(int nCameraID, int nErr);

//! 华3用户回调函数.
/*!
\param sUser 用户名.
\param sPass 密码.
\param bGetUser 为true时，取华3用户；为false时，释放华3用户.
\return 是否成功
*/
typedef bool (CALLBACK* HsUserCallBack)(char* sUser,char* sPass,bool bGetUser);

/*! 实时视频头回调指针
\param  pBuf;     //缓冲
\param  nSizeint  //缓冲大小
\praram nCameraID //镜头ID
*/

typedef void (CALLBACK *LPVedioHeadStreamCBFun)(BYTE * pBuf,long nSizeint, int  nCameraID);

/*! 实时视频流回调指针
\param  pBuf;     //缓冲
\param  nSizeint  //缓冲大小
\praram nCameraID //镜头ID
*/
typedef void (CALLBACK *LPVedioBodyStreamCBFun)(BYTE * pBuf,long nSizeint, int  nCameraID);

/*! 视频被切换通知回调指针
\param nUserID;       //用户ID
\param nCameraID;     //镜头ID
*/
/*! 预览画面叠加字符和图像
\param lRealHandle NET_DVR_RealPlay()或NET_DVR_RealPlay_V30()的返回值 
\param hDc 画图句柄
\param nCameraID 镜头ID
*/
typedef void (CALLBACK *LPDrawCBFun)(intptr_t lRealHandle, DWORD hDc, int nCameraID);

typedef void (CALLBACK *NoticeSwitchedCallBack)(int nUserID,int nPriorCameraID,int nCameraID,char* pDesc);


//! [00] 选择DLL模式
/*!
\param cType 0-DLL Windows 1-Linux
\return 无
*/
NVSUNITEPLAY_API void nvs_selectLib(char cType = PLAYLIB_WIN);
//! [01] 初始化业务逻辑核心模块
/*!
\param pAddress 索引服务地址.
\param nPort 索引服务端口.
\param type ICE通讯方式.
\param nRight 权限值.
\return 初始化成功与否
*/
NVSUNITEPLAY_API bool nvs_initEnviroment(const char* pAddress,unsigned short nPort,int nRight, char type);
//! [02] 清理业务逻辑核心环境.
/*!
\return 无
*/
NVSUNITEPLAY_API void nvs_cleanEnviroment();
//! [03] 客户端注册上索引服务.
/*!
\return 注册结果
*/
NVSUNITEPLAY_API bool nvs_registerOnIndex();
//! [04] 设置播放模式.
/*!
\param nPlayModel /0-软解播放 1-硬解播放 2-集中存储.
\return 无
*/
NVSUNITEPLAY_API void nvs_setPlayModel(int nPlayModel);
/*! 设置回调函数 */
NVSUNITEPLAY_API void nvs_setDecordCardCallBack(PlayResultByDecordCard pFun);
NVSUNITEPLAY_API void nvs_setRealPlayCallBack(RealPlayCallBack pFun);
NVSUNITEPLAY_API void nvs_setRealDecodeCallBack(LPDecCBFun pFun);
NVSUNITEPLAY_API void nvs_setIndexNoticeCallBack(IndexNoticeCallBack pFun);
NVSUNITEPLAY_API void nvs_setDVRNoticeCallBack(DVRNoticeCallBack pFun);

//! [35] 设置VIS回调函数
/*!
\param pFun 回调函数指针
*/
NVSUNITEPLAY_API void nvs_setNoticeSwitchedCallBack(NoticeSwitchedCallBack pFun);

//! [05] 客户端硬解播放
/*!
\param nCameraID 请求控制的摄像头ID
\param nCardIndex 硬解播放的卡序号
\return 请求播放结果 0-播放成功 -1流媒体获取适配器失败 -2该窗体已被占用 -3请求流媒体失败 -4播放出现异常 -5正在等待头数据
*/
NVSUNITEPLAY_API int nvs_playVideoByDecordCard(int nCameraID,int nCardIndex, HANDLE* hStreamPlayHandle);
//! [07] 客户端软解播放
/*!
\param nCameraID 摄像头ID
\param hWnd 播放的窗口句柄
\param bUseDecode 获取标准流标识
\return 请求播放结果 0-请求播放成功 -1流媒体获取适配器失败 -2该窗体已被占用 -3请求流媒体失败 -4播放出现异常 -5正在等待头数据 -6未注册索引服务 -7未设置标准流回调
*/
NVSUNITEPLAY_API int nvs_playVideo2(int nCameraID,HWND hWnd, bool bUseDecode/*获取标准流标识*/, bool bIsExternalDvr );

NVSUNITEPLAY_API int nvs_playVideo(int nCameraID,HWND hWnd, bool bUseDecode/*获取标准流标识*/);
//! [08] 客户端关闭某窗口的播放
/*!
\param hWnd 播放的窗口句柄
\return 无
*/
NVSUNITEPLAY_API bool nvs_stopPlayVideo(HWND hWnd, int nCardIndex, int nCameraID);

NVSUNITEPLAY_API bool nvs_stopPlayByCameraID(int nCameraID);
//! [09] 客户端关闭所有窗口播放
/*!
\return 无
*/
NVSUNITEPLAY_API void nvs_stopAll();
//! [11] 客户端控制摄像头(带控制速度)
/*!
\param nCameraID 请求控制的摄像头ID
\param nCmd 控制标志
\param bControl 启停
\return 返回控制成功与否
\nSpeed 控制速度值1-15级别
*/
NVSUNITEPLAY_API bool nvs_controlCameraSpeed(int nCameraID,int nCmd,bool bControl,int nSpeed);
//! [12] 自动注销PTZ控制权限
NVSUNITEPLAY_API bool nvs_cancelControlCamera(HWND hWnd,int nCameraID);

//! [13] 抓图
NVSUNITEPLAY_API bool nvs_capturePictureEx(int nCameraID, char* pFileName);
//! [14] 预置位
NVSUNITEPLAY_API bool nvs_TransPTZ(int nCameraID, int nCmd, int nTransPTZIndex);
//! [15] 获取通道参数（主码流、子码流视频参数）
NVSUNITEPLAY_API bool nvs_getCompress(int nCameraID, char **lpOutBuffer);
//! [16] 设置通道参数
NVSUNITEPLAY_API bool nvs_setCompress(int nCameraID, char* pCompressInfo);
//! [17] 获取视频参数（亮度、色度、饱和度等）
NVSUNITEPLAY_API bool nvs_getVideoEffect(int nCameraID, int* pBrightValue,int* pContrastValue, int* pSaturationValue,int* pHueValue);
//! [18] 设置视频参数
NVSUNITEPLAY_API bool nvs_setVideoEffect(int nCameraID, DWORD dwBrightValue,DWORD dwContrastValue, DWORD dwSaturationValue,DWORD dwHueValue);
//! [19] 开始本地录像
/*!
\return [-1]未注册索引
[-2]查找已连接流媒体失败或异常
[-3]未注册流媒体服务
[-4]查找VideoProcess失败
[-5]查找指定窗体视频失败
[-6]生成录像文件失败
[-7]文件头为空,写入头文件失败
[0]成功
[1]已在录像

*/
NVSUNITEPLAY_API int  nvs_startRecord(int nCameraID, char* pFileName);
//! [20] 停止本地录像
NVSUNITEPLAY_API bool nvs_stopRecord(int nCameraID);
//! [21] 使用透明通道
NVSUNITEPLAY_API bool nvs_serialSend(int nCameraID, char* cmd1, DWORD nLen1, char* cmd2, DWORD nLen2);
//! [22] 刷新重设视频播放使用监视器
NVSUNITEPLAY_API void nvs_reSetDDrawDevice(int nCameraID);
//! [23] 分割录像文件
//NVSSTREAMPLAY_API HANDLE nvs_splitFile(HWND hWnd,char * sFileName);
NVSUNITEPLAY_API int nvs_splitFile(int nCameraID,char* sFileName,int nPriorTime);
//! [24] 集中存储播放
/*!
\param nCameraID 摄像头ID
\param sFileName 存储文件名
\return 请求播放结果 0-请求播放成功 -1流媒体获取适配器失败 -2该窗体已被占用 -3请求流媒体失败 -4播放出现异常 -5正在等待头数据 -6未注册索引服务 -7未设置标准流回调
*/
NVSUNITEPLAY_API int nvs_play4Storage(int nCameraID,char* sFileName,int nPriorTime);
//! [25] 集中存储播放停止
/*!
\param nCameraID 摄像头ID
*/
NVSUNITEPLAY_API bool nvs_stopPlay4Storage(int nCameraID);
//! [26] 控制摄像头视频声音
/*!
\param nCameraID 镜头ID.
\param bOpenSound 设置状态 0-关闭声音 1-打开声音
\return 开启声音是否成功
*/
NVSUNITEPLAY_API bool nvs_controlCameraSound(int nCameraID, bool bOpenSound);
//! [27]客户端通知回调对象建立完成
/*!
*/
NVSUNITEPLAY_API bool nvs_clientNotice();
//! [28]获取流媒体工作状态
/*!
\param nCameraID (In)镜头ID
\param nCameraCount (In)镜头个数
\param outSize (Out)流媒体状态数组个数
\return StreamServerWorkState结构
*/

NVSUNITEPLAY_API intptr_t nvs_getStreamServerWorkState(int nCameraID, int nCameraCount, int *outSize );
//! [29]获取
/*!
*/
NVSUNITEPLAY_API char * nvs_getStreamServerIP( int nCameraID);
//! [30]设置是否为外网客户端
/*!
\param bIsExternal: 如果客户端在外网，则设置为true
*/
NVSUNITEPLAY_API void nvs_SetExternalClient(bool bIsExternal);
//! [31]写日志专为Linux增加的接口
/*!
\param
*/
NVSUNITEPLAY_API void nvs_writeLog(char* logMsg, int level);

//! [31]设置实时视频头回调函数
NVSUNITEPLAY_API void nvs_SetVedioHeadStreamCallBack(LPVedioHeadStreamCBFun pFun);

//! [32]设置实时视频流回调函数
NVSUNITEPLAY_API void nvs_SetVedioBodyStreamCallBack(LPVedioBodyStreamCBFun pFun);
//! [33]设置预览画面叠加字符和图像回调函灵敏
NVSUNITEPLAY_API void nvs_SetDrawFun(LPDrawCBFun pFun);

//! [33]设置华3用户回调函数.
/*!
\param CallbackFun 华3回调函数指针.
\return 无
*/
NVSUNITEPLAY_API void nvs_SetHsCallBack(HsUserCallBack CallbackFun);

//! [34]客户端传用户ID与机构ID给Linux
/*!
\param nUserID 用户ID
\param nOrgID  机构ID
\return 无
*/
NVSUNITEPLAY_API void nvs_SetUserIDandOrgID(int nUserID,int OrgID);


///////////////////////////////////////////////////
//! 以下的接口是直接从DVR上获取视频 (用于华三)

//! [1]连接DVR.
/*!
\param sIP 地址.
\param nPort 端口.
\param sUser 用户名.
\param sPwd 密码.
\return 连接句柄
*/
NVSUNITEPLAY_API intptr_t nvs_loginDVR(char* sIP, int nPort, char* sUser, char* sPwd);
//! [2]释放连接.
/*!
\param identify 连接时的句柄
\return 无
*/
NVSUNITEPLAY_API void nvs_logoutDVR(intptr_t identify);
//! [3]客户端软解播放.
/*!
\param identify 连接时的句柄
\param nCameraID 摄像头ID
\param hWnd 播放的窗口句柄
\return 播放结果
*/
NVSUNITEPLAY_API bool nvs_playVideoByDVR(intptr_t identify,int nCameraID,HWND hWnd);
//! [4]客户端关闭某窗口的播放
/*!
\param identify 连接时的句柄
\param hWnd 播放的窗口句柄.
\return 操作结果
*/
NVSUNITEPLAY_API bool nvs_stopPlayVideoByDVR(intptr_t identify,HWND hWnd);
//! [5]客户端控制摄像头(带控制速度)
/*!
\param identify 连接时的句柄
\param nCameraID 请求控制的摄像头ID
\param nCmd 控制标志
\param bControl 启停
\nSpeed 控制速度值
\return 返回控制成功与否
*/
NVSUNITEPLAY_API bool nvs_controlCameraSpeedByDVR(intptr_t identify,int nCameraID,int nCmd,bool bControl,int nSpeed,int nChannel);
//! [6]预置位
/*!
\param identify 连接时的句柄
\param nCameraID 请求控制的摄像头ID
\param nCmd 控制命令.
\param nIndex 预置点的序号
\return 操作结果
*/
NVSUNITEPLAY_API bool nvs_presetPTZByDVR(intptr_t identify,int nCameraID, int nCmd, int nTransPTZIndex, int nChannel);
//! [7]获取第三方软件的镜头信息
/*!
\param identify 连接时的句柄
\param nSize 结构数组长度,(结构个数)

\结构数组为 INFOCAMERA InfoCamera[]
\  typedef struct _infoCamera
\  {
\   	DWORD cameraId ;	  //镜头ID	
\    char cameraName[50];  //镜头名称
\  }INFOCAMERA;

\return 返回结构(一维)数组指针
*/
NVSUNITEPLAY_API intptr_t nvs_getCameraInfo(intptr_t identify,int *nSize);
//! [8]设置播放窗口句柄
/*!
\param palyWindow播放窗口数组
\param nMaxCount窗口数组个数，最大16个
\return INFOCAMERA结构数组指针.(见nvssdkdef.h定义)
*/
NVSUNITEPLAY_API int nvs_setPlayWindow(HWND palyWindow[], int nMaxCount);

//! [9]设置华三服务IP和端口
//返回false,无法连接HSServer获取帐号
NVSUNITEPLAY_API bool nvs_InitHSServer(char *strIP, int nPort);

//! 获取得错误信息
//nErrorCode; nvs_playVideo的返回值(除了0和1的错误码)。
//返回: NULL=未错误
NVSUNITEPLAY_API const char* nvs_GetErrorMessage(int nErrorCode);

//V3.0
//! [26] 标准视频消息回调初始化
/*!
\param pCB		回调函数指针
\param pUser	用户数据指针
*/
NVSUNITEPLAY_API int nvs_stdVideoinit(pNVSSipCallback pCB, void *pUser);
//! [27] 标准视频播放停止
/*!
\param sCameraID 摄像头编码
\param hWnd		 窗口句柄
\param sIP		 服务IP
\param nPort	 服务端口
\param sUser	 用户名
\param sPwd		 密码
\param sDllType	 设备类型
\param LPREALSTREAMCALLBACK lpCallBack 实时流回调函数
\param void* pUser                     参数
*/
NVSUNITEPLAY_API int nvs_playStdVideo(char* sCameraID,HWND hWnd ,char* sIP, int nPort, char* sUser, char* sPwd ,char* sDllType, LPREALSTREAMCALLBACK lpCallBack, void* pUser);
//! [28] 标准视频播放停止
/*!
\param sCameraID 摄像头编码
\param hWnd		 窗口句柄
*/
NVSUNITEPLAY_API int nvs_stopStdVideo(char* sCameraID,HWND hWnd);
//! [29] 视频上墙
/*!
\param sCameraID 摄像头编码
\param sMonitorCode		 监视器ID
\param sIP		 服务IP
\param nPort	 服务端口
\param sUser	 用户名
\param sPwd		 密码
\param sDllType	 设备类型
*/
NVSUNITEPLAY_API int nvs_startPlayMonitor(char* sCameraCode, char *sMonitorCode,char* sIP, int nPort, char* sUser, char* sPwd ,char* sDllType);
//! [30] 停止视频上墙
/*!
\param sMonitorCode		 监视器ID
*/
NVSUNITEPLAY_API int nvs_stopPlayMonitor(char *sMonitorCode);
// 抓图.
/*
\param identify 初始化返回的句柄.
\param sFilePath 文件路径.
\return 抓图结果
*/
NVSUNITEPLAY_API bool nvs_capturePictureByCode(char* sCameraCode, char* sFilePath);
// 制作关键帧
/*
\param sCameraID 摄像头编码
\param identify 初始化返回的句柄.
\return 无
*/
NVSUNITEPLAY_API void nvs_makeKey(char* sCameraCode);
// 连接DVR.
/*
\param sIP 地址.
\param nPort 端口.
\param sUser 用户名.
\param sPwd 密码.
\param nChannel 通道.
\param sType 解析库.
\return 连接句柄
\-1:加载PlugIn.dll失败
\-2:获取DVRHandler对象失败
\-3:登录DVR失败
*/
NVSUNITEPLAY_API intptr_t nvs_connectDVR(char* sIP, int nPort, char* sUser, char* sPwd, int nChannel ,char* sDllType);
// 释放连接.
/*
\param identify 连接时的句柄.
\return 无
*/
NVSUNITEPLAY_API void nvs_disconnectDVR(intptr_t identify);
//执行云台控制_带通道
/*
\param sCameraID 摄像头编码
\param identify 连接时的句柄
\param nCmd 控制命令.
\param bEnable 开关.
\param nSpeed 速度
\return 操作结果
*/
NVSUNITEPLAY_API bool nvs_controlPTZSpeedWithChannel(string sCameraID,intptr_t identify,int nCmd, bool bEnable, int nSpeed, int nChannel);
//执行预置位_带通道
/*
\param sCameraID 摄像头编码
\param identify 连接时的句柄.
\param nCmd 控制命令.
\param bEnable 开关.
\return 操作结果
*/
NVSUNITEPLAY_API bool nvs_presetPTZWithChannel(string sCameraID,intptr_t identify, int nCmd, int nIndex, int nChannel);
// 调整视频参数.
/*
\param identify 初始化返回的句柄.
\param nBrightValue 亮度(取值为1-10).
\param nContrastValue 对比度(取值为1-10).
\param nSaturationValue 饱和度(取值为1-10).
\param nHueValue 色度(取值为1-10).
\return 操作结果
*/
NVSUNITEPLAY_API bool nvs_setVideoEffectByCode(string sCameraID,intptr_t identify,DWORD dwBrightValue,DWORD dwContrastValue, DWORD dwSaturationValue,DWORD dwHueValue);
// 获取视频参数.
/*
\param sCameraID 摄像头编码
\param identify 初始化返回的句柄.
\param nBrightValue 亮度(取值为1-10).
\param nContrastValue 对比度(取值为1-10).
\param nSaturationValue 饱和度(取值为1-10).
\param nHueValue 色度(取值为1-10).
\return 操作结果
*/
NVSUNITEPLAY_API bool nvs_getVideoEffectByCode(string sCameraID,intptr_t identify,DWORD *pBrightValue,DWORD *pContrastValue, DWORD *pSaturationValue,DWORD *pHueValue);
// 获取设备结构.
/*
\param sCameraID 摄像头编码
\param sCameraID 摄像头编码
\param identify 初始化返回的句柄.
\param dwCommand 命令
\param lChannel 通道.
\param lpOutBuffer 是一个传出的字符串指针（byStreamType@byResolution@byBitrateType@byPicQuality@dwVideoBitrate@dwVideoFrameRate$byStreamType@byResolution@byBitrateType@byPicQuality@dwVideoBitrate@dwVideoFrameRate）用$符号区分录像结构信息和网传信息结构,用@区分信息体内各个参数 的一段是录像结构信息  第二段是网络结构信息
\param dwOutBufferSize 缓冲区大小.
\param lpBytesReturned 返回状态.
\return 获取结果
*/
NVSUNITEPLAY_API bool nvs_getDVRConfig(string sCameraID,intptr_t identify, DWORD dwCommand, LONG lChannel,LPVOID lpOutBuffer,DWORD dwOutBufferSize,LPDWORD lpBytesReturned);

// 设置设备结构.
/*
\param sCameraID 摄像头编码
\param identify 初始化返回的句柄.
\param dwCommand 命令
\param lChannel 通道.
\param lpInBuffer 是一个传入的字符串指针（byStreamType@byResolution@byBitrateType@byPicQuality@dwVideoBitrate@dwVideoFrameRate$byStreamType@byResolution@byBitrateType@byPicQuality@dwVideoBitrate@dwVideoFrameRate）用$符号区分录像结构信息和网传信息结构,用@区分信息体内各个参数 的一段是录像结构信息  第二段是网络结构信息
\param dwInBufferSize 缓冲区大小.
\return 设置结果
*/

NVSUNITEPLAY_API bool nvs_setDVRConfig(string sCameraID,intptr_t identify, DWORD dwCommand,LONG lChannel,LPVOID lpInBuffer,DWORD dwInBufferSize);
// 获取录像文件列表.
/*
\param sCameraID 摄像头编码
\param identify 连接时的句柄.
\param nType 记录类型.
\param startTime 开启时间.
\param endTime 关闭时间.
\param pRecordFile 缓冲区地址.
\param nMaxFileCount 缓冲区大小.
\return 记录文件个数   0:无记录  -1：不支持该查找类型 -2:失败  -3:还未登录DVR
*/
NVSUNITEPLAY_API int  nvs_getRecordFileEx(string sCameraID,intptr_t identify,RECORDQUERYTYPE nType,char* startTime,char* endTime,RECORDFILE pRecordFile[],int nMaxFileCount);
// 下载录像文件.
/*
\param identify 连接时的句柄.
\param fileName 文件名.  ==文件名不为空，按文件名下载，文件名为空时按时间下载。==
\param startTime 开启时间.
\param endTime 关闭时间.
\param nFileSize 文件大小.
\param saveFile 存储文件路径.
\param lpCallBack 回调函数指针. ==此回调函数是为通知客户端下载进度的时候有用，
\                                 现在不用这种方式，使用的是客户端主动获取的方式，
\                                 所以这个回调函数指针设为空即可。==
\param pUser 承载对象指针.
\return 返回的下载句柄
\-1:获取下载文件句柄失败
\-2:还未登录DVR
*/
NVSUNITEPLAY_API intptr_t nvs_downloadRecordFile(string sCameraID,intptr_t identify,char* fileName,char* startTime, char* endTime,int nFileSize,char* saveFile,LPDOWNLOADRECORDFILECALLBACK lpCallBack,void* pUser);
// 停止下载录像文件.
/*
\param identify 连接时的句柄.
\param ldownFileHandle 下载文件句柄
\return 操作结果
*/
NVSUNITEPLAY_API bool nvs_stopDownloadRecordFile(intptr_t identify,intptr_t ldownFileHandle);
// 获取下载的进度.
/*
\param identify 初始化返回的句柄.
\param lFileHandle 文件句柄.

\return ：-1表示失败，0-100:下载的进度，100表示下载结束，>100: 由于网络原因或DVR忙,下载异常终止
\         -2:下载文件句柄无效
*/
NVSUNITEPLAY_API int nvs_getDownloadPos(intptr_t identify,intptr_t lFileHandle);

// 远程回放.
/*
\param identify 连接时的句柄.
\param hWnd 窗口句柄.
\param fileName 文件名称. ==文件名不为空时按文件名播放，否则按时间播放==
\param startTime 开始时间.
\param endTime 结束时间.
\param nFileSize 文件大小.
\return 回放句柄
*/
NVSUNITEPLAY_API intptr_t nvs_replayRecordFile(string sCameraID,intptr_t identify,int hWnd,char* fileName,char* startTime, char* endTime,int nFileSize);
// 远程回放控制.
/*
\param identify 连接时的句柄.
\param lReplayHandle 回播句柄.
\param nCmd 命令.
\param nInValue 输入参数.
\param outValue 输出参数.
\return 操作结果
*/
NVSUNITEPLAY_API bool nvs_controlReplayRecordFile(intptr_t identify,intptr_t lReplayHandle,int nCmd,int nInValue,int* outValue);
// 停止远程回放.
/*
\param identify 连接时的句柄.
\param lReplayHandle 回播句柄.
\return 操作结果
*/
NVSUNITEPLAY_API bool nvs_stopReplayRecordFile(intptr_t identify,intptr_t lReplayHandle);

// 开始语音对讲.
/*
\param identify 连接时的句柄.
\return 操作结果
*/
NVSUNITEPLAY_API bool nvs_startTalk(string sCameraID,intptr_t identify);
// 停止语音对讲.
/*
\param identify 连接时的句柄.
\return 操作结果
*/
NVSUNITEPLAY_API bool nvs_stopTalk(string sCameraID,intptr_t identify);
//20140819


// 获取硬盘录像机工作状态.
/*
\param identify 初始化返回的句柄.
\param dvrWorkState 返回得工作状态字符串如下例
HK$0$1024000!1024000!0^1024000!1024000!0$0!0!0!50!2!2250004@2250008^0!0!0!50!2!2250004@2250008$0@0@0@0@0@0@0$0@0@0@0@0@0@0$0
用$来区分每段表示的意思
HK									海康
0										设备的状态,0-正常,1-CPU占用率太高,超过85%,2-硬件错误
1024000!1024000!0^1024000!1024000!0	表示有两个硬盘,每个硬盘参数(硬盘的容量 硬盘的剩余空间 硬盘的状态,按位 1-休眠，2-不正常)
0!0!0!50!2!2250004@2250008^0!0!0!50!2!2250004@2250008
表示有两个通道,每个通道信息如下
通道是否在录像,0-不录像,1-录像
连接的信号状态,0-正常,1-信号丢失
通道硬件状态,0-正常,1-异常,例如DSP死掉
实际码率
客户端连接的个数(这里举例是2个)
客户端的IP地址(这里有两个客户端,用 @ 把两个IP地址区分)
0@0@0@0@0@0@0							报警端口的状态,0-没有报警,1-有报警,用 @ 把每个端口区分
0@0@0@0@0@0@0							报警输出端口的状态,0-没有输出,1-有报警输出,用 @ 把每个端口区分
0										本地显示状态,0-正常,1-不正常
\param arrayLen 缓冲区长度.
\return 获取结果
*/
NVSUNITEPLAY_API bool nvs_getDVRWorkState(intptr_t identify,char dvrWorkState[],int arrayLen);

//获取错误代码
/*
\return DVR错误码
*/
NVSUNITEPLAY_API DWORD nvs_getLastError(string sCameraID,intptr_t identify);

//远程回放时抓图
/*
\param identify 初始化返回的句柄
\param lReplayHandle 播放句柄
\param pFileName 保存图片的文件名
\return 成功与否
*/
NVSUNITEPLAY_API  bool nvs_playBackCaptureFile(intptr_t identify , intptr_t  lReplayHandle, char *pFileName);

// 保存回放的数据.
/*
\param identify 初始化返回的句柄.
\param lReplayHandle 回播句柄
\param sFileName 文件名
\return 获取结果
*/
NVSUNITEPLAY_API bool nvs_playBackSaveData(intptr_t identify,intptr_t lReplayHandle,char *sFileName);
// 停止保存回放的数据.
/*
\param identify 初始化返回的句柄.
\param lReplayHandle 回播句柄
\return 获取结果
*/
NVSUNITEPLAY_API bool nvs_stopPlayBackSave(intptr_t identify,intptr_t lReplayHandle);

NVSUNITEPLAY_API bool nvs_startRecordByCode(string sCameraID,intptr_t identify, char* saveFile);

NVSUNITEPLAY_API bool nvs_stopRecordByCode(string sCameraID,intptr_t identify);

//局部放大(对应解码库XY_SetCropArea()接口)
/*
Param:  identify: 句柄
bFlag: 无意义
x1, y1, x2, y2分别为鼠标在播放窗体上的左上及右下的坐标, 全部为0时表示停止局部放大.
return:true 成功, false 失败*/
NVSUNITEPLAY_API bool nvs_SetCropArea(string sCameraID,intptr_t identify, bool bFlag = false, int x1 = 0, int y1 = 0, int x2 = 0, int y2 = 0);

//视频解码智能调节(根据nCmd参数, 分别对应解码库XY_SetClearFogParam(), XY_OpenOrCloseClearFog(), XY_OpenOrCloseInvert(), XY_OpenOrCloseSharpen()接口)
/*
Param:  identify: 句柄
nCmd: 智能调节的类型, 1为去雾, 2为反色, 3为锐化, 4为亮度调节
bFlag: true为执行智能调节, false为取消
x1, y1: 去雾时表示起始点坐标, 高度调节时为参数
x2, y2: 亮度调节表示终结点坐标.
return: 0成功, <0失败*/
NVSUNITEPLAY_API bool nvs_SetDecodeParam(string sCameraID,intptr_t identify, int nCmd, bool bFlag = false, int x1 = 0, int y1 = 0, int x2 = 0, int y2 = 0);

/****以下三个接口是为了实现在客户端播放实时视频时的15秒快速回放****/

//设置实时播放时保存流数据的时间, 默认15秒
/*
Param:  identify: 句柄
nSaveTime: 保存的时间(单位:秒）
return: true成功, false失败*/
NVSUNITEPLAY_API bool nvs_SetStreamSaveTime(string sCameraID,intptr_t identify, int nSaveTime = 15);

//回放保存的视频流
/*
Param:  identify: 句柄;
hWnd: 窗口句柄
return: true成功, false失败*/
NVSUNITEPLAY_API bool nvs_PlayBackSaveStream(string sCameraID,intptr_t identify, HWND hWnd);

//停止回放保存的视频流
/*
Param:  identify: 句柄
return: true成功, false失败*/
NVSUNITEPLAY_API bool nvs_StopPlayBackSaveStream(string sCameraID,intptr_t identify);
//设置图像的渲染模式，默认为D3D渲染
/*
Param:identify: 句柄;
OutParam:无
返回值：成功返回true，否则返回false
*/
NVSUNITEPLAY_API bool nvs_SetRenderMode(string sCameraID,intptr_t identify, int nMode = RENDER_BY_D3D);

//根据帧号定位,定位至nFrameNum最近的关键帧（往前查找）
/*
Param:identify: 句柄；nFrameNum 帧号
OutParam:无
返回值：成功返回true，否则返回false
*/
NVSUNITEPLAY_API bool nvs_SetPosByFrameNum(string sCameraID,intptr_t identify,DWORD nFrameNum);

//截取beginTime和endTime之间的录像，保存至filename所指定的路径，beginTime和endTime为秒级时间
/*
Param:identify: 句柄;
beginFrame：截取开始的时间；
endFrame：截取结束的时间；
filename：录像保存的绝对路径
OutParam:无
返回值：成功返回true，否则返回false
*/
NVSUNITEPLAY_API bool nvs_GetVideoCut(string sCameraID,intptr_t identify, DWORD beginFrame, DWORD endFrame, LPSTR filename);

//中止文件剪切
/*
Param:identify: 句柄;
OutParam:无
返回值：成功返回true，否则返回false
*/
NVSUNITEPLAY_API bool nvs_StopCutVideo(string sCameraID,intptr_t identify);

//设置文件结束回调
/*
Param:identify: 句柄;
OutParam:无
返回值：成功返回true，否则返回false
*/
NVSUNITEPLAY_API bool nvs_SetFileEndCallback(string sCameraID,intptr_t identify, void *pUser, pFileOverCB pCallBack);// 通知使用（为了确认视频文件已经播放完毕，因为部分视频文件播放完毕时，当前帧不等于总帧数）

//获取媒体信息
/*
Param:identify: 句柄；mInf用来获取媒体信息的结构指针
OutParam:无
返回值：成功返回true，否则返回false
*/
NVSUNITEPLAY_API bool nvs_GetMediaInfo(string sCameraID,intptr_t identify,MediaInf &mInf);
//视频解码获取配置参数
/*
Param:identify: 句柄； 
nCmd: 智能调节的类型, 1为去雾, 2为反色, 3为锐化, 4为亮度调节
OutParam:
当nCmd为1去雾调节时:
x1				起始点X坐标
y1				起始点Y坐标
x2				结束点X坐标
y2				结束点Y坐标
当nCmd为4亮度调节时:
x1 为gray1	亮度调节参数的灰度值1
y1 为gray2	亮度调节参数的灰度值2
return: 0成功, <0失败*/
NVSUNITEPLAY_API bool nvs_GetDecodeParam(string sCameraID,intptr_t identify, int nCmd, int &x1, int &y1, int &x2, int &y2);

// 开始播放并且获取标准格式视频流.
/*
\param identify 初始化返回的句柄.
\param hWnd 播放窗口句柄.
\return 操作结果
*/
NVSUNITEPLAY_API bool nvs_startPlayer4Standard(string sCameraID,intptr_t identify,HWND hWnd,LPDecCBFun lpDecCBFun, int nCameraID);

//设置YUV回调函数(对应解码库XY_SetStreamCallBackForVideo()接口)
/*
Param:  identify: 句柄
pCallBack: 回调函数, 定义见上面.
return:true 成功, false 失败*/
NVSUNITEPLAY_API bool nvs_SetYUVCallBack(string sCameraID,intptr_t identify, LPYUVCALLBACK pCallBack);

//根据视频源获取历史视频的信息  根据视频源获取历史视频的信息, 查找到的信息在pSipMsgCallBack中返回
/*                
Parameter:  nType                             历史视频类型
Parameter:  startTime                      视频开始时间
Parameter:  endTime                        视频结束时间
Parameter:  nRecordSource                     视频源1:设备2：平台
Returns:true 成功, false 失败
*/
NVSUNITEPLAY_API bool nvs_getRecordFileBySource(string sCameraID,intptr_t identify,int nType, char* startTime, char* endTime, int nRecordSource);



//************************************
// Method:    downloadRecordFileBySource                 下载历史视频
// Returns:   intptr_t                                       小于表示失败其它为下载标识用于停止下载
// Parameter: char * fileName                            视频名
// Parameter: char * startTime                           视频开始时间
// Parameter: char * endTime                             视频结束时间
// Parameter: int nFileSize                              文件大小（也常用于传入一些其它必需的参数）
// Parameter: char * saveFile                            保存文件路径
// Parameter: LPDOWNLOADRECORDFILECALLBACK lpCallBack    下载进度回调
// Parameter: void * pUser                               用户指针，用于区分到底是哪个对象的数据
// Parameter: int nRecordSource							 视频源:设备：平台
//************************************
NVSUNITEPLAY_API intptr_t nvs_downloadRecordFileBySource(string sCameraID,intptr_t identify,char* fileName,char* startTime, char* endTime,int nFileSize,char* saveFile,LPDOWNLOADRECORDFILECALLBACK lpCallBack,void* pUser, int nRecordSource);

//V3.0
#endif