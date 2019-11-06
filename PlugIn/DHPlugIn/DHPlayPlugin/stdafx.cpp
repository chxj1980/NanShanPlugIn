// stdafx.cpp : 只包括标准包含文件的源文件
// DHPlayPlugin.pch 将作为预编译头
// stdafx.obj 将包含预编译类型信息

#include "stdafx.h"

extern "C" IDVRHandler* getHandler()
{
	IDVRHandler* pClass = new DHPlayHandle();

    return pClass;
}