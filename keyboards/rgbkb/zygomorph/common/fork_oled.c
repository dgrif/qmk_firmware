// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H

#ifdef OLED_ENABLE
bool oled_task_user(void) {
    if (!is_keyboard_master()) {
        static const char PROGMEM logo[] = {0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94, 0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4, 0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4, 0};
        oled_write_P(logo, false);
        return false;
    }

    static const char PROGMEM mode_logo[2][2][3] = {{{0x95, 0x96, 0}, {0xb5, 0xb6, 0}}, {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}}};
    uint8_t                   mode               = keymap_config.swap_lalt_lgui ? 1 : 0;
    oled_write_ln_P(mode_logo[mode][0], false);
    oled_write_ln_P(mode_logo[mode][1], false);
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state | default_layer_state)) {
        case 0:
            oled_write_ln_P(PSTR("QWERTY"), false);
            break;
        case 1:
            oled_write_ln_P(PSTR("Colemak"), false);
            break;
        case 2:
            oled_write_ln_P(PSTR("FN"), false);
            break;
        case 3:
            oled_write_ln_P(PSTR("ADJ"), false);
            break;
    }
    led_t leds = host_keyboard_led_state();
    oled_write_P(leds.num_lock ? PSTR("NUMLOCK ") : PSTR("        "), false);
    oled_write_P(leds.caps_lock ? PSTR("CAPS ") : PSTR("     "), false);
    oled_write_P(leds.scroll_lock ? PSTR("SCLK") : PSTR("    "), false);
    return false;
}
#endif
