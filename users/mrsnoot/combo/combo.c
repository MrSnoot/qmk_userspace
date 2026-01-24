#include "mrsnoot.h"

#ifdef COMBO_ENABLE
enum combos {
    #ifdef CS_INCLUDE_SONNE_LAYER
    // SONNE links
    SONNE_ESC,
    SONNE_DOT,
    SONNE_COMMA,
    SONNE_DASH,
    SONNE_SQOUT,
    SONNE_DQUOT,
    SONNE_STAR,
    SONNE_HASH,
    SONNE_EQUAL,
    SONNE_PERCENT,
    SONNE_SLASH,
    SONNE_BACKSLASH,
    // SONNE rechts
    SONNE_BSPC,
    SONNE_BSPC_WORD,
    SONNE_DEL,
    SONNE_DEL_WORD,
    SONNE_COPY,
    SONNE_PASTE,
    SONNE_CUT,
    SONNE_COPY_ALL,
    SONNE_COPY_LINE,
    SONNE_COPY_WORD,
    SONNE_ALT_F4,
    SONNE_TAB,
    SONNE_VDPR,
    SONNE_VDNX,
    //SONNE_TG_MOUSE_LAYER,
    // SONNE beidseitig
    SONNE_CAPS_WORD,
    #ifdef CS_NUM_WORD_ENABLE
    SONNE_NUM_WORD,
    #endif
    #endif
    // Alle Base Layer
    #ifdef CS_NUM_WORD_ENABLE
    NUM_NUM_WORD,
    #endif
    NUM_NUM_BSPC,
    NUM_NUM_DEL,
    COM_MOUSE_DBL_CLICK
};

#ifdef CS_INCLUDE_SONNE_LAYER
// SONNE links
const uint16_t PROGMEM sonne_esc_combo[] = { DE_ADIA, DE_U, COMBO_END };
const uint16_t PROGMEM sonne_dot_combo[] = { HRM_S_E, HRM_S_S, COMBO_END };
const uint16_t PROGMEM sonne_comma_combo[] = { HRM_S_I, HRM_S_E, COMBO_END };
const uint16_t PROGMEM sonne_dash_combo[] = { HRM_S_A, HRM_S_I, COMBO_END };
const uint16_t PROGMEM sonne_squot_combo[] = { DE_O, DE_M, COMBO_END };
const uint16_t PROGMEM sonne_dquot_combo[] = { DE_ODIA, DE_W, COMBO_END };
const uint16_t PROGMEM sonne_star_combo[] = { HRM_S_E, DE_W, COMBO_END };
const uint16_t PROGMEM sonne_hash_combo[] = { DE_J, DE_ODIA, COMBO_END };
const uint16_t PROGMEM sonne_equal_combo[] = { DE_U, DE_O, COMBO_END };
const uint16_t PROGMEM sonne_percent_combo[] = { HRM_S_S, DE_ODIA, COMBO_END };
const uint16_t PROGMEM sonne_slash_combo[] = { HRM_S_E, DE_J, COMBO_END };
const uint16_t PROGMEM sonne_backslash_combo[] = { HRM_S_I, DE_ODIA, COMBO_END };
// SONNE rechts
const uint16_t PROGMEM sonne_bspc_combo[]  = { HRM_S_H, HRM_S_T, COMBO_END };
const uint16_t PROGMEM sonne_bspc_word_combo[]  = { HRM_S_H, HRM_S_T, HRM_S_N, COMBO_END };
const uint16_t PROGMEM sonne_del_combo[]  = { HRM_S_N, HRM_S_R, COMBO_END };
const uint16_t PROGMEM sonne_del_word_combo[]  = { HRM_S_T, HRM_S_N, HRM_S_R, COMBO_END };
const uint16_t PROGMEM sonne_copy_combo[]  = { DE_D, DE_C, COMBO_END };
const uint16_t PROGMEM sonne_paste_combo[]  = { DE_C, DE_L, COMBO_END };
const uint16_t PROGMEM sonne_cut_combo[] = { DE_L, DE_Q, COMBO_END };
const uint16_t PROGMEM sonne_copy_all_combo[] = { DE_K, DE_B, COMBO_END };
const uint16_t PROGMEM sonne_copy_line_combo[] = { DE_B, DE_X, COMBO_END };
const uint16_t PROGMEM sonne_copy_word_combo[] = { DE_X, GUI_SS, COMBO_END };
const uint16_t PROGMEM sonne_alt_f4_combo[] = { DE_G, DE_Z, COMBO_END };
const uint16_t PROGMEM sonne_tab_combo[] = { HRM_S_T, DE_K, COMBO_END };
const uint16_t PROGMEM sonne_vdpr_combo[] = { HRM_S_H, DE_C, COMBO_END };
const uint16_t PROGMEM sonne_vdnx_combo[] = { HRM_S_T, DE_D, COMBO_END };
//const uint16_t PROGMEM sonne_tg_mouse_layer_combo[]  = { MS_ENT, HRM_S_N, COMBO_END };
#ifdef CS_NUM_WORD_ENABLE
const uint16_t PROGMEM sonne_num_word_combo[] = { HRM_S_H, DE_B, COMBO_END };
#endif
// SONNE Beidseitig
const uint16_t PROGMEM sonne_caps_word_combo[] = { HRM_S_A, HRM_S_R, COMBO_END };
#endif
// Alle Base Layer
#ifdef CS_NUM_WORD_ENABLE
const uint16_t PROGMEM num_num_word_combo[] = { NUM_4, DE_2, COMBO_END };
#endif
const uint16_t PROGMEM num_num_bspc_combo[]  = { NUM_4, NUM_5, COMBO_END };
const uint16_t PROGMEM num_num_del_combo[]  = { NUM_6, NUM_PLS, COMBO_END };
const uint16_t PROGMEM com_mouse_double_click_combo[] = { MS_BTN1, MS_BTN2, COMBO_END };

combo_t key_combos[] = {
    #ifdef CS_INCLUDE_SONNE_LAYER
    // SONNE links
    [SONNE_ESC] = COMBO(sonne_esc_combo, KC_ESC),
    [SONNE_DOT] = COMBO(sonne_dot_combo, DE_DOT),
    [SONNE_COMMA] = COMBO(sonne_comma_combo, DE_COMM),
    [SONNE_DASH] = COMBO(sonne_dash_combo, DE_MINS),
    [SONNE_SQOUT] = COMBO(sonne_squot_combo, DE_QUOT),
    [SONNE_DQUOT] = COMBO(sonne_dquot_combo, DE_DQUO),
    [SONNE_STAR] = COMBO(sonne_star_combo, DE_ASTR),
    [SONNE_HASH] = COMBO(sonne_hash_combo, DE_HASH),
    [SONNE_EQUAL] = COMBO(sonne_equal_combo, DE_EQL),
    [SONNE_PERCENT] = COMBO(sonne_percent_combo, DE_PERC),
    [SONNE_SLASH] = COMBO(sonne_slash_combo, DE_SLSH),
    [SONNE_BACKSLASH] = COMBO(sonne_backslash_combo, DE_BSLS),
    // SONNE rechts
    [SONNE_BSPC] = COMBO(sonne_bspc_combo, KC_BSPC),
    [SONNE_BSPC_WORD] = COMBO(sonne_bspc_word_combo, LCTL(KC_BSPC)),
    [SONNE_DEL] = COMBO(sonne_del_combo, KC_DEL),
    [SONNE_DEL_WORD] = COMBO(sonne_del_word_combo, LCTL(KC_DEL)),
    [SONNE_COPY] = COMBO(sonne_copy_combo, LCTL(DE_C)),
    [SONNE_PASTE] = COMBO(sonne_paste_combo, LCTL(DE_V)),
    [SONNE_CUT] = COMBO(sonne_cut_combo, LCTL(DE_X)),
    [SONNE_COPY_ALL] = COMBO(sonne_copy_all_combo, CP_ALL),
    [SONNE_COPY_LINE] = COMBO(sonne_copy_line_combo, CP_LINE),
    [SONNE_COPY_WORD] = COMBO(sonne_copy_word_combo, CP_WORD),
    [SONNE_ALT_F4] = COMBO(sonne_alt_f4_combo, LALT(KC_F4)),
    [SONNE_TAB] = COMBO(sonne_tab_combo, KC_TAB),
    [SONNE_VDPR] = COMBO(sonne_vdpr_combo, CS_VDPR),
    [SONNE_VDNX] = COMBO(sonne_vdnx_combo, CS_VDNX),
    //[SONNE_TG_MOUSE_LAYER] = COMBO(sonne_tg_mouse_layer_combo, TG_MS_L),
    #ifdef CS_NUM_WORD_ENABLE
    [SONNE_NUM_WORD] = COMBO(sonne_num_word_combo, NUMWORD),
    #endif
    // SONNE beidseitig
    [SONNE_CAPS_WORD] = COMBO(sonne_caps_word_combo, CW_TOGG),
    #endif
    // Alle Base Layer
    #ifdef CS_NUM_WORD_ENABLE
    [NUM_NUM_WORD] = COMBO(num_num_word_combo, NUMWORD),
    #endif
    [NUM_NUM_BSPC] = COMBO(num_num_bspc_combo, KC_BSPC),
    [NUM_NUM_DEL] = COMBO(num_num_del_combo, KC_DEL),
    [COM_MOUSE_DBL_CLICK] = COMBO(com_mouse_double_click_combo, DBL_CLK),
};

bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
    switch (combo_index) {
        #ifdef CS_INCLUDE_SONNE_LAYER
        case SONNE_ESC ... SONNE_CAPS_WORD:
            if (!layer_state_cmp(default_layer_state, SONNE)) {
                return false;
            }
            break;
        #ifdef CS_NUM_WORD_ENABLE
        case SONNE_NUM_WORD:
            if (!layer_state_cmp(default_layer_state, SONNE)) {
                return false;
            }
            break;
        #endif
        #endif
        #ifdef CS_NUM_WORD_ENABLE
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