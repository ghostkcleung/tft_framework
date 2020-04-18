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

# Usage of Point

```cpp
Point p1 ( 10, 20 );    // x: 10, y: 20

scr -> println ( p1.getX ( ) );     // 10
scr -> println ( p1.getY ( ) );     // 20

p1.setPoint ( 30, 40 );  // x: 30, y: 40
p1.setX ( 50 );          // x: 50
p1.setY ( 60 );          // y: 60

// Move the point to direction 135 degree ( Bottom Right ) , distance 50.
p1.Move ( 135, 50 );    
scr -> println ( p1.getX ( ) );     // 85
scr -> println ( p1.getY ( ) );     // 95

Point p2;
p2.setPoint ( p1 ) ;    // Set the X, Y of p2 same as p1

Point p3 ( p1 ) ;       // Create the point and set it as p1
```
