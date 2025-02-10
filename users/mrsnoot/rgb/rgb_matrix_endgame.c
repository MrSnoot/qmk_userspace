#include "mrsnoot.h"

#ifdef RGB_MATRIX_ENABLE

enum colors {
    LILAC = 0,
    ICEBLUE,
    GREEN,
    YELLOW,
    RED,
    ORANGE
};

uint8_t color_values[6][3] = {
    { 10, 0, 50 },  // Lila
    { 0, 40, 50 },  // Eisblau
    { 10, 50, 2 },  // Grün
    { 50, 40, 0 },  // Gelb
    { 50, 0, 0 },   // Rot
    { 50, 15.6, 0 } // Orange
};

void set_color(uint8_t led_index, uint8_t color)
{
    rgb_matrix_set_color(led_index, color_values[color][0], color_values[color][1], color_values[color][2]);
}

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {

    uint8_t layer = biton32(layer_state);

    switch (layer) {
        case OPY:
            rgb_matrix_set_color_all(RGB_TURQUOISE);
            break;
        case NAV:
            // set_color(RGB_VIOLET);
            rgb_matrix_set_color_all(RGB_PURPLE);
            break;
        case MOUSE:
            // set_color(RGB_ORANGE); 
            rgb_matrix_set_color_all(RGB_ORANGE);
            break;
        case NUM_FUNC:
            // set_color(RGB_YELLOW);
            rgb_matrix_set_color_all(RGB_YELLOW);
            break;
        case SYMBOL:
            // set_color(RGB_GREEN);
            rgb_matrix_set_color_all(RGB_GREEN);
            break;
        case ADJUST:
            // set_color(RGB_RED);
            rgb_matrix_set_color_all(RGB_RED);
            break;
    }

    return false;
}

#endif