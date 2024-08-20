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

// Caps Word Feature --------------------------------------
// #ifdef CAPS_WORD_ENABLE
// #   define BOTH_SHIFTS_TURNS_ON_CAPS_WORD
// #endif

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

// Dasbob ------------------------------------------------
#if defined(KEYBOARD_dasbob)
#   define HAS_OPY_LAYER
#   define USE_HRM
#   define USE_FOUR_THUMB_DEFAULT

#   define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#   define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 500U
#   define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_LED 17U
#endif

// HMKB EON40 ---------------------------------------------
#if defined(KEYBOARD_evyd13_eon40)
#   define HAS_OPY_LAYER
#   define USE_HRM
#   define USE_FOUR_THUMB_DEFAULT
#endif

// HMKB EON95 ---------------------------------------------
#if defined(KEYBOARD_evyd13_eon95)
#   define HAS_QWERTY_LAYER
#   define USE_HRM
#   define LNAV_SPC LT(NAV, KC_SPC)
#   define LADJ_CPS LT(ADJUST, KC_CAPS)
#endif

// Horizon ------------------------------------------------
#if defined(KEYBOARD_horizon)
#   define HAS_OPY_LAYER
#   define USE_HRM
#   define USE_FOUR_THUMB_DEFAULT

#   ifdef CONVERT_TO_HELIOS
#       ifdef AUDIO_ENABLE
#           define AUDIO_PIN 12U
#           define AUDIO_PWM_DRIVER PWMD6
#           define AUDIO_PWM_CHANNEL RP2040_PWM_CHANNEL_A
#       endif
#   endif
#endif

// KPRepublic BM60 HSRGB ---------------------------------------------
#if defined(KEYBOARD_kprepublic_bm60hsrgb_iso_rev1)
#   define HAS_QWERTY_LAYER
#endif

// Ploopy Adept -------------------------------------------
#if defined(KEYBOARD_ploopyco_madromys_rev1_001)
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

// Splitkb Aurora Corne -------------------------------------------
#if defined(KEYBOARD_splitkb_aurora_corne_rev1)
#   define HAS_OPY_LAYER
#   define USE_HRM
#   define USE_FOUR_THUMB_DEFAULT

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

// Splitkb Aurora Helix -------------------------------------------
#if defined(KEYBOARD_splitkb_aurora_helix_rev1)
#   define HAS_OPY_LAYER
#   define USE_HRM
#   define USE_FOUR_THUMB_DEFAULT

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

#ifdef USE_FOUR_THUMB_DEFAULT
#  define OSL_NUM OSL(NUM_FUNC)
#  define NAV_SPC LT(NAV, KC_SPC)
#  define NAV_ENT LT(NAV, KC_ENT)
#  define OSL_SYM OSL(SYMBOL)
#endif

#ifdef USE_HRM
#  define NUM_F6 RSFT_T(KC_F6)
#  define NUM_F7 LALT_T(KC_F7)
#  define NUM_F8 LCTL_T(KC_F8)
#  define NUM_F9 LGUI_T(KC_F9)

#  define NUM_4 LGUI_T(DE_4)
#  define NUM_5 LCTL_T(DE_5)
#  define NUM_6 LALT_T(DE_6)
#  define NUM_PLS RSFT_T(DE_PLUS)

#  ifdef HAS_QWERTY_LAYER
#    define HRM_Q_A LSFT_T(DE_A)
#    define HRM_Q_S LALT_T(DE_S)
#    define HRM_Q_D LCTL_T(DE_D)
#    define HRM_Q_F DE_F
#    define HRM_Q_J DE_J
#    define HRM_Q_K LCTL_T(DE_K)
#    define HRM_Q_L LALT_T(DE_L)
#    define HRM_QOE RSFT_T(DE_ODIA)
#  endif

#  ifdef HAS_OPY_LAYER
#    define HRM_O_H LSFT_T(DE_H)
#    define HRM_O_A LALT_T(DE_A)
#    define HRM_O_E LCTL_T(DE_E)
#    define HRM_O_I DE_I
#    define HRM_O_T DE_T
#    define HRM_O_N LCTL_T(DE_N)
#    define HRM_O_S LALT_T(DE_S)
#    define HRM_O_R RSFT_T(DE_R)
#  endif
#endif