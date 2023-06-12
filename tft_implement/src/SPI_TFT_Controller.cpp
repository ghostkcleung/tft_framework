#ifdef ESP32
#include <SPI_TFT_Controller.h>

using namespace tft_framework;

SPI_TFT_Controller::SPI_TFT_Controller(uint8_t dc){
	cs = SS;
	this -> dc = dc;

	spi = new SPIClass(VSPI);
	spi->begin(SCK, MISO, MOSI, SS);

	spi -> beginTransaction(SPISettings(40000000, MSBFIRST, SPI_MODE0));
}

void SPI_TFT_Controller::writeComs ( uint8_t com, uint8_t *datas, unsigned int count ){

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


void SPI_TFT_Controller::setWindow ( Rectangle* r ) {
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

SPI_TFT_Controller::~SPI_TFT_Controller() {
	spi -> endTransaction();
	spi -> end();

	delete spi ;
}
#endif