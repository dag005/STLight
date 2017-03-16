#pragma once

#include "STLightAPI.hpp"
#include <corecrt.h>
#include <corecrt_memory.h>
#include "corecrt_wstring.h"
#include <vcruntime_string.h>

namespace STLigth {
	extern "C" STLIGHT_API errno_t __cdecl strcpy_s(
			_Out_writes_z_(_SizeInBytes) char*       _Destination,
			_In_                         rsize_t     _SizeInBytes,
			_In_z_                       char const* _Source
		);
}