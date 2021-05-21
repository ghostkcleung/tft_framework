#ifdef ESP32

#include <SPI.h>

#ifndef ILI9486_SPI_18BIT_H
#define ILI9486_SPI_18BIT_H

#include <ILI9486.h>


namespace tft_framework {

class ILI9486_SPI_18BIT:public ILI9486
{

private:
	uint8_t cs, dc;
	SPIClass* spi;

protected:

	void writeComs ( uint8_t com, uint8_t *datas, unsigned int count );
	void setWindow ( Rectangle* r );

public:

	ILI9486_SPI_18BIT (uint8_t dc);

    void init ( );
    void fillRect(Rectangle* r);
    void setRotate(uint8_t rotate);

    void fillShape(BufferScreen* buf);
	void drawShape(Dot *d);
	~ILI9486_SPI_18BIT();
};

}
#endif
#endif