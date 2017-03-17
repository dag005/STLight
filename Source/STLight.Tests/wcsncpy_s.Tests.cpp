#include "stdafx.h"

#include "../STLight/string.h"

TEST(wcsncpy_sTests, Valid)
{
	wchar_t arr[10];
	STLight::wcsncpy_s(arr, 10, L"Hell", 4);
	ASSERT_STREQ(arr, L"Hell");
}

TEST(wcsncpy_sTests,  nullDest)
{
	auto error = STLight::wcsncpy_s(NULL, 10, L"Hell", 4);
	ASSERT_EQ(error, EINVAL);
}

TEST(wcsncpy_sTests, smallBoofer)
{
	wchar_t arr[10] = L"he";
	ASSERT_STREQ(arr, L"he");
	auto error = STLight::wcsncpy_s(arr, 3, L"Hello", 5);
	ASSERT_STREQ(arr, L"");
	ASSERT_EQ(error, ERANGE);
}