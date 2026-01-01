# Color Usage

TFT Framework uses the **RGB565** color format, which stores colors in 16 bits:
- 5 bits for Red
- 6 bits for Green
- 5 bits for Blue

<img src="565color.jpg" width="903" />

## Class Properties

The Color class stores color data as a single `uint16_t` property, accessible through public methods.

## Creating a Color Object

### Default Constructor

```cpp
Color c;  // Initializes to black (0x0000)
```

### Constructor with 16-bit Value

```cpp
Color c(0xFFFF);  // Initializes to white
```

### Constructor with RGB Values

```cpp
Color c(127, 127, 127);  // Gray color (RGB values: 0-255)
```

## Accessing and Modifying Colors

### Get/Set 16-bit Color

```cpp
uint16_t getColor();
void setColor(uint16_t c);
void setColor(Color c);
```

### RGB Conversion

**Note:** Converting between 24-bit RGB and 16-bit RGB565 causes slight color distortion due to bit reduction.

```cpp
// Get RGB values
uint32_t getRGB();  // Returns 24-bit RGB
uint8_t getR();     // Red channel (0-255)
uint8_t getG();     // Green channel (0-255)
uint8_t getB();     // Blue channel (0-255)

// Set RGB values
void setRGB(uint32_t rgb);
void setR(uint8_t r);  // Range: 0-255
void setG(uint8_t g);
void setB(uint8_t b);
```

## Example Usage

```cpp
// Working with 16-bit colors
Color c1(0);                        // Black
c1.setColor(0xFFFF);                // White
scr->println(c1.getColor());        // Output: 65535

// Using RGB colors
c1.setRGB(0xFF0000);  // Red
c1.setRGB(0x00FF00);  // Green
c1.setRGB(0x0000FF);  // Blue

// Setting individual channels
c1.setColor(0);
c1.setR(0x33);  // Red: 0x33
c1.setG(0x66);  // Green: 0x66
c1.setB(0x99);  // Blue: 0x99

// Reading back causes slight distortion
scr->println(c1.getR(), HEX);    // Output: 30 (not 33)
scr->println(c1.getG(), HEX);    // Output: 64 (not 66)
scr->println(c1.getB(), HEX);    // Output: 98 (not 99)
scr->println(c1.getRGB(), HEX);  // Output: 306498

// Copying colors
Color c2;
c2.setColor(c1);  // c2 now has same color as c1
```

## Understanding Color Distortion

When converting from 24-bit RGB to 16-bit RGB565, lower bits are truncated:

```
Input: 0x336699

R: 0x33 = 00110011 → 5-bit: 00110 → 0x30 = 00110000
G: 0x66 = 01100110 → 6-bit: 011001 → 0x64 = 01100100
B: 0x99 = 10011001 → 5-bit: 10011 → 0x98 = 10011000

Output: 0x306498 (slightly different from input)
```

This distortion is minimal and usually imperceptible to the human eye.
