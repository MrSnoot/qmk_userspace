/*
Copyright 2024 Nachie

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include QMK_KEYBOARD_H
#include "mrsnoot.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[SONNE] = LAYOUT(
		KC_ESC ,                                                       CS_VDPR, CS_VDNX, CS_TSPR, CS_TSNX,
		DE_ADIA, DE_U   , DE_O   , DE_M   , DE_Y   , XXXXXXX, DE_P   , DE_D   , LT_MS_C, DE_L   , DE_Q   ,
    HRM_S_A, HRM_S_I, HRM_S_E, HRM_S_S, DE_F   , XXXXXXX, DE_G   , HRM_S_H, HRM_S_T, HRM_S_N, HRM_S_R,
    DE_UDIA, DE_J   , DE_ODIA, DE_W   , DE_V   , XXXXXXX, DE_Z   , DE_K   , DE_B   , DE_X   , GUI_SS ,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, NUM_SPC, XXXXXXX, NUM_ENT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),

[NAV] = LAYOUT(
    _______,                                                       _______, _______, _______, _______,
		XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_HOME, KC_UP  , KC_END , KC_PGUP,
    KC_LSFT, KC_LALT, KC_LCTL, _______, XXXXXXX, XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    _______, _______, _______, _______, KC_LGUI, XXXXXXX, _______, _______, _______, _______, _______
),

[MOUSE] = LAYOUT(
    _______,                                                       _______, _______, _______, _______,
		XXXXXXX, XXXXXXX, XXXXXXX, MICMUTE, XXXXXXX, XXXXXXX, KC_PSCR, MS_BTN1, _______, LT_CMB2, KC_LSFT,
    KC_LSFT, KC_LALT, KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, TG_MS_L, DBL_CLK, XXXXXXX, TB_DPI , TB_SCR ,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    _______, _______, _______, _______, KC_LGUI, XXXXXXX, XXXXXXX, _______, _______, _______, _______
),

[NUM_FUNC] = LAYOUT(
    _______,                                                       _______, _______, _______, _______,
		KC_F12 , KC_F11 , KC_F10 , KC_F9  , XXXXXXX, XXXXXXX, DE_MINS, DE_7   , DE_8   , DE_9   , DE_PLUS,
    NUM_F8 , NUM_F7 , NUM_F6 , NUM_F5 , ALT_F5 , XXXXXXX, DE_COMM, NUM_4  , NUM_5  , NUM_6  , NUM_DOT,
    KC_F4  , KC_F3  , KC_F2  , KC_F1  , XXXXXXX, XXXXXXX, DE_COMM, DE_1   , DE_2   , DE_3   , DE_0   ,
    _______, _______, _______, _______, _______, XXXXXXX, XXXXXXX, _______, _______, _______, _______
),

[SYMBOL] = LAYOUT(
    _______,                                                       _______, _______, _______, _______,
		DE_EXLM, DE_DEG , DE_SECT, DE_DLR , DE_AMPR, XXXXXXX, XXXXXXX, XXXXXXX, NP_XMLL, NP_XMLF, DE_PIPE,
    DE_QUES, DE_LCBR, DE_RCBR, DE_LPRN, DE_RPRN, XXXXXXX, XXXXXXX, _______, F2_CPLN, IM1_INS, DE_CIRC,
    XXXXXXX, DE_LBRC, DE_RBRC, DE_LABK, DE_RABK, XXXXXXX, XXXXXXX, XXXXXXX, DE_ACUT, DE_GRV , DE_TILD,
    _______, _______, _______, _______, MO_ADJ , XXXXXXX, _______, _______, _______, _______, _______
),

[ADJUST] = LAYOUT(
    _______,                                                       _______, _______, _______, _______,
		XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_NUM , XXXXXXX, QK_BOOT,
    AU_TOGG, CK_TOGG, CK_DOWN, CK_UP  , CK_RST , XXXXXXX, XXXXXXX, XXXXXXX, KC_CAPS, XXXXXXX, XXXXXXX,
    AS_TOGG, AS_DOWN, AS_UP  , AS_RPT , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_SCRL, XXXXXXX, TB_RST ,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),
};
