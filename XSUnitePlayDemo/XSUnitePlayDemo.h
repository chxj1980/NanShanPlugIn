
// XSUnitePlayDemo.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CXSUnitePlayDemoApp: 
// �йش����ʵ�֣������ XSUnitePlayDemo.cpp
//

class CXSUnitePlayDemoApp : public CWinApp
{
public:
	CXSUnitePlayDemoApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CXSUnitePlayDemoApp theApp;