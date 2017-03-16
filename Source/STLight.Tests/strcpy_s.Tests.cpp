#include "stdafx.h"
#include "../STLight/string.h"

TEST(strcpy_sTests, valid)
{
	char arr[10];
	STLigth::strcpy_s(arr, 10, "Hello");
	ASSERT_STREQ(arr, "Hello");
}