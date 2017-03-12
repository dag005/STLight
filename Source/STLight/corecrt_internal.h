#pragma once

#include "internal_shared.h"
//#include <corecrt_internal_fls.h>
//#include <corecrt_internal_state_isolation.h>

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