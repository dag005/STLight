#include "stdafx.h"

#include "../STLight/corecrt_memcpy_s.h"

TEST(memcpy_sTests, WithTheCorrectParametersTest1)
{
	char dest1[5] = "abcd";
	char dest2[5] = "abcd";
	char src[5] = "1234";

	// ���� STLigth::memcpy_s
	ASSERT_EQ(0, STLigth::memcpy_s(dest1, 5, src, 5));
	ASSERT_STREQ(src, dest1);

	// ���� memcpy_s
	ASSERT_EQ(0, memcpy_s(dest2, 5, src, 5));
	ASSERT_STREQ(src, dest2);
}

TEST(memcpy_sTests, WithTheCorrectParametersTest2)
{
	char dest1[11] = "1111111111";
	char dest2[11] = "1111111111";
	char src[11] = "1234567890";

	// ���� STLigth::memcpy_s
	ASSERT_EQ(0, STLigth::memcpy_s(dest1, 11, src, 5));
	ASSERT_STREQ("1234511111", dest1);

	// ���� memcpy_s
	ASSERT_EQ(0, memcpy_s(dest2, 11, src, 5));
	ASSERT_STREQ("1234511111", dest2);
}

TEST(memcpy_sTests, CountEqualToZeroTest)
{
	char dest1[11] = "1111111111";
	char dest2[11] = "1111111111";
	char src[11] = "1234567890";

	// ���� STLigth::memcpy_s
	ASSERT_EQ(0, STLigth::memcpy_s(dest1, 11, src, 0));
	ASSERT_STREQ(dest1, dest1);

	// ���� memcpy_s
	ASSERT_EQ(0, memcpy_s(dest2, 11, src, 0));
	ASSERT_STREQ(dest2, dest2);
}

/*
	� MSDN ��������, ��� � ���� ����� ������ ������������ EINVAL, �� ��� ������� �� ���! 
	��������� ������ ������, ���� ����������������� ��� (��� ��� ����� �������, ��� ��� �����������).
TEST(memcpy_sTests, WithNullDestTest)
{
	char src[11] = "1234567890";

	// ���� STLigth::memcpy_s
	ASSERT_EQ(EINVAL, STLigth::memcpy_s(NULL, 11, src, 1));

	// ���� memcpy_s
	ASSERT_EQ(EINVAL, memcpy_s(NULL, 11, src, 1));
} */

/*
	� MSDN ��������, ��� � ���� ����� ������ ������������ EINVAL � ���������� dest, �� ��� ������� �� ���! 
	��������� ������ ������, ���� ����������������� ��� (��� ��� ����� �������, ��� ��� �����������).
TEST(memcpy_sTests, WithNullSrcTest)
{
	char dest1[11] = "1111111111";
	char dest2[11] = "1111111111";

	// ���� STLigth::memcpy_s
	ASSERT_EQ(EINVAL, STLigth::memcpy_s(dest1, 11, NULL, 1));
	ASSERT_STREQ(NULL, dest1);

	// ���� memcpy_s
	ASSERT_EQ(EINVAL, memcpy_s(dest2, 11, NULL, 1));
	ASSERT_STREQ(NULL, dest2);
} */

/*
� MSDN ��������, ��� � ���� ����� ������ ������������ ERANGE � ���������� dest, �� ��� ������� �� ���!
��������� ������ ������, ���� ����������������� ��� (��� ��� ����� �������, ��� ��� �����������).
TEST(memcpy_sTests, DestSizeLessCountTest)
{
	char dest1[11] = "1111111111";
	char dest2[11] = "1111111111";
	char src[11] = "1234567890";

	// ���� STLigth::memcpy_s
	ASSERT_EQ(ERANGE, STLigth::memcpy_s(dest1, 4, src, 5));
	ASSERT_STREQ(NULL, dest1);

	// ���� memcpy_s
	ASSERT_EQ(ERANGE, memcpy_s(dest2, 4, src, 5));
	ASSERT_STREQ(NULL, dest2);
} */

/* 
	��� ������� ��������� ���� ���������.���� count �� ����� 
	���� � dest ��� src �������� ���������� null ��� destSize ������,
	��� count, ��� ������� �������� ���������� ������������� ���������, 
	��� ������� � ������� �������� ����������.���� ����������� ���������� ���������, 
	��� ������� ���������� EINVAL � ������������� ��� errno �������� EINVAL.
*/