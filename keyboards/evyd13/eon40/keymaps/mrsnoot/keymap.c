/* Copyright 2019 Evy Dekkers
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H
#include "mrsnoot.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[SONNE] = LAYOUT_ortho_4x12_2x2u(
    DE_ADIA, DE_U   , DE_O   , DE_M   , DE_Y   , XXXXXXX, XXXXXXX, DE_P   , DE_D   , DE_C   , DE_L   , DE_Q   ,
    HRM_S_A, HRM_S_I, HRM_S_E, HRM_S_S, DE_F   , XXXXXXX, XXXXXXX, DE_G   , HRM_S_H, HRM_S_T, HRM_S_N, HRM_S_R,
    DE_UDIA, DE_J   , DE_ODIA, DE_W   , DE_V   , XXXXXXX, XXXXXXX, DE_Z   , DE_K   , DE_B   , DE_X   , GUI_SS ,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, NUM_SPC,                   SYM_ENT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),

[NAV] = LAYOUT_ortho_4x12_2x2u(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_HOME, KC_UP  , KC_END , KC_PGUP,
    KC_LSFT, KC_LALT, KC_LCTL, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    _______, _______, _______, _______, KC_LGUI,                   _______, _______, _______, _______, _______
),

[MOUSE] = LAYOUT_ortho_4x12_2x2u(
    XXXXXXX, XXXXXXX, XXXXXXX, MICMUTE, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, TB_SCR , TG_MS_L, XXXXXXX,
    KC_LSFT, KC_LALT, KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, KC_BTN2, KC_LCTL, KC_LSFT,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DBL_CLK, XXXXXXX, TB_DPI ,
    _______, _______, _______, _______, KC_LGUI,                   KC_BTN1, _______, _______, _______, _______
),

[NUM_FUNC] = LAYOUT_ortho_4x12_2x2u(
    KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , XXXXXXX, XXXXXXX, DE_SLSH, DE_7   , DE_8   , DE_9   , DE_MINS,
    NUM_F6 , NUM_F7 , NUM_F8 , NUM_F9 , KC_F10 , XXXXXXX, XXXXXXX, DE_ASTR, NUM_4  , NUM_5  , NUM_6  , NUM_PLS,
    KC_F11 , KC_F12 , XXXXXXX, S_LN_F5, XXXXXXX, XXXXXXX, XXXXXXX, DE_COMM, DE_1   , DE_2   , DE_3   , DE_DOT ,
    _______, _______, _______, _______, _______,                   DE_0   , _______, _______, _______, _______
),

[SYMBOL] = LAYOUT_ortho_4x12_2x2u(
    DE_EXLM, DE_DEG , DE_SECT, DE_DLR , DE_AMPR, XXXXXXX, XXXXXXX, XXXXXXX, DE_PIPE, DE_CIRC, DE_TILD, XXXXXXX,
    DE_QUES, DE_LCBR, DE_RCBR, DE_LPRN, DE_RPRN, XXXXXXX, XXXXXXX, XXXXXXX, NP_XMLL, NP_XMLF, DE_ACUT, DE_GRV ,
    XXXXXXX, DE_LBRC, DE_RBRC, DE_LABK, DE_RABK, XXXXXXX, XXXXXXX, XXXXXXX, F2_CPLN, IM1_INS, XXXXXXX, KC_PSCR,
    _______, _______, _______, _______, MO_ADJ ,                   _______, _______, _______, _______, _______
),

[ADJUST] = LAYOUT_ortho_4x12_2x2u(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_NUM , XXXXXXX, XXXXXXX, QK_BOOT,
    AU_TOGG, CK_TOGG, CK_DOWN, CK_UP  , CK_RST , XXXXXXX, XXXXXXX, XXXXXXX, KC_CAPS, XXXXXXX, XXXXXXX, XXXXXXX,
    AS_TOGG, AS_DOWN, AS_UP  , AS_RPT , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_SCRL, XXXXXXX, XXXXXXX, TB_RST ,
    _______, _______, _______, _______, _______,                   _______, _______, _______, _______,   _______
),
};