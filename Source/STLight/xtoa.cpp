#include "stdafx.h"

#include "stdlib.h"

#include <algorithm>

namespace STLight 
{
	extern "C" errno_t __cdecl _itoa_s(
		int    const value,
		char*  const buffer,
		size_t const /*buffer_count*/,
		int    const radix
		)
	{
		_itoa(value, buffer, radix);

		return 0;
	}
}