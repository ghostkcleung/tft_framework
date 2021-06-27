#if defined ( __AVR_ATmega2560__ ) || defined ( __SAM3X8E__ )
#ifndef ILI9486_PARALLEL_H
#define ILI9486_PARALLEL_H

#include <ILI9486.h>

namespace tft_framework {

#ifdef __AVR_ATmega2560__
	typedef volatile uint8_t RegType;
	typedef uint8_t RegSize;
#else #ifdef __SAM3X8E__
	typedef volatile uint32_t RegType;
	typedef uint32_t RegSize;
#endif

class ILI9486_Parallel:public ILI9486
{

private:

    RegType *ports[4];
    RegSize bitmasks[4];
    void cbi ( RegType *port, RegSize bitmask );
    void sbi ( RegType *port, RegSize bitmask );
    void pulseLow ( RegType *port, RegSize bitmask );
	void feedValue ( uint8_t h, uint8_t l );

protected:

	void writeComs ( uint8_t com, uint8_t *datas, unsigned int count );
	void setWindow ( Rectangle* r );

public:

    ILI9486_Parallel( int16_t w, int16_t h,
        uint8_t rs, uint8_t wr, uint8_t cs, uint8_t rst );

    ILI9486_Parallel():ILI9486_Parallel(
            480, 320, 38, 39, 40, 41) {};

    void init ( );
    void fillRect(Rectangle* r);
    void setRotate(uint8_t rotate);

    void fillShape(BufferScreen* buf);
	void drawShape(Dot *d);
};

}
#endif
#endif