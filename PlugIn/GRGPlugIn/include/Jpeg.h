#pragma once
#ifdef MEDIATOOL_EXPORTS
#define MEDIATOOL_API __declspec(dllexport)
#else
#define MEDIATOOL_API __declspec(dllimport)
#endif

MEDIATOOL_API int WriteJpegFile(const char* jpeg_file, unsigned char* rgb_buffer, int width, int height);
MEDIATOOL_API int WriteJpegFile(const char* jpeg_file, unsigned char* rgb_buffer, int width, int height, int quality);

void savebmp(char * pdata, char * bmp_file, int width, int height);
MEDIATOOL_API void SaveBmp(const char *filename, unsigned char *rgbbuf, int width, int height);