#pragma once


#ifdef MEDIATOOL_EXPORTS
#define MEDIATOOL_API __declspec(dllexport)
#else
#define MEDIATOOL_API __declspec(dllimport)
#endif

#define MP4WRITER_INVALID_AUDIO_TYPE          0x00
#define MP4WRITER_MPEG1_AUDIO_TYPE            0x6B
#define MP4WRITER_MPEG2_AUDIO_TYPE            0x69
#define MP4WRITER_MP3_AUDIO_TYPE              MP4WRITER_MPEG2_AUDIO_TYPE
#define MP4WRITER_MPEG2_AAC_MAIN_AUDIO_TYPE   0x66
#define MP4WRITER_MPEG2_AAC_LC_AUDIO_TYPE     0x67
#define MP4WRITER_MPEG2_AAC_SSR_AUDIO_TYPE    0x68
#define MP4WRITER_MPEG2_AAC_AUDIO_TYPE        MP4WRITER_MPEG2_AAC_MAIN_AUDIO_TYPE
#define MP4WRITER_MPEG4_AUDIO_TYPE            0x40
#define MP4WRITER_PRIVATE_AUDIO_TYPE          0xC0
#define MP4WRITER_PCM16_LITTLE_ENDIAN_AUDIO_TYPE  0xE0 /* a private definition */
#define MP4WRITER_VORBIS_AUDIO_TYPE           0xE1 /* a private definition */
#define MP4WRITER_AC3_AUDIO_TYPE              0xE2 /* a private definition */
#define MP4WRITER_ALAW_AUDIO_TYPE             0xE3 /* a private definition */
#define MP4WRITER_ULAW_AUDIO_TYPE             0xE4 /* a private definition */
#define MP4WRITER_G723_AUDIO_TYPE             0xE5 /* a private definition */
#define MP4WRITER_PCM16_BIG_ENDIAN_AUDIO_TYPE 0xE6 /* a private definition */


class IMp4FileWriter
{
public:
	IMp4FileWriter() {};
	virtual ~IMp4FileWriter() {};
public:
	virtual int CreateMp4(const char* filename, int w, int h, int nVideoFrameRate) = 0;
	virtual void WriteVideo(void* data, int nLen) = 0;
	virtual void SetAudioFormat(int channel, int audioSampleRate, unsigned char audioType) = 0;
	virtual void WriteAudio(void* data, int nLen) = 0;
	virtual void CloseMp4() = 0;
};

/*
param nEncodeType : 1: h264
*/
MEDIATOOL_API IMp4FileWriter* CreateMp4FileWriter(int nEncodeType);
MEDIATOOL_API void ReleaseMp4FileWriter(IMp4FileWriter** pMp4FileWriter);
