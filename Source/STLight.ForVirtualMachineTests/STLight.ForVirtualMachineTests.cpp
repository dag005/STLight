#include "stdafx.h"

#include "ForVMTests.hpp"

#include "../STLight/corecrt_wstring.h"


int main()
{
	//Тест 1
	wchar_t arr[30];
	STLight::wcscat_s(arr, 30, L"Hel");
	STLight::wcscpy_s(arr, 30, L"Hello");
	STLight::wcsncpy_s(arr, 30, L"Hello", 5);

	strerrorTest();
	// Тест функции _itoa_s для виртуальных машин.
	_itoa_sForVMTests();

	// Тест функции memcpy_s для виртуальных машин.
	memcpy_sForVMTests();

    return 0;
}