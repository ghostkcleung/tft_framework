#include <Mega2560_16Bit_ILI9486.h>
#include "matrix.h"

using namespace tft_framework;

Screen* scr;

void setup()
{
    scr = new Mega2560_16Bit_ILI9486 ( );
    scr -> init ( ) ;
    scr -> setColor ( 0xFFFF ) ;
    scr -> clear ( ) ;

    Dot d;
    d.setRGB ( 0x979C ) ;

    int p = 0, x = 0, y = 0;

    for ( int i = 0; i < 11025; i ++ )
    {
        uint8_t bits = pgm_read_byte_near(m+p++);

        for ( int j = 0; j < 8; j++ )
        {

            d.setPoint ( 60 + x ++, 283 - y);

            if ( bits & ( 1 << j ) )
            {
                d.draw ( scr ) ;
            }

            if ( x == 360 )
            {
                y ++;
                x = 0 ;
            }
        }
    }
}

void loop ( )
{
    delay ( 1000000 ) ;
}
