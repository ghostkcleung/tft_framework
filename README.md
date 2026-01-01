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

- [Getting Started](./docs/getting_start.md)
- [Supported Hardware](./docs/hardware.md)
- [Installation](./docs/installation.md)

### Core Concepts

- [Point Usage](./docs/PointUsage.md)
- [Color Usage](./docs/ColorUsage.md)
- [Shapes and Fillable Objects](./docs/shape.md)

### Drawing Shapes

- [Dot Usage](./docs/DotUsage.md)
- [Line Usage](./docs/LineUsage.md)
- [Rectangle Usage](./docs/RectangleUsage.md)
- [Other Shapes](./docs/otherShape.md)

### Advanced Features

- [Font Usage](./docs/fontUsage.md)
- [Screen Printing](./docs/print.md)
- [Buffered Screen](./docs/buffered_screen.md)
- [BMP Images](./docs/bitmap.md)

## Roadmap

Future enhancements planned for the framework:

- [ ] Screen pixel reading and capture functionality
- [ ] Screen scrolling support
- [ ] Unicode font support
- [ ] JPG, PNG, and GIF image format support
- [ ] Extended MCU and TFT module compatibility
- [ ] Additional shape drawing algorithms