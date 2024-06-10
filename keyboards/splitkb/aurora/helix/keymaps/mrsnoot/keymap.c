/* Copyright 2023 splitkb.com <support@splitkb.com>
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
    KC_ESC , DE_Q   , DE_Z   , DE_O   , DE_P   , DE_Y   ,                   DE_W   , DE_C   , DE_M   , DE_V   , DE_X   , KC_LGUI,
    XXXXXXX, HRM_O_H, HRM_O_A, HRM_O_E, HRM_O_I, DE_K   ,                   DE_G   , HRM_O_T, HRM_O_N, HRM_O_S, HRM_O_R, KC_ENT ,
    KC_BTN2, DE_J   , DE_ODIA, DE_ADIA, DE_U   , DE_UDIA,                   DE_B   , DE_D   , DE_L   , DE_F   , DE_SS  , V_DESKT,
    KC_BTN1, TB_SCR , XXXXXXX, XXXXXXX, THUMB_1, THUMB_2, XXXXXXX, XXXXXXX, THUMB_3, THUMB_4, CS_VDPR, CS_VDNX, CS_TSPR, CS_TSNX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),

[NAV] = LAYOUT(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, KC_HOME, KC_UP  , KC_END , KC_PGUP, XXXXXXX,
    XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,                   XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, MO_ADJ , _______, _______, _______, _______,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),

[NUM_FUNC] = LAYOUT(
    XXXXXXX, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,                   DE_SLSH, DE_7   , DE_8   , DE_9   , DE_MINS, XXXXXXX,
    XXXXXXX, NUM_F6 , NUM_F7 , NUM_F8 , NUM_F9 , KC_F10 ,                   DE_ASTR, NUM_4  , NUM_5  , NUM_6  , NUM_PLS, XXXXXXX,
    XXXXXXX, KC_F11 , KC_F12 , XXXXXXX, S_LN_F5, XXXXXXX,                   DE_COMM, DE_1   , DE_2   , DE_3   , DE_DOT , XXXXXXX,
    _______, _______, CS_PGU , CS_PGD , _______, _______, _______, _______, _______, DE_0   , _______, _______, _______, _______,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),

[SYMBOL] = LAYOUT(
    XXXXXXX, DE_EXLM, DE_DEG , DE_SECT, DE_DLR , DE_AMPR,                   XXXXXXX, NP_XMLL, NP_XMLF, DE_ACUT, DE_GRV , XXXXXXX,
    XXXXXXX, DE_QUES, DE_LCBR, DE_LBRC, DE_LPRN, DE_LABK,                   XXXXXXX, DE_PIPE, DE_CIRC, DE_TILD, XXXXXXX, KC_PSCR,
    XXXXXXX, XXXXXXX, DE_RCBR, DE_RBRC, DE_RPRN, DE_RABK,                   XXXXXXX, F2_CPLN, IM1_INS, XXXXXXX, XXXXXXX, XXXXXXX,
    MS_BN13, KC_BTN3, XXXXXXX, XXXXXXX, MO_ADJ , _______, _______, _______, _______, _______, _______, _______, _______, _______,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),

[ADJUST] = LAYOUT(
    QK_BOOT, RGB_TOG, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, RGUI(KC_7), RGUI(KC_8), RGUI(KC_9), KC_NUM , XXXXXXX,
    EE_CLR , AU_TOGG, CK_TOGG, CK_DOWN, CK_UP  , CK_RST ,                   TB_DPI , RGUI(KC_4), RGUI(KC_5), RGUI(KC_6), KC_CAPS, XXXXXXX,
    TB_RST , AS_TOGG, AS_DOWN, AS_UP  , AS_RPT , XXXXXXX,                   XXXXXXX, RGUI(KC_1), RGUI(KC_2), RGUI(KC_3), KC_SCRL, XXXXXXX,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______   , _______   , _______   , _______, _______,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX   , XXXXXXX   , XXXXXXX   , XXXXXXX, XXXXXXX
)
};