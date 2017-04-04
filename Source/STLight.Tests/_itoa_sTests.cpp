#include "stdafx.h"

#include "../STLight/stdlib.h"

// Тесты _itoa_s с четырьмя параметрами.

TEST(_itoa_sTestsFourParams, Test1)
{
	char buffer[200];
	STLight::_itoa_s(-1, buffer, 200, 10);
	ASSERT_STREQ("-1", buffer);
}

TEST(_itoa_sTestsFourParams, Test2)
{
	char buffer[200];
	STLight::_itoa_s(-1, buffer, 200, 9);
	ASSERT_STREQ("12068657453", buffer);
}

TEST(_itoa_sTestsFourParams, Test3)
{
	char buffer[200];
	STLight::_itoa_s(-1, buffer, 200, 8);
	ASSERT_STREQ("37777777777", buffer);
}

TEST(_itoa_sTestsFourParams, Test4)
{
	char buffer[200];
	STLight::_itoa_s(-1, buffer, 200, 7);
	ASSERT_STREQ("211301422353", buffer);
}

TEST(_itoa_sTestsFourParams, Test5)
{
	char buffer[200];
	STLight::_itoa_s(-1, buffer, 200, 6);
	ASSERT_STREQ("1550104015503", buffer);
}

TEST(_itoa_sTestsFourParams, Test6)
{
	char buffer[200];
	STLight::_itoa_s(-1, buffer, 200, 5);
	ASSERT_STREQ("32244002423140", buffer);
}

TEST(_itoa_sTestsFourParams, Test7)
{
	char buffer[200];
	STLight::_itoa_s(-1, buffer, 200, 4);
	ASSERT_STREQ("3333333333333333", buffer);
}

TEST(_itoa_sTestsFourParams, Test8)
{
	char buffer[200];
	STLight::_itoa_s(-1, buffer, 200, 3);
	ASSERT_STREQ("102002022201221111210", buffer);
}

TEST(_itoa_sTestsFourParams, Test9)
{
	char buffer[200];
	STLight::_itoa_s(-1, buffer, 200, 2);
	ASSERT_STREQ("11111111111111111111111111111111", buffer);
}

TEST(_itoa_sTestsFourParams, Test10)
{
	char buffer[200];
	STLight::_itoa_s(0, buffer, 200, 32);
	ASSERT_STREQ("0", buffer);
}

// Тесты _itoa_s с тремя параметрами.

TEST(_itoa_sTestsThreeParams, Test1)
{
	char buffer[200];
	STLight::_itoa_s(-1, buffer, 10);
	ASSERT_STREQ("-1", buffer);
}

TEST(_itoa_sTestsThreeParams, Test2)
{
	char buffer[200];
	STLight::_itoa_s(-1, buffer, 9);
	ASSERT_STREQ("12068657453", buffer);
}

TEST(_itoa_sTestsThreeParams, Test3)
{
	char buffer[200];
	STLight::_itoa_s(-1, buffer, 8);
	ASSERT_STREQ("37777777777", buffer);
}

TEST(_itoa_sTestsThreeParams, Test4)
{
	char buffer[200];
	STLight::_itoa_s(-1, buffer, 7);
	ASSERT_STREQ("211301422353", buffer);
}

TEST(_itoa_sTestsThreeParams, Test5)
{
	char buffer[200];
	STLight::_itoa_s(-1, buffer, 6);
	ASSERT_STREQ("1550104015503", buffer);
}

TEST(_itoa_sTestsThreeParams, Test6)
{
	char buffer[200];
	STLight::_itoa_s(-1, buffer, 5);
	ASSERT_STREQ("32244002423140", buffer);
}

TEST(_itoa_sTestsThreeParams, Test7)
{
	char buffer[200];
	STLight::_itoa_s(-1, buffer, 4);
	ASSERT_STREQ("3333333333333333", buffer);
}

TEST(_itoa_sTestsThreeParams, Test8)
{
	char buffer[200];
	STLight::_itoa_s(-1, buffer, 3);
	ASSERT_STREQ("102002022201221111210", buffer);
}

TEST(_itoa_sTestsThreeParams, Test9)
{
	char buffer[200];
	STLight::_itoa_s(-1, buffer, 2);
	ASSERT_STREQ("11111111111111111111111111111111", buffer);
}

TEST(_itoa_sTestsThreeParams, Test10)
{
	char buffer[200];
	STLight::_itoa_s(0, buffer, 32);
	ASSERT_STREQ("0", buffer);
}