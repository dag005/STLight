#include "stdafx.h"

#include "../STLight/string.h"

TEST(wcsncpy_sTests, Valid)
{
	wchar_t arr[10];
	STLigth::wcsncpy_s(arr, 10, L"Hell", 4);
	ASSERT_STREQ(arr, L"Hell");
}

TEST(wcsncpy_sTests, InValid)
{
	auto error = STLigth::wcsncpy_s(NULL, 10, L"Hell", 4);
	ASSERT_EQ(error, EINVAL);
}