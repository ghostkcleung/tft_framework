#if defined(__AVR_ATmega2560__) || defined(__SAM3X8E__)

/**
 * @file Parallel_TFT_Controller.h
 * @brief Parallel interface TFT display controller class
 * 
 * This class implements a TFT display controller based on parallel bus interface.
 * Supports AVR ATmega2560 and SAM3X8E (Arduino Due) platforms.
 * Uses 8-bit parallel data bus and control signal lines (RS, WR, CS, RST).
 */

#ifndef PARALLEL_TFT_CONTROLLER_H
#define PARALLEL_TFT_CONTROLLER_H

#include <TFT_Controller.h>

namespace tft_framework {

#ifdef __AVR_ATmega2560__
typedef volatile uint8_t RegType;
typedef uint8_t RegSize;
#else #ifdef __SAM3X8E__
typedef volatile uint32_t RegType;
typedef uint32_t RegSize;
#endif

/**
 * @class Parallel_TFT_Controller
 * @brief Parallel interface TFT controller class
 * 
 * This class inherits from TFT_Controller and implements an 8-bit parallel data bus interface.
 * Uses direct port register operations for improved speed.
 */
class Parallel_TFT_Controller : public TFT_Controller {
   protected:
	RegType* ports[4];    ///< Stores port register pointers for RS, WR, CS, RST
	RegSize bitmasks[4];  ///< Stores bitmasks for each control signal

	/**
	 * @brief Set specified bit
	 * @param port Port register pointer
	 * @param bitmask Bit mask
	 */
	void sbi(RegType* port, RegSize bitmask);
	
	/**
	 * @brief Generate a low pulse
	 * @param port Port register pointer
	 * @param bitmask Bit mask
	 */
	void pulseLow(RegType* port, RegSize bitmask);
	
	/**
	 * @brief Send 16-bit data (high byte and low byte) to data bus
	 * @param h High byte
	 * @param l Low byte
	 */
	void feedValue(uint8_t h, uint8_t l);
	
	/**
	 * @brief Clear specified bit
	 * @param port Port register pointer
	 * @param bitmask Bit mask
	 */
	void cbi(RegType* port, RegSize bitmask);

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
	 * @param rs Register select pin
	 * @param wr Write pin
	 * @param cs Chip select pin
	 * @param rst Reset pin
	 */
	Parallel_TFT_Controller(uint8_t rs, uint8_t wr, uint8_t cs, uint8_t rst);
	
	/**
	 * @brief Default constructor using default pins (RS=38, WR=39, CS=40, RST=41)
	 */
	Parallel_TFT_Controller() : Parallel_TFT_Controller(38, 39, 40, 41) {};
};
};

}  // namespace tft_framework

#endif

#endif