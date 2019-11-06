
#ifndef _NVSSTREAMPLAYSDK_H
#define _NVSSTREAMPLAYSDK_H

#if defined NVSSTREAMPLAYLIB_EXPORTS
#define NVSSTREAMPLAY_API extern "C" __declspec(dllexport)
#else
#define NVSSTREAMPLAY_API extern "C" __declspec(dllimport)
#endif
#ifndef CALLBACK
#define CALLBACK   __stdcall
#endif // !CALLBACK

//! 请求视频播放错误返回码
#define XY_REQ_PLAY_SUCCESS 		 1  //传入的镜头已存在播放对象，直接调用Plugin播放成功
#define XY_REQ_SUCCESS 				 0  //向流媒体请求视频数据成功
#define XY_REQ_FAIL_GET_ADAPTER 	-1  //获取流媒体适配器失败
#define XY_REQ_USED_WINDOW 			-2  //传入窗体已被占用，播放失败
#define XY_REQ_UNCONTROL_DVR 		-3  //当前流媒体服务不控制这个硬盘录像机
#define XY_REQ_NOT_FIND_CHANNEL		-4  //当前流媒体服务控制这个硬盘录像机但没有找到相应通道
#define XY_REQ_OVER_MAXLINK			-5  //流媒体最大负载客户端数已满
#define XY_REQ_STREAM_NORIGHT 		-6  //流媒体服务还没有授权
#define XY_REQ_DVR_NOT_CONNECT		-7  //流媒体服务与硬盘录像机还没连接好
#define XY_REQ_ERR_VIDEOPROCESS		-8  //视频播放对象向流媒体请求视频异常
#define XY_REQ_NOT_RECEIVE_DATA		-9  //请求视频成功但未收到头数据
#define XY_REQ_NOT_WNDINUSE         -10 //播放窗口已被使用

//以下6个同为回调播放结果宏
#define XY_PLAY_SUCCESS		    	 0	//播放成功
#define XY_PLAY_FAIL_GET_PORT    	-10	//获取播放端口失败
#define XY_PLAY_NULL_HEADDATA		-11 //头数据为空
#define XY_PLAY_FAIL_PLUGIN_INIT	-12 //初始化PlugIn失败
#define XY_PLAY_FAIL_PLUGIN_PLAY	-13 //调用PlugIn播放视频失败
#define XY_FAIL_DISCONNECT_INDEX	-14 //与索引服务网络断开了
#define XY_FAIL_DISCONNECT_STREAM	-15 //与流媒体服务的连接断开了

#define XY_REQ_STREAM_UNREGISTER	-16 //未向被索引分配的流媒体注册或注册失败
#define XY_REQ_FAIL_GET_PLAYOBJ 	-17 //获取播放对象失败
#define XY_REQ_ERROR_GET_PLAYOBJ	-18 //NVSStreamManager::playVideo4ICE播放异常
#define XY_REQ_FAIL_ASKFOR_STREAM   -19 //请示流媒体对象失败
#define XY_REQ_INDEX_UNREGISTER	    -20 //未向索引服务注册 
#define XY_REQ_UNSET_CALLBACK	    -21 //回调函数未设置
#define XY_REQ_UNSET_STDCALLBACK	-22 //标准流回调函数未设置
#define XY_PLAY_H3C_FAIL			-23 //播放华三镜头失败

//2011-7-27 增加
#define XY_PLAY_FAIL_SETBODYCALLBACK -24 //接收器为NULL时设置数据体接收对象失败

//以下3个为硬解专用
#define XY_PLAY_ERR_CARD_OPENSTREAM -26 //打开解码卡流播放端口失败
#define XY_PLAY_FAIL_CARD_PLAY		-27 //硬解播放失败
#define XY_REQ_USED_DECODE_CHANNEL  -28 //传入解码通道已被占用，播放失败

//集中存储
#define XY_RECORD_WRITEHEAD_FAILURE	-29 //集中存储录像写入头数据失败


//重新连接
#define XY_REQ_RE_PLAY				   -40 //前端设备未传回数据流，正在重新请求播放
#define XY_REQ_STREAM_NOT_FIND_CHANNEL -41 //找不到通道的DVR信息
#define XY_REQ_STREAM_NOT_REGISTER     -42 //客户端未向流媒体注册,请等待重连或重新启动客户端
#define XY_REQ_STREAM_QUERYVISFAIL     -43 //请求VIS失败
#define XY_REQ_STREAM_SOURCEFULL       -44 //流媒体输入源已满
#define XY_REQ_STREAM_SINKFULL         -45 //流媒体输出已满

#define XY_PLAY_NOT_RECEIVE_CLOSE	   -46 //客户端未向流媒体注册,请等待重连或重新启动客户端


#define XY_REQ_INDEX_NOT_FIND_DVRINFO -180 //镜头关联DVR不存在,检索镜头信息失败,请核对	//2011-7-28 修改
#define XY_REQ_INDEX_NOT_FIND_STREAM  -181 //没有找到关联流媒体
#define XY_REQ_INDEX_MAX_LOAD		  -182 //对应流媒体已超负荷，连接已满
#define XY_REQ_INDEX_NOT_FIND_GRADE	  -183 //没有空闲在线级联流媒体
#define XY_REQ_INDEX_NOT_QUERYVIS	  -184 //请求切换VIS失败
#define XY_REQ_INDEX_QUERY_TIMEOUT    -185 //请求镜头关联流媒体地址超时

//2013-2-21 针对调用接口索引接口异常而增加的宏
#define XY_EXP_INDEX_GETSTREAMINFO	  -186 //请求镜头关联流媒体地址异常
#define XY_EXP_INDEX_GETDVRINFO		  -187 //请求镜头关联DVR地址异常


//2011-7-28 针对华三视频宏定义
#define XY_REQ_INDEX_NOT_FIND_DVRPARA -190 //镜头关联DVR存在,但获取设备信息失败
#define XY_REQ_INDEX_FALSE_GETCHACODE -191 //获取镜头统一编码异常,取消播放
#define XY_REQ_INDEX_FALSE_GETHSUSER  -192 //获取华三用户信息失败

#define XY_UNKNOWN -999    //未定义

//2012-10-12 新增加
#define  ERROR_SOURCEPARA		 -70
#define  ERROR_SOURCERETURN		 -71
#define  ERROR_SOURCEFIND		 -72
#define  ERROR_SOURCEEXCEPTION	 -73

/*! \file NVSStreamPlaySDK.h
*   \brief 用户视频客户端与索引、流媒体间通讯播放控制库
*   \author 孙靖宇
*   \version 1.0
*   \date    2008-03-20
*/

/*! 定义ICE模式请求为0 */
#define BY_ICE		0
/*! 定义Socket模式请求为1 */
#define BY_SOCKET	1

/*! 软解播放结果回调指针 */ 
//typedef void (CALLBACK * PlayResult)(char Des[256]);
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

/*! 视频被切换通知回调指针
\param nCameraID;     //镜头ID
*/
typedef void (CALLBACK *NoticeSwitchedCallBack)(int nUserID,int nPriorCameraID,int nCameraID,char* pDesc);


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
typedef void (CALLBACK *LPVedioBodyStreamCBFun)(BYTE * pBuf, long nSizeint, int  nCameraID);

/*! 预览画面叠加字符和图像
\param lRealHandle NET_DVR_RealPlay()或NET_DVR_RealPlay_V30()的返回值 
\param hDc 画图句柄
\param nCameraID 镜头ID
*/
typedef void (CALLBACK *LPDrawCBFun)(intptr_t lRealHandle, DWORD hDc, int nCameraID);

//! [01] 初始化业务逻辑核心模块
/*!
\param pAddress 索引服务地址.
\param nPort 索引服务端口.
\param type ICE通讯方式.
\param nRight 权限值.
\return 初始化成功与否
*/
NVSSTREAMPLAY_API bool nvs_initEnviroment(const char* pAddress,unsigned short nPort,int nRight, char type = BY_ICE);
//! [02] 清理业务逻辑核心环境.
/*!
\return 无
*/
NVSSTREAMPLAY_API void nvs_cleanEnviroment();
//! [03] 客户端注册上索引服务.
/*!
\return 注册结果
*/
NVSSTREAMPLAY_API bool nvs_registerOnIndex();
/*! 设置回调函数 */
NVSSTREAMPLAY_API void nvs_setDecordCardCallBack(PlayResultByDecordCard pFun);
NVSSTREAMPLAY_API void nvs_setRealPlayCallBack(RealPlayCallBack pFun);
NVSSTREAMPLAY_API void nvs_setRealDecodeCallBack(LPDecCBFun pFun);
NVSSTREAMPLAY_API void nvs_setIndexNoticeCallBack(IndexNoticeCallBack pFun);
NVSSTREAMPLAY_API void nvs_setDVRNoticeCallBack(DVRNoticeCallBack pFun);


//! [07] 客户端软解播放
/*!
\param nCameraID 摄像头ID
\param hWnd 播放的窗口句柄
\param bUseDecode 获取标准流标识
\return 请求播放结果 0-请求播放成功 -1流媒体获取适配器失败 -2该窗体已被占用 -3请求流媒体失败 -4播放出现异常 -5正在等待头数据 -6未注册索引服务 -7未设置标准流回调
*/
NVSSTREAMPLAY_API int nvs_playVideo(int nCameraID,HWND hWnd, bool bUseDecode/*获取标准流标识*/);


NVSSTREAMPLAY_API int nvs_playVideo2(int nCameraID,HWND hWnd, bool bUseDecode/*获取标准流标识*/, bool bIsExternalDvr);


NVSSTREAMPLAY_API int xs_playVideo(int nCameraID,HWND hWnd, bool bUseDecode, bool bIsExternalDvr,const char* pCameraID,void *pUsr);
//! [08] 客户端关闭某窗口的播放
/*!
\param hWnd 播放的窗口句柄
\return 无
*/
NVSSTREAMPLAY_API bool nvs_stopPlayVideo(HWND hWnd, int nCardIndex, int nCameraID);

NVSSTREAMPLAY_API bool nvs_stopPlayByCameraID(int nCameraID);

NVSSTREAMPLAY_API int xs_stopPlayVideo(HWND hWnd,int nCameraID,const char* pCameraID);

NVSSTREAMPLAY_API int xs_stopPlayByCameraID(int nCameraID,const char* pCameraID);
//! [09] 客户端关闭所有窗口播放
/*!
\return 无
*/
NVSSTREAMPLAY_API void nvs_stopAll();
//! [11] 客户端控制摄像头(带控制速度)
/*!
\param nCameraID 请求控制的摄像头ID
\param nCmd 控制标志
\param bControl 启停
\return 返回控制成功与否
\nSpeed 控制速度值1-15级别
*/
NVSSTREAMPLAY_API bool nvs_controlCameraSpeed(int nCameraID,int nCmd,bool bControl,int nSpeed);
//! [12] 自动注销PTZ控制权限
NVSSTREAMPLAY_API bool nvs_cancelControlCamera(HWND hWnd,int nCameraID);

//! [13] 抓图
NVSSTREAMPLAY_API bool nvs_capturePictureEx(int nCameraID, char* pFileName);
//! [14] 预置位
NVSSTREAMPLAY_API bool nvs_TransPTZ(int nCameraID, int nCmd, int nTransPTZIndex);
//! [15] 获取通道参数（主码流、子码流视频参数）
NVSSTREAMPLAY_API bool nvs_getCompress(int nCameraID, char **lpOutBuffer);
//! [16] 设置通道参数
NVSSTREAMPLAY_API bool nvs_setCompress(int nCameraID, char* pCompressInfo);
//! [17] 获取视频参数（亮度、色度、饱和度等）
NVSSTREAMPLAY_API bool nvs_getVideoEffect(int nCameraID, int* pBrightValue,int* pContrastValue, int* pSaturationValue,int* pHueValue);
//! [18] 设置视频参数
NVSSTREAMPLAY_API bool nvs_setVideoEffect(int nCameraID, DWORD dwBrightValue,DWORD dwContrastValue, DWORD dwSaturationValue,DWORD dwHueValue);
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
NVSSTREAMPLAY_API int  nvs_startRecord(int nCameraID, char* pFileName);
//! [20] 停止本地录像
NVSSTREAMPLAY_API bool nvs_stopRecord(int nCameraID);
//! [21] 使用透明通道
NVSSTREAMPLAY_API bool nvs_serialSend(int nCameraID, char* cmd1, DWORD nLen1, char* cmd2, DWORD nLen2);
//! [22] 刷新重设视频播放使用监视器
NVSSTREAMPLAY_API void nvs_reSetDDrawDevice(int nCameraID);
//! [23] 分割录像文件
//NVSSTREAMPLAY_API HANDLE nvs_splitFile(HWND hWnd,char * sFileName);
NVSSTREAMPLAY_API int nvs_splitFile(int nCameraID, char* sFileName, int nPriorTime,  bool bIsExternalDvr= false);
//! [26] 控制摄像头视频声音
/*!
\param nCameraID 镜头ID.
\param bOpenSound 设置状态 0-关闭声音 1-打开声音
\return 开启声音是否成功
*/
NVSSTREAMPLAY_API bool nvs_controlCameraSound(int nCameraID, bool bOpenSound);
//! [27]客户端通知回调对象建立完成
/*!
*/
NVSSTREAMPLAY_API bool nvs_clientNotice();
//! [28]获取流媒体工作状态
/*!
\param CameraIDArray (In)需要获取镜头所在流媒体工作状态的镜头数组
\param nCameraCount (In)镜头个数
\param outSize (Out)流媒体状态数组个数
\return StreamServerWorkState结构
*/

NVSSTREAMPLAY_API intptr_t nvs_getStreamServerWorkState(int nCameraID, int nCameraCount, int *outSize );
//! [29]获取镜头对应的流媒体的IP地址
/*!
*/
NVSSTREAMPLAY_API char * nvs_getStreamServerIP( int nCameraID);
//! [30]设置是否为外网客户端
/*!
\param bIsExternal: 如果客户端在外网，则设置为true
*/
NVSSTREAMPLAY_API void nvs_SetExternalClient(bool bIsExternal);

//! [31]设置实时视频头回调函数
NVSSTREAMPLAY_API void nvs_SetVedioHeadStreamCallBack(LPVedioHeadStreamCBFun pFun);
//! [32]设置实时视频流回调函数
NVSSTREAMPLAY_API void nvs_SetVedioBodyStreamCallBack(LPVedioBodyStreamCBFun pFun);
//! [33]设置预览画面叠加字符和图像回调函灵敏
NVSSTREAMPLAY_API void nvs_SetDrawFun(LPDrawCBFun pFun);
////////////////////////////////////////////////////
//! 以下的接口是直接从DVR上获取视频 (用于华三)

//! [1]连接DVR.
/*!
\param sIP 地址.
\param nPort 端口.
\param sUser 用户名.
\param sPwd 密码.
\return 连接句柄
*/
NVSSTREAMPLAY_API intptr_t nvs_loginDVR(char* sIP, int nPort, char* sUser, char* sPwd);
//! [2]释放连接.
/*!
\param identify 连接时的句柄
\return 无
*/
NVSSTREAMPLAY_API void nvs_logoutDVR(intptr_t identify);
//! [3]客户端软解播放.
/*!
\param identify 连接时的句柄
\param nCameraID 摄像头ID
\param hWnd 播放的窗口句柄
\return 播放结果
*/
NVSSTREAMPLAY_API bool nvs_playVideoByDVR(intptr_t identify,int nCameraID,HWND hWnd);
//! [4]客户端关闭某窗口的播放
/*!
\param identify 连接时的句柄
\param hWnd 播放的窗口句柄.
\return 操作结果
*/
NVSSTREAMPLAY_API bool nvs_stopPlayVideoByDVR(intptr_t identify,HWND hWnd);
//! [5]客户端控制摄像头(带控制速度)
/*!
\param identify 连接时的句柄
\param nCameraID 请求控制的摄像头ID
\param nCmd 控制标志
\param bControl 启停
\nSpeed 控制速度值
\return 返回控制成功与否
*/
NVSSTREAMPLAY_API bool nvs_controlCameraSpeedByDVR(intptr_t identify,int nCameraID,int nCmd,bool bControl,int nSpeed,int nChannel);
//! [6]预置位
/*!
\param identify 连接时的句柄
\param nCameraID 请求控制的摄像头ID
\param nCmd 控制命令.
\param nIndex 预置点的序号
\return 操作结果
*/
NVSSTREAMPLAY_API bool nvs_presetPTZByDVR(intptr_t identify,int nCameraID, int nCmd, int nTransPTZIndex, int nChannel);
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
NVSSTREAMPLAY_API intptr_t nvs_getCameraInfo(intptr_t identify,int *nSize);
//! [8]设置播放窗口句柄
/*!
\param palyWindow播放窗口数组
\param nMaxCount窗口数组个数，最大16个
\return INFOCAMERA结构数组指针.(见nvssdkdef.h定义)
*/
NVSSTREAMPLAY_API int nvs_setPlayWindow(HWND palyWindow[], int nMaxCount);

//! [9]设置华三服务IP和端口
//返回false,无法连接HSServer获取帐号
NVSSTREAMPLAY_API bool nvs_InitHSServer(char *strIP, int nPort);

;//! 获取得错误信息
//nErrorCode; nvs_playVideo的返回值(除了0和1的错误码)。
//返回: NULL=未错误
NVSSTREAMPLAY_API const char* nvs_GetErrorMessage(int nErrorCode);

//可能废弃的选项
//! [] 设置通知回调函数
/*!
\param pFun 回调函数指针
*/
NVSSTREAMPLAY_API void nvs_setNoticeSwitchedCallBack(NoticeSwitchedCallBack pFun);
//
//! [04] 设置播放模式.
/*!
\param nPlayModel /0-软解播放 1-硬解播放 2-集中存储.
\return 无
*/
NVSSTREAMPLAY_API void nvs_setPlayModel(int nPlayModel = 0);
//! [05] 客户端硬解播放
/*!
\param nCameraID 请求控制的摄像头ID
\param nCardIndex 硬解播放的卡序号
\return 请求播放结果 0-播放成功 -1流媒体获取适配器失败 -2该窗体已被占用 -3请求流媒体失败 -4播放出现异常 -5正在等待头数据
*/
NVSSTREAMPLAY_API int nvs_playVideoByDecordCard(int nCameraID,int nCardIndex, HANDLE* hStreamPlayHandle, bool bIsExternalDvr = false);

//! [24] 集中存储播放
/*!
\param nCameraID 摄像头ID
\param sFileName 存储文件名
\return 请求播放结果 0-请求播放成功 -1流媒体获取适配器失败 -2该窗体已被占用 -3请求流媒体失败 -4播放出现异常 -5正在等待头数据 -6未注册索引服务 -7未设置标准流回调
*/
NVSSTREAMPLAY_API int nvs_play4Storage(int nCameraID,char* sFileName,int nPriorTime, bool bIsExternalDvr = false);
//! [25] 集中存储播放停止
/*!
\param nCameraID 摄像头ID
*/
NVSSTREAMPLAY_API bool nvs_stopPlay4Storage(int nCameraID);
;//! 设置重连标志
//bIsNeedRePlay; 重连标志
//返回: 
NVSSTREAMPLAY_API void nvs_SetRePlayFlag(bool bIsNeedRePlay);


NVSSTREAMPLAY_API int nvs_GetRecordFile(intptr_t lHandle,RECORDQUERYTYPE nType,char* startTime,char* endTime,RECORDFILE pRecordFile[],int nMaxFileCount);

NVSSTREAMPLAY_API intptr_t nvs_ReplayRecordFile(intptr_t lHandle,HWND hWnd,char* fileName,char* startTime, char* endTime,int nFileSize);

NVSSTREAMPLAY_API int nvs_ControlReplayRecordFile(intptr_t lHandle,intptr_t lRePlayhandle,int nCmd,int nInValue);

NVSSTREAMPLAY_API bool nvs_StopReplayRecordFile(intptr_t lHandle,intptr_t lRePlayhandle);

NVSSTREAMPLAY_API intptr_t nvs_DownloadRecordFile(intptr_t lHandle,char* fileName,char* startTime, char* endTime,int nFileSize,char* saveFile);

NVSSTREAMPLAY_API int nvs_GetDownloadPos(intptr_t lHandle,intptr_t ldownloadHandle);
NVSSTREAMPLAY_API bool nvs_StopDownloadRecordFile(intptr_t lHandle,intptr_t ldownloadHandle);

NVSSTREAMPLAY_API intptr_t nvs_CaptureStream(int CameraID, LPCAPTURESTREAMCALLBACK pCaptuerStreamFuc, void* pUser, int nGetVideoType = 0);

NVSSTREAMPLAY_API bool nvs_StopCaptureStream(intptr_t lHandle);

NVSSTREAMPLAY_API bool nvs_GetDecodeType(int nCameraID,char*sType);
NVSSTREAMPLAY_API intptr_t nvs_ConnectDVR(int nCameraID);
NVSSTREAMPLAY_API void nvs_disConnectDVR(intptr_t lHandle);



#endif
