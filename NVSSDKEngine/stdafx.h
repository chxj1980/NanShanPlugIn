// stdafx.h : 标准系统包含文件的包含文件，
// 或是常用但不常更改的项目特定的包含文件
//
#ifndef stdafx_h__
#define stdafx_h__



#ifdef _WIN32

#define WIN32_LEAN_AND_MEAN		// 从 Windows 头中排除极少使用的资料
// Windows 头文件:
#include <windows.h>
#include <direct.h>
#include <io.h>
#define ACCESS _access
#define MKDIR(a) _mkdir((a))


#else
#define MAX_PATH 260
#include <string.h>
#include <pthread.h>
typedef pthread_mutex_t   CRITICAL_SECTION;
#define EnterCriticalSection	pthread_mutex_lock
#define LeaveCriticalSection	pthread_mutex_unlock
#define DeleteCriticalSection   pthread_mutex_destroy
#define InitializeCriticalSection(a) pthread_mutex_init(a, NULL)

#include <stdarg.h>
#include <sys/stat.h>
#define ACCESS access
#define MKDIR(a) mkdir((a),0755)


#include <dlfcn.h>
#define HINSTANCE void*
#define LoadLibrary(a) dlopen(a , RTLD_LAZY)
#define GetProcAddress dlsym
#define FreeLibrary    dlclose

#include <unistd.h>
#define GetModuleFileName( a, b, c ) getcwd(b , c)

#endif

#pragma warning(disable : 4996)

// TODO: 在此处引用程序要求的附加头文件
#include "NVSSDKFunctions.h"
#include "NVSHandlerMgr.h"
extern NVSHandlerMgr gNVSHandlerMgr;

#endif // stdafx_h__
