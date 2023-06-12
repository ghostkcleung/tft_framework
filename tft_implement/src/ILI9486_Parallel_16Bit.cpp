#if defined ( __AVR_ATmega2560__ ) || defined ( __SAM3X8E__ )

#include <ILI9486_Parallel_16Bit.h>

using namespace tft_framework;

void ILI9486_Parallel_16Bit::init()
{
#ifdef __AVR_ATmega2560__
	DDRA = 0xFF;
	DDRC = 0xFF;
#endif

#ifdef __SAM3X8E__
	REG_PIOA_OER = 0x0000c000;
	REG_PIOB_OER = 0x04000000;
	REG_PIOD_OER = 0x0000064f;
	REG_PIOA_OER = 0x00000080;
	REG_PIOC_OER = 0x0000003e;
#endif

	sbi(ports[3], bitmasks[3]);
	delay(5);
	cbi(ports[3], bitmasks[3]);
	delay(15);
	sbi(ports[3], bitmasks[3]);
	delay(15);

	cbi(ports[2], bitmasks[2]);

	writeCom(0x11); // Sleep OUT
	delay(120);

	// ?????
	{
		uint8_t datas[] = {
			0x1C, 0xA3, 0x32, 0x02, 0xb2,
			0x12, 0xFF, 0x12, 0x00};

		writeComs(0xF2, datas, sizeof(datas));
	}

	writeCom16(0xF1, 0x36A4); // ?????
	writeCom16(0xF8, 0x2104); // ?????
	writeCom16(0xF9, 0x0008); // ?????

	writeCom16(0xC0, 0x0d0d); // Power Control 1
	writeCom16(0xC1, 0x4300); // Power Control 2
	writeCom(0xC2, 0x0000);	  // Power Control 3

	writeCom16(0xC5, 0x0048); // VCOM Control

	// ?????
	{
		uint8_t datas[] = {0x00, 0x22, 0x3b};
		writeComs(0xB6, datas, sizeof(datas));
	}

	// PGAMCTRL (Positive Gamma Control)
	{
		uint8_t datas[] = {
			0x0f, 0x24, 0x1c, 0x0a, 0x0f,
			0x08, 0x43, 0x88, 0x32, 0x0f,
			0x10, 0x06, 0x0f, 0x07, 0x00};

		writeComs(0xE0, datas, sizeof(datas));
	}

	// NGAMCTRL (Negative Gamma Control)
	{
		uint8_t datas[] = {
			0x0F, 0x38, 0x30, 0x09, 0x0f,
			0x0f, 0x4e, 0x77, 0x3c, 0x07,
			0x10, 0x05, 0x23, 0x1b, 0x00};

		writeComs(0xE1, datas, sizeof(datas));
	}

	writeCom(0x20); // Display Inversion OFF

	writeCom(0x36, 0b10101000); // Memory Access Control

	writeCom(0x3A, 0x55); // Interface Pixel Format

	// Column Addess Set
	{
		uint8_t datas[] = {
			0x00, 0x00, 0x01, 0xDF};

		writeComs(0x2A, datas, sizeof(datas));
	}

	// Page Address Set
	{
		uint8_t datas[] = {
			0x00, 0x00, 0x01, 0x3F};

		writeComs(0x2B, datas, sizeof(datas));
	}

	delay(50);
	writeCom(0x29); // Display ON
	writeCom(0x2C); // Memory Write
	sbi(ports[2], bitmasks[2]);
}

void ILI9486_Parallel_16Bit::fillRect(Rectangle *r)
{
	setWindow(r);

	uint16_t color = r->getColor();

	feedValue(color >> 8, color);

	uint32_t count = (uint32_t)r->getWidth() * r->getHeight();
	while (count--)
	{
		pulseLow(ports[1], bitmasks[1]);
	}
	sbi(ports[2], bitmasks[2]);
};

void ILI9486_Parallel_16Bit::setRotate(uint8_t rotate)
{
    rotate %= 8;
    if (getRotate()==rotate) {
        return;
    }

    Screen::setRotate(rotate);

    cbi( ports[2], bitmasks[2] );
    switch ( rotate ) {
    case 0:
        writeCom ( 0x36, 0b10101000 ) ;
        break;
    case 1:
        writeCom ( 0x36, 0b00101000 ) ;
        break;
    case 2:
        writeCom ( 0x36, 0b00001000 ) ;
        break;
    case 3:
        writeCom ( 0x36, 0b01001000 ) ;
        break;
    case 4:
        writeCom ( 0x36, 0b01101000 ) ;
        break;
    case 5:
        writeCom ( 0x36, 0b11101000 ) ;
        break;
    case 6:
        writeCom ( 0x36, 0b11001000 ) ;
        break;
    case 7:
        writeCom ( 0x36, 0b10001000 ) ;
        break;
    }

    sbi( ports[2], bitmasks[2] );
}

void ILI9486_Parallel_16Bit::fillShape(BufferScreen *buf)
{
	uint8_t scale = buf->getScale();

	if ( ! scale ) {
		return ;
	}

    Rectangle r ;
    r.setPoint ( *buf ) ;
    uint16_t w = buf->getWidth ( ),
            h = buf->getHeight ( ) ;

	if ( ( buf -> getRotate ( ) / 2 ) % 2 ) {
		uint16_t tmp = w;
		w = h; h = tmp;
	}

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

void ILI9486_Parallel_16Bit::drawShape(Dot *d)
{
	uint16_t x = d->getX()
		, y = d->getY(), color = d-> getColor();

	cbi( ports[2], bitmasks[2] ) ;

	{ uint8_t datas[] = { x >> 8, x, x >> 8, x } ;
	writeComs ( 0x2A, datas, 4 ) ; }

	{ uint8_t datas[] = { y >> 8, y, y >> 8, y } ;
	writeComs ( 0x2B, datas, 4 ) ; }

    writeCom ( 0x2c ) ;

    sbi( ports[0], bitmasks[0] ) ;
	feedValue ( color >> 8, color ) ;
	pulseLow ( ports[1], bitmasks[1] ) ;
    sbi ( ports[2], bitmasks[2] );
}

void ILI9486_Parallel_16Bit::fillShape(Bitmap *bmp)
{
if ( bmp -> getColorDepth ( ) == 16 ) {
	Rectangle viewport = bmp -> getViewport ( ) ;
	if ( ! sortRect ( &viewport, bmp ) ) { return ; }

	viewport.moveTo ( *bmp ) ;
	if ( ! sortRect ( &viewport, this ) ) { return ; }

	uint16_t viewH = viewport.getHeight ( )
		, viewW = viewport.getWidth ( )
		, imgW = bmp -> getWidth ( )
		, bufSize = viewW * 2 ;

	int16_t viewY = viewport.getY ( );

	byte bytes [ bufSize ] ;

	viewport.moveToY ( getHeight ( ) - viewH - viewY ) ;

	uint8_t rotate = getRotate ( ) ;
	setRotate ( ( rotate + 5 ) % 8 ) ;

	setWindow(&viewport);

	viewport.moveTo ( bmp -> getViewport ( ) ) ;

	int16_t viewX = viewport.getX ( ) ;
	viewY = viewport.getY ( ) ;

	File f = bmp -> getFile ( ) ;
	f.seek ( bmp -> getDataOffset ( ) + ( bmp -> getHeight ( ) - viewH - viewY ) * imgW * 2 ) ;

	for ( int y = 0; y < viewH; y ++ ) {
		f.seek ( f.position ( ) + viewX * 2 ) ;
		f.read ( bytes, bufSize ) ;
		for ( int x = 0; x < viewW; x ++ ) {
			feedValue ( bytes [ x * 2+1 ], bytes [ x * 2 ] ) ;
			pulseLow ( ports[1], bitmasks[1] ) ;
		}
		f.seek ( f.position ( ) + ( imgW - viewX - viewW ) * 2 ) ;
	}

	sbi ( ports[2], bitmasks[2] );
	setRotate ( rotate ) ;
} else {
	bmp -> fillGeneric ( this ) ;
}
}

#endif