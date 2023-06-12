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
