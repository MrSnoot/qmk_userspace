#include "mrsnoot.h"

#if defined(RGBLIGHT_ENABLE) && defined(RGBLIGHT_LAYERS)
static uint16_t key_timer; // timer to track the last keyboard activity
static void refresh_rgb(void); // refreshes the activity timer and RGB, invoke whenever activity happens
static void check_rgb_timeout(void); // checks if enough time has passed for RGB to timeout
bool is_rgb_timeout = false; // store if RGB has timed out or not in a boolean

// Rot  HSV_RED
// Gelb HSV_YELLOW
// Grün HSV_CHARTREUSE
// Blau HSV_CYAN
const rgblight_segment_t PROGMEM rgb_qwerty_layer[] = RGBLIGHT_LAYER_SEGMENTS( {0, 20, HSV_CYAN} );
const rgblight_segment_t PROGMEM rgb_nav_layer[] = RGBLIGHT_LAYER_SEGMENTS( {0, 20, HSV_PURPLE} );
const rgblight_segment_t PROGMEM rgb_num_func_layer[] = RGBLIGHT_LAYER_SEGMENTS( {0, 20, HSV_CYAN} );
const rgblight_segment_t PROGMEM rgb_symbol_layer[] = RGBLIGHT_LAYER_SEGMENTS( {0, 20, HSV_CHARTREUSE} );
const rgblight_segment_t PROGMEM rgb_swap_hands_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 2, HSV_ORANGE},
    {18, 2, HSV_ORANGE}
);
const rgblight_segment_t PROGMEM rgb_numlock_indicator[] = RGBLIGHT_LAYER_SEGMENTS( {9, 1, HSV_GREEN} );
const rgblight_segment_t PROGMEM rgb_capslock_indicator[] = RGBLIGHT_LAYER_SEGMENTS( {0, 1, HSV_PURPLE} );
const rgblight_segment_t PROGMEM rgb_scrlock_indicator[] = RGBLIGHT_LAYER_SEGMENTS( {5, 1, HSV_ORANGE} );

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    rgb_nav_layer,
    rgb_num_func_layer,
    rgb_symbol_layer,
    rgb_swap_hands_layer,
    rgb_numlock_indicator,
    rgb_capslock_indicator,
    rgb_scrlock_indicator
);

void keyboard_post_init_user(void) {
  rgblight_layers = my_rgb_layers;
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, QWERTY));
    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(2, layer_state_cmp(state, NAV));
    rgblight_set_layer_state(3, layer_state_cmp(state, NUM_FUNC));
    rgblight_set_layer_state(4, layer_state_cmp(state, SYMBOL));
    return state;
}

bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(6, !led_state.num_lock);
    rgblight_set_layer_state(7, led_state.caps_lock);
    rgblight_set_layer_state(8, led_state.scroll_lock);
    return true;
}

void refresh_rgb() {
  key_timer = timer_read(); // store time of last refresh
  if (is_rgb_timeout) { // only do something if rgb has timed out
    //print("Activity detected, removing timeout\n");
    is_rgb_timeout = false;
    rgblight_wakeup();
  }
}

void check_rgb_timeout() {
  if (!is_rgb_timeout && timer_elapsed(key_timer) > RGBLIGHT_TIMEOUT) {
    rgblight_suspend();
    is_rgb_timeout = true;
  }
}

/* Runs at the end of each scan loop, check if RGB timeout has occured */
void housekeeping_task_user(void) {
  #ifdef RGBLIGHT_TIMEOUT
  check_rgb_timeout();
  #endif
}

void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
  #ifdef RGBLIGHT_TIMEOUT
  if (record->event.pressed) refresh_rgb();
  #endif
  return;
}
#endif