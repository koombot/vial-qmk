#include QMK_KEYBOARD_H

#ifdef QUANTUM_PAINTER_ENABLE
#include "qp.h"
#include "qp_st7735.h"

static painter_device_t oled;

static void draw_test_pattern(void) {
    qp_rect(oled, 0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1, 0, 0, 0, true);
    qp_rect(oled, 4, 4, LCD_WIDTH - 5, LCD_HEIGHT - 5, 42, 180, 120, true);
    qp_flush(oled);
}

__attribute__((weak)) void ui_init(void) {
    oled = qp_st7735_make_spi_device(LCD_WIDTH, LCD_HEIGHT, LCD_CS_PIN, LCD_DC_PIN, LCD_RST_PIN, LCD_SPI_DIVISOR, SPI_MODE);
    if (!qp_init(oled, LCD_ROTATION)) {
        return;
    }
    draw_test_pattern();
}

void keyboard_post_init_kb(void) {
    ui_init();
    keyboard_post_init_user();
}
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_split_3x6_3(
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                               KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                                            KC_LGUI, KC_BSPC, KC_SPC,           KC_SPC,  KC_ENT,  KC_RALT
    )
};
