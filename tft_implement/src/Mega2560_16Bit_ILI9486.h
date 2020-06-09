#ifndef MEGA2560_16BIT_ILI9486_H
#define MEGA2560_16BIT_ILI9486_H

#include <tft_framework.h>

namespace tft_framework {

class Mega2560_16Bit_ILI9486:public Screen
{

private:

    volatile uint8_t *ports[4];
    uint8_t bitmasks[4];
    void cbi ( volatile uint8_t *port, uint8_t bitmask );
    void sbi ( volatile uint8_t *port, uint8_t bitmask );
    void pulseHigh ( volatile uint8_t *port, uint8_t bitmask );
    void pulseLow ( volatile uint8_t *port, uint8_t bitmask );
    void writeCom ( uint8_t com );
    void writeData ( uint8_t data );
    void writeData ( uint8_t h, uint8_t l );
	void setWindow ( Rectangle* r );

public:

    Mega2560_16Bit_ILI9486( int16_t w, int16_t h,
        uint8_t rs, uint8_t wr, uint8_t cs, uint8_t rst );

    Mega2560_16Bit_ILI9486():Mega2560_16Bit_ILI9486(
            480, 320, 38, 39, 40, 41) {};

    void init ( );
    void fillRect(Rectangle* r);
    void setRotate(uint8_t rotate);

    void fillImpl(BufferScreen* buf);
	void VerticalScroll ( );
};

}
#endif
