/**
 * @file TFT_Controller.h
 * @brief Abstract base class for TFT display controllers
 * 
 * This class defines the basic interface for TFT display controllers, providing
 * abstract methods for sending commands and setting windows.
 * Concrete implementations are provided by subclasses (e.g., Parallel_TFT_Controller and SPI_TFT_Controller).
 */

#ifndef TFT_CONTROLLER_H
#define TFT_CONTROLLER_H

#include <tft_framework.h>

namespace tft_framework {

/**
 * @class TFT_Controller
 * @brief Abstract base class for TFT controllers
 * 
 * This is an abstract base class that defines the common interface for all TFT controllers.
 * Subclasses must implement writeComs() and setWindow() methods.
 */
class TFT_Controller {
   protected:
	/**
	 * @brief Send command to TFT controller
	 * @param com Command byte
	 */
	void writeCom(uint8_t com);
	
	/**
	 * @brief Send command and single data byte to TFT controller
	 * @param com Command byte
	 * @param data Data byte
	 */
	void writeCom(uint8_t com, uint8_t data);
	
	/**
	 * @brief Send command and 16-bit data to TFT controller
	 * @param com Command byte
	 * @param data 16-bit data
	 */
	void writeCom16(uint8_t com, uint16_t data);

	/**
	 * @brief Send command and multiple data bytes to TFT controller (pure virtual)
	 * @param com Command byte
	 * @param datas Pointer to data array
	 * @param count Number of data bytes
	 */
	virtual void writeComs(uint8_t com, uint8_t* datas, unsigned int count) = 0;
	
	/**
	 * @brief Set display window (pure virtual)
	 * @param r Pointer to rectangle object defining the display area
	 */
	virtual void setWindow(Rectangle* r) = 0;
};

}  // namespace tft_framework
#endif