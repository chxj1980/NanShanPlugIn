#include "StdAfx.h"
#include "NVSCore.h"

#ifndef PLAYLIB_WIN
#define PLAYLIB_WIN 0
#endif

NVSCore::NVSCore(void)
{
	m_pPlayLib = NULL;
}

NVSCore::~NVSCore(void)
{
	if (m_pPlayLib)
	{
		delete m_pPlayLib;
		m_pPlayLib = NULL;
	}
}

void NVSCore::Init(char cType)
{
	if (cType == PLAYLIB_WIN)
	{
		m_pPlayLib = new NVSPlayLibWin();
	}
	else
	{
		m_pPlayLib = new NVSPlayLibLux();
	}
}
