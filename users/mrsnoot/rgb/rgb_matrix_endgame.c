#include "mrsnoot.h"

#ifdef RGB_MATRIX_ENABLE

uint16_t lock_led_timer = 0;
static led_t current_led_state;
typedef enum {
    NONE,
    ENTER_ADJUST,
    NUM,
    CAPS,
    SCROLL,
} latest_event_t;

latest_event_t last_event = NONE;

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {

    uint8_t layer = biton32(layer_state);

    if (layer < ADJUST)
    {
        last_event = NONE;
    }

    switch (layer) {
        case SONNE:
            rgb_matrix_set_color_all(RGB_TURQUOISE);
            break;
        case NAV:
            rgb_matrix_set_color_all(RGB_ORANGE);
            break;
        case MOUSE:
            rgb_matrix_set_color_all(RGB_PURPLE);
            break;
        case NUM_FUNC:
            rgb_matrix_set_color_all(RGB_YELLOW);
            break;
        case SYMBOL:
            rgb_matrix_set_color_all(RGB_GREEN);
            break;
        case ADJUST:
            if (last_event == NUM && timer_elapsed(lock_led_timer) <= 2000)
            {
                current_led_state.num_lock ? rgb_matrix_set_color_all(RGB_GREEN) : rgb_matrix_set_color_all(RGB_RED);
            }
            else if (last_event == CAPS && timer_elapsed(lock_led_timer) <= 2000)
            {
                current_led_state.caps_lock ? rgb_matrix_set_color_all(RGB_GREEN) : rgb_matrix_set_color_all(RGB_RED);
            }
            else if (last_event == SCROLL && timer_elapsed(lock_led_timer) <= 2000)
            {
                current_led_state.scroll_lock ? rgb_matrix_set_color_all(RGB_GREEN) : rgb_matrix_set_color_all(RGB_RED);
            }
            else
            {
                last_event = NONE;
                rgb_matrix_set_color_all(RGB_BLUE);
            }
    
            break;
    }

    return false;
}

bool led_update_user(led_t led_state) {
    
    if (led_state.num_lock != current_led_state.num_lock) { last_event = NUM; }
    if (led_state.caps_lock != current_led_state.caps_lock) { last_event = CAPS; }
    if (led_state.scroll_lock != current_led_state.scroll_lock) { last_event = SCROLL; }

    lock_led_timer = timer_read();
    current_led_state = led_state;

    return true;
}

#endif