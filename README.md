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
p1.move ( 135, 50 );    
scr -> println ( p1.getX ( ) );     // Output: 85
scr -> println ( p1.getY ( ) );     // Output: 95

Point p2;
p2.setPoint ( p1 ) ;    // Set the X, Y of p2 same as p1

Point p3 ( p1 ) ;       // Create the Point and init as p1
```

# Usage of Color
```cpp
// The data of Color is stored as 16 bit(565)
Color c1 ( 0 ) ;                        // Init the color to black
c1.setColor ( 0xFFFF );                 // Set to white
scr -> println ( c1.getColor ( ) ) ;    // Output: 65535

c1.setRGB ( 0xFF0000 ); // Set to Red
c1.setRGB ( 0x00FF00 ); // Set to Green
c1.setRGB ( 0x0000FF ); // Set to Blue

c1.setColor ( 0 );
c1.setR ( 0x99 );   // 0x990000
c1.setG ( 0x66 );   // 0x996600
c1.setB ( 0x33 );   // 0x996633

// There is some lost when covert from RGB to 565
scr -> println ( c1.getR ( ), HEX ) ;    // Output: 94
scr -> println ( c1.getG ( ), HEX ) ;    // Output: 65
scr -> println ( c1.getB ( ), HEX ) ;    // Output: 31
scr -> println ( c1.getRGB ( ), HEX ) ;    // Output: 946531

Color c2;
c2.setColor ( c1 );     // Set the color content same as c1

Color c3 ( c1 );        // Create the Color and init as c1
```
