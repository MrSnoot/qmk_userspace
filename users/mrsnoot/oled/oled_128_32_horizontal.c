#include "mrsnoot.h"

#ifdef OLED_ENABLE

static void render_minifig_head_1(void) {
    static const char PROGMEM minifig_head[] = {
        // 'Lego Minifig Kopf Outline', 32x32px, vertical
        0x00, 0x00, 0x00, 0x80, 0xc0, 0x60, 0x60, 0x60, 0x60, 0x7e, 0x63, 0x63, 0x63, 0x63, 0x63, 0x63, 
        0x63, 0x63, 0x63, 0x63, 0x63, 0x63, 0x7e, 0x60, 0x60, 0x60, 0x60, 0xc0, 0x80, 0x00, 0x00, 0x00,
    };

    oled_write_raw_P(minifig_head, sizeof(minifig_head));
}

static void render_minifig_head_2(void) {
    static const char PROGMEM minifig_head[] = {
        // 'Lego Minifig Kopf Outline', 32x32px, vertical
        0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xc0, 0xc0, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0xc0, 0xc0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00,
    };

    oled_write_raw_P(minifig_head, sizeof(minifig_head));
}

static void render_minifig_head_3(void) {
    static const char PROGMEM minifig_head[] = {
        // 'Lego Minifig Kopf Outline', 32x32px, vertical
        0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x31, 0x20, 0x60, 0x40, 0x40, 
        0x40, 0x40, 0x60, 0x20, 0x31, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00,
    };

    oled_write_raw_P(minifig_head, sizeof(minifig_head));
}

static void render_minifig_head_4(void) {
    static const char PROGMEM minifig_head[] = {
        // 'Lego Minifig Kopf Outline', 32x32px, vertical
        0x00, 0x00, 0x03, 0x07, 0x0c, 0x18, 0x10, 0x70, 0xf0, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 
        0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0xf0, 0x70, 0x10, 0x18, 0x0c, 0x07, 0x03, 0x00, 0x00,
    };

    oled_write_raw_P(minifig_head, sizeof(minifig_head));
}

void render_keylock_status(void) {
    led_t led_state = host_keyboard_led_state();
    bool caps_state = (led_state.caps_lock || is_caps_word_on());
    oled_write(PSTR("CAPS"), caps_state);
    oled_write(PSTR(" "), false);
    oled_write(PSTR("NUM"), led_state.num_lock);
    oled_write(PSTR(" "), false);
    oled_write(PSTR("SCRL"), led_state.scroll_lock);
}

void render_mod_status(void) {
    uint8_t mod_state = (get_mods()|get_oneshot_mods());
    oled_write(PSTR("SH"), (mod_state & MOD_MASK_SHIFT));
    oled_write(PSTR(" "), false);
    oled_write(PSTR("CT"), (mod_state & MOD_MASK_CTRL));
    oled_write(PSTR(" "), false);
    oled_write(PSTR("ALT"), (mod_state & MOD_MASK_ALT));
    oled_write(PSTR(" "), false);
    oled_write(PSTR("GUI"), (mod_state & MOD_MASK_GUI));
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
            oled_write(PSTR("UNKNOWN"), false);
    }
}

void render_current_wpm(void){
    oled_write_P(PSTR("WPM: "), false);
    oled_write(get_u8_str(get_current_wpm(), '0'), false);
}

bool oled_task_user(void) {
    oled_set_cursor(1,0);
    render_minifig_head_1();
    oled_set_cursor(8,0);
    render_keylock_status();
    oled_set_cursor(1,1);
    render_minifig_head_2();
    oled_set_cursor(8,1);
    render_mod_status();
    oled_set_cursor(1,2);
    render_minifig_head_3();
    oled_set_cursor(8,2);
    render_current_layer();
    oled_set_cursor(1,3);
    render_minifig_head_4();
    oled_set_cursor(8,3);
    render_current_wpm();

    return false;
}
#endif