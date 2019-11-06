#pragma once

#ifdef MEDIATOOL_EXPORTS
#define MEDIATOOL_API __declspec(dllexport)
#else
#define MEDIATOOL_API __declspec(dllimport)
#endif

class IAudioPlayer
{
public:
	virtual void Release() = 0;
	virtual bool Start(int decoder_type) = 0;
	virtual void Stop() = 0;
	virtual bool InputData(char* buf, int len) = 0;
};

MEDIATOOL_API IAudioPlayer* CreateAudioPlayer();

