#ifdef ESP32
  #include <ILI9488_SPI_18BIT.h>
#else
  #include <ILI9486_Parallel.h>
#endif

using namespace tft_framework;
Screen* scr;

#include "hello.h"
#include "fillScreenTest.h"
#include "drawDotTest.h"
#include "drawLineTest.h"
#include "drawRectTest.h"
#include "fillRectTest.h"
#include "drawTriangleTest.h"
#include "fillTriangleTest.h"
#include "drawCircleTest.h"
#include "fillCircleTest.h"
#include "drawEllipseTest.h"
#include "fillEllipseTest.h"
#include "allColorTest.h"
#include "bufferTest.h"
#include "testDrawFont.h"
#include "testPrint.h"

void setup() {
    randomSeed(analogRead(A0));

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
    
    scr -> init();
    scr -> setPrintBuffer ( true ) ;
    scr -> clear ( ) ;
    
    scr -> getFont ( ) -> setScale ( 2 ) ;
}

void loop ( ) {

  hello();
  fillScreenTest ( );
  drawDotTest ( );
  drawLineTest ( );
  drawRectTest ( );
  fillRectTest ( );
  drawTriangleTest ( );
  fillTriangleTest ( );
  drawCircleTest ( );
  fillCircleTest ( );
  drawEllipseTest ( );
  fillEllipseTest ( );
  allColorTest ( );
  bufferTest ( ) ;
  testDrawFont ( ) ;
  testPrint ( ) ;

  delay ( 1000000 );
}
