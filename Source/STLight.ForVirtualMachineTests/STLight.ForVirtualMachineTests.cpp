#include "stdafx.h"

#include "ForVMTests.hpp"

#include "../STLight/corecrt_wstring.h"


int main()
{
	//���� 1
	wchar_t arr[30];
	STLight::wcscat_s(arr, 30, L"Hel");
	STLight::wcscpy_s(arr, 30, L"Hello");
	STLight::wcsncpy_s(arr, 30, L"Hello", 5);

	strerrorTest();
	// ���� ������� _itoa_s ��� ����������� �����.
	_itoa_sForVMTests();

	// ���� ������� memcpy_s ��� ����������� �����.
	memcpy_sForVMTests();

    return 0;
}