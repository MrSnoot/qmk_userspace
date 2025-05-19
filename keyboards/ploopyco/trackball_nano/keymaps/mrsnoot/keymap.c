/* Copyright 2021 Colin Lam (Ploopy Corporation)
 * Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
 * Copyright 2019 Sunjun Kim
 * Copyright 2019 Hiroyuki Okada
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H
#include "mrsnoot.h"

// Dummy Keymap
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {{{ KC_NO }}};

// void suspend_power_down_user(void) {
//     // Switch off sensor + LED making trackball unable to wake host
//     adns5050_power_down();
// }

// void suspend_wakeup_init_user(void) {
//     adns5050_init();
// }

#ifdef RAW_ENABLE
#include "raw_hid.h"

void raw_hid_receive(uint8_t* data, uint8_t length) {
    // layer_clear();
    // if (data[0] == 99) {
    //     layer_on(_BASE);
    // }
    // else {
    //     layer_on(data[0]);
    // }
	raw_hid_send(data, length);
}
#endif

#define DELTA_X_THRESHOLD 30
#define DELTA_Y_THRESHOLD 15

static int8_t delta_x = 0;
static int8_t delta_y = 0;
static uint8_t scroll_enabled = false;

enum host_led_reference {
	CAPS_LOCK_REF,
	NUM_LOCK_REF,
	SCROLL_LOCK_REF
};

enum trigger_names {
	TOGGLE_SCROLL_TRIGGER,
	CYCLE_DPI_TRIGGER,
	RESET_TRIGGER,
	TRIGGER_LENGTH
};

struct action_trigger_t {
	uint8_t name;
	uint8_t reference_state;
	uint8_t state;
	uint8_t timer_min;
	uint8_t timer_max;
	uint8_t trigger_count;
	uint8_t current_count;
	uint16_t timer;
};

struct action_trigger_t action_trigger[TRIGGER_LENGTH];

report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    if (scroll_enabled) {
        delta_x += mouse_report.x;
        delta_y += mouse_report.y;

        if (delta_x > DELTA_X_THRESHOLD) {
            mouse_report.h = -1;
            delta_x        = 0;
        } else if (delta_x < -DELTA_X_THRESHOLD) {
            mouse_report.h = 1;
            delta_x        = 0;
        }

        if (delta_y > DELTA_Y_THRESHOLD) {
            mouse_report.v = 1;
            delta_y        = 0;
        } else if (delta_y < -DELTA_Y_THRESHOLD) {
            mouse_report.v = -1;
            delta_y        = 0;
        }
        mouse_report.x = 0;
        mouse_report.y = 0;
    }
    return mouse_report;
}

void set_led_state_to_trigger(struct action_trigger_t *trigger, led_t led_state) {
	switch (trigger->reference_state) {
		case CAPS_LOCK_REF:
			trigger->state = led_state.caps_lock;
			break;
		case NUM_LOCK_REF:
			trigger->state = led_state.num_lock;
			break;
		case SCROLL_LOCK_REF:
			trigger->state = led_state.scroll_lock;
			break;
	}
}

void keyboard_post_init_user(void) {
	struct action_trigger_t toggle_scroll_trigger = { TOGGLE_SCROLL_TRIGGER, SCROLL_LOCK_REF, 0, 0, 35, 2, 0, 0 };
	struct action_trigger_t cycle_dpi_trigger = { CYCLE_DPI_TRIGGER, NUM_LOCK_REF, 0, 0, 35, 2, 0, 0 };
	struct action_trigger_t reset_trigger = { RESET_TRIGGER, CAPS_LOCK_REF, 0, 0, 35, 2, 0, 0 };
	action_trigger[TOGGLE_SCROLL_TRIGGER] = toggle_scroll_trigger;
	action_trigger[CYCLE_DPI_TRIGGER] = cycle_dpi_trigger;
	action_trigger[RESET_TRIGGER] = reset_trigger;

	led_t led_state = host_keyboard_led_state();
	int i;

	for (i = 0; i < TRIGGER_LENGTH; i++) {
		set_led_state_to_trigger(&action_trigger[i], led_state);
	}
	
	//debug_enable=true;
	//debug_matrix=true;
	//debug_keyboard=true;
	//debug_mouse=true;
}
void toggle_scroll(void) {
	scroll_enabled = !scroll_enabled;
}

bool has_trigger_state_led_state(struct action_trigger_t *trigger, led_t led_state) {
	bool state_is_matching = false;

	switch (trigger->reference_state) {
		case CAPS_LOCK_REF:
			state_is_matching = (trigger->state == led_state.caps_lock);
			break;
		case NUM_LOCK_REF:
			state_is_matching = (trigger->state == led_state.num_lock);
			break;
		case SCROLL_LOCK_REF:
			state_is_matching = (trigger->state == led_state.scroll_lock);
			break;
	}

	return state_is_matching;
}

void do_trigger_action(struct action_trigger_t *trigger) {
	switch(trigger->name) {
		case TOGGLE_SCROLL_TRIGGER:
			//toggle_drag_scroll();
			toggle_scroll();
			break;
		case CYCLE_DPI_TRIGGER:
			cycle_dpi();
			break;
		case RESET_TRIGGER:
			reset_keyboard();
			break;
	}
}

void update_trigger(struct action_trigger_t *trigger, led_t led_state) {
	if (timer_elapsed(trigger->timer) < trigger->timer_min || timer_elapsed(trigger->timer) > trigger->timer_max) {
		trigger->timer = timer_read();
		trigger->current_count = 0;
	}

	if (!has_trigger_state_led_state(trigger, led_state)) {
		trigger->current_count++;

		if (trigger->current_count == trigger->trigger_count) {
			do_trigger_action(trigger);
			trigger->current_count = 0;
		}
	}

	set_led_state_to_trigger(trigger, led_state);
}

void update_trigger_list(led_t led_state) {
	int i;
	for(i = 0; i < TRIGGER_LENGTH; i++) {
		update_trigger(&action_trigger[i], led_state);
	}
}

bool led_update_user(led_t led_state) {
	update_trigger_list(led_state);
	return true;
}