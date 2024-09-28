#include "mrsnoot.h"

#ifdef COMBO_ENABLE
enum combos {
    #ifdef CS_INCLUDE_QWERTY_LAYER
    // QWERTY links
    QWERTY_TB_SCROLL,
    // QWERTY rechts
    QWERTY_BSPC,
    QWERTY_BSPC_WORD,
    QWERTY_DEL,
    QWERTY_DEL_WORD,
    QWERTY_COPY,
    QWERTY_PASTE,
    QWERTY_CUT,
    QWERTY_COPY_ALL,
    QWERTY_COPY_LINE,
    QWERTY_COPY_WORD,
    QWERTY_ALT_F4,
    #endif
    #ifdef CS_INCLUDE_OPY_LAYER
    // OPY links
    OPY_ESC,
    OPY_DOT,
    OPY_COMMA,
    OPY_DASH,
    OPY_SQOUT,
    OPY_DQUOT,
    OPY_STAR,
    OPY_HASH,
    OPY_EQUAL,
    OPY_PERCENT,
    OPY_SLASH,
    OPY_BACKSLASH,
    // OPY rechts
    OPY_BSPC,
    OPY_BSPC_WORD,
    OPY_DEL,
    OPY_DEL_WORD,
    OPY_COPY,
    OPY_PASTE,
    OPY_CUT,
    OPY_COPY_ALL,
    OPY_COPY_LINE,
    OPY_COPY_WORD,
    OPY_ALT_F4,
    OPY_TAB,
    OPY_VDPR,
    OPY_VDNX,
    NUM_BSPC,
    NUM_DEL,
    // OPY beidseitig
    OPY_CAPS_WORD,
#ifdef CS_NUM_WORD_ENABLE
    OPY_NUM_WORD,
    NUM_NUM_WORD,
#endif
    #endif
    // Alle Base Layer
    COM_MOUSE_DBL_CLICK
};

#ifdef CS_INCLUDE_QWERTY_LAYER
// QWERTY links
const uint16_t PROGMEM qwerty_trackball_scroll_combo[] = { KC_BTN2, DE_LABK, COMBO_END };
// QWERTY rechts
const uint16_t PROGMEM qwerty_bspc_combo[]  = { HRM_Q_J, HRM_Q_K, COMBO_END };
const uint16_t PROGMEM qwerty_bspc_word_combo[]  = { HRM_Q_J, HRM_Q_K, HRM_Q_L, COMBO_END };
const uint16_t PROGMEM qwerty_del_combo[]  = { HRM_Q_L, HRM_QOE, COMBO_END };
const uint16_t PROGMEM qwerty_del_word_combo[]  = { HRM_Q_K, HRM_Q_L, HRM_QOE, COMBO_END };
const uint16_t PROGMEM qwerty_copy_combo[]  = { DE_U, DE_I, COMBO_END };
const uint16_t PROGMEM qwerty_paste_combo[]  = { DE_I, DE_O, COMBO_END };
const uint16_t PROGMEM qwerty_cut_combo[] = { DE_O, DE_P, COMBO_END };
const uint16_t PROGMEM qwerty_copy_all_combo[] = { DE_M, DE_COMM, COMBO_END };
const uint16_t PROGMEM qwerty_copy_line_combo[] = { DE_COMM, DE_DOT, COMBO_END };
const uint16_t PROGMEM qwerty_copy_word_combo[] = { DE_DOT, DE_MINS, COMBO_END };
const uint16_t PROGMEM qwerty_alt_f4_combo[] = { DE_H, DE_N, COMBO_END };
#endif
#ifdef CS_INCLUDE_OPY_LAYER
// OPY links
const uint16_t PROGMEM opy_esc_combo[] = { DE_Q, DE_Z, COMBO_END };
const uint16_t PROGMEM opy_dot_combo[] = { HRM_O_E, HRM_O_I, COMBO_END };
const uint16_t PROGMEM opy_comma_combo[] = { HRM_O_A, HRM_O_E, COMBO_END };
const uint16_t PROGMEM opy_dash_combo[] = { HRM_O_H, HRM_O_A, COMBO_END };
const uint16_t PROGMEM opy_squot_combo[] = { DE_O, DE_P, COMBO_END };
const uint16_t PROGMEM opy_dquot_combo[] = { DE_ADIA, DE_U, COMBO_END };
const uint16_t PROGMEM opy_star_combo[] = { HRM_O_E, DE_U, COMBO_END };
const uint16_t PROGMEM opy_hash_combo[] = { DE_ODIA, DE_ADIA, COMBO_END };
const uint16_t PROGMEM opy_equal_combo[] = { DE_Z, DE_O, COMBO_END };
const uint16_t PROGMEM opy_percent_combo[] = { HRM_O_I, DE_ADIA, COMBO_END };
const uint16_t PROGMEM opy_slash_combo[] = { HRM_O_E, DE_ODIA, COMBO_END };
const uint16_t PROGMEM opy_backslash_combo[] = { HRM_O_A, DE_ADIA, COMBO_END };
// OPY rechts
const uint16_t PROGMEM opy_bspc_combo[]  = { HRM_O_T, HRM_O_N, COMBO_END };
const uint16_t PROGMEM opy_bspc_word_combo[]  = { HRM_O_T, HRM_O_N, HRM_O_S, COMBO_END };
const uint16_t PROGMEM opy_del_combo[]  = { HRM_O_S, HRM_O_R, COMBO_END };
const uint16_t PROGMEM opy_del_word_combo[]  = { HRM_O_N, HRM_O_S, HRM_O_R, COMBO_END };
const uint16_t PROGMEM opy_copy_combo[]  = { DE_C, DE_M, COMBO_END };
const uint16_t PROGMEM opy_paste_combo[]  = { DE_M, DE_V, COMBO_END };
const uint16_t PROGMEM opy_cut_combo[] = { DE_V, DE_X, COMBO_END };
const uint16_t PROGMEM opy_copy_all_combo[] = { DE_D, DE_L, COMBO_END };
const uint16_t PROGMEM opy_copy_line_combo[] = { DE_L, DE_F, COMBO_END };
const uint16_t PROGMEM opy_copy_word_combo[] = { DE_F, GUI_SS, COMBO_END };
const uint16_t PROGMEM opy_alt_f4_combo[] = { DE_G, DE_B, COMBO_END };
const uint16_t PROGMEM opy_tab_combo[] = { HRM_O_N, DE_D, COMBO_END };
const uint16_t PROGMEM opy_vdpr_combo[] = { HRM_O_T, DE_M, COMBO_END };
const uint16_t PROGMEM opy_vdnx_combo[] = { HRM_O_N, DE_C, COMBO_END };
const uint16_t PROGMEM num_bspc_combo[]  = { NUM_4, NUM_5, COMBO_END };
const uint16_t PROGMEM num_del_combo[]  = { NUM_6, NUM_PLS, COMBO_END };
// OPY Beidseitig
const uint16_t PROGMEM opy_caps_word_combo[] = { HRM_O_H, HRM_O_R, COMBO_END };
#ifdef CS_NUM_WORD_ENABLE
const uint16_t PROGMEM opy_num_word_combo[] = { DE_M, HRM_O_S, COMBO_END };
const uint16_t PROGMEM num_num_word_combo[] = { DE_8, NUM_6, COMBO_END };
#endif
#endif
// Alle Base Layer
const uint16_t PROGMEM com_mouse_double_click_combo[] = { KC_BTN1, KC_BTN2, COMBO_END };

combo_t key_combos[] = {
    #ifdef CS_INCLUDE_QWERTY_LAYER
    // QWERTY links
    [QWERTY_TB_SCROLL] = COMBO(qwerty_trackball_scroll_combo, TB_SCR),
    // QWERTY rechts
    [QWERTY_BSPC] = COMBO(qwerty_bspc_combo, KC_BSPC),
    [QWERTY_BSPC_WORD] = COMBO(qwerty_bspc_word_combo, LCTL(KC_BSPC)),
    [QWERTY_DEL] = COMBO(qwerty_del_combo, KC_DEL),
    [QWERTY_DEL_WORD] = COMBO(qwerty_del_word_combo, LCTL(KC_DEL)),
    [QWERTY_COPY] = COMBO(qwerty_copy_combo, LCTL(DE_C)),
    [QWERTY_PASTE] = COMBO(qwerty_paste_combo, LCTL(DE_V)),
    [QWERTY_CUT] = COMBO(qwerty_cut_combo, LCTL(DE_X)),
    [QWERTY_COPY_ALL] = COMBO(qwerty_copy_all_combo, CP_ALL),
    [QWERTY_COPY_LINE] = COMBO(qwerty_copy_line_combo, CP_LINE),
    [QWERTY_COPY_WORD] = COMBO(qwerty_copy_word_combo, CP_WORD),
    [QWERTY_ALT_F4] = COMBO(qwerty_alt_f4_combo, LALT(KC_F4)),
    #endif
    #ifdef CS_INCLUDE_OPY_LAYER
    // OPY links
    [OPY_ESC] = COMBO(opy_esc_combo, KC_ESC),
    [OPY_DOT] = COMBO(opy_dot_combo, DE_DOT),
    [OPY_COMMA] = COMBO(opy_comma_combo, DE_COMM),
    [OPY_DASH] = COMBO(opy_dash_combo, DE_MINS),
    [OPY_SQOUT] = COMBO(opy_squot_combo, DE_QUOT),
    [OPY_DQUOT] = COMBO(opy_dquot_combo, DE_DQUO),
    [OPY_STAR] = COMBO(opy_star_combo, DE_ASTR),
    [OPY_HASH] = COMBO(opy_hash_combo, DE_HASH),
    [OPY_EQUAL] = COMBO(opy_equal_combo, DE_EQL),
    [OPY_PERCENT] = COMBO(opy_percent_combo, DE_PERC),
    [OPY_SLASH] = COMBO(opy_slash_combo, DE_SLSH),
    [OPY_BACKSLASH] = COMBO(opy_backslash_combo, DE_BSLS),
    // OPY rechts
    [OPY_BSPC] = COMBO(opy_bspc_combo, KC_BSPC),
    [OPY_BSPC_WORD] = COMBO(opy_bspc_word_combo, LCTL(KC_BSPC)),
    [OPY_DEL] = COMBO(opy_del_combo, KC_DEL),
    [OPY_DEL_WORD] = COMBO(opy_del_word_combo, LCTL(KC_DEL)),
    [OPY_COPY] = COMBO(opy_copy_combo, LCTL(DE_C)),
    [OPY_PASTE] = COMBO(opy_paste_combo, LCTL(DE_V)),
    [OPY_CUT] = COMBO(opy_cut_combo, LCTL(DE_X)),
    [OPY_COPY_ALL] = COMBO(opy_copy_all_combo, CP_ALL),
    [OPY_COPY_LINE] = COMBO(opy_copy_line_combo, CP_LINE),
    [OPY_COPY_WORD] = COMBO(opy_copy_word_combo, CP_WORD),
    [OPY_ALT_F4] = COMBO(opy_alt_f4_combo, LALT(KC_F4)),
    [OPY_TAB] = COMBO(opy_tab_combo, KC_TAB),
    [OPY_VDPR] = COMBO(opy_vdpr_combo, CS_VDPR),
    [OPY_VDNX] = COMBO(opy_vdnx_combo, CS_VDNX),
    [NUM_BSPC] = COMBO(num_bspc_combo, KC_BSPC),
    [NUM_DEL] = COMBO(num_del_combo, KC_DEL),
    // OPY beidseitig
    [OPY_CAPS_WORD] = COMBO(opy_caps_word_combo, CW_TOGG),
#ifdef CS_NUM_WORD_ENABLE
    [OPY_NUM_WORD] = COMBO(opy_num_word_combo, NUMWORD),
    [NUM_NUM_WORD] = COMBO(num_num_word_combo, NUMWORD),
#endif
    #endif
    // Alle Base Layer
    [COM_MOUSE_DBL_CLICK] = COMBO(com_mouse_double_click_combo, DBL_CLK),
};

bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
    switch (combo_index) {
        #ifdef CS_INCLUDE_QWERTY_LAYER
        case QWERTY_TB_SCROLL ... QWERTY_ALT_F4:
            if (!layer_state_cmp(default_layer_state, QWERTY)) {
                return false;
            }
            break;
        #endif
        #ifdef CS_INCLUDE_OPY_LAYER
        case OPY_ESC ... OPY_CAPS_WORD:
            if (!layer_state_cmp(default_layer_state, OPY)) {
                return false;
            }
            break;
        #endif
        #ifdef CS_NUM_WORD_ENABLE
        case OPY_NUM_WORD:
            if (!layer_state_cmp(default_layer_state, OPY)) {
                return false;
            }
            break;
        case NUM_NUM_WORD:
            if (!layer_state_cmp(layer_state, NUM_FUNC)) {
                return false;
            }
            break;
        #endif
    }

    return true;
}
#endif