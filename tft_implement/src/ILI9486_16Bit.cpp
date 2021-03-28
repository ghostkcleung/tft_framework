#if defined ( __AVR_ATmega2560__ ) || defined ( __SAM3X8E__ )
#include <ILI9486_16Bit.h>

using namespace tft_framework;

void ILI9486_16Bit::setDirectionRegisters(){
	
#ifdef __AVR_ATmega2560__
	DDRA = 0xFF ;
    DDRC = 0xFF ;
#else #ifdef __SAM3X8E__
		REG_PIOA_OER=0x0000c000;
		REG_PIOB_OER=0x04000000;
		REG_PIOD_OER=0x0000064f;
		REG_PIOA_OER=0x00000080;
		REG_PIOC_OER=0x0000003e;
#endif
}

ILI9486_16Bit::ILI9486_16Bit(int16_t w, int16_t h,
        uint8_t rs, uint8_t wr, uint8_t cs, uint8_t rst ):Screen(w,h)
{

	setDirectionRegisters ( ) ;
    uint8_t pins[4] = { rs, wr, cs, rst } ;

    uint8_t i = 0;
    do
    {
        pinMode ( pins[i], OUTPUT ) ;
        ports[i] = portOutputRegister( digitalPinToPort( pins[i] ) ) ;
        bitmasks[i] = digitalPinToBitMask( pins[i] ) ;
    }
    while ( i++ < 3 ) ;
}

void ILI9486_16Bit::cbi ( RegType *port, RegSize bitmask )
{
    *port &= ~bitmask ;
}

void ILI9486_16Bit::sbi ( RegType *port, RegSize bitmask )
{
    *port |= bitmask ;
}

void ILI9486_16Bit::pulseHigh ( RegType *port, RegSize bitmask )
{
    sbi ( port, bitmask ) ;
    cbi ( port, bitmask ) ;
}

void ILI9486_16Bit::pulseLow ( RegType *port, RegSize bitmask )
{
    cbi ( port, bitmask ) ;
    sbi ( port, bitmask ) ;
}

void ILI9486_16Bit::writeCom ( uint8_t com )
{
    cbi ( ports[0], bitmasks[0] ) ;
    feedValue ( 0, com ) ;
    pulseLow ( ports[1], bitmasks[1] ) ;
}

void ILI9486_16Bit::writeData ( uint8_t data )
{
    sbi ( ports[0], bitmasks[0] ) ;
    feedValue ( 0, data ) ;
    pulseLow ( ports[1], bitmasks[1] ) ;
}

void ILI9486_16Bit::init()
{
	setDirectionRegisters();

    sbi( ports[3], bitmasks[3] );
    delay(5);
    cbi( ports[3], bitmasks[3] );
    delay(15);
    sbi( ports[3], bitmasks[3] );
    delay(15);

    cbi( ports[2], bitmasks[2] );

    writeCom(0x11);	// Sleep OUT
    delay(50);

    writeCom(0xF2);	// ?????
    writeData(0x1C);
    writeData(0xA3);
    writeData(0x32);
    writeData(0x02);
    writeData(0xb2);
    writeData(0x12);
    writeData(0xFF);
    writeData(0x12);
    writeData(0x00);

    writeCom(0xF1);	// ?????
    writeData(0x36);
    writeData(0xA4);

    writeCom(0xF8);	// ?????
    writeData(0x21);
    writeData(0x04);

    writeCom(0xF9);	// ?????
    writeData(0x00);
    writeData(0x08);

    writeCom(0xC0);	// Power Control 1
    writeData(0x0d);
    writeData(0x0d);

    writeCom(0xC1);	// Power Control 2
    writeData(0x43);
    writeData(0x00);

    writeCom(0xC2);	// Power Control 3
    writeData(0x00);

    writeCom(0xC5);	// VCOM Control
    writeData(0x00);
    writeData(0x48);

    writeCom(0xB6);	// Display Function Control
    writeData(0x00);
    writeData(0x22);   // 0x42 = Rotate display 180 deg.
    writeData(0x3B);

    writeCom(0xE0);	// PGAMCTRL (Positive Gamma Control)
    writeData(0x0f);
    writeData(0x24);
    writeData(0x1c);
    writeData(0x0a);
    writeData(0x0f);
    writeData(0x08);
    writeData(0x43);
    writeData(0x88);
    writeData(0x32);
    writeData(0x0f);
    writeData(0x10);
    writeData(0x06);
    writeData(0x0f);
    writeData(0x07);
    writeData(0x00);

    writeCom(0xE1);	// NGAMCTRL (Negative Gamma Control)
    writeData(0x0F);
    writeData(0x38);
    writeData(0x30);
    writeData(0x09);
    writeData(0x0f);
    writeData(0x0f);
    writeData(0x4e);
    writeData(0x77);
    writeData(0x3c);
    writeData(0x07);
    writeData(0x10);
    writeData(0x05);
    writeData(0x23);
    writeData(0x1b);
    writeData(0x00);

    writeCom(0x20);	// Display Inversion OFF

    writeCom(0x36);	// Memory Access Control
    writeData(0b10101000);

    writeCom(0x3A);	// Interface Pixel Format
    writeData(0x55);

    writeCom(0x2A);	// Column Addess Set
    writeData(0x00);
    writeData(0x00);
    writeData(0x01);
    writeData(0xDF);

    writeCom(0x002B);	// Page Address Set
    writeData(0x00);
    writeData(0x00);
    writeData(0x01);
    writeData(0x3f);
    delay(50);
    writeCom(0x0029);	// Display ON
    writeCom(0x002C);	// Memory Write
    sbi(ports[2], bitmasks[2]);
}

void ILI9486_16Bit::setWindow ( Rectangle* r )
{
    int16_t x1 = r -> getX(),
            y1 = r -> getY(),
            x2 = r -> getEndX(),
            y2 = r -> getEndY();

    cbi( ports[2], bitmasks[2] ) ;
    writeCom ( 0x2a ) ;
    writeData ( x1 >> 8 ) ;
    writeData ( x1 ) ;
    writeData ( x2 >> 8 ) ;
    writeData ( x2 ) ;
    writeCom ( 0x2b ) ;
    writeData ( y1 >> 8 ) ;
    writeData ( y1 ) ;
    writeData ( y2 >> 8 ) ;
    writeData ( y2 ) ;
    writeCom ( 0x2c ) ;

    sbi( ports[0], bitmasks[0] ) ;

}

void ILI9486_16Bit::feedValue ( uint8_t h, uint8_t l ) {
#ifdef __AVR_ATmega2560__
    PORTA = h;
    PORTC = l ;
#else #ifdef __SAM3X8E__
	REG_PIOA_CODR=0x0000C080;
	REG_PIOC_CODR=0x0000003E;
	REG_PIOD_CODR=0x0000064F;
	REG_PIOA_SODR=((h & 0x06)<<13) | ((l & 0x40)<<1);
	(h & 0x01) ? REG_PIOB_SODR = 0x4000000 : REG_PIOB_CODR = 0x4000000;
	REG_PIOC_SODR=((l & 0x01)<<5) | ((l & 0x02)<<3) | ((l & 0x04)<<1) | ((l & 0x08)>>1) | ((l & 0x10)>>3);
	REG_PIOD_SODR=((h & 0x78)>>3) | ((h & 0x80)>>1) | ((l & 0x20)<<5) | ((l & 0x80)<<2);
#endif
}

void ILI9486_16Bit::fillRect ( Rectangle* r )
{
	setWindow ( r );

    uint16_t color = r->getColor ( ) ;

	feedValue ( color >> 8, color ) ;

    uint32_t count = (uint32_t)r->getWidth() * r->getHeight() ;
    while ( count -- > 0 )
    {
        pulseLow ( ports[1], bitmasks[1] ) ;
    }
    sbi ( ports[2], bitmasks[2] );
}

void ILI9486_16Bit::setRotate(uint8_t rotate)
{
    rotate %= 4;
    if (getRotate()==rotate)
    {
        return;
    }

    Screen::setRotate(rotate);

    cbi( ports[2], bitmasks[2] );
    writeCom(0x36);
    switch ( rotate )
    {
    case 0:
        writeData ( 0b10101000 ) ;
        break;
    case 1:
        writeData ( 0b00001000 ) ;
        break;
    case 2:
        writeData ( 0b01101000 ) ;
        break;
    case 3:
        writeData ( 0b11001000 ) ;
        break;
    }

    sbi( ports[2], bitmasks[2] );
}


void ILI9486_16Bit::fillShape(BufferScreen* buf)
{
    uint8_t scale = buf->getScale();
    if ( ! scale )
    {
        return ;
    }

    Rectangle r ;
    r.setPoint ( *buf ) ;
    int16_t w = buf->getWidth ( ),
            h = buf->getHeight ( ) ;
    r.setSize ( w*scale, h*scale ) ;

    setWindow ( &r ) ;

    uint16_t y = h, x ;
    uint8_t sy, sx ;
    uint16_t *data=buf->getData(), *col;

    while ( y-- > 0 )
    {
        sy = scale ;
        while ( sy-- > 0 )
        {
            col = data ;
            x = w ;
            while ( x-- > 0 )
            {
                uint16_t value = *col ++;
                sx = scale ;
                while ( sx-- > 0 )
                {
                    feedValue ( value >> 8, value ) ;
                    pulseLow ( ports[1], bitmasks[1] ) ;
                }
            }
        }
        data += w ;
    }

    sbi( ports[2], bitmasks[2] ) ;
}
#endif