#include "stdafx.h"

#include "../STLight/string.h"

TEST(wcscat_sTests, valid)
{
	wchar_t arr[10] = L"Hel";
	STLigth::wcscat_s(arr, 10, L"lo");
	ASSERT_STREQ(arr, L"Hello");
}