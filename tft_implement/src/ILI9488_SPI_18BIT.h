#ifdef ESP32

#include <SPI.h>

#ifndef ILI9488_SPI_18BIT_H
#define ILI9488_SPI_18BIT_H

#include <ILI9486.h>


namespace tft_framework {

class ILI9488_SPI_18BIT:public ILI9486
{

private:
	uint8_t cs, dc;
	SPIClass* spi;

protected:

	void writeComs ( uint8_t com, uint8_t *datas, unsigned int count );
	void setWindow ( Rectangle* r );

public:

	ILI9488_SPI_18BIT (uint16_t w, uint16_t h, SPIClass* spi, uint8_t cs, uint8_t dc)
		:ILI9486(w,h),spi(spi),cs(cs),dc(dc){};

	ILI9488_SPI_18BIT (uint8_t dc);

    void init ( );
    void fillRect(Rectangle* r);
    void setRotate(uint8_t rotate);

    void fillShape(BufferScreen* buf);
	void drawShape(Dot *d);
	void fillShape(Bitmap* bmp);
	~ILI9488_SPI_18BIT();
};

}
#endif
#endif