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
    XXXXXXX, DE_Q   , DE_Z   , DE_O   , DE_P   , DE_Y   ,                   DE_W   , DE_C   , DE_M   , DE_V   , DE_X   , XXXXXXX,
    XXXXXXX, HRM_O_H, HRM_O_A, HRM_O_E, HRM_O_I, DE_K   ,                   DE_G   , HRM_O_T, HRM_O_N, HRM_O_S, HRM_O_R, XXXXXXX,
    XXXXXXX, DE_J   , DE_ODIA, DE_ADIA, DE_U   , DE_UDIA,                   DE_B   , DE_D   , DE_L   , DE_F   , GUI_SS , XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, OSL_NUM, NAV_SPC, XXXXXXX, XXXXXXX, MS_ENT , OSL_SYM, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),

/* ä u o m y  p d c l q
   a i e s f  g h t n r
   ü j ö w v  z k b x ß 
*/
[SONNE] = LAYOUT(
    XXXXXXX, DE_ADIA, DE_U   , DE_O   , DE_M   , DE_Y   ,                   DE_P   , DE_D   , DE_C   , DE_L   , DE_Q   , XXXXXXX,
    XXXXXXX, HRM_S_A, HRM_S_I, HRM_S_E, HRM_S_S, DE_F   ,                   DE_G   , HRM_S_H, HRM_S_T, HRM_S_N, HRM_S_R, XXXXXXX,
    XXXXXXX, DE_UDIA, DE_J   , DE_ODIA, DE_W   , DE_V   ,                   DE_Z   , DE_K   , DE_B   , DE_X   , GUI_SS , XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, OSL_NUM, NAV_SPC, XXXXXXX, XXXXXXX, MS_ENT , OSL_SYM, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),

[NAV] = LAYOUT(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, KC_HOME, KC_UP  , KC_END , KC_PGUP, XXXXXXX,
    XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,                   XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),

[MOUSE] = LAYOUT(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, MICMUTE, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,                   TB_DPI , KC_BTN1, KC_BTN2, KC_LCTL, KC_LSFT, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, TB_SCR , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    _______, _______, _______, _______, _______, _______, _______, _______, TG_MS_L, _______, _______, _______, _______, _______,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),

[NUM_FUNC] = LAYOUT(
    XXXXXXX, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,                   DE_SLSH, DE_7   , DE_8   , DE_9   , DE_MINS, XXXXXXX,
    XXXXXXX, NUM_F6 , NUM_F7 , NUM_F8 , NUM_F9 , KC_F10 ,                   DE_ASTR, NUM_4  , NUM_5  , NUM_6  , NUM_PLS, XXXXXXX,
    XXXXXXX, KC_F11 , KC_F12 , XXXXXXX, S_LN_F5, XXXXXXX,                   DE_COMM, DE_1   , DE_2   , DE_3   , DE_DOT , XXXXXXX,
    _______, _______, _______, _______, _______, _______, _______, _______, DE_0   , MO_ADJ , _______, _______, _______, _______,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),

[SYMBOL] = LAYOUT(
    XXXXXXX, DE_EXLM, DE_DEG , DE_SECT, DE_DLR , DE_AMPR,                   XXXXXXX, DE_PIPE, DE_CIRC, DE_TILD, XXXXXXX, XXXXXXX,
    XXXXXXX, DE_QUES, DE_LCBR, DE_RCBR, DE_LPRN, DE_RPRN,                   XXXXXXX, NP_XMLL, NP_XMLF, DE_ACUT, DE_GRV , XXXXXXX,
    XXXXXXX, XXXXXXX, DE_LBRC, DE_RBRC, DE_LABK, DE_RABK,                   XXXXXXX, F2_CPLN, IM1_INS, XXXXXXX, KC_PSCR, XXXXXXX,
    _______, _______, _______, _______, MO_ADJ , _______, _______, _______, _______, _______, _______, _______, _______, _______,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),

[ADJUST] = LAYOUT(
    XXXXXXX, RGB_TOG, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, KC_NUM,  XXXXXXX, DF(OPY),   QK_BOOT, XXXXXXX,
    XXXXXXX, AU_TOGG, CK_TOGG, CK_DOWN, CK_UP  , CK_RST ,                   XXXXXXX, KC_CAPS, XXXXXXX, DF(SONNE), XXXXXXX, XXXXXXX,
    XXXXXXX, AS_TOGG, AS_DOWN, AS_UP  , AS_RPT , XXXXXXX,                   XXXXXXX, KC_SCRL, XXXXXXX, XXXXXXX,   TB_RST , XXXXXXX,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______, _______,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX
)
};