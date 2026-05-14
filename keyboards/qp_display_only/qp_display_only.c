// Copyright 2023 OakNinja (@oakninja)
// SPDX-License-Identifier: GPL-2.0-or-later

#include "qp.h"
#include "qp_comms.h"
#include "gpio.h"

#ifdef GC_9A01
#include "qp_gc9a01_opcodes.h"
#include "gfx/cat240x240.qgf.h"
#elif defined(ST7735)
#include "qp_st77xx_opcodes.h"
#include "qp_st7735_opcodes.h"
#include "gfx/cat160x80.qgf.h"
#else
#include "qp_st77xx_opcodes.h"
#include "gfx/cat320x240.qgf.h"
#endif


#include "color.h"
#include "config.h"

painter_device_t lcd;

void keyboard_post_init_kb(void) {
    // Backlight on
    gpio_set_pin_output(LCD_BLK_PIN);
    gpio_write_pin_high(LCD_BLK_PIN);

    //Display timeout
    wait_ms(LCD_WAIT_TIME);

    #ifdef GC_9A01
    lcd = qp_gc9a01_make_spi_device(LCD_WIDTH, LCD_HEIGHT, LCD_CS_PIN, LCD_DC_PIN, LCD_RST_PIN, LCD_SPI_DIVISOR, SPI_MODE);
    #elif defined(ST7735)
    lcd = qp_st7735_make_spi_device(LCD_WIDTH, LCD_HEIGHT, LCD_CS_PIN, LCD_DC_PIN, LCD_RST_PIN, LCD_SPI_DIVISOR, SPI_MODE);
    #else
    lcd = qp_st7789_make_spi_device(LCD_WIDTH, LCD_HEIGHT, LCD_CS_PIN, LCD_DC_PIN, LCD_RST_PIN, LCD_SPI_DIVISOR, SPI_MODE);
    #endif
    qp_init(lcd, LCD_ROTATION);

    // Some screens have inverted colors
    #ifdef LCD_INVERT_COLOR
    qp_comms_start(lcd);
    qp_comms_command(lcd, ST77XX_CMD_INVERT_ON);
    qp_comms_stop(lcd);
    #endif

    // Display offset
    qp_set_viewport_offsets(lcd, LCD_OFFSET_X, LCD_OFFSET_Y);

    // Power on display, fill with white
    qp_power(lcd, 1);
    uint16_t draw_width, draw_height;
    qp_get_geometry(lcd, &draw_width, &draw_height, NULL, NULL, NULL);
    qp_rect(lcd, 0, 0, draw_width - 1, draw_height - 1, 0, 255, 255, true);
    //qp_rect(lcd, 0, 0, LCD_WIDTH, LCD_HEIGHT,HSV_WHITE, 1);

    // Paint catpaste/Katten Paste
    painter_image_handle_t logo_image = qp_load_image_mem(gfx_cat);
    qp_drawimage(lcd, 0, 0, logo_image);

    keyboard_post_init_user();
}
