//
// crtdbg.h
//
//      Copyright (c) Microsoft Corporation. All rights reserved.
//
// Public debugging facilities for the CRT
//
#pragma once
#define _INC_CRTDBG

#include "corecrt.h"
#include <vcruntime_new_debug.h>

_CRT_BEGIN_C_HEADER

//_ACRTIMP int __cdecl _CrtDbgReportW(
//	_In_       int            _ReportType,
//	_In_opt_z_ wchar_t const* _FileName,
//	_In_       int            _LineNumber,
//	_In_opt_z_ wchar_t const* _ModuleName,
//	_In_opt_z_ wchar_t const* _Format,
//	...);

#ifndef _DEBUG

#define _CrtDbgBreak() ((void)0)

#ifndef _ASSERT_EXPR
#define _ASSERT_EXPR(expr, msg) ((void)0)
#endif

#ifndef _ASSERT
#define _ASSERT(expr) ((void)0)
#endif

#ifndef _ASSERTE
#define _ASSERTE(expr) ((void)0)
#endif

#define _RPT0(rptno, msg)
#define _RPTN(rptno, msg, ...)

#define _RPTW0(rptno, msg)
#define _RPTWN(rptno, msg, ...)

#define _RPTF0(rptno, msg)
#define _RPTFN(rptno, msg, ...)

#define _RPTFW0(rptno, msg)
#define _RPTFWN(rptno, msg, ...)

#else // ^^^ !_DEBUG ^^^ // vvv _DEBUG vvv //

#define _CrtDbgBreak() __debugbreak()

// !! is used to ensure that any overloaded operators used to evaluate expr
// do not end up at &&.
#ifndef _ASSERT_EXPR
#define _ASSERT_EXPR(expr, msg) \
            (void)(                                                                                     \
                (!!(expr)) ||                                                                           \
                (1 != _CrtDbgReportW(_CRT_ASSERT, _CRT_WIDE(__FILE__), __LINE__, NULL, L"%ls", msg)) || \
                (_CrtDbgBreak(), 0)                                                                     \
            )
#endif

#ifndef _ASSERT
#define _ASSERT(expr) _ASSERT_EXPR((expr), NULL)
#endif

#ifndef _ASSERTE
#define _ASSERTE(expr) _ASSERT_EXPR((expr), _CRT_WIDE(#expr))
#endif

#define _RPT_BASE(...)                           \
        (void) ((1 != _CrtDbgReport(__VA_ARGS__)) || \
                (_CrtDbgBreak(), 0))

#define _RPT_BASE_W(...)                          \
        (void) ((1 != _CrtDbgReportW(__VA_ARGS__)) || \
                (_CrtDbgBreak(), 0))

#define _RPT0(rptno, msg)      _RPT_BASE(rptno, NULL, 0, NULL, "%s", msg)
#define _RPTN(rptno, msg, ...) _RPT_BASE(rptno, NULL, 0, NULL, msg, __VA_ARGS__)

#define _RPTW0(rptno, msg)      _RPT_BASE_W(rptno, NULL, 0, NULL, L"%ls", msg)
#define _RPTWN(rptno, msg, ...) _RPT_BASE_W(rptno, NULL, 0, NULL, msg, __VA_ARGS__)

#define _RPTF0(rptno, msg)      _RPT_BASE(rptno, __FILE__, __LINE__, NULL, "%s", msg)
#define _RPTFN(rptno, msg, ...) _RPT_BASE(rptno, __FILE__, __LINE__, NULL, msg, __VA_ARGS__)

#define _RPTFW0(rptno, msg)      _RPT_BASE_W(rptno, _CRT_WIDE(__FILE__), __LINE__, NULL, L"%ls", msg)
#define _RPTFWN(rptno, msg, ...) _RPT_BASE_W(rptno, _CRT_WIDE(__FILE__), __LINE__, NULL, msg, __VA_ARGS__)

#endif // _DEBUG

_CRT_END_C_HEADER
