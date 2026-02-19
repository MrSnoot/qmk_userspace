#include QMK_KEYBOARD_H
#include "mrsnoot.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [SONNE] = LAYOUT_eg(
        DE_ADIA, DE_U   , DE_O   , DE_M   , DE_Y   ,                   DE_P   , DE_D   , LT_MS_C, DE_L   , DE_Q   ,
        HRM_S_A, HRM_S_I, HRM_S_E, HRM_S_S, DE_F   ,                   DE_G   , HRM_S_H, HRM_S_T, HRM_S_N, HRM_S_R,
        DE_UDIA, DE_J   , DE_ODIA, DE_W   , DE_V   ,                   DE_Z   , DE_K   , DE_B   , DE_X   , GUI_SS ,
                                   XXXXXXX, XXXXXXX, NUM_SPC, NUM_ENT, XXXXXXX, XXXXXXX
    ),

    [NAV] = LAYOUT_eg(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, KC_HOME, KC_UP  , KC_END , KC_PGUP,
        KC_LSFT, KC_LALT, KC_LCTL, _______, XXXXXXX,                   XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                   _______, _______, KC_LGUI, _______, _______, _______
    ),

    [MOUSE] = LAYOUT_eg(
        XXXXXXX, XXXXXXX, XXXXXXX, MICMUTE, XXXXXXX,                   KC_PSCR, MS_BTN1, _______, LT_CMB2, KC_LSFT,
        KC_LSFT, KC_LALT, KC_LCTL, XXXXXXX, XXXXXXX,                   TG_MS_L, DBL_CLK, XXXXXXX, TB_DPI , TB_SCR ,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                   _______, _______, KC_LGUI, XXXXXXX, _______, _______
    ),

    [NUM_FUNC] = LAYOUT_eg(
        KC_F12 , KC_F11 , KC_F10 , KC_F9  , XXXXXXX,                   DE_MINS, DE_7   , DE_8   , DE_9   , DE_PLUS,
        NUM_F8 , NUM_F7 , NUM_F6 , NUM_F5 , ALT_F5 ,                   DE_COMM, NUM_4  , NUM_5  , NUM_6  , NUM_DOT,
        KC_F4  , KC_F3  , KC_F2  , KC_F1  , XXXXXXX,                   DE_COMM, DE_1   , DE_2   , DE_3   , DE_0   ,
                                   _______, _______, _______, XXXXXXX, _______, _______
    ),

    [SYMBOL] = LAYOUT_eg(
        DE_EXLM, DE_DEG , DE_SECT, DE_DLR , DE_AMPR,                   XXXXXXX, XXXXXXX, NP_XMLL, NP_XMLF, DE_PIPE,
        DE_QUES, DE_LCBR, DE_RCBR, DE_LPRN, DE_RPRN,                   XXXXXXX, _______, F2_CPLN, IM1_INS, DE_CIRC,
        XXXXXXX, DE_LBRC, DE_RBRC, DE_LABK, DE_RABK,                   XXXXXXX, XXXXXXX, DE_ACUT, DE_GRV , DE_TILD,
                                   _______, _______, MO_ADJ , _______, _______, _______
    ),

    [ADJUST] = LAYOUT_eg(
        RM_TOGG, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, KC_NUM , XXXXXXX, QK_BOOT,
        AU_TOGG, CK_TOGG, CK_DOWN, CK_UP  , CK_RST ,                   XXXXXXX, XXXXXXX, KC_CAPS, XXXXXXX, XXXXXXX,
        AS_TOGG, AS_DOWN, AS_UP  , AS_RPT , XXXXXXX,                   XXXXXXX, XXXXXXX, KC_SCRL, XXXXXXX, TB_RST ,
                                   _______, _______, _______, _______, _______, _______
    ),
};

// bool led_update_user(led_t led_state) {

//     return true;
// }