#include "stdafx.h"

#include "../STLight/corecrt_memcpy_s.h"
#include "../STLight/corecrt_wstdio.h"
#include "../STLight/stdio.h"
#include "../STLight/stdlib.h"
int main()
{
	// _itoa_s
	char buffer[200];
	STLight::_itoa_s(-1, buffer, 200, 9);

	// memcpy_s
	char sourceStr[] = "STLight all day all night";
	char destStr[] = "000000000000000";
	STLight::memcpy_s(destStr, sizeof(destStr), sourceStr, 11);

	//fopen_s
	FILE* filePtr1;
	STLight::fopen_s(&filePtr1, "FilesTests/fopen_sTest1.txt", "r+");

	//_wfopen_s
	FILE* filePtr2;
	STLight::_wfopen_s(&filePtr2, L"FilesTests/fopen_sTest1.txt", L"r+");

    return 0;
}