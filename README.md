# tft_framework
TFT Framework is the graphic interface for TFT Screen with Arduino.

# Hello World
```cpp
#include <Mega2560_16Bit_ILI9486.h>

using namespace tft_framework;

Screen* scr;

void setup () {
    scr = new Mega2560_16Bit_ILI9486 () ;
    scr -> init ();
    scr -> clear ();
    scr -> println ( "Hello world" );
}

void loop () { delay ( 100000 ) ; }
```
