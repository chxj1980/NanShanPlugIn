#pragma once
#include "nvssdkdef.h"
#include <vector>
#include <queue>
using namespace std;

struct frame
{
	unsigned char	*buffer;
	unsigned int	bufflen;
	int				type;
};

typedef queue<frame>  DataBuffer;

class PlaybackManager
{
public:
	PlaybackManager(void);
public:
	~PlaybackManager(void);
public:
	static DWORD WINAPI InputDataThrd(LPVOID lpThreadParameter);
	static DWORD WINAPI OutDataThrd(LPVOID lpThreadParameter);
	void InputData();
	void OutputData();

	int Init(LPCAPTURESTREAMCALLBACK lpCallBack, void* pUser);
	void Push(unsigned char *sBuffer, unsigned int nBufflen, int nType);
	void Clear();
public:
	BOOL					m_bStop;
	BOOL					m_bSend;
	LPCAPTURESTREAMCALLBACK m_pCb;
	void					*m_pUser;
	DataBuffer				m_InputBuffer;
	DataBuffer				m_OutputBuffer;
	CRITICAL_SECTION		m_InLock;
	CRITICAL_SECTION		m_OutLock;
};
