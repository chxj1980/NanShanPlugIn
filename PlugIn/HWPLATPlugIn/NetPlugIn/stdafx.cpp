// stdafx.cpp : ֻ������׼�����ļ���Դ�ļ�
// PlugIn.pch ����ΪԤ����ͷ
// stdafx.obj ������Ԥ����������Ϣ

#include "stdafx.h"

// TODO: �� STDAFX.H ��
// �����κ�����ĸ���ͷ�ļ����������ڴ��ļ�������


extern "C" IDVRHandler * getHandler()
{
	NetPlugIn* pClass = new NetPlugIn();
	return pClass;
}