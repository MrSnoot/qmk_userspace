#include QMK_KEYBOARD_H
#include "mrsnoot.h"


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     /*
      * ┌───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┐
      * │ Q │ Z │ O │ P │ Y │       │ W │ C │ M │ V │ X │
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │ H │ A │ E │ I │ K │       │ G │ T │ N │ S │ R │
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │ J │ Ö │ Ä │ U │ Ü │       │ B │ D │ L │ F │ ß │
      * └───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┘
      *           ┌───┐                   ┌───┐
      *           │DEL├───┐           ┌───┤ESC│
      *           └───┤SPC├───┐   ┌───┤BSP├───┘
      *               └───│LOW│   │RSE├───┘
      *                   └───┘   └───┘
      */


    [OPY] = LAYOUT_split_3x5_3(
        DE_Q   , DE_Z   , DE_O   , DE_P   , DE_Y   ,                   DE_W   , DE_C   , DE_M   , DE_V   , DE_X   ,
        HRM_O_H, HRM_O_A, HRM_O_E, HRM_O_I, DE_K   ,                   DE_G   , HRM_O_T, HRM_O_N, HRM_O_S, HRM_O_R,
        DE_J   , DE_ODIA, DE_ADIA, DE_U   , DE_UDIA,                   DE_B   , DE_D   , DE_L   , DE_F   , GUI_SS ,
                                   XXXXXXX, OSL_NUM, NAV_SPC, MS_ENT , OSL_SYM, XXXXXXX
    ),

    /* ä u o m y  p d c l q
    a i e s f  g h t n r
    ü j ö w v  z k b x ß 
    */
    [SONNE] = LAYOUT_split_3x5_3(
        DE_ADIA, DE_U   , DE_O   , DE_M   , DE_Y   ,                   DE_P   , DE_D   , DE_C   , DE_L   , DE_Q   ,
        HRM_S_A, HRM_S_I, HRM_S_E, HRM_S_S, DE_F   ,                   DE_G   , HRM_S_H, HRM_S_T, HRM_S_N, HRM_S_R,
        DE_UDIA, DE_J   , DE_ODIA, DE_W   , DE_V   ,                   DE_Z   , DE_K   , DE_B   , DE_X   , GUI_SS ,
                                   XXXXXXX, OSL_NUM, NAV_SPC, MS_ENT , OSL_SYM, XXXXXXX
    ),

    [NAV] = LAYOUT_split_3x5_3(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, KC_HOME, KC_UP  , KC_END , KC_PGUP,
        KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,                   XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                   _______, _______, _______, _______, _______, _______
    ),

    [MOUSE] = LAYOUT_split_3x5_3(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, MICMUTE, XXXXXXX, XXXXXXX,
        KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,                   TB_DPI , KC_BTN1, KC_BTN2, KC_LCTL, KC_LSFT,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, TB_SCR , XXXXXXX, XXXXXXX, XXXXXXX,
                                   _______, _______, _______, TG_MS_L, _______, _______
    ),

    [NUM_FUNC] = LAYOUT_split_3x5_3(
        KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,                   DE_SLSH, DE_7   , DE_8   , DE_9   , DE_MINS,
        NUM_F6 , NUM_F7 , NUM_F8 , NUM_F9 , KC_F10 ,                   DE_ASTR, NUM_4  , NUM_5  , NUM_6  , NUM_PLS,
        KC_F11 , KC_F12 , XXXXXXX, S_LN_F5, XXXXXXX,                   DE_COMM, DE_1   , DE_2   , DE_3   , DE_DOT ,
                                   _______, _______, _______, DE_0   , MO_ADJ , _______
    ),

    [SYMBOL] = LAYOUT_split_3x5_3(
        DE_EXLM, DE_DEG , DE_SECT, DE_DLR , DE_AMPR,                   XXXXXXX, DE_PIPE, DE_CIRC, DE_TILD, XXXXXXX,
        DE_QUES, DE_LCBR, DE_RCBR, DE_LPRN, DE_RPRN,                   XXXXXXX, NP_XMLL, NP_XMLF, DE_ACUT, DE_GRV ,
        XXXXXXX, DE_LBRC, DE_RBRC, DE_LABK, DE_RABK,                   XXXXXXX, F2_CPLN, IM1_INS, XXXXXXX, KC_PSCR,
                                   _______, MO_ADJ , _______, _______, _______, _______
    ),

    [ADJUST] = LAYOUT_split_3x5_3(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, KC_NUM , XXXXXXX, DF(OPY),   QK_BOOT,
        AU_TOGG, CK_TOGG, CK_DOWN, CK_UP  , CK_RST ,                   XXXXXXX, KC_CAPS, XXXXXXX, DF(SONNE), XXXXXXX,
        AS_TOGG, AS_DOWN, AS_UP  , AS_RPT , XXXXXXX,                   XXXXXXX, KC_SCRL, XXXXXXX, XXXXXXX,   TB_RST ,
                                   _______, _______, _______, _______, _______, _______
    ),
};