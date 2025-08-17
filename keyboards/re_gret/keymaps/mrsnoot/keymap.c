// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "mrsnoot.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     /*
      * ┌───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┐
      * │ Ä │ U │ O │ M │ Y │       │ P │ D │ C │ L │ Q │
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │ A │ I │ E │ S │ F │       │ G │ H │ T │ N │ R │
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │ Ü │ J │ Ö │ W │ V │       │ Z │ K │ B │ X │ ß │
      * └───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┘
      *               ┌───┐           ┌───┐
      *               │NUM├───┐   ┌───┤SYM│
      *               └───┤SPC│   │RET├───┘
      *                   └───┘   └───┘
      */
    [SONNE] = LAYOUT_split_3x5_2(
        DE_ADIA, DE_U   , DE_O   , DE_M   , DE_Y   ,                   DE_P   , DE_D   , DE_C   , DE_L   , DE_Q   ,
        HRM_S_A, HRM_S_I, HRM_S_E, HRM_S_S, DE_F   ,                   DE_G   , HRM_S_H, HRM_S_T, HRM_S_N, HRM_S_R,
        DE_UDIA, DE_J   , DE_ODIA, DE_W   , DE_V   ,                   DE_Z   , DE_K   , DE_B   , DE_X   , GUI_SS ,
                                            OSL_NUM, NAV_SPC, MS_ENT , OSL_SYM
    ),

    [NAV] = LAYOUT_split_3x5_2(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, KC_HOME, KC_UP  , KC_END , KC_PGUP,
        KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,                   XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                            _______, _______, _______, _______
    ),

    [MOUSE] = LAYOUT_split_3x5_2(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, MICMUTE, XXXXXXX, XXXXXXX,
        KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,                   TB_DPI , KC_BTN1, KC_BTN2, KC_LCTL, KC_LSFT,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, TB_SCR , XXXXXXX, XXXXXXX, XXXXXXX,
                                            _______, _______, TG_MS_L, _______
    ),

    [NUM_FUNC] = LAYOUT_split_3x5_2(
        KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,                   DE_SLSH, DE_7   , DE_8   , DE_9   , DE_MINS,
        NUM_F6 , NUM_F7 , NUM_F8 , NUM_F9 , KC_F10 ,                   DE_ASTR, NUM_4  , NUM_5  , NUM_6  , NUM_PLS,
        KC_F11 , KC_F12 , XXXXXXX, S_LN_F5, XXXXXXX,                   DE_COMM, DE_1   , DE_2   , DE_3   , DE_DOT ,
                                            _______, _______, DE_0   , MO_ADJ
    ),

    [SYMBOL] = LAYOUT_split_3x5_2(
        DE_EXLM, DE_DEG , DE_SECT, DE_DLR , DE_AMPR,                   XXXXXXX, DE_PIPE, DE_CIRC, DE_TILD, XXXXXXX,
        DE_QUES, DE_LCBR, DE_RCBR, DE_LPRN, DE_RPRN,                   XXXXXXX, NP_XMLL, NP_XMLF, DE_ACUT, DE_GRV ,
        XXXXXXX, DE_LBRC, DE_RBRC, DE_LABK, DE_RABK,                   XXXXXXX, F2_CPLN, IM1_INS, XXXXXXX, KC_PSCR,
                                            MO_ADJ , _______, _______, _______
    ),

    [ADJUST] = LAYOUT_split_3x5_2(
        RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX,                   XXXXXXX, KC_NUM , XXXXXXX, XXXXXXX, QK_BOOT,
        XXXXXXX, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX,                   XXXXXXX, KC_CAPS, XXXXXXX, XXXXXXX, XXXXXXX,
        AU_TOGG, CK_TOGG, CK_DOWN, CK_UP  , CK_RST ,                   XXXXXXX, KC_SCRL, XXXXXXX, XXXXXXX, TB_RST ,
                                            _______, _______, _______, _______
    ),
};
  
// WS2812: GPIO11 is the PWR (so it doesn't draw unless you enable it) , GPIO12 DATA
// RGB LED: GPIO16 G, GPIO17 R, GPIO 25 B
void keyboard_post_init_user(void) {
    // LED Green
    gpio_set_pin_output(GP16);
    gpio_write_pin_high(GP16);
    // LED Red
    gpio_set_pin_output(GP17);
    gpio_write_pin_high(GP17);
    // LED Blue
    gpio_set_pin_output(GP25);
    gpio_write_pin_high(GP25);
    // LED RGB
    gpio_set_pin_output(GP11);
    gpio_write_pin_high(GP11);
}