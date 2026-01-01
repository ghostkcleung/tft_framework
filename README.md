# TFT Framework

A lightweight and flexible graphics framework for TFT displays on embedded systems. Simply define your screen size and implement the "Fill Rect" method to get started with powerful drawing capabilities.

## Features

- **Simple Integration**: Minimal setup required - just specify screen dimensions and implement basic fill function
- **Shape Drawing**: Built-in support for dots, lines, rectangles, and custom shapes
- **Text Rendering**: Font rendering and screen printing capabilities
- **Image Support**: BMP image display
- **Buffer Management**: Efficient buffered screen operations
- **Hardware Agnostic**: Works with various TFT modules and MCU platforms

## Documentation

- [Getting Started](./md/getting_start.md)
- [Supported Hardware](./md/hardware.md)
- [Installation](./md/installation.md)

### Core Concepts

- [Point Usage](./md/PointUsage.md)
- [Color Usage](./md/ColorUsage.md)
- [Shapes and Fillable Objects](./md/shape.md)

### Drawing Shapes

- [Dot Usage](./md/DotUsage.md)
- [Line Usage](./md/LineUsage.md)
- [Rectangle Usage](./md/RectangleUsage.md)
- [Other Shapes](./md/otherShape.md)

### Advanced Features

- [Font Usage](./md/fontUsage.md)
- [Screen Printing](./md/print.md)
- [Buffered Screen](./md/buffered_screen.md)
- [BMP Images](./md/bitmap.md)

## Roadmap

Future enhancements planned for the framework:

- [ ] Screen pixel reading and capture functionality
- [ ] Screen scrolling support
- [ ] Unicode font support
- [ ] JPG, PNG, and GIF image format support
- [ ] Extended MCU and TFT module compatibility
- [ ] Additional shape drawing algorithms