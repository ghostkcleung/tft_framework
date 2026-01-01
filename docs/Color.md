# Color Class

The `Color` class handles colors in RGB565 format, with support for RGB888 conversion.

## Constructors

```cpp
Color()                                // Create black color (0x0000)
Color(uint16_t color)                  // Create color from RGB565 value
Color(uint8_t r, uint8_t g, uint8_t b) // Create color from RGB888 values
```

## Member Functions

### Get/Set RGB565 Color Value
```cpp
uint16_t getColor()           // Get RGB565 format color value
void setColor(uint16_t color) // Set RGB565 format color value
void setColor(Color c)        // Copy color from another Color object
```

### Get/Set Individual Color Channels (RGB888 format)
```cpp
uint8_t getR()           // Get red channel (0-255)
uint8_t getG()           // Get green channel (0-255)
uint8_t getB()           // Get blue channel (0-255)

void setR(uint8_t r)     // Set red channel (0-255)
void setG(uint8_t g)     // Set green channel (0-255)
void setB(uint8_t b)     // Set blue channel (0-255)
```

### RGB888 Format Conversion
```cpp
uint32_t getRGB()           // Get RGB888 format (0xRRGGBB)
void setRGB(uint32_t rgb)   // Set color using RGB888 format
```

## Color Format Description

- **RGB565**: 16-bit format, 5 bits for red, 6 bits for green, 5 bits for blue
  - Format: `RRRRR GGGGGG BBBBB`
  - Range: 0x0000 - 0xFFFF
  
- **RGB888**: 24-bit format, 8 bits per channel (0-255)
  - Format: `RRRRRRRR GGGGGGGG BBBBBBBB`
  - Range: 0x000000 - 0xFFFFFF

### Conversion Notes

When converting from RGB888 to RGB565:
- Red: 8 bits → 5 bits (divide by 8)
- Green: 8 bits → 6 bits (divide by 4)
- Blue: 8 bits → 5 bits (divide by 8)

When converting from RGB565 to RGB888, the class expands the values back, though some precision is lost.

## Usage Example

```cpp
using namespace tft_framework;

// Create colors
Color black;                        // Black (default)
Color red(0xF800);                  // Red (RGB565)
Color green(0, 255, 0);             // Green (RGB888)

// Get RGB565 color value
uint16_t colorValue = red.getColor(); // 0xF800

// Set color using RGB888
Color blue;
blue.setR(0);
blue.setG(0);
blue.setB(255);

// Or use RGB888 format
blue.setRGB(0x0000FF);

// Get individual channel values
uint8_t r = red.getR();    // Red channel
uint8_t g = red.getG();    // Green channel
uint8_t b = red.getB();    // Blue channel

// Get RGB888 format
uint32_t rgb = red.getRGB(); // 0xFF0000

// Common colors (RGB565)
Color white(0xFFFF);       // White
Color black(0x0000);       // Black
Color red(0xF800);         // Red
Color green(0x07E0);       // Green
Color blue(0x001F);        // Blue
Color yellow(0xFFE0);      // Yellow
Color cyan(0x07FF);        // Cyan
Color magenta(0xF81F);     // Magenta
```

## Common RGB565 Color Values

| Color   | RGB565 Hex | RGB888 (R, G, B) |
|---------|-----------|------------------|
| Black   | 0x0000    | (0, 0, 0)       |
| White   | 0xFFFF    | (255, 255, 255) |
| Red     | 0xF800    | (255, 0, 0)     |
| Green   | 0x07E0    | (0, 255, 0)     |
| Blue    | 0x001F    | (0, 0, 255)     |
| Yellow  | 0xFFE0    | (255, 255, 0)   |
| Cyan    | 0x07FF    | (0, 255, 255)   |
| Magenta | 0xF81F    | (255, 0, 255)   |
