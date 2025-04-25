#pragma once

#include "quantum.h"
#include "keymap_german.h"

// NUM_WORD Feature ---------------------------------------
#ifdef CS_NUM_WORD_ENABLE
#    include "num_word/num_word.h"
#endif

// Combo Feature ------------------------------------------
#if defined(COMBO_ENABLE)
#   include "combo/combo.h"
#endif

// Encoder Feature ----------------------------------------
#if defined(ENCODER_ENABLE)
#   if defined(KEYBOARD_3x3macropad)
#       include "encoder/encoder_3x3macropad.h"
#   else
#       include "encoder/encoder_split.h"
#   endif
#endif

// OLED Feature -------------------------------------------
#if defined(OLED_ENABLE)
#   if defined(KEYBOARD_3x3macropad)
#       include "oled/oled_128_32_3x3macropad.h"
#   elif defined(OLED_DISPLAY_128X32) && defined(SPLIT_OLED_ENABLE)
#       include "oled/oled_128_32_split.h"
#   elif defined(OLED_DISPLAY_128X64) && defined(SPLIT_OLED_ENABLE)
#       include "oled/oled_128_64_split.h"
#   endif
#endif

// RGB Light Feature --------------------------------------
#if defined(RGBLIGHT_ENABLE)
#   include "rgb/rgb_light.h"
#endif

// RGB Matrix Feature -------------------------------------
#if defined(RGB_MATRIX_ENABLE)
#   if defined(KEYBOARD_endgame_rev6)
#       include "rgb/rgb_matrix_endgame.h"
#   elif defined(KEYBOARD_splitkb_aurora_corne_rev1) || defined(KEYBOARD_splitkb_aurora_helix_rev1)
#       include "rgb/rgb_matrix.h"
#   endif
#endif

// RAW Feature --------------------------------------------
#ifdef RAW_ENABLE
void raw_hid_send_trigger(void);
#endif

// Layer -------------------------------------------------- 
enum layers {
#ifdef CS_INCLUDE_BASIS_LAYER
    BASIS,
#endif

#ifdef CS_INCLUDE_QWERTY_LAYER
    QWERTY,
#endif

#ifdef CS_INCLUDE_SONNE_LAYER
    SONNE,
#endif

#ifdef CS_INCLUDE_NAV_LAYER
    NAV,
#endif

#ifdef CS_INCLUDE_MOUSE_LAYER
    MOUSE,
#endif

#ifdef CS_INCLUDE_NAV_FUNC_LAYER
    NAV_FUNC,
#endif

#ifdef CS_INCLUDE_NUM_FUNC_LAYER
    NUM_FUNC,
#endif

#ifdef CS_INCLUDE_SYMBOL_LAYER
    SYMBOL,
#endif

#ifdef CS_INCLUDE_ADJUST_LAYER
    ADJUST,
#endif

#ifdef CS_INCLUDE_FUN_LAYER
    FUN,
#endif
    _LAYER_SAFE_RANGE
};

// Aurora Corne / Aurora Helix ----------------------------
#if defined(KEYBOARD_splitkb_aurora_corne_rev1) || defined(KEYBOARD_splitkb_aurora_helix_rev1)
#   ifdef ENCODER_ENABLE
enum encoder {
    BOTTOM_LEFT = 0,
    BOTTOM_RIGHT = 1    
};
#   endif
#endif

// Custom Functions ---------------------------------------
#ifdef CS_USE_CUSTOM_FUNCTIONS
void cs_mouse_wheel_up(void);
void cs_mouse_wheel_down(void);
void cs_mouse_wheel_up_accelerated(void);
void cs_mouse_wheel_down_accelerated(void);
void cs_cursor_left(void);
void cs_cursor_right(void);
void cs_virtual_desktop_previous(void);
void cs_virtual_desktop_next(void);
void cs_task_previous(void);
void cs_task_next(void);

// Custom Keycodes ----------------------------------------
enum custom_keycodes {
    CP_ALL = SAFE_RANGE,
    CP_LINE,
    CP_WORD,
    CS_CSRL,
    CS_CSRR,
    CS_VDPR,
    CS_VDNX,
    CS_TSPR,
    CS_TSNX,
    DBL_CLK,
    TB_SCR,
    TB_DPI,
    TB_RST,
    S_LN_F5,
    F2_CPLN,
    IM1_INS,
#ifdef CS_NUM_WORD_ENABLE
    NUMWORD,
#endif
    MS_BN13
};
#endif