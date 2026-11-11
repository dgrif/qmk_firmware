// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H

enum layers {
    _QWERTY,
    // Keep saved EVE defaults compatible; layer 1 was Colemak.
    _EVE = 2,
    _LEFT,
    _RIGHT,
    _EVE_LEFT,
    _ADJUST,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_ergodox_pretty(
        KC_GRV,  KC_1,        KC_2,    KC_3,    KC_4,      KC_5, KC_NO,          KC_NO, KC_6, KC_7,       KC_8,    KC_9,    KC_0,    KC_BSPC,
        KC_ESC,  KC_Q,        KC_W,    KC_E,    KC_R,      KC_T, KC_NO,          KC_NO, KC_Y, KC_U,       KC_I,    KC_O,    KC_P,    KC_BSLS,
        KC_TAB,  KC_A,        KC_S,    KC_D,    KC_F,      KC_G,                        KC_H, KC_J,       KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LSFT, CTL_T(KC_Z), KC_X,    KC_C,    KC_V,      KC_B, KC_NO,          KC_NO, KC_N, KC_M,       KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
        KC_LCTL, KC_LGUI,     KC_LALT, KC_NO,   MO(_EVE_LEFT),                               MO(_RIGHT), KC_MINS, KC_EQL,  KC_PGUP, KC_PGDN,
                                                    KC_LGUI, KC_LALT,          KC_LEFT, KC_RGHT,
                                                             KC_HOME,          KC_UP,
                                            KC_SPC, KC_DEL,   KC_END,           KC_DOWN, KC_ENT, KC_SPC
    ),

    [_LEFT] = LAYOUT_ergodox_pretty(
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5, KC_F6,   _______,            _______, KC_F7,   KC_F8,   KC_F9,   KC_F10, KC_F11, KC_F12,
        _______, KC_NO,   KC_NO,   KC_NO,   QK_BOOT, KC_LBRC, _______,          _______, KC_RBRC, KC_PGUP, KC_UP,   KC_PGDN, KC_INS, KC_HOME,
        _______, KC_NO,   KC_NO,   KC_NO,   _______, _______,                           _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_DEL, KC_END,
        KC_LSFT, _______, _______, _______, _______, _______, _______,         _______, NK_TOGG, _______, _______, KC_MPLY, KC_MPRV, KC_MNXT,
        KC_LCTL, KC_LGUI, KC_LALT, KC_NO,   _______,                                             _______, _______, KC_MUTE, KC_VOLU, KC_VOLD,
                                                    _______, _______,         _______, _______,
                                                             _______,         _______,
                                           _______, _______, _______,         _______, _______, _______
    ),

    [_RIGHT] = LAYOUT_ergodox_pretty(
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5, KC_F6,   _______,            _______, KC_F7,   KC_F8,   KC_F9,   KC_F10, KC_F11, KC_F12,
        _______, KC_NO,   KC_NO,   KC_NO,   QK_BOOT, KC_LBRC, _______,          _______, KC_RBRC, KC_PGUP, KC_UP,   KC_PGDN, KC_INS, KC_HOME,
        _______, KC_NO,   KC_NO,   KC_NO,   _______, _______,                           _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_DEL, KC_END,
        KC_LSFT, _______, _______, _______, _______, _______, _______,         _______, NK_TOGG, _______, _______, KC_MPLY, KC_MPRV, KC_MNXT,
        KC_LCTL, KC_LGUI, KC_LALT, KC_NO,   _______,                                             _______, _______, KC_MUTE, KC_VOLU, KC_VOLD,
                                                    _______, _______,         _______, _______,
                                                             _______,         _______,
                                           _______, _______, _______,         _______, _______, _______
    ),

    [_EVE] = LAYOUT_ergodox_pretty(
        KC_GRV,  KC_1,        KC_2,    KC_3,    KC_4,          KC_5, KC_NO,      KC_NO, KC_6, KC_7,       KC_8,    KC_9,    KC_0,    KC_BSPC,
        KC_ESC,  KC_Q,        KC_W,    KC_E,    KC_R,          KC_T, KC_NO,      KC_NO, KC_Y, KC_U,       KC_I,    KC_O,    KC_P,    KC_BSLS,
        KC_TAB,  KC_A,        KC_S,    KC_D,    KC_F,          KC_G,                    KC_H, KC_J,       KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LSFT, CTL_T(KC_Z), KC_X,    KC_C,    KC_V,          KC_B, KC_NO,      KC_NO, KC_N, KC_M,       KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
        KC_LCTL, KC_LGUI,     KC_LALT, KC_NO,   MO(_EVE_LEFT),                               MO(_RIGHT), KC_MINS, KC_EQL,  KC_PGUP, KC_PGDN,
                                                    KC_LGUI, KC_LALT,          KC_LEFT, KC_RGHT,
                                                             KC_HOME,          KC_UP,
                                            KC_SPC, KC_DEL,   KC_END,           KC_DOWN, KC_ENT, KC_SPC
    ),

    [_EVE_LEFT] = LAYOUT_ergodox_pretty(
        KC_F1,   KC_F2,        KC_F3,        KC_F4,        KC_F5,        KC_F6,        _______, _______, KC_F7,   KC_F8,   KC_F9,   KC_F10, KC_F11, KC_F12,
        _______, KC_F1,        KC_F2,        KC_F3,        KC_F4,        KC_F5,        _______, _______, KC_RBRC, KC_PGUP, KC_UP,   KC_PGDN, KC_INS, KC_HOME,
        _______, ALT_T(KC_F1), ALT_T(KC_F2), ALT_T(KC_F3), ALT_T(KC_F4), ALT_T(KC_F5),                   _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_DEL, KC_END,
        KC_LSFT, CTL_T(KC_F1), CTL_T(KC_F2), CTL_T(KC_F3), CTL_T(KC_F4), CTL_T(KC_F5), _______, _______, NK_TOGG, _______, _______, KC_MPLY, KC_MPRV, KC_MNXT,
        KC_LCTL, KC_LGUI,      KC_LALT,      KC_NO,        _______,                                               _______, _______, KC_MUTE, KC_VOLU, KC_VOLD,
                                                    _______, _______,         _______, _______,
                                                             _______,         _______,
                                           _______, _______, _______,         _______, _______, _______
    ),

    [_ADJUST] = LAYOUT_ergodox_pretty(
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6, _______,            _______, KC_F7,          KC_F8,        KC_F9,   KC_F10,   KC_F11,   KC_F12,
        _______, QK_BOOT, _______, _______, _______, _______, _______,       _______, _______,        _______,      _______, _______,  _______,  KC_DEL,
        _______, _______, _______, _______, _______, _______,                        _______,        PDF(_QWERTY), _______,     _______, PDF(_EVE), _______,
        _______, KC_NO,   KC_NO,   _______, _______, _______, _______,        _______, _______,        _______,      _______, _______,  _______,  _______,
        _______, _______, _______, _______, _______,                                                 _______,      _______, _______,  _______,  _______,
                                                    _______, _______,         _______, _______,
                                                             _______,         _______,
                                           _______, _______, _______,         _______, _______, _______
    ),
};
// clang-format on

layer_state_t default_layer_state_set_user(layer_state_t state) {
    // A previously saved Colemak default now falls back to QWERTY.
    if (state & (1UL << 1)) {
        return (state & ~(1UL << 1)) | (1UL << _QWERTY);
    }
    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    const layer_state_t left_nav  = (1UL << _LEFT) | (1UL << _EVE_LEFT);
    const layer_state_t right_nav = 1UL << _RIGHT;
    const layer_state_t adjust    = 1UL << _ADJUST;

    if ((state & left_nav) && (state & right_nav)) {
        return state | adjust;
    }
    return state & ~adjust;
}
