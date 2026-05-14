#define LCD_WIDTH 80
#define LCD_HEIGHT 160
#define SPI_MODE 0
#define ST7735
#define gfx_cat gfx_cat160x80

// 160x80 ST7735 modules need these offsets to align the controller address
// space to the physical panel (see jpe230/big_knob for reference config)
#undef LCD_OFFSET_X
#define LCD_OFFSET_X 1
#undef LCD_OFFSET_Y
#define LCD_OFFSET_Y 26
#define ST7735_NO_AUTOMATIC_VIEWPORT_OFFSETS
#define LCD_INVERT_COLOR

// 270 rotation matches the big_knob reference; change to 90 if image is mirrored
#undef LCD_ROTATION
#define LCD_ROTATION QP_ROTATION_90
