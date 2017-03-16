#include "stdafx.h"

#include "../STLight/string.h"

TEST(wcscpy_sTests, Valid)
{
	strerror_s
	wchar_t arr[10];
	STLigth::wcscpy_s(arr, 10, L"Hell");
	ASSERT_STREQ(arr, L"Hell");
}