// stdafx.cpp : ֻ������׼�����ļ���Դ�ļ�
// HKPlayPlugin.pch ����ΪԤ����ͷ
// stdafx.obj ������Ԥ����������Ϣ

#include "stdafx.h"


extern "C" IDVRHandler* getHandler()
{
	IDVRHandler* pClass = new HKPlayHandle();
    return pClass;
}