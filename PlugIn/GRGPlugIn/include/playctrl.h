#pragma once

#include <Windows.h>


#ifdef	GRGPLAYER_EXPORTS
#define GRGPLAYER_API extern "C" __declspec(dllexport)
#else
#define GRGPLAYER_API extern "C" __declspec(dllimport)

#endif

#define STDCALL __stdcall

#define GPLAY_VIDEO_ENCODE_TYPE_HIS_H264			1				// 海思H264
#define GPLAY_VIDEO_ENCODE_TYPE_HIS_H265			2				// 海思H265
#define GPLAY_VIDEO_ENCODE_TYPE_MJPEG				3				// MJPEG

//#define GPLAY_VIDEO_ENCODE_TYPE_FFMPEG_H264			1001			// FFMPEG H264
//#define GPLAY_VIDEO_ENCODE_TYPE_FFMPEG_H265			1002			// FFMPEG H265
//#define GPLAY_VIDEO_ENCODE_TYPE_FFMPEG_MJPEG		1003			// FFMPEG MJPEG (调用到ffmpeg的AV_CODEC_ID_MJPEG解码器)


typedef void (CALLBACK* GPlay_VideoDrawCallBack)(long port, HDC hDc, int x, int y, int width, int height, int bmp_width, int bmp_height, void* nUser);
typedef void (CALLBACK* GPlay_DecodeDataCallBack)(long port, void* data, int colorspace, int width, int height, void* nUser);

GRGPLAYER_API long STDCALL GPlay_SDKInit();
GRGPLAYER_API long STDCALL GPlay_CleanUp();

GRGPLAYER_API long STDCALL GPlay_GetPort(long* nPort);
GRGPLAYER_API long STDCALL GPlay_FreePort(long nPort);

GRGPLAYER_API void STDCALL GPlay_SetVideoDrawCallBack(long nPort, GPlay_VideoDrawCallBack cb, void* nUser);
GRGPLAYER_API void STDCALL GPlay_SetDecodeDataCallBack(long nPort, GPlay_DecodeDataCallBack cb, void* nUser);

GRGPLAYER_API long STDCALL GPlay_OpenStream(long nPort);
GRGPLAYER_API long STDCALL GPlay_CloseStream(long nPort);
GRGPLAYER_API long STDCALL GPlay_InputData(long nPort, PBYTE pBuf, DWORD nSize);
GRGPLAYER_API long STDCALL GPlay_Play(long nPort, HWND hWnd, long nEncodeType);
/*
param type : 1:满窗口，2：原始比例
*/
GRGPLAYER_API void STDCALL GPlay_SetPlayScale(long nPort, int type);
GRGPLAYER_API void STDCALL GPlay_SetMagnifier(long nPort, bool bSet);

GRGPLAYER_API long STDCALL GPlay_Stop(long nPort);

GRGPLAYER_API long STDCALL GPlay_PlayAudio(long nPort, long nEncodeType);
GRGPLAYER_API long STDCALL GPlay_StopAudio(long nPort);
GRGPLAYER_API long STDCALL GPlay_InputAudioData(long nPort, PBYTE pBuf, DWORD nSize);

GRGPLAYER_API long STDCALL GPlay_Snap(long nPort, char* filename);

