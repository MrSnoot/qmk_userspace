/* Copyright 2020 QMK
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */
#pragma once

#include_next "mcuconf.h"

// Aurora Corne und Helix mit Helios MCU
#if defined(CONVERT_TO_HELIOS) && defined(KEYBOARD_splitkb_aurora_corne_rev1)
#    undef  RP_PWM_USE_PWM5
#    define RP_PWM_USE_PWM5 TRUE
#endif

// Ploopy Adept
#if defined(KEYBOARD_ploopyco_madromys_rev1_001)
#    undef  RP_PWM_USE_PWM6
#    define RP_PWM_USE_PWM6 TRUE
#endif

// re_gret
#if defined(KEYBOARD_re_gret)
#    undef  RP_PWM_USE_PWM0
#    define RP_PWM_USE_PWM0 TRUE
#endif