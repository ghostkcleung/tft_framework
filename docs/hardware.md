# Supported Hardware

The core concept of this library is hardware abstraction. As long as your hardware can implement the `fillRect()` function, all other drawing functions become available automatically.

## Tested Platforms

TFT Framework supports most Arduino-compatible boards. The following configurations have been tested:

- **Arduino Mega 2560** with ILI9486 (16-bit parallel)
- **Arduino Due** with ILI9486 (16-bit parallel)
- **ESP32** with ILI9488 (SPI)
- **ESP32** with ST7796s (SPI)

### Development Boards

- [Arduino Mega 2560](https://docs.arduino.cc/hardware/mega-2560)
- [Arduino Due](https://docs.arduino.cc/hardware/due)
- [ESP32-DevKitC V4](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/hw-reference/esp32/get-started-devkitc.html)

### LCD Modules

- [3.5" ILI9486 16-bit Parallel](http://www.lcdwiki.com/zh/3.5inch_16BIT_Module_ILI9486_SKU:MRB3503)
- [3.5" ILI9488 SPI](http://www.lcdwiki.com/zh/3.5inch_SPI_Module_ILI9488_SKU:MSP3520)
- [4.0" ST7796s SPI](http://www.lcdwiki.com/zh/3.5inch_SPI_Module_ILI9488_SKU:MSP3520)

## Performance Considerations

The 16-pin parallel bus offers significantly faster data transfer compared to SPI, making it ideal for Arduino Mega or Due. However, parallel connections require more pins and complex wiring, especially with ESP32.

## Recommended Setup

**ESP32 + ST7796s (SPI)** is the recommended combination for new projects due to:

- Higher processing performance
- More memory (RAM and Flash)
- Multi-tasking support (FreeRTOS)
- Built-in WiFi and Bluetooth
- Internal storage (SPIFFS/LittleFS)
- Full Arduino compatibility
- Simpler SPI wiring

## Initialization Examples

### ILI9486 16-bit Parallel (Arduino Mega/Due)

This display module is designed for Arduino Mega 2560 and Due with pin-compatible headers. Simply attach the display to the board.

```cpp
#include <ILI9486_Parallel_16Bit.h>

using namespace tft_framework;

Screen* scr;

void setup() {
    scr = new ILI9486_Parallel_16Bit();
    scr->init();
}

void loop() {
    delay(100000);
}
```

### ESP32 with SPI Displays

The framework provides implementations for ILI9488 and ST7796s displays using SPI communication at 40MHz by default.

**Demo:** [ILI9488 with ESP32](https://youtu.be/k89JIES1duM)

#### Default Wiring

| Display Pin | ESP32 Pin | Function |
|------------|-----------|----------|
| VDD | 3V3 | Power |
| GND | GND | Ground |
| CS | 5 | Chip Select |
| RST | EN | Reset |
| D/C | 27 | Data/Command |
| SDI | 23 | MOSI |
| SCK | 18 | Clock |
| BL | 32 | Backlight |
| SDO | 19 | MISO |

**Recommended PWM Pins for Backlight:** 4, 16, 17, 27, 32, 33

**Reference:** [ESP32 Pinout Guide](https://randomnerdtutorials.com/esp32-pinout-reference-gpios/)

#### Basic Implementation

```cpp
#include <ILI9488_SPI_18Bit.h>
// or
#include <ST7796s_SPI_16Bit.h>

using namespace tft_framework;
Screen* scr;

void setup() {
    // Configure backlight
    uint8_t bl = 32;
    pinMode(bl, OUTPUT);
    digitalWrite(bl, HIGH);

    // Set data/command pin
    uint8_t dc = 27;

    // Initialize display
    scr = new ILI9488_SPI_18BIT(dc);
    // Or: scr = new ST_7796s_SPI_16Bit(dc);
    scr->init();
}
```

#### Custom Pin Configuration

For custom wiring configurations, use the advanced constructor:

```cpp
using namespace tft_framework;
Screen* scr;

void setup() {
    // Configure backlight
    uint8_t bl = 32;
    pinMode(bl, OUTPUT);
    digitalWrite(bl, HIGH);

    // Pin configuration
    uint8_t cs = SS;
    uint8_t dc = 27;

    // SPI settings
    uint32_t clock = 27000000;  // 27 MHz

    // Initialize SPI bus
    SPIClass* spi = new SPIClass(VSPI);
    spi->begin(SCK, MISO, MOSI, cs);
    spi->beginTransaction(SPISettings(clock, MSBFIRST, SPI_MODE0));

    // Screen dimensions
    uint16_t w = 480, h = 320;
    
    // Initialize display with custom configuration
    scr = new ILI9488_SPI_18BIT(w, h, spi, cs, dc);
    // Or: scr = new ST7796s_SPI_16Bit(w, h, spi, cs, dc);
    scr->init();
}
```
