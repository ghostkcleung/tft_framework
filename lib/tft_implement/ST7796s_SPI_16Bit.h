#ifdef ESP32

/**
 * @file ST7796s_SPI_16Bit.h
 * @brief ST7796s TFT display driver (SPI 16-bit interface)
 * 
 * This class implements the driver for the ST7796s TFT display controller,
 * using SPI interface and 16-bit (RGB565) color mode.
 * Supports ESP32 platform only.
 */

#ifndef ST7796S_SPI_16BIT_H
#define ST7796S_SPI_16BIT_H

#include <SPI_TFT_Controller.h>

namespace tft_framework {

/**
 * @class ST_7796s_SPI_16Bit
 * @brief ST7796s TFT driver class
 * 
 * This class inherits from both SPI_TFT_Controller and Screen,
 * providing complete ST7796s display control functions. Uses 16-bit color depth,
 * with 2 bytes per pixel.
 */
class ST_7796s_SPI_16Bit : public SPI_TFT_Controller, public Screen {
   public:
	/**
	 * @brief Constructor
	 * @param w Display width (pixels)
	 * @param h Display height (pixels)
	 * @param spi SPI class pointer
	 * @param cs Chip select pin
	 * @param dc Data/Command select pin
	 */
	ST_7796s_SPI_16Bit(uint16_t w, uint16_t h, SPIClass* spi, uint8_t cs,
					   uint8_t dc)
		: Screen(w, h), SPI_TFT_Controller(spi, cs, dc) {};

	/**
	 * @brief Default constructor using default resolution (480x320)
	 * @param dc Data/Command select pin
	 */
	ST_7796s_SPI_16Bit(uint8_t dc)
		: Screen(480, 320), SPI_TFT_Controller(dc) {};

	/**
	 * @brief Initialize ST7796s display
	 */
	void init();
	
	/**
	 * @brief Fill rectangle area
	 * @param r Pointer to rectangle object
	 */
	void fillRect(Rectangle* r);
	
	/**
	 * @brief Set display rotation direction
	 * @param rotate Rotation value (0-7)
	 */
	void setRotate(uint8_t rotate);

	/**
	 * @brief Display buffer screen content
	 * @param buf Pointer to buffer screen object
	 */
	void fillShape(BufferScreen* buf);
	
	/**
	 * @brief Draw single pixel point
	 * @param d Pointer to dot object
	 */
	void drawShape(Dot* d);
	
	/**
	 * @brief Display bitmap
	 * @param bmp Pointer to bitmap object
	 */
	void fillShape(Bitmap* bmp);
};

}  // namespace tft_framework
#endif
#endif