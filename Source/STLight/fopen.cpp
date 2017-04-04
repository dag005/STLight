#include "stdafx.h"

#include "stdio.h"
#include "corecrt_wstdio.h"

namespace STLight 
{
	extern "C" errno_t __cdecl fopen_s(
		FILE**		const result,
		char const* const file,
		char const* const mode
		)
	{
		*result = fopen(file, mode);

		return 0;
	}

	extern "C" errno_t __cdecl _wfopen_s(
		FILE**         const result,
		const wchar_t* const file,
		const wchar_t* const mode
		)
	{
		*result = _wfopen(file, mode);

		return 0;
	}
}
