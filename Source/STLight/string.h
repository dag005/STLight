#pragma once

#include "STLightAPI.hpp"
#include "corecrt.h"
#include "corecrt_wstring.h"

namespace STLight {
	_CRT_BEGIN_C_HEADER

		STLIGHT_API errno_t __cdecl strcpy_s(
			_Out_writes_z_(_SizeInBytes) char*       _Destination,
			_In_                         rsize_t     _SizeInBytes,
			_In_z_                       char const* _Source
		);

		STLIGHT_API errno_t __cdecl strerror_s(
				_Out_writes_z_(_SizeInBytes) char*  _Buffer,
				_In_                         size_t _SizeInBytes,
				_In_						 int    _ErrorNumber);

		STLIGHT_API errno_t __cdecl strncpy_s(
				_Out_writes_z_(_SizeInBytes) char*       _Destination,
				_In_                         rsize_t     _SizeInBytes,
				_In_reads_or_z_(_MaxCount)   char const* _Source,
				_In_                         rsize_t     _MaxCount
			);

	_CRT_END_C_HEADER
}