# tft_framework
TFT Framework is the graphic interface for TFT Screen with Arduino.
I've tested it with Arduino Mega 2560 and ILI9486 16bit parallel 3.5inch TFT Screen.
There is a sample:
https://youtu.be/RjGyStkZ0k4

01.jpg 02.jpg

# Hello World
```cpp
#include <Mega2560_16Bit_ILI9486.h>

using namespace tft_framework;

Screen* scr;

void setup () {
    scr = new Mega2560_16Bit_ILI9486 () ;
    scr -> init ();
    scr -> clear ();
    scr -> println ( "Hello world" );   // Print text to the screen
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

# Shape
The following type is inherit Shape:
- Dot
- Line
- Rectangle
- Triangle
- Circle
- Ellipse
- Font

All of them have the properties of Point and Color.
They are Drawable. And most of them are Fillable except:

- Dot
- Line
- Font

# Usage of Dot
```cpp
Dot d;
d.setPoint ( 10, 20 );  // Set the position of the dot.
d.setRGB ( 0xFF0000 );  // Set the color of the dot.
d.draw ( scr ) ;        // Draw the dot to the screen.

for ( int x = 15; x < 100; x ++ ) {
    d.move ( 90, 5 );   // Move to right, distance 5.
    d.draw ( scr );     // Draw each iterated dot.
}
```

# Usage of Line
```cpp
Line l;
l.setPoint ( 10, 20 );      // Start point
l.setEndPoint ( 50, 60 );   // End point
l.draw ( scr );

l.lineTo ( 135, 50 );   // Set the end to 135 degree of start point, distance 50
l.draw ( scr );
```

# Usage of Rectangle
```cpp
Rectangle r;
r.setPoint ( 10, 20 );       // Start Point
r.setEndPoint ( 60, 100 ) ;  // End Point
r.draw ( scr );              // Draw the rectangle to screen

r.setPoint ( 100, 50 );
r.setWidth ( 60 );           // End point of X: 159
r.setHeight ( 120 );         // End point of X: 169
// You may also write it as: r.setSize ( 60, 120 ) ;
r.fill ( scr );              // Fill to screen
```

# Usage of Triangle
```cpp
Triangle t;
t.setPoint ( 10, 10 );      // The first point
t.setP2 ( 10, 40 );         // The second point
t.setp3 ( 50, 40 );         // The third point
t.draw ( scr );             // There will be right angle triangle 30, 40, 50 
```

# Usage of Circle
```cpp
Circle c;
c.setPoint ( 150, 100 );    // Center point
c.setRadius ( 70 );         // Radius
c.fill ( scr );             // Fill to screen
```

# Usage of Ellipse
```cpp
Ellipse e;
c.setPoint ( 150, 150 );    // Center point
e.setRx ( 70 );             // Rx
e.setRy ( 100 );            // Ry
e.fill ( scr );
```

# Font
```cpp
Font *f = new Font5X7();     // Usually the font is assigned to pointer.
f -> setChar ( 'A' );        // Set character
f -> setRGB ( 0x0000FF );    // Set to Blue
f -> setPoint ( 10, 20 );
f -> draw ( scr ) ;

f -> setScale ( 3 );         // Scale the font to 3x.
f -> setPoint ( 50, 20 );
f -> draw ( scr ) ;

delete f;                   // Deallocate
```

# Print
The Screen class is inherit offical Print class.
So you can print the text easier than draw each font.
The usage of print just like Serial.print()
```cpp

scr -> setFont ( new Font5X7() );               // It's not necessary when using default font.
scr -> setFontColor ( Color ( 0x0000FF ) ) ;    // Set the print color to blue.
scr -> setFontScale ( 3 );                      // Set the font size to 3x.
scr -> setFontPadding ( 1 ) ;                   // The distance of each char.
scr -> setCursor ( 18, 24 );                    // Set the print cursor

scr -> println ( 78 );              // 78
scr -> println ( 1.23456 );         // 1.23
scr -> println ( 'N' );             // N
scr -> println ( "Hello world." );  // Hello world.

scr -> println(78, BIN);      // 1001110
scr -> println(78, OCT);      // 116
scr -> println(78, DEC);      // 78
scr -> println(78, HEX);      // 4E
scr -> println(1.23456, 0); // 1
scr -> println(1.23456, 2); // 1.23
scr -> println(1.23456, 4); // 1.2346
```

# BufferScreen
The buffer is a virtual screen. You can draw something to it to store the content.
Then fill to the real screen. Sometimes it can be more efficiency. The buffer can be enlarge.
But be attention for the limitation of memory size. It need 2byte per pixel. There is 8k bytes inside the Arduino Mega 2560. That means the maxium bounds of buf can be about 60x60 only. And remember to deallocate it when not use. 
60x60x2 = 7200bytes

```cpp
BufferScreen *buf = new BufferScreen ( 40, 40 );      // Create the buffer with bounds 40x40.
buf -> setRGB ( 0xFFFF00 );                     // Set the background Color to yellow.
buf -> clear ( );

Triangle t;
t.setPoint ( 0,39 );
t.setP2 ( 19, 0 );
t.setP3 ( 39, 39);

t.draw ( buf );

buf -> setPoint ( 20, 20 );
buf -> fill ( scr );           // Fill the buffer to real screen

buf -> setScale ( 3 );         // Enlarge to 3x
buf -> setPoint ( 20, 100 );
buf -> fill ( scr );           // Fill the buffer to real screen

delete buf;                                     // Deallocate
```
