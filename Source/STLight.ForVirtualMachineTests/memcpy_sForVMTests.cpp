#include "stdafx.h"

#include "../STLight/corecrt_memcpy_s.h"

void memcpy_sForVMTests()
{
	char dest1[11] = "1111111111";
	char dest2[11] = "1111111111";
	char src[11] = "1234567890";

	STLigth::memcpy_s(dest1, 11, src, 5);

	STLigth::memcpy_s(dest2, 11, src, 0);
}