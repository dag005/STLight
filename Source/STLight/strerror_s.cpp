//
// strerror.cpp
//
//      Copyright (c) Microsoft Corporation. All rights reserved.
//
// Defines the strerror() family of functions, which convert an errno error code
// to a string representation.  Note that there are legacy implementations of
// these functions, prefixed with underscores, in _strerr.cpp.  The functions in
// this file are implemented per the C Standard Library specification.
//
#include "stdafx.h"
#include "corecrt_internal.h"
//#include <malloc.h>
//#include <stddef.h>
//#include <stdlib.h>
#include "string.h"

//namespace STLight {
//	extern "C" errno_t __cdecl strerror_s(
//		char*  const buffer,
//		size_t const buffer_count,
//		int    const error_number
//	)
//	{
//		return common_strerror_s(buffer, buffer_count, error_number);
//	}
//}