BOOTMAGIC_ENABLE = no
MOUSEKEY_ENABLE = no
EXTRAKEY_ENABLE = yes
CONSOLE_ENABLE = $(if $(filter yes,$(OLED_ENABLE)),no,yes)
COMMAND_ENABLE = yes
NKRO_ENABLE = no
RGBLIGHT_ENABLE = yes
RGB_MATRIX_ENABLE = no
ENCODER_ENABLE = yes
OLED_ENABLE = no
LTO_ENABLE = yes

SRC += keyboards/rgbkb/zygomorph/common/fork_oled.c
