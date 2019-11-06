#pragma once

namespace base64
{
	void encode(unsigned char *bInput, unsigned long dwInputLen, unsigned char *bOutput, unsigned long *dwOutputLen);
	void decode(unsigned char *bInput, unsigned long dwInputLen, unsigned char *bOutput, unsigned long *dwOutputLen);
};
