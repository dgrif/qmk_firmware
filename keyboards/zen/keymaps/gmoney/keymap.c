#include "zen.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _COLEMAK 1
#define _LEFT 2
#define _RIGHT 3
#define _EVE 4
#define _EVE_LEFT 5
#define _ADJUST 6


enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  LEFT,
  RIGHT,
  EVE,
  EVE_LEFT,
  ADJUST

};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------.             .-----------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |             |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |             |   Y  |   U  |   I  |   O  |   P  |   \  |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |             |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * | Shift| Ctl/Z|   X  |   C  |   V  |   B  |             |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------..-----+------+------+------+------+------+------|
 * | Ctrl | GUI  | Alt  |RGBTOG| NAV  |Space |Delete||Enter|Space |  NAV |   -  |   =  | PGUP | PGDN |
 * `------------------------------------------------''-----------------------------------------------'
 */
[_QWERTY] = KEYMAP( \
  KC_GRV,           KC_1,    KC_2,    KC_3,    KC_4,     KC_5,                       KC_6,     KC_7,     KC_8,    KC_9,    KC_0,    KC_BSPC, \
  KC_ESC,           KC_Q,    KC_W,    KC_E,    KC_R,     KC_T,                       KC_Y,     KC_U,     KC_I,    KC_O,    KC_P,    KC_BSLS, \
  KC_TAB,           KC_A,    KC_S,    KC_D,    KC_F,     KC_G,                       KC_H,     KC_J,     KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  KC_LSFT,   CTL_T(KC_Z),    KC_X,    KC_C,    KC_V,     KC_B,                       KC_N,     KC_M,     KC_COMM, KC_DOT,  KC_SLSH, KC_ENT , \
  KC_LCTL,          KC_LGUI, KC_LALT, RGB_TOG, MO(_LEFT), KC_SPC,  KC_DEL,  KC_ENT,   KC_SPACE, MO(_RIGHT), KC_MINS, KC_EQL,  KC_PGUP, KC_PGDN \
),

/* TODO: Fix this */
[_COLEMAK] = KEYMAP( \
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, \
    KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,                      KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_DEL , \
    KC_CAPS, KC_A,    KC_R,    KC_S,    KC_T,    KC_D,                      KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT, \
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                      KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, \
    MO(_LEFT),   KC_LCTL, KC_LALT, KC_LEFT, KC_RGHT, KC_BSPC, KC_LGUI, KC_ENT,  KC_SPC,  KC_UP,   KC_DOWN, KC_RGUI, KC_RCTL, MO(_RIGHT)   \
  ),

/* Left NAV
 * ,-----------------------------------------.             .-----------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |             |  F7  |  F8  |  F9  |  F10 |  F11 | F12  |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * |      |RGBSAI|RGBVAI|RGBSAD| RESET|  [   |             |   ]  | Pgup |  Up  | Pgdn |Insert| Home |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * |      |RGBHUD|RGBVAD|RGBHUI|      |      |             |      | Left | Down | Right|Delete| End  |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * |Shift |      |      |      |      |      |             | NKRO |      |      | Pause| Back | Next |
 * |------+------+------+------+------+------+------..-----+------+------+------+------+------+------|
 * | Ctrl | GUI  | Alt  |RGBMOD|      |      |      ||     |      |      |      | Mute | VOLUP| VOLDN|
 * `------------------------------------------------''-----------------------------------------------'
 */
[_LEFT] = KEYMAP( \
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                     KC_F7,             KC_F8,    KC_F9,   KC_F10,  KC_F11,  KC_F12 ,  \
  _______, RGB_SAI, RGB_VAI, RGB_SAD, RESET,   KC_LBRC,                   KC_RBRC,           KC_PGUP,  KC_UP,   KC_PGDN, KC_INS,  KC_HOME , \
  _______, RGB_HUD, RGB_VAD, RGB_HUI, _______, _______,                   _______,           KC_LEFT,  KC_DOWN, KC_RGHT, KC_DEL,  KC_END , \
  KC_LSFT, _______, _______, _______, _______, _______,                   MAGIC_TOGGLE_NKRO, _______,  _______, KC_MPLY, KC_MPRV, KC_MNXT , \
  KC_LCTL, KC_LGUI, KC_LALT, RGB_MOD, _______, _______, _______, _______, _______,           _______,  _______, KC_MUTE, KC_VOLU, KC_VOLD \
),

/* Right NAV
 * ,-----------------------------------------.             .-----------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |             |  F7  |  F8  |  F9  |  F10 |  F11 | F12  |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * |      |RGBSAI|RGBVAI|RGBSAD| RESET|  [   |             |   ]  | Pgup |  Up  | Pgdn |Insert| Home |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * |      |RGBHUD|RGBVAD|RGBHUI|      |      |             |      | Left | Down | Right|Delete| End  |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * |Shift |      |      |      |      |      |             | NKRO |      |      | Pause| Back | Next |
 * |------+------+------+------+------+------+------..-----+------+------+------+------+------+------|
 * | Ctrl | GUI  | Alt  |RGBMOD|      |      |      ||     |      |      |      | Mute | VOLUP| VOLDN|
 * `------------------------------------------------''-----------------------------------------------'
 */
[_RIGHT] = KEYMAP( \
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                     KC_F7,             KC_F8,    KC_F9,   KC_F10,  KC_F11,  KC_F12 ,  \
  _______, RGB_SAI, RGB_VAI, RGB_SAD, RESET,   KC_LBRC,                   KC_RBRC,           KC_PGUP,  KC_UP,   KC_PGDN, KC_INS,  KC_HOME , \
  _______, RGB_HUD, RGB_VAD, RGB_HUI, _______, _______,                   _______,           KC_LEFT,  KC_DOWN, KC_RGHT, KC_DEL,  KC_END , \
  KC_LSFT, _______, _______, _______, _______, _______,                   MAGIC_TOGGLE_NKRO, _______,  _______, KC_MPLY, KC_MPRV, KC_MNXT , \
  KC_LCTL, KC_LGUI, KC_LALT, RGB_MOD, _______, _______, _______, _______, _______,           _______,  _______, KC_MUTE, KC_VOLU, KC_VOLD \
),

/* Eve Qwerty
 * ,-----------------------------------------.             .-----------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |             |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |             |   Y  |   U  |   I  |   O  |   P  |   \  |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |             |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * | Shift| Ctl/Z|   X  |   C  |   V  |   B  |             |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------..-----+------+------+------+------+------+------|
 * | Ctrl | GUI  | Alt  |RGBTOG| NAV  |Space |Delete||Enter|Space |  NAV |   -  |   =  | PGUP | PGDN |
 * `------------------------------------------------''-----------------------------------------------'
 */
[_EVE] = KEYMAP( \
  KC_GRV,           KC_1,    KC_2,    KC_3,    KC_4,          KC_5,                       KC_6,     KC_7,     KC_8,    KC_9,    KC_0,    KC_BSPC, \
  KC_ESC,           KC_Q,    KC_W,    KC_E,    KC_R,          KC_T,                       KC_Y,     KC_U,     KC_I,    KC_O,    KC_P,    KC_BSLS, \
  KC_TAB,           KC_A,    KC_S,    KC_D,    KC_F,          KC_G,                       KC_H,     KC_J,     KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  KC_LSFT,   CTL_T(KC_Z),    KC_X,    KC_C,    KC_V,          KC_B,                       KC_N,     KC_M,     KC_COMM, KC_DOT,  KC_SLSH, KC_ENT , \
  KC_LCTL,          KC_LGUI, KC_LALT, RGB_TOG, MO(_EVE_LEFT), KC_SPC,  KC_DEL,  KC_ENT,   KC_SPACE, MO(_RIGHT), KC_MINS, KC_EQL,  KC_PGUP, KC_PGDN \
),

/* EVE_LEFT TODO: Gfx needs updating
 * ,-----------------------------------------.             .-----------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |             |  F7  |  F8  |  F9  |  F10 |  F11 | F12  |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * |      |RGBSAI|RGBVAI|RGBSAD| RESET|  [   |             |   ]  | Pgup |  Up  | Pgdn |Insert| Home |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * |      |RGBHUD|RGBVAD|RGBHUI|      |      |             |      | Left | Down | Right|Delete| End  |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * |Shift |      |      |      |      |      |             | NKRO |      |      | Pause| Back | Next |
 * |------+------+------+------+------+------+------..-----+------+------+------+------+------+------|
 * | Ctrl | GUI  | Alt  |RGBMOD|      |      |      ||     |      |      |      | Mute | VOLUP| VOLDN|
 * `------------------------------------------------''-----------------------------------------------'
 */
[_EVE_LEFT] = KEYMAP( \
  KC_F1,           KC_F2,        KC_F3,        KC_F4,        KC_F5,        KC_F6,                     KC_F7,           KC_F8,    KC_F9,   KC_F10,  KC_F11,  KC_F12 ,  \
  _______,         KC_F1,        KC_F2,        KC_F3,        KC_F4,        KC_F5,                   KC_RBRC,           KC_PGUP,  KC_UP,   KC_PGDN, KC_INS,  KC_HOME , \
  _______,  ALT_T(KC_F1), ALT_T(KC_F2), ALT_T(KC_F3), ALT_T(KC_F4), ALT_T(KC_F5),                   _______,           KC_LEFT,  KC_DOWN, KC_RGHT, KC_DEL,  KC_END , \
  KC_LSFT,  CTL_T(KC_F1), CTL_T(KC_F2), CTL_T(KC_F3), CTL_T(KC_F4), CTL_T(KC_F5),                   MAGIC_TOGGLE_NKRO, _______,  _______, KC_MPLY, KC_MPRV, KC_MNXT , \
  KC_LCTL,       KC_LGUI,      KC_LALT,      RGB_MOD,      _______,      _______, _______, _______, _______,           _______,  _______, KC_MUTE, KC_VOLU, KC_VOLD \
),

/* Adjust (Left + Right)
 * ,-----------------------------------------              .------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |             |   F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------+             | ------+------+------+------+------+------|
 * |      | Reset|      |      |      |      |             |       |      |      |      |      |  Del |
 * |------+------+------+------+------+-------             | ------+------+------+------+------+------|
 * |      |      |      |Aud on|AudOff|AGnorm|             | AGswap|Qwerty|Colemk|Dvorak|Eve   |      |
 * |------+------+------+------+------+------|             | ------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|MusOff|MidiOn|             | MidOff|      |      |      |      |      |
 * |------+------+------+------+------+------+------..-----+ ------+------+------+------+------+------+
 * |      |      |      |      |      |      |      ||     |       |      |      |      |      |      | 
 * `------------------------------------------------''------------------------------------------------'
 */
[_ADJUST] = KEYMAP( \
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                     KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,\
  _______, RESET,   _______, _______, _______, _______,                   _______, _______, _______, _______, _______, KC_DEL,\
  _______, _______, _______, _______, _______, _______,                   _______,  QWERTY, COLEMAK, _______,  EVE   , _______,\
  _______, MUV_DE,  MUV_IN,  _______, _______, _______,                   _______, _______, _______, _______, _______, _______,\
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______\
),
};

void persistant_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

void matrix_init_user(void) {
   // This will disable the red LEDs on the ProMicros
   DDRD &= ~(1<<5);
   PORTD &= ~(1<<5);
   DDRB &= ~(1<<0);
   PORTB &= ~(1<<0);
}

/*
#define _QWERTY 0
#define _LEFT 1
#define _RIGHT 2
#define _EVE 3
#define _EVE_LEFT 4
#define _ADJUST 5
*/
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // There are three primary layers, QWERTY, Colemak and Eve
    case QWERTY:
      if (record->event.pressed) {
        persistant_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case COLEMAK:
      if (record->event.pressed) {
        persistant_default_layer_set(1UL<<_COLEMAK);
      }
      return false;
      break;
    case EVE:
      if (record->event.pressed) {
        persistant_default_layer_set(1UL<<_EVE);
      }
      return false;
      break;
    // Then there are a few momentary layers
    case LEFT:
      if (record->event.pressed) {
        layer_on(_LEFT);
        update_tri_layer(_LEFT, _RIGHT, _ADJUST);
      } else {
        layer_off(_LEFT);
        update_tri_layer(_LEFT, _RIGHT, _ADJUST);
      }
      return false;
      break;
    case RIGHT:
      if (record->event.pressed) {
        layer_on(_RIGHT);
        update_tri_layer(_LEFT, _RIGHT, _ADJUST);
      } else {
        layer_off(_RIGHT);
        update_tri_layer(_LEFT, _RIGHT, _ADJUST);
      }
      return false;
      break;
    case EVE_LEFT:
      if (record->event.pressed) {
        layer_on(_EVE_LEFT);
        update_tri_layer(_EVE_LEFT, _RIGHT, _ADJUST);
      } else {
        layer_off(_EVE_LEFT);
        update_tri_layer(_EVE_LEFT, _RIGHT, _ADJUST);
      }
      return false;
      break;
  }
  return true;
}
