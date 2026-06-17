// Copyright 2020 @jola5
// Copyright 2025 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

/*
Since our quirky block definitions are basically a list of comma separated
arguments, we need a wrapper in order for these definitions to be
expanded before being used as arguments to the LAYOUT_xxx macro.
*/

/*
Blocks for each of the four major keyboard layouts
Organized so we can quickly adapt and modify all of them
at once, rather than for each keyboard, one at a time.
And this allows for much cleaner blocks in the keymaps.
For instance Tap/Hold for Control on all of the layouts

NOTE: These are all the same length.  If you do a search/replace
  then you need to add/remove underscores to keep the
  lengths consistent.
*/
// clang-format off
#define _________________SONNE_L1__________________       DE_ADIA, DE_U   , DE_O   , DE_M   , DE_Y
#define _________________SONNE_L2__________________       HRM_S_A, HRM_S_I, HRM_S_E, HRM_S_S, DE_F
#define _________________SONNE_L3__________________       DE_UDIA, DE_J   , DE_ODIA, DE_W   , DE_V

#define _________________SONNE_R1__________________       DE_P   , DE_D   , LT_MS_C, DE_L   , DE_Q
#define _________________SONNE_R2__________________       DE_G   , HRM_S_H, HRM_S_T, HRM_S_N, HRM_S_R
#define _________________SONNE_R3__________________       DE_Z   , DE_K   , DE_B   , DE_X   , GUI_SS

#define _____________SONNE_THUMB_BASE______________       NUM_SPC, NUM_ENT

#define __________________NAV_L1___________________       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
#define __________________NAV_L2___________________       KC_LSFT, KC_LALT, KC_LCTL, _______, XXXXXXX
#define __________________NAV_L3___________________       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX

#define __________________NAV_R1___________________       XXXXXXX, KC_HOME, KC_UP  , KC_END , KC_PGUP
#define __________________NAV_R2___________________       XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN
#define __________________NAV_R3___________________       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX

#define ______________NAV_THUMB_BASE_______________       KC_LGUI, _______

#define _________________MOUSE_L1__________________       XXXXXXX, XXXXXXX, XXXXXXX, MICMUTE, XXXXXXX
#define _________________MOUSE_L2__________________       KC_LSFT, KC_LALT, KC_LCTL, XXXXXXX, XXXXXXX
#define _________________MOUSE_L3__________________       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX

#define _________________MOUSE_R1__________________       KC_PSCR, MS_BTN1, _______, LT_CMB2, KC_LSFT
#define _________________MOUSE_R2__________________       TG_MS_L, DBL_CLK, XXXXXXX, TB_DPI , TB_SCR
#define _________________MOUSE_R3__________________       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX

#define _____________MOUSE_THUMB_BASE______________       KC_LGUI, XXXXXXX

#define ________________NUM_FUNC_L1________________       KC_F12 , KC_F11 , KC_F10 , KC_F9  , XXXXXXX
#define ________________NUM_FUNC_L2________________       NUM_F8 , NUM_F7 , NUM_F6 , NUM_F5 , ALT_F5
#define ________________NUM_FUNC_L3________________       KC_F4  , KC_F3  , KC_F2  , KC_F1  , XXXXXXX

#define ________________NUM_FUNC_R1________________       DE_MINS, DE_7   , DE_8   , DE_9   , DE_PLUS
#define ________________NUM_FUNC_R2________________       DE_COMM, NUM_4  , NUM_5  , NUM_6  , NUM_DOT
#define ________________NUM_FUNC_R3________________       DE_0   , DE_1   , DE_2   , DE_3   , DE_0

#define ____________NUM_FUNC_THUMB_BASE____________       _______, XXXXXXX

#define _________________SYMBOL_L1_________________       DE_EXLM, DE_DEG , DE_SECT, DE_DLR , DE_AMPR
#define _________________SYMBOL_L2_________________       DE_QUES, DE_LCBR, DE_RCBR, DE_LPRN, DE_RPRN
#define _________________SYMBOL_L3_________________       XXXXXXX, DE_LBRC, DE_RBRC, DE_LABK, DE_RABK

#define _________________SYMBOL_R1_________________       XXXXXXX, XXXXXXX, NP_XMLL, NP_XMLF, DE_PIPE
#define _________________SYMBOL_R2_________________       XXXXXXX, _______, F2_CPLN, IM1_INS, DE_CIRC
#define _________________SYMBOL_R3_________________       XXXXXXX, XXXXXXX, DE_ACUT, DE_GRV , DE_TILD

#define _____________SYMBOL_THUMB_BASE_____________       MO_ADJ , _______

#define _________________ADJUST_L1_________________       RM_TOGG, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
#define _________________ADJUST_L2_________________       AU_TOGG, CK_TOGG, CK_DOWN, CK_UP  , CK_RST
#define _________________ADJUST_L3_________________       AS_TOGG, AS_DOWN, AS_UP  , AS_RPT , XXXXXXX

#define _________________ADJUST_R1_________________       XXXXXXX, XXXXXXX, KC_NUM , XXXXXXX, QK_BOOT
#define _________________ADJUST_R2_________________       XXXXXXX, XXXXXXX, KC_CAPS, XXXXXXX, XXXXXXX
#define _________________ADJUST_R3_________________       XXXXXXX, XXXXXXX, KC_SCRL, XXXXXXX, TB_RST

#define _____________ADJUST_THUMB_BASE_____________       _______, _______