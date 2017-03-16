#pragma once

#include "corecrt_internal.h"
#include "errno.h"

#define _FILL_STRING _SECURECRT__FILL_STRING

#define _RESET_STRING(_String, _Size) \
    *(_String) = 0; \
    _FILL_STRING((_String), (_Size), 1);

/* validations */
#define _VALIDATE_STRING_ERROR(_String, _Size, _Ret) \
    _VALIDATE_RETURN((_String) != NULL && (_Size) > 0, EINVAL, (_Ret))

#define _VALIDATE_STRING(_String, _Size) \
    _VALIDATE_STRING_ERROR((_String), (_Size), EINVAL)

#define _VALIDATE_POINTER_ERROR_RETURN(_Pointer, _ErrorCode, _Ret) \
    _VALIDATE_RETURN((_Pointer) != NULL, (_ErrorCode), (_Ret))

#define _VALIDATE_POINTER_RESET_STRING_ERROR(_Pointer, _String, _Size, _Ret) \
    if ((_Pointer) == NULL) \
    { \
        _RESET_STRING((_String), (_Size)); \
        _VALIDATE_POINTER_ERROR_RETURN((_Pointer), EINVAL, (_Ret)); \
    }

#define _VALIDATE_POINTER_RESET_STRING(_Pointer, _String, _Size) \
    _VALIDATE_POINTER_RESET_STRING_ERROR((_Pointer), (_String), (_Size), EINVAL)

#define _RETURN_BUFFER_TOO_SMALL_ERROR(_String, _Size, _Ret) \
    _VALIDATE_RETURN((L"Buffer is too small" && 0), ERANGE, _Ret)

#define _RETURN_BUFFER_TOO_SMALL(_String, _Size) \
    _RETURN_BUFFER_TOO_SMALL_ERROR((_String), (_Size), ERANGE)

#define _RETURN_DEST_NOT_NULL_TERMINATED(_String, _Size) \
    _VALIDATE_RETURN((L"String is not null terminated" && 0), EINVAL, EINVAL)

#define _RETURN_TRUNCATE \
    return STRUNCATE