#ifdef ESP32
  #include <ILI9488_SPI_18BIT.h>
#else
  #include <ILI9486_Parallel.h>
#endif

using namespace tft_framework;
Screen* scr;

class Star: public Shape {
	private:
	int len;

	public:
	void setLength (int len){
		this->len = len ;
	}

	int getSize ( ) {
		return len;
	}

	void draw ( Screen* scr ) {
		Line l;
		l.setPoint(*this);
		l.setColor(*this);

		int degree = 0;

		for ( int i=0; i<5;i++){
			l.lineTo ( degree , len ) ;
			degree += 144 ;
			l.draw ( scr ) ;
			l.setPoint (l.getEndPoint());
		}
	}
} ;

void setup() {
    #ifdef ESP32
		uint8_t bl = 32;
		pinMode ( bl, OUTPUT ) ;
		digitalWrite ( bl, HIGH ) ;

		uint8_t dc = 27;

    /*
		uint8_t cs = SS,
			
		uint32_t clock = 27000000 ;

		SPIClass* spi = new SPIClass(VSPI);
		spi->begin(SCK, MISO, MOSI, cs);

		spi -> beginTransaction(SPISettings(clock, MSBFIRST, SPI_MODE0));

		uint16_t w = 480, h = 320 ;

		scr = new ILI9488_SPI_18BIT ( w, h, spi, cs, dc ) ;
    */
    
    scr = new ILI9488_SPI_18BIT ( dc ) ;
    #else
		scr = new ILI9486_Parallel ( ) ;
    #endif

    scr -> init ( ) ;
    scr -> clear ( ) ;

	Star star ;
	star.setPoint(240,160);
	star.setColor(0xFFFF);
	star.setLength ( 100 ) ;
	star.draw(scr);
}

void loop(){
	delay ( 10000 ) ;
}
