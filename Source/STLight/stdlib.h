#pragma once

#include "STLightAPI.hpp"
#include <corecrt.h>

namespace STLight {
	_Success_(return == 0)
		_Check_return_opt_
		extern "C" STLIGHT_API errno_t __cdecl _itoa_s(
			_In_                         int    _Value,
			_Out_writes_z_(_BufferCount) char*  _Buffer,
			_In_                         size_t _BufferCount,
			_In_                         int    _Radix
			);

	__DEFINE_CPP_OVERLOAD_SECURE_FUNC_1_1(
		_Success_(return == 0)
		errno_t, _itoa_s,
		_In_ int, _Value,
		char, _Buffer,
		_In_ int, _Radix
		);
}