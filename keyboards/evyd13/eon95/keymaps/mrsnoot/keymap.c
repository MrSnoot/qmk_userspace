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
[QWERTY] = LAYOUT_all(
    KC_ESC,           KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  XXXXXXX,          KC_DEL, KC_PSCR, KC_SCRL, KC_PAUS,
    KC_GRV,           KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  XXXXXXX, KC_BSPC, KC_NUM, KC_PSLS, KC_PAST, KC_PMNS,
    KC_TAB,           KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, XXXXXXX,          KC_P7,  KC_P8,   KC_P9,   KC_PPLS,
    LADJ_CPS,         HRM_Q_A, HRM_Q_S, HRM_Q_D, HRM_Q_F, KC_G,    KC_H,    HRM_Q_J, HRM_Q_K, HRM_Q_L, HRM_QOE, KC_QUOT, KC_NUHS, KC_ENT,           KC_P4,  KC_P5,   KC_P6,   KC_PPLS,
    KC_BTN2, KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,              KC_UP,        KC_P1,  KC_P2,   KC_P3,   KC_PENT,
    KC_BTN1, KC_LGUI, KC_LALT,                                     LNAV_SPC,                  KC_RALT, KC_RGUI, KC_RCTL,     KC_LEFT, KC_DOWN, KC_RGHT,     KC_P0,   KC_PDOT
),

[NAV] = LAYOUT_all(
    _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______,
    _______,          _______, _______, _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, _______, _______, _______, _______,
    _______,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_HOME, KC_UP,   KC_END,  KC_PGUP, XXXXXXX, _______, _______,          _______, _______, _______, _______,
    _______,          KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, XXXXXXX, _______, _______,          _______, _______, _______, _______,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,              _______,      _______, _______, _______, _______,
    _______, _______, _______,                                     _______,                   _______, _______, _______,     _______, _______, _______,      _______, _______
),

[ADJUST] = LAYOUT_all(
    QK_BOOT,          TB_RST , _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,             _______, _______, _______, _______,
    _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______,
    _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,             _______, _______, _______, _______,
    _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,             _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,              TB_DPI ,         _______, _______, _______, _______,
    _______, _______, _______,                                     _______,                   _______, _______, _______,     _______, _______, _______,         _______, _______
),
};