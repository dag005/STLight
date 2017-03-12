#include "stdafx.h"

#include "../STLight/wcsncpy_s.hpp"

int main()
{
	//Тест 1
	wchar_t arr[30];
	STLigth::wcsncpy_s(arr, 30, L"Hello", 5);
    return 0;
}