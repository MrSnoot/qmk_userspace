#include "mrsnoot.h"

#ifdef ENCODER_ENABLE

void mouse_wheel_up_down(bool clockwise) {
    if (clockwise) {
        cs_mouse_wheel_down();
    } else {
        cs_mouse_wheel_up();
    }
}

void mouse_wheel_up_down_accelerated(bool clockwise)
{
    mouse_wheel_up_down(clockwise);
    mouse_wheel_up_down(clockwise);
}

void page_up_down(bool clockwise) {
    if (clockwise) {
        cs_page_down();
    } else {
        cs_page_up();
    }
}

void cursor_left_right(bool clockwise) {
    if (clockwise) {
        cs_cursor_right();
    } else {
        cs_cursor_left();
    }
}

void virtual_desktop_previous_next(bool clockwise) {
    if (clockwise) {
        cs_virtual_desktop_next();
    } else {
        cs_virtual_desktop_previous();
    }
}

void task_previous_next(bool clockwise) {
    if (clockwise) {
        cs_task_next();
    } else {
        cs_task_previous();
    }
}

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == BOTTOM_LEFT) {
        switch (get_highest_layer(layer_state)) {
            case NUM_FUNC:
                page_up_down(clockwise);
                break;
            case SYMBOL:
                mouse_wheel_up_down_accelerated(clockwise);
                break;
            default:
                mouse_wheel_up_down(clockwise);
                break;
        }
    } else if (index == BOTTOM_RIGHT) {
        switch (get_highest_layer(layer_state)) {
            case NAV:
                cursor_left_right(clockwise);
                break;
            case SYMBOL:
                task_previous_next(clockwise);
                break;
            default:
                virtual_desktop_previous_next(clockwise);
                break;
        }
    }

    return false;
}
#endif