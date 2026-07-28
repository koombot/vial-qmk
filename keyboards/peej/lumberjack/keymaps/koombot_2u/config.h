/* SPDX-License-Identifier: GPL-2.0-or-later */

#pragma once

#define VIAL_KEYBOARD_UID {0xBE, 0x78, 0x4B, 0x49, 0x48, 0xB7, 0xA9, 0x77}

/* this is the left upper and left lower key */
#define VIAL_UNLOCK_COMBO_ROWS { 0, 4 }
#define VIAL_UNLOCK_COMBO_COLS { 0, 0 }

#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD

/* default to "2u Spacebars" layout option on a fresh/reset EEPROM */
#define VIA_EEPROM_LAYOUT_OPTIONS_DEFAULT 0x00000001

/* only the top-left/top-right corner key chord uses deferred execution */
#define MAX_DEFERRED_EXECUTORS 2

/* the _GAME layer brings the layer count to 5, above the default of 4;
 * this grows dynamic keymap EEPROM usage by ~120 bytes (60 keys * 2 bytes) */
#define DYNAMIC_KEYMAP_LAYER_COUNT 5
