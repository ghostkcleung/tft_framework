# TFT Framework

A lightweight framework designed for TFT displays, providing basic graphics drawing tools.

## Overview

This framework provides two core classes for graphics programming on TFT displays:

- **[Point](docs/Point.md)** - Represents 2D coordinates with movement functionality
- **[Color](docs/Color.md)** - Handles RGB565 color format with RGB888 conversion support

## Quick Start

```cpp
#include "tft_framework.h"
using namespace tft_framework;

// Create and manipulate points
Point p(100, 100);
p.move(45, 50);  // Move 50 pixels at 45° angle

// Create and use colors
Color red(255, 0, 0);           // RGB888
Color blue(0x001F);             // RGB565
uint16_t colorValue = red.getColor();
```

## Documentation

- [Point Class Documentation](docs/Point.md) - Coordinate representation and movement
- [Color Class Documentation](docs/Color.md) - Color handling and format conversion

## Namespace

All classes are in the `tft_framework` namespace. Use it with:

```cpp
using namespace tft_framework;
```

Or use the full path:

```cpp
tft_framework::Point p(10, 20);
tft_framework::Color c(255, 0, 0);
```

## Project Structure

```
lib/tft_framework/tft_framework/
├── Point.h          // Point class definition
├── Point.cpp        // Point class implementation
├── Color.h          // Color class definition
├── Color.cpp        // Color class implementation
└── tft_framework.h  // Framework main header file
```

## License

Please refer to the project license terms.
