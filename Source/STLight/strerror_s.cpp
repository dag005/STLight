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
#include "string.h"
//#include "internal.h"
#include "internal_shared.h"
#include "corecrt_internal.h"

// These functions copy the narrow string into the provided buffer.
_Success_(return == 0)
static errno_t copy_string_into_buffer(
	_In_reads_or_z_(max_count)      char const* const   string,
	_Out_writes_z_(buffer_count)    char*       const   buffer,
	size_t      const   buffer_count,
	size_t      const   max_count
) throw()
{
	return STLight::strncpy_s(buffer, buffer_count, string, max_count);
}

size_t const minimum_message_length = 5;

	// Maps an error number to an error message string.  The error number should be
	// one of the errno values.  The string is copied into the provided buffer.  On
	// success or truncation, 0 is returned.  Otherwise, an error code is returned.
	template <typename Character>
	static errno_t __cdecl common_strerror_s(
		_Out_writes_z_(buffer_count)    Character* const    buffer,
		size_t     const    buffer_count,
		int        const    error_number
	)
	{
		_VALIDATE_RETURN_ERRCODE(buffer != nullptr, EINVAL);
		_VALIDATE_RETURN_ERRCODE(buffer_count > 0, EINVAL);

		errno_t const result = _ERRCHECK_EINVAL_ERANGE(copy_string_into_buffer(
			_get_sys_err_msg(error_number),
			buffer,
			buffer_count,
			_TRUNCATE));

		return result == STRUNCATE ? 0 : result;
	}

namespace STLight {
	errno_t __cdecl strerror_s(
		char*  const buffer,
		size_t const buffer_count,
		int    const error_number
	)
	{
		return common_strerror_s(buffer, buffer_count, error_number);
	}
}