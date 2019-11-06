#include "StdAfx.h"
#include "AudioRender.h"
#include "g711.h"

AudioRender::AudioRender(void)
{
	m_ctx = NULL;
	m_nAudionType = -1;
}

AudioRender::~AudioRender(void)
{
	if (m_ctx)
	{
		free(m_ctx);
		m_ctx = NULL;
	}
}

bool AudioRender::Init(int nAudioType,int nChannels,int nBits,int nSampleRate)
{
	m_nAudionType = nAudioType;
	m_ctx = (ao_context *)malloc(sizeof(ao_context));
	if (m_ctx)
	{
		if (dsound_init_audio(m_ctx, nChannels, nBits, nSampleRate, nChannels<<6) == 0)
		{
			return true;
		}
	}
	return false;
}

bool AudioRender::Play(unsigned char *sBuffer, int nBufSize)
{
	if (m_ctx)
	{
		memset(m_szAudioBuf,0,sizeof(m_szAudioBuf));
		for (int i=0; i<nBufSize; i++)
		{
			if (m_nAudionType == AUDIO_PCMU)
			{
				m_szAudioBuf[i] = ulaw2linear(sBuffer[i]);
			}
			else if (m_nAudionType  == AUDIO_PCMA)
			{
				m_szAudioBuf[i] = alaw2linear(sBuffer[i]);
			}
			else
			{
				return false;  
			}
		}
		int nRet = dsound_play_audio(m_ctx, (unsigned char *)m_szAudioBuf, nBufSize*2);
		if (nRet > 0)
		{
			return true;
		}
	}
	return false;
}

bool AudioRender::Control(double dVol)
{
	if (m_ctx)
	{
		dsound_audio_control(m_ctx, dVol, dVol);
	}
	return false;
}

void AudioRender::Destory()
{
	if (m_ctx)
	{
		dsound_destory_audio(m_ctx);
		free(m_ctx);
		m_ctx = NULL;
	}
}

