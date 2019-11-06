#pragma once
#include "NVSPlayLib.h"

class NVSCore
{
public:
	NVSCore(void);
public:
	~NVSCore(void);
public:
	NVSPlayLib *m_pPlayLib;
public:
	void Init(char nType);
};
