//
// corecrt.h
//
//      Copyright (c) Microsoft Corporation. All rights reserved.
//
// Declarations used throughout the CoreCRT library.
//
#pragma once

#include <vcruntime.h>

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//
// Annotation Macros
//
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
#ifndef _ACRTIMP
#if defined _CRTIMP && !defined _VCRT_DEFINED_CRTIMP
#define _ACRTIMP _CRTIMP
#elif !defined _CORECRT_BUILD && defined _DLL
#define _ACRTIMP __declspec(dllimport)
#else
#define _ACRTIMP
#endif
#endif

#if defined _PREFAST_ && defined _CA_SHOULD_CHECK_RETURN
#define _Check_return_opt_ _Check_return_
#else
#define _Check_return_opt_
#endif

typedef int                           errno_t;