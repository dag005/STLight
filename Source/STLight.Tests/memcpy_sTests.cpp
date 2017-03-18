#include "stdafx.h"

#include "../STLight/corecrt_memcpy_s.h"

TEST(memcpy_sTests, WithTheCorrectParametersTest1)
{
	char dest1[5] = "abcd";
	char dest2[5] = "abcd";
	char src[5] = "1234";

	// 义耱 STLigth::memcpy_s
	ASSERT_EQ(0, STLigth::memcpy_s(dest1, 5, src, 5));
	ASSERT_STREQ(src, dest1);

	// 义耱 memcpy_s
	ASSERT_EQ(0, memcpy_s(dest2, 5, src, 5));
	ASSERT_STREQ(src, dest2);
}

TEST(memcpy_sTests, WithTheCorrectParametersTest2)
{
	char dest1[11] = "1111111111";
	char dest2[11] = "1111111111";
	char src[11] = "1234567890";

	// 义耱 STLigth::memcpy_s
	ASSERT_EQ(0, STLigth::memcpy_s(dest1, 11, src, 5));
	ASSERT_STREQ("1234511111", dest1);

	// 义耱 memcpy_s
	ASSERT_EQ(0, memcpy_s(dest2, 11, src, 5));
	ASSERT_STREQ("1234511111", dest2);
}

TEST(memcpy_sTests, CountEqualToZeroTest)
{
	char dest1[11] = "1111111111";
	char dest2[11] = "1111111111";
	char src[11] = "1234567890";

	// 义耱 STLigth::memcpy_s
	ASSERT_EQ(0, STLigth::memcpy_s(dest1, 11, src, 0));
	ASSERT_STREQ(dest1, dest1);

	// 义耱 memcpy_s
	ASSERT_EQ(0, memcpy_s(dest2, 11, src, 0));
	ASSERT_STREQ(dest2, dest2);
}

/*
	� MSDN 磬镨襦眍, 黩� � 铎 蝈耱� 漕腈眍 忸玮疣螯�� EINVAL, 眍 � 龛躔屙� 礤 蜞�! 
	橡钽疣祆� 镳铖蝾 忤耥弪, 羼腓 疣耜铎戾眚桊钼囹� 觐� (黩� 潆� 磬� 趔黻鲨�, 黩� 潆� 耱囗溧痱眍�).
TEST(memcpy_sTests, WithNullDestTest)
{
	char src[11] = "1234567890";

	// 义耱 STLigth::memcpy_s
	ASSERT_EQ(EINVAL, STLigth::memcpy_s(NULL, 11, src, 1));

	// 义耱 memcpy_s
	ASSERT_EQ(EINVAL, memcpy_s(NULL, 11, src, 1));
} */

/*
	� MSDN 磬镨襦眍, 黩� � 铎 蝈耱� 漕腈眍 忸玮疣螯�� EINVAL � 钺眢��螯�� dest, 眍 � 龛躔屙� 礤 蜞�! 
	橡钽疣祆� 镳铖蝾 忤耥弪, 羼腓 疣耜铎戾眚桊钼囹� 觐� (黩� 潆� 磬� 趔黻鲨�, 黩� 潆� 耱囗溧痱眍�).
TEST(memcpy_sTests, WithNullSrcTest)
{
	char dest1[11] = "1111111111";
	char dest2[11] = "1111111111";

	// 义耱 STLigth::memcpy_s
	ASSERT_EQ(EINVAL, STLigth::memcpy_s(dest1, 11, NULL, 1));
	ASSERT_STREQ(NULL, dest1);

	// 义耱 memcpy_s
	ASSERT_EQ(EINVAL, memcpy_s(dest2, 11, NULL, 1));
	ASSERT_STREQ(NULL, dest2);
} */

/*
� MSDN 磬镨襦眍, 黩� � 铎 蝈耱� 漕腈眍 忸玮疣螯�� ERANGE � 钺眢��螯�� dest, 眍 � 龛躔屙� 礤 蜞�!
橡钽疣祆� 镳铖蝾 忤耥弪, 羼腓 疣耜铎戾眚桊钼囹� 觐� (黩� 潆� 磬� 趔黻鲨�, 黩� 潆� 耱囗溧痱眍�).
TEST(memcpy_sTests, DestSizeLessCountTest)
{
	char dest1[11] = "1111111111";
	char dest2[11] = "1111111111";
	char src[11] = "1234567890";

	// 义耱 STLigth::memcpy_s
	ASSERT_EQ(ERANGE, STLigth::memcpy_s(dest1, 4, src, 5));
	ASSERT_STREQ(NULL, dest1);

	// 义耱 memcpy_s
	ASSERT_EQ(ERANGE, memcpy_s(dest2, 4, src, 5));
	ASSERT_STREQ(NULL, dest2);
} */

/* 
	蒡� 趔黻鲨� 镳钼屦� 疋铊 镟疣戾蝠�.篷腓 count 礤 疣忭� 
	眢膻 � dest 桦� src �怆�弪�� 箨噻囹咫屐 null 桦� destSize 戾睃,
	麇� count, � 趔黻鲨� 恹琨忄 钺疣犷蝼桕 礤漕矬耱桁钽� 镟疣戾蝠�, 
	赅� 铒桉囗� � 疣玟咫� 镳钼屦觇 镟疣戾蝠钼.篷腓 镳钿铍驽龛� 恹镱腠屙�� 疣琊屮屙�, 
	� 趔黻鲨� 忸玮疣 EINVAL � 篑蜞磬怆桠帼� 潆� errno 珥圜屙桢 EINVAL.
*/