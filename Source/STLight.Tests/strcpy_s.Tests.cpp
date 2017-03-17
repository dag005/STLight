#include "stdafx.h"
#include "../STLight/string.h"

TEST(strcpy_sTests, valid)
{
	char arr[10];
	STLight::strcpy_s(arr, 10, "Hello");
	ASSERT_STREQ(arr, "Hello");
}

TEST(strcpy_sTests, nullDest)
{
	auto error = STLight::strcpy_s(NULL, 10, "Hello");
	ASSERT_EQ(error, EINVAL);
}

TEST(strcpy_sTests, smallBoofer)
{
	char arr[10];
	auto error = STLight::strcpy_s(arr, 3, "Hello");
	ASSERT_EQ(error, ERANGE);
}