#ifndef AUDIOPLAY_H
#define AUDIOPLAY_H


#define AUDIO_PCMU	0
#define AUDIO_PCMA  1

typedef void* AudioHandle;

#ifdef AUDIOPLAY_EXPORTS
#define AUDIODEC extern "C" __declspec(dllexport) 
#else
#define AUDIODEC extern "C" __declspec(dllimport)
#endif



AUDIODEC AudioHandle AudioOpen(int nAudioType,int nChannels=1,int nBits=16,int nSampleRate=8000);
AUDIODEC void  AudioPlay(AudioHandle pAudioHandler, unsigned char* pFrameData, int nFrameLen);
AUDIODEC void  AudioClose(AudioHandle pAudioHandler);

#endif