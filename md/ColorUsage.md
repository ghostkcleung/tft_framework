# Usage of Color

The tft_framework is using 5-6-5 color format. The following picture show how does the 16bit color work.

<img src="565color.jpg" width="903" />

The Color object have a uint16_t property. We can access it by some public method also.

## Create a Color object
The easiest way to create a Color object.
```cpp
Color c;          // c will be initialled as black color (0).
```
We can provide initial values at creation time
```cpp
Color c(0xFFFF);  // c will be init as white color (0xFFFF).
                  // The data type is uint16_t
```
## Setter and getter
The following methods can get or set the property of the Color object.
```cpp
uint16_t getColor();

void setColor(uint16_t c);
void setColor(Color c);
```
## Exchange with 24bit RGB
There is some distortion when exchange with RGB each other.
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
