// stdafx.cpp : ֻ������׼�����ļ���Դ�ļ�
// SIPPlugIn.pch ����ΪԤ����ͷ
// stdafx.obj ������Ԥ����������Ϣ

#include "stdafx.h"

// TODO: �� STDAFX.H �������κ�����ĸ���ͷ�ļ���
//�������ڴ��ļ�������


extern "C" IDVRHandler *getHandler()
{
	SIPHandler* pHandler = new SIPHandler();
	return pHandler;
}