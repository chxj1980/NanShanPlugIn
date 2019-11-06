/********************************************************************
    filename	: 	IVSPlayerDataType.h
    author		:	z00201790
    created		:	2012/10/23
    description	:	提供IVS播放库数据结构、错误码、回调等
    copyright	:	Copyright (C) 2011-2015
    history		:	2012/10/23 初始版本;
 *********************************************************************/
#ifndef IVS_PLAYER_DATA_TYPE_H
#define IVS_PLAYER_DATA_TYPE_H

#include "IVS_PlayerTypes.h"
#include "ivs_error.h"

// 模块句柄;
typedef void * IVS_HANDLE;


typedef struct {
	unsigned int uVideoCodeRate;
	unsigned int uAvgVideoCodeRate;
	unsigned int uAudioCodeRate;
	unsigned int uAvgAudioCodeRate;
	unsigned int uFrameListSize;
	unsigned int uUsedMemBlockNum;
} CODE_RATE_INFO;



typedef struct 
{
	time_t tmDownLoadBeg;
	time_t tmDwonLoadEnd;
	int    bReportFinish;
} DOWNLOAD_PARAM;

typedef struct {
	unsigned int FileSize;
	unsigned int TimeSpan;
	unsigned int DiskWarnMB;
	unsigned int DiskFullMB;
	char         Directory[MAX_PATH]; 
} RECORD_CONFIG;


// 播放信息
typedef struct
{
    unsigned int       Frames; // 已经播放帧数
	unsigned long long PalyTime; //毫秒
    float              FrameRate;
    unsigned int  Width;
    unsigned int  Height;
	long          VideoStatus;
	long          AudioStatus;
	unsigned long Reserved1;
	unsigned long Reserved2;
} MEDIA_INFO;

// 渲染统计参数，用于DEBUG
typedef struct 
{
	unsigned long InFrames;
	unsigned long DropFrames;
	unsigned long InFrameRate;
	unsigned long OutFrames;
	unsigned long SkipFrames;
	double        OutFrameRate;
	unsigned int  Width;
	unsigned int  Height;
    unsigned long VListSz;
	unsigned long AListSz;
	unsigned int  uLastRtpStamp;
	unsigned long long PlayedTime;
	unsigned long long FrameTick;
} RENDER_STATIS;


typedef enum {
	STREAM_REALTIME     = 0, // 实时视频
	STREAM_LOCALFILE    = 1, // 本地文件
	STREAM_REMOTEFILE   = 2  // 平台文件 
} STREAM_MODE;

typedef struct
{
    unsigned char*  pY;
    unsigned char*  pU;
    unsigned char*  pV;
    unsigned int  uiPitch;            // 平面的内存占用长度(也叫做跨度Stride)
    unsigned int  uiWidth;            // 画面宽
    unsigned int  uiHeight;           // 画面高
    unsigned int  uiPictureFormat;    // 画面格式,参考IVS_PICTURE_FORMAT
    unsigned int  uiTimeStamp;        // RTP时间戳
    unsigned long long  ullTimeTick;        // 时标信息，单位毫秒
    unsigned int	uiGopSequence;		// GOP序列
    unsigned char	cReserve[32];
    unsigned int  uiFrameType;        //帧类型(I P)
}IVS_VIDEO_FRAME;


#endif //IVS_PLAYER_DATA_TYPE_H

