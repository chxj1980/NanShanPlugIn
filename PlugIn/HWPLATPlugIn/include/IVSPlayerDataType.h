/********************************************************************
    filename	: 	IVSPlayerDataType.h
    author		:	z00201790
    created		:	2012/10/23
    description	:	�ṩIVS���ſ����ݽṹ�������롢�ص���
    copyright	:	Copyright (C) 2011-2015
    history		:	2012/10/23 ��ʼ�汾;
 *********************************************************************/
#ifndef IVS_PLAYER_DATA_TYPE_H
#define IVS_PLAYER_DATA_TYPE_H

#include "IVS_PlayerTypes.h"
#include "ivs_error.h"

// ģ����;
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


// ������Ϣ
typedef struct
{
    unsigned int       Frames; // �Ѿ�����֡��
	unsigned long long PalyTime; //����
    float              FrameRate;
    unsigned int  Width;
    unsigned int  Height;
	long          VideoStatus;
	long          AudioStatus;
	unsigned long Reserved1;
	unsigned long Reserved2;
} MEDIA_INFO;

// ��Ⱦͳ�Ʋ���������DEBUG
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
	STREAM_REALTIME     = 0, // ʵʱ��Ƶ
	STREAM_LOCALFILE    = 1, // �����ļ�
	STREAM_REMOTEFILE   = 2  // ƽ̨�ļ� 
} STREAM_MODE;

typedef struct
{
    unsigned char*  pY;
    unsigned char*  pU;
    unsigned char*  pV;
    unsigned int  uiPitch;            // ƽ����ڴ�ռ�ó���(Ҳ�������Stride)
    unsigned int  uiWidth;            // �����
    unsigned int  uiHeight;           // �����
    unsigned int  uiPictureFormat;    // �����ʽ,�ο�IVS_PICTURE_FORMAT
    unsigned int  uiTimeStamp;        // RTPʱ���
    unsigned long long  ullTimeTick;        // ʱ����Ϣ����λ����
    unsigned int	uiGopSequence;		// GOP����
    unsigned char	cReserve[32];
    unsigned int  uiFrameType;        //֡����(I P)
}IVS_VIDEO_FRAME;


#endif //IVS_PLAYER_DATA_TYPE_H

