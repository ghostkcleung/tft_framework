#ifdef ESP32

#ifndef ST7796S_SPI_16BIT_H
#define ST7796S_SPI_16BIT_H

#include <SPI_TFT_Controller.h>

namespace tft_framework {

class ST_7796s_SPI_16Bit:public SPI_TFT_Controller, public Screen
{

public:

	ST_7796s_SPI_16Bit (uint16_t w, uint16_t h, SPIClass* spi, uint8_t cs, uint8_t dc)
		:Screen(w, h),SPI_TFT_Controller(spi,cs,dc){};

	ST_7796s_SPI_16Bit (uint8_t dc):Screen(480,320),SPI_TFT_Controller(dc){};

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