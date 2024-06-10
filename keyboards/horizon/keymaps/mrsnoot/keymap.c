/* Copyright 2021 Steven Karrmann
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
[OPY] = LAYOUT(
    DE_Q   , DE_Z   , DE_O   , DE_P   , DE_Y   , XXXXXXX,                   XXXXXXX, DE_W   , DE_C   , DE_M   , DE_V   , DE_X   ,
    HRM_O_H, HRM_O_A, HRM_O_E, HRM_O_I, DE_K   , XXXXXXX,                   XXXXXXX, DE_G   , HRM_O_T, HRM_O_N, HRM_O_S, HRM_O_R,
    DE_J   , DE_ODIA, DE_ADIA, DE_U   , DE_UDIA, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DE_B   , DE_D   , DE_L   , DE_F   , GUI_SS ,
    XXXXXXX, XXXXXXX, XXXXXXX, NUM_FUN, NAV_SPC, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, NAV_ENT, OSL_SYM, XXXXXXX, XXXXXXX, XXXXXXX
),

[NAV] = LAYOUT(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, KC_HOME, KC_UP  , KC_END , KC_PGUP,
    KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, XXXXXXX, XXXXXXX, KC_BTN1, KC_BTN2, TB_SCR , XXXXXXX,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

[NUM_FUNC] = LAYOUT(
    KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , XXXXXXX,                   XXXXXXX, DE_SLSH, DE_7  , DE_8   , DE_9   , DE_MINS,
    NUM_F6 , NUM_F7 , NUM_F8 , NUM_F9 , KC_F10 , XXXXXXX,                   XXXXXXX, DE_ASTR, NUM_4 , NUM_5  , NUM_6  , NUM_PLS,
    KC_F11 , KC_F12 , XXXXXXX, S_LN_F5, XXXXXXX, XXXXXXX, _______, _______, XXXXXXX, DE_COMM, DE_1  , DE_2   , DE_3   , DE_DOT ,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, DE_0   , MO_ADJ, _______, _______, _______
),

[SYMBOL] = LAYOUT(
    DE_EXLM, DE_DEG , DE_SECT, DE_DLR , DE_AMPR, XXXXXXX,                   XXXXXXX, XXXXXXX, NP_XMLL, NP_XMLF, DE_ACUT, DE_GRV ,
    DE_QUES, DE_LCBR, DE_RCBR, DE_LPRN, DE_RPRN, XXXXXXX,                   XXXXXXX, XXXXXXX, DE_PIPE, DE_CIRC, DE_TILD, KC_PSCR,
    XXXXXXX, DE_LBRC, DE_RBRC, DE_LABK, DE_RABK, XXXXXXX, _______, _______, XXXXXXX, XXXXXXX, F2_CPLN, IM1_INS, XXXXXXX, XXXXXXX,
    _______, _______, _______, MO_ADJ , _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

[ADJUST] = LAYOUT(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, KC_NUM , XXXXXXX, XXXXXXX, QK_BOOT,
    AU_TOGG, CK_TOGG, CK_DOWN, CK_UP  , CK_RST , XXXXXXX,                   XXXXXXX, TB_DPI , KC_CAPS, XXXXXXX, XXXXXXX, XXXXXXX,
    AS_TOGG, AS_DOWN, AS_UP  , AS_RPT , XXXXXXX, XXXXXXX, _______, _______, XXXXXXX, XXXXXXX, KC_SCRL, XXXXXXX, XXXXXXX, TB_RST ,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
)
};