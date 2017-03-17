#include "stdafx.h"

#include "../STLight/corecrt_wstring.h"

int main()
{
	//Тест 1
	wchar_t arr[30];
	STLight::wcsncpy_s(arr, 30, L"Hello", 5);
    return 0;
}
