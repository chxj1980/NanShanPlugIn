
// XSUnitePlayDemoDlg.h : 头文件
//

#pragma once
#include "afxwin.h"

#include "NVSUnitePlaySDK.h"
#include "afxcmn.h"
#ifdef _WIN64
#pragma comment(lib, "XSUnitePlayLib.lib")
#endif
#pragma comment(lib, "NVSSDKEngine.lib")

// CXSUnitePlayDemoDlg 对话框
class CXSUnitePlayDemoDlg : public CDialogEx
{
// 构造
public:
	CXSUnitePlayDemoDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_XSUNITEPLAYDEMO_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CStatic m_PlayWnd;
	CStatic m_PlayWnd2;
	CStatic m_PlayWnd3;
	CStatic m_PlayWnd4;
	CRect	m_PlayRect;
	CStatic m_MsgBox;
	CSliderCtrl m_PlayCtrl;
	CMenu	m_Menu;
	BOOL	m_bInit;
	BOOL	m_bRealPlay;
	BOOL    m_bRecManual;
	BOOL	m_bSplit;
	BOOL	m_bAuto;
	intptr_t m_handler;
	intptr_t m_playid;
	static void CALLBACK RealPlayCB(int nCameraID, int nRe);
	static void CALLBACK DrawCB(intptr_t lRealHandle, DWORD hDc, int nCameraID);
	static UINT AutoStartThrd(LPVOID pParam);
	void AutoStartPorc();
public:
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedRealstart();
	afx_msg void OnBnClickedRealstop();
	afx_msg void OnBnClickedPlayback();
	afx_msg void OnBnClickedStopplay();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnBnClickedButton10();
	afx_msg void OnBnClickedButton11();
	afx_msg void OnBnClickedButton16();
	afx_msg void OnBnClickedAutostart();
	afx_msg void OnBnClickedAutostop();

	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void SplitScreen();
	afx_msg void SingleSrceen();
	afx_msg void CapturePic();
	afx_msg void RecStart();
	afx_msg void RecStop();
};
