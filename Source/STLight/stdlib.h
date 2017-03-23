#pragma once

#include "STLightAPI.hpp"
#include "corecrt.h"

#ifndef _countof
#define _countof __crt_countof
#endif

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//
// Global State (errno, global handlers, etc.)
//
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
#ifndef _M_CEE_PURE
// a purecall handler procedure. Never returns normally
typedef void(__cdecl* _purecall_handler)(void);

// Invalid parameter handler function pointer type
typedef void(__cdecl* _invalid_parameter_handler)(
	wchar_t const*,
	wchar_t const*,
	wchar_t const*,
	unsigned int,
	uintptr_t
	);

// Establishes a purecall handler
_VCRTIMP _purecall_handler __cdecl _set_purecall_handler(
	_In_opt_ _purecall_handler _Handler
);

_VCRTIMP _purecall_handler __cdecl _get_purecall_handler(void);

// Establishes an invalid parameter handler
_ACRTIMP _invalid_parameter_handler __cdecl _set_invalid_parameter_handler(
	_In_opt_ _invalid_parameter_handler _Handler
);

_ACRTIMP _invalid_parameter_handler __cdecl _get_invalid_parameter_handler(void);

_ACRTIMP _invalid_parameter_handler __cdecl _set_thread_local_invalid_parameter_handler(
	_In_opt_ _invalid_parameter_handler _Handler
);

_ACRTIMP _invalid_parameter_handler __cdecl _get_thread_local_invalid_parameter_handler(void);
#endif

// This is non-const for backwards compatibility; do not modify it.
extern "C" STLIGHT_API _CRT_INSECURE_DEPRECATE(strerror) char** __cdecl __sys_errlist(void);
#define _sys_errlist (__sys_errlist())

extern "C" STLIGHT_API _CRT_INSECURE_DEPRECATE(strerror) int * __cdecl __sys_nerr(void);
#define _sys_nerr (*__sys_nerr())

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