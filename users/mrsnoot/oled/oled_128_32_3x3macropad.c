#include "mrsnoot.h"
#include <stdio.h>

#ifdef OLED_ENABLE

#ifdef RGBLIGHT_ENABLE
extern rgblight_config_t rgblight_config;

void render_rgb_status(void) {
    static char temp[22] = {0};
    snprintf(temp, sizeof(temp) + 1, "M%3d/H%3d/S%3d/V%3d  ", rgblight_config.mode, rgblight_config.hue, rgblight_config.sat, rgblight_config.val);
    oled_write(temp, false);
}
#endif

bool oled_task_user(void)
{
	switch (get_highest_layer(layer_state))
    {
    case BASIS:             //---------------------//
        oled_write_ln_P(PSTR("VOL-   MUTE      VOL+"
                             "F2     WIN+G   LAYER+"
                             "F11    ALT+F4     SCR"), false);
        break;
    case ADJUST:         //---------------------//
        oled_write_P(PSTR("MODE-  ON/OFF   MODE+"), false);
        oled_write_P(PSTR("HUE+   SAT+    LAYER+"), false);
        #ifdef RGBLIGHT_ENABLE
        render_rgb_status();   
        #endif              
        break;
    case FUN:            //---------------------//
        oled_write_P(PSTR("   Emils Macropad    "), false);
        oled_write_P(PSTR("                     "), false);
        oled_write_P(PSTR("                     "), false);
        break;
    }
	return true;
}
#endif