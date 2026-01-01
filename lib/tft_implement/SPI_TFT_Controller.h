#ifdef ESP32

#include <SPI.h>

/**
 * @file SPI_TFT_Controller.h
 * @brief SPI interface TFT display controller class
 *
 * This class implements a TFT display controller based on SPI interface.
 * Supports ESP32 platform only, using hardware SPI communication.
 */

#ifndef SPI_TFT_CONTROLLER_H
#define SPI_TFT_CONTROLLER_H

#include <TFT_Controller.h>

namespace tft_framework {

/**
 * @class SPI_TFT_Controller
 * @brief SPI interface TFT controller class
 *
 * This class inherits from TFT_Controller and uses ESP32's SPI interface to
 * communicate with TFT displays. Supports high-speed SPI transfer (up to
 * 40MHz).
 */
class SPI_TFT_Controller : public TFT_Controller {
   protected:
	SPIClass* spi;	///< SPI class pointer
	uint8_t cs;		///< Chip select pin
	uint8_t dc;		///< Data/Command select pin

	/**
	 * @brief Send command and data to TFT controller
	 * @param com Command byte
	 * @param datas Pointer to data array
	 * @param count Number of data bytes
	 */
	void writeComs(uint8_t com, uint8_t* datas, unsigned int count);

	/**
	 * @brief Set display window area
	 * @param r Pointer to rectangle object defining the display area
	 */
	void setWindow(Rectangle* r);

   public:
	/**
	 * @brief Constructor
	 * @param spi SPI class pointer
	 * @param cs Chip select pin
	 * @param dc Data/Command select pin
	 */
	SPI_TFT_Controller(SPIClass* spi, uint8_t cs, uint8_t dc)
		: spi(spi), cs(cs), dc(dc) {};

	/**
	 * @brief Constructor using default SPI settings
	 * @param dc Data/Command select pin
	 */
	SPI_TFT_Controller(uint8_t dc);

	/**
	 * @brief Destructor, releases SPI resources
	 */
	virtual ~SPI_TFT_Controller();
};

}  // namespace tft_framework
#endif
#endif