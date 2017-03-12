#include "stdafx.h"

#include "../STLight/wcsncpy_s.hpp"

TEST(wcsncpy_sTests, valid)
{
	wchar_t arr[10];
	STLigth::wcsncpy_s(arr, 10, L"Hello", 5);
	ASSERT_STREQ(arr, L"Hello");
}