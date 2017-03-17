#include "stdafx.h"

#include "../STLight/string.h"
#include <excpt.h>

TEST(wcscpy_sTests, Valid)
{
	wchar_t arr[10];
	STLight::wcscpy_s(arr, 10, L"Hell");
	ASSERT_STREQ(arr, L"Hell");
}

TEST(wcscpy_sTests, smallBoofer)
{
	wchar_t arr[10] = L"my";
	ASSERT_STREQ(arr, L"my");
	auto error = STLight::wcscpy_s(arr, 4, L"Hello");
	ASSERT_STREQ(arr, L"");
	ASSERT_EQ(error, ERANGE);
}

TEST(wcscpy_sTests, nullArr)
{
	auto error = STLight::wcscpy_s(NULL, 10, L"hello");
	ASSERT_EQ(error, EINVAL);
}