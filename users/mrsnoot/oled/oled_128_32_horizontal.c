#include "mrsnoot.h"

#ifdef OLED_ENABLE
#include "os_detection.h"

bool clear_screen = false;
bool rerender_platform = false;
os_variant_t current_platform;

static void render_logo(void) {
    static const char PROGMEM logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
    };

    oled_write(logo, false);
}

void render_keylock_status(led_t led_state) {
    bool caps_state = (led_state.caps_lock || is_caps_word_on());
    oled_write(PSTR("CAPS"), caps_state);
    oled_write(PSTR(" "), false);
    oled_write(PSTR("NUM"), led_state.num_lock);
    oled_write(PSTR(" "), false);
    oled_write(PSTR("SCRL"), led_state.scroll_lock);
    //oled_write_ln_P(PSTR(" "), false);
}

void render_mod_status(uint8_t modifiers) {
    oled_write(PSTR("SH"), (modifiers & MOD_MASK_SHIFT));
    oled_write(PSTR(" "), false);
    (current_platform == OS_MACOS || current_platform == OS_IOS)  ? oled_write(PSTR("CMD"), (modifiers & MOD_MASK_GUI)) : oled_write(PSTR("CT"), (modifiers & MOD_MASK_CTRL));
    oled_write(PSTR(" "), false);
    (current_platform == OS_MACOS || current_platform == OS_IOS) ? oled_write(PSTR("OPT"), (modifiers & MOD_MASK_ALT)) : oled_write(PSTR("ALT"), (modifiers & MOD_MASK_ALT));
    oled_write(PSTR(" "), false);
    (current_platform == OS_MACOS || current_platform == OS_IOS) ? oled_write(PSTR("CT"), (modifiers & MOD_MASK_CTRL)) : oled_write(PSTR("GUI"), (modifiers & MOD_MASK_GUI));
}

void render_key_status_or_logo(void) {
    led_t led_state = host_keyboard_led_state();
    uint8_t mod_state = (get_mods()|get_oneshot_mods());
    if ( !led_state.num_lock && !led_state.caps_lock && !led_state.scroll_lock
    && !(mod_state & MOD_MASK_SHIFT) && !(mod_state & MOD_MASK_ALT) && !(mod_state & MOD_MASK_CTRL) && !(mod_state & MOD_MASK_GUI)) {
        if(!clear_screen) {
            render_logo();
            rerender_platform = true;
        }
        clear_screen = true;
    } else {
        if (clear_screen == true) {
            oled_clear();
            oled_render();
            clear_screen = false;
        }
        oled_set_cursor(8,0);
        render_keylock_status(led_state);
        oled_set_cursor(8,1);
        render_mod_status(mod_state);
        rerender_platform = true;
    }

}

void render_current_layer(void){
    switch (get_highest_layer(layer_state)) {
            case SONNE:
                oled_write(PSTR("SONNE  "), false);
                break;
            case NAV:
                oled_write(PSTR("NAV    "), false);
                break;
            case MOUSE:
                oled_write(PSTR("MOUSE  "), false);
                break;
            case NUM_FUNC:
                oled_write(PSTR("NUM_FKT"), false);
                break;
            case SYMBOL:
                oled_write(PSTR("SYMBOL "), false);
                break;
            case ADJUST:
                oled_write(PSTR("ADJUST "), false);
                break;
            default:
                oled_write(PSTR("UNKNOWN"), false);    // Should never display, here as a catchall
    }
}

void render_current_wpm(void){
    oled_write_P(PSTR("WPM: "), false);
    oled_write(get_u8_str(get_current_wpm(), '0'), false);
}

void render_platform_status(int col, int line) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][5][3] = {
        {{0x9B, 0x9C, 0}, {0xbb, 0xbc, 0}}, //Android
        {{0x99, 0x9A, 0}, {0xb9, 0xba, 0}}, //Linux
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}}, //Windows
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}}, //Mac/iOS
        {{0x9D, 0x9E, 0}, {0xbd, 0xbe, 0}}, //Empty Placeholder
    };
    current_platform = detected_host_os();
    switch (current_platform) {
        case OS_LINUX: //Linux
            oled_set_cursor(col,line);
            oled_write(logo[1][0], false);
            oled_set_cursor(col,line+1);
            oled_write(logo[1][1], false);
            keymap_config.swap_lctl_lgui = false;
            keymap_config.swap_rctl_rgui = false;
            break;
        case OS_WINDOWS: //Windows
            oled_set_cursor(col,line);
            oled_write(logo[2][0], false);
            oled_set_cursor(col,line+1);
            oled_write(logo[2][1], false);
            keymap_config.swap_lctl_lgui = false;
            keymap_config.swap_rctl_rgui = false;
            break;
        case OS_MACOS: //Mac
            oled_set_cursor(col,line);
            oled_write(logo[3][0], false);
            oled_set_cursor(col,line+1);
            oled_write(logo[3][1], false);
            keymap_config.swap_lctl_lgui = true;
            keymap_config.swap_rctl_rgui = true;
            break;
        case OS_IOS: //iOS
            oled_set_cursor(col,line);
            oled_write(logo[3][0], false);
            oled_set_cursor(col,line+1);
            oled_write(logo[3][1], false);
            keymap_config.swap_lctl_lgui = true;
            keymap_config.swap_rctl_rgui = true;
            break;
        default: //OS_UNSURE or not configured
            oled_set_cursor(col,line);
            oled_write(logo[4][0], false);
            oled_set_cursor(col,line+1);
            oled_write(logo[4][1], false);
            break;
    }
    rerender_platform = false;
}

bool oled_task_user(void) {
    render_key_status_or_logo();
    oled_set_cursor(8,2);
    render_current_layer();
    #ifdef DYNAMIC_MACRO_ENABLE
        render_dynamic_macro_status(18,2);
    #endif
    oled_set_cursor(8,3);
    render_current_wpm();
    #ifdef OS_DETECTION_ENABLE
        if(current_platform != detected_host_os() || rerender_platform) { render_platform_status(3,0); }
    #endif

    return false;
}
#endif