# Quantum Mechanical Keyboard Firmware

[![Current Version](https://img.shields.io/github/tag/qmk/qmk_firmware.svg)](https://github.com/qmk/qmk_firmware/tags)
[![Discord](https://img.shields.io/discord/440868230475677696.svg)](https://discord.gg/qmk)
[![Docs Status](https://img.shields.io/badge/docs-ready-orange.svg)](https://docs.qmk.fm)
[![GitHub contributors](https://img.shields.io/github/contributors/qmk/qmk_firmware.svg)](https://github.com/qmk/qmk_firmware/pulse/monthly)
[![GitHub forks](https://img.shields.io/github/forks/qmk/qmk_firmware.svg?style=social&label=Fork)](https://github.com/qmk/qmk_firmware/)

This is a keyboard firmware based on the [tmk\_keyboard firmware](https://github.com/tmk/tmk_keyboard) with some useful features for Atmel AVR and ARM controllers, and more specifically, the [OLKB product line](https://olkb.com), the [ErgoDox EZ](https://ergodox-ez.com) keyboard, and the Clueboard product line.

## This Fork's Keymaps

This fork tracks the stable `master` branch of [qmk/qmk_firmware](https://github.com/qmk/qmk_firmware), not the website repository `qmk/qmk.fm`. The 2026 migration integrates upstream commit `f5db962110` while retaining the custom typing, Colemak, navigation, and EVE gaming layers.

Run these commands from QMK MSYS, selecting the revision that matches your hardware:

```sh
qmk compile -kb preonic/rev2 -km dgrif
qmk compile -kb keebio/nyquist/rev1 -km gmoney
qmk compile -kb rgbkb/zen/rev1 -km gmoney
qmk compile -kb rgbkb/zygomorph/rev1 -km gmoney
qmk compile -kb rgbkb/zygomorph/rev1 -km legacy_default
qmk compile -kb rgbkb/zygomorph/rev1 -km kageurufu
```

The old `nyquist` and `zen` keymaps now live under their upstream vendor directories. Zen's keymap is revision-specific and retains its `F4` backlight using the timer driver and its 100 ms tapping term. Preonic uses layout macros instead of an AVR-only matrix initializer.

The three migrated Zygomorph keymaps share `keyboards/rgbkb/zygomorph/common/fork_config.h`: the fourth matrix column remains **D5**, not upstream's C6, and RGB LEDs remain on **B7**. They retain EEPROM-based handedness (`EE_HANDS`), mirrored 30-LED lighting with the original brightness limit, the 150 ms tapping term, and volume control on both encoders. Upstream's `default` keymap is untouched; use `legacy_default` for the fork's old default and its wiring workaround. Do not flash upstream's `default` onto the board with the pin issue.

OLED support is off by default. Enable the modern OLED driver, retaining the original font and status display, with `qmk compile -kb rgbkb/zygomorph/rev1 -km gmoney -e OLED_ENABLE=yes`; these builds disable the debug console to fit in flash. Existing handedness EEPROM settings must match the left and right halves; firmware compilation does not verify physical wiring or flash the keyboard.

## Documentation

* [See the official documentation on docs.qmk.fm](https://docs.qmk.fm)

The docs are powered by [VitePress](https://vitepress.dev/). They are also viewable offline; see [Previewing the Documentation](https://docs.qmk.fm/#/contributing?id=previewing-the-documentation) for more details.

You can request changes by making a fork and opening a [pull request](https://github.com/qmk/qmk_firmware/pulls).

## Supported Keyboards

* [Planck](/keyboards/planck/)
* [Preonic](/keyboards/preonic/)
* [ErgoDox EZ](/keyboards/ergodox_ez/)
* [Clueboard](/keyboards/clueboard/)
* [Cluepad](/keyboards/clueboard/17/)
* [Atreus](/keyboards/atreus/)

The project also includes community support for [lots of other keyboards](/keyboards/).

## Maintainers

QMK is developed and maintained by Jack Humbert of OLKB with contributions from the community, and of course, [Hasu](https://github.com/tmk). The OLKB product firmwares are maintained by [Jack Humbert](https://github.com/jackhumbert), the Ergodox EZ by [ZSA Technology Labs](https://github.com/zsa), the Clueboard by [Zach White](https://github.com/skullydazed), and the Atreus by [Phil Hagelberg](https://github.com/technomancy).

## Official Website

[qmk.fm](https://qmk.fm) is the official website of QMK, where you can find links to this page, the documentation, and the keyboards supported by QMK.
