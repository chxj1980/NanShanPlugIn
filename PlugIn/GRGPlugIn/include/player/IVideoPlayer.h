#pragma once

#ifdef MEDIATOOL_EXPORTS
#define MEDIATOOL_API __declspec(dllexport)
#else
#define MEDIATOOL_API __declspec(dllimport)
#endif
#include <Windows.h>

class IYuvPlayer
{
public:
	virtual void Release() = 0;
	virtual bool Start(HWND hwnd, DWORD fourcc, int bitcount) = 0;
	virtual void Stop() = 0;
	virtual bool InputData(BYTE* buf, DWORD len, int w, int h) = 0;

	/*
	param type : 1:满窗口，2：原始比例
	*/
	virtual void SetScale(int type) = 0;
	virtual void SetMagnifier(bool bSet) = 0;

	virtual void RegisterDrawFun(void* DrawOSDFunc, void* nUser) = 0;
};

MEDIATOOL_API IYuvPlayer* CreateYuvPlayer();



#define	DECODER_TYPE_H264	1
#define	DECODER_TYPE_H265	2

class IVideoPlayer
{
public:
	virtual void Release() = 0;
	virtual bool Start(HWND hwnd, int decoder_type) = 0;
	virtual void Stop() = 0;
	virtual bool InputData(BYTE* buf, DWORD len) = 0;

};

MEDIATOOL_API IVideoPlayer* CreateVideoPlayer();


MEDIATOOL_API bool TestSuportColorSpace(HWND hwnd, DWORD fourcc, int bitcount);