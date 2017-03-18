#include "stdafx.h"

#include "../STLight/stdlib.h"

// ����� ������� _itoa_s � ����������� �����������.
TEST(_itoa_sTests, WithTheCorrectParametersTest)
{
	// ����� ������� _itoa_s, ������� ����� 4 ���������.
	char buffer1[5];
	ASSERT_EQ(0, STLight::_itoa_s(15, buffer1, 5, 10));
	ASSERT_STREQ("15", buffer1);

	char buffer2[5];
	ASSERT_EQ(0, STLight::_itoa_s(15, buffer2, 5, 16));
	ASSERT_STREQ("f", buffer2);

	char buffer3[5];
	ASSERT_EQ(0, STLight::_itoa_s(10, buffer3, 5, 2));
	ASSERT_STREQ("1010", buffer3);

	char buffer41[10];
	char buffer42[10];
	ASSERT_EQ(_itoa_s(567, buffer41, 10, 29), STLight::_itoa_s(567, buffer42, 10, 29));
	ASSERT_STREQ(buffer41, buffer42);

	char buffer51[10];
	char buffer52[10];
	ASSERT_EQ(_itoa_s(-5677, buffer51, 10, 25), STLight::_itoa_s(-5677, buffer52, 10, 25));
	ASSERT_STREQ(buffer51, buffer52);

	// ����� ������� _itoa_s, ������� ����� 3 ���������.
	char buffer6[5];
	ASSERT_EQ(0, STLight::_itoa_s(15, buffer6, 10));
	ASSERT_STREQ("15", buffer1);

	char buffer7[5];
	ASSERT_EQ(0, STLight::_itoa_s(15, buffer7, 16));
	ASSERT_STREQ("f", buffer7);

	char buffer8[5];
	ASSERT_EQ(0, STLight::_itoa_s(10, buffer8, 2));
	ASSERT_STREQ("1010", buffer8);

	char buffer91[10];
	char buffer92[10];
	ASSERT_EQ(_itoa_s(567, buffer91, 29), STLight::_itoa_s(567, buffer92, 29));
	ASSERT_STREQ(buffer91, buffer92);

	char buffer101[10];
	char buffer102[10];
	ASSERT_EQ(_itoa_s(-5677, buffer101, 25), STLight::_itoa_s(-5677, buffer102, 25));
	ASSERT_STREQ(buffer101, buffer102);
}

// ����� ������� _itoa_s � �������, ������ NULL.
TEST(_itoa_sTests, WithNullTest)
{
	// ����� ������� _itoa_s, ������� ����� 4 ���������.
	ASSERT_EQ(EINVAL, STLight::_itoa_s(15, NULL, 5, 10));
	ASSERT_EQ(_itoa_s(15, NULL, 5, 10), STLight::_itoa_s(15, NULL, 5, 10));

	// ����� ������� _itoa_s, ������� ����� 3 ���������.
	/*ASSERT_EQ(EINVAL, STLight::_itoa_s(15, NULL, 10));
	ASSERT_EQ(_itoa_s(15, NULL, 10), STLight::_itoa_s(15, NULL, 10));*/
	// �� ���������� � ��� ������� �������� NULL.
}

// ����� ������� _itoa_s � �������� �������� ������, �����, ��� � ���� �� ���������� 
// ���������� ������ (��� ���� ������� ������� ������ ������� ��� ������).
TEST(_itoa_sTests, IncorrectBufferCountTest)
{
	// ����� ������� _itoa_s, ������� ����� 4 ���������.
	char buffer1[5];
	char buffer2[5];
	ASSERT_EQ(ERANGE, STLight::_itoa_s(10, buffer1, 2, 2));
	ASSERT_STREQ("", buffer1);
	ASSERT_EQ(_itoa_s(10, buffer2, 2, 2), STLight::_itoa_s(10, buffer1, 2, 2));
	ASSERT_STREQ(buffer1, buffer2);
}

// ����� ������� _itoa_s � ����������� �������� ���������� ������� ���������.
TEST(_itoa_sTests, IncorrectRadixTest)
{
	// ����� ������� _itoa_s, ������� ����� 4 ���������.
	char buffer1[100];
	ASSERT_EQ(EINVAL, STLight::_itoa_s(15, buffer1, 100, 37));
	ASSERT_EQ(_itoa_s(15, buffer1, 100, 37), STLight::_itoa_s(15, buffer1, 100, 37));
	ASSERT_EQ(EINVAL, STLight::_itoa_s(15, buffer1, 100, 1));
	ASSERT_EQ(_itoa_s(15, buffer1, 100, 1), STLight::_itoa_s(15, buffer1, 100, 1));

	// ����� ������� _itoa_s, ������� ����� 3 ���������.
	char buffer2[100];
	ASSERT_EQ(EINVAL, STLight::_itoa_s(15, buffer2, 37));
	ASSERT_EQ(_itoa_s(15, buffer2, 37), STLight::_itoa_s(15, buffer2, 37));
	ASSERT_EQ(EINVAL, STLight::_itoa_s(15, buffer2, 1));
	ASSERT_EQ(_itoa_s(15, buffer2, 1), STLight::_itoa_s(15, buffer2, 1));
}

// ����� ������� _itoa_s � �������, � ������� �� ��������� ������������ ������.
TEST(_itoa_sTests, WithSmallBufferTest)
{
	// ����� ������� _itoa_s, ������� ����� 4 ���������.
	char buffer1[4] = "fda";
	char buffer2[4] = "fda";
	ASSERT_EQ(ERANGE, STLight::_itoa_s(100, buffer1, 3, 2));
	ASSERT_STREQ("", buffer1);
	ASSERT_EQ(_itoa_s(100, buffer2, 3, 2), STLight::_itoa_s(100, buffer1, 3, 2));
	ASSERT_STREQ(buffer2, buffer1);

	// ����� ������� _itoa_s, ������� ����� 3 ���������.
	char buffer3[4] = "fda";
	char buffer4[4] = "fda";
	//STLight::_itoa_s(1000, buffer5, 2);	// �������� � ��������� ������ � ���� ������� (�� ���, ������� � �����������)
	//_itoa_s(1000, buffer5, 2);		// �� �������� � ��������� ������ � ���� ������� (�� ���, ������� � �����������)
	ASSERT_EQ(ERANGE, STLight::_itoa_s(1000, buffer3, 2));
	ASSERT_STREQ("", buffer3);	// ������ ����������.
	ASSERT_EQ(_itoa_s(1000, buffer4, 2), STLight::_itoa_s(1000, buffer3, 2));
	ASSERT_STREQ(buffer4, buffer3);
}