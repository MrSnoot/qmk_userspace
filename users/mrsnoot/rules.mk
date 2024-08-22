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

# Common features -----------------------------------------
ifeq ($(strip $(KEYBOARD)), $(filter $(KEYBOARD), dasbob evyd13/eon40 evyd13/eon95 horizon kprepublic/bm60hsrgb_iso/rev1 ploopyco/madromys/rev1_001 ploopyco/trackball_nano/rev1_001 splitkb/aurora/corne/rev1 splitkb/aurora/helix/rev1))
	EXTRAKEY_ENABLE = no
endif

ifeq ($(strip $(KEYBOARD)), $(filter $(KEYBOARD), 3x3macropad))
	EXTRAKEY_ENABLE = yes
endif

# Split Boards --------------------------------------------

# Audio ---------------------------------------------------
ifeq ($(strip $(KEYBOARD)), $(filter $(KEYBOARD), 3x3macropad evyd13/eon40 evyd13/eon95 kprepublic/bm60hsrgb_iso/rev1 ploopyco/trackball_nano/rev1_001))
	AUDIO_ENABLE = no
endif

ifeq ($(strip $(KEYBOARD)), $(filter $(KEYBOARD), dasbob horizon ploopyco/madromys/rev1_001 splitkb/aurora/corne/rev1 splitkb/aurora/helix/rev1))
	AUDIO_ENABLE = yes
	AUDIO_DRIVER = pwm_hardware
endif

# Combos --------------------------------------------------
ifeq ($(strip $(KEYBOARD)), $(filter $(KEYBOARD), 3x3macropad kprepublic/bm60hsrgb_iso/rev1 ploopyco/madromys/rev1_001 ploopyco/trackball_nano/rev1_001))
	COMBO_ENABLE = no
endif

ifeq ($(strip $(KEYBOARD)), $(filter $(KEYBOARD), dasbob evyd13/eon40 evyd13/eon95 horizon splitkb/aurora/corne/rev1 splitkb/aurora/helix/rev1))
	COMBO_ENABLE = yes
	INTROSPECTION_KEYMAP_C = $(USER_PATH)/combo/combo.c
endif

# Encoder -------------------------------------------------
ifeq ($(strip $(KEYBOARD)), $(filter $(KEYBOARD), dasbob evyd13/eon40 evyd13/eon95 horizon kprepublic/bm60hsrgb_iso/rev1 ploopyco/madromys/rev1_001 ploopyco/trackball_nano/rev1_001))
	ENCODER_ENABLE = no
endif

ifeq ($(strip $(KEYBOARD)), $(filter $(KEYBOARD), 3x3macropad))
	ENCODER_ENABLE = yes
	SRC += $(USER_PATH)/encoder/encoder_3x3macropad.c
endif

ifeq ($(strip $(KEYBOARD)), $(filter $(KEYBOARD), splitkb/aurora/corne/rev1 splitkb/aurora/helix/rev1))
	ENCODER_ENABLE = yes
	SRC += $(USER_PATH)/encoder/encoder_split.c
endif

# OLED ----------------------------------------------------
ifeq ($(strip $(KEYBOARD)), $(filter $(KEYBOARD), dasbob evyd13/eon40 evyd13/eon95 horizon kprepublic/bm60hsrgb_iso/rev1 ploopyco/madromys/rev1_001 ploopyco/trackball_nano/rev1_001))
	OLED_ENABLE = no
endif

ifeq ($(strip $(KEYBOARD)), $(filter $(KEYBOARD), 3x3macropad))
	OLED_ENABLE = yes
	SRC += $(USER_PATH)/oled/oled_128_32_3x3macropad.c
endif

ifeq ($(strip $(KEYBOARD)), $(filter $(KEYBOARD), splitkb/aurora/corne/rev1 splitkb/aurora/helix/rev1))
	OLED_ENABLE = yes
	SRC += $(USER_PATH)/oled/oled_128_32_split.c
endif

ifeq ($(strip $(KEYBOARD)), $(filter $(KEYBOARD), xxx))
	OLED_ENABLE = yes
	SRC += $(USER_PATH)/oled/oled_128_64_split.c
endif

# RGB -----------------------------------------------------
ifeq ($(strip $(KEYBOARD)), $(filter $(KEYBOARD), dasbob evyd13/eon40 evyd13/eon95 horizon ploopyco/madromys/rev1_001 ploopyco/trackball_nano/rev1_001))
	RGBLIGHT_ENABLE = no
	RGB_MATRIX_ENABLE = no
endif

ifeq ($(strip $(KEYBOARD)), $(filter $(KEYBOARD), 3x3macropad))
	RGBLIGHT_ENABLE = yes
	RGB_MATRIX_ENABLE = no
	SRC += $(USER_PATH)/rgb/rgb_light.c
endif

ifeq ($(strip $(KEYBOARD)), $(filter $(KEYBOARD), kprepublic/bm60hsrgb_iso/rev1 splitkb/aurora/corne/rev1 splitkb/aurora/helix/rev1))
	RGBLIGHT_ENABLE = no
	RGB_MATRIX_ENABLE = yes
	SRC += $(USER_PATH)/rgb/rgb_matrix.c
endif

# Mouse Keys ----------------------------------------------
ifeq ($(strip $(KEYBOARD)), $(filter $(KEYBOARD), 3x3macropad kprepublic/bm60hsrgb_iso/rev1 ploopyco/trackball_nano/rev1_001))
	MOUSEKEY_ENABLE = no
endif

ifeq ($(strip $(KEYBOARD)), $(filter $(KEYBOARD), dasbob evyd13/eon40 evyd13/eon95 horizon ploopyco/madromys/rev1_001 splitkb/aurora/corne/rev1 splitkb/aurora/helix/rev1))
	MOUSEKEY_ENABLE = yes
endif

# WPM -----------------------------------------------------
ifeq ($(strip $(KEYBOARD)), $(filter $(KEYBOARD), 3x3macropad dasbob evyd13/eon40 evyd13/eon95 horizon kprepublic/bm60hsrgb_iso/rev1 ploopyco/madromys/rev1_001 ploopyco/trackball_nano/rev1_001))
	WPM_ENABLE = no
endif

ifeq ($(strip $(KEYBOARD)), $(filter $(KEYBOARD), splitkb/aurora/corne/rev1 splitkb/aurora/helix/rev1))
	WPM_ENABLE = yes
endif

# Caps Word -----------------------------------------------
ifeq ($(strip $(KEYBOARD)), $(filter $(KEYBOARD), 3x3macropad kprepublic/bm60hsrgb_iso/rev1 ploopyco/madromys/rev1_001 ploopyco/trackball_nano/rev1_001))
	CAPS_WORD_ENABLE = no 
endif

ifeq ($(strip $(KEYBOARD)), $(filter $(KEYBOARD), dasbob evyd13/eon40 evyd13/eon95 horizon splitkb/aurora/corne/rev1 splitkb/aurora/helix/rev1))
	CAPS_WORD_ENABLE = yes
endif

# Auto Shift -----------------------------------------------
ifeq ($(strip $(KEYBOARD)), $(filter $(KEYBOARD), 3x3macropad kprepublic/bm60hsrgb_iso/rev1 ploopyco/madromys/rev1_001 ploopyco/trackball_nano/rev1_001))
	AUTO_SHIFT_ENABLE = no 
endif

ifeq ($(strip $(KEYBOARD)), $(filter $(KEYBOARD), dasbob evyd13/eon40 evyd13/eon95 horizon splitkb/aurora/corne/rev1 splitkb/aurora/helix/rev1))
	AUTO_SHIFT_ENABLE = no
endif