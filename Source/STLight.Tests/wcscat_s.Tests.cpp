#include "stdafx.h"

#include "../STLight/string.h"

TEST(wcscat_sTests, valid)
{
	wchar_t arr[10] = L"Hel";
	STLight::wcscat_s(arr, 10, L"lo");
	ASSERT_STREQ(arr, L"Hello");
}

TEST(wcscat_sTests, nullDest)
{
	auto error = STLight::wcscat_s(NULL, 10, L"Hello");
	ASSERT_EQ(error, EINVAL);
}

TEST(wcscat_sTests, smallBoofer)
{
	wchar_t arr[5];
	auto error = STLight::wcscat_s(arr, 5, L"Hello my friend");
	ASSERT_STREQ(arr, L"");
	ASSERT_EQ(error, EINVAL);
}

