#include "ssd1306.h"

// Screenbuffer
static uint8_t SSD1306_Buffer[SSD1306_WIDTH * SSD1306_HEIGHT / 8];

// Screen object
static SSD1306_t SSD1306;

//
//  Send a byte to the command register
//
static uint8_t ssd1306_WriteCommand(I2C_HandleTypeDef *hi2c, uint8_t command)
{
    return HAL_I2C_Mem_Write(hi2c, SSD1306_I2C_ADDR, 0x00, 1, &command, 1, 10);
}


//
//  Initialize the oled screen
//
uint8_t ssd1306_Init(I2C_HandleTypeDef *hi2c)
{
    // Wait for the screen to boot
    HAL_Delay(100);
    int status = 0;

    // Init LCD
    status += ssd1306_WriteCommand(hi2c, 0xAE);   // Display off
    status += ssd1306_WriteCommand(hi2c, 0x20);   // Set Memory Addressing Mode
    status += ssd1306_WriteCommand(hi2c, 0x10);   // 00,Horizontal Addressing Mode;01,Vertical Addressing Mode;10,Page Addressing Mode (RESET);11,Invalid
    status += ssd1306_WriteCommand(hi2c, 0xB0);   // Set Page Start Address for Page Addressing Mode,0-7
    status += ssd1306_WriteCommand(hi2c, 0xC8);   // Set COM Output Scan Direction
    status += ssd1306_WriteCommand(hi2c, 0x00);   // Set low column address
    status += ssd1306_WriteCommand(hi2c, 0x10);   // Set high column address
    status += ssd1306_WriteCommand(hi2c, 0x40);   // Set start line address
    status += ssd1306_WriteCommand(hi2c, 0x81);   // set contrast control register
    status += ssd1306_WriteCommand(hi2c, 0xFF);
    status += ssd1306_WriteCommand(hi2c, 0xA1);   // Set segment re-map 0 to 127
    status += ssd1306_WriteCommand(hi2c, 0xA6);   // Set normal display

    status += ssd1306_WriteCommand(hi2c, 0xA8);   // Set multiplex ratio(1 to 64)
    status += ssd1306_WriteCommand(hi2c, SSD1306_HEIGHT - 1);

    status += ssd1306_WriteCommand(hi2c, 0xA4);   // 0xa4,Output follows RAM content;0xa5,Output ignores RAM content
    status += ssd1306_WriteCommand(hi2c, 0xD3);   // Set display offset
    status += ssd1306_WriteCommand(hi2c, 0x00);   // No offset
    status += ssd1306_WriteCommand(hi2c, 0xD5);   // Set display clock divide ratio/oscillator frequency
    status += ssd1306_WriteCommand(hi2c, 0xF0);   // Set divide ratio
    status += ssd1306_WriteCommand(hi2c, 0xD9);   // Set pre-charge period
    status += ssd1306_WriteCommand(hi2c, 0x22);

    status += ssd1306_WriteCommand(hi2c, 0xDA);   // Set com pins hardware configuration
#ifdef SSD1306_COM_LR_REMAP
    status += ssd1306_WriteCommand(hi2c, 0x32);   // Enable COM left/right remap
#else
    status += ssd1306_WriteCommand(hi2c, 0x12);   // Do not use COM left/right remap
#endif // SSD1306_COM_LR_REMAP

    status += ssd1306_WriteCommand(hi2c, 0xDB);   // Set vcomh
    status += ssd1306_WriteCommand(hi2c, 0x20);   // 0x20,0.77xVcc
    status += ssd1306_WriteCommand(hi2c, 0x8D);   // Set DC-DC enable
    status += ssd1306_WriteCommand(hi2c, 0x14);   //
    status += ssd1306_WriteCommand(hi2c, 0xAF);   // Turn on SSD1306 panel

    if (status != 0) {
        return 1;
    }

    // Clear screen
    ssd1306_Fill(Black);

    // Flush buffer to screen
    ssd1306_UpdateScreen(hi2c);

    // Set default values for screen object
    SSD1306.CurrentX = 0;
    SSD1306.CurrentY = 0;

    SSD1306.Initialized = 1;

    return 0;
}

//
//  Fill the whole screen with the given color
//
void ssd1306_Fill(SSD1306_COLOR color)
{
    // Fill screen buffer with a constant value (color)
    uint32_t i;

    for(i = 0; i < sizeof(SSD1306_Buffer); i++)
    {
        SSD1306_Buffer[i] = (color == Black) ? 0x00 : 0xFF;
    }

    return;
}

//
//  Write the screen buffer with changes to the screen
//
void ssd1306_UpdateScreen(I2C_HandleTypeDef *hi2c)
{
    uint8_t i;

    for (i = 0; i < 8; i++) {
        ssd1306_WriteCommand(hi2c, 0xB0 + i);
        ssd1306_WriteCommand(hi2c, 0x00);
        ssd1306_WriteCommand(hi2c, 0x10);

        HAL_I2C_Mem_Write(hi2c, SSD1306_I2C_ADDR, 0x40, 1, &SSD1306_Buffer[SSD1306_WIDTH * i], SSD1306_WIDTH, 100);
    }

    return;
}

//
//  Draw one pixel in the screen buffer
//  X => X Coordinate
//  Y => Y Coordinate
//  color => Pixel color
//
void ssd1306_DrawPixel(uint8_t x, uint8_t y, SSD1306_COLOR color)
{
    if (x >= SSD1306_WIDTH || y >= SSD1306_HEIGHT)
    {
        // Don't write outside the buffer
        return;
    }

    // Check if pixel should be inverted
    if (SSD1306.Inverted)
    {
        color = (SSD1306_COLOR)!color;
    }

    // Draw in the correct color
    if (color == White)
    {
        SSD1306_Buffer[x + (y / 8) * SSD1306_WIDTH] |= 1 << (y % 8);
    }
    else
    {
        SSD1306_Buffer[x + (y / 8) * SSD1306_WIDTH] &= ~(1 << (y % 8));
    }

    return;
}

void ssd1306_DrawHLine(uint8_t x, uint8_t y, uint8_t l, SSD1306_COLOR color)
{
	/* Check if requested length exceeds dimensions of screen. If so, limit to
	 * screen dimensions to prevent from writing into improper memory locations.
	 */
	if ((x + l) > SSD1306_WIDTH)
		l = SSD1306_WIDTH - x;
	else if (y > SSD1306_HEIGHT)
		y = SSD1306_HEIGHT;

	for (uint8_t i = x; i < (x + l); i++)
		ssd1306_DrawPixel(i, y, color);

	return;
}

void ssd1306_DrawVLine(uint8_t x, uint8_t y, uint8_t h, SSD1306_COLOR color)
{
	/* Check if requested length exceeds dimensions of screen. If so, limit to
	 * screen dimensions to prevent from writing into improper memory locations.
	 */
	if ((y + h) > SSD1306_HEIGHT)
		h = SSD1306_HEIGHT - y;
	else if (x > SSD1306_WIDTH)
		x = SSD1306_WIDTH;

	for (uint8_t i = y; i < (y + h); i++)
		ssd1306_DrawPixel(x, i, color);

	return;
}

/*
 * Draw a filled box of specified color. Useful to blank out old data before writing new
 * data to a location on the screen.
 * x,y = start coordinates
 * w,h = width and height of box, from start coordinates
 * color = White or Black
 */
void ssd1306_DrawBox(uint8_t x, uint8_t y, uint8_t w, uint8_t h, SSD1306_COLOR color)
{
  for (uint8_t i = x; i < (x + w); i++) {
	for (uint8_t j = y; j < (y + h); j++) {
		ssd1306_DrawPixel(i, j, color);
	}
  }

  return;
}

/*
 * Draw Bitmap
 * Reads data from Left-to-right
 */
void ssd1306_DrawBitmap(uint8_t x, uint8_t y, uint8_t w, uint8_t h, ScreenDef Screen, SSD1306_COLOR color)
{
    int16_t byteWidth = (w + 7) / 8; // Bitmap scan line pad = whole byte
    uint8_t byte = 0;

    if (x >= SSD1306_WIDTH || y >= SSD1306_HEIGHT) {
        return;
    }

    for (uint8_t j = 0; j < h; j++, y++) {
        for (uint8_t i = 0; i < w; i++) {
            if (i & 7)
                byte <<= 1;
            else
                byte = (*(const unsigned char *)(&Screen.data[j * byteWidth + i / 8]));
            if (byte & 0x80)
                ssd1306_DrawPixel(x + i, y, color);
        }
    }

    return;
}


/*
 * Draw XBitmap
 * Bitmaps generated by GIMP are Right-to-Left and thus need to be unpacked as such
 */
void ssd1306_DrawXBitmap(uint8_t x, uint8_t y, uint8_t w, uint8_t h, ScreenDef Screen, SSD1306_COLOR color)
{
    int16_t byteWidth = (w + 7) / 8; // Bitmap scan line pad = whole byte
    uint8_t byte = 0;

    if (x >= SSD1306_WIDTH || y >= SSD1306_HEIGHT) {
        return;
    }

    for (uint8_t j = 0; j < h; j++, y++) {
        for (uint8_t i = 0; i < w; i++) {
            if (i & 7)
                byte >>= 1;
            else
                byte = (*(const unsigned char *)(&Screen.data[j * byteWidth + i / 8]));
            if (byte & 0x01)
                ssd1306_DrawPixel(x + i, y, color);
        }
    }

    return;
}

//
//  Draw 1 char to the screen buffer
//  ch      => Character to write
//  Font    => Font to use
//  color   => Black or White
//
char ssd1306_WriteChar(char ch, FontDef Font, SSD1306_COLOR color)
{
    uint32_t i, b, j;

    // Check remaining space on current line
    if (SSD1306_WIDTH <= (SSD1306.CurrentX + Font.FontWidth) ||
        SSD1306_HEIGHT <= (SSD1306.CurrentY + Font.FontHeight))
    {
        // Not enough space on current line
        return 0;
    }

    // Translate font to screen buffer
    for (i = 0; i < Font.FontHeight; i++)
    {
        b = Font.data[(ch - 32) * Font.FontHeight + i];
        for (j = 0; j < Font.FontWidth; j++)
        {
            if ((b << j) & 0x8000)
            {
                ssd1306_DrawPixel(SSD1306.CurrentX + j, (SSD1306.CurrentY + i), (SSD1306_COLOR) color);
            }
            else
            {
                ssd1306_DrawPixel(SSD1306.CurrentX + j, (SSD1306.CurrentY + i), (SSD1306_COLOR)!color);
            }
        }
    }

    // The current space is now taken
    SSD1306.CurrentX += Font.FontWidth;

    // Return written char for validation
    return ch;
}

//
//  Write full string to screenbuffer
//
char ssd1306_WriteString(char* str, FontDef Font, SSD1306_COLOR color)
{
    // Write until null-byte
    while (*str)
    {
        if (ssd1306_WriteChar(*str, Font, color) != *str)
        {
            // Char could not be written
            return *str;
        }

        // Next char
        str++;
    }

    // Everything ok
    return *str;
}

//
//  Invert background/foreground colors
//
void ssd1306_InvertColors(void)
{
    SSD1306.Inverted = !SSD1306.Inverted;
}

//
//  Set cursor position
//
void ssd1306_SetCursor(uint8_t x, uint8_t y)
{
    SSD1306.CurrentX = x;
    SSD1306.CurrentY = y;
}
