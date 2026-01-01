# Shape Class

**Inheritance:** Point, Color

## Overview

The `Shape` class is the base class for all drawable objects in TFT Framework. It inherits from both `Point` and `Color`, providing position and color properties for all shapes.

Shapes can be drawn to the screen using the `draw()` method.

## Shape Hierarchy

The following classes inherit from Shape:
- **Dot** - Single pixel
- **Line** - Straight line between two points
- **Rectangle** - Four-sided polygon
- **Triangle** - Three-sided polygon
- **Circle** - Round shape with radius
- **Ellipse** - Oval shape with two radii
- **Font** - Character rendering

## Fillable Interface

The `Fillable` interface defines shapes that can be filled with solid color using the `fill()` method.

### Fillable Shapes
- Rectangle
- Triangle
- Circle
- Ellipse

### Non-Fillable Shapes
- Dot (already a single pixel)
- Line (one-dimensional)
- Font (character outline only)

## Basic Usage

All shapes inherit methods from Point and Color:

```cpp
Screen* scr;
// Initialize your screen...

// Example with Rectangle
Rectangle rect;
rect.setPoint(50, 50);      // Position
rect.setSize(100, 80);      // Dimensions
rect.setRGB(0xFF0000);      // Red color

rect.draw(scr);             // Draw outline
rect.fill(scr);             // Fill with color (if Fillable)
```

See individual shape documentation for specific methods and examples.
