#pragma once 

#include "STLightAPI.hpp"

namespace STLigth
{
	STLIGHT_API errno_t __cdecl wcsncpy_s(
		wchar_t*       const destination,
		size_t         const size_in_elements,
		wchar_t const* const source,
		size_t         const count
	);
}