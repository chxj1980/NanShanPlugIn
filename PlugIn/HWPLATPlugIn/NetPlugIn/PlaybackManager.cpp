#include "StdAfx.h"
#include "PlaybackManager.h"

PlaybackManager::PlaybackManager(void)
{
	InitializeCriticalSection(&m_InLock);
	InitializeCriticalSection(&m_OutLock);
	m_bStop = FALSE;
	m_bSend = FALSE;
}

PlaybackManager::~PlaybackManager(void)
{
	DeleteCriticalSection(&m_InLock);
	DeleteCriticalSection(&m_OutLock);
	while (m_InputBuffer.size())
	{
		frame packet = m_InputBuffer.pop();
		delete[] packet.buffer;
		packet.buffer = NULL;
	}
	while (m_OutputBuffer.size())
	{
		frame packet = m_OutputBuffer.pop();
		delete[] packet.buffer;
		packet.buffer = NULL;
	}
}

DWORD PlaybackManager::InputDataThrd(LPVOID lpThreadParameter)
{
	PlaybackManager *pThis = (PlaybackManager *)lpThreadParameter;
	if (pThis)
	{
		pThis->InputData();
	}
}
DWORD PlaybackManager::OutDataThrd(LPVOID lpThreadParameter)
{
	PlaybackManager *pThis = (PlaybackManager *)lpThreadParameter;
	if (pThis)
	{
		pThis->OutputData();
	}
}

void PlaybackManager::InputData()
{
	vector<frame> PacketList;
	while (!m_bStop)
	{
		while (m_InputBuffer.size())
		{
			if (m_bStop)
			{
				return;
			}
			frame packet = m_InputBuffer.pop();
			if (packet.type == 0)
			{
				for (int i=PacketList.size()-1; i >= 0; i--)
				{
					EnterCriticalSection(&m_OutLock);
					m_OutputBuffer.push(PacketList[i]);
					LeaveCriticalSection(*m_OutLock);
				}
				PacketList.clear();
				PacketList.push_back(packet);
			}
			else
			{
				PacketList.push_back(packet);
			}
		}
		Sleep(1000);
	}
}
void PlaybackManager::OutputData()
{
	while(!m_bStop)
	{
		while (m_OutputBuffer.size())
		{	
			if (m_bStop)
			{
				return;
			}
			EnterCriticalSection(&m_OutLock);
			frame packet = m_OutputBuffer.pop();
			LeaveCriticalSection(&m_OutLock);
			if (m_pCb != NULL && m_pUser != NULL)
			{
				if (!m_bSend)
				{
					m_bSend = TRUE;
					m_pCb(m_pUser,1,packet.buffer,packet.bufflen,m_pUser);
				}
				m_pCb(m_pUser,2,packet.buffer,packet.bufflen,m_pUser);
			}
			delete[] packet.buffer;
			packet.buffer = NULL;
		}
		Sleep(2000);
	}
}

int PlaybackManager::Init(LPCAPTURESTREAMCALLBACK lpCallBack, void* pUser)
{
	HANDLE hInputThrd = CreateThread(NULL,0,InputDataThrd,this,0,NULL);
	HANDLE hOutputThrd = CreateThread(NULL,0,OutDataThrd,this,0,NULL);
	CloseHandle(hInputThrd);
	CloseHandle(hOutputThrd);
	m_pCb = lpCallBack;
	m_pUser = pUser;
}

void PlaybackManager::Push(unsigned char *sBuffer, unsigned int nBufflen, int nType)
{
	if (m_bStop)
	{
		return;
	}
	EnterCriticalSection(&m_InLock);
	frame packet;
	packet.buffer = new unsigned char[nBufflen];
	memcpy(packet.buffer,sBuffer,nBufflen);
	packet.bufflen = nBufflen;
	packet.type = nType;
	m_InputBuffer.push(packet);
	LeaveCriticalSection(&m_InLock);
}

void PlaybackManager::Clear()
{
	m_bStop = TRUE;
	m_bSend = FALSE;
	m_pCb = NULL;
	m_pUser = NULL;
}

