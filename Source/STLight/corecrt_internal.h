#pragma once

#include "internal_shared.h"
#include "stdlib.h"
//#include <corecrt_internal_fls.h>
//#include <corecrt_internal_state_isolation.h>



_Ret_z_
__inline char const* _get_sys_err_msg(size_t const m)
{
	_BEGIN_SECURE_CRT_DEPRECATION_DISABLE
		if (m >= (size_t)_sys_nerr)
			return _sys_errlist[_sys_nerr];

	return _sys_errlist[m];
	_END_SECURE_CRT_DEPRECATION_DISABLE
}

#define _CORECRT_GENERATE_FORWARDER(prefix, callconv, name, callee_name)                     \
    __pragma(warning(push))                                                                  \
    __pragma(warning(disable: 4100)) /* unreferenced formal parameter */                     \
    template <typename... Params>                                                            \
    prefix auto callconv name(Params&&... args) throw() -> decltype(callee_name(args...))    \
    {                                                                                        \
        _BEGIN_SECURE_CRT_DEPRECATION_DISABLE                                                \
        return callee_name(args...);                                                         \
        _END_SECURE_CRT_DEPRECATION_DISABLE                                                  \
    }                                                                                        \

#ifndef _SECURECRT_FILL_BUFFER_THRESHOLD
// _SECURECRT_FILL_BUFFER_THRESHOLD must be a constant for Prefast due to the
// double evaluation. Making it something unique like 42 would pollute Prefast's warnings.
#if defined(_PREFAST_) || !defined(_DEBUG)
#define _SECURECRT_FILL_BUFFER_THRESHOLD ((size_t)0)
#else
#define _SECURECRT_FILL_BUFFER_THRESHOLD (_CrtGetDebugFillThreshold())
#endif
#endif

#if _SECURECRT_FILL_BUFFER
#define _SECURECRT__FILL_STRING(_String, _Count, _Offset)                       \
        if ((_Count) != ((size_t)-1) &&                                             \
            (_Count) != INT_MAX &&                                                  \
            ((size_t)(_Offset)) < (_Count))                                         \
        {                                                                           \
            size_t max_buffer_count = _SECURECRT_FILL_BUFFER_THRESHOLD;             \
            memset(                                                                 \
                (_String) + (_Offset),                                              \
                _SECURECRT_FILL_BUFFER_PATTERN,                                     \
                (max_buffer_count < ((size_t)((_Count) - (_Offset)))                \
                    ? max_buffer_count                                              \
                    : ((_Count) - (_Offset))) * sizeof(*(_String)));                \
        }
#else
#define _SECURECRT__FILL_STRING(_String, _Count, _Offset)
#endif

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//
// Invalid Parameter Macros
//
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
// Invoke Watson if _ExpressionError is not 0; otherwise simply return
// _EspressionError.
_CRT_SECURITYCRITICAL_ATTRIBUTE
__forceinline void _invoke_watson_if_error(
	_In_       errno_t        expression_error,
	_In_opt_z_ wchar_t const* expression,
	_In_opt_z_ wchar_t const* function_name,
	_In_opt_z_ wchar_t const* file_name,
	_In_       unsigned int   line_number,
	_In_       uintptr_t      reserved
)
{
	if (expression_error == 0)
	{
		return;
	}

	_invoke_watson(expression, function_name, file_name, line_number, reserved);
}

// Invoke Watson if _ExpressionError is not 0 and equal to _ErrorValue1 or
// _ErrorValue2; otherwise simply return _EspressionError.
__forceinline errno_t _invoke_watson_if_oneof(
	_In_       errno_t        expression_error,
	_In_       errno_t        error_value1,
	_In_       errno_t        error_value2,
	_In_opt_z_ wchar_t const* expression,
	_In_opt_z_ wchar_t const* function_name,
	_In_opt_z_ wchar_t const* file_name,
	_In_       unsigned int   line_number,
	_In_       uintptr_t      reserved
)
{
	if (expression_error == 0 || (expression_error != error_value1 && expression_error != error_value2))
	{
		return expression_error;
	}

	_invoke_watson(expression, function_name, file_name, line_number, reserved);
}

#ifdef _DEBUG
#define _INVOKE_WATSON_IF_ERROR(expr) _invoke_watson_if_error((expr), _CRT_WIDE(#expr), __FUNCTIONW__, __FILEW__, __LINE__, 0)
#define _INVOKE_WATSON_IF_ONEOF(expr, errvalue1, errvalue2) _invoke_watson_if_oneof(expr, (errvalue1), (errvalue2), _CRT_WIDE(#expr), __FUNCTIONW__, __FILEW__, __LINE__, 0)
#else
#define _INVOKE_WATSON_IF_ERROR(expr) _invoke_watson_if_error(expr, NULL, NULL, NULL, 0, 0)
#define _INVOKE_WATSON_IF_ONEOF(expr, errvalue1, errvalue2) _invoke_watson_if_oneof((expr), (errvalue1), (errvalue2), NULL, NULL, NULL, 0, 0)
#endif

#define _ERRCHECK(e)               _INVOKE_WATSON_IF_ERROR(e)
#define _ERRCHECK_EINVAL(e)        _INVOKE_WATSON_IF_ONEOF(e, EINVAL, EINVAL)
#define _ERRCHECK_EINVAL_ERANGE(e) _INVOKE_WATSON_IF_ONEOF(e, EINVAL, ERANGE)

#define _BEGIN_SECURE_CRT_DEPRECATION_DISABLE \
    __pragma(warning(push))                   \
    __pragma(warning(disable:4996))           \
    __pragma(warning(disable:6053))

#define _END_SECURE_CRT_DEPRECATION_DISABLE   \
    __pragma(warning(pop))