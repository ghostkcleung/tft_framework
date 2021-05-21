#ifdef ESP32
  #include <ILI9486_SPI_18BIT.h>
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

		scr = new ILI9486_SPI_18BIT ( 27 ) ;
    #else
		scr = new ILI9486_Parallel ( ) ;
    #endif
    
    scr -> init();
    scr -> setFontScale ( 2 ) ;
    scr -> setFontPadding ( 1 ) ;
    scr -> setPrintBuffer ( true ) ;
    scr -> clear ( ) ;
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
