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
  _GAME,
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
 * |   =  |  1   |  2   |  3   |  4   |  5   | |  6   |  7   |  8   |  9   |  0   |  -   |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * | Tab  |  Q   |  W   |  E   |  R   |  T   | |  Y   |  U   |  I   |  O   |  P   |BKSPC |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * | Esc  |  A   |  S   |  D   |  F   |  G   | |  H   |  J   |  K   |  L   |  ;   |  '   |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |  #   |  Z   |  X   |  C   |  V   |  B   | |  N   |  M   |  ,   |  .   |  /   |  \   |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * | Ctrl |  Alt | Cmd  | Lwr  |  (Lwr)Entr  | |  (Uppr)Spac | Left | Dwn  |  Up  | Rght |
 * `-----------------------------------------' `-----------------------------------------'
 */
[_QWERTY] = LAYOUT_ortho_5x12(
    KC_EQUAL,        KC_1,         KC_2,            KC_3,          KC_4,         KC_5,            KC_6,               KC_7,         KC_8,         KC_9,         KC_0,            KC_MINS,
    KC_TAB,        KC_Q,         KC_W,            KC_E,          KC_R,         KC_T,            KC_Y,               KC_U,         KC_I,         KC_O,         KC_P,            KC_BSPC,
    KC_ESC,        KC_A,         KC_S,            KC_D,          LSFT_T(KC_F), KC_G,            KC_H,               RSFT_T(KC_J), KC_K,         KC_L,         KC_SCLN, KC_QUOT,
    KC_NONUS_HASH, KC_Z,         KC_X,            KC_C,          KC_V,         KC_B,            KC_N,               KC_M,         KC_COMM,      KC_DOT,       KC_SLSH,         KC_BSLS,
    KC_LCTL,       KC_LALT,      KC_LGUI,         KC_MYCM,       TL_LOWR,      LT(_LOWER,KC_ENT),          LT(_RAISE,KC_SPC), TL_UPPR,      KC_LEFT,      KC_DOWN,      KC_UP,           KC_RIGHT
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

/* Game
 * Same as Qwerty, but Space and Enter swap thumb positions (Space on the left).
 * Toggled on/off by holding the top-left and top-right keys (` and -) together.
 * ,-----------------------------------------. ,-----------------------------------------.
 * |   `  |  1   |  2   |  3   |  4   |  5   | |  6   |  7   |  8   |  9   |  0   |  -   |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * | Tab  |  Q   |  W   |  E   |  R   |  T   | |  Y   |  U   |  I   |  O   |  P   |BKSPC |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * | Esc  |  A   |  S   |  D   |  F   |  G   | |  H   |  J   |  K   |  L   |  ;   |  '   |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |  #   |  Z   |  X   |  C   |  V   |  B   | |  N   |  M   |  ,   |  .   |  /   |  \   |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * | Ctrl |  Alt | Cmd  | Lwr  |    Spac     | |     Entr    | Uppr | Cmd  |  Alt | Ctrl |
 * `-----------------------------------------' `-----------------------------------------'
 */
[_GAME] = LAYOUT_ortho_5x12(
    KC_GRV,        KC_1,         KC_2,            KC_3,          KC_4,         KC_5,            KC_6,   KC_7,         KC_8,         KC_9,         KC_0, KC_MINS,
    KC_TAB,        KC_Q,         KC_W,            KC_E,          KC_R,         KC_T,            KC_Y,   KC_U,         KC_I,         KC_O,         KC_P, KC_BSPC,
    KC_ESC,        KC_A,         KC_S,            KC_D,          LSFT_T(KC_F), KC_G,            KC_H,   RSFT_T(KC_J), KC_K,         KC_L,         KC_SCLN, KC_QUOT,
    KC_NONUS_HASH, KC_Z,         KC_X,            KC_C,          KC_V,         KC_B,            KC_N,   KC_M,         KC_COMM,      KC_DOT,       KC_SLSH, KC_BSLS,
    KC_LCTL,       KC_LALT,      KC_LGUI,         TL_LOWR,       TL_LOWR,      KC_SPC,          KC_ENT, TL_UPPR,      TL_UPPR,      KC_LGUI,      KC_LALT, KC_LCTL
),

};

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

// Corner-key chord (top-left = + top-right -) toggles the _GAME layer.
// Implemented by hand rather than QMK's Combo feature: with VIAL_ENABLE on,
// enabling COMBO_ENABLE hands combo storage over to Vial's dynamic (EEPROM
// backed) combo system, which is too costly on this chip's 1KB EEPROM.
#define CORNER_CHORD_TERM 50

typedef enum {
    CORNER_IDLE,
    CORNER_PENDING,
    CORNER_HELD,
} corner_key_state_t;

typedef struct {
    corner_key_state_t state;
    deferred_token      token;
    uint16_t             keycode;
    uint16_t             held_keycode; // actual keycode registered while state == CORNER_HELD
} corner_key_t;

static corner_key_t corner_tl = {CORNER_IDLE, INVALID_DEFERRED_TOKEN, KC_EQUAL, KC_NO};
static corner_key_t corner_tr = {CORNER_IDLE, INVALID_DEFERRED_TOKEN, KC_MINS, KC_NO};

// This bypasses process_caps_word() (see process_record_user() below), so Caps
// Word's usual "-" -> "_" substitution has to be applied manually here.
static uint16_t corner_key_output(uint16_t keycode) {
    return (keycode == KC_MINS && is_caps_word_on()) ? KC_UNDS : keycode;
}

static uint32_t corner_key_resolve(uint32_t trigger_time, void *cb_arg) {
    corner_key_t *self = (corner_key_t *)cb_arg;
    self->state        = CORNER_HELD;
    self->held_keycode = corner_key_output(self->keycode);
    register_code16(self->held_keycode);
    return 0;
}

// `keycode` is whatever the active layer actually sent for this corner (e.g.
// KC_EQUAL on _QWERTY vs. KC_GRV on _GAME), so a plain tap/hold echoes the
// right character on either layer.
static void corner_key_press(corner_key_t *self, corner_key_t *other, uint16_t keycode) {
    if (other->state == CORNER_PENDING) {
        cancel_deferred_exec(other->token);
        other->state = CORNER_IDLE;
        layer_invert(_GAME);
        return;
    }
    self->keycode = keycode;
    self->state   = CORNER_PENDING;
    self->token   = defer_exec(CORNER_CHORD_TERM, corner_key_resolve, self);
}

static void corner_key_release(corner_key_t *self) {
    switch (self->state) {
        case CORNER_PENDING:
            cancel_deferred_exec(self->token);
            self->state = CORNER_IDLE;
            tap_code16(corner_key_output(self->keycode));
            break;
        case CORNER_HELD:
            unregister_code16(self->held_keycode);
            self->state = CORNER_IDLE;
            break;
        case CORNER_IDLE:
            break;
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_GRV:
        case KC_EQUAL:
            if (record->event.pressed) {
                corner_key_press(&corner_tl, &corner_tr, keycode);
            } else {
                corner_key_release(&corner_tl);
            }
            return false;
        case KC_MINS:
            if (record->event.pressed) {
                corner_key_press(&corner_tr, &corner_tl, keycode);
            } else {
                corner_key_release(&corner_tr);
            }
            return false;
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

// LED1/LED2 are plain GPIO pins (no hardware PWM), so fading is faked with a
// cheap software PWM: each scan, the pin is on for the first `brightness`
// fraction of a ~20ms (50Hz) window and off for the rest.
#define LED_SOFT_PWM_PERIOD_MS 20
#define GAME_CROSSFADE_PERIOD_MS 5000
#define CAPS_WORD_FADE_PERIOD_MS 1000

// Triangle wave 0..255..0 over one period.
static uint8_t triangle_wave(uint16_t phase, uint16_t period) {
    uint16_t half = period / 2;
    return phase < half ? (uint32_t)phase * 255 / half : (uint32_t)(period - phase) * 255 / half;
}

static void write_led_soft_pwm(pin_t pin, uint16_t now, uint8_t brightness) {
    uint16_t phase     = now % LED_SOFT_PWM_PERIOD_MS;
    uint16_t threshold = (uint16_t)brightness * LED_SOFT_PWM_PERIOD_MS / 255;
    writePin(pin, phase < threshold);
}

void matrix_scan_user(void) {
    uint16_t now = timer_read();
    if (IS_LAYER_ON(_GAME)) {
        uint8_t led1 = triangle_wave(now % GAME_CROSSFADE_PERIOD_MS, GAME_CROSSFADE_PERIOD_MS);
        write_led_soft_pwm(LED1, now, led1);
        write_led_soft_pwm(LED2, now, 255 - led1);
    } else if (is_caps_word_on()) {
        uint8_t led1 = triangle_wave(now % CAPS_WORD_FADE_PERIOD_MS, CAPS_WORD_FADE_PERIOD_MS);
        write_led_soft_pwm(LED1, now, led1);
        writePin(LED2, host_keyboard_led_state().num_lock);
    } else {
        writePin(LED1, host_keyboard_led_state().caps_lock);
        writePin(LED2, host_keyboard_led_state().num_lock);
    }
}
