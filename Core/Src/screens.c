/*
 * screens.c
 *
 *  Created on: Nov 12, 2022
 *      Author: carlos
 */

#include "screens.h"
#include "ssd1306.h"

void Draw_Home_Screen(void)
{
	/*
	 * Draw Frame
	 */
	// Top Horizontal Line
	ssd1306_DrawHLine(0, 0, 128, White);
	// Left Vertical Line
	ssd1306_DrawVLine(0, 1, 62, White);
	// Right Vertical Line
	ssd1306_DrawVLine(127, 1, 62, White);
	// Bottom Horizontal Line
	ssd1306_DrawHLine(0, 63, 128, White);
	// Temperature Dividers
	ssd1306_DrawHLine(1, 51, 127, White);
	ssd1306_DrawVLine((SSD1306_WIDTH / 2), 50, 63, White);

	/*
	 * Fill in Text
	 */
	ssd1306_SetCursor(2, 53);
	ssd1306_WriteString("ADC: ", Font_6x8, White);
}

/*
 * Bitmaps!
 */

#define Lamchop_logo_width 128
#define Lamchop_logo_height 64
static unsigned char Lamchop_logo[] =  {
   0xa2, 0x24, 0x92, 0x44, 0x44, 0x25, 0x21, 0x84, 0x4a, 0x00, 0x10, 0xa2,
   0x04, 0x00, 0x40, 0x44, 0xa2, 0x92, 0x24, 0x45, 0x44, 0x25, 0x21, 0x84,
   0x4a, 0x00, 0x10, 0xa2, 0x04, 0x00, 0x40, 0x44, 0xa2, 0xc9, 0x49, 0x46,
   0x44, 0x25, 0x21, 0x84, 0xca, 0xff, 0xff, 0xa2, 0xfc, 0xff, 0x7f, 0x44,
   0xa2, 0xe4, 0x93, 0x44, 0x44, 0x25, 0x21, 0xfc, 0x4a, 0x40, 0x80, 0xa2,
   0x04, 0x00, 0x40, 0x44, 0xa2, 0x72, 0x27, 0x45, 0x44, 0x25, 0x21, 0x00,
   0x4a, 0x40, 0x80, 0xa2, 0x04, 0x00, 0x40, 0x44, 0xa2, 0x39, 0x4e, 0x46,
   0x44, 0x25, 0x21, 0x00, 0x4a, 0xc0, 0xff, 0xa2, 0xfc, 0xff, 0x7f, 0xc4,
   0xa2, 0x72, 0x27, 0x45, 0xc4, 0x25, 0xe1, 0xff, 0x4b, 0x40, 0x80, 0xa2,
   0x44, 0x00, 0x48, 0x04, 0xa2, 0xe4, 0x93, 0x44, 0x04, 0x24, 0x01, 0x00,
   0x48, 0x40, 0x80, 0xbe, 0x44, 0x00, 0x48, 0x04, 0xa2, 0xc9, 0x49, 0x46,
   0x04, 0x24, 0xff, 0xff, 0xcf, 0x7f, 0xfe, 0x80, 0x44, 0x7e, 0x48, 0x04,
   0xa2, 0x92, 0x24, 0x45, 0x04, 0x24, 0x04, 0xa0, 0x40, 0x00, 0x82, 0x80,
   0x44, 0x42, 0x48, 0x04, 0xa2, 0x24, 0x92, 0x44, 0xfc, 0x27, 0x04, 0xa0,
   0x40, 0x00, 0x82, 0xff, 0x44, 0x42, 0x48, 0xfc, 0xa3, 0x49, 0x49, 0x46,
   0x00, 0x20, 0x04, 0xa0, 0xc0, 0xff, 0x83, 0x00, 0x44, 0x42, 0x48, 0x00,
   0xa0, 0x92, 0x24, 0x45, 0x00, 0x20, 0xfc, 0xbf, 0x40, 0x00, 0x82, 0x00,
   0x44, 0x42, 0x48, 0x00, 0xa0, 0x24, 0x92, 0x44, 0x00, 0x20, 0x04, 0xa0,
   0x40, 0x00, 0x82, 0x00, 0x44, 0x42, 0x48, 0x00, 0xa0, 0xff, 0xff, 0x47,
   0x00, 0x20, 0x04, 0xa0, 0xc0, 0xff, 0xff, 0x00, 0x44, 0x42, 0xc8, 0xff,
   0xa0, 0x00, 0x00, 0xc1, 0xff, 0x3f, 0x04, 0xa0, 0x00, 0x00, 0x00, 0x1c,
   0x44, 0x7e, 0x08, 0x21, 0xa0, 0x00, 0x00, 0x01, 0x00, 0x00, 0x04, 0xa0,
   0x00, 0x00, 0x00, 0x0a, 0x44, 0x00, 0x08, 0x21, 0xbf, 0x00, 0x00, 0x01,
   0x00, 0x00, 0x04, 0xa0, 0x00, 0x00, 0x00, 0x01, 0x44, 0x00, 0x08, 0x21,
   0x80, 0x00, 0x0e, 0x01, 0x00, 0x00, 0x04, 0xa0, 0x00, 0x70, 0xc0, 0x00,
   0xc4, 0xff, 0x0f, 0x21, 0x80, 0x00, 0x07, 0xff, 0xff, 0xff, 0x07, 0xa0,
   0x00, 0xe6, 0x41, 0x00, 0x04, 0x00, 0x00, 0x21, 0x80, 0x40, 0x00, 0x00,
   0x00, 0x00, 0x00, 0xa0, 0x03, 0x81, 0x63, 0xf8, 0x07, 0x00, 0x00, 0x3f,
   0xff, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0xa0, 0x40, 0x80, 0x63, 0x00,
   0x04, 0x00, 0x00, 0x00, 0x00, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0,
   0x21, 0x00, 0x61, 0xfc, 0x07, 0x00, 0x00, 0x00, 0x00, 0x30, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x18, 0x00, 0x00, 0x1e, 0x40, 0x10, 0x08, 0x08, 0x00, 0x30, 0x10,
   0x00, 0x03, 0x08, 0x02, 0x00, 0x18, 0x00, 0x80, 0x38, 0x70, 0x18, 0x0e,
   0x0c, 0x00, 0x30, 0x1c, 0x40, 0x0f, 0x8e, 0x07, 0x00, 0x18, 0x00, 0x40,
   0x30, 0x3c, 0x9e, 0x0e, 0x04, 0x00, 0x30, 0x19, 0x10, 0x8c, 0x2f, 0x0e,
   0x00, 0x18, 0x00, 0x20, 0x30, 0xb0, 0x58, 0x0c, 0x06, 0x00, 0x30, 0x18,
   0x18, 0x1c, 0x16, 0x06, 0x00, 0x0c, 0x00, 0x30, 0x18, 0x70, 0x18, 0x06,
   0x06, 0x00, 0x18, 0x0c, 0x0c, 0x0c, 0x0e, 0x0c, 0x00, 0x0c, 0x00, 0x30,
   0x18, 0x10, 0x08, 0x06, 0x03, 0x00, 0x18, 0x0c, 0x04, 0x0c, 0x06, 0x06,
   0x00, 0x0c, 0x00, 0x18, 0x18, 0x18, 0x0c, 0x06, 0x03, 0x00, 0x18, 0x0c,
   0x06, 0x0c, 0x06, 0x06, 0x00, 0x0c, 0x00, 0x18, 0x18, 0x18, 0x0c, 0x02,
   0x03, 0x00, 0x08, 0x0c, 0x06, 0x04, 0x02, 0x02, 0x00, 0x06, 0x80, 0x18,
   0x0c, 0x18, 0x04, 0x03, 0x03, 0x00, 0x0c, 0x04, 0x07, 0x06, 0x03, 0x02,
   0x00, 0x06, 0x00, 0x08, 0x0c, 0x08, 0x06, 0x83, 0x03, 0x00, 0x0c, 0x06,
   0x02, 0x06, 0x03, 0x03, 0x00, 0x03, 0x40, 0x1c, 0x4d, 0x0c, 0x06, 0x23,
   0x03, 0x00, 0x0c, 0x06, 0x07, 0x01, 0x83, 0x01, 0x00, 0x01, 0x20, 0xbc,
   0x3c, 0x0c, 0x06, 0x8f, 0x03, 0x00, 0x04, 0x2e, 0x07, 0x01, 0x03, 0x00,
   0xf0, 0x6d, 0x3f, 0x38, 0x0e, 0x0c, 0x02, 0x03, 0x03, 0x00, 0x06, 0x0e,
   0x5e, 0x80, 0x3f, 0x00, 0x00, 0x80, 0x0e, 0x08, 0x04, 0x00, 0x01, 0x01,
   0x07, 0x10, 0x02, 0x06, 0x14, 0x80, 0x17, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x0f, 0x04, 0x00, 0x00, 0x00, 0x80, 0x01, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfe, 0x01, 0x00, 0x00,
   0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x10, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x00, 0xfe, 0x00, 0xf0, 0xff, 0xff,
   0xff, 0xff, 0x03, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xc1, 0x00, 0x12,
   0x00, 0x10, 0x00, 0x00, 0x00, 0x80, 0x02, 0x00, 0x00, 0x00, 0x01, 0x00,
   0x00, 0xc1, 0x00, 0x12, 0xff, 0x1f, 0x00, 0x00, 0x00, 0x80, 0x02, 0x00,
   0x00, 0x00, 0x01, 0x00, 0x78, 0xc1, 0x80, 0x13, 0x00, 0x10, 0xf0, 0xff,
   0xff, 0x80, 0xfe, 0xff, 0xff, 0xff, 0xf1, 0xff, 0x4b, 0x61, 0x80, 0xd2,
   0x00, 0x10, 0x10, 0x00, 0x80, 0x80, 0x02, 0x00, 0x00, 0x00, 0x11, 0x00,
   0x4a, 0xe1, 0x80, 0x52, 0xff, 0xff, 0x13, 0x00, 0x80, 0x80, 0x02, 0x00,
   0x00, 0x00, 0x11, 0x00, 0x4a, 0x11, 0x81, 0x52, 0x00, 0x00, 0x92, 0xff,
   0x9f, 0x80, 0x02, 0x00, 0x00, 0x00, 0x91, 0x7f, 0x4a, 0x01, 0x80, 0x52,
   0x00, 0x00, 0x92, 0x00, 0x90, 0xf0, 0xff, 0x3f, 0x00, 0x00, 0x91, 0x40,
   0x4a, 0x01, 0x80, 0x52, 0x00, 0x00, 0x92, 0x00, 0x90, 0x10, 0x00, 0xe0,
   0xff, 0xff, 0x91, 0x40, 0x4a, 0x01, 0x80, 0x52, 0x00, 0x00, 0x92, 0xfc,
   0x93, 0x10, 0x00, 0x20, 0x00, 0x00, 0x91, 0x5c, 0x4a, 0x01, 0x80, 0x52,
   0xff, 0x3f, 0x92, 0x04, 0x92, 0x10, 0x00, 0xe0, 0xff, 0xff, 0x97, 0x54,
   0x7a, 0x01, 0x80, 0x52, 0x00, 0x20, 0x92, 0xfc, 0x93, 0x10, 0xfe, 0x21,
   0x00, 0x00, 0x94, 0x54, 0x02, 0x01, 0x80, 0x52, 0x00, 0x20, 0x92, 0x00,
   0x90, 0x10, 0x02, 0x21, 0x00, 0x00, 0x94, 0x54, 0xf2, 0xff, 0xff, 0xff,
   0xfc, 0x23, 0x92, 0xf8, 0x91, 0x10, 0x02, 0xa1, 0xff, 0x3f, 0x94, 0x54,
   0x12, 0x00, 0x00, 0x00, 0x04, 0x22, 0x92, 0x08, 0x91, 0x10, 0x02, 0xa1,
   0x00, 0x20, 0x94, 0x54, 0x12, 0x00, 0x00, 0x00, 0x04, 0x22, 0x92, 0x08,
   0x91, 0x10, 0x02, 0xa1, 0x00, 0x20, 0x94, 0x54, 0x92, 0xff, 0xff, 0xff,
   0x04, 0x22, 0x92, 0x08, 0x91, 0x10, 0x7a, 0xa1, 0xfe, 0x23, 0x94, 0x54,
   0x92, 0x00, 0x00, 0x00, 0x04, 0x22, 0x92, 0x08, 0x91, 0x10, 0x4a, 0xa1,
   0x02, 0x22, 0x94, 0x54, 0x92, 0x00, 0x00, 0x00, 0x04, 0x22, 0x92, 0x08,
   0x91, 0x10, 0x4a, 0xa1, 0x02, 0x22, 0x94, 0x54, 0x92, 0xfc, 0xff, 0xff,
   0x04, 0x22, 0x92, 0x08, 0x91, 0x10, 0x4a, 0xa1, 0x3a, 0x22, 0x94, 0x54,
   0x92, 0x04, 0x00, 0x00, 0xfc, 0x23, 0x92, 0x08, 0x91, 0x10, 0x4a, 0xa1,
   0x2a, 0x22, 0x94, 0x54, 0x92, 0x04, 0xf8, 0xff, 0x00, 0x20, 0x92, 0x08,
   0x91, 0x10, 0x4a, 0xa1, 0x2a, 0x22, 0x94, 0x54, 0x92, 0x04, 0x08, 0x00,
   0x00, 0x20, 0x92, 0x08, 0x91, 0x10, 0x4a, 0xa1, 0x2a, 0x22, 0x94, 0x54,
   0x92, 0x04, 0x08, 0x00 };

#define HomeScreenFrame_width 128
#define HomeScreenFrame_height 64
static const uint8_t HomeScreenFrame[] = {
   0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
   0xff, 0xff, 0xff, 0xff, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x01, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80,
   0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x80, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x01, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80,
   0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x80, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x01, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80,
   0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x80, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x01, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80,
   0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x80, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x01, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80,
   0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x80, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x01, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80,
   0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x80, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x01, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80,
   0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x80, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x01, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80,
   0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x80, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x01, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80,
   0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x80, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x01, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80,
   0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x80, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x01, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80,
   0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x80, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x01, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80,
   0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x80, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x01, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80,
   0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x80, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x01, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80,
   0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x80, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x01, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80,
   0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
   0xff, 0xff, 0xff, 0xff, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x01, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80,
   0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x80, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x01, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80,
   0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x80, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x01, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80,
   0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x80, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x01, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80,
   0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x80, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x01, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80,
   0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x80, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x01, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80,
   0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
   0xff, 0xff, 0xff, 0xff };

ScreenDef Logo = {Lamchop_logo_width, Lamchop_logo_height, Lamchop_logo};
ScreenDef Home_Screen = {HomeScreenFrame_width, HomeScreenFrame_height, HomeScreenFrame};

