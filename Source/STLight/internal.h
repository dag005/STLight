#pragma once

#ifndef _INC_INTERNAL
#define _INC_INTERNAL

#include <crtdefs.h>

#ifdef __cplusplus
extern "C" {
#endif  /* __cplusplus */

	//#include <cruntime.h> k
#include <limits.h>

	/*
	* Conditionally include windows.h to pick up the definition of
	* CRITICAL_SECTION.
	*/
#include <windows.h>

	//#include <mtdll.h> k

#pragma pack(push,_CRT_PACKING)

	/* Define function types used in several startup sources */

	typedef void(__cdecl *_PVFV)(void);
	typedef int(__cdecl *_PIFV)(void);
	typedef void(__cdecl *_PVFI)(int);

#if defined (_M_CEE)
	typedef const void* (__clrcall *_PVFVM)(void);
	typedef int(__clrcall *_PIFVM)(void);
	typedef void(__clrcall *_CPVFV)(void);
#endif  /* defined (_M_CEE) */

	/*
	* Assert in debug builds.
	* set errno and return
	*
	*/

#include <crtdbg.h> /* k */

#ifdef _DEBUG
#define _CALL_INVALID_PARAMETER(expr) _invalid_parameter(expr, __FUNCTIONW__, __FILEW__, __LINE__, 0)
#define _INVOKE_WATSON_IF_ERROR(expr) _invoke_watson_if_error((expr), __STR2WSTR(#expr), __FUNCTIONW__, __FILEW__, __LINE__, 0)
#define _INVOKE_WATSON_IF_ONEOF(expr, errvalue1, errvalue2) _invoke_watson_if_oneof(expr, (errvalue1), (errvalue2), __STR2WSTR(#expr), __FUNCTIONW__, __FILEW__, __LINE__, 0)
#else  /* _DEBUG */
#define _CALL_INVALID_PARAMETER(expr) _invalid_parameter_noinfo()
#define _INVOKE_WATSON_IF_ERROR(expr) _invoke_watson_if_error(expr, NULL, NULL, NULL, 0, 0)
#define _INVOKE_WATSON_IF_ONEOF(expr, errvalue1, errvalue2) _invoke_watson_if_oneof((expr), (errvalue1), (errvalue2), NULL, NULL, NULL, 0, 0)
#endif  /* _DEBUG */

//#define _INVALID_PARAMETER(expr) _CALL_INVALID_PARAMETER(expr)

#define _VALIDATE_RETURN_ERRCODE( expr, errorcode )                            \
    {                                                                          \
        int _Expr_val=!!(expr);                                                \
        _ASSERT_EXPR( ( _Expr_val ), _CRT_WIDE(#expr) );                       \
        if ( !( _Expr_val ) )                                                  \
        {                                                                      \
            errno = errorcode;                                                 \
            _INVALID_PARAMETER(_CRT_WIDE(#expr));                              \
            return ( errorcode );                                              \
        }                                                                      \
    }
}

//#ifdef __cplusplus
//}
//#endif  /* __cplusplus */

#define CRT_WARNING_DISABLE_PUSH(x,y)    __pragma(warning(push)); __pragma(warning(disable: x))
#define CRT_WARNING_POP                  __pragma(warning(pop))

#pragma pack(pop)

#endif  /* _INC_INTERNAL */