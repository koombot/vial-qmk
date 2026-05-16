#pragma once

/* SPI configuration for the RP2040 controller */
#define SPI_DRIVER SPID0
#define SPI_SCK_PIN GP6
#define SPI_MOSI_PIN GP7
#define SPI_MISO_PIN GP20 // unused for the ST7735 display

/* LCD pins */
#define LCD_RST_PIN GP8
#define LCD_DC_PIN  GP9
#define LCD_CS_PIN  GP5
#define LCD_SPI_DIVISOR 4
#define LCD_WAIT_TIME 150

/* Quantum Painter configuration */
#define QUANTUM_PAINTER_SUPPORTS_NATIVE_COLORS TRUE
#define QUANTUM_PAINTER_DISPLAY_TIMEOUT 0
