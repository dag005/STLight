#pragma once

#include <corecrt.h>
#include "STLightAPI.hpp"
#include <vcruntime_string.h>

namespace STLight {
	extern "C" STLIGHT_API errno_t __cdecl wcscat_s(
			_Inout_updates_z_(_SizeInWords) wchar_t*		_Destination,
			_In_							rsize_t			_SizeInWords,
			_In_z_							wchar_t const*	_Source
		);

	extern "C" STLIGHT_API errno_t __cdecl wcsncpy_s(
			_Out_writes_z_(_SizeInWords) wchar_t*       _Destination,
			_In_                         rsize_t        _SizeInWords,
			_In_reads_or_z_(_MaxCount)   wchar_t const* _Source,
			_In_                         rsize_t        _MaxCount
		);

	extern "C" STLIGHT_API errno_t __cdecl wcscpy_s(
			 _Out_writes_z_(_SizeInWords)	wchar_t*		_Destination,
			 _In_							rsize_t			_SizeInWords,
			 _In_z_							wchar_t const*	_Source
		 );
}

