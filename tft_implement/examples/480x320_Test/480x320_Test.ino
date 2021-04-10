#include <ILI9486_Parallel.h>

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

    scr = new ILI9486_Parallel ( ) ;
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
