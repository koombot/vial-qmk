/* Copyright 2020 Paul James
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

#include QMK_KEYBOARD_H

void keyboard_post_init_user(void) {
    if (!(host_keyboard_led_state().num_lock)) {
        tap_code(KC_NUM_LOCK);
    }
}


enum layers {
  _QWERTY = 0,
  _LOWER,
  _RAISE,
  _ADJUST,
};

enum custom_keycodes {
    ALT_18 = SAFE_RANGE, //
    ALT_14,
    ALT_38,
    ALT_12,
    ALT_58,
    ALT_34,
    ALT_78,
    ALT_DEG,
    ALT_SQ2,
    ALT_SQ3,
};

//#define FN MO(_FUNCTION)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------. ,-----------------------------------------.
 * |   `  |  1   |  2   |  3   |  4   |  5   | |  6   |  7   |  8   |  9   |  0   |  -   |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * | Tab  |  Q   |  W   |  E   |  R   |  T   | |  Y   |  U   |  I   |  O   |  P   |BKSPC |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * | Esc  |  A   |  S   |  D   |  F   |  G   | |  H   |  J   |  K   |  L   |  ;   |  '   |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |  #   |  Z   |  X   |  C   |  V   |  B   | |  N   |  M   |  ,   |  .   |  /   |  \   |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * | Ctrl |  Alt | Cmd  | Lwr  |  (Lwr)Entr  | |  (Uppr)Spac | Uppr | Cmd  |  Alt | Ctrl |
 * `-----------------------------------------' `-----------------------------------------'
 */
[_QWERTY] = LAYOUT_ortho_5x12(
    KC_GRV,        KC_1,         KC_2,            KC_3,          KC_4,         KC_5,            KC_6,               KC_7,         KC_8,         KC_9,         KC_0,            KC_MINS,
    KC_TAB,        KC_Q,         KC_W,            KC_E,          KC_R,         KC_T,            KC_Y,               KC_U,         KC_I,         KC_O,         KC_P,            KC_BSPC,
    KC_ESC,        KC_A,         KC_S,            KC_D,          LSFT_T(KC_F), KC_G,            KC_H,               RSFT_T(KC_J), KC_K,         KC_L,         KC_SCLN, KC_QUOT,
    KC_NONUS_HASH, KC_Z,         KC_X,            KC_C,          KC_V,         KC_B,            KC_N,               KC_M,         KC_COMM,      KC_DOT,       KC_SLSH,         KC_BSLS,
    KC_LCTL,       KC_LALT,      KC_LGUI,         TL_LOWR,       TL_LOWR,      LT(_LOWER,KC_ENT),          LT(_RAISE,KC_SPC), TL_UPPR,      TL_UPPR,      KC_LGUI,      KC_LALT,           KC_LCTL
),

/* Lower
* ,------------------------------------------. ,-----------------------------------------.
 * |   -  |  1/8 |  1/4 | 3/8  | 1/2  | 5/8  | | 3/4  | 7/8  |  ^o  |  ^2  |  ^3  | ---  |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * | Spac |   1  |   2  |   3  |   4  |   5  | |   6  |   7  |   8  |   9  |   0  | ---  |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * | Del  |   !  |  @   |   #  |   $  |   %  | |   ^  |   &  |   *  |   (  |   )  |  |   |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * | ---  |   =  |   -  |  +   |   {  |   }  | |  [   |   ]  |   ;  |   :  |   \  | ---  |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |  --- |  --- |  --- |  --- |     ---     | |             | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------' `-----------------------------------------'
 */
[_LOWER] = LAYOUT_ortho_5x12(
    LSFT_T(KC_MINS), ALT_18,  ALT_14,  ALT_38,  ALT_12,  ALT_58,          ALT_34,  ALT_78,  ALT_DEG, ALT_SQ2, ALT_SQ3, _______,
    KC_SPC,          KC_1,    KC_2,    KC_3,    KC_4,    KC_5,            KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
    KC_DEL,          KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,         KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE,
    _______,         KC_EQL,  KC_MINS, KC_PLUS, KC_LCBR, KC_RCBR,         KC_LBRC, KC_RBRC, KC_SCLN, KC_COLN, KC_BSLS, _______,
    _______,         _______, _______, _______, _______, _______,         _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
),

/* Raise
* ,------------------------------------------. ,-----------------------------------------.
 * |   -  |      |      |      |      |      | | CALC | NmLk |   /  |   *  |   -  |      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |   `  |      |  up  |      |      |      | |  Del |   7  |   8  |   9  |   +  | BKSP |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * | Del  | left | down | rght |      |      | |      |   4  |   5  |   6  |   ,  |      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * | cplk | undo | cut  | copy | pste |      | |      |   1  |   2  |   3  |      |      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |      |      |             | |         0   |  .   |      |      |      |
 * `-----------------------------------------' `-----------------------------------------'
 */
[_RAISE] = LAYOUT_ortho_5x12(
    XXXXXXX, XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX, XXXXXXX,         KC_CALC, KC_NUM_LOCK, KC_KP_SLASH, KC_KP_ASTERISK, KC_KP_MINUS, _______,
    KC_GRV,  XXXXXXX,   KC_UP,     XXXXXXX,   XXXXXXX, XXXXXXX,         KC_DEL,  KC_KP_7,     KC_KP_8,     KC_KP_9,        KC_KP_PLUS,  _______,
    KC_DEL,  KC_LEFT,   KC_DOWN,   KC_RIGHT,  XXXXXXX, XXXXXXX,         XXXXXXX, KC_KP_4,     KC_KP_5,     KC_KP_6,        KC_KP_COMMA, XXXXXXX,
    KC_CAPS_LOCK, C(KC_Z),   C(KC_X),   C(KC_C),   C(KC_V), XXXXXXX,         XXXXXXX, KC_KP_1,     KC_KP_2,     KC_KP_3,        KC_KP_ENTER, _______,
    _______, _______,   _______,   _______,   _______, _______,         _______, _______,     KC_KP_0,     KC_KP_DOT,      XXXXXXX,     XXXXXXX
),

/* Adjust
* ,------------------------------------------. ,-----------------------------------------.
 * |   -  |  F1  |  F2  |  F3  |  F4  |  F5  | |  F6  |  F7  |  F8  |  F9  |  F10 | F11  |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |      |      |      |      | |      |      |      |      |      |  F12 |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  | |  F6  |      |      |      |      |      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 | |  F12 |ISO # |ISO / |      |      |      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |      |      |             | |             | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------' `-----------------------------------------'
 */
[_ADJUST] = LAYOUT_ortho_5x12(
    XXXXXXX, KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,          KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,    KC_F11,
    _______,  _______,    _______,    _______,    _______,    _______,          _______,    _______,    _______,    _______,    _______,    KC_F12,
    _______,  _______,   _______,   _______,   _______,   _______,         _______,   _______, _______,  _______, _______, _______,
    _______, _______,   _______,   _______,   _______,  _______,        _______,  KC_NUHS, KC_NUBS, KC_PGUP, KC_PGDN, _______,
    _______, _______, _______, _______, _______, _______,       _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
),

};

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case ALT_18:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT(SS_TAP(X_KP_8) SS_TAP(X_KP_5) SS_TAP(X_KP_3) SS_TAP(X_KP_9)));
            }
            break;
        case ALT_14:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_8) SS_TAP(X_KP_8)));
            }
            break;
        case ALT_38:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT(SS_TAP(X_KP_8) SS_TAP(X_KP_5) SS_TAP(X_KP_4) SS_TAP(X_KP_0)));
            }
            break;
        case ALT_12:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_8) SS_TAP(X_KP_9)));
            }
            break;
        case ALT_58:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT(SS_TAP(X_KP_8) SS_TAP(X_KP_5) SS_TAP(X_KP_4) SS_TAP(X_KP_1)));
            }
            break;
        case ALT_34:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_9) SS_TAP(X_KP_0)));
            }
            break;
        case ALT_78:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT(SS_TAP(X_KP_8) SS_TAP(X_KP_5) SS_TAP(X_KP_4) SS_TAP(X_KP_2)));
            }
            break;
        case ALT_DEG:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_7) SS_TAP(X_KP_6)));
            }
            break;
        case ALT_SQ2:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_7) SS_TAP(X_KP_8)));
            }
            break;
        case ALT_SQ3:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_7) SS_TAP(X_KP_9)));
            }
            break;
    }
    return true;
}
