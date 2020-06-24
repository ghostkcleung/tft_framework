#if defined ( __AVR_ATmega2560__ )
#ifndef Mega2560_ILI9486_16Bit_H
#define Mega2560_ILI9486_16Bit_H

#include <tft_framework.h>

namespace tft_framework {

typedef volatile uint8_t RegType;
typedef uint8_t RegSize;

class Mega2560_ILI9486_16Bit:public Screen
{

private:

    RegType *ports[4];
    RegSize bitmasks[4];
    void cbi ( RegType *port, RegSize bitmask );
    void sbi ( RegType *port, RegSize bitmask );
    void pulseHigh ( RegType *port, RegSize bitmask );
    void pulseLow ( RegType *port, RegSize bitmask );
    void writeCom ( uint8_t com );
    void writeData ( uint8_t data );
	void setWindow ( Rectangle* r );
	void feedValue ( uint8_t h, uint8_t l );

protected:
	void setDirectionRegisters ( ) ;

public:

    Mega2560_ILI9486_16Bit( int16_t w, int16_t h,
        uint8_t rs, uint8_t wr, uint8_t cs, uint8_t rst );

    Mega2560_ILI9486_16Bit():Mega2560_ILI9486_16Bit(
            480, 320, 38, 39, 40, 41) {};

    void init ( );
    void fillRect(Rectangle* r);
    void setRotate(uint8_t rotate);

    void fillImpl(BufferScreen* buf);
};

}
#endif
#endif