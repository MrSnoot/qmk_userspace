/* Copyright 2023 Colin Lam (Ploopy Corporation)
 * Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
 * Copyright 2019 Sunjun Kim
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

// #define SW_L_0
#define SW_L_1 LT(1, KC_BTN2)
#define SW_L_2 MO(2)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT( SW_L_1     , CS_VDPR, CS_VDNX, DBL_CLK   , 
                  DRAG_SCROLL,                   KC_BTN1    ),

    [1] = LAYOUT( XXXXXXX    , CS_TSNX, CS_TSPR, XXXXXXX   , 
                  SW_L_2     ,                   DPI_CONFIG ),

    [2] = LAYOUT( XXXXXXX    , CK_TOGG, AU_TOGG, XXXXXXX   ,
                  _______    ,                   QK_BOOT    ),
};

// const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//     [0] = LAYOUT( DRAG_SCROLL, SW_L_1 , KC_BTN1, DBL_CLK    , 
//                   CS_VDPR    ,                   CS_VDNX    ),

//     [1] = LAYOUT( XXXXXXX    , XXXXXXX, CS_TSNX, CS_TSPR   , 
//                   SW_L_2     ,                   DPI_CONFIG),

//     [2] = LAYOUT( XXXXXXX    , _______, AU_TOGG, CK_TOGG   ,
//                   _______    ,                   QK_BOOT   ),
// };