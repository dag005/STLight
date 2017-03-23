#include "stdafx.h"

#include "../STLight/string.h"

TEST(strerror_sTests, errangeError)
{
	char str[1000];
	STLight::strerror_s(str, 1000, ERANGE);
	ASSERT_STREQ("Result too large", str);
}

TEST(strerror_sTests, unknownError)
{
	char str[1000];
	STLight::strerror_s(str, 1000, 80);
	ASSERT_STREQ("Unknown error", str);
}