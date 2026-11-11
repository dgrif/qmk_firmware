# Zen-Style ErgoDox Keymap

This keymap adapts `keyboards\rgbkb\zen\rev1\keymaps\gmoney` to `ergodox_ez/base`, without RGB lighting, RGB matrix, audio, or backlight support. It keeps the Zen QWERTY, navigation/media, and EVE gaming bindings; Colemak is removed. QWERTY and EVE retain Ctrl/Z with a 100 ms tapping term.

## Layout Adaptation

The top four main rows retain Zen's six-key-per-half QWERTY ordering. The extra inner ErgoDox keys are unused. Former RGB and audio-only controls are disabled rather than generating unrelated key presses.

The bottom and thumb controls are consistent across QWERTY and EVE.

| Position | Left half, left to right | Right half, left to right |
| --- | --- | --- |
| Five-key bottom row | Ctrl, GUI, Alt, unused, left NAV | right NAV, Minus, Equals, Page Up, Page Down |
| Two upper thumb keys | GUI, Alt | Left, Right |
| Small middle thumb key | Home | Up |
| Bottom thumb row | Space, Delete, End | Down, Enter, Space |

The two large left thumb keys are Space/Delete; the two large right thumb keys are Enter/Space. Navigation layers keep the thumb keys transparent.

## Navigation and Layer Selection

Hold **left NAV** for the EVE module bindings from either QWERTY or EVE: Q/W/E/R/T become F1-F5, A/S/D/F/G their Alt-tap variants, and Z/X/C/V/B their Ctrl-tap variants. Release it to return to typing; selecting EVE first is no longer necessary. These variants preserve the original mod-tap behavior: tap for the function key, hold for Alt or Ctrl; they are not single-tap Alt+Fn/Ctrl+Fn shortcuts.

Hold **right NAV** for regular navigation: F1-F12, brackets, arrows, Home/End, Insert/Delete, media controls, and NKRO toggle. Left NAV also retains the top-row function keys and right-hand navigation/media bindings.

Hold **both NAV keys** to enter Adjust, including while using EVE. On Adjust, the right home row is unused, QWERTY, unused, unused, EVE, unused. Those selection keys persist the default layer in EEPROM; the two typing modes now have identical bindings. Release NAV to return to typing. This corrects the original Zen keymap's unreachable tri-layer combination without modifying the Zen keymap itself.

All typing layers are below the navigation overlays in layer priority, so right NAV works when EVE is the persistent default as well.

Existing layer IDs are preserved so a saved EVE default remains valid after flashing. Layer 1 is unused, and a previously saved Colemak default falls back to QWERTY automatically; no EEPROM reset is required.

Bootloader entry is available at the Q position on Adjust, or the R position on right NAV, matching Zen's reset bindings.

## Build

For visual review, upload the repository-root [ergodox-zen-keymap.json](../../../../ergodox-zen-keymap.json) using **Upload a QMK Keymap JSON File** at [QMK Configurator](https://config.qmk.fm/). Its layers are ordered by firmware ID: 0 QWERTY, 1 unused, 2 EVE, 3 legacy navigation (not bound to a key), 4 right NAV, 5 EVE left NAV, and 6 Adjust. The empty slot preserves the firmware's IDs; it contains no Colemak bindings.

The JSON is a binding/layout export, not a replacement for this C keymap: it does not include the custom both-NAV-to-Adjust hook, the saved-Colemak fallback, or the 100 ms tapping configuration. Use the locally built firmware rather than a Configurator build if you want those behaviors. Keep the export outside this keymap directory so QMK does not select it instead of `keymap.c`.

From QMK MSYS at the repository root:

```sh
qmk compile -kb ergodox_ez/base -km gmoney
```

The resulting firmware is `ergodox_ez_base_gmoney.hex`. This retains the base target's ATmega32U4, MCP23018 matrix expander, and HalfKay bootloader assumptions. A non-EZ ErgoDox is compatible only if its controller, matrix wiring, expander, and bootloader match; the absence of RGB alone does not establish compatibility. Do not flash it onto a different controller or bootloader without selecting the appropriate hardware target.
