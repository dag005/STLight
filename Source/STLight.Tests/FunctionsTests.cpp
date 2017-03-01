#include "stdafx.h"

#include "../STLight/Functions.hpp"

TEST(MyFunctionsTests, DivideEvenlyTests)
{
	ASSERT_EQ(2, DivideEvenly(5, 2));
	ASSERT_EQ(0, DivideEvenly(4, 5));
	ASSERT_EQ(100, DivideEvenly(400, 4));

	try
	{
		DivideEvenly(5, 0);

		FAIL() << "Expected std::runtime_error";
	}
	catch (char *str)
	{
		ASSERT_STREQ("Division by zero!", str);
	}
}

TEST(MyFunctionsTests, StrLenTests)
{
	ASSERT_EQ(2, StrLen("rk"));
	ASSERT_EQ(0, StrLen(""));
	ASSERT_EQ(10, StrLen("rkgasfgasf"));
}

TEST(MyFunctionsTests, MyStrTests)
{
	char *str1 = MyStr();

	ASSERT_STREQ("abcde1234", str1);
}