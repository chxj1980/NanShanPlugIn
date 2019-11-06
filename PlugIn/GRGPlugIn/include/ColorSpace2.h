#pragma once
#ifdef MEDIATOOL_EXPORTS
#define MEDIATOOL_API __declspec(dllexport)
#else
#define MEDIATOOL_API __declspec(dllimport)
#endif

#include <Windows.h>

class MEDIATOOL_API ColorSpace
{
public:
	ColorSpace( );
	virtual ~ColorSpace( );

public:
	/*RGB555*/
	static void __stdcall rgb555_to_rgb555(void* d,void* s,unsigned int l);
	static void __stdcall rgb555_to_bgr555(void* d,void* s,unsigned int l);
	static void __stdcall rgb555_to_rgb565(void* d,void* s,unsigned int l);
	static void __stdcall rgb555_to_bgr565(void* d,void* s,unsigned int l);
	static void __stdcall rgb555_to_rgb888(void* d,void* s,unsigned int l);
	static void __stdcall rgb555_to_bgr888(void* d,void* s,unsigned int l);
	static void __stdcall rgb555_to_rgb8888(void* d,void* s,unsigned int l);
	static void __stdcall rgb555_to_bgr8888(void* d,void* s,unsigned int l);
	/*RGB565*/
	static void __stdcall rgb565_to_rgb555(void* d,void* s,unsigned int l);
	static void __stdcall rgb565_to_bgr555(void* d,void* s,unsigned int l);
	static void __stdcall rgb565_to_rgb565(void* d,void* s,unsigned int l);
	static void __stdcall rgb565_to_bgr565(void* d,void* s,unsigned int l);
	static void __stdcall rgb565_to_rgb888(void* d,void* s,unsigned int l);
	static void __stdcall rgb565_to_bgr888(void* d,void* s,unsigned int l);
	static void __stdcall rgb565_to_rgb8888(void* d,void* s,unsigned int l);
	static void __stdcall rgb565_to_bgr8888(void* d,void* s,unsigned int l);
	/*RGB888*/
	static void __stdcall rgb888_to_rgb555(void* d,void* s,unsigned int l);
	static void __stdcall rgb888_to_bgr555(void* d,void* s,unsigned int l);
	static void __stdcall rgb888_to_rgb565(void* d,void* s,unsigned int l);
	static void __stdcall rgb888_to_bgr565(void* d,void* s,unsigned int l);
	static void __stdcall rgb888_to_rgb888(void* d,void* s,unsigned int l);
	static void __stdcall rgb888_to_bgr888(void* d,void* s,unsigned int l);
	static void __stdcall rgb888_to_rgb8888(void* d,void* s,unsigned int l);
	static void __stdcall rgb888_to_bgr8888(void* d,void* s,unsigned int l);
	/*RGB8888*/
	static void __stdcall rgb8888_to_rgb555(void* d,void* s,unsigned int l);
	static void __stdcall rgb8888_to_bgr555(void* d,void* s,unsigned int l);
	static void __stdcall rgb8888_to_rgb565(void* d,void* s,unsigned int l);
	static void __stdcall rgb8888_to_bgr565(void* d,void* s,unsigned int l);
	static void __stdcall rgb8888_to_rgb888(void* d,void* s,unsigned int l);
	static void __stdcall rgb8888_to_bgr888(void* d,void* s,unsigned int l);
	static void __stdcall rgb8888_to_rgb8888(void* d,void* s,unsigned int l);
	static void __stdcall rgb8888_to_bgr8888(void* d,void* s,unsigned int l);

	/*YUY2*/
	static int __stdcall YUV2RGB(void* pYUV, void* pRGB, int width, int height, bool alphaYUV, bool alphaRGB);

	/*YUV*/
	//wait!!
	
	/*YUV2*/
	//wait!!
	
	/*HSV*/
	//wait!!
	
	/*others*/
	static void __stdcall zero_memory(void* d,unsigned int l);
	static void __stdcall memory_copy(void* d,void* s,unsigned int l);
	static void __stdcall flip_bmp(void* s,int w,int h,int c);
	static void __stdcall mirror_bmp(void* s,int w,int h,int c);

};
