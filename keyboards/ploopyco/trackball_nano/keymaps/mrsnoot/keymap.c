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

#define DELTA_X_THRESHOLD 30
#define DELTA_Y_THRESHOLD 15

#define NUM_LOCK_BITMASK 0b001
#define CAPS_LOCK_BITMASK 0b010
#define SCROLL_LOCK_BITMASK 0b100

static int8_t delta_x = 0;
static int8_t delta_y = 0;
static uint8_t scroll_enabled = false;
static uint8_t auto_mouse_layer_enabled = false;

typedef enum {
    // You could theoretically define 0b00 and send it by having a macro send
    // the second tap after LED_CMD_TIMEOUT has elapsed.
    // CMD_EXTRA = 0b00,
    TG_SCROLL = 0b001,
    CYC_DPI   = 0b010,
    CMD_RESET = 0b011 // CMD_ prefix to avoid clash with QMK macro
} led_cmd_t;

enum host_led_reference {
	CAPS_LOCK_REF,
	NUM_LOCK_REF,
	SCROLL_LOCK_REF
};

enum kb_to_tb_trigger_names {
	KB_TO_TB_TOGGLE_SCROLL_TRIGGER,
	KB_TO_TB_CYCLE_DPI_TRIGGER,
	KB_TO_TB_RESET_TRIGGER,
	KB_TO_TB_TRIGGER_LENGTH
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

struct action_trigger_t kb_to_tb_trigger[KB_TO_TB_TRIGGER_LENGTH];

void send_auto_mouse_off() {

}

void send_auto_mouse_on() {

}

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

	if (auto_mouse_activation(mouse_report) != auto_mouse_layer_enabled) {
		auto_mouse_layer_enabled = !auto_mouse_layer_enabled;
		auto_mouse_layer_enabled ? send_auto_mouse_on() : send_auto_mouse_off();
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
	struct action_trigger_t kb_to_tb_toggle_scroll_trigger = { KB_TO_TB_TOGGLE_SCROLL_TRIGGER, SCROLL_LOCK_REF, 0, 0, 35, 2, 0, 0 };
	struct action_trigger_t kb_to_tb_cycle_dpi_trigger = { KB_TO_TB_CYCLE_DPI_TRIGGER, NUM_LOCK_REF, 0, 0, 35, 2, 0, 0 };
	struct action_trigger_t kb_to_tb_reset_trigger = { KB_TO_TB_RESET_TRIGGER, CAPS_LOCK_REF, 0, 0, 35, 2, 0, 0 };
	kb_to_tb_trigger[KB_TO_TB_TOGGLE_SCROLL_TRIGGER] = kb_to_tb_toggle_scroll_trigger;
	kb_to_tb_trigger[KB_TO_TB_CYCLE_DPI_TRIGGER] = kb_to_tb_cycle_dpi_trigger;
	kb_to_tb_trigger[KB_TO_TB_RESET_TRIGGER] = kb_to_tb_reset_trigger;

	led_t led_state = host_keyboard_led_state();
	int i;

	for (i = 0; i < KB_TO_TB_TRIGGER_LENGTH; i++) {
		set_led_state_to_trigger(&kb_to_tb_trigger[i], led_state);
	}
	
	// debug_enable=true;
	// debug_matrix=true;
	// debug_keyboard=true;
	// debug_mouse=true;
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

// void send_dpi_value_to_kb(void) {
// 	switch (keyboard_config.dpi_config) {
// 		case 0:
// 			tap_code(KC_SCRL);
//             wait_ms(39);
//             tap_code(KC_SCRL);
// 			break;
// 		case 1 :
// 			tap_code(KC_SCRL);
//             wait_ms(49);
//             tap_code(KC_SCRL);
// 			break;
// 		case 2:
// 			tap_code(KC_SCRL);
//             wait_ms(59);
//             tap_code(KC_SCRL);
// 			break;
// 	}
// }

void do_trigger_action(struct action_trigger_t *trigger) {
	switch(trigger->name) {
		case KB_TO_TB_TOGGLE_SCROLL_TRIGGER:
			toggle_scroll();
			break;
		case KB_TO_TB_CYCLE_DPI_TRIGGER:
			cycle_dpi();
			// send_dpi_value_to_kb();
#           ifdef CONSOLE_ENABLE
        	dprintf("dpi_config: %u\n", keyboard_config.dpi_config);
#			endif
			break;
		case KB_TO_TB_RESET_TRIGGER:
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
	for(i = 0; i < KB_TO_TB_TRIGGER_LENGTH; i++) {
		update_trigger(&kb_to_tb_trigger[i], led_state);
	}
}

bool led_update_user(led_t led_state) {
	update_trigger_list(led_state);
	return true;
}