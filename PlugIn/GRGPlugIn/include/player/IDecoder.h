#pragma once

#ifdef MEDIATOOL_EXPORTS
#define MEDIATOOL_API __declspec(dllexport)
#else
#define MEDIATOOL_API __declspec(dllimport)
#endif

#define DECODER_TYPE_HIS_H264		1		// ��˼H264
#define DECODER_TYPE_HIS_H265		2		// ��˼H265
#define DECODER_TYPE_FFMPEG_H264	1001	// FFMPEG H264
#define DECODER_TYPE_FFMPEG_H265	1002	// FFMPEG H265
#define DECODER_TYPE_FFMPEG_MJPEG	1003	// FFMPEG MJPEG (���õ�ffmpeg��AV_CODEC_ID_MJPEG������)


// ��ɫ����
#define			HI_COLORTYPE_YUV422			1L		// YUYV YUYV ...��y = w*h��u��v=w/2*h                    16 bit per pix
//#define		HI_COLORTYPE_UYUV422		2L		// UYUV UYUV ...��y = w*h��u��v=w/2*h
#define			HI_COLORTYPE_YUV420			3L		// ��Y=w*h����u=(w/2)*(h/2)�����v=(w/2)*(h/2)    YV12   12 bit per pix
#define			HI_COLORTYPE_RGB24			15L
//#define		HI_COLORTYPE_RGB565			16L
//#define		HI_COLORTYPE_RGB32			17L


class IDecoder
{
public:
	virtual void Release() = 0;

	virtual bool DecoderInit(unsigned long lColorType) = 0;

	virtual char* InStreamData(char* pData, int nDataLength, int* pWidth, int* pHeight) = 0;

	virtual char* GetDataBuffer(int* pWidth, int* pHeight) = 0;

	
};

MEDIATOOL_API IDecoder* CreateDecoder(int decoder_type);
