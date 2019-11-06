
// XSUnitePlayDemoDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "XSUnitePlayDemo.h"
#include "XSUnitePlayDemoDlg.h"
#include "afxdialogex.h"
#include <direct.h>
#include "DatabaseClient.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CXSUnitePlayDemoDlg �Ի���
CXSUnitePlayDemoDlg *__pDlg = NULL;


CXSUnitePlayDemoDlg::CXSUnitePlayDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_XSUNITEPLAYDEMO_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CXSUnitePlayDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PLAYWND, m_PlayWnd);
	DDX_Control(pDX, IDC_MSG, m_MsgBox);
	DDX_Control(pDX, IDC_PLAYSLIDER, m_PlayCtrl);
	DDX_Control(pDX, IDC_PLAYWND2, m_PlayWnd2);
	DDX_Control(pDX, IDC_PLAYWND3, m_PlayWnd3);
	DDX_Control(pDX, IDC_PLAYWND4, m_PlayWnd4);
}

BEGIN_MESSAGE_MAP(CXSUnitePlayDemoDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDCANCEL, &CXSUnitePlayDemoDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_REALSTART, &CXSUnitePlayDemoDlg::OnBnClickedRealstart)
	ON_BN_CLICKED(IDC_REALSTOP, &CXSUnitePlayDemoDlg::OnBnClickedRealstop)
	ON_BN_CLICKED(IDC_PLAYBACK, &CXSUnitePlayDemoDlg::OnBnClickedPlayback)
	ON_BN_CLICKED(IDC_STOPPLAY, &CXSUnitePlayDemoDlg::OnBnClickedStopplay)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BUTTON10, &CXSUnitePlayDemoDlg::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON11, &CXSUnitePlayDemoDlg::OnBnClickedButton11)
	ON_BN_CLICKED(IDC_BUTTON16, &CXSUnitePlayDemoDlg::OnBnClickedButton16)
	ON_BN_CLICKED(IDC_AUTOSTART, &CXSUnitePlayDemoDlg::OnBnClickedAutostart)
	ON_BN_CLICKED(IDC_AUTOSTOP, &CXSUnitePlayDemoDlg::OnBnClickedAutostop)
	ON_WM_RBUTTONDOWN()
	ON_COMMAND(ID__SplitScreen, &CXSUnitePlayDemoDlg::SplitScreen)
	ON_COMMAND(ID__SingleSrceen, &CXSUnitePlayDemoDlg::SingleSrceen)
	ON_COMMAND(ID__CapturePic, &CXSUnitePlayDemoDlg::CapturePic)
	ON_COMMAND(ID__RecStart, &CXSUnitePlayDemoDlg::RecStart)
	ON_COMMAND(ID__RecStop, &CXSUnitePlayDemoDlg::RecStop)
END_MESSAGE_MAP()


// CXSUnitePlayDemoDlg ��Ϣ�������

BOOL CXSUnitePlayDemoDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	SetDlgItemText(IDC_ADDR, "10.200.66.102:10010");
	SetDlgItemText(IDC_CAMERA, "11491"); //��
	//SetDlgItemText(IDC_CAMERA, "26509"); //��
	//SetDlgItemText(IDC_CAMERA, "11418"); //��Ϊ

	SetDlgItemText(IDC_DEVIP, "10.200.198.153");
	SetDlgItemText(IDC_DEVPORT, "8000");
	SetDlgItemText(IDC_DEVCHN, "1");
	SetDlgItemText(IDC_DEVTYPE, "HK");
	SetDlgItemText(IDC_DEVUSER, "admin");
	SetDlgItemText(IDC_DEVPWD, "Xinyi@12345");
	SetDlgItemText(IDC_DEVCODE, "44030500151326000203");

	SetDlgItemText(IDC_AUTOSEC, "15");
	SetDlgItemText(IDC_SPEED, "5");

	m_PlayCtrl.SetRange(0, 100);
	CTime sTime, eTime;
	((CDateTimeCtrl *)GetDlgItem(IDC_STIME))->GetTime(sTime);
	((CDateTimeCtrl *)GetDlgItem(IDC_ETIME))->GetTime(sTime);
	CTimeSpan sSpan(0, 1, 30, 0);
	CTimeSpan eSpan(0, 0, 30, 0);
	CTime sTime2 = sTime - sSpan;
	CTime eTime2 = eTime - eSpan;
	((CDateTimeCtrl *)GetDlgItem(IDC_STIME))->SetTime(&sTime2);
	((CDateTimeCtrl *)GetDlgItem(IDC_ETIME))->SetTime(&eTime2);

	memset(&m_PlayRect, 0, sizeof(CRect));
	m_Menu.LoadMenu(IDR_MENU1);

	char szFilePath[256] = { 0 };
	_getcwd(szFilePath, sizeof(szFilePath));
	char szPicPath[256] = { 0 };
	char szRecPath[256] = { 0 };
	sprintf(szPicPath, "%s\\TestCaptureFile.jpg", szFilePath);
	sprintf(szRecPath, "%s\\TestRecordFile.mp4", szFilePath);
	remove(szPicPath);
	remove(szRecPath);

	m_bInit = false;
	m_bRealPlay = false;
	m_bRecManual = false;
	m_bSplit = false;
	m_bAuto = false;
	m_handler = 0;
	m_playid = 0;
	__pDlg = this;
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CXSUnitePlayDemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CXSUnitePlayDemoDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CXSUnitePlayDemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CXSUnitePlayDemoDlg::OnBnClickedCancel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	OnBnClickedRealstop();
	if (m_bInit)
	{
#ifdef _WIN64
		nvs_cleanEnviroment();
#endif
		m_bInit = false;
	}
	m_Menu.DestroyMenu();
	CDialogEx::OnCancel();
	//char szFilePath[256] = { 0 };
	//_getcwd(szFilePath, sizeof(szFilePath));
	//char szPicPath[256] = { 0 };
	//char szRecPath[256] = { 0 };
	//sprintf(szPicPath, "del /Q %s\\*.jpg", szFilePath);
	//sprintf(szRecPath, "del /Q %s\\*.mp4", szFilePath);
	//system(szPicPath);
	//system(szRecPath);
	if (m_playid > 0)
	{
		m_playid = 0;
		system("taskkill /f /t /im XSUnitePlayDemo.exe");
	}
	
}

void CXSUnitePlayDemoDlg::RealPlayCB(int nCameraID, int nRe)
{
	CString sMsg;
	sMsg.Format("��ͷID:%d ʵ��Ԥ�����Ž��[%d]", nCameraID, nRe);
	__pDlg->m_MsgBox.SetWindowText(sMsg);
}

void CXSUnitePlayDemoDlg::DrawCB(intptr_t lRealHandle, DWORD hDc, int nCameraID)
{
	if (__pDlg->m_bRecManual)
	{
		CRect Rect;
		__pDlg->GetDlgItem(IDC_PLAYWND)->GetClientRect(&Rect);
		CDC *pDC = CDC::FromHandle((HDC)hDc);
		pDC->Draw3dRect(&Rect, RGB(255, 0, 0), RGB(255, 0, 0));
		pDC->Draw3dRect(Rect.left + 1, Rect.top + 1, Rect.right - 1, Rect.bottom - 1, RGB(255, 0, 0), RGB(255, 0, 0));
		__pDlg->ReleaseDC(pDC);
	}
}

void CXSUnitePlayDemoDlg::OnBnClickedRealstart()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString sAddr;
	GetDlgItemText(IDC_ADDR, sAddr);
	UINT nCameraID = GetDlgItemInt(IDC_CAMERA);
	int nPos = sAddr.Find(':');
	CString sIp = sAddr.Left(nPos);
	CString sPort = sAddr.Right(sAddr.GetLength() - nPos - 1);
#ifdef _WIN64
	if (!m_bInit)
	{
		nvs_selectLib();
		bool bRet = nvs_initEnviroment(sIp.GetBuffer(), atoi(sPort.GetBuffer()), 0, 0);
		sIp.ReleaseBuffer();
		sPort.ReleaseBuffer();
		if (!bRet)
		{
			AfxMessageBox("��ʼ������ʧ��!");
			return;
		}
		bRet = nvs_registerOnIndex();
		if (!bRet)
		{
			AfxMessageBox("������������ʧ��!");
			return;
		}
		nvs_setPlayModel(0);
		nvs_setRealPlayCallBack(RealPlayCB);
		nvs_SetDrawFun(DrawCB);
		m_bInit = true;
	}
	int nRet = nvs_playVideo(nCameraID, m_PlayWnd.GetSafeHwnd(), false);
	if (nRet != XY_TRUE)
	{
		AfxMessageBox("ʵʱԤ��ʧ��!");
	}
	m_bRealPlay = true;
#endif

}


void CXSUnitePlayDemoDlg::OnBnClickedRealstop()
{
#ifdef _WIN64
	if (m_bRealPlay)
	{
		UINT nCameraID = GetDlgItemInt(IDC_CAMERA);
		nvs_stopPlayVideo(m_PlayWnd.GetSafeHwnd(), 0, nCameraID);
		m_bRealPlay = false;
	}
#endif
	Invalidate();
	UpdateWindow();
}


void CXSUnitePlayDemoDlg::OnBnClickedPlayback()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString sIp, sType, sUser, sPwd, sCode;
	int nPort, nChannel;
	GetDlgItemText(IDC_DEVIP, sIp);
	nPort = GetDlgItemInt(IDC_DEVPORT);
	nChannel = GetDlgItemInt(IDC_DEVCHN);
	GetDlgItemText(IDC_DEVTYPE, sType);
	GetDlgItemText(IDC_DEVUSER, sUser);
	GetDlgItemText(IDC_DEVPWD, sPwd);
	GetDlgItemText(IDC_DEVCODE, sCode);
	CTime sdate, stime, edate, etime;
	((CDateTimeCtrl *)GetDlgItem(IDC_SDATE))->GetTime(sdate);
	((CDateTimeCtrl *)GetDlgItem(IDC_STIME))->GetTime(stime);
	((CDateTimeCtrl *)GetDlgItem(IDC_ETIME))->GetTime(edate);
	((CDateTimeCtrl *)GetDlgItem(IDC_EDATE))->GetTime(etime);
	CString sBeginTime, sEndTime;
	sBeginTime.Format("%s %s", sdate.Format("%Y-%m-%d"), stime.Format("%H:%M:%S"));
	sEndTime.Format("%s %s", edate.Format("%Y-%m-%d"), etime.Format("%H:%M:%S"));

	BOOL bRet;
	m_handler = connectDVR(sIp.GetBuffer(), nPort, sUser.GetBuffer(), sPwd.GetBuffer(), nChannel, sType.GetBuffer(), bRet);
	sIp.ReleaseBuffer();
	sUser.ReleaseBuffer();
	sPwd.ReleaseBuffer();
	sType.ReleaseBuffer();
	if (!bRet)
	{
		CString sMsg;
		sMsg.Format("��½�豸ʧ�ܣ�Error:%lld", m_handler);
		AfxMessageBox(sMsg);
		return;
	}
	setCurrentCameraCode(m_handler, sCode.GetBuffer());
	sCode.ReleaseBuffer();
	RECORDFILE recfile[100];
	//int nCount = getRecordFileEx(m_handler, 0, sBeginTime.GetBuffer(), sEndTime.GetBuffer(), recfile, 100);
	//sBeginTime.ReleaseBuffer();
	//sEndTime.ReleaseBuffer();
	//if (nCount <= 0)
	//{
	//	AfxMessageBox("��ѯ¼���ļ�ʧ�ܣ�");
	//	return;
	//}
	m_playid = replayRecordFile(m_handler, m_PlayWnd.GetSafeHwnd(), NULL, sBeginTime.GetBuffer(), sEndTime.GetBuffer(), 0);
	sBeginTime.ReleaseBuffer();
	sEndTime.ReleaseBuffer();
	if (m_playid < 0)
	{
		AfxMessageBox("������ʷ�ط�ʧ�ܣ�");
		return;
	}
	SetTimer(m_playid, 1000, NULL);
}


void CXSUnitePlayDemoDlg::OnBnClickedStopplay()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (m_handler > 0)
	{
		KillTimer(m_playid);
		stopReplayRecordFile(m_handler, m_playid);
		disconnectDVR(m_handler);
		m_handler = 0;
	}
}


void CXSUnitePlayDemoDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if (nIDEvent == m_playid)
	{
		int totaltime,playtime = 0;
		controlReplayRecordFile(m_handler, m_playid, REPLAY_CTRL_GETTOTALTIME, 0, &totaltime);
		controlReplayRecordFile(m_handler, m_playid, REPLAY_CTRL_PLAYGETTIME, 0, &playtime);
		int pos = playtime * 100.0 / totaltime;
		m_PlayCtrl.SetPos(pos);
	}
	CDialogEx::OnTimer(nIDEvent);
}


void CXSUnitePlayDemoDlg::OnBnClickedButton10()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (m_handler == 0)
	{
		return;
	}
	char szPicPath[256] = { 0 };
	GetModuleFileName(NULL, szPicPath, sizeof(szPicPath));
	strrchr(szPicPath, '\\')[1] = '\0';
	strcat_s(szPicPath, "TestCaptureFile.jpg");
	if (m_playid > 0)
	{
		playBackCaptureFile(m_handler, m_playid, szPicPath);
	}
	else
	{
		capturePictureEx(m_handler, szPicPath);
	}
}


void CXSUnitePlayDemoDlg::OnBnClickedButton11()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (m_handler == 0)
	{
		return;
	}
	char szPicPath[256] = { 0 };
	GetModuleFileName(NULL, szPicPath, sizeof(szPicPath));
	strrchr(szPicPath, '\\')[1] = '\0';
	strcat_s(szPicPath, "TestRecordFile.mp4");
	if (m_playid > 0)
	{
		playBackSaveData(m_handler, m_playid, szPicPath);
	}
}


void CXSUnitePlayDemoDlg::OnBnClickedButton16()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (m_handler == 0)
	{
		return;
	}
	if (m_playid > 0)
	{
		stopPlayBackSave(m_handler, m_playid);
	}
}


void CXSUnitePlayDemoDlg::OnBnClickedAutostart()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString sAddr;
	GetDlgItemText(IDC_ADDR, sAddr);
	UINT nCameraID = GetDlgItemInt(IDC_CAMERA);
	int nPos = sAddr.Find(':');
	CString sIp = sAddr.Left(nPos);
	CString sPort = sAddr.Right(sAddr.GetLength() - nPos - 1);
	if (!m_bInit)
	{
		nvs_selectLib();
		bool bRet = nvs_initEnviroment(sIp.GetBuffer(), atoi(sPort.GetBuffer()), 0, 0);
		sIp.ReleaseBuffer();
		sPort.ReleaseBuffer();
		if (!bRet)
		{
			AfxMessageBox("��ʼ������ʧ��!");
			return;
		}
		bRet = nvs_registerOnIndex();
		if (!bRet)
		{
			AfxMessageBox("������������ʧ��!");
			return;
		}
		nvs_setPlayModel(0);
		nvs_setRealPlayCallBack(RealPlayCB);
		nvs_SetDrawFun(DrawCB);
		m_bInit = true;
	}
	AfxBeginThread(AutoStartThrd, this);
}

UINT CXSUnitePlayDemoDlg::AutoStartThrd(LPVOID pParam)
{
	CXSUnitePlayDemoDlg *pDlg = (CXSUnitePlayDemoDlg *)pParam;
	if (pDlg)
	{
		pDlg->m_bAuto = true;
		pDlg->AutoStartPorc();
	}
	AfxEndThread(0);
	return 0;
}

void CXSUnitePlayDemoDlg::AutoStartPorc()
{
	DatabaseClient db;
	if (!db.Connect(DB_ORACLE, "10.200.66.64", "nsqw", "XY_BASE", "XY_BASE"))
	{
		AfxMessageBox("�������ݿ�ʧ�ܣ�");
		return;
	}
	vector<int> chanlist;
	db.GetHighPointChannels(NULL, chanlist);
	db.Disconnect();
	while (m_bAuto)
	{
		for (size_t i = 0; i < chanlist.size(); i++)
		{
			if (!m_bAuto)
			{
				return;
			}
			if (m_bSplit)
			{
				nvs_playVideo(chanlist[i], m_PlayWnd.GetSafeHwnd(), false);
				nvs_playVideo(chanlist[i+1], m_PlayWnd2.GetSafeHwnd(), false);
				nvs_playVideo(chanlist[i+2], m_PlayWnd3.GetSafeHwnd(), false);
				nvs_playVideo(chanlist[i+3], m_PlayWnd4.GetSafeHwnd(), false);
			}
			else
			{
				nvs_playVideo(chanlist[i], m_PlayWnd.GetSafeHwnd(), false);
			}
			UINT nSec = GetDlgItemInt(IDC_AUTOSEC);
			Sleep(nSec*1000);
			if (m_bSplit)
			{
				nvs_stopPlayVideo(m_PlayWnd.GetSafeHwnd(), 0, chanlist[i]);
				nvs_stopPlayVideo(m_PlayWnd2.GetSafeHwnd(), 0, chanlist[i+1]);
				nvs_stopPlayVideo(m_PlayWnd3.GetSafeHwnd(), 0, chanlist[i+2]);
				nvs_stopPlayVideo(m_PlayWnd4.GetSafeHwnd(), 0, chanlist[i+3]);
				i += 3;
			}
			else
			{
				nvs_stopPlayVideo(m_PlayWnd.GetSafeHwnd(), 0, chanlist[i]);
			}
		}
		UINT nSec = GetDlgItemInt(IDC_AUTOSEC);
		Sleep(nSec*1000);
	}
}


void CXSUnitePlayDemoDlg::OnBnClickedAutostop()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_bAuto = false;
}


void CXSUnitePlayDemoDlg::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if (m_PlayRect.Width() == 0 && m_PlayRect.Height() == 0)
	{
		GetDlgItem(IDC_PLAYWND)->GetWindowRect(&m_PlayRect);
	}
	ClientToScreen(&point);
	if (m_PlayRect.PtInRect(point))
	{
		m_Menu.GetSubMenu(0)->TrackPopupMenu(TPM_LEFTALIGN | TPM_LEFTBUTTON | TPM_VERTICAL, point.x, point.y, this);
	}
	CDialogEx::OnRButtonDown(nFlags, point);
}


void CXSUnitePlayDemoDlg::SplitScreen()
{
	// TODO: �ڴ���������������
	if (!m_bSplit)
	{
		CRect Rect;
		GetDlgItem(IDC_PLAYWND)->GetWindowRect(&Rect);
		ScreenToClient(&Rect);
		WORD iWidth, iHeight;
		iWidth = Rect.Width();
		iHeight = Rect.Height();
		m_PlayWnd.MoveWindow(Rect.left, Rect.top, iWidth / 2, iHeight / 2);
		m_PlayWnd.ShowWindow(SW_SHOW);
		m_PlayWnd2.MoveWindow(Rect.left+(iWidth/2)+1, Rect.top, iWidth / 2, iHeight / 2);
		m_PlayWnd2.ShowWindow(SW_SHOW);
		m_PlayWnd3.MoveWindow(Rect.left, Rect.top + (iHeight / 2), iWidth / 2, iHeight / 2);
		m_PlayWnd3.ShowWindow(SW_SHOW);
		m_PlayWnd4.MoveWindow(Rect.left + (iWidth / 2) + 1, Rect.top + (iHeight / 2), iWidth / 2, iHeight / 2);
		m_PlayWnd4.ShowWindow(SW_SHOW);
		Invalidate();
		UpdateWindow();
		m_bSplit = true;
	}
}


void CXSUnitePlayDemoDlg::SingleSrceen()
{
	// TODO: �ڴ���������������
	if (m_bSplit)
	{
		CRect Rect;
		GetDlgItem(IDC_PLAYWND)->GetWindowRect(&Rect);
		ScreenToClient(&Rect);
		WORD iWidth, iHeight;
		iWidth = Rect.Width()*2;
		iHeight = Rect.Height()*2;
		m_PlayWnd.MoveWindow(Rect.left, Rect.top, iWidth, iHeight);
		m_PlayWnd.ShowWindow(SW_SHOW);
		m_PlayWnd2.ShowWindow(SW_HIDE);
		m_PlayWnd3.ShowWindow(SW_HIDE);
		m_PlayWnd4.ShowWindow(SW_HIDE);
		Invalidate();
		UpdateWindow();
		m_bSplit = false;
	}
}


void CXSUnitePlayDemoDlg::CapturePic()
{
	// TODO: �ڴ���������������
	char szPicPath[256] = { 0 };
	_getcwd(szPicPath, sizeof(szPicPath));
	strcat_s(szPicPath, "\\TestCaptureFile.jpg");
	if (m_bRealPlay)
	{
		UINT nCameraID = GetDlgItemInt(IDC_CAMERA);
		if (nvs_capturePictureEx(nCameraID, szPicPath))
		{
			CString strParm;
			strParm.Format("shimgvw.dll ImageView_Fullscreen %s", szPicPath);
			ShellExecute(NULL, "open", "rundll32.exe", strParm, "", SW_SHOWNORMAL);
		}
	}

}


void CXSUnitePlayDemoDlg::RecStart()
{
	// TODO: �ڴ���������������
	UINT nCameraID = GetDlgItemInt(IDC_CAMERA);
	char szRecPath[256] = { 0 };
	_getcwd(szRecPath, sizeof(szRecPath));
	strcat_s(szRecPath, "\\TestRecordFile.mp4");
	if (m_bRealPlay)
	{
		nvs_startRecord(nCameraID, szRecPath);
		m_bRecManual = true;
		//CRect Rect;
		//GetDlgItem(IDC_PLAYWND)->GetWindowRect(&Rect);
		//Rect.left - 2;
		//Rect.top - 2;
		//Rect.right + 2;
		//Rect.bottom + 2;
		//ScreenToClient(&Rect);
		//CDC *pDc = GetDC();
		//pDc->Draw3dRect(&Rect, RGB(255, 0, 0), RGB(255, 0, 0));
		//ReleaseDC(pDc);
		//pDc = NULL;
	}
}


void CXSUnitePlayDemoDlg::RecStop()
{
	// TODO: �ڴ���������������
	UINT nCameraID = GetDlgItemInt(IDC_CAMERA);
	char szRecPath[256] = { 0 };
	_getcwd(szRecPath, sizeof(szRecPath));
	strcat_s(szRecPath, "\\TestRecordFile.mp4");
	if (m_bRecManual)
	{
		nvs_stopRecord(nCameraID);
		m_bRecManual = false;
		//CRect Rect;
		//GetDlgItem(IDC_PLAYWND)->GetWindowRect(&Rect);
		//ScreenToClient(&Rect);
		//InvalidateRect(&Rect);
	}
}
