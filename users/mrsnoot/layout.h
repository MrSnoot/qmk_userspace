#include "quantum/keycodes.h"

#define G_T_F6 LGUI_T(KC_F6)
#define A_T_F7 LALT_T(KC_F7)
#define C_T_F8 LCTL_T(KC_F8)
#define S_T_F9 RSFT_T(KC_F9)
#define NPP_LN MEH(KC_L)
#define NPP_PP MEH(KC_B)
#define QUESTM LSFT(KC_MINS)
#define L_CBKT RALT(KC_7)
#define L_SBKT RALT(KC_8)
#define R_CBKT RALT(KC_0)
#define R_SBKT RALT(KC_9)
#define AC_TG LSFT(KC_EQL)
#define S_NUBS LSFT(KC_NUBS)
#define PIPE RALT(KC_NUBS)
#define TILDE RALT(KC_RBRC)
#define MO_ADJ MO(ADJUST)

// Home row mod-tap macros
#define HRML(k1,k2,k3,k4) LSFT_T(k1), LALT_T(k2), LCTL_T(k3), k4
#define HRMR(k1,k2,k3,k4) k1, LCTL_T(k2), LALT_T(k3), RSFT_T(k4)

// Layers
// enum layers {
//     OPY = 0,
//     QWERTY,
//     NAV,
//     NUM_FUNC,
//     SYMBOL,
//     ADJUST
// };

#define _OPY \
/* ╭────────┬────────┬────────┬────────┬────────╮   ╭────────┬────────┬────────┬────────┬────────╮ */\
/* │  Q     │  Z     │  O     │  P     │  Y     │   │  W     │  C     │  M     │  V     │  X     │ */\
	KC_Q,    KC_Y,    KC_O,    KC_P,    KC_Z,        KC_W,    KC_C,    KC_M,    KC_V,    KC_X,       \
/* ├────────┼────────┼────────┼────────┼────────┤   ├────────┼────────┼────────┼────────┼────────┤ */\
/* │  H     │  A     │  E     │  I     │  U     │   │  D     │  T     │  N     │  S     │ R      │ */\
	KC_H,    KC_A,    KC_E,    KC_I,    KC_U,        KC_D,    KC_T,    KC_N,    KC_S,    KC_R,       \
/* ├────────┼────────┼────────┼────────┼────────┤   ├────────┼────────┼────────┼────────┼────────┤ */\
/* │  J     │  Ö     │  Ä     │  K     │  Ü     │   │  B     │  G     │ L      │ F      │ '      │ */\
	KC_J,    KC_SCLN, KC_QUOT, KC_K,    KC_LBRC,     KC_B,    KC_G,    KC_L,    KC_F,    QUOT_S,     \
/* ╰────────┴────────┴────────┼────────┼────────┤   ├────────┼────────┼────────┴────────┴────────╯ */\
	              OSL(NUM_FUNC), LT(NAV, KC_SPC),    KC_ENT, OSL(SYMBOL)
/*                            ╰────────┴────────╯   ╰────────┴────────╯ */

#define _QWERTY \
/* ╭────────┬────────┬────────┬────────┬────────╮   ╭────────┬────────┬────────┬────────┬────────╮ */\
/* │  Q     │  W     │  E     │  R     │  T     │   │  Z     │  U     │  I     │  O     │  P     │ */\
    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,       \
/* ├────────┼────────┼────────┼────────┼────────┤   ├────────┼────────┼────────┼────────┼────────┤ */\
/* │  A     │  S     │  D     │  F     │  G     │   │  H     │  J     │  K     │  L     │  Ö     │ */\
    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,        KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,    \
/* ├────────┼────────┼────────┼────────┼────────┤   ├────────┼────────┼────────┼────────┼────────┤ */\
/* │  Y     │  X     │  C     │  V     │  B     │   │  N     │  M     │ , ;    │ . :    │ - _    │ */\
    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,        KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,    \
/* ╰────────┴────────┴────────┼────────┼────────┤   ├────────┼────────┼────────┴────────┴────────╯ */\
                               _______, _______,     _______, _______
/*                            ╰────────┴────────╯   ╰────────┴────────╯ */

#define _NAV \
/* ╭────────┬────────┬────────┬────────┬────────╮   ╭────────┬────────┬────────┬────────┬────────╮ */\
/* │        │        │        │        │        │   │        │  Home  │  Up    │  End   │  PgUp  │ */\
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, KC_HOME, KC_UP,   KC_END,  KC_PGUP,    \
/* ├────────┼────────┼────────┼────────┼────────┤   ├────────┼────────┼────────┼────────┼────────┤ */\
/* │  Gui   │  Alt   │  Ctrl  │  Shift │        │   │        │  Left  │  Down  │  Right │  PgDn  │ */\
    KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,     XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,    \
/* ├────────┼────────┼────────┼────────┼────────┤   ├────────┼────────┼────────┼────────┼────────┤ */\
/* │        │        │        │        │        │   │        │        │        │        │        │ */\
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    \
/* ╰────────┴────────┴────────┼────────┼────────┤   ├────────┼────────┼────────┴────────┴────────╯ */\
                               _______, _______,     _______, _______
/*                            ╰────────┴────────╯   ╰────────┴────────╯ */

#define _NUM_FUNC \
/* ╭────────┬────────┬────────┬────────┬────────╮   ╭────────┬────────┬────────┬────────┬────────╮ */\
/* │  F1    │  F2    │  F3    │  F4    │  F5    │   │  /     │  7     │  8     │  9     │  -     │ */\
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,       KC_PSLS, KC_7,    KC_8,    KC_9,    KC_PMNS,    \
/* ├────────┼────────┼────────┼────────┼────────┤   ├────────┼────────┼────────┼────────┼────────┤ */\
/* │  F6    │  F7    │  F8    │  F9    │  F10   │   │  *     │  4     │  5     │  6     │  +     │ */\
    G_T_F6,  A_T_F7,  C_T_F8,  S_T_F9,  KC_F10,      KC_PAST, KC_4,    KC_5,    KC_6,    KC_PPLS,    \
/* ├────────┼────────┼────────┼────────┼────────┤   ├────────┼────────┼────────┼────────┼────────┤ */\
/* │        │        │        │        │        │   │  ,     │  1     │  2     │  3     │  .     │ */\
    KC_F11,  KC_F12,  XXXXXXX, S_LN_F5, XXXXXXX,     KC_PDOT, KC_1,    KC_2,    KC_3,    KC_DOT,     \
/* ╰────────┴────────┴────────┼────────┼────────┤   ├────────┼────────┼────────┴────────┴────────╯ */\
                               _______, _______,     KC_0,    MO_ADJ
/*                            ╰────────┴────────╯   ╰────────┴────────╯ */

#define _SYMBOL \
/* ╭────────┬────────┬────────┬────────┬────────╮   ╭────────┬────────┬────────┬────────┬────────╮ */\
/* │  !     │        │        │  $     │  &     │   │        │ NPP LN │ NPP PP │        │        │ */\
    KC_EXLM, KC_TILD, KC_HASH, KC_DLR,  KC_CIRC,     XXXXXXX, NPP_LN,  NPP_PP,  XXXXXXX, XXXXXXX,    \
/* ├────────┼────────┼────────┼────────┼────────┤   ├────────┼────────┼────────┼────────┼────────┤ */\
/* │  ?     │  {     │  [     │  (     │  <     │   │        │  CP LN │ IM1 INS│  ´     │  `     │ */\
    QUESTM,  L_CBKT,  L_SBKT,  KC_ASTR, KC_NUBS,     XXXXXXX, F2_CPLN, IM1_INS, KC_EQL,  AC_TG,      \
/* ├────────┼────────┼────────┼────────┼────────┤   ├────────┼────────┼────────┼────────┼────────┤ */\
/* │        │  }     │  ]     │  )     │  >     │   │        │  |     │  ^     │  ~     │  .     │ */\
    XXXXXXX, R_CBKT,  R_SBKT,  KC_LPRN, S_NUBS,      XXXXXXX, PIPE,    KC_GRV,  TILDE,   XXXXXXX,    \
/* ╰────────┴────────┴────────┼────────┼────────┤   ├────────┼────────┼────────┴────────┴────────╯ */\
                               MO_ADJ,  _______,     _______, _______
/*                            ╰────────┴────────╯   ╰────────┴────────╯ */

#define _ADJUST \
/* ╭────────┬────────┬────────┬────────┬────────╮   ╭────────┬────────┬────────┬────────┬────────╮ */\
/* │        │        │        │        │        │   │        │        │        │        │        │ */\
    RGB_TOG, CK_TOGG, CK_DOWN, CK_UP,   CK_RST,      XXXXXXX, RGUI(KC_7), RGUI(KC_8), RGUI(KC_9), KC_NUM, \
/* ├────────┼────────┼────────┼────────┼────────┤   ├────────┼────────┼────────┼────────┼────────┤ */\
/* │        │        │        │        │        │   │        │        │        │        │        │ */\
    AU_TOGG, MU_TOGG, MU_NEXT, XXXXXXX, XXXXXXX,     TB_DPIM, RGUI(KC_4), RGUI(KC_5), RGUI(KC_6), KC_CAPS, \
/* ├────────┼────────┼────────┼────────┼────────┤   ├────────┼────────┼────────┼────────┼────────┤ */\
/* │        │        │        │        │        │   │        │        │        │        │        │ */\
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     TB_DPIS, RGUI(KC_1), RGUI(KC_2), RGUI(KC_3), KC_SCRL, \
/* ╰────────┴────────┴────────┼────────┼────────┤   ├────────┼────────┼────────┴────────┴────────╯ */\
                               _______,  _______,     _______, _______
/*                            ╰────────┴────────╯   ╰────────┴────────╯ */


// Mod-tap wrapper
#define HRM(k) HR_MODTAP(k)
#define HR_MODTAP( \
	  l01, l02, l03, l04, l05,   r01, r02, r03, r04, r05, \
	  l06, l07, l08, l09, l10,   r06, r07, r08, r09, r10, \
	  l11, l12, l13, l14, l15,   r11, r12, r13, r14, r15, \
	                 l16, l17,   r16, r17                 \
) \
	  l01, l02, l03, l04, l05,   r01, r02, r03, r04, r05,       \
HRML(l06, l07, l08, l09), l10,   r06, HRMR(r07, r08, r09, r10), \
	  l11, l12, l13, l14, l15,   r11, r12, r13, r14, r15, \
	                 l16, l17,   r16, r17


// Layout aliases for json keymap
#define LAYOUT_34key_w(...) LAYOUT_split_3x5_2(__VA_ARGS__)
#define LAYOUT_aurora_corne_w(...) LAYOUT_split_3x6_3(__VA_ARGS__)
// #define LAYOUT_ortho_w(...) LAYOUT_ortho_4x12(__VA_ARGS__)


// Convert 3x5_2 to 42-key
#define C_42(k) CONV_42(k)
#define CONV_42( \
	     l01, l02, l03, l04, l05,   r01, r02, r03, r04, r05, \
	     l06, l07, l08, l09, l10,   r06, r07, r08, r09, r10, \
	     l11, l12, l13, l14, l15,   r11, r12, r13, r14, r15, \
	                    l16, l17,   r16, r17                 \
) \
KC_ESC,  l01, l02, l03, l04, l05,   r01, r02, r03, r04, r05, KC_LGUI, \
KC_BTN2, l06, l07, l08, l09, l10,   r06, r07, r08, r09, r10, KC_TAB, \
KC_BTN1, l11, l12, l13, l14, l15,   r11, r12, r13, r14, r15, RSFT(KC_TAB), \
	           XXXXXXX, l16, l17,   r16, r17, XXXXXXX