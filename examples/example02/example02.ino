#include <Mega2560_16Bit_ILI9486.h>

using namespace tft_framework;

Screen* scr;
Line l;

Color colors[4];

void setup () {
    scr = new Mega2560_16Bit_ILI9486 () ;
    scr -> init ();

    colors [ 0 ].setRGB ( 0xFF0000 ) ;
    colors [ 1 ].setRGB ( 0xFFFF00 ) ;
    colors [ 2 ].setRGB ( 0x0000FF ) ;
    colors [ 3 ].setRGB ( 0xFF00FF ) ;
}


void loop () {
  int x = scr -> getWidth ( ) / 2 ;
  int y = scr -> getHeight ( ) / 2 ;
  l.setPoint ( x, y ) ;

  int angle = 0;

  scr -> clear ( ) ;

  for ( int i = 0; i < 230 ; i ++ ) {
    angle += 92;
    angle %= 360;

    l.setColor ( colors [ i % 4 ] ) ;
    l.lineTo ( angle, i*2 ) ;
    l.draw ( scr ) ;
    l.setPoint ( l.getEndPoint ( ) ) ;
  }

  delay ( 5000 ) ;
}
