#pragma once

class NVSProcessByDVR
{
public:
	NVSProcessByDVR(void);
public:
	~NVSProcessByDVR(void);
public:
	/*!< ²å¼þÀàÐÍ */
	string m_strType;

public:
	intptr_t v_loginDVR(char* sIP, int nPort, char* sUser, char* sPwd);
	void v_logoutDVR(intptr_t identify);
	bool v_playVideoByDVR(intptr_t identify,int nCameraID,HWND hWnd);
	bool v_stopPlayVideoByDVR(intptr_t identify,HWND hWnd);
	bool v_controlCameraSpeedByDVR(intptr_t identify,int nCameraID,int nCmd, bool bControl, int nSpeed, int nChannel);
	bool v_presetPTZByDVR(intptr_t identify,int nCameraID,int nCmd,int nTransPTZIndex,int nChannel);
	intptr_t v_getCameraInfo(intptr_t identify,int *nSize);
    int v_setPlayWindow(intptr_t identify,HWND palyWindow[],int nMaxCount);
};
