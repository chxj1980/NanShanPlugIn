// NVSStreamPlayLib.cpp : 定义 DLL 应用程序的入口点。
//

#include "stdafx.h"
#include "NVSCoreBiz.h"
#include "NVSProcessByDVR.h"

NVSCoreBiz GL_CoreBiz;
NVSProcessByDVR GL_ProcessByDVR;

#ifdef _MANAGED
#pragma managed(push, off)
#endif

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
	//_CrtSetBreakAlloc(3488);
    return TRUE;
}
