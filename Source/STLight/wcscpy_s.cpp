#include "stdafx.h"

#include "corecrt_internal_string_templates.h"
#include "string.h"

namespace STLight {
	extern "C" errno_t __cdecl wcscpy_s(
		wchar_t*       const destination,
		size_t         const size_in_elements,
		wchar_t const* const source
	)
	{
		return common_tcscpy_s(destination, size_in_elements, source);
	}
}