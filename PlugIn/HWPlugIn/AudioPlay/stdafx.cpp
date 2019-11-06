// stdafx.cpp : 只包括标准包含文件的源文件
// AudioPlay.pch 将作为预编译头
// stdafx.obj 将包含预编译类型信息

#include "stdafx.h"

// TODO: 在 STDAFX.H 中
// 引用任何所需的附加头文件，而不是在此文件中引用
#include "AudioRender.h"

extern "C" void* AudioOpen(int nAudioType,int nChannels,int nBits,int nSampleRate)
{
	AudioRender *pHandler = new AudioRender;
	if (pHandler == NULL)
	{
		return NULL;
	}
	if (pHandler->Init(nAudioType,nChannels,nBits,nSampleRate))
	{
		return pHandler;
	}
	delete pHandler;
	pHandler = NULL;
	return NULL;
}

extern "C" void  AudioPlay(void* pAudioHandler, unsigned char* pFrameData, int nFrameLen)
{
	AudioRender *pHandler = (AudioRender *)pAudioHandler;
	if (pHandler)
	{
		pHandler->Play(pFrameData, nFrameLen);
	}
}

extern "C" void  AudioClose(void* pAudioHandler)
{
	AudioRender *pHandler = (AudioRender *)pAudioHandler;
	if (pHandler)
	{
		pHandler->Destory();
		delete pHandler;
		pHandler = NULL;
	}
}

