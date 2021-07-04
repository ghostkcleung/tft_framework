#ifdef ESP32
#include <ILI9488_SPI_18BIT.h>

using namespace tft_framework;

ILI9488_SPI_18BIT::ILI9488_SPI_18BIT(uint8_t dc):ILI9486(480,320){
	cs = SS;
	this -> dc = dc;

	spi = new SPIClass(VSPI);
	spi->begin(SCK, MISO, MOSI, SS);

	spi -> beginTransaction(SPISettings(27000000, MSBFIRST, SPI_MODE0));
}

void ILI9488_SPI_18BIT::writeComs ( uint8_t com, uint8_t *datas, unsigned int count ){

	GPIO.out_w1tc = (1 << cs) ;
	GPIO.out_w1tc = (1 << dc) ;
	spi -> transfer ( com ) ;
	GPIO.out_w1ts = (1 << cs) ;

	if ( count ) {
		GPIO.out_w1tc = (1 << cs) ;
		GPIO.out_w1ts = (1 << dc) ;
		spi -> transfer ( datas, count ) ;
		GPIO.out_w1ts = (1 << cs) ;
	}
}

void ILI9488_SPI_18BIT::init() {

	pinMode(cs, OUTPUT);
	pinMode(dc, OUTPUT);
	digitalWrite(cs, HIGH);
	digitalWrite(dc, HIGH);

	writeCom(0x01);
	delay(150);


    writeCom(0x11);
    delay(120);

    writeCom(0x3A, 0x66);
	writeCom(0xC2, 0x44);

	{ uint8_t datas[] = {
		0x00, 0x00, 0x00, 0x00 } ;

    writeComs( 0xC5, datas, sizeof ( datas ) );	}

	{ uint8_t datas[] = {
		0x0F, 0x1F, 0x1C, 0x0C,
		0x0F, 0x08, 0x48, 0x98,
		0x37, 0x0A, 0x13, 0x04,
		0x11, 0x0D, 0x00 } ;

    writeComs( 0xE0, datas, sizeof ( datas ) );	}

	{ uint8_t datas[] = {
		0x0F, 0x32, 0x2E, 0x0B,
		0x0D, 0x05, 0x47, 0x75,
		0x37, 0x06, 0x10, 0x03,
		0x24, 0x20, 0x00 } ;

    writeComs( 0xE1, datas, sizeof ( datas ) );	}
	writeCom ( 0x36, 0b00100000 ) ;

	writeCom(0x20);
    writeCom(0x29);
	
}

void ILI9488_SPI_18BIT::setWindow ( Rectangle* r ) {
    uint16_t x1 = r -> getX(),
            y1 = r -> getY(),
            x2 = r -> getEndX(),
            y2 = r -> getEndY();

	{ uint8_t datas[] = { x1 >> 8, x1, x2 >> 8, x2 } ;
	writeComs ( 0x2A, datas, 4 ) ; }

	{ uint8_t datas[] = { y1 >> 8, y1, y2 >> 8, y2 } ;
	writeComs ( 0x2B, datas, 4 ) ; }

    writeCom ( 0x2C ) ;

}

void ILI9488_SPI_18BIT::fillRect ( Rectangle* r ) {
	setWindow(r);

	uint32_t area =
		(uint32_t)r->getWidth()
		* r->getHeight();

	GPIO.out_w1tc = (1 << cs) ;
	GPIO.out_w1ts = (1 << dc) ;

	uint16_t color = r -> getColor ( ) ;

	int bufSize=128;
	uint8_t buf[bufSize*3];

	uint8_t blue = r -> getB();
	uint8_t green = r -> getG();
	uint8_t red = r -> getR();

	while(area >= bufSize) {
		for(int i=0; i< bufSize*3; i+=3){
			buf[2+i] = red ;
			buf[1+i] = green ;
			buf[0+i] = blue ;
		}

		spi -> transfer(buf ,bufSize*3);
		area -= bufSize ;
	}


	buf[2] = red ;
	buf[1] = green ;
	buf[0] = blue ;
	spi -> writePattern ( buf, 3, area ) ;

	GPIO.out_w1ts = (1 << cs) ;

};

void ILI9488_SPI_18BIT::setRotate(uint8_t rotate) {
    rotate %= 8;
    if (getRotate()==rotate) {
		return;
	}

    Screen::setRotate(rotate);

    switch ( rotate ) {
    case 0:
        writeCom ( 0x36, 0b00100000 ) ;
        break;

    case 1:
        writeCom ( 0x36, 0b10100000 ) ;
        break;

    case 2:
        writeCom ( 0x36, 0b10000000 ) ;
        break;

    case 3:
        writeCom ( 0x36, 0b11000000 ) ;
        break;

    case 4:
        writeCom ( 0x36, 0b11100000 ) ;
        break;

    case 5:
        writeCom ( 0x36, 0b01100000 ) ;
        break;

    case 6:
        writeCom ( 0x36, 0b01000000 ) ;
        break;

    case 7:
        writeCom ( 0x36, 0b00000000 ) ;
        break;
    }
}

void ILI9488_SPI_18BIT::fillShape(BufferScreen* buf) {

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

	GPIO.out_w1tc = (1 << cs) ;
	GPIO.out_w1ts = (1 << dc) ;

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
                Color c ( *col ++ );
				
                sx = scale ;

                while ( sx-- > 0 ) {
					spi -> transfer ( c.getB() ) ;
					spi -> transfer ( c.getG() ) ;
					spi -> transfer ( c.getR() ) ;
                }
            }
        }
        data += w ;
    }

	GPIO.out_w1ts = (1 << cs) ;

}

void ILI9488_SPI_18BIT::drawShape ( Dot *d ) {

	uint16_t x = d->getX()
		, y = d->getY();

	{ uint8_t datas[] = { x >> 8, x, x >> 8, x } ;
	writeComs ( 0x2A, datas, 4 ) ; }

	{ uint8_t datas[] = { y >> 8, y, y >> 8, y } ;
	writeComs ( 0x2B, datas, 4 ) ; }

    writeCom ( 0x2c ) ;

	GPIO.out_w1tc = (1 << cs) ;
	GPIO.out_w1ts = (1 << dc) ;

	spi -> transfer ( d -> getB() ) ;
	spi -> transfer ( d -> getG() ) ;
	spi -> transfer ( d -> getR() ) ;

	GPIO.out_w1ts = (1 << cs) ;

}

void ILI9488_SPI_18BIT::fillShape ( Bitmap *bmp ) {
	if ( bmp -> getColorDepth ( ) == 24 ) {
		File f = bmp -> getFile ( ) ;
		f.seek ( bmp -> getDataOffset ( ) ) ;

		uint16_t w = bmp -> getWidth ( ),
			h = bmp -> getHeight ( ) ;

		Rectangle r ;
		r.setPoint ( *bmp ) ;
		r.setSize ( w, h ) ;

		setWindow ( &r ) ;

		GPIO.out_w1tc = (1 << cs) ;
		GPIO.out_w1ts = (1 << dc) ;

		byte bytes[ w * 3 ] ;

		for ( uint16_t y = 0; y < h; y ++ ) {
			f.read ( bytes, w * 3 ) ;
			spi -> transfer ( bytes, w * 3 ) ;
		}
		
		GPIO.out_w1ts = (1 << cs) ;
	} else {
		bmp -> fillGeneric ( this ) ;
	}
}

ILI9488_SPI_18BIT::~ILI9488_SPI_18BIT() {
	spi -> endTransaction();
	spi -> end();
	delete spi ;
}
#endif