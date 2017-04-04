#pragma once

#include "STLightAPI.hpp"

#include <cstdio>

_CRT_BEGIN_C_HEADER

/*#ifndef _FILE_DEFINED
#define _FILE_DEFINED
typedef struct _iobuf
{
	void* _Placeholder;
} FILE;
#endif*/

namespace STLight 
{
	extern "C" STLIGHT_API errno_t __cdecl _wfopen_s(
		FILE**         _Stream,
		wchar_t const* _FileName,
		wchar_t const* _Mode
		);
}

_CRT_END_C_HEADER