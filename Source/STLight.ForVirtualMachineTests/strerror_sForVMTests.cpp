#include "stdafx.h"

#include "../STLight/string.h"

void strerrorTest()
{
	char str[1000];
	STLight::strerror_s(str, 1000, ERANGE);
	STLight::strerror_s(str, 1000, EINVAL);
	STLight::strerror_s(str, 1000, 0);
}