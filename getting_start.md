# tft_framework
TFT Framework is the graphic interface for TFT Screen with Arduino.
I've tested it with Arduino Mega 2560, Arduino Due and ILI9486 16bit parallel 3.5inch TFT Screen.
There is a sample:
https://youtu.be/qud3bSVzDqk

![image](./01.jpg)
![image](./02.jpg)

# Hello World
```cpp
#include <ILI9486_Parallel.h>

using namespace tft_framework;

Screen* scr;

void setup () {
    scr = new ILI9486_Parallel ( ) ;
    scr -> init ();
    scr -> clear ();
    scr -> println ( "Hello world" );   // Print text to the screen
}

void loop () { delay ( 100000 ) ; }
```
