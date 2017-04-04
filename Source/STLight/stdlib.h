#pragma once

#define _INC_STDLIB

#include "STLightAPI.hpp"

#include <corecrt.h>

_CRT_BEGIN_C_HEADER

namespace STLight 
{
	extern "C" STLIGHT_API errno_t __cdecl _itoa_s(
		int    _Value,
		char*  _Buffer,
		size_t _BufferCount,
		int    _Radix
		);

	extern "C++" { 
		template <size_t _Size>
		errno_t __cdecl _itoa_s(
			int _Value, 
			char (&_Buffer)[_Size], 
			int _Radix
			) throw()
		{
			return STLight::_itoa_s(_Value, _Buffer, _Size, _Radix);
		} 
	}
}

_CRT_END_C_HEADER