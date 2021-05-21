21-May-2021

# Add support ESP32 with ILI9486 18-Bit

This class is designed for ESP32 only.
And the color interface of the screen module is 18-bit(666) only but not 16-bit(565).
So that you cannot set it by write command(0x3A, 0x55).

I've set some pins for default wiring.

- VDO = VCC
- GND = GND
- CS = 5 ( Or any output pin, but 5 is recommanded )
- D/C = 27 ( Or any output pin )
- SDI = MOSI = 23
- SCK = SCK = 18
- BL = 32 ( Or any output pin )
- SDO = MISO = 19

```cpp
// To create the new instance:

uint8_t bl = 32;
pinMode ( bl, OUTPUT ) ;
digitalWrite ( bl, HIGH ) ;

uint8_t dc = 27;
Screen *scr = new ILI9486_SPI_18BIT ( dc ) ;
```

You may also create the object by your customize pin:
```cpp
uint8_t bl = 32;
pinMode ( bl, OUTPUT ) ;
digitalWrite ( bl, HIGH ) ;

uint8_t cs = 5,
  dc = 27,
  sck = 18,
  miso = 19,
  mosi = 23;

uint32_t clock = 27000000 ;

SPIClass* spi = new SPIClass(VSPI);
spi->begin(sck, miso, mosi, cs);
spi -> beginTransaction(SPISettings(clock, MSBFIRST, SPI_MODE0));

scr = new ILI9486_SPI_18BIT ( spi, cs, dc ) ;
```

![image](./ILI9486_SPI_18BIT.jpg)
