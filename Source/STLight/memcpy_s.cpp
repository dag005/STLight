#include "stdafx.h"

#include "corecrt_memcpy_s.h"

namespace STLight
{
	extern "C" errno_t _cdecl memcpy_s(
		void*       const _Destination,
		rsize_t     const /*_DestinationSize*/,
		void const* const _Source,
		rsize_t     const _SourceSize
		)
	{
		if (_SourceSize == 0)
			return 0;

		memcpy(_Destination, _Source, _SourceSize);

		return 0;
	}
}