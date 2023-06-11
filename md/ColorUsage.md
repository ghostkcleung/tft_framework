# Usage of Color

The tft_framework is using 5-6-5 color format. The following picture show how does the 16bit color work.

<img src="565color.jpg" width="903" />

The Color object have a uint16_t property. We can access it by some public method also.

## Create a Color object
The easiest way to create a Color object.
```cpp
Color c;          // c will be initialled as black color (0).
```
We can feed an initial values at creation time
```cpp
Color c(0xFFFF);  // c will be init as white color (0xFFFF).
                  // The data type is uint16_t
```

And we can feed a RGB value also
```cpp
Color c(127, 127, 127);  // Grey color, 3 params type: uint8_t
```

## Setter and getter
The following methods can get or set the property of the Color object.
```cpp
uint16_t getColor();

void setColor(uint16_t c);
void setColor(Color c);
```
## Exchange with 24bit RGB
There is little distortion when exchange with RGB each other.
```cpp
uint32_t getRGB();
void setRGB(uint32_t rgb);

uint8_t getR();
uint8_t getG();
uint8_t getB();

void setR(uint8_t r);   // Range: 0 to 255
void setG(uint8_t g);
void setB(uint8_t b);
```

## Example
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

// There is little distortion when covert from RGB to 565
scr -> println ( c1.getR ( ), HEX ) ;    // Output: 98
scr -> println ( c1.getG ( ), HEX ) ;    // Output: 64
scr -> println ( c1.getB ( ), HEX ) ;    // Output: 30
scr -> println ( c1.getRGB ( ), HEX ) ;    // Output: 986430

Color c2;
c2.setColor ( c1 );     // Set the color content same as c1
```

## About distortion
When we exchange with 24bit RGB data. We will get distortion as follow:

```Input Color: 0x336699

R:0x33 = 00110011
G:0x66 = 01100110
B:0x99 = 10011001
```
The color will store to 16bit as follow:
```
R: 00110011, to 5-bit: 00110
G: 01100110, to 6-bit: 011001
B: 10011001, to 5-bit: 10011
```
When we get back 24-bit value, distortion as follow:
```
R: 00110,  to 8-bit: 00110000, 0x30
G: 011001, to 8-bit: 01100100, 0x64
B: 10011,  to 8-bit: 10011000, 0x98

Output Color: 0x306498
```
