//
// corecrt_wstdio.h
//
//      Copyright (c) Microsoft Corporation. All rights reserved.
//
// This file declares the wide character (wchar_t) I/O functionality, shared by
// <stdio.h> and <wchar.h>.  It also defines several core I/O types, which are
// also shared by those two headers.
//
#pragma once

#include "corecrt.h"
#include "corecrt_stdio_config.h"
#include <algorithm>

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//
// Wide Character Formatted Input Functions (String)
//
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
_Success_(return >= 0)
_ACRTIMP int __cdecl __stdio_common_vswscanf(
	_In_                                   unsigned __int64 _Options,
	_In_reads_(_BufferCount) _Pre_z_       wchar_t const*   _Buffer,
	_In_                                   size_t           _BufferCount,
	_In_z_ _Scanf_format_string_params_(2) wchar_t const*   _Format,
	_In_opt_                               _locale_t        _Locale,
	va_list          _ArgList
);

_Success_(return >= 0)
_Check_return_opt_
_CRT_STDIO_INLINE int __CRTDECL _vswscanf_l(
	_In_z_                        wchar_t const* const _Buffer,
	_In_z_ _Printf_format_string_ wchar_t const* const _Format,
	_In_opt_                      _locale_t      const _Locale,
	va_list              _ArgList
)
#if defined _NO_CRT_STDIO_INLINE
;
#else
{
	return __stdio_common_vswscanf(
		_CRT_INTERNAL_LOCAL_SCANF_OPTIONS,
		_Buffer, (size_t)-1, _Format, _Locale, _ArgList);
}
#endif

_CRT_BEGIN_C_HEADER

_Success_(return >= 0)
_Check_return_ _CRT_INSECURE_DEPRECATE(swscanf_s)
_CRT_STDIO_INLINE int __CRTDECL swscanf(
	_In_z_                       wchar_t const* const _Buffer,
	_In_z_ _Scanf_format_string_ wchar_t const* const _Format,
	...)
#if defined _NO_CRT_STDIO_INLINE // SCANF
	;
#else
{
	int _Result;
	va_list _ArgList;
	__crt_va_start(_ArgList, _Format);
	_Result = _vswscanf_l(_Buffer, _Format, NULL, _ArgList);
	__crt_va_end(_ArgList);
	return _Result;
}
#endif

#if __STDC_WANT_SECURE_LIB__

	_Success_(return >= 0)
		_Check_return_opt_
		_CRT_STDIO_INLINE int __CRTDECL swscanf_s(
			_In_z_                         wchar_t const* const _Buffer,
			_In_z_ _Scanf_s_format_string_ wchar_t const* const _Format,
			...)
#if defined _NO_CRT_STDIO_INLINE // SCANF
		;
#else
	{
		int _Result;
		va_list _ArgList;
		__crt_va_start(_ArgList, _Format);
		_Result = _vswscanf_s_l(_Buffer, _Format, NULL, _ArgList);
		__crt_va_end(_ArgList);
		return _Result;
	}
#endif

#endif