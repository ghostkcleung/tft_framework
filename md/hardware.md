# Supported Hardware

tft_framework is support most of arduino board. The following modules those are tested.

- Arduino Mega 2560 with ILI9486 parallel.
- Arduino Due with ILI9486 parallel.
- ESP32 with ili9488 SPI.
- ESP32 with st7796s SPI.

Here are some detailed information.
- [Arduino Mega 2560](https://docs.arduino.cc/hardware/mega-2560)
- [Arduino Due](https://docs.arduino.cc/hardware/due)
- [ESP32-DevKitC V4](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/hw-reference/esp32/get-started-devkitc.html)

LCD Modules
- [3.5 inch ILI9486 16 bit  parallel](http://www.lcdwiki.com/zh/3.5inch_16BIT_Module_ILI9486_SKU:MRB3503)
- [3.5 inch ILI9488 SPI](http://www.lcdwiki.com/zh/3.5inch_SPI_Module_ILI9488_SKU:MSP3520)
- [4.0 inch ST7796s](http://www.lcdwiki.com/zh/3.5inch_SPI_Module_ILI9488_SKU:MSP3520)

In terms of transmission, the speed of 16 pins parallel bus is faster than SPI. It is suitable for Arduino Mega or Due. But it is not easy to implement and wiring with ESP32.

For the project, ESP32 is recommended. It has higher performance, more memories, multi task supported and Wifi/BT, internal storage(SPIFFS) built-in. ESP32 is almost fully support Arduino. 

ESP32 with ST7796s is recommended.

The main concept of this library is not about supporting hardware, but rather through this library, as long as the hardware in hand has the implementation of fillRect(), there will be other drawing functions.

## Initialize with 3.5 inch ILI9486 16 bit  parallel
This screen module is designed for Arduino Mega 2560 and Due. The pins is fit already. We just need to combine the screen and MCU module together.

```cpp
#include <ILI9486_Parallel_16Bit.h>

using namespace tft_framework;

Screen* scr;

void setup () {
    scr = new ILI9486_Parallel_16Bit ( ) ;
    scr -> init ();
}

void loop () { delay ( 100000 ) ; }
```

## Initialize with ESP32

For the ESP32, I've made the ILI9488 and ST7796s implements. They are both connecting with SPI. I set the frequency to 40Mhz by default.

ILI9488 demo: https://youtu.be/k89JIES1duM

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

For more details of pinout, you may see this page:\
https://randomnerdtutorials.com/esp32-pinout-reference-gpios/
## Coding
This is the easy way to create the Screen Object.
```cpp
#include <ILI9488_SPI_18Bit.h>
// or
#include <ST7796s_SPI_16Bit.h>
```

```cpp
using namespace tft_framework;
Screen* scr;

void setup() {
	uint8_t bl = 32;
	pinMode ( bl, OUTPUT ) ;
	digitalWrite ( bl, HIGH ) ;

	uint8_t dc = 27;

	scr = new ILI9488_SPI_18BIT ( dc ) ;
	scr -> init();
}
```

## Custumize pins
If you wiring with your customize pins. There is a similar code.
```cpp
using namespace tft_framework;
Screen* scr;

void setup() {
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
	scr -> init();
}
```
