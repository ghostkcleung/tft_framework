#include <Mega2560_16Bit_ILI9486.h>
#include "splashScreenData.h"

using namespace tft_framework;

Screen* scr;

void setup()
{
    scr = new Mega2560_16Bit_ILI9486 ( );
    scr -> init ( ) ;
    scr -> setColor ( 0xFFFF ) ;

    scr -> clear ( ) ;
    Line l;
    l.setRGB ( 0x979C ) ;

    int16_t x = 0, y = 281;

    for ( int i = 0; i < 2570; i ++ )
    {
        uint16_t len = pgm_read_word_near(splashScreenData + i);

        if ( i % 2 )
        {
            l.setPoint ( x+60, y ) ;

            if ( x + len < 360 )
            {
                x += len;
                l.setEndPoint ( x+60, y ) ;
                l.draw ( scr ) ;
            }
            else
            {
                l.setEndPoint ( 419, y -- ) ;
                l.draw ( scr ) ;

                x = len - ( 360 - x ) ;
                l.setPoint ( 60, y );
                l.setEndPoint ( x+60, y );
                l.draw ( scr ) ;
            }
        }
        else
        {
            if ( x + len < 360 )
            {
                x += len ;
            }
            else
            {
                y -= len / 360 + 1 ;
                len %= 360;
                x = len - ( 360 - x ) ;
            }
        }
    }
}

void loop ( )
{
    delay ( 1000000 ) ;
}
