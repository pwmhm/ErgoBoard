#pragma once
#include "quantum.h"

#ifdef VIAL_ENABLE
    #define CUSTOM_CONFIG QK_KB_0
#else
    #define CUSTOM_CONFIG SAFE_RANGE
#endif

enum ergo_kc {
    SCROLL_CPI_UP = CUSTOM_CONFIG,
    SCROLL_CPI_DOWN,
    MOUSE_CPI_UP,
    MOUSE_CPI_DOWN,
    SCROLL_MODE_TB,
    SCROLL_MODE_TB_MO
};