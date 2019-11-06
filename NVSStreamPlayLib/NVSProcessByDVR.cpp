#include "StdAfx.h"
#include "NVSProcessByDVR.h"

NVSProcessByDVR::NVSProcessByDVR(void)
{
#ifdef _DEBUG
	m_strType = "HSPlugInd.dll";
#else
	m_strType = "HSPlugIn.dll";
#endif
}

NVSProcessByDVR::~NVSProcessByDVR(void)
{
}

intptr_t NVSProcessByDVR::v_loginDVR(char* sIP, int nPort, char* sUser, char* sPwd)
{
	intptr_t lPlugHandle = -1;
	BOOL bRe = FALSE;
	lPlugHandle = connectDVR(sIP,nPort,sUser,sPwd,-1,(char*)m_strType.c_str(),bRe);
	
	return lPlugHandle;
}

void NVSProcessByDVR::v_logoutDVR(intptr_t identify)
{
	disconnectDVR(identify);
}
bool NVSProcessByDVR::v_playVideoByDVR(intptr_t identify,int nCameraID,HWND hWnd)
{
	bool bPlay = false;

	bPlay = startPlayerByCamera(identify,hWnd,nCameraID);

	return bPlay;
}
bool NVSProcessByDVR::v_stopPlayVideoByDVR(intptr_t identify,HWND hWnd)
{
	bool bStop = false;

	bStop = stopPlayerByCamera(identify,hWnd,-1);

	return bStop;
}
bool NVSProcessByDVR::v_controlCameraSpeedByDVR(intptr_t identify,int nCameraID,int nCmd, bool bControl, int nSpeed, int nChannel)
{
	bool bcontrolPTZ = false;

	bcontrolPTZ = controlPTZSpeedWithChannel(identify,nCmd,bControl,nSpeed,nCameraID);

	return bcontrolPTZ;
}
bool NVSProcessByDVR::v_presetPTZByDVR(intptr_t identify,int nCameraID,int nCmd,int nTransPTZIndex,int nChannel)
{
	bool presetPTZ = false;

	presetPTZ = presetPTZWithChannel(identify,nCmd,nTransPTZIndex,nChannel);

	return presetPTZ;
}

intptr_t NVSProcessByDVR::v_getCameraInfo(intptr_t identify,int *nSize)
{
	intptr_t lpInfo = 0;

	lpInfo = getCameraInfo(identify,nSize);

	return lpInfo;
}
int NVSProcessByDVR::v_setPlayWindow(intptr_t identify,HWND palyWindow[], int nMaxCount)
{
	int nWndCount = 0;

	nWndCount = setPlayWindow(identify,palyWindow,nMaxCount);

	return nWndCount;
}