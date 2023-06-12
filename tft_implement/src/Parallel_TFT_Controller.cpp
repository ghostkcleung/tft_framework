#if defined ( __AVR_ATmega2560__ ) || defined ( __SAM3X8E__ )

#include <Parallel_TFT_Controller.h>

using namespace tft_framework;

Parallel_TFT_Controller::Parallel_TFT_Controller(uint8_t rs, uint8_t wr, uint8_t cs, uint8_t rst)
{
	uint8_t pins[4] = {rs, wr, cs, rst};

	uint8_t i = 0;
	do
	{
		pinMode(pins[i], OUTPUT);
		ports[i] = portOutputRegister(digitalPinToPort(pins[i]));
		bitmasks[i] = digitalPinToBitMask(pins[i]);
	} while (i++ < 3);
}

void Parallel_TFT_Controller::sbi(RegType *port, RegSize bitmask)
{
	*port |= bitmask;
}

void Parallel_TFT_Controller::pulseLow(RegType *port, RegSize bitmask)
{
	cbi(port, bitmask);
	sbi(port, bitmask);
}

void Parallel_TFT_Controller::feedValue(uint8_t h, uint8_t l)
{
#ifdef __AVR_ATmega2560__
	PORTA = h;
	PORTC = l;
#else #ifdef __SAM3X8E__
	REG_PIOA_CODR = 0x0000C080;
	REG_PIOC_CODR = 0x0000003E;
	REG_PIOD_CODR = 0x0000064F;
	REG_PIOA_SODR = ((h & 0x06) << 13) | ((l & 0x40) << 1);
	(h & 0x01) ? REG_PIOB_SODR = 0x4000000 : REG_PIOB_CODR = 0x4000000;
	REG_PIOC_SODR = ((l & 0x01) << 5) | ((l & 0x02) << 3) | ((l & 0x04) << 1) | ((l & 0x08) >> 1) | ((l & 0x10) >> 3);
	REG_PIOD_SODR = ((h & 0x78) >> 3) | ((h & 0x80) >> 1) | ((l & 0x20) << 5) | ((l & 0x80) << 2);
#endif
}

void Parallel_TFT_Controller::cbi(RegType *port, RegSize bitmask)
{
	*port &= ~bitmask;
}

void Parallel_TFT_Controller::writeComs(uint8_t com, uint8_t *datas, unsigned int count)
{
	cbi(ports[0], bitmasks[0]);
	feedValue(0, com);
	pulseLow(ports[1], bitmasks[1]);

	while (count-- != 0)
	{
		sbi(ports[0], bitmasks[0]);
		feedValue(0, *datas++);
		pulseLow(ports[1], bitmasks[1]);
	}
}

void Parallel_TFT_Controller::setWindow(Rectangle *r)
{
	    uint16_t x1 = r -> getX(),
            y1 = r -> getY(),
            x2 = r -> getEndX(),
            y2 = r -> getEndY();

    cbi( ports[2], bitmasks[2] ) ;

	{ uint8_t datas[] = { x1 >> 8, x1, x2 >> 8, x2 } ;
	writeComs ( 0x2A, datas, 4 ) ; }

	{ uint8_t datas[] = { y1 >> 8, y1, y2 >> 8, y2 } ;
	writeComs ( 0x2B, datas, 4 ) ; }

    writeCom ( 0x2c ) ;

    sbi( ports[0], bitmasks[0] ) ;
}

#endif