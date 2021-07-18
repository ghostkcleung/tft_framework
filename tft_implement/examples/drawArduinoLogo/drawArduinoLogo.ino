#ifdef ESP32
  #include <ILI9488_SPI_18BIT.h>
#else
  #include <ILI9486_Parallel.h>
#endif

#include "splashScreenData.h"

using namespace tft_framework;
Screen* scr;

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
