#pragma once

#define _INC_STDIO

#include "STLightAPI.hpp"

#include <corecrt.h>
#include "corecrt_wstdio.h"

_CRT_BEGIN_C_HEADER

namespace STLight 
{
	extern "C" STLIGHT_API errno_t __cdecl fopen_s(
		FILE**      _Stream,
		char const* _FileName,
		char const* _Mode
		);
}

_CRT_END_C_HEADER