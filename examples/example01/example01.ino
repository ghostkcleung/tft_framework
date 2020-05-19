#include <Mega2560_16Bit_ILI9486.h>

using namespace tft_framework;

Screen* scr;
Line l;

void setup () {
    scr = new Mega2560_16Bit_ILI9486 () ;
    scr -> init ();
    scr -> setColor ( 0xFFFF ) ;

    randomSeed ( analogRead ( A0 ) ) ;
}


void loop () {
  int x = scr -> getWidth ( ) / 2 ;
  int y = scr -> getHeight ( ) / 2 ;
  l.setPoint ( x, y ) ;

  scr -> clear ( ) ;

  for ( int i = 0; i < 1000 ; i ++ ) {
    int angle = random ( 360 ) ;
    l.setColor ( random ( 0xFFFF ) ) ;
    l.lineTo ( angle, 5 ) ;
    l.draw ( scr ) ;
    l.setPoint ( l.getEndPoint ( ) ) ;
  }

  delay ( 5000 ) ;
}
