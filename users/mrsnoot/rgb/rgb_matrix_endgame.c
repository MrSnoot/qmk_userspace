#include "mrsnoot.h"

#ifdef RGB_MATRIX_ENABLE

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {

    uint8_t layer = biton32(layer_state);

    switch (layer) {
        case OPY:
            switch (biton32(default_layer_state))
            {
                case OPY:
                    rgb_matrix_set_color_all(RGB_TURQUOISE);
                    break;
                case SONNE:
                    rgb_matrix_set_color_all(RGB_PURPLE);
            }
            break;
        case NAV:
            rgb_matrix_set_color_all(RGB_ORANGE);
            break;
        case MOUSE:
            rgb_matrix_set_color_all(RGB_BLUE);
            break;
        case NUM_FUNC:
            rgb_matrix_set_color_all(RGB_YELLOW);
            break;
        case SYMBOL:
            rgb_matrix_set_color_all(RGB_GREEN);
            break;
        case ADJUST:
            rgb_matrix_set_color_all(RGB_RED);
            break;
    }

    return false;
}

#endif