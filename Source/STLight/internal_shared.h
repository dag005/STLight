#pragma once

#include <crtdbg.h>

#ifdef _DEBUG
#define _INVALID_PARAMETER(expr) _invalid_parameter(expr, __FUNCTIONW__, __FILEW__, __LINE__, 0)
#else
#define _INVALID_PARAMETER(expr) _invalid_parameter_noinfo()
#endif

#define _VALIDATE_RETURN(expr, errorcode, retexpr)                             \
    {                                                                          \
        int _Expr_val=!!(expr);                                                \
        _ASSERT_EXPR((_Expr_val), _CRT_WIDE(#expr));                           \
        if (!(_Expr_val))                                                      \
        {                                                                      \
            errno = errorcode;                                                 \
            _INVALID_PARAMETER(_CRT_WIDE(#expr));                              \
            return retexpr;                                                    \
        }                                                                      \
    }