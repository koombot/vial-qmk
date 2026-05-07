// Copyright 2024 Ryan Neff (@JellyTitan)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

void keyboard_post_init_user(void) {
    if (!(host_keyboard_led_state().num_lock)) {
        tap_code(KC_NUM_LOCK);
    }
}

enum sofle_layers {
    _QWERTY,
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

//const uint16_t PROGMEM caps_word_combo[] = {MT(MOD_LSFT, KC_F), MT(MOD_RSFT, KC_J), COMBO_END};

// combo_t key_combos[] = {
//     COMBO(caps_word_combo, CW_TOGG),
// };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // clang-format off
    [_QWERTY] = LAYOUT(
        KC_GRV,  KC_1,            KC_2,            KC_3,             KC_4,             KC_5,                        KC_6,    KC_7,             KC_8,             KC_9,             KC_0,             KC_GRV,
        QK_GESC, KC_Q,            KC_W,            KC_E,             KC_R,             KC_T,                        KC_Y,    KC_U,             KC_I,             KC_O,             KC_P,             KC_BSPC,
        KC_TAB,  LGUI_T(KC_A),    LALT_T(KC_S),    LCTL_T(KC_D),     LSFT_T(KC_F),     KC_G,                        KC_H,    RSFT_T(KC_J),     RCTL_T(KC_K),     RALT_T(KC_L),     RGUI_T(KC_SCLN),  KC_QUOT,
        KC_LSFT, KC_Z,            KC_X,            KC_C,             KC_V,             KC_B,    KC_MUTE,   XXXXXXX,  KC_N,    KC_M,             KC_COMM,          KC_DOT,           KC_SLSH,          KC_RSFT,
                                  KC_LGUI,         KC_LALT,          KC_LCTL,          TL_LOWR, KC_ENT,    KC_SPC,   TL_UPPR, KC_RCTL,          KC_RALT,          KC_RGUI
    ),
    [_LOWER] = LAYOUT(
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_F12,
        _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                     KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE,
        _______, KC_EQL,  KC_MINS, KC_PLUS, KC_LCBR, KC_RCBR, _______,  _______, KC_LBRC, KC_RBRC, KC_SCLN, KC_COLN, KC_BSLS, _______,
                          _______, _______, _______, _______, _______,              _______, _______, _______, _______, _______
    ),
    [_RAISE] = LAYOUT(
        _______, ALT_18, ALT_14, ALT_38, ALT_12, ALT_58,                        ALT_34, ALT_78, ALT_DEG, ALT_SQ2, ALT_SQ3, _______,
        _______, KC_INS,  KC_PSCR, KC_APP,  XXXXXXX, XXXXXXX,                                  KC_PGUP, XXXXXXX, KC_UP,   XXXXXXX, XXXXXXX, KC_BSPC,
        _______, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX, KC_CAPS,                                  KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_DEL,  KC_BSPC,
        _______, C(KC_Z), C(KC_X), C(KC_C), C(KC_V), XXXXXXX, _______,        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
                                  _______, _______, _______, _______, _______,        _______, _______, _______, _______, _______
    ),
    [_ADJUST] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                XXXXXXX, KC_NUM_LOCK, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, CG_TOGG, XXXXXXX,                                RM_TOGG, KC_KP_7, KC_KP_8, KC_KP_9, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, CG_TOGG, XXXXXXX, XXXXXXX, XXXXXXX,                                RM_NEXT, KC_KP_4, KC_KP_5, KC_KP_6, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX, XXXXXXX, KC_KP_1, KC_KP_2, KC_KP_3, XXXXXXX, XXXXXXX,
                                  _______, _______, _______, _______, _______,      _______, _______, KC_KP_0, _______, _______
    )
    // clang-format on
};

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

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_PGDN, KC_PGUP)},
    [1] = {ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(LWIN(LCTL(KC_LEFT)), LWIN(LCTL(KC_RGHT)))},
    [2] = {ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______)},
    [3] = {ENCODER_CCW_CW(RGB_VAD, RGB_VAI), ENCODER_CCW_CW(RGB_RMOD, RGB_MOD)},
};
#endif
