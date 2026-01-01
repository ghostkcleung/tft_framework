
#if defined(__AVR_ATmega2560__) || defined(__SAM3X8E__)

/**
 * @file ILI9486_Parallel_16Bit.h
 * @brief ILI9486 TFT display driver (parallel 16-bit interface)
 * 
 * This class implements the driver for the ILI9486 TFT display controller,
 * using parallel 16-bit color mode and 8-bit data bus.
 * Supports ATmega2560 and SAM3X8E platforms.
 */

#ifndef ILI9486_PARALLEL_16BIT_H
#define ILI9486_PARALLEL_16BIT_H

#include <PARALLEL_TFT_Controller.h>

namespace tft_framework {

/**
 * @class ILI9486_Parallel_16Bit
 * @brief ILI9486 TFT driver class
 * 
 * This class inherits from both Parallel_TFT_Controller and Screen,
 * providing complete ILI9486 display control functions, including initialization, rectangle filling,
 * rotation settings, buffer display, single pixel drawing, and bitmap rendering.
 */
class ILI9486_Parallel_16Bit : public Parallel_TFT_Controller, public Screen {
   public:
	/**
	 * @brief Constructor
	 * @param w Display width (pixels)
	 * @param h Display height (pixels)
	 * @param rs Register select pin
	 * @param wr Write pin
	 * @param cs Chip select pin
	 * @param rst Reset pin
	 */
	ILI9486_Parallel_16Bit(uint16_t w, uint16_t h, uint8_t rs, uint8_t wr,
						   uint8_t cs, uint8_t rst)
		: Parallel_TFT_Controller(rs, wr, cs, rst), Screen(w, h) {};

	/**
	 * @brief Default constructor using default resolution (480x320) and pins
	 */
	ILI9486_Parallel_16Bit() : Parallel_TFT_Controller(), Screen(480, 320) {};

	/**
	 * @brief Initialize ILI9486 display
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