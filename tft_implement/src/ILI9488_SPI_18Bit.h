#ifdef ESP32

#ifndef ILI9488_SPI_18BIT_H
#define ILI9488_SPI_18BIT_H

#include <SPI_TFT_Controller.h>

namespace tft_framework {

class ILI9488_SPI_18Bit:public SPI_TFT_Controller, public Screen
{

public:

	ILI9488_SPI_18Bit (uint16_t w, uint16_t h, SPIClass* spi, uint8_t cs, uint8_t dc)
		:Screen(w, h),SPI_TFT_Controller(spi,cs,dc){};

	ILI9488_SPI_18Bit (uint8_t dc):Screen(480,320),SPI_TFT_Controller(dc){};

    void init ( );
    void fillRect(Rectangle* r);
    void setRotate(uint8_t rotate);

    void fillShape(BufferScreen* buf);
	void drawShape(Dot *d);
	void fillShape(Bitmap* bmp);

};

}
#endif
#endif