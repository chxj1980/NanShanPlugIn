// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 特定于项目的包含文件
//

#pragma once

// 如果必须将位于下面指定平台之前的平台作为目标，请修改下列定义。
// 有关不同平台对应值的最新信息，请参考 MSDN。
#ifndef WINVER				// 允许使用特定于 Windows XP 或更高版本的功能。
#define WINVER 0x0501		// 将此值更改为相应的值，以适用于 Windows 的其他版本。
#endif

#ifndef _WIN32_WINNT		// 允许使用特定于 Windows XP 或更高版本的功能。
#define _WIN32_WINNT 0x0501	// 将此值更改为相应的值，以适用于 Windows 的其他版本。
#endif						

#ifndef _WIN32_WINDOWS		// 允许使用特定于 Windows 98 或更高版本的功能。
#define _WIN32_WINDOWS 0x0410 // 将此值更改为适当的值，以指定将 Windows Me 或更高版本作为目标。
#endif

#ifndef _WIN32_IE			// 允许使用特定于 IE 6.0 或更高版本的功能。
#define _WIN32_IE 0x0600	// 将此值更改为相应的值，以适用于 IE 的其他版本。
#endif

#define WIN32_LEAN_AND_MEAN		// 从 Windows 头中排除极少使用的资料
// Windows 头文件:
#include <windows.h>

#include "NVSTypeDefine.h"

// TODO: 在此处引用程序需要的其他头文件
#include <Ice/Application.h>
#include <Ice/Ice.h>
#include <IceUtil/UUID.h>

#include "NVSIndexData.h"
#include "NVSIndex4Monitor.h"
#include "NVSIndex4Stream.h"
#include "NVSStreamServiceAPI.h"
#include "NVSSDKDef_x64.h"
#include "NVSSDKFunctions.h"
#include <string>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;
#include "IniFileParam.h"
#include "NVSStreamPlaySDK.h"
#include "NVSCoreBiz.h"
#include "NVSErrorManage.h"

//ICE
typedef struct _ServerInfo
{
	int    nType;
	int	   nPort;
	string strIp;
	string strInterFace;
	_ServerInfo()
	{
		nType = 0;
		nPort = 0;
		strIp = "";
		strInterFace = "";	
	}
	_ServerInfo& operator =(_ServerInfo info)
	{
		nType = info.nType;
		nPort = info.nPort;
		strIp = info.strIp;
		strInterFace = info.strInterFace;
		return *this;
	}

}ServerInfo;