/*
#include <stdio.h>
#include <string.h>
#include "md5.h"

int main(int argc, char *argv[])
{
	MD5_CTX md5;
	MD5Init(&md5);
	int i;
	char encrypt[100];
	printf("Input content you need to encrypt :");
	scanf("%s", encrypt);
	unsigned char decrypt[16];
	MD5Update(&md5, encrypt, strlen((char *)encrypt));
	MD5Final(&md5, decrypt);

	unsigned char hexstr[32];
	for (i = 0; i < 16; i++)
	{
		sprintf(&hexstr[i * 2], "%02x", decrypt[i]);
	}

	printf("Before:%s\nAfter:%s", encrypt, hexstr);

	return 0;
}
*/

#pragma once

#ifdef MEDIATOOL_EXPORTS
#define MEDIATOOL_API __declspec(dllexport)
#else
#define MEDIATOOL_API __declspec(dllimport)
#endif

typedef struct {
	unsigned int count[2];
	unsigned int state[4];
	unsigned char buffer[64];
}MD5_CTX;

#define F(x,y,z) ((x & y) | (~x & z))
#define G(x,y,z) ((x & z) | (y & ~z))
#define H(x,y,z) (x^y^z)
#define I(x,y,z) (y ^ (x | ~z))
#define ROTATE_LEFT(x,n) ((x << n) | (x >> (32-n)))
#define FF(a,b,c,d,x,s,ac) \
          { \
          a += F(b,c,d) + x + ac; \
          a = ROTATE_LEFT(a,s); \
          a += b; \
          }
#define GG(a,b,c,d,x,s,ac) \
          { \
          a += G(b,c,d) + x + ac; \
          a = ROTATE_LEFT(a,s); \
          a += b; \
          }
#define HH(a,b,c,d,x,s,ac) \
          { \
          a += H(b,c,d) + x + ac; \
          a = ROTATE_LEFT(a,s); \
          a += b; \
          }
#define II(a,b,c,d,x,s,ac) \
          { \
          a += I(b,c,d) + x + ac; \
          a = ROTATE_LEFT(a,s); \
          a += b; \
          }

MEDIATOOL_API void MD5Init(MD5_CTX *context);
MEDIATOOL_API void MD5Update(MD5_CTX *context, unsigned char *input, unsigned int inputlen);
MEDIATOOL_API void MD5Final(MD5_CTX *context, unsigned char digest[16]);
MEDIATOOL_API void MD5Transform(unsigned int state[4], unsigned char block[64]);
MEDIATOOL_API void MD5Encode(unsigned char *output, unsigned int *input, unsigned int len);
MEDIATOOL_API void MD5Decode(unsigned int *output, unsigned char *input, unsigned int len);
