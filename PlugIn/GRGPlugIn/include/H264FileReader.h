#pragma once
#ifdef MEDIATOOL_EXPORTS
#define MEDIATOOL_API __declspec(dllexport)
#else
#define MEDIATOOL_API __declspec(dllimport)
#endif

#include <stdio.h>

#define		READ_BUF_SIZE	(1024*1024*4)

typedef void (__stdcall* DataCallBack)(void* data, int len, void* pUser);

class MEDIATOOL_API H264FileReader
{
public:
	H264FileReader();
	virtual ~H264FileReader();

public:
	void SetDataCallBack(DataCallBack cb, void*	pUser);
	int OpenFile(char* filename);
	void Close();
	int ReadFile();

private:
	FILE*		m_File;
	char*		m_pBuf;
	int			m_nReadLen;

	char*		m_pFrame;
	int			m_nPos;

	DataCallBack	m_CB;
	void*			m_pUser;
};

int FindStartCode(char* buf, int len);