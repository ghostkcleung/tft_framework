Class: Dot

Inherit class: Shape

# Usage of Dot

Dot is a 1x1 Rectangle to draw to the screen.
After set the Point(position) and Color, you can draw a dot to the screen.

## Constructor

```cpp
Dot d;
```

## Methods about Point and Color
Dot is inherit Shape. It also contains the methods and properties of Point and Color

```cpp
Dot d;

uint16_t x = 100;
uint16_t y = 50;

uint8_t r = 63;
uint8_t g = 127;
uint8_t b = 255;

d.setPoint ( x, y );
d.setR ( r );
d.setG ( g );
d.setB ( b );
```
