#include "stdafx.h"

#include "../STLight/stdlib.h"

void _itoa_sForVMTests()
{
	char buffer[500];
	STLight::_itoa_s(15, buffer, 500, 10);
	STLight::_itoa_s(-5677, buffer, 500, 25);
	STLight::_itoa_s(567, buffer, 29);
	STLight::_itoa_s(-5677, buffer, 29);
}