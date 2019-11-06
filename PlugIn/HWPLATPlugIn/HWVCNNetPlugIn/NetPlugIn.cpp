#include "StdAfx.h"
#include "NetPlugIn.h"
#include "NetInit.h"

NetInit G_NetInit;


NetPlugIn::NetPlugIn(void)
{
	m_log = NULL;
	m_pHandler = NULL;
}

NetPlugIn::~NetPlugIn(void)
{

}

void NetPlugIn::WriteLog(const char *sFormat, ...)
{
	m_log = fopen("C:\\NVSLog\\SDKEngine\\HWPlatPlugIn.log", "a+");
	if (m_log)
	{
		char szLog[1024] = { 0 };
		va_list args;
		va_start(args, sFormat);
		vsprintf(szLog, sFormat, args);
		va_end(args);
		strcat(szLog, "\r\n");
		fwrite(szLog, strlen(szLog), 1, m_log);
		fclose(m_log);
		m_log = NULL;
	}
}

bool NetPlugIn::connectDVR(char* sIP,int nPort,char* sUser,char* sPwd,int nChannel)
{
	if (!G_NetInit.Init())
	{
		return false;
	}
	m_pHandler = G_NetInit.GetHandler();
}

void NetPlugIn::disconnectDVR()
{
	if (m_pHandler)
	{
		G_NetInit.FreeHandler(m_pHandler);
		m_pHandler = NULL;
	}
}

void NetPlugIn::setCurrentCameraCode(char* sCameraCode)
{
	char szInfo[1024] = {0};
	GetPrivateProfileString("info", sCameraCode,"",szInfo,sizeof(szInfo),G_NetInit.m_szConfig);
	if (szInfo[0] != '\0')
	{
		char *sIP = strtok(szInfo,";");
		char *sPort = strtok(NULL,";");
		char *sUser = strtok(NULL,";");
		char *sPwd = strtok(NULL,";");
		char *sCode = strtok(NULL,";");
		int nPort = atoi(sPort);
		if (m_pHandler->connectDVR(sIP, nPort, sUser, sPwd, 0))
		{
			m_pHandler->setCurrentCameraCode(sCode);
		}
		else
		{
			WriteLog("Login %s %s %s %s %s false!",sIP,sPort,sUser,sPwd,sCode);
		}
	}
	else
	{
		WriteLog("当前镜头没有在VCN有存储计划!");
	}

}

bool NetPlugIn::captureStream(LPCAPTURESTREAMCALLBACK lpCallBack, void* pUser, int nGetVideoType)
{
	return true;
}
bool NetPlugIn::stopCaptureStream()
{
	return true;
}
bool NetPlugIn::controlPTZSpeedWithChannel(int nCmd, bool bEnable, int nSpeed, int nChannel)
{
	return true;
}
bool NetPlugIn::controlPTZSpeed(int nCmd, bool bEnable,int nSpeed)
{
	return controlPTZSpeedWithChannel(nCmd,bEnable,nSpeed,0);
}
bool NetPlugIn::presetPTZWithChannel(int nCmd, int nIndex, int nChannel)
{
	return true;
}
bool NetPlugIn::presetPTZ(int nCmd, int nIndex)
{
	return presetPTZWithChannel(nCmd, nIndex, 0);
}
RECORDFILE* NetPlugIn::getRecordFile(int nType,char* startTime,char* endTime,int* nFileCount)
{
	if (m_pHandler)
	{
		return m_pHandler->getRecordFile(nType, startTime, endTime, nFileCount);
	}
	return NULL;
}

int NetPlugIn::getRecordFileEx(int nType,char* startTime,char* endTime,RECORDFILE pRecordFile[],int nMaxFileCount)
{
	if (m_pHandler)
	{
		return m_pHandler->getRecordFileEx(nType, startTime, endTime, pRecordFile, nMaxFileCount);
	}
	return 0;
}

intptr_t NetPlugIn::captureFileStream(LPCAPTURESTREAMCALLBACK lpCallBack, void* pUser, int nStreamType, RECORDFILE FileInfo, char* sType)
{
	if (m_pHandler)
	{
		return m_pHandler->captureFileStream(lpCallBack, pUser, nStreamType, FileInfo, sType);
	}
	return 0;
}


bool NetPlugIn::controlReplayRecordFile(intptr_t lReplayHandle,int nCmd,int nInValue,int* outValue)
{
	if (m_pHandler)
	{
		return m_pHandler->controlReplayRecordFile(lReplayHandle, nCmd, nInValue, outValue);
	}
	return false;
}

intptr_t NetPlugIn::replayRecordFile(HWND hWnd,char* fileName,char* startTime, char* endTime,int nFileSize)
{
	if (m_pHandler)
	{
		return m_pHandler->replayRecordFile(hWnd, fileName, startTime, endTime, nFileSize);
	}
	return 0;
}

bool NetPlugIn::stopReplayRecordFile(intptr_t lReplayHandle)
{
	if (m_pHandler)
	{
		return m_pHandler->stopReplayRecordFile(lReplayHandle);
	}
	return false;
}

bool NetPlugIn::playBackCaptureFile(intptr_t lReplayHandle, char *pFileName)
{
	if (m_pHandler)
	{
		return m_pHandler->playBackCaptureFile(lReplayHandle, pFileName);
	}
	return false;
}

bool NetPlugIn::playBackSaveData(intptr_t lReplayHandle,char *sFileName)
{
	if (m_pHandler)
	{
		return m_pHandler->playBackSaveData(lReplayHandle, sFileName);
	}
	return false;
}

bool NetPlugIn::stopPlayBackSave(intptr_t lReplayHandle)
{
	if (m_pHandler)
	{
		return m_pHandler->stopPlayBackSave(lReplayHandle);
	}
	return false;
}

intptr_t NetPlugIn::downloadRecordFile(char* fileName,char* startTime, char* endTime,int nFileSize,char* saveFile,LPDOWNLOADRECORDFILECALLBACK lpCallBack,void* pUser)
{
	if (m_pHandler)
	{
		return m_pHandler->downloadRecordFile(fileName, startTime, endTime, nFileSize, saveFile, lpCallBack, pUser);
	}
	return 0;
}

bool NetPlugIn::stopDownloadRecordFile(intptr_t ldownFileHandle)
{
	if (m_pHandler)
	{
		return m_pHandler->stopDownloadRecordFile(ldownFileHandle);
	}
	return 0;
}

int NetPlugIn::getDownloadPos(intptr_t lFileHandle)
{
	if (m_pHandler)
	{
		return m_pHandler->getDownloadPos(lFileHandle);
	}
	return 0;
}

bool NetPlugIn::startPlayer4Standard(HWND hWnd,LPDecCBFun lpDecCBFun, int nCameraID)
{
	return false;
}
bool NetPlugIn::startPlayerByCamera(HWND hwndPlay, int nCameraID)
{
	return true;
}
bool NetPlugIn::stopPlayerByCamera(HWND hwndPlay, int nCameraID)
{
	return true;
}
bool NetPlugIn::capturePicture(char* sFilePath)
{
	if (m_pHandler)
	{
		return m_pHandler->capturePicture(sFilePath);
	}
	return true;
}
bool NetPlugIn::startRecord(char* saveFile)
{
	return false;
}
bool NetPlugIn::stopRecord()
{
	return true;
}
bool NetPlugIn::startPlayer2(HWND hWnd, LPDRAWCBCALLLBACK lpDrawCBFun, void *pUser)
{
	return false;
}
bool NetPlugIn::setDVRConfig(DWORD dwCommand,LONG lChannel,LPVOID lpInBuffer,DWORD dwInBufferSize)
{
	return true;
}
bool NetPlugIn::getDVRConfig(DWORD dwCommand,LONG lChannel,LPVOID lpOutBuffer,DWORD dwOutBufferSize,LPDWORD lpBytesReturned)
{
	return true;
}
bool NetPlugIn::initialPlayer(int nPort,int nDecodeType,BYTE* buff, int nSize, int nStreamType)
{
	return true;
}
bool NetPlugIn::startPlayer(HWND hWnd)
{

	return true;
}
bool NetPlugIn::addData(BYTE* buff, int nSize)
{
	return false;
}
bool NetPlugIn::stopPlayer()
{
	return true;
}