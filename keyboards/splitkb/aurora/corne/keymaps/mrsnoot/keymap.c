/* Copyright 2021 MrSnoot
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
[OPY] = LAYOUT_split_3x6_3(
    KC_ESC , DE_Q   , DE_Z   , DE_O   , DE_P   , DE_Y,                      DE_W   , DE_C   , DE_M   , DE_V   , DE_X   , KC_LGUI,
    KC_BTN2, HRM_O_H, HRM_O_A, HRM_O_E, HRM_O_I, DE_K,                      DE_G,    HRM_O_T, HRM_O_N, HRM_O_S, HRM_O_R, KC_ENT,
    KC_BTN1, DE_J,    DE_ODIA, DE_ADIA, DE_U,    DE_UDIA,                   DE_B,    DE_D,    DE_L,    DE_F,    DE_SS,   V_DESKT,
                                        XXXXXXX, OSL_NUM, NAV_SPC, MS_ENT , OSL_SYM, XXXXXXX 
),
  
[NAV] = LAYOUT_split_3x6_3(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, KC_HOME, KC_UP,   KC_END,  KC_PGUP, XXXXXXX,
    XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,                   XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                        _______, _______, _______, _______, _______, _______
),

[MOUSE] = LAYOUT_split_3x6_3(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,                   TB_DPI , KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, TB_SCR , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                        _______, _______, _______, _______, _______, _______
),

[NUM_FUNC] = LAYOUT_split_3x6_3(
    XXXXXXX, KC_F1,  KC_F2,  KC_F3,   KC_F4,   KC_F5,                     DE_SLSH, DE_7,  DE_8,  DE_9,  DE_MINS, XXXXXXX,
    XXXXXXX, NUM_F6, NUM_F7, NUM_F8,  NUM_F9,  KC_F10,                    DE_ASTR, NUM_4, NUM_5, NUM_6, NUM_PLS, XXXXXXX,
    XXXXXXX, KC_F11, KC_F12, XXXXXXX, S_LN_F5, XXXXXXX,                   DE_COMM, DE_1,  DE_2,  DE_3,  DE_DOT,  XXXXXXX,
                                      _______, _______, _______, DE_0   , MO_ADJ , _______
),

[SYMBOL] = LAYOUT_split_3x6_3(
    XXXXXXX, DE_EXLM, DE_DEG,  DE_SECT, DE_DLR,  DE_AMPR,                   XXXXXXX, NP_XMLL, NP_XMLF, DE_ACUT, DE_GRV , XXXXXXX,
    XXXXXXX, DE_QUES, DE_LCBR, DE_LBRC, DE_LPRN, DE_LABK,                   XXXXXXX, DE_PIPE, DE_CIRC, DE_TILD, TB_SCR , KC_PSCR,
    MS_BN13, KC_BTN3, DE_RCBR, DE_RBRC, DE_RPRN, DE_RABK,                   XXXXXXX, F2_CPLN, IM1_INS, XXXXXXX, XXXXXXX, XXXXXXX,
                                        _______, MO_ADJ,  _______, _______, _______, _______
),

[ADJUST] = LAYOUT_split_3x6_3(
    XXXXXXX, RGB_TOG, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, KC_NUM , XXXXXXX, XXXXXXX, QK_BOOT, XXXXXXX,
    XXXXXXX, AU_TOGG, CK_TOGG, CK_DOWN, CK_UP  , CK_RST,                    XXXXXXX, KC_CAPS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, AS_TOGG, AS_DOWN, AS_UP  , AS_RPT , XXXXXXX,                   XXXXXXX, KC_SCRL, XXXXXXX, XXXXXXX, TB_RST , XXXXXXX,
                                        _______, _______, _______, _______, _______, _______
),
};