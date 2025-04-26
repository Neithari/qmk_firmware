/*
Copyright 2023 Spencer Deven <splitlogicdesign@gmail.com>
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.
This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

// Default for VIA is 4
#define DYNAMIC_KEYMAP_LAYER_COUNT 5

// Screen support
#define ST7789_NUM_DEVICES 1
#define LCD_RST_PIN GP27
#define LCD_DC_PIN GP28
#define LCD_CS_PIN GP11
#define LCD_SPI_DIVISOR 8
#define LCD_WAIT_TIME 3000
#define LCD_ROTATION QP_ROTATION_270
#define LCD_OFFSET_X 0
#define LCD_OFFSET_Y 0
#define LCD_WIDTH 320 // Set according to your display specs
#define LCD_HEIGHT 240 // Set according to your display specs
#define SPI_MODE 3 // Set according to your display specs
#define ST7789 // Set according to your display specs
#define QUANTUM_PAINTER_SUPPORTS_NATIVE_COLORS TRUE
#define QUANTUM_PAINTER_DISPLAY_TIMEOUT 240000 // 240 seconds

// Azoteq TPS65 
#define AZOTEQ_IQS5XX_TPS65
#define SPLIT_POINTING_ENABLE
#define POINTING_DEVICE_RIGHT
//#define POINTING_DEVICE_GESTURES_SCROLL_ENABLE
