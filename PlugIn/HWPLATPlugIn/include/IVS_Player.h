/********************************************************************
filename    :    IVS_Player.h
author      :    
created     :    2012/11/12
description :    IVS播放库接口
copyright   :    Copyright (c) 2012-2016 Huawei Tech.Co.,Ltd
history     :    2012/11/12 初始版本
*********************************************************************/
#ifndef __IVS_PLAYER_H__
#define __IVS_PLAYER_H__

#include "IVS_PlayerTypes.h"

#ifdef IVS_PLAYER_EXPORTS
# define IVS_PLAYER_API extern "C" __declspec(dllexport)
#else
# define IVS_PLAYER_API extern "C" __declspec(dllimport)
#endif


/*****************************************************************************
 函数名称：IVS_PLAY_Init
 功能描述：初始化;
 输入参数：const char* pLogPath
 输出参数：NA
 返 回 值：成功:IVS_SUCCEED; 失败:IVS_FAIL;
*****************************************************************************/
IVS_PLAYER_API int __stdcall IVS_PLAY_Init(const char* pLogPath);

/*****************************************************************************
 函数名称：IVS_PLAY_UnInit
 功能描述：清除库;
 输入参数：NA
 输出参数：NA
 返 回 值：NA
*****************************************************************************/
IVS_PLAYER_API void __stdcall IVS_PLAY_UnInit();

/*****************************************************************************
 函数名称：IVS_PLAY_GetChannel
 功能描述：获取可用的媒体通道号;
 输入参数：NA
 输出参数：pChannel  通道号;
 返 回 值：成功:IVS_SUCCEED;失败:IVS_FAIL;
*****************************************************************************/
IVS_PLAYER_API int __stdcall IVS_PLAY_GetChannel(HDL_PLAY* pChannel);

/*****************************************************************************
 函数名称：IVS_PLAY_FreeChannel
 功能描述：释放指定的媒体通道号;
 输入参数：ulChannel  通道号;
 输出参数：NA
 返 回 值：成功:IVS_SUCCEED;失败:IVS_FAIL;
*****************************************************************************/
IVS_PLAYER_API int __stdcall IVS_PLAY_FreeChannel(HDL_PLAY ulChannel);

/***************************************************************************
 函 数 名 : IVS_PLAY_SetExceptionCallBack
 功能描述 : 设置异常回调函数;
 输入参数 : cbExceptionCallBack        异常回调函数;
            pUser                      用户数据;
 输出参数 : NA
 返 回 值 : 成功:IVS_SUCCEED;失败:IVS_FAIL;
***************************************************************************/
IVS_PLAYER_API void __stdcall IVS_PLAY_SetExceptionCallBack(PLAYER_EXCEPTION_CALLBACK cbExceptionCallBack, void* pUser);


/***************************************************************************
 函 数 名 : IVS_PLAY_SetExceptionCallBack
 功能描述 : 设置事件回调函数;
 输入参数 : ulChannel                  通道号
			cbExceptionCallBack        异常回调函数;
            pUser                      用户数据;
 输出参数 : NA
 返 回 值 : 成功:IVS_SUCCEED;失败:IVS_FAIL;
***************************************************************************/
IVS_PLAYER_API void __stdcall IVS_PLAY_SetEventCallback(HDL_PLAY ulChannel, PLAYER_EVENT_CALLBACK cbExceptionCallBack, void* pUser);

/***************************************************************************
 函 数 名 : IVS_PLAY_MetadataCallBack
 功能描述 : 设置元数据回调函数;
 输入参数 : ulChannel                  通道号
			callback                   元数据回调函数;
            pUser                      用户数据;
 输出参数 : NA
 返 回 值 : 成功:IVS_SUCCEED;失败:IVS_FAIL;
***************************************************************************/
IVS_PLAYER_API int __stdcall IVS_PLAY_SetMetadataCallBack(HDL_PLAY ulChannel, METADATA_CALLBACK  callback, void *pUser);

/*****************************************************************************
 函数名称：IVS_PLAY_OpenStream
 功能描述：打开流通道;
 输入参数：ulChannel  通道号;
           StreamParam  流参数;
           uBufferSize 缓冲区大小;
 输出参数：NA
 返 回 值：成功:IVS_SUCCEED;失败:IVS_FAIL;
 *****************************************************************************/
IVS_PLAYER_API int __stdcall IVS_PLAY_OpenStream(HDL_PLAY ulChannel, IVS_STREAM_PARAM *StreamParam, unsigned int uBufferSize);

/*****************************************************************************
 函数名称：IVS_PLAY_UpdateStream
 功能描述：更新码流参数
 输入参数：ulChannel  通道号;
           StreamParam  流参数;
           uBufferSize 缓冲区大小;
 输出参数：NA
 返 回 值：成功:IVS_SUCCEED;失败:IVS_FAIL;
 *****************************************************************************/
IVS_PLAYER_API int __stdcall  IVS_PLAY_UpdateStream(HDL_PLAY ulChannel, IVS_STREAM_PARAM *StreamParam, unsigned int uBufferSize); 


/*****************************************************************************
 函数名称：IVS_PLAY_CloseStream
 功能描述：关闭流通道;
 输入参数：ulChannel 通道号;
 输出参数：NA
 返 回 值：成功:IVS_SUCCEED;失败:IVS_FAIL;
*****************************************************************************/
IVS_PLAYER_API int __stdcall IVS_PLAY_CloseStream(HDL_PLAY ulChannel);

/*****************************************************************************
 函数名称：IVS_PLAY_StartPlay
 功能描述：启动播放;
 输入参数：ulChannel 通道号;
           HWND   窗口句柄;
           HwAccel  1/0 开启(关闭)GPU解码加速           
 输出参数：NA
 返 回 值：成功:IVS_SUCCEED;失败:IVS_FAIL;
*****************************************************************************/
IVS_PLAYER_API int __stdcall IVS_PLAY_StartPlay(HDL_PLAY ulChannel, HWND hWnd, int HwAccel);

/*****************************************************************************
 函数名称：IVS_PLAY_StopPlay
 功能描述：停止播放;
 输入参数：ulChannel 通道号;
 输出参数：NA
 返 回 值：成功:IVS_SUCCEED;失败:IVS_FAIL;
*****************************************************************************/
IVS_PLAYER_API int __stdcall IVS_PLAY_StopPlay(HDL_PLAY ulChannel);

/*****************************************************************************
 函数名称：IVS_PLAY_PausePlay
 功能描述：暂停播放
 输入参数：ulChannel 通道号;
 输出参数：NA
 返 回 值：成功:IVS_SUCCEED;失败:IVS_FAIL;
*****************************************************************************/
IVS_PLAYER_API int __stdcall IVS_PLAY_PausePlay(HDL_PLAY ulChannel);

/*****************************************************************************
 函数名称：IVS_PLAY_ResumePlay
 功能描述：恢复播放
 输入参数：ulChannel 通道号;
 输出参数：NA
 返 回 值：成功:IVS_SUCCEED;失败:IVS_FAIL;
*****************************************************************************/
IVS_PLAYER_API int __stdcall IVS_PLAY_ResumePlay(HDL_PLAY ulChannel);

/*****************************************************************************
 函数名称：IVS_PLAY_SetPlaySpeed
 功能描述：设置播放速度
 输入参数：ulChannel 通道号;
			dSpeed   播放速度;
 输出参数：NA
 返 回 值：成功:IVS_SUCCEED;失败:IVS_FAIL;
*****************************************************************************/
IVS_PLAYER_API int __stdcall IVS_PLAY_SetPlaySpeed(HDL_PLAY ulChannel, double dSpeed);

/*****************************************************************************
 函数名称：IVS_PLAY_StepPlayForward
 功能描述：单步播放前进
 输入参数：ulChannel 通道号;
 输出参数：NA 
 返 回 值：成功:IVS_SUCCEED;失败:IVS_FAIL;
*****************************************************************************/
IVS_PLAYER_API int __stdcall IVS_PLAY_StepPlayForward(HDL_PLAY ulChannel);

/*****************************************************************************
 函数名称：IVS_PLAY_StepPlayBackward
 功能描述：单步播放后退
 输入参数：ulChannel 通道号;
 输出参数：NA
 返 回 值：成功:IVS_SUCCEED;失败:IVS_FAIL;
*****************************************************************************/
IVS_PLAYER_API int __stdcall IVS_PLAY_StepPlayBackward(HDL_PLAY ulChannel);

/*****************************************************************************
 函数名称：IVS_PLAY_PlaySound
 功能描述：启动音频播放;
 输入参数：ulChannel 通道号;
 输出参数：NA
 返 回 值：成功:IVS_SUCCEED;失败:IVS_FAIL;
*****************************************************************************/
IVS_PLAYER_API int __stdcall IVS_PLAY_PlaySound(HDL_PLAY ulChannel);

/*****************************************************************************
 函数名称：IVS_PLAY_StopSound
 功能描述：停止音频播放;
 输入参数：ulChannel 通道号;
 输出参数：NA
 返 回 值：成功:IVS_SUCCEED;失败:IVS_FAIL;
*****************************************************************************/
IVS_PLAYER_API int __stdcall IVS_PLAY_StopSound(HDL_PLAY ulChannel);

/*****************************************************************************
 函数名称：IVS_PLAY_SetVolume
 功能描述：设置音频播放音量;
 输入参数：ulChannel 通道号;
           uiVolumeValue 音量
 输出参数：NA
 返 回 值：成功:IVS_SUCCEED;失败:IVS_FAIL;
*****************************************************************************/
IVS_PLAYER_API int __stdcall IVS_PLAY_SetVolume(HDL_PLAY ulChannel, unsigned int uiVolumeValue);

/*****************************************************************************
 函数名称：IVS_PLAY_GetVolume
 功能描述：获取音频播放音量;
 输入参数：ulChannel 通道号;
 输出参数：uiVolumeValue 音量
 返 回 值：成功:IVS_SUCCEED;失败:IVS_FAIL;
*****************************************************************************/
IVS_PLAYER_API int __stdcall IVS_PLAY_GetVolume(HDL_PLAY ulChannel, unsigned int* puiVolumeValue);

/*****************************************************************************
 函数名称：IVS_PLAY_SetFrameCallBack
 功能描述：设置码流回调;
 输入参数：ulChannel           通道号;
           CallBack  回调函数指针;
           pUser             用户数据;
 输出参数：NA
 返 回 值：成功:IVS_SUCCEED;失败:IVS_FAIL;
*****************************************************************************/
IVS_PLAYER_API int __stdcall IVS_PLAY_SetFrameCallBack(HDL_PLAY ulChannel, FRAME_CALLBACK CallBack, void *pUser);

/*****************************************************************************
 函数名称：IVS_PLAY_SetFrameCallBack
 功能描述：设置解码帧数据回调;
 输入参数：ulChannel           通道号;
           CallBack    回调函数指针;
           pUser               用户数据;
 输出参数：NA
 返 回 值：成功:IVS_SUCCEED;失败:IVS_FAIL;
*****************************************************************************/
IVS_PLAYER_API int __stdcall IVS_PLAY_SetDecodeCallBack(HDL_PLAY ulChannel, DECODE_CALLBACK CallBack, void *pUser);

/*****************************************************************************
 函数名称：IVS_PLAY_SetDisplayFrameCallBack
 功能描述：设置渲染帧数据回调;
 输入参数：ulChannel           通道号;
           CallBack    回调函数指针;
           pUser               用户数据;
 输出参数：NA
 返 回 值：成功:IVS_SUCCEED;失败:IVS_FAIL;
*****************************************************************************/
IVS_PLAYER_API int __stdcall IVS_PLAY_SetDisplayCallBack(HDL_PLAY ulChannel, DISPLAY_CALLBACK CallBack, void *pUser);

/*****************************************************************************
 函数名称：IVS_PLAY_SetBufferStateCallback
 功能描述：设置码流缓存回调;
 输入参数：ulChannel  通道号;
           callback   回调函数指针;
           pUser       用户数据;
 输出参数：NA
 返 回 值：NA
*****************************************************************************/
IVS_PLAYER_API void __stdcall IVS_PLAY_SetBufferStateCallback(HDL_PLAY ulChannel, BUFFER_STATUS_CALLBACK CallBack, void *pUser);

/*****************************************************************************
 函数名称：IVS_PLAY_AddPlayWindow
 功能描述：设置播放窗口句柄
 输入参数：ulChannel 通道号;
	       IVS_HANDLE： 渲染通道句柄
	       hWnd：       窗口句柄
	       nType：      渲染布局类型
	       pLayout：    窗口布局参数
 输出参数：NA
 返 回 值：int
****************************************************************************/
IVS_PLAYER_API int __stdcall IVS_PLAY_AddPlayWindow(HDL_PLAY ulChannel, HWND hWnd, int nType, void *pLayout);

/*****************************************************************************
 函数名称：IVS_PLAY_AddPlayWindowPartial
 功能描述：增加局部图像播放窗口
 输入参数：ulChannel 通道号;
	       hWnd 渲染通道句柄
	       hWnd：       窗口句柄
	       pPartial：   局部图片参数
 输出参数：NA
 返 回 值：int
****************************************************************************/
IVS_PLAYER_API int __stdcall IVS_PLAY_AddPlayWindowPartial(HDL_PLAY ulChannel, HWND hWnd, LAYOUT_DRAW_PARTIAL *pPartial);

/*****************************************************************************
 函数名称：IVS_PLAY_UpdateWindowPartial
 功能描述：更新局部放大源矩形
 输入参数：ulChannel 通道号
	       hWnd：       窗口句柄
	       pPartial：   局部参数
 输出参数：NA
 返 回 值：int
****************************************************************************/
IVS_PLAYER_API int __stdcall IVS_PLAY_UpdateWindowPartial(HDL_PLAY ulChannel, HWND hWnd, LAYOUT_DRAW_PARTIAL *pPartial);

/*****************************************************************************
 函数名称：IVS_PLAY_DelPlayWindow
 功能描述：删除播放窗口句柄
 输入参数：ulChannel 通道号;
	       hWnd：    窗口句柄
 输出参数：NA
 返 回 值：int
****************************************************************************/
IVS_PLAYER_API int __stdcall IVS_PLAY_DelPlayWindow(HDL_PLAY ulChannel, HWND hWnd);

/*****************************************************************************
 函数名称：IVS_PLAY_SetDisplayAspectRatio
 功能描述：按通道和窗口设置视频显示比例
 输入参数：ulChannel:    通道号;
		   uiScale:       显示比例  1 原始 2 铺满
 输出参数：NA
 返 回 值：int
****************************************************************************/
IVS_PLAYER_API int __stdcall IVS_PLAY_SetDisplayAspectRatio(HDL_PLAY ulChannel, unsigned int uiScale);

/*****************************************************************************
 函数名称：IVS_PLAY_InputRtpData
 功能描述：向播放库输入RTP流;
 输入参数：ulChannel    通道号;
           pBuf         缓存;
		   ulSize       缓存大小;
 输出参数：NA
 返 回 值：成功:IVS_SUCCEED;失败:IVS_FAIL;
 *****************************************************************************/
IVS_PLAYER_API int __stdcall IVS_PLAY_InputRtpData(HDL_PLAY ulChannel, char *pBuf, unsigned int uiSize);

IVS_PLAYER_API int __stdcall IVS_PLAY_InputEos(HDL_PLAY ulChannel);

/*****************************************************************************
 函数名称：IVS_PLAY_InputFrameData
 功能描述：向播放库输入帧数据(音视频);
 输入参数：ulChannel    通道号;
           pFrameInfo   帧数据信息;
		   pFrame       帧数据
		   uFrameSize   帧数据长度
 输出参数：NA
 返 回 值：成功:IVS_SUCCEED;失败:IVS_FAIL;
 *****************************************************************************/
IVS_PLAYER_API int __stdcall IVS_PLAY_InputFrameData(HDL_PLAY ulChannel, IVS_FRAME_INFO* pFrameInfo, char* pFrame, unsigned int uFrameSize);

/*****************************************************************************
 函数名称：IVS_PLAY_OpenFile
 功能描述：打开文件;
 输入参数：ulChannel    通道号;
 输入参数：pFileName    文件名;
 输出参数：NA
 返 回 值：成功:IVS_SUCCEED;失败:IVS_FAIL;
*****************************************************************************/
IVS_PLAYER_API int __stdcall IVS_PLAY_OpenFile(HDL_PLAY ulChannel, const char* pFileName);

/*****************************************************************************
 函数名称：IVS_PLAY_SetFileTimeRange
 功能描述：设置文件播放时间范围
 输入参数：ulChannel  通道号;
           beg        起始时间
           end        结束时间
 输出参数：NA
 返 回 值：成功:IVS_SUCCEED;失败:IVS_FAIL;
*****************************************************************************/
IVS_PLAYER_API int __stdcall IVS_PLAY_SetFileTimeRange(HDL_PLAY ulChannel, unsigned int beg, unsigned int end);

/*****************************************************************************
 函数名称：IVS_PLAY_CloseFile
 功能描述：打开文件;
 输入参数：ulChannel    通道号;
 输出参数：NA
 返 回 值：成功:IVS_SUCCEED;失败:IVS_FAIL;
*****************************************************************************/
IVS_PLAYER_API int __stdcall IVS_PLAY_CloseFile(HDL_PLAY ulChannel);

/*****************************************************************************
 函数名称：IVS_SetWaterMarkVerify()
 功能描述：设置开启/停止校验水印
 输入参数：ulChannel 通道号:  
         ：iStart 0-开始校验，1-停止校验
 输出参数：NA
 返 回 值：成功:IVS_SUCCEED;失败:IVS_FAIL;
 *****************************************************************************/
IVS_PLAYER_API int __stdcall IVS_PLAY_SetWaterMarkVerify(HDL_PLAY ulChannel, int iStart);

/*****************************************************************************
 函数名称：IVS_PLAY_GetMediaInfo()
 功能描述：获取视频质量参数
 输入参数：ulChannel 通道号:  
 输出参数：pMediaInfo 视频质量参数
 返 回 值：成功:IVS_SUCCEED;失败:IVS_FAIL;
 *****************************************************************************/
IVS_PLAYER_API int __stdcall IVS_PLAY_GetMediaInfo(HDL_PLAY ulChannel, IVS_PLAY_STATUS* pMediaInfo);

/*****************************************************************************
 函数名称：IVS_PLAY_GetLostPacketRate()
 功能描述：获取当前播放时间
 输入参数：ulChannel 通道号
 输出参数：puPlayTime 当前播放时间
 返 回 值：成功:IVS_SUCCEED;失败:IVS_FAIL;
 *****************************************************************************/
IVS_PLAYER_API int __stdcall IVS_PLAY_GetPlayedTime(HDL_PLAY ulChannel,unsigned long long *puPlayTime);

/*****************************************************************************
 函数名称：IVS_PLAY_GetCurrentFrameTick
 功能描述：获取当前帧时间戳
 输入参数：ulChannel 通道号
 输出参数：pTick 当前时间戳
 返 回 值：成功:IVS_SUCCEED;失败:IVS_FAIL;
 *****************************************************************************/
IVS_PLAYER_API int __stdcall IVS_PLAY_GetCurrentFrameTick(HDL_PLAY ulChannel, unsigned long long *pTick);

/*****************************************************************************
 函数名称：IVS_PLAY_SetPlayTime
 功能描述：设置播放时间
 输入参数：ulChannel 通道号
			tm 播放时间
 返 回 值：成功:IVS_SUCCEED;失败:IVS_FAIL;
 *****************************************************************************/
IVS_PLAYER_API int __stdcall IVS_PLAY_SetPlayTime(HDL_PLAY ulChannel, time_t tm);

/*****************************************************************************
 函数名称：IVS_PLAY_SetDownLoadTimeSpan
 功能描述：设置下载时间范围
 输入参数：ulChannel 通道号
		   tmBeg   开始时间
		   tmEnd   停止时间
		   bReportFinsh 是否上报
 返 回 值：成功:IVS_SUCCEED;失败:IVS_FAIL;
 *****************************************************************************/
IVS_PLAYER_API int __stdcall IVS_PLAY_SetDownLoadTimeSpan(HDL_PLAY ulChannel, time_t tmBeg, time_t tmEnd, int bReportFinsh);


/*****************************************************************************
 函数名称：IVS_PLAY_SetPlayQualityMode()
 功能描述：设置实况播放模式：清晰、流畅
 输入参数：ulChannel 通道号
		   iPlayQualityMode 播放模式
 输出参数：NA
 返 回 值：成功:IVS_SUCCEED;失败:IVS_FAIL;
 *****************************************************************************/
IVS_PLAYER_API int __stdcall IVS_PLAY_SetPlayQualityMode(HDL_PLAY ulChannel,int iPlayQualityMode);

/*****************************************************************************
 函数名称：IVS_PLAY_SetDisplayDelay()
 功能描述：设置播放延时，网络差环境调用该函数
 输入参数：ulChannel 通道号
		   uMs  毫秒
 输出参数：NA
 返 回 值：成功:IVS_SUCCEED;失败:IVS_FAIL;
 *****************************************************************************/
IVS_PLAYER_API int __stdcall IVS_PLAY_SetDisplayDelay(HDL_PLAY ulChannel, unsigned int uMs);


/*****************************************************************************
 函数名称：IVS_PLAY_SetDisplayBufferFrameMaxNum()
 功能描述：设置播放器最大缓存解码后帧数
 输入参数：ulChannel 通道号
		   uMs  毫秒
 输出参数：NA
 返 回 值：成功:IVS_SUCCEED;失败:IVS_FAIL;
 *****************************************************************************/
IVS_PLAYER_API int __stdcall IVS_PLAY_SetDisplayBufferFrameMaxNum(HDL_PLAY ulChannel, unsigned int uFrameNum);


/*****************************************************************************
 函数名称：IVS_PLAY_ShowPlayStatis()
 功能描述：播放界面显示统计信息
 输入参数：ulChannel  通道号
		   hWnd       窗口句柄
		   enable     是否使能
 输出参数：NA
 返 回 值：成功:IVS_SUCCEED;失败:IVS_FAIL;
 *****************************************************************************/
IVS_PLAYER_API int __stdcall IVS_PLAY_ShowPlayStatis(HDL_PLAY ulChannel, HWND hWnd, int enable);

/*****************************************************************************
 函数名称：IVS_PLAY_ResetData
 功能描述：清空数据;
 输入参数：ulChannel    通道号;
 输出参数：NA
 返 回 值：成功:IVS_SUCCEED;失败:IVS_FAIL;
 *****************************************************************************/
IVS_PLAYER_API void __stdcall IVS_PLAY_ResetData(HDL_PLAY ulChannel);

/*****************************************************************************
 函数名称：IVS_PLAY_SetResetFlag
 功能描述：设置复位标记;
 输入参数：ulChannel    通道号;
		   bIsReset  是否复位
 输出参数：NA
 返 回 值：成功:IVS_SUCCEED;失败:IVS_FAIL;
 *****************************************************************************/
IVS_PLAYER_API void __stdcall IVS_PLAY_SetResetFlag(HDL_PLAY ulChannel, bool bIsReset);

/*****************************************************************************
 函数名称：IVS_PLAY_StartRecord
 功能描述：开始录像
 输入参数：ulChannel 通道号
		   pCamCode  相机编码
		   pCamName  相机名称
		   pName     文件名
		   pParameter 本地录像配置参数
		   bAssociatedAudio 是否为相关语音
 输出参数：NA
 返 回 值：成功:IVS_SUCCEED;失败:IVS_FAIL;
 *****************************************************************************/
IVS_PLAYER_API int IVS_PLAY_StartRecord(HDL_PLAY ulChannel, const char *pCamCode, const char *pCamName, 
	                  const char *pName, const IVS_LOCAL_RECORD_CONFIG *pParameter, bool bAssociatedAudio);

/*****************************************************************************
函数名称：IVS_PLAY_StopRecord
功能描述：停止录像
输入参数：ulChannel 通道号
输出参数：NA
返 回 值：成功:IVS_SUCCEED;失败:IVS_FAIL;
*****************************************************************************/
IVS_PLAYER_API  int IVS_PLAY_StopRecord(HDL_PLAY ulChannel);

/*****************************************************************************
函数名称：IVS_PLAY_GetRecordStatis
功能描述：获取录像信息
输入参数：ulChannel 通道号
输出参数：pTime 录像时间
		  pSpeed 录像速率
		  pTotalSz 录像大小
返 回 值：成功:IVS_SUCCEED;失败:IVS_FAIL;
*****************************************************************************/
IVS_PLAYER_API int IVS_PLAY_GetRecordStatis(HDL_PLAY ulChannel, 
	        unsigned int *pTime, unsigned int *pSpeed, unsigned long long *pTotalSz);

/*****************************************************************************
 函数名称：IVS_PLAY_Snapshot
 功能描述：本地抓拍单张图片
 输入参数：pSavePath		图片保存路径；
		   ulSnapshotFormat	图片保存类型
 输出参数：NA
 返 回 值：成功:IVS_SUCCEED;失败:IVS_FAIL;
 *****************************************************************************/
IVS_PLAYER_API int IVS_PLAY_Snapshot(HDL_PLAY ulChannel, const char *pSavePath, unsigned long ulSnapshotFormat);

/*****************************************************************************
 函数名称：IVS_PLAY_SnapshotRect
 功能描述：本地抓拍单张图片
 输入参数：pSavePath			图片保存路径；
		   ulSnapshotFormat	图片保存类型
		   Rct   矩形位置信息
 输出参数：NA
 返 回 值：成功:IVS_SUCCEED;失败:IVS_FAIL;
 *****************************************************************************/
IVS_PLAYER_API int IVS_PLAY_SnapshotRect(HDL_PLAY ulChannel, const char *pSavePath, unsigned long ulSnapshotFormat, const RECT *Rct);

/*****************************************************************************
 函数名称：IVS_PLAY_SetDrawCallBack
 功能描述：设置绘图回调
 输入参数：ulChannel  通道号
           Callback   回调函数
           pUser      用户参数
 输出参数：NA
 返 回 值：成功:IVS_SUCCEED;失败:IVS_FAIL;
 *****************************************************************************/
IVS_PLAYER_API int __stdcall IVS_PLAY_SetDrawCallBack(HDL_PLAY ulChannel, DRAW_CALLBACK Callback, void *pUser);

/*****************************************************************************
 函数名称：IVS_PLAY_SetDrawCallBack
 功能描述：设置绘图回调扩展接口
 输入参数：ulChannel  通道号
		   hWnd       窗口句柄
           Callback   回调函数
           pUser      用户参数
 输出参数：NA
 返 回 值：成功:IVS_SUCCEED;失败:IVS_FAIL;
 *****************************************************************************/
IVS_PLAYER_API int __stdcall IVS_PLAY_SetDrawCallBackEx(HDL_PLAY ulChannel, HWND hWnd, DRAW_CALLBACK callback, void *pUser);

/*****************************************************************************
 函数名称：IVS_PLAY_StartAudioCapture
 功能描述：开启语音采集
 输入参数： ulChannel  通道号
			conf       语音抓拍配置参数
			Callback   回调函数
			pUser      用户数据
 输出参数：无
 返 回 值： ULONG
 *****************************************************************************/
IVS_PLAYER_API int  __stdcall IVS_PLAY_StartAudioCapture(
	                            HDL_PLAY ulChannel,
	                            AUDIO_CAPTURE_CONF *conf,
	                            AUDIO_CAPTURE_CALLBACK Callback, 
	                            void *pUser
	                            );
								
/*****************************************************************************
 函数名称：IVS_PLAY_StopAudioCapture
 功能描述：停止语音采集
 输入参数： ulChannel  通道号
 输出参数：无
 返 回 值： ULONG
 *****************************************************************************/
IVS_PLAYER_API void __stdcall IVS_PLAY_StopAudioCapture(HDL_PLAY ulChannel);


/*****************************************************************************
 函数名称：IVS_PLAY_StartAudioCapture
 功能描述：提取音频对外回调
 输入参数： ulChannel  通道号
			pFileName  文件名称
			bLoop   是否循环
			conf      语音抓拍配置参数
			Callback  回调函数
			pUser     用户数据
 输出参数：无
 返 回 值： ULONG
 *****************************************************************************/
IVS_PLAYER_API int __stdcall IVS_PLAY_StartFileAudioCapture (
                                HDL_PLAY ulChannel,
                                const char *pFileName,
                                int bLoop,
                                AUDIO_CAPTURE_CONF *conf,
	                            AUDIO_CAPTURE_CALLBACK Callback, 
	                            void *pUser
	                           );

/*****************************************************************************
 函数名称：IVS_PLAY_StopFileAudioCapture
 功能描述：停止音频对外回调
 输入参数： ulChannel  通道号
 输出参数：无
 返 回 值： ULONG
 *****************************************************************************/
IVS_PLAYER_API  void __stdcall IVS_PLAY_StopFileAudioCapture(HDL_PLAY ulChannel);




/*****************************************************************************
 函数名称：IVS_PLAY_SetWaitForVertiBlank
 功能描述：设置垂直同步使能
 输入参数：ulChannel  通道号
			bEnable    是否使能
 输出参数：无
 返 回 值： int
*****************************************************************************/
IVS_PLAYER_API  int __stdcall IVS_PLAY_SetWaitForVertiBlank(HDL_PLAY ulChannel, int bEnable);


/*****************************************************************************
 函数名称：IVS_PLAY_SetVideoEffect
 功能描述：设置视频质量
 输入参数：ulChannel  通道号
		   lBright     明亮度
           lContrast	对比度
		   lSaturation  饱和度
		   lHue     色度
 输出参数：无
 返 回 值：int
*****************************************************************************/
IVS_PLAYER_API int __stdcall IVS_PLAY_SetVideoEffect(
                                  HDL_PLAY ulChannel,
                                  long lBright,
								  long lContrast,
								  long lSaturation, 
								  long lHue);




/*****************************************************************************
 函数名称：IVS_PLAY_EnableOptimization
 功能描述：开启黑屏优化
 输入参数：iEnable  开启标识
 输出参数：无
 返 回 值：int
*****************************************************************************/
IVS_PLAYER_API int __stdcall IVS_PLAY_EnableOptimization(HDL_PLAY ulChannel, int iEnable);

#endif //__IVS_PLAYER_H__

