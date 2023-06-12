#ifdef ESP32

#include <SPI.h>

#ifndef SPI_TFT_CONTROLLER_H
#define SPI_TFT_CONTROLLER_H

#include <TFT_Controller.h>


namespace tft_framework {

class SPI_TFT_Controller:public TFT_Controller
{
protected:

	SPIClass* spi;
	uint8_t cs, dc;
	void writeComs ( uint8_t com, uint8_t *datas, unsigned int count );
	void setWindow ( Rectangle* r );

public:

	SPI_TFT_Controller (SPIClass* spi, uint8_t cs, uint8_t dc)
		:spi(spi),cs(cs),dc(dc){};

	SPI_TFT_Controller (uint8_t dc);

	virtual ~SPI_TFT_Controller();
};

}
#endif
#endif