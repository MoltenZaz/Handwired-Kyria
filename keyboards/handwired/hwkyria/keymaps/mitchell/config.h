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

// place overrides here
#define USB_POLLING_INTERVAL_MS 1
#define QMK_KEYS_PER_SCAN 24
#define FORCE_NKRO
// #define TAPPING_TOGGLE 1
#define LCPO_KEYS KC_LCTL, KC_LSFT, KC_LBRC
#define RCPC_KEYS KC_RCTL, KC_RSFT, KC_RBRC
#define LAPO_KEYS KC_LALT, KC_TRNS, KC_LBRC
#define RAPC_KEYS KC_RALT, KC_TRNS, KC_RBRC
#define LAYER_STATE_32BIT

#define UNICODE_SELECTED_MODES UNICODE_MODE_WINDOWS, UNICODE_MODE_LINUX
#define UNICODE_KEY_WINC KC_PAUSE

#define TAPPING_TERM 200
#define QUICK_TAP_TERM 0
// #define PERMISSIVE_HOLD
#define HOLD_ON_OTHER_KEY_PRESS
// #define HOLD_ON_OTHER_KEY_PRESS_PER_KEY
#define TAP_CODE_DELAY 30

#define TRI_LAYER_LOWER_LAYER 3
#define TRI_LAYER_UPPER_LAYER 5
#define TRI_LAYER_ADJUST_LAYER 6

// #define MOUSEKEY_INTERVAL 16

// #define MOUSEKEY_DELAY 0

// #define MOUSEKEY_TIME_TO_MAX 60

// #define MOUSEKEY_MAX_SPEED 5

// #define MOUSEKEY_WHEEL_DELAY 0

// #define MK_3_SPEED
// #define MK_MOMENTARY_ACCEL

// #undef MOUSEKEY_DELAY
// #define MOUSEKEY_DELAY          0
// #undef MOUSEKEY_INTERVAL
// #define MOUSEKEY_INTERVAL       16
// #undef MOUSEKEY_WHEEL_DELAY
// #define MOUSEKEY_WHEEL_DELAY    0
// #undef MOUSEKEY_MAX_SPEED
// #define MOUSEKEY_MAX_SPEED      6
// #undef MOUSEKEY_TIME_TO_MAX
// #define MOUSEKEY_TIME_TO_MAX    64

#define MK_KINETIC_SPEED
#define MOUSEKEY_DELAY							5
#define MOUSEKEY_INTERVAL						8
#define MOUSEKEY_MOVE_DELTA						16
#define MOUSEKEY_INITIAL_SPEED					100
#define MOUSEKEY_BASE_SPEED						5000
#define MOUSEKEY_DECELERATED_SPEED				400
#define MOUSEKEY_ACCELERATED_SPEED				3000
#define MOUSEKEY_WHEEL_INITIAL_MOVEMENTS		8
#define MOUSEKEY_WHEEL_BASE_MOVEMENTS			16
#define MOUSEKEY_WHEEL_ACCELERATED_MOVEMENTS	48
#define MOUSEKEY_WHEEL_DECELERATED_MOVEMENTS	8

// #define BOTH_SHIFTS_TURNS_ON_CAPS_WORD
// #define CAPS_WORD_INVERT_ON_SHIFT
// #define CAPS_WORD_IDLE_TIMEOUT 5000