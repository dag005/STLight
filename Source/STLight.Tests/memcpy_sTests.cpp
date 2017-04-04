#include "stdafx.h"

#include "../STLight/corecrt_memcpy_s.h"

TEST(memcpy_sTests, Test1)
{
	int destArr[10];
	int sourceArr[100];

	for (int i = 0; i < 100; ++i)
		sourceArr[i] = i * i;
 
	ASSERT_EQ(0, STLight::memcpy_s(destArr, sizeof(destArr), sourceArr, 10 * sizeof(int)));

	ASSERT_EQ(0, destArr[0]);
	ASSERT_EQ(1, destArr[1]);
	ASSERT_EQ(4, destArr[2]);
	ASSERT_EQ(9, destArr[3]);
	ASSERT_EQ(16, destArr[4]);
	ASSERT_EQ(25, destArr[5]);
	ASSERT_EQ(36, destArr[6]);
	ASSERT_EQ(49, destArr[7]);
	ASSERT_EQ(64, destArr[8]);
	ASSERT_EQ(81, destArr[9]);
}

TEST(memcpy_sTests, Test2)
{
	char sourceStr[] = "STLight all day all night";
	char destStr[] = "000000000000000";

	ASSERT_EQ(0, STLight::memcpy_s(destStr, sizeof(destStr), sourceStr, 11));

	ASSERT_STREQ("STLight all0000", destStr);
}

TEST(memcpy_sTests, Test3)
{
	wchar_t destStr[5] = L"abcd";
	wchar_t sourceStr[5] = L"1234";

	ASSERT_EQ(0, STLight::memcpy_s(destStr, 5, sourceStr, 5 * sizeof(wchar_t)));

	ASSERT_STREQ(L"1234", destStr);
}

TEST(memcpy_sTests, Test4)
{
	char destStr[11] = "1111111111";
	char sourceStr[11] = "1234567890";

	ASSERT_EQ(0, STLight::memcpy_s(destStr, 11, sourceStr, 5));

	ASSERT_STREQ("1234511111", destStr);
}

TEST(memcpy_sTests, Test5)
{
	char destStr[11] = "1111111111";
	char sourceStr[11] = "1234567890";

	ASSERT_EQ(0, STLight::memcpy_s(destStr, 11, sourceStr, 0));

	ASSERT_STREQ("1111111111", destStr);
}