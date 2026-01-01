#ifdef ESP32

/**
 * @file ILI9488_SPI_18Bit.h
 * @brief ILI9488 TFT display driver (SPI 18-bit interface)
 * 
 * This class implements the driver for the ILI9488 TFT display controller,
 * using SPI interface and 18-bit (RGB666) color mode.
 * Supports ESP32 platform only.
 */

#ifndef ILI9488_SPI_18BIT_H
#define ILI9488_SPI_18BIT_H

#include <SPI_TFT_Controller.h>

namespace tft_framework {

/**
 * @class ILI9488_SPI_18Bit
 * @brief ILI9488 TFT driver class
 * 
 * This class inherits from both SPI_TFT_Controller and Screen,
 * providing complete ILI9488 display control functions. Uses 18-bit color depth,
 * with 6 bits per color channel (R/G/B).
 */
class ILI9488_SPI_18Bit : public SPI_TFT_Controller, public Screen {
   public:
	/**
	 * @brief Constructor
	 * @param w Display width (pixels)
	 * @param h Display height (pixels)
	 * @param spi SPI class pointer
	 * @param cs Chip select pin
	 * @param dc Data/Command select pin
	 */
	ILI9488_SPI_18Bit(uint16_t w, uint16_t h, SPIClass* spi, uint8_t cs,
					  uint8_t dc)
		: Screen(w, h), SPI_TFT_Controller(spi, cs, dc) {};

	/**
	 * @brief Default constructor using default resolution (480x320)
	 * @param dc Data/Command select pin
	 */
	ILI9488_SPI_18Bit(uint8_t dc) : Screen(480, 320), SPI_TFT_Controller(dc) {};

	/**
	 * @brief Initialize ILI9488 display
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