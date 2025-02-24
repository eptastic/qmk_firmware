/* Copyright 2022 Thomas Baart <thomas@splitkb.com>
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

#pragma once

#ifdef RGBLIGHT_ENABLE
#    define RGBLIGHT_ANIMATIONS
#    define RGBLIGHT_HUE_STEP  8
#    define RGBLIGHT_SAT_STEP  8
#    define RGBLIGHT_VAL_STEP  8
#    define RGBLIGHT_LIMIT_VAL 150
#endif




// Lets you roll mod-tap keys
//#define IGNORE_MOD_TAP_INTERRUPT - not required anymore

// EC11K encoders have a different resolution than other EC11 encoders.
// When using the default resolution of 4, if you notice your encoder skipping
#define ENCODER_RESOLUTION 2
#define ENCODER_RESOLUTION_RIGHT 8


// The Leader key allows to flexibly assign macros to key sequences.
#define LEADER_PER_KEY_TIMING
#define LEADER_TIMEOUT 350

#define TAPPING_TERM 200


// Allows media codes to properly register in macros and rotary encoder code
#define TAP_CODE_DELAY 10

// Auto Shift Configuration, enabled only on Num keys
#define AUTO_SHIFT_TIMEOUT 150
#define NO_AUTO_SHIFT_ALPHA
#define NO_AUTO_SHIFT_SPECIAL

/* Charybdis-specific features. */

#ifdef POINTING_DEVICE_ENABLE
// Automatically enable the pointer layer when moving the trackball.  See also:
// - `CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS`
// - `CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD`
// #define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
#endif // POINTING_DEVICE_ENABLE

