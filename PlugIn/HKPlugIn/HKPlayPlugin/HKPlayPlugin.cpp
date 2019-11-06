// HKPlayPlugin.cpp : ���� DLL �ĳ�ʼ�����̡�
//

#include "stdafx.h"
#include "HKPlayPlugin.h"
#include "HKPlayHandle.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//
//TODO: ����� DLL ����� MFC DLL �Ƕ�̬���ӵģ�
//		��Ӵ� DLL �������κε���
//		MFC �ĺ������뽫 AFX_MANAGE_STATE ����ӵ�
//		�ú�������ǰ�档
//
//		����:
//
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// �˴�Ϊ��ͨ������
//		}
//
//		�˺������κ� MFC ����
//		������ÿ��������ʮ����Ҫ������ζ��
//		��������Ϊ�����еĵ�һ�����
//		���֣������������ж������������
//		������Ϊ���ǵĹ��캯���������� MFC
//		DLL ���á�
//
//		�й�������ϸ��Ϣ��
//		����� MFC ����˵�� 33 �� 58��
//


// CHKPlayPluginApp

BEGIN_MESSAGE_MAP(CHKPlayPluginApp, CWinApp)
END_MESSAGE_MAP()


// CHKPlayPluginApp ����

CHKPlayPluginApp::CHKPlayPluginApp()
{
	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
	InitializeCriticalSection(&HKPlayHandle::m_Lock);
	InitializeCriticalSection(&HKPlayHandle::m_picLock);
}


// Ψһ��һ�� CHKPlayPluginApp ����

CHKPlayPluginApp theApp;


// CHKPlayPluginApp ��ʼ��

BOOL CHKPlayPluginApp::InitInstance()
{
	CWinApp::InitInstance();
	return TRUE;
}

int CHKPlayPluginApp::ExitInstance()
{
    // TODO: �ڴ����ר�ô����/����û���

    DeleteCriticalSection(&HKPlayHandle::m_Lock);
	DeleteCriticalSection(&HKPlayHandle::m_picLock);
    return CWinApp::ExitInstance();
}
