# Add support ESP32 with ILI9486 18-Bit

The ILI9488 SPI 18-Bit(6-6-6 Color) has implemented. It support for ESP32 only temporary (Basically it should be support ALL of MCU which have SPI).

YouTube Demo: https://youtu.be/k89JIES1duM

![image](./ILI9486_SPI_18BIT.jpg)

## Default Wiring
VDD => 3V3\
GND => GND\
CS  => 5\
RST => EN\
D/C => 27\
SDI => 23\
SCK => 18\
BL  => 32\
SDO => 19
## Coding
This is the easier way to create the Screen Object.
```cpp
#ifdef ESP32
  #include <ILI9488_SPI_18BIT.h>
#endif

using namespace tft_framework;
Screen* scr;

void setup() {

    #ifdef ESP32
		uint8_t bl = 32;
		pinMode ( bl, OUTPUT ) ;
		digitalWrite ( bl, HIGH ) ;

		uint8_t cs = SS,
			dc = 27;
    
    scr = new ILI9488_SPI_18BIT ( dc ) ;
    #endif
    
    scr -> init();
    scr -> setPrintBuffer ( true ) ;
    scr -> clear ( ) ;
}
```
