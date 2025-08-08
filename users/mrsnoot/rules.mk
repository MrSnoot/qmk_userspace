SRC += mrsnoot.c

# Disable unused features ---------------------------------
COMMAND_ENABLE = no
CONSOLE_ENABLE = no
LEADER_ENABLE = no
RAW_ENABLE = no
SWAP_HANDS_ENABLE = no
TAP_DANCE_ENABLE= no
LTO_ENABLE = no

# Microcontroller features -----------------------------------------
#ifeq ($(strip $(KEYBOARD)), $(filter $(KEYBOARD), splitkb/aurora/corne/rev1 splitkb/aurora/helix/rev1))
#	CONVERT_TO = helios
#endif

# INTROSPECTION_KEYMAP_C = mrsnoot.c

# Common features -----------------------------------------
ifeq ($(strip $(KEYBOARD)), $(filter $(KEYBOARD), dasbob endgame/rev6 evyd13/eon40 evyd13/eon95 horizon kprepublic/bm60hsrgb_iso/rev1 ploopyco/madromys/rev1_001 ploopyco/trackball_nano/rev1_001 re_gret splitkb/aurora/corne/rev1 splitkb/aurora/helix/rev1))
	EXTRAKEY_ENABLE = no
endif

ifeq ($(strip $(KEYBOARD)), $(filter $(KEYBOARD), 3x3macropad))
	EXTRAKEY_ENABLE = yes
endif

# Split Boards --------------------------------------------

# Audio ---------------------------------------------------
ifeq ($(strip $(KEYBOARD)), $(filter $(KEYBOARD), 3x3macropad evyd13/eon40 evyd13/eon95 kprepublic/bm60hsrgb_iso/rev1 ploopyco/trackball_nano/rev1_001 re_gret))
	AUDIO_ENABLE = no
endif

ifeq ($(strip $(KEYBOARD)), $(filter $(KEYBOARD), dasbob endgame/rev6 horizon ploopyco/madromys/rev1_001 splitkb/aurora/corne/rev1 splitkb/aurora/helix/rev1))
	AUDIO_ENABLE = yes
	AUDIO_DRIVER = pwm_hardware
endif

# Num Word -----------------------------------------------
ifeq ($(strip $(KEYBOARD)), $(filter $(KEYBOARD), 3x3macropad evyd13/eon95 kprepublic/bm60hsrgb_iso/rev1 ploopyco/madromys/rev1_001 ploopyco/trackball_nano/rev1_001))
	CS_NUM_WORD_ENABLE = no 
endif

ifeq ($(strip $(KEYBOARD)), $(filter $(KEYBOARD), dasbob endgame/rev6 evyd13/eon40 horizon re_gret splitkb/aurora/corne/rev1 splitkb/aurora/helix/rev1))
	CS_NUM_WORD_ENABLE = yes
	SRC += num_word/num_word.c
    OPT_DEFS += -DCS_NUM_WORD_ENABLE
endif

# Combos --------------------------------------------------
ifeq ($(strip $(KEYBOARD)), $(filter $(KEYBOARD), 3x3macropad kprepublic/bm60hsrgb_iso/rev1 ploopyco/madromys/rev1_001 ploopyco/trackball_nano/rev1_001))
	COMBO_ENABLE = no
endif

ifeq ($(strip $(KEYBOARD)), $(filter $(KEYBOARD), dasbob endgame/rev6 evyd13/eon40 evyd13/eon95 horizon re_gret splitkb/aurora/corne/rev1 splitkb/aurora/helix/rev1))
	COMBO_ENABLE = yes
	INTROSPECTION_KEYMAP_C = combo/combo.c
# SRC += combo/combo.c

endif

# Encoder -------------------------------------------------
ifeq ($(strip $(KEYBOARD)), $(filter $(KEYBOARD), dasbob endgame/rev6 evyd13/eon40 evyd13/eon95 horizon kprepublic/bm60hsrgb_iso/rev1 ploopyco/madromys/rev1_001 ploopyco/trackball_nano/rev1_001 re_gret))
	ENCODER_ENABLE = no
endif

ifeq ($(strip $(KEYBOARD)), $(filter $(KEYBOARD), 3x3macropad))
	ENCODER_ENABLE = yes
	SRC += encoder/encoder_3x3macropad.c
endif

ifeq ($(strip $(KEYBOARD)), $(filter $(KEYBOARD), splitkb/aurora/corne/rev1 splitkb/aurora/helix/rev1))
	ENCODER_ENABLE = yes
	SRC += encoder/encoder_split.c
endif

# OLED ----------------------------------------------------
ifeq ($(strip $(KEYBOARD)), $(filter $(KEYBOARD), dasbob endgame/rev6 evyd13/eon40 evyd13/eon95 horizon kprepublic/bm60hsrgb_iso/rev1 ploopyco/madromys/rev1_001 ploopyco/trackball_nano/rev1_001 re_gret))
	OLED_ENABLE = no
endif

ifeq ($(strip $(KEYBOARD)), $(filter $(KEYBOARD), 3x3macropad))
	OLED_ENABLE = yes
	SRC += oled/oled_128_32_3x3macropad.c
endif

ifeq ($(strip $(KEYBOARD)), $(filter $(KEYBOARD), splitkb/aurora/corne/rev1 splitkb/aurora/helix/rev1))
	OLED_ENABLE = yes
	SRC += oled/oled_128_32_split.c
endif

ifeq ($(strip $(KEYBOARD)), $(filter $(KEYBOARD), xxx))
	OLED_ENABLE = yes
	SRC += oled/oled_128_64_split.c
endif

# RGB -----------------------------------------------------
ifeq ($(strip $(KEYBOARD)), $(filter $(KEYBOARD), dasbob endgame/rev6 evyd13/eon40 evyd13/eon95 horizon ploopyco/madromys/rev1_001 ploopyco/trackball_nano/rev1_001))
	RGBLIGHT_ENABLE = no
	RGB_MATRIX_ENABLE = no
endif

ifeq ($(strip $(KEYBOARD)), $(filter $(KEYBOARD), 3x3macropad))
	RGBLIGHT_ENABLE = yes
	RGB_MATRIX_ENABLE = no
	SRC += rgb/rgb_light.c
endif

ifeq ($(strip $(KEYBOARD)), $(filter $(KEYBOARD), endgame/rev6))
	RGBLIGHT_ENABLE = no
	RGB_MATRIX_ENABLE = yes
	SRC += rgb/rgb_matrix_endgame.c
endif

ifeq ($(strip $(KEYBOARD)), $(filter $(KEYBOARD), kprepublic/bm60hsrgb_iso/rev1 splitkb/aurora/corne/rev1 splitkb/aurora/helix/rev1))
	RGBLIGHT_ENABLE = no
	RGB_MATRIX_ENABLE = yes
	SRC += rgb/rgb_matrix.c
endif

# Mouse Keys ----------------------------------------------
ifeq ($(strip $(KEYBOARD)), $(filter $(KEYBOARD), 3x3macropad kprepublic/bm60hsrgb_iso/rev1 ploopyco/trackball_nano/rev1_001))
	MOUSEKEY_ENABLE = no
endif

ifeq ($(strip $(KEYBOARD)), $(filter $(KEYBOARD), dasbob endgame/rev6 evyd13/eon40 evyd13/eon95 horizon ploopyco/madromys/rev1_001 re_gret splitkb/aurora/corne/rev1 splitkb/aurora/helix/rev1))
	MOUSEKEY_ENABLE = yes
endif


# Deferred Executo ----------------------------------------
ifeq ($(strip $(KEYBOARD)), $(filter $(KEYBOARD), 3x3macropad dasbob endgame/rev6 evyd13/eon40 evyd13/eon95 horizon kprepublic/bm60hsrgb_iso/rev1 ploopyco/madromys/rev1_001 ploopyco/trackball_nano/rev1_001 re_gret splitkb/aurora/corne/rev1 splitkb/aurora/helix/rev1))
	DEFERRED_EXEC_ENABLE = no
endif

ifeq ($(strip $(KEYBOARD)), $(filter $(KEYBOARD), ))
	DEFERRED_EXEC_ENABLE = yes
endif

# WPM -----------------------------------------------------
ifeq ($(strip $(KEYBOARD)), $(filter $(KEYBOARD), 3x3macropad dasbob endgame/rev6 evyd13/eon40 evyd13/eon95 horizon kprepublic/bm60hsrgb_iso/rev1 ploopyco/madromys/rev1_001 ploopyco/trackball_nano/rev1_001 re_gret))
	WPM_ENABLE = no
endif

ifeq ($(strip $(KEYBOARD)), $(filter $(KEYBOARD), splitkb/aurora/corne/rev1 splitkb/aurora/helix/rev1))
	WPM_ENABLE = yes
endif

# Caps Word -----------------------------------------------
ifeq ($(strip $(KEYBOARD)), $(filter $(KEYBOARD), 3x3macropad kprepublic/bm60hsrgb_iso/rev1 ploopyco/madromys/rev1_001 ploopyco/trackball_nano/rev1_001))
	CAPS_WORD_ENABLE = no 
endif

ifeq ($(strip $(KEYBOARD)), $(filter $(KEYBOARD), dasbob endgame/rev6 evyd13/eon40 evyd13/eon95 horizon re_gret splitkb/aurora/corne/rev1 splitkb/aurora/helix/rev1))
	CAPS_WORD_ENABLE = yes
endif

# Auto Shift -----------------------------------------------
ifeq ($(strip $(KEYBOARD)), $(filter $(KEYBOARD), 3x3macropad kprepublic/bm60hsrgb_iso/rev1 ploopyco/madromys/rev1_001 ploopyco/trackball_nano/rev1_001))
	AUTO_SHIFT_ENABLE = no 
endif

ifeq ($(strip $(KEYBOARD)), $(filter $(KEYBOARD), dasbob endgame/rev6 evyd13/eon40 evyd13/eon95 horizon re_gret splitkb/aurora/corne/rev1 splitkb/aurora/helix/rev1))
	AUTO_SHIFT_ENABLE = no
endif