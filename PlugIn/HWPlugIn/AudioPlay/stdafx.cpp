// stdafx.cpp : ֻ������׼�����ļ���Դ�ļ�
// AudioPlay.pch ����ΪԤ����ͷ
// stdafx.obj ������Ԥ����������Ϣ

#include "stdafx.h"

// TODO: �� STDAFX.H ��
// �����κ�����ĸ���ͷ�ļ����������ڴ��ļ�������
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

