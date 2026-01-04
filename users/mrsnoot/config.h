#pragma once

//#ifndef __ASSEMBLER__
//#   include "layout.h"
//#endif

// Allgemein ----------------------------------------------
#define LAYER_STATE_8BIT

// Audio Feature ------------------------------------------
#ifdef AUDIO_ENABLE
#   define AUDIO_ENABLE_TONE_MULTIPLEXING
#   define AUDIO_TONE_MULTIPLEXING_RATE_DEFAULT 10
#   define AUDIO_CLICKY
#   define AUDIO_CLICKY_FREQ_MIN 100.0f
#   define AUDIO_CLICKY_FREQ_RANDOMNESS 1.0f
#   undef  AUDIO_INIT_DELAY
#   define AUDIO_INIT_DELAY 1000
#   define STARTUP_SONG SONG(STARTUP_SOUND)
#endif

// Combo Feature ------------------------------------------
#ifdef COMBO_ENABLE
#   undef  TAPPING_TERM
#   define TAPPING_TERM 190
#   define TAPPING_FORCE_HOLD_PER_KEY
#   define TAPPING_TOGGLE 1
#   define ONESHOT_TAP_TOGGLE 3
#   define ONESHOT_TIMEOUT 3000
#   define COMBO_SHOULD_TRIGGER
#endif

// OLED Feature -------------------------------------------
#ifdef OLED_ENABLE
#   if defined(KEYBOARD_3x3macropad)
#       define OLED_SCROLL_TIMEOUT 0
#   else
#       define OLED_SCROLL_TIMEOUT 10000
#   endif
#endif

// RGB Matrix Feature -------------------------------------
#ifdef RGB_MATRIX_ENABLE
#   define RGB_MATRIX_TIMEOUT 30000
#   define RGB_DISABLE_WHEN_USB_SUSPENDED
#endif

// WPM Feature --------------------------------------------
#ifdef WPM_ENABLE
#   define WPM_SAMPLE_SECONDS 10
#   define WPM_SAMPLE_PERIODS 50
//#   define WPM_ESTIMATED_WORD_SIZE 5
#endif

// Auto Shift Feature -------------------------------------
#ifdef AUTO_SHIFT_ENABLE
#   define AUTO_SHIFT_TIMEOUT 135
#   define AUTO_SHIFT_REPEAT
#   define RETRO_SHIFT 400
#endif

// 3x3 Macropad -------------------------------------------
#if defined(KEYBOARD_3x3macropad)
#   define CS_INCLUDE_BASIS_LAYER
#   define CS_INCLUDE_ADJUST_LAYER
#   define CS_INCLUDE_FUN_LAYER
#   ifdef RGBLIGHT_ENABLE
#       define RGBLIGHT_LIMIT_VAL 150
#       define RGBLIGHT_SLEEP
#       define RGBLIGHT_HUE_STEP 8
#       define RGBLIGHT_SAT_STEP 8
#       define RGBLIGHT_VAL_STEP 8
#       define RGBLIGHT_EFFECT_BREATHING
#       define RGBLIGHT_EFFECT_CHRISTMAS
#       define RGBLIGHT_EFFECT_KNIGHT
#       define RGBLIGHT_EFFECT_RAINBOW_MOOD
#       define RGBLIGHT_EFFECT_RAINBOW_SWIRL
#       define RGBLIGHT_EFFECT_SNAKE
#       define RGBLIGHT_EFFECT_STATIC_GRADIENT
#       define RGBLIGHT_EFFECT_TWINKLE
// #       define RGBLIGHT_TIMEOUT 30000
#   endif
#   ifdef ENCODER_ENABLE
#       define ENCODER_RESOLUTION 4
#   endif
#endif

// Dasbob -------------------------------------------------
#if defined(KEYBOARD_dasbob)
#   define CS_INCLUDE_SONNE_LAYER
#   define CS_INCLUDE_NAV_LAYER
#   define CS_INCLUDE_MOUSE_LAYER
#   define CS_INCLUDE_NUM_FUNC_LAYER
#   define CS_INCLUDE_SYMBOL_LAYER
#   define CS_INCLUDE_ADJUST_LAYER
#   define CS_USE_HRM
#   define CS_USE_TWO_THUMB_DEFAULT
#   define CS_USE_CUSTOM_FUNCTIONS
#   define CS_IS_KB_TO_TB_SENDER
    // Frood Bootloader ueber Doppeltap auf Resetknopf
#   define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#   define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 500U
#   define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_LED 17U
#endif

// Endgame ------------------------------------------------
#if defined(KEYBOARD_endgame_rev6)
#   define CS_INCLUDE_SONNE_LAYER
#   define CS_INCLUDE_NAV_LAYER
#   define CS_INCLUDE_MOUSE_LAYER
#   define CS_INCLUDE_NUM_FUNC_LAYER
#   define CS_INCLUDE_SYMBOL_LAYER
#   define CS_INCLUDE_ADJUST_LAYER
#   define CS_USE_HRM
#   define CS_USE_TWO_THUMB_DEFAULT
#   define CS_USE_CUSTOM_FUNCTIONS
#   define CS_IS_TB_TO_KB_RECEIVER
#   define CS_IS_KB_TO_TB_SENDER

#   ifdef RGB_MATRIX_ENABLE
#      define RGB_MATRIX_MAXIMUM_BRIGHTNESS 100
#      undef ENABLE_RGB_MATRIX_BREATHING
#      undef ENABLE_RGB_MATRIX_CYCLE_ALL
#      undef ENABLE_RGB_MATRIX_PIXEL_RAIN
#      undef ENABLE_RGB_MATRIX_TYPING_HEATMAP
#   endif
#endif

// HMKB EON40 ---------------------------------------------
#if defined(KEYBOARD_evyd13_eon40)
#   define CS_INCLUDE_SONNE_LAYER
#   define CS_INCLUDE_NAV_LAYER
#   define CS_INCLUDE_MOUSE_LAYER
#   define CS_INCLUDE_NUM_FUNC_LAYER
#   define CS_INCLUDE_SYMBOL_LAYER
#   define CS_INCLUDE_ADJUST_LAYER
#   define CS_USE_HRM
#   define CS_USE_TWO_THUMB_DEFAULT
#   define CS_USE_CUSTOM_FUNCTIONS
#   define CS_IS_KB_TO_TB_SENDER
#endif

// re_gret ------------------------------------------------
#if defined(KEYBOARD_fidrildi_v4)
#   define CS_INCLUDE_SONNE_LAYER
#   define CS_INCLUDE_NAV_LAYER
#   define CS_INCLUDE_MOUSE_LAYER
#   define CS_INCLUDE_NUM_FUNC_LAYER
#   define CS_INCLUDE_SYMBOL_LAYER
#   define CS_INCLUDE_ADJUST_LAYER
#   define CS_USE_HRM
#   define CS_USE_TWO_THUMB_DEFAULT
#   define CS_USE_CUSTOM_FUNCTIONS
#   define CS_IS_TB_TO_KB_RECEIVER
#   define CS_IS_KB_TO_TB_SENDER

#   ifdef RGB_MATRIX_ENABLE
#      define RGB_MATRIX_MAXIMUM_BRIGHTNESS 100
#      undef ENABLE_RGB_MATRIX_BREATHING
#      undef ENABLE_RGB_MATRIX_CYCLE_ALL
#      undef ENABLE_RGB_MATRIX_PIXEL_RAIN
#      undef ENABLE_RGB_MATRIX_TYPING_HEATMAP
#   endif
#endif

// KPRepublic BM60 HSRGB ---------------------------------------------
#if defined(KEYBOARD_kprepublic_bm60hsrgb_iso_rev1)
#   define CS_INCLUDE_QWERTY_LAYER
#   define CS_INCLUDE_NAV_FUNC_LAYER
#endif

// Ploopy Adept -------------------------------------------
#if defined(KEYBOARD_ploopyco_madromys_rev1_001)
#   define CS_USE_CUSTOM_FUNCTIONS
#    undef PLOOPY_DPI_DEFAULT
#    define PLOOPY_DPI_DEFAULT 2
// #    undef PLOOPY_DRAGSCROLL_INVERT
// #    define PLOOPY_DRAGSCROLL_INVERT 0
// #    undef PLOOPY_DRAGSCROLL_MOMENTARY
// #    define PLOOPY_DRAGSCROLL_MOMENTARY 0
#    ifdef AUDIO_ENABLE
#        define AUDIO_PIN GP12
#        define AUDIO_PWM_DRIVER PWMD6
#        define AUDIO_PWM_CHANNEL RP2040_PWM_CHANNEL_A
#    endif
#endif

// Ploopy Adept -------------------------------------------
#if defined(KEYBOARD_ploopyco_trackball_nano_rev1_001)
// #   undef PLOOPY_DPI_OPTIONS
#   define PLOOPY_DPI_OPTIONS { 500, 1000, 1375 }
// #   undef PLOOPY_DPI_DEFAULT
#   define PLOOPY_DPI_DEFAULT 2
#endif

// re_gret ------------------------------------------------
#if defined(KEYBOARD_re_gret)
#   define CS_INCLUDE_SONNE_LAYER
#   define CS_INCLUDE_NAV_LAYER
#   define CS_INCLUDE_MOUSE_LAYER
#   define CS_INCLUDE_NUM_FUNC_LAYER
#   define CS_INCLUDE_SYMBOL_LAYER
#   define CS_INCLUDE_ADJUST_LAYER
#   define CS_USE_HRM
#   define CS_USE_TWO_THUMB_DEFAULT
#   define CS_USE_CUSTOM_FUNCTIONS
#   define CS_IS_TB_TO_KB_RECEIVER
#   define CS_IS_KB_TO_TB_SENDER

#   ifdef AUDIO_ENABLE
#       define AUDIO_PIN GP1
#       define AUDIO_PWM_DRIVER PWMD0
#       define AUDIO_PWM_CHANNEL RP2040_PWM_CHANNEL_B
#   endif

#   ifdef RGB_MATRIX_ENABLE
#      define RGB_MATRIX_MAXIMUM_BRIGHTNESS 100
#      undef ENABLE_RGB_MATRIX_BREATHING
#      undef ENABLE_RGB_MATRIX_CYCLE_ALL
#      undef ENABLE_RGB_MATRIX_PIXEL_RAIN
#      undef ENABLE_RGB_MATRIX_TYPING_HEATMAP
#   endif
#endif

// Splitkb Aurora Corne -------------------------------------------
#if defined(KEYBOARD_splitkb_aurora_corne_rev1)
#   define CS_INCLUDE_SONNE_LAYER
#   define CS_INCLUDE_NAV_LAYER
#   define CS_INCLUDE_MOUSE_LAYER
#   define CS_INCLUDE_NUM_FUNC_LAYER
#   define CS_INCLUDE_SYMBOL_LAYER
#   define CS_INCLUDE_ADJUST_LAYER
#   define CS_USE_HRM
#   define CS_USE_TWO_THUMB_DEFAULT
#   define CS_USE_CUSTOM_FUNCTIONS
#   define CS_IS_KB_TO_TB_SENDER

#   ifdef CONVERT_TO_HELIOS
#       ifdef AUDIO_ENABLE
#           define AUDIO_PIN 11U
#           define AUDIO_PWM_DRIVER PWMD5
#           define AUDIO_PWM_CHANNEL RP2040_PWM_CHANNEL_B
#       endif
#   endif
#   ifdef ENCODER_ENABLE
#       define ENCODER_RESOLUTION 2
#   endif
#   ifdef RGB_MATRIX_ENABLE
#       define SPLIT_LAYER_STATE_ENABLE
#   endif
#   ifdef WPM_ENABLE
#       define SPLIT_WPM_ENABLE
#   endif
#endif

// Alias Keycodes -----------------------------------------
#define MO_ADJ MO(ADJUST)
#define NP_XMLL MEH(DE_L)
#define NP_XMLF MEH(DE_B)
#define GUI_SS LGUI_T(DE_SS)
#define MICMUTE C(S(KC_M))

#ifdef CS_USE_TWO_THUMB_DEFAULT
#  define NUM_SPC LT(NUM_FUNC, KC_SPC)
#  define SYM_ENT LT(SYMBOL, KC_ENT)
#  define TG_MS_L TG(MOUSE)
#endif

#ifdef CS_USE_FOUR_THUMB_DEFAULT
#  define OSL_NUM OSL(NUM_FUNC)
#  define NAV_SPC LT(NAV, KC_SPC)
#  define MS_ENT LT(MOUSE, KC_ENT)
#  define OSL_SYM OSL(SYMBOL)
#  define TG_MS_L TG(MOUSE)
#endif

#ifdef CS_USE_HRM
#  define NUM_F6 RSFT_T(KC_F6)
#  define NUM_F7 LALT_T(KC_F7)
#  define NUM_F8 LCTL_T(KC_F8)
#  define NUM_F9 LGUI_T(KC_F9)

#  define NUM_4 LGUI_T(DE_4)
#  define NUM_5 LCTL_T(DE_5)
#  define NUM_6 LALT_T(DE_6)
#  define NUM_PLS RSFT_T(DE_PLUS)

#  ifdef CS_INCLUDE_QWERTY_LAYER
#    define HRM_Q_A LSFT_T(DE_A)
#    define HRM_Q_S LALT_T(DE_S)
#    define HRM_Q_D LCTL_T(DE_D)
#    define HRM_Q_F DE_F
#    define HRM_Q_J DE_J
#    define HRM_Q_K LCTL_T(DE_K)
#    define HRM_Q_L LALT_T(DE_L)
#    define HRM_QOE RSFT_T(DE_ODIA)
#  endif

#  ifdef CS_INCLUDE_SONNE_LAYER
#    define HRM_S_A LSFT_T(DE_A)
#    define HRM_S_I LALT_T(DE_I)
#    define HRM_S_E LCTL_T(DE_E)
#    define HRM_S_S LT(NAV, DE_S)
#    define HRM_S_H LT(MOUSE, DE_H)
#    define HRM_S_T LCTL_T(DE_T)
#    define HRM_S_N LALT_T(DE_N)
#    define HRM_S_R RSFT_T(DE_R)
#  endif
#endif