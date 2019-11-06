#pragma once

#ifdef MEDIATOOL_EXPORTS
#define MEDIATOOL_API __declspec(dllexport)
#else
#define MEDIATOOL_API __declspec(dllimport)
#endif

#include <windows.h>


void ConvertYUYtoRGB32(DWORD width, DWORD height, BYTE pRGB[], BYTE SData[]);
void ConvertYUYtoRGB24(DWORD width, DWORD height, BYTE pRGB[], BYTE SData[]);

int convert_yuv_to_rgb(unsigned char *yuv, unsigned char *rgb, unsigned int width, unsigned int height);


MEDIATOOL_API void YUVtoRGB24(unsigned char *src0, unsigned char *src1, unsigned char *src2,
	unsigned char *dst_ori, int width, int height);


MEDIATOOL_API void YUV_TO_RGB24(unsigned char *puc_y, int stride_y,
	unsigned char *puc_u, unsigned char *puc_v, int stride_uv,
	unsigned char *puc_out, int width_y, int height_y, int stride_out);

MEDIATOOL_API void YV12_to_RGB24(unsigned char* pYV0, unsigned char* pYV1, unsigned char* pYV2, int w, int h, unsigned char* pRGB24);

// 旋转180 度
// src 图像数据
// srcW 图像宽度
// srcH 图像高度
// channel 图像通道,如果是RGB,BGR,=3, RGBA = 4,GRAY=1
MEDIATOOL_API int RotationDown(unsigned char * src, int srcW, int srcH, int channel);



/*
sample:ColorSpaceChange_FFmpeg((BYTE*)pic, AV_PIX_FMT_YUV420P, pRGB, AV_PIX_FMT_RGB24, w, h);// yuv420(yv12) ---> rgb
param src_pix_fmt : AVPixelFormat  : AV_PIX_FMT_YUV420P=0  AV_PIX_FMT_YUYV422=1    AV_PIX_FMT_RGB24=2    AV_PIX_FMT_BGR24=3
param dest_pix_fmt : AVPixelFormat
*/
MEDIATOOL_API bool ColorSpaceChange_FFmpeg(unsigned char* src, int src_pix_fmt, unsigned char* dest, int dest_pix_fmt, int width, int height);

MEDIATOOL_API bool ColorSpaceChange_FFmpeg(unsigned char* src, int src_pix_fmt, unsigned char* dest, int dest_pix_fmt, int src_width, int src_height, int dest_width, int dest_height);
