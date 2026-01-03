# Rectangle Class - Complete Usage Guide

## Table of Contents
- [Overview](#overview)
- [Class Hierarchy](#class-hierarchy)
- [Core Concepts](#core-concepts)
- [Methods Reference](#methods-reference)
- [Basic Usage Examples](#basic-usage-examples)
- [Advanced Examples](#advanced-examples)
- [Performance Tips](#performance-tips)
- [Common Patterns](#common-patterns)

---

## Overview

The **Rectangle** class is the fundamental building block for all graphics operations in TFT Framework. All rendering ultimately relies on the `fillRect()` method. Rectangles can be both drawn (outline) and filled (solid color).

### Key Features
- Foundation of all graphics rendering
- Inherits from Line (provides two corner points)
- Implements Fillable interface (supports both outline and fill)
- Width/height abstraction over Line's end point
- Automatic boundary clipping

### Important Notes
⚠️ **Rectangle inherits from Line**, which means:
- Start point (x, y) is the top-left corner (from `Point`)
- End point defines the opposite corner (from `Line`)
- Width and height are calculated from these two points

**Optimization Facts:**
- A **Dot** is essentially a 1×1 rectangle
- Horizontal/vertical **Lines** are drawn as 1×N or N×1 rectangles
- `fillRect()` is the most optimized rendering operation

---

## Class Hierarchy

```
Color
  ↓
Point
  ↓
Shape (abstract)
  ↓
Line
  ↓
Rectangle ← Fillable (interface)
```

**Inherited Properties:**
- From `Point`: Top-left corner coordinates (x, y)
- From `Color`: Rectangle color (RGB565 format)
- From `Line`: Bottom-right corner (endX, endY)
- From `Fillable`: fill() method

---

## Core Concepts

### Width and Height vs End Point

Rectangle provides a **width/height abstraction** over Line's end point system:

```cpp
Rectangle rect;
rect.setPoint(10, 20);      // Top-left corner at (10, 20)
rect.setSize(100, 50);      // 100px wide, 50px tall
// Internally: endPoint becomes (109, 69) - inclusive coordinates
```

**Important:** Width/height include the starting pixel:
- Width of 1 = single pixel column
- Height of 1 = single pixel row
- `getWidth()` returns `endX - x + 1` (or `-1` for negative)

### Negative Width/Height

Rectangles support negative dimensions:

```cpp
Rectangle rect;
rect.setPoint(100, 100);
rect.setSize(-50, -30);     // Grows leftward and upward
// End point is at (51, 71)
```

This is useful for:
- Drawing from bottom-right to top-left
- Mirror/flip operations
- Relative positioning

---

## Methods Reference

### Dimension Management

#### Get Width and Height
```cpp
int16_t getWidth() const;
int16_t getHeight() const;
```

**Returns:** Width or height in pixels (can be negative)

**Example:**
```cpp
Rectangle rect;
rect.setPoint(10, 20);
rect.setSize(100, 50);

int16_t w = rect.getWidth();   // Returns 100
int16_t h = rect.getHeight();  // Returns 50

// Negative dimensions
rect.setSize(-100, 50);
w = rect.getWidth();           // Returns -100
```

#### Set Width and Height
```cpp
void setWidth(int16_t w);
void setHeight(int16_t h);
void setSize(int16_t w, int16_t h);
void setSize(const Rectangle& rect);
```

**Parameters:**
- `w`, `h` - Width and height in pixels (can be negative)
- `rect` - Rectangle to copy dimensions from

**Important:** Zero width/height is ignored (no change)

**Example:**
```cpp
Rectangle rect;
rect.setPoint(50, 50);

rect.setWidth(100);            // 100px wide
rect.setHeight(80);            // 80px tall
rect.setSize(120, 90);         // Set both at once

// Copy size from another rectangle
Rectangle other;
other.setSize(200, 150);
rect.setSize(other);           // rect is now 200×150
```

### Rendering Methods

#### Draw Outline
```cpp
void draw(Screen* scr);
```

Draws the rectangle's outline (border only) using the current color.

**Implementation:** Draws four lines (top, bottom, left, right) using `fill()`.

**Example:**
```cpp
Rectangle rect(50, 50, 100, 80);
rect.setColor(0xF800);  // Red
rect.draw(scr);         // Draw red outline
```

#### Fill Rectangle
```cpp
void fill(Screen* scr);
```

Fills the rectangle with solid color using the current color.

**Implementation:** Calls `Screen::fillRect()` - the most optimized drawing operation.

**Example:**
```cpp
Rectangle rect(50, 50, 100, 80);
rect.setColor(0x07E0);  // Green
rect.fill(scr);         // Fill with green
```

### Inherited Methods

From **Line**:
- `getEndX()`, `getEndY()`, `setEndX()`, `setEndY()`, `setEndPoint()`
- `move()`, `moveTo()`, `moveToX()`, `moveToY()`, `lineTo()`

From **Point**:
- `getX()`, `getY()`, `setX()`, `setY()`, `setPoint()`
- `offset()`, `offsetX()`, `offsetY()`, `midPoint()`

From **Color**:
- `getColor()`, `setColor()`, `getR()`, `getG()`, `getB()`
- `setRGB(r, g, b)`, static color constants

---

## Basic Usage Examples

### Example 1: Simple Rectangle
```cpp
Screen* scr;
// Initialize screen...

Rectangle rect;
rect.setPoint(50, 50);     // Top-left corner
rect.setSize(100, 80);     // 100×80 pixels
rect.setColor(0xF800);     // Red
rect.draw(scr);            // Draw outline
```

### Example 2: Filled Rectangle
```cpp
Rectangle rect;
rect.setPoint(50, 50);
rect.setSize(100, 80);
rect.setColor(0x07E0);     // Green
rect.fill(scr);            // Fill solid
```

### Example 3: Outline with Fill (Border Effect)
```cpp
Rectangle rect;
rect.setPoint(50, 50);
rect.setSize(100, 80);

// Draw colored border
rect.setColor(0xF800);     // Red border
rect.draw(scr);

// Fill interior with different color
rect.setPoint(52, 52);     // Shrink by 2 pixels
rect.setSize(96, 76);
rect.setColor(0xFFE0);     // Yellow fill
rect.fill(scr);
```

### Example 4: Using Line's Constructor
```cpp
// Rectangle inherits from Line, so you can use Line's constructors
Rectangle rect(10, 20, 110, 100);  // From (10,20) to (110,100)
// This creates a 101×81 rectangle
rect.setColor(0x001F);     // Blue
rect.fill(scr);
```

---

## Advanced Examples

### Example 5: RGB Rectangles (from original docs)
```cpp
Screen* scr;

void setup() {
    scr->clear();

    // Red, green, and blue (RGB888 format)
    uint32_t colors[] = {0xFF0000, 0x00FF00, 0x0000FF};

    Rectangle rect;
    rect.setPoint(50, 50);
    rect.setSize(100, 100);

    // Draw outlines
    for (int i = 0; i < 3; i++) {
        rect.setRGB(colors[i]);
        rect.draw(scr);
        rect.move(135, 30);  // Move diagonally
    }

    // Draw filled rectangles
    rect.moveTo(250, 50);
    for (int i = 0; i < 3; i++) {
        rect.setRGB(colors[i]);
        rect.fill(scr);
        rect.move(135, 30);
    }
}
```

**Output:**

<img src="RectangleExample.jpg" width="480" />

### Example 6: Checkerboard Pattern
```cpp
void drawCheckerboard(Screen* scr, int16_t size) {
    Rectangle rect;
    rect.setSize(size, size);
    
    for (int16_t y = 0; y < scr->getHeight(); y += size) {
        for (int16_t x = 0; x < scr->getWidth(); x += size) {
            rect.setPoint(x, y);
            
            // Alternate colors
            if ((x / size + y / size) % 2 == 0) {
                rect.setColor(0xFFFF);  // White
            } else {
                rect.setColor(0x0000);  // Black
            }
            
            rect.fill(scr);
        }
    }
}

void setup() {
    scr->clear();
    drawCheckerboard(scr, 20);  // 20×20 pixel squares
}
```

### Example 7: Progress Bar
```cpp
void drawProgressBar(Screen* scr, int16_t x, int16_t y, 
                     int16_t width, int16_t height, int percent) {
    Rectangle border, fill;
    
    // Draw border
    border.setPoint(x, y);
    border.setSize(width, height);
    border.setColor(0xFFFF);  // White border
    border.draw(scr);
    
    // Calculate fill width
    int16_t fillWidth = (width - 4) * percent / 100;
    
    // Draw fill
    fill.setPoint(x + 2, y + 2);
    fill.setSize(fillWidth, height - 4);
    fill.setColor(0x07E0);    // Green fill
    fill.fill(scr);
}

void loop() {
    static int progress = 0;
    
    scr->clear();
    drawProgressBar(scr, 50, 100, 200, 30, progress);
    
    progress = (progress + 5) % 105;
    delay(100);
}
```

### Example 8: Gradient Effect (Horizontal)
```cpp
void drawHorizontalGradient(Screen* scr, int16_t x, int16_t y, 
                            int16_t width, int16_t height) {
    Rectangle strip;
    strip.setSize(1, height);  // 1-pixel wide strips
    
    for (int16_t i = 0; i < width; i++) {
        strip.setPoint(x + i, y);
        
        // Calculate color (blue to red gradient)
        uint8_t red = (i * 255) / width;
        uint8_t blue = 255 - red;
        strip.setRGB(red, 0, blue);
        
        strip.fill(scr);
    }
}

void setup() {
    scr->clear();
    drawHorizontalGradient(scr, 10, 100, 300, 60);
}
```

### Example 9: Button UI Element
```cpp
void drawButton(Screen* scr, int16_t x, int16_t y, 
                int16_t width, int16_t height, 
                const char* label, bool pressed) {
    Rectangle btn;
    btn.setPoint(x, y);
    btn.setSize(width, height);
    
    // Background color based on state
    if (pressed) {
        btn.setColor(0x8410);  // Dark gray
    } else {
        btn.setColor(0xBDF7);  // Light gray
    }
    btn.fill(scr);
    
    // Border
    btn.setColor(0x0000);  // Black border
    btn.draw(scr);
    
    // Add shadow effect when not pressed
    if (!pressed) {
        Rectangle shadow;
        shadow.setPoint(x + 2, y + height);
        shadow.setSize(width, 2);
        shadow.setColor(0x4208);  // Shadow
        shadow.fill(scr);
    }
}
```

### Example 10: Window/Dialog Box
```cpp
void drawWindow(Screen* scr, int16_t x, int16_t y, 
                int16_t width, int16_t height) {
    Rectangle window;
    
    // Title bar
    window.setPoint(x, y);
    window.setSize(width, 30);
    window.setColor(0x001F);   // Blue title bar
    window.fill(scr);
    
    // Window body
    window.setPoint(x, y + 30);
    window.setSize(width, height - 30);
    window.setColor(0xFFFF);   // White body
    window.fill(scr);
    
    // Border around entire window
    window.setPoint(x, y);
    window.setSize(width, height);
    window.setColor(0x0000);   // Black border
    window.draw(scr);
}

void setup() {
    scr->clear(0x8410);  // Gray desktop background
    drawWindow(scr, 50, 40, 220, 160);
}
```

### Example 11: Animated Bouncing Box
```cpp
Rectangle box;
int16_t vx = 2, vy = 2;  // Velocity

void setup() {
    box.setPoint(160, 120);
    box.setSize(30, 30);
    box.setColor(0xF800);  // Red
}

void loop() {
    scr->clear();
    
    // Draw box
    box.fill(scr);
    
    // Move box
    box.setPoint(box.getX() + vx, box.getY() + vy);
    
    // Bounce off edges
    if (box.getX() <= 0 || box.getX() + 30 >= scr->getWidth()) {
        vx = -vx;
    }
    if (box.getY() <= 0 || box.getY() + 30 >= scr->getHeight()) {
        vy = -vy;
    }
    
    delay(20);
}
```

---

## Performance Tips

### 1. Fill is Faster Than Draw
`fill()` uses optimized `fillRect()` which is much faster than `draw()` (which draws 4 separate lines).

```cpp
// ✅ Fast - single fillRect operation
rect.fill(scr);

// ❌ Slower - draws 4 lines
rect.draw(scr);
```

### 2. Batch Operations by Color
Minimize color changes by grouping rectangles with the same color:

```cpp
// ✅ Good - group by color
rect.setColor(0xF800);
for (int i = 0; i < 10; i++) {
    // Draw all red rectangles
}

rect.setColor(0x07E0);
for (int i = 0; i < 10; i++) {
    // Draw all green rectangles
}
```

### 3. Reuse Rectangle Objects
Avoid creating new objects in loops:

```cpp
// ✅ Good - reuse object
Rectangle rect;
for (int i = 0; i < 100; i++) {
    rect.setPoint(i * 10, 50);
    rect.setSize(8, 8);
    rect.fill(scr);
}

// ❌ Bad - creates 100 objects
for (int i = 0; i < 100; i++) {
    Rectangle rect(i * 10, 50, 8, 8);
    rect.fill(scr);
}
```

### 4. Use setSize() Instead of setEndPoint()
`setSize()` is more intuitive and less error-prone for rectangles:

```cpp
// ✅ Clear and intuitive
rect.setPoint(10, 20);
rect.setSize(100, 50);

// ❌ Confusing - need to calculate inclusive coordinates
rect.setPoint(10, 20);
rect.setEndPoint(109, 69);  // Easy to get off-by-one errors
```

### 5. Leverage Horizontal/Vertical Strips
Drawing 1-pixel wide/tall rectangles is very efficient:

```cpp
// Efficient gradient using 1-pixel strips
Rectangle strip;
strip.setSize(1, height);  // 1-pixel wide
for (int x = 0; x < width; x++) {
    strip.setPoint(x, y);
    strip.fill(scr);  // Very fast
}
```

---

## Common Patterns

### Pattern 1: Centered Rectangle
```cpp
void drawCenteredRect(Screen* scr, int16_t cx, int16_t cy, 
                      int16_t width, int16_t height, uint16_t color) {
    Rectangle rect;
    rect.setPoint(cx - width / 2, cy - height / 2);
    rect.setSize(width, height);
    rect.setColor(color);
    rect.fill(scr);
}
```

### Pattern 2: Clear Screen Region
```cpp
void clearRegion(Screen* scr, int16_t x, int16_t y, 
                 int16_t width, int16_t height) {
    Rectangle rect(x, y, width, height);
    rect.setColor(0x0000);  // Black
    rect.fill(scr);
}
```

### Pattern 3: Screen Border
```cpp
void drawScreenBorder(Screen* scr, int16_t thickness, uint16_t color) {
    Rectangle border;
    border.setColor(color);
    
    int16_t w = scr->getWidth();
    int16_t h = scr->getHeight();
    
    // Top
    border.setPoint(0, 0);
    border.setSize(w, thickness);
    border.fill(scr);
    
    // Bottom
    border.setPoint(0, h - thickness);
    border.setSize(w, thickness);
    border.fill(scr);
    
    // Left
    border.setPoint(0, 0);
    border.setSize(thickness, h);
    border.fill(scr);
    
    // Right
    border.setPoint(w - thickness, 0);
    border.setSize(thickness, h);
    border.fill(scr);
}
```

### Pattern 4: Grid Layout
```cpp
void drawGrid(Screen* scr, int16_t cellSize, uint16_t lineColor) {
    Rectangle line;
    line.setColor(lineColor);
    
    // Vertical lines
    for (int16_t x = 0; x < scr->getWidth(); x += cellSize) {
        line.setPoint(x, 0);
        line.setSize(1, scr->getHeight());
        line.fill(scr);
    }
    
    // Horizontal lines
    for (int16_t y = 0; y < scr->getHeight(); y += cellSize) {
        line.setPoint(0, y);
        line.setSize(scr->getWidth(), 1);
        line.fill(scr);
    }
}
```

---

## Summary

The **Rectangle** class provides:
- ✅ Fundamental graphics primitive (all rendering uses `fillRect()`)
- ✅ Width/height abstraction over Line's end point system
- ✅ Both outline (`draw()`) and filled (`fill()`) rendering
- ✅ Support for negative dimensions
- ✅ Full inheritance from Line, Point, and Color
- ✅ `const`-correct getter methods

**Key Methods:**
- **Dimensions**: `getWidth()`, `getHeight()`, `setWidth()`, `setHeight()`, `setSize()`
- **Rendering**: `draw()` (outline), `fill()` (solid)
- **Inherited**: All Line, Point, and Color methods

**Best Practices:**
- Prefer `fill()` over `draw()` for performance
- Use `setSize()` for intuitive width/height specification
- Reuse Rectangle objects instead of creating new ones
- Batch operations by color to minimize state changes
- Use 1-pixel strips for efficient gradients and patterns
