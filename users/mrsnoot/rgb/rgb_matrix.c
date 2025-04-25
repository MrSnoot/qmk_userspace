#include "mrsnoot.h"

#ifdef RGB_MATRIX_ENABLE
/* Per-Key Farben setzen
 * 
 * rgb_matrix_set_color(key_index, 10, 50, 2); grün
 * rgb_matrix_set_color(key_index, 50, 40, 0); gelb
 * rgb_matrix_set_color(key_index, 50, 15.6, 0); orange
 * rgb_matrix_set_color(key_index, 50, 0, 0); rot
 * rgb_matrix_set_color(key_index, 10, 0, 50); lila
 * rgb_matrix_set_color(key_index, 0, 40, 50); ice blau
 *
 */
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

#if defined(KEYBOARD_splitkb_aurora_corne_rev1)
uint8_t home_row_mods_left[] = { 15, 16, 17, 18 };
uint8_t home_row_mods_right[] = { 42, 43, 44, 45 };
uint8_t layout_indicators[] = { 6, 7, 8, 33, 34, 35 };
// Nav
uint8_t pgup_pgdn[] = { 45, 50 };
uint8_t home_end[] = { 47, 49 };
uint8_t cursor[] = { 42, 43, 44, 48 };
// Mouse
uint8_t tb_dpi[] = { 37, 41 };
uint8_t mouse_btn[] = { 42, 43 };
uint8_t mouse_ctrl[] = { 44, 45 };
// Num_Func
uint8_t f_rows[] = { 10, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23 };
uint8_t num_block[] = { 33, 37, 38, 39, 42, 43, 44, 47, 48, 49 };
uint8_t num_block_ops[] = { 41, 45, 46, 50 };
uint8_t num_block_dots[] = { 36, 40 };
// Symbol
uint8_t symbols[] = { 18, 19, 20, 21, 22, 23, 44, 45 };
uint8_t brackets[] = { 9, 10, 11, 12, 14, 15, 16, 17 };
uint8_t xml_pretty_print[] = { 42, 43 };
uint8_t im1_admin[] = { 37, 38 };
uint8_t hl7_entities[] = { 47, 48, 49 };
uint8_t print_screen = 40;
// Adjust
uint8_t reset_kb_tb[] = { 40, 50 };
uint8_t rgb_toggle = 23;
uint8_t audio_settings[] = { 14, 15, 16, 17, 18 };
uint8_t auto_shift_settings[] = { 10, 11, 12, 13 };
uint8_t host_led_status[] = { 37, 42, 47 };
#endif

#if defined(KEYBOARD_splitkb_aurora_helix_rev1)
uint8_t home_row_mods_left[] = { 13, 14, 15, 16 };
uint8_t home_row_mods_right[] = { 51, 52, 53, 54 };
uint8_t layout_indicators[] = { 24, 25, 26, 62, 63, 64 };
// Nav
uint8_t pgup_pgdn[] = { 48, 54 };
uint8_t home_end[] = { 45, 47 };
uint8_t cursor[] = { 46, 51, 52, 53 };
// Mouse
uint8_t tb_dpi[] = { 50, 57 };
uint8_t mouse_btn[] = { 51, 52 };
uint8_t mouse_ctrl[] = { 53, 54 };
// Num_Func  
uint8_t f_rows[] = { 6, 7, 8, 9, 10, 12, 13, 14, 15, 16, 19, 21, 22 };
uint8_t num_block[] = { 45, 46, 47, 51, 52, 53, 57, 58, 59, 63 };
uint8_t num_block_ops[] = { 44, 48, 50, 54 };
uint8_t num_block_dots[] = { 56, 60 };
// Symbol
uint8_t symbols[] = { 6, 7, 8, 9, 10, 16, 53, 54 };
uint8_t brackets[] = { 12, 13, 14, 15, 18, 19, 20, 21 };
uint8_t xml_pretty_print[] = { 51, 52 };
uint8_t im1_admin[] = { 57, 58 };
uint8_t hl7_entities[] = { 45, 46, 47 };
uint8_t print_screen = 60;
// Adjust
uint8_t reset_kb_tb[] = { 48, 60 };
uint8_t rgb_toggle = 11;
uint8_t audio_settings[] = { 12, 13, 14, 15, 16 };
uint8_t auto_shift_settings[] = { 19, 20, 21, 22 };
uint8_t host_led_status[] = { 45, 51, 57 };
#endif

void set_color(uint8_t led_index, uint8_t color)
{
    rgb_matrix_set_color(led_index, color_values[color][0], color_values[color][1], color_values[color][2]);
}

void set_colors(uint8_t led_indexes[], uint8_t length, uint8_t color)
{
    for(uint8_t i = 0; i < length; i++)
    {
        set_color(led_indexes[i], color);
    }
}

void set_colors_green(uint8_t led_indexes[], uint8_t length)
{
    set_colors(led_indexes, length, GREEN);
}

void set_colors_yellow(uint8_t led_indexes[], uint8_t length)
{
    set_colors(led_indexes, length, YELLOW);
}

void set_colors_orange(uint8_t led_indexes[], uint8_t length)
{
    set_colors(led_indexes, length, ORANGE);
}

void set_colors_red(uint8_t led_indexes[], uint8_t length)
{
    set_colors(led_indexes, length, RED);
}

void set_colors_lilac(uint8_t led_indexes[], uint8_t length)
{
    set_colors(led_indexes, length, LILAC);
}

void set_colors_iceblue(uint8_t led_indexes[], uint8_t length)
{
    set_colors(led_indexes, length, ICEBLUE);
}

uint8_t get_default_layer_color(void)
{
    uint8_t color = LILAC;

    switch (biton32(default_layer_state))
    {
        case SONNE:
            color = SONNE;
            break;
        // case QWERTY:
        //     color = QWERTY;
        //     break;
    }

    return color;
}

void set_layout_indicators(void)
{
    set_colors(layout_indicators, sizeof(layout_indicators), get_default_layer_color());
}

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
     
	uint8_t layer = biton32(layer_state);
    rgb_matrix_set_color_all(0, 0, 0);
    set_layout_indicators();

	switch (layer)
	{
        case SONNE:
            set_colors(home_row_mods_left, sizeof(home_row_mods_left), get_default_layer_color());
            set_colors(home_row_mods_right, sizeof(home_row_mods_right), get_default_layer_color());
            break;
        case NAV:
			set_colors(home_row_mods_left, sizeof(home_row_mods_left), get_default_layer_color());
            set_colors_lilac(pgup_pgdn, sizeof(pgup_pgdn));
            set_colors_orange(home_end, sizeof(home_end));
            set_colors_green(cursor, sizeof(cursor));
            break;
        case MOUSE:
            set_colors(home_row_mods_left, sizeof(home_row_mods_left), get_default_layer_color());
            set_colors(mouse_ctrl, sizeof(mouse_ctrl), get_default_layer_color());
            set_colors_orange(mouse_btn, sizeof(mouse_btn));
            set_colors_lilac(tb_dpi, sizeof(tb_dpi));
		case NUM_FUNC:
			set_colors_green(f_rows, sizeof(f_rows));
            set_colors_orange(num_block, sizeof(num_block));
            set_colors_iceblue(num_block_ops, sizeof(num_block_ops));
            set_colors_yellow(num_block_dots, sizeof(num_block_dots));
			break;
        case SYMBOL:
            set_colors_lilac(symbols, sizeof(symbols));
            set_colors_green(brackets, sizeof(brackets));
            set_colors_iceblue(xml_pretty_print, sizeof(xml_pretty_print));
            set_colors_red(im1_admin, sizeof(im1_admin));
            set_colors_orange(hl7_entities, sizeof(hl7_entities));
            set_color(print_screen, YELLOW);
            break;
        case ADJUST:
            set_colors_red(reset_kb_tb, sizeof(reset_kb_tb));
            set_color(rgb_toggle, YELLOW);
            set_colors_green(audio_settings, sizeof(audio_settings));
            set_colors_iceblue(auto_shift_settings, sizeof(auto_shift_settings));
            
            // Host Keyboard LED Status
            set_colors_green(host_led_status, sizeof(host_led_status));
            // uint8_t led_usb_state = host_keyboard_leds();
            // IS_LED_ON(led_usb_state, USB_LED_NUM_LOCK) ? set_color(50, GREEN) : set_color(50, ICEBLUE);
            // IS_LED_ON(led_usb_state, USB_LED_CAPS_LOCK) ? set_color(45, GREEN) : set_color(45, ICEBLUE);
            // IS_LED_ON(led_usb_state, USB_LED_SCROLL_LOCK) ? set_color(40, GREEN) : set_color(40, ICEBLUE);	
            break;
	}

    return false;
}
#endif