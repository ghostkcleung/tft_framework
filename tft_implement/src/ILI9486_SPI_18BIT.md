# Add support ESP32 with ILI9486 18-Bit

The ILI9488 SPI 18-Bit(6-6-6 Color) has implemented. It support for ESP32 only temporary (Basically it should be support ALL of MCU which have SPI).

YouTube Demo: https://youtu.be/k89JIES1duM

![image](./ILI9486_SPI_18BIT.jpg)

## Default Wiring
VDD => 3V3\
GND => GND\
CS  => 5 (CS)\
RST => EN\
D/C => 27 (Or any output pin)\
SDI => 23 (MOSI)\
SCK => 18 (CLK)\
BL  => 32 (Or any output pin)\
SDO => 19 (MISO)

The recommended PWM output pin is:\
4, 16, 17, 27, 32, 33
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
## Custumize pins
If you wiring with your customize pins. The code will be similar to following.
```cpp
#ifdef ESP32
	uint8_t bl = 32;
	pinMode ( bl, OUTPUT ) ;
	digitalWrite ( bl, HIGH ) ;

	uint8_t cs = SS,
		dc = 27;

	uint32_t clock = 27000000 ;

	SPIClass* spi = new SPIClass(VSPI);
	spi->begin(SCK, MISO, MOSI, cs);

	spi -> beginTransaction(SPISettings(clock, MSBFIRST, SPI_MODE0));

	uint16_t w = 480, h = 320 ;

	scr = new ILI9488_SPI_18BIT ( w, h, spi, cs, dc ) ;
#endif
```
