#pragma once

#define AUDIO_DECODER_PCM				0		// 
#define AUDIO_DECODER_TYPE_G711A		1		// G711A
#define AUDIO_DECODER_TYPE_G711U		2		// G711U

class IAudioDecoder
{
public:
	virtual void Release() = 0;

	virtual bool Init() = 0;

	virtual char* InputData(void* pData, int nDataLength, int& nOutLen) = 0;
	
};

IAudioDecoder* CreateAudioDecoder(int decoder_type);
