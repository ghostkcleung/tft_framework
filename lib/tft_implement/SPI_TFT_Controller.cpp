#ifdef ESP32

/**
 * @file SPI_TFT_Controller.cpp
 * @brief Implementation of SPI interface TFT display controller
 */

#include <SPI_TFT_Controller.h>

using namespace tft_framework;

/**
 * @brief Constructor, initialize SPI interface
 * 
 * Uses default settings: VSPI, SS pin as CS, 40MHz clock frequency, SPI_MODE0.
 * 
 * @param dc Data/Command select pin
 */
SPI_TFT_Controller::SPI_TFT_Controller(uint8_t dc) {
	cs = SS;
	this->dc = dc;

	spi = new SPIClass(VSPI);
	spi->begin(SCK, MISO, MOSI, SS);

	spi->beginTransaction(SPISettings(40000000, MSBFIRST, SPI_MODE0));
}

/**
 * @brief Send command and data to TFT controller
 * 
 * First sends command byte (DC=low), then sends data bytes (DC=high).
 * Uses ESP32's fast GPIO operations (GPIO.out_w1tc/GPIO.out_w1ts) for improved speed.
 * 
 * @param com Command byte
 * @param datas Pointer to data array
 * @param count Number of data bytes
 */
void SPI_TFT_Controller::writeComs(uint8_t com, uint8_t* datas,
								   unsigned int count) {
	GPIO.out_w1tc = (1 << cs);
	GPIO.out_w1tc = (1 << dc);
	spi->transfer(com);
	GPIO.out_w1ts = (1 << cs);

	if (count) {
		GPIO.out_w1tc = (1 << cs);
		GPIO.out_w1ts = (1 << dc);
		spi->transfer(datas, count);
		GPIO.out_w1ts = (1 << cs);
	}
}

/**
 * @brief Set TFT display window area
 * 
 * Uses 0x2A (Column Address Set) and 0x2B (Page Address Set) commands to set drawing area,
 * then sends 0x2C (Memory Write) command to prepare to receive pixel data.
 * 
 * @param r Pointer to rectangle object defining the display area
 */
void SPI_TFT_Controller::setWindow(Rectangle* r) {
	uint16_t x1 = r->getX(), y1 = r->getY(), x2 = r->getEndX(),
			 y2 = r->getEndY();

	{
		uint8_t datas[] = {x1 >> 8, x1, x2 >> 8, x2};
		writeComs(0x2A, datas, 4);
	}

	{
		uint8_t datas[] = {y1 >> 8, y1, y2 >> 8, y2};
		writeComs(0x2B, datas, 4);
	}

	writeCom(0x2C);
}

/**
 * @brief Destructor, end SPI transaction and release resources
 */
SPI_TFT_Controller::~SPI_TFT_Controller() {
	spi->endTransaction();
	spi->end();

	delete spi;
}
#endif