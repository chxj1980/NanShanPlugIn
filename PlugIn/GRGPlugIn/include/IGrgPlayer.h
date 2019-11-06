#pragma once
#include "typedef.h"
#include "player/IDecoder.h"

#ifdef	GRGPLAYER_EXPORTS
#define GRGPLAYER_API extern "C" __declspec(dllexport)
#else
#define GRGPLAYER_API extern "C" __declspec(dllimport)

#endif


#define DECODER_TYPE_FFMPEG_H264	1001	// FFMPEG H264
#define DECODER_TYPE_FFMPEG_H265	1002	// FFMPEG H265
#define DECODER_TYPE_FFMPEG_MJPEG	1003	// FFMPEG MJPEG (调用到ffmpeg的AV_CODEC_ID_MJPEG解码器)

typedef void (CALLBACK* GPlay_VideoDrawCallBack)(long port, HDC hDc, int x, int y, int width, int height, int bmp_width, int bmp_height, void* nUser);
typedef void (CALLBACK* GPlay_DecodeDataCallBack)(long port, void* data, int colorspace, int width, int height, void* nUser);
typedef void (CALLBACK* GPlay_RealDataCallBack)(long port, void* data, int len, void* nUser);

#define GPLAY_EVENT_TYPE_VIDEO_TIMESTAMP	1
typedef void (CALLBACK* GPlay_EventCallBack)(long port, long type, void* data, int len, void* nUser);

class IGrgPlayer
{
public:
	virtual void Release() = 0;

	virtual bool Start(HWND hwnd, int decoder_type) = 0;
	virtual void Stop() = 0;
	virtual bool InputData(BYTE* buf, DWORD len) = 0;

	virtual int GetWidth() = 0;
	virtual int GetHeight() = 0;

	virtual void SetMagnifier(bool bSet) = 0;

	virtual void RegisterDrawFun(GPlay_VideoDrawCallBack DrawOSDFunc, void* nUser) = 0;
	virtual void SetDecodeDataCallBack(GPlay_DecodeDataCallBack func, void* nUser) = 0;
	virtual void SetRealDataCallBack(GPlay_RealDataCallBack func, void* nUser) = 0;
	virtual void SetEventCallBack(GPlay_EventCallBack func, void* nUser) = 0;

	virtual void Snap(char* filename) = 0;
};

GRGPLAYER_API IGrgPlayer* CreateGrgPlayer();
GRGPLAYER_API void ReleaseGrgPlayer(IGrgPlayer* pPlayer);

GRGPLAYER_API IGrgPlayer* CreatePsPlayer();
GRGPLAYER_API void ReleasePsPlayer(IGrgPlayer* pPlayer);


GRGPLAYER_API IGrgPlayer* CreateGBh264Player();