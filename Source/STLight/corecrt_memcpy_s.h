#pragma once

#include "STLightAPI.hpp"

#include <corecrt.h>

_CRT_BEGIN_C_HEADER

namespace STLight
{
	extern "C" STLIGHT_API errno_t _cdecl memcpy_s(
		void*       const _Destination,
		rsize_t     const _DestinationSize,
		void const* const _Source,
		rsize_t     const _SourceSize
		);
}

_CRT_END_C_HEADER