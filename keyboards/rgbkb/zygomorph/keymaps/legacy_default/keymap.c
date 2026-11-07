// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_number {
    _QWERTY = 0,
    _COLEMAK,
    _FN,
    _ADJ
};

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  FN,
  ADJ,
  BACKLIT,
  RGBRST
};

enum macro_keycodes {
  KC_SAMPLEMACRO,
};



#define FN_ESC  LT(_FN, KC_ESC)
#define FN_CAPS  LT(_FN, KC_CAPS)
// Define your non-alpha grouping in this define's LAYOUT, and all your BASE_LAYERS will share the same mod/macro columns

#define BASE_LAYOUT( \
  _00, _01, _02, _03, _04,  _05, _06, _07, _08, _09, \
  _10, _11, _12, _13, _14,  _15, _16, _17, _18, _19, \
  _20, _21, _22, _23, _24,  _25, _26, _27, _28, _29 \
) \
LAYOUT_ortho_5x12( \
      QK_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,   KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
      KC_TAB,  _00,     _01,     _02,     _03,     _04,    _05,     _06,     _07,     _08,     _09,     KC_BSLS, \
      QK_BOOT,   _10,     _11,     _12,     _13,     _14,    _15,     _16,     _17,     _18,     _19,     KC_QUOT, \
      KC_LSFT, _20,     _21,     _22,     _23,     _24,    _25,     _26,     _27,     _28,     _29,     KC_ENT, \
      KC_LCTL, KC_LGUI, KC_LALT, UG_TOGG, ADJ,     KC_SPC, KC_SPC,  FN,      KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT \
)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = BASE_LAYOUT( \
      KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    \
      KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, \
      KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH  \
  ),

  [_COLEMAK] = BASE_LAYOUT( \
      KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,   KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, \
      KC_A,    KC_R,    KC_S,    KC_T,    KC_G,   KC_K,    KC_N,    KC_E,    KC_I,    KC_O,    \
      KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,   KC_M,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH  \
  ),

  [_FN] = LAYOUT_ortho_5x12( \
      KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, \
      _______, KC_PGDN, KC_UP,   KC_PGUP, _______, _______, _______, KC_PGDN, KC_UP,   KC_PGUP, KC_PSCR, KC_HOME, \
      _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_INS, KC_END, \
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
      _______, _______, _______, UG_NEXT, _______, _______, _______, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU \
      ),

  [_ADJ] =  LAYOUT_ortho_5x12( \
      KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,    KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, \
      _______, UG_SATD, UG_VALU, UG_SATU, QK_BOOT,   _______, _______, _______, _______, _______, _______, _______, \
      _______, UG_HUED, UG_VALD, UG_HUEU, RGBRST,  _______, _______, QWERTY,  COLEMAK, _______, _______, _______, \
      _______, _______, _______, _______, _______, _______, _______, _______, UG_TOGG, UG_HUEU, UG_SATU, UG_VALU, \
      _______, _______, _______, UG_NEXT, _______, _______, _______, _______, UG_PREV,UG_HUED, UG_SATD, UG_VALD \
      )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  //uint8_t shifted = get_mods() & (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_RSHIFT));

  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case COLEMAK:
      if(record->event.pressed) {
        set_single_persistent_default_layer(_COLEMAK);
      }
      return false;
      break;
    case FN:
      if (record->event.pressed) {
        layer_on(_FN);
      } else {
        layer_off(_FN);
      }
      return false;
      break;
    case ADJ:
        if (record->event.pressed) {
          layer_on(_ADJ);
        } else {
          layer_off(_ADJ);
        }
        return false;
        break;
    case RGBRST:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          eeconfig_update_rgblight_default();
          rgblight_enable();
        }
      #endif
      break;
  }
  return true;
}


bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index < 2) {
        tap_code(clockwise ? KC_VOLD : KC_VOLU);
    }
    return false;
}
