#include "stdafx.h"

#include "Functions.hpp"

int DivideEvenly(int num1, int num2)
{
	if (num2 == 0)
		throw "Division by zero!";

	return num1 / num2;
}

size_t StrLen(char* str)
{
	return strlen(str);
}

char* MyStr()
{
	char* result = new char[10];

	result = "abcde1234";

	return result;
}