// HKPlayPlugin.h : HKPlayPlugin DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CHKPlayPluginApp
// �йش���ʵ�ֵ���Ϣ������� HKPlayPlugin.cpp
//

class CHKPlayPluginApp : public CWinApp
{
public:
	CHKPlayPluginApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
public:
    virtual int ExitInstance();
};
