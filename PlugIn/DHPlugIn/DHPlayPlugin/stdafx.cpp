// stdafx.cpp : ֻ������׼�����ļ���Դ�ļ�
// DHPlayPlugin.pch ����ΪԤ����ͷ
// stdafx.obj ������Ԥ����������Ϣ

#include "stdafx.h"

extern "C" IDVRHandler* getHandler()
{
	IDVRHandler* pClass = new DHPlayHandle();

    return pClass;
}