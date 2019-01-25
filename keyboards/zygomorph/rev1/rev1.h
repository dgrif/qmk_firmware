#ifndef REV1_H
#define REV1_H

#include "zygomorph.h"

//void promicro_bootloader_jmp(bool program);
#include "quantum.h"

#ifdef RGBLIGHT_ENABLE
//rgb led driver
#include "ws2812.h"
#endif

//void promicro_bootloader_jmp(bool program);
// LEL/LER/REL/RER are
//   LeftEncoderLeft, LeftEncoderRight, RightEncoderLeft, and RightEncoderRight

#define LAYOUT_5x6( \
  L00, L01, L02, L03, L04, L05, \
  L10, L11, L12, L13, L14, L15, \
  L20, L21, L22, L23, L24, L25, \
  L30, L31, L32, L33, L34, L35, \
  L40, L41, L42, L43, L44, L45, \
            LEL, LER \
  ) \
  { \
    { L00, L01, L02, L03, L04, L05, LEL }, \
    { L10, L11, L12, L13, L14, L15, LER }, \
    { L20, L21, L22, L23, L24, L25, KC_NO }, \
    { L30, L31, L32, L33, L34, L35, KC_NO }, \
    { L40, L41, L42, L43, L44, L45, KC_NO }, \
    { KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO } \
    { KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO } \
    { KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO } \
    { KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO } \
    { KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO } \
  }

#define LAYOUT_5x12( \
  L00, L01, L02, L03, L04, L05, R00, R01, R02, R03, R04, R05, \
  L10, L11, L12, L13, L14, L15, R10, R11, R12, R13, R14, R15, \
  L20, L21, L22, L23, L24, L25, R20, R21, R22, R23, R24, R25, \
  L30, L31, L32, L33, L34, L35, R30, R31, R32, R33, R34, R35, \
  L40, L41, L42, L43, L44, L45, R40, R41, R42, R43, R44, R45, \
            LEL, LER,                     REL, RER \
  ) \
  { \
    { L00, L01, L02, L03, L04, L05, LEL }, \
    { L10, L11, L12, L13, L14, L15, LER }, \
    { L20, L21, L22, L23, L24, L25, KC_NO }, \
    { L30, L31, L32, L33, L34, L35, KC_NO }, \
    { L40, L41, L42, L43, L44, L45, KC_NO }, \
    { R00, R01, R02, R03, R04, R05, REL }, \
    { R10, R11, R12, R13, R14, R15, RER }, \
    { R20, R21, R22, R23, R24, R25, KC_NO }, \
    { R30, R31, R32, R33, R34, R35, KC_NO }, \
    { R40, R41, R42, R43, R44, R45, KC_NO } \
  }

#define LAYOUT_4x6( \
  L00, L01, L02, L03, L04, L05, \
  L10, L11, L12, L13, L14, L15, \
  L20, L21, L22, L23, L24, L25, \
  L30, L31, L32, L33, L34, L35, \
            LEL, LER \
  ) \
  { \
    { L00, L01, L02, L03, L04, L05, LEL }, \
    { L10, L11, L12, L13, L14, L15, LER }, \
    { L20, L21, L22, L23, L24, L25, KC_NO }, \
    { L30, L31, L32, L33, L34, L35, KC_NO }, \
    { KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO } \
    { KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO } \
    { KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO } \
    { KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO } \
    { KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO } \
    { KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO } \
  }

#define LAYOUT_4x12( \
  L00, L01, L02, L03, L04, L05, R00, R01, R02, R03, R04, R05, \
  L10, L11, L12, L13, L14, L15, R10, R11, R12, R13, R14, R15, \
  L20, L21, L22, L23, L24, L25, R20, R21, R22, R23, R24, R25, \
  L30, L31, L32, L33, L34, L35, R30, R31, R32, R33, R34, R35, \
            LEL, LER,                     REL, RER \
  ) \
  { \
    { L00, L01, L02, L03, L04, L05, LEL }, \
    { L10, L11, L12, L13, L14, L15, LER }, \
    { L20, L21, L22, L23, L24, L25, KC_NO }, \
    { L30, L31, L32, L33, L34, L35, KC_NO }, \
    { KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO } \
    { R00, R01, R02, R03, R04, R05, REL }, \
    { R10, R11, R12, R13, R14, R15, RER }, \
    { R20, R21, R22, R23, R24, R25, KC_NO }, \
    { R30, R31, R32, R33, R34, R35, KC_NO }, \
    { KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO } \
  }


#endif
