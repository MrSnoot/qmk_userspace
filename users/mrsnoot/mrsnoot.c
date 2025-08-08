#include "mrsnoot.h"

// Audio Feature ------------------------------------------
#ifdef AUDIO_ENABLE
float tone_caps_lock_on[][2]    = SONG(CAPS_LOCK_ON_SOUND);
float tone_caps_lock_off[][2]   = SONG(CAPS_LOCK_OFF_SOUND);
float tone_num_lock_on[][2]     = SONG(NUM_LOCK_ON_SOUND);
float tone_num_lock_off[][2]    = SONG(NUM_LOCK_OFF_SOUND);
float tone_scroll_lock_on[][2]  = SONG(SCROLL_LOCK_ON_SOUND);
float tone_scroll_lock_off[][2] = SONG(SCROLL_LOCK_OFF_SOUND);
float tone_startup[][2]         = SONG(STARTUP_SOUND);
// float tone_tb_dpi_value[][2]    = SONG(Q__NOTE(_D5));
#endif

// Custom Functions ---------------------------------------
#ifdef CS_USE_CUSTOM_FUNCTIONS
bool is_alt_tab_active = false;
uint16_t alt_tab_timer = 0;

void cs_mouse_wheel_up(void) {
    tap_code(KC_WH_U);
}

void cs_mouse_wheel_down(void) {
    tap_code(KC_WH_D);
}

void cs_mouse_wheel_up_accelerated(void) {
    cs_mouse_wheel_up();
    cs_mouse_wheel_up();
}

void cs_mouse_wheel_down_accelerated(void) {
    cs_mouse_wheel_down();
    cs_mouse_wheel_down();
}

void cs_cursor_left(void) {
    tap_code(KC_LEFT);
}

void cs_cursor_right(void) {
    tap_code(KC_RIGHT);
}

void cs_virtual_desktop_previous(void) {
    tap_code16(G(C(KC_LEFT)));
    #ifdef AUDIO_ENABLE
    PLAY_SONG(tone_scroll_lock_off);
    #endif
}

void cs_virtual_desktop_next(void) {
    tap_code16(G(C(KC_RIGHT)));
    #ifdef AUDIO_ENABLE
    PLAY_SONG(tone_scroll_lock_on);
    #endif
}

void cs_task_previous(void) {
    if (!is_alt_tab_active) {
        is_alt_tab_active = true;
        register_code(KC_LALT);
    }

    alt_tab_timer = timer_read();

    tap_code16(S(KC_TAB));
    #ifdef AUDIO_ENABLE
    PLAY_SONG(tone_scroll_lock_off);
    #endif
}

void cs_task_next(void) {
    if (!is_alt_tab_active) {
        is_alt_tab_active = true;
        register_code(KC_LALT);
    }

    alt_tab_timer = timer_read();

    tap_code16(KC_TAB);
    #ifdef AUDIO_ENABLE
    PLAY_SONG(tone_scroll_lock_on);
    #endif
}
#endif

// Matrix Scan --------------------------------------------
void matrix_scan_user(void) {
#ifdef CS_USE_CUSTOM_FUNCTIONS
  if (is_alt_tab_active) {
    if (timer_elapsed(alt_tab_timer) > 1000) {
      unregister_code(KC_LALT);
      is_alt_tab_active = false;
    }
  }
#endif
}

// Process Record -----------------------------------------
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_NUM:
            if (record->event.pressed) {
                #ifdef AUDIO_ENABLE
                host_keyboard_led_state().num_lock? PLAY_SONG(tone_num_lock_on) : PLAY_SONG(tone_num_lock_off);
                #endif
            }
            break;
        case KC_CAPS:
            if (record->event.pressed) {
                #ifdef AUDIO_ENABLE
                host_keyboard_led_state().caps_lock? PLAY_SONG(tone_caps_lock_on) : PLAY_SONG(tone_caps_lock_off);
                #endif
            }
            break;
        case KC_SCRL:
            if (record->event.pressed) {
                #ifdef AUDIO_ENABLE
                host_keyboard_led_state().scroll_lock? PLAY_SONG(tone_scroll_lock_on) : PLAY_SONG(tone_scroll_lock_off);
                #endif
            }
            break;
        case KC_BTN1:
        case KC_BTN2:
            #ifdef AUDIO_ENABLE
            if(record->event.pressed) {
                audio_stop_all();
            }
            #endif
            break;
        case KC_ENT:
            #ifdef AUDIO_ENABLE
            if(record->event.pressed) {
                PLAY_SONG(tone_startup);
            }
            #endif
            break;
        case KC_BSPC:
        case LCTL(KC_BSPC):
            #ifdef AUDIO_ENABLE
            if(record->event.pressed) {
                PLAY_SONG(tone_num_lock_off);
            }
            #endif
            break;
        case KC_DEL:
        case LCTL(KC_DEL):
            #ifdef AUDIO_ENABLE
            if(record->event.pressed) {
                PLAY_SONG(tone_scroll_lock_off);
            }
            #endif
            break;
        case LCTL(KC_C):
            #ifdef AUDIO_ENABLE
            if(record->event.pressed) {
                PLAY_SONG(tone_num_lock_on);
            }
            #endif
            break;
        case LCTL(KC_V):
            #ifdef AUDIO_ENABLE
            if(record->event.pressed) {
                PLAY_SONG(tone_num_lock_off);
            }
            #endif
            break;
        case LCTL(KC_X):
            #ifdef AUDIO_ENABLE
            if(record->event.pressed) {
                PLAY_SONG(tone_scroll_lock_on);
            }
            #endif
            break;
#ifdef CS_USE_CUSTOM_FUNCTIONS
        case CP_ALL:
            if (record->event.pressed) {
                tap_code16(LCTL(KC_A));
                tap_code16(LCTL(KC_C));
                #ifdef AUDIO_ENABLE
                PLAY_SONG(tone_caps_lock_on);
                #endif
            }
            break;
        case CP_LINE:
            if (record->event.pressed) {
                tap_code16(KC_HOME);
                tap_code16(LSFT(KC_END));
                tap_code16(LCTL(KC_C));
                #ifdef AUDIO_ENABLE
                PLAY_SONG(tone_num_lock_on);
                #endif
            }
            break;
        case CP_WORD:
            if (record->event.pressed) {
                tap_code16(LCTL(KC_LEFT));
                tap_code16(RCS(KC_RIGHT));
                tap_code16(LCTL(KC_C));
                #ifdef AUDIO_ENABLE
                PLAY_SONG(tone_scroll_lock_on);
                #endif
            }
            break;
        case CS_CSRL:
            if (record->event.pressed) {
                cs_cursor_left();
            }
            break;
        case CS_CSRR:
            if (record->event.pressed) {
                cs_cursor_right();
            }
            break;
        case CS_VDPR:
            if (record->event.pressed) {
                cs_virtual_desktop_previous();
            }
            break;
        case CS_VDNX:
            if (record->event.pressed) {
                cs_virtual_desktop_next();
            }
            break;
        case CS_TSPR:
            if (record->event.pressed) {
                cs_task_previous();
            }
            break;
        case CS_TSNX:
            if (record->event.pressed) {
                cs_task_next();
            }
            break;
        case DBL_CLK:
            if (record->event.pressed) {
                #ifdef AUDIO_ENABLE
                audio_stop_all();
                #endif
                tap_code16(KC_BTN1);
                tap_code16(KC_BTN1);
            }
            break;
        case S_LN_F5:
            if (record->event.pressed) {
                tap_code16(KC_HOME);
                tap_code16(LSFT(KC_END));
                tap_code(KC_F5);
            }
            break;
        case F2_CPLN:
            if (record->event.pressed) {
                #ifdef AUDIO_ENABLE
                PLAY_SONG(tone_num_lock_on);
                #endif
                tap_code(KC_F2);
                tap_code16(KC_HOME);
                tap_code16(LSFT(KC_END));
                tap_code16(LCTL(KC_C));
                tap_code(KC_ESC);
            }
            break;
        case IM1_INS:
            if (record->event.pressed) {
                #ifdef AUDIO_ENABLE
                PLAY_SONG(tone_num_lock_off);
                #endif
                tap_code16(LCTL(KC_A));
                tap_code16(LCTL(KC_V));
                wait_ms(500);
                tap_code16(LALT(KC_F4));
                wait_ms(500);
                tap_code(KC_ENT);
            }
            break;
        case MS_BN13:
            if (record->event.pressed) {
                register_code(KC_BTN3);
                register_code(KC_BTN1);
            }
            else {
                unregister_code(KC_BTN1);
                unregister_code(KC_BTN3);
            }
            break;
#endif
#ifdef CS_IS_KB_TO_TB_SENDER
        case TB_SCR:
            if (record->event.pressed) {
                #ifdef AUDIO_ENABLE
                audio_stop_all();
                #endif
                tap_code(KC_SCRL);
                wait_ms(29);
                tap_code(KC_SCRL);
            }
            break;
        case TB_DPI:
            if (record->event.pressed) {
                tap_code(KC_NUM);
                wait_ms(29);
                tap_code(KC_NUM);
            }
            break;
        case TB_RST:
            if (record->event.pressed) {
                tap_code(KC_CAPS);
                wait_ms(29);
                tap_code(KC_CAPS);
            }
            break;
#endif
    }

#ifdef CS_NUM_WORD_ENABLE
    if (!process_record_num_word(keycode, record)) {
        return false; 
    }
#endif

    return true;
}

// Tapping Feature ----------------------------------------
__attribute__ ((weak))
bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
    return true;
}

// Caps Word Feature --------------------------------------
#ifdef CAPS_WORD_ENABLE
void caps_word_set_user(bool active) {
    if (active) {
        #ifdef AUDIO_ENABLE
        PLAY_SONG(tone_num_lock_on);
        #endif
    } else {
        #ifdef AUDIO_ENABLE
        PLAY_SONG(tone_num_lock_off); 
        #endif
    }
}

__attribute__ ((weak))
bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
        case DE_MINS:
        case DE_ADIA:
        case DE_ODIA:
        case DE_UDIA:
            add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
            return true;

        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
            return true;

        default:
            return false;  // Deactivate Caps Word.
    }
}
#endif

// Auto Shift Feature -------------------------------------
#ifdef AUTO_SHIFT_ENABLE
bool get_auto_shifted_key(uint16_t keycode, keyrecord_t *record) {
    // option 1
    if (IS_RETRO(keycode))
        return true;

    // option 2
    switch (keycode) {
        case AUTO_SHIFT_ALPHA:
        case AUTO_SHIFT_SYMBOLS:
        // case DE_ADIA:
        // case DE_ODIA:
        // case DE_UDIA:
        case KC_TAB:
        case QK_MOD_TAP ... QK_MOD_TAP_MAX:
            return true;
    }

    return get_custom_auto_shifted_key(keycode, record);
}
#endif

// Overriding Methods -------------------------------------
__attribute__ ((weak))
bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
  return true;
}