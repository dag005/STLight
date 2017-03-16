#include "stdafx.h"

#include "string.h"
#include "corecrt_internal_string_templates.h"

namespace STLigth {
	extern "C" errno_t __cdecl wcsncpy_s(
		wchar_t*       const destination,
		size_t         const size_in_elements,
		wchar_t const* const source,
		size_t         const count
	)
	{
		return common_tcsncpy_s(destination, size_in_elements, source, count);
	}
}