#include QMK_KEYBOARD_H
#include "mrsnoot.h"

#define LAYOUT_wrapper(...)            LAYOUT_eg(__VA_ARGS__)
#define LAYOUT_endgame_base( \
    K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, \
    K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, \
    K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, \
                        K31, K32 \
  ) \
  LAYOUT_wrapper( \
  K01    , K02    , K03    , K04    , K05    ,                   K06    , K07    , K08    , K09    , K0A, \
  K11    , K12    , K13    , K14    , K15    ,                   K16    , K17    , K18    , K19    , K1A, \
  K21    , K22    , K23    , K24    , K25    ,                   K26    , K27    , K28    , K29    , K2A, \
                             XXXXXXX, XXXXXXX, K31    , K32    , XXXXXXX, XXXXXXX \
  )
/* Re-pass though to allow templates to be used */
#define LAYOUT_base_wrapper(...)       LAYOUT_endgame_base(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [SONNE] = LAYOUT_base_wrapper(
        _________________SONNE_L1__________________,                   _________________SONNE_R1__________________,
        _________________SONNE_L2__________________,                   _________________SONNE_R2__________________,
        _________________SONNE_L3__________________,                   _________________SONNE_R3__________________,
                                        _____________SONNE_THUMB_BASE______________
    ),

    [NAV] = LAYOUT_base_wrapper(
        __________________NAV_L1___________________,                   __________________NAV_R1___________________,
        __________________NAV_L2___________________,                   __________________NAV_R2___________________,
        __________________NAV_L3___________________,                   __________________NAV_R3___________________,
                                        ______________NAV_THUMB_BASE_______________
    ),

    [MOUSE] = LAYOUT_base_wrapper(
        _________________MOUSE_L1__________________,                   _________________MOUSE_R1__________________,
        _________________MOUSE_L2__________________,                   _________________MOUSE_R2__________________,
        _________________MOUSE_L3__________________,                   _________________MOUSE_R3__________________,
                                        _____________MOUSE_THUMB_BASE______________
    ),

    [NUM_FUNC] = LAYOUT_base_wrapper(
        ________________NUM_FUNC_L1________________,                   ________________NUM_FUNC_R1________________,
        ________________NUM_FUNC_L2________________,                   ________________NUM_FUNC_R2________________,
        ________________NUM_FUNC_L3________________,                   ________________NUM_FUNC_R3________________,
                                        ____________NUM_FUNC_THUMB_BASE____________
    ),

    [SYMBOL] = LAYOUT_base_wrapper(
        _________________SYMBOL_L1_________________,                   _________________SYMBOL_R1_________________,
        _________________SYMBOL_L2_________________,                   _________________SYMBOL_R2_________________,
        _________________SYMBOL_L3_________________,                   _________________SYMBOL_R3_________________,
                                        _____________SYMBOL_THUMB_BASE_____________
    ),

    [ADJUST] = LAYOUT_base_wrapper(
        _________________ADJUST_L1_________________,                   _________________ADJUST_R1_________________,
        _________________ADJUST_L2_________________,                   _________________ADJUST_R2_________________,
        _________________ADJUST_L3_________________,                   _________________ADJUST_R3_________________,
                                        _____________ADJUST_THUMB_BASE_____________
    ),
};

// bool led_update_user(led_t led_state) {

//     return true;
// }