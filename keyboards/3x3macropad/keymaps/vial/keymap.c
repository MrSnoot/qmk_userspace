#include QMK_KEYBOARD_H

#define ____ KC_TRNS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT(
        KC_1,  KC_2,    KC_3,
		KC_4,   KC_5,   KC_6,
		KC_7,   KC_8,   KC_9
    ),

    [1] = LAYOUT(
        ____, ____,    ____,
		____,   ____,   ____,
		____,   ____,   ____
    ),

    [2] = LAYOUT(
        ____, ____,    ____,
		____,   ____,   ____,
		____,   ____,   ____
    ),

    [3] = LAYOUT(
        ____, ____,    ____,
		____,   ____,   ____,
		____,   ____,   ____
    ),

};

