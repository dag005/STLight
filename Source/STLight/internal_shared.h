//
// internal_shared.h
//
//      Copyright (c) Microsoft Corporation. All rights reserved.
//
// Header-only utilities used by both the VCRuntime and the CoreCRT.
//
#pragma once

#include "crtdbg.h"
//#include <intrin.h>
//#include <malloc.h>
#include "stdlib.h"
#include <vcruntime.h>
#include <windows.h>

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//
// Preprocessor Utilities and Awesome Macros
//
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
// Attributes for managed declarations in the CRT
#ifdef _M_CEE
#define _CRT_INTEROPSERVICES_DLLIMPORT(_DllName , _EntryPoint , _CallingConvention) \
        [System::Runtime::InteropServices::DllImport( \
            _DllName , EntryPoint = _EntryPoint, CallingConvention = _CallingConvention)]
#define _CRT_SUPPRESS_UNMANAGED_CODE_SECURITY [System::Security::SuppressUnmanagedCodeSecurity]
#define _CRT_CALLING_CONVENTION_CDECL System::Runtime::InteropServices::CallingConvention::Cdecl
#define _CRT_CALLING_CONVENTION_WINAPI System::Runtime::InteropServices::CallingConvention::Winapi
#define _CRT_RELIABILITY_CONTRACT \
        [System::Runtime::ConstrainedExecution::ReliabilityContract( \
            System::Runtime::ConstrainedExecution::Consistency::WillNotCorruptState, \
            System::Runtime::ConstrainedExecution::Cer::Success)]
#define _CRT_ASSERT_UNMANAGED_CODE_ATTRIBUTE \
        [System::Security::Permissions::SecurityPermissionAttribute( \
            System::Security::Permissions::SecurityAction::Assert, UnmanagedCode = true)]
#define _CRT_SECURITYCRITICAL_ATTRIBUTE [System::Security::SecurityCritical]
#define _CRT_SECURITYSAFECRITICAL_ATTRIBUTE [System::Security::SecuritySafeCritical]
#else
#define _CRT_INTEROPSERVICES_DLLIMPORT(_DllName , _EntryPoint , _CallingConvention)
#define _CRT_SUPPRESS_UNMANAGED_CODE_SECURITY
#define _CRT_CALLING_CONVENTION_CDECL
#define _CRT_CALLING_CONVENTION_WINAPI
#define _CRT_RELIABILITY_CONTRACT
#define _CRT_ASSERT_UNMANAGED_CODE_ATTRIBUTE
#define _CRT_SECURITYCRITICAL_ATTRIBUTE
#define _CRT_SECURITYSAFECRITICAL_ATTRIBUTE
#endif

//#ifdef _DEBUG
//#define _INVALID_PARAMETER(expr) _invalid_parameter(expr, __FUNCTIONW__, __FILEW__, __LINE__, 0)
//#else
#define _INVALID_PARAMETER(expr) _invalid_parameter_noinfo()
//#endif

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

#define _BEGIN_SECURE_CRT_DEPRECATION_DISABLE \
    __pragma(warning(push))                   \
    __pragma(warning(disable:4996))           \
    __pragma(warning(disable:6053))

#define _END_SECURE_CRT_DEPRECATION_DISABLE   \
    __pragma(warning(pop))

#define _VALIDATE_RETURN_ERRCODE(expr, errorcode)                              \
    {                                                                          \
        int _Expr_val=!!(expr);                                                \
        _ASSERT_EXPR((_Expr_val), _CRT_WIDE(#expr));                           \
        if (!(_Expr_val))                                                      \
        {                                                                      \
            errno = errorcode;                                                 \
            _INVALID_PARAMETER(_CRT_WIDE(#expr));                              \
            return errorcode;                                                  \
        }                                                                      \
    }