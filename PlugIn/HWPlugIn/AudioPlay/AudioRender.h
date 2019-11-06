#pragma once
#include "audio_out.h"
#pragma comment(lib,"EasyAudioRender.lib")

class AudioRender
{
public:
	AudioRender(void);
public:
	~AudioRender(void);
public:
	bool Init(int nAudioType,int nChannels,int nBits,int nSampleRate);
	bool Play(unsigned char *sBuffer, int nBufSize);
	bool Control(double dVol);
	void Destory();
private:
	struct ao_context *m_ctx;
	int m_nAudionType;
	short m_szAudioBuf[2048];
	
};
