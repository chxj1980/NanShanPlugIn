// DHPlayPlugin.cpp : ���� DLL �ĳ�ʼ�����̡�
//

#include "stdafx.h"
#include "GRGPlayPlugin.h"
#include "GRGPlayHandle.h"

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


// CDHPlayPluginApp

BEGIN_MESSAGE_MAP(CDHPlayPluginApp, CWinApp)
END_MESSAGE_MAP()


// CDHPlayPluginApp ����

CDHPlayPluginApp::CDHPlayPluginApp()
{
	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
	InitializeCriticalSection(&GRGPlayHandle::m_Lock);
}


// Ψһ��һ�� CDHPlayPluginApp ����

CDHPlayPluginApp theApp;


// CDHPlayPluginApp ��ʼ��

BOOL CDHPlayPluginApp::InitInstance()
{
	CWinApp::InitInstance();


	return TRUE;
}

int CDHPlayPluginApp::ExitInstance()
{
    // TODO: �ڴ����ר�ô����/����û���
	DeleteCriticalSection(&GRGPlayHandle::m_Lock);


    return CWinApp::ExitInstance();
}
