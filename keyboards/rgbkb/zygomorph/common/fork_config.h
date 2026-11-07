// SPDX-License-Identifier: GPL-2.0-or-later
#pragma once

// This fork's PCB wiring differs from the current upstream revision.
#undef MATRIX_COL_PINS
#define MATRIX_COL_PINS {F4, F6, C7, D5, B6, D4}

#define TAPPING_TERM 150
#define QUICK_TAP_TERM 0
#define RGBLIGHT_HUE_STEP 10
#define RGBLIGHT_SAT_STEP 17
#define RGBLIGHT_VAL_STEP 12
#define RGBLIGHT_RAINBOW_SWIRL_RANGE 1950
#define OLED_FONT_H "keyboards/rgbkb/zygomorph/common/glcdfont.c"
