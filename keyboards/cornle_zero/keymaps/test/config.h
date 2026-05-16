#pragma once

#define ST7735
#define LCD_WIDTH 80
#define LCD_HEIGHT 160
#define SPI_MODE 0

// 160x80 ST7735 modules often need explicit offsets for the physical panel.
#undef LCD_OFFSET_X
#define LCD_OFFSET_X 1
#undef LCD_OFFSET_Y
#define LCD_OFFSET_Y 26
#define ST7735_NO_AUTOMATIC_VIEWPORT_OFFSETS

#undef LCD_ROTATION
#define LCD_ROTATION QP_ROTATION_90

// If you add a QGF test image, define the image symbol here, e.g.:
// #define gfx_cat gfx_cat160x80
