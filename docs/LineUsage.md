# Line Class - Complete Usage Guide

## Table of Contents
- [Overview](#overview)
- [Class Hierarchy](#class-hierarchy)
- [Constructors](#constructors)
- [Core Concepts](#core-concepts)
- [Methods Reference](#methods-reference)
- [Basic Usage Examples](#basic-usage-examples)
- [Advanced Examples](#advanced-examples)
- [Performance Tips](#performance-tips)
- [Common Patterns](#common-patterns)

---

## Overview

The **Line** class represents a straight line segment between two points. Lines are rendered using [Bresenham's line algorithm](https://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm), an efficient integer-only algorithm that calculates intermediate pixels.

### Key Features
- Efficient pixel-perfect rendering using Bresenham's algorithm
- Automatic optimization for horizontal/vertical lines (uses fast `fillRect`)
- Inherits position and color from Shape base class
- Independent start and end point management
- Direction-based line creation with `lineTo()`

### Important Notes
⚠️ **Line inherits from Shape**, which means:
- Start point comes from `Point` (via `Shape`)
- Color comes from `Color` (via `Shape`)
- End point is managed independently by `Line`

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
```

**Inherited Properties:**
- From `Point`: Start point coordinates (x, y)
- From `Color`: Line color (RGB565 format)

---

## Constructors

### Default Constructor
```cpp
Line();
```
Creates a line from (0, 0) to (0, 0) with default color (0x0000 - black).

**Example:**
```cpp
Line line;  // Line from (0,0) to (0,0), color = black
line.setPoint(10, 20);
line.setEndPoint(100, 50);
line.setColor(0xFFFF);
line.draw(scr);
```

### Coordinate Constructor
```cpp
Line(int16_t x0, int16_t y0, int16_t x1, int16_t y1);
```
Creates a line from start point (x0, y0) to end point (x1, y1).

**Parameters:**
- `x0`, `y0` - Start point coordinates
- `x1`, `y1` - End point coordinates

**Example:**
```cpp
Line line(10, 20, 100, 50);  // From (10,20) to (100,50)
line.setColor(0xF800);       // Set to red
line.draw(scr);
```

### Point Constructor
```cpp
Line(const Point& start, const Point& end);
```
Creates a line from start Point to end Point.

**Parameters:**
- `start` - Start point object
- `end` - End point object

**Example:**
```cpp
Point p1(10, 20);
Point p2(100, 50);
Line line(p1, p2);
line.setColor(0x07E0);  // Green
line.draw(scr);
```

---

## Core Concepts

### Start Point vs End Point
A line has TWO distinct points:

1. **Start Point** (inherited from Point)
   - Accessed via: `getX()`, `getY()`, `setX()`, `setY()`, `setPoint()`
   
2. **End Point** (managed by Line)
   - Accessed via: `getEndX()`, `getEndY()`, `setEndX()`, `setEndY()`, `setEndPoint()`

### Direction System
Directions use degrees (0-359°):
```
        270°
         |
180° ←---+---→ 0° / 360°
         |
        90°
```

---

## Methods Reference

### End Point Management

#### Get End Point Coordinates
```cpp
int16_t getEndX() const;
int16_t getEndY() const;
Point getEndPoint() const;
```

**Returns:** End point X/Y coordinate or Point object

**Example:**
```cpp
Line line(0, 0, 100, 50);
int16_t ex = line.getEndX();    // Returns 100
int16_t ey = line.getEndY();    // Returns 50
Point endPt = line.getEndPoint(); // Returns Point(100, 50)
```

#### Set End Point
```cpp
void setEndX(int16_t x);
void setEndY(int16_t y);
void setEndPoint(int16_t x, int16_t y);
void setEndPoint(const Point& p);
```

**Parameters:**
- `x`, `y` - New end point coordinates
- `p` - Point object for end point

**Example:**
```cpp
Line line(0, 0, 50, 50);
line.setEndX(100);              // End point now (100, 50)
line.setEndY(75);               // End point now (100, 75)
line.setEndPoint(200, 150);     // End point now (200, 150)

Point p(300, 200);
line.setEndPoint(p);            // End point now (300, 200)
```

### Movement Methods

#### Move Entire Line (Start and End Together)
```cpp
void move(double direction, double distance);
```

Moves BOTH start and end points in the specified direction.

**Parameters:**
- `direction` - Angle in degrees (0-359)
- `distance` - Distance to move in pixels

**Example:**
```cpp
Line line(50, 50, 100, 100);
line.move(0, 10);    // Move right 10px: (60,50) to (110,100)
line.move(90, 20);   // Move down 20px: (60,70) to (110,120)
```

#### Move Line to New Position (Preserving Shape)
```cpp
void moveTo(const Point& p);
void moveTo(int16_t x, int16_t y);
void moveToX(int16_t x);
void moveToY(int16_t y);
```

Moves start point to new location; end point follows to maintain relative position.

**Parameters:**
- `p` - New start point
- `x`, `y` - New start coordinates

**Example:**
```cpp
Line line(50, 50, 100, 100);  // 50px right, 50px down
line.moveTo(200, 200);         // Now (200,200) to (250,250)
line.moveToX(300);             // Now (300,200) to (350,250)
line.moveToY(100);             // Now (300,100) to (350,150)

Point p(400, 400);
line.moveTo(p);                // Now (400,400) to (450,450)
```

#### Set End Point Using Direction/Distance
```cpp
void lineTo(double direction, double distance);
```

Sets end point relative to start point using polar coordinates.

**Parameters:**
- `direction` - Angle from start point (0-359°)
- `distance` - Distance from start point in pixels

**Example:**
```cpp
Line line(100, 100, 0, 0);
line.lineTo(0, 50);      // End point 50px to the right: (150, 100)
line.lineTo(45, 70.7);   // End point 70.7px at 45°: (~150, ~50)
line.lineTo(90, 100);    // End point 100px down: (100, 200)
```

### Rendering

#### Draw Line
```cpp
void draw(Screen* scr);
```

Draws the line on the screen using Bresenham's algorithm.

**Optimizations:**
- Horizontal lines (y0 == y1) use fast `fillRect()`
- Vertical lines (x0 == x1) use fast `fillRect()`
- Diagonal/arbitrary lines use Bresenham's algorithm

**Example:**
```cpp
Line line(10, 10, 100, 100);
line.setColor(0xFFFF);  // White
line.draw(scr);
```

---

## Basic Usage Examples

### Example 1: Simple Line
```cpp
Screen* scr;
// Initialize screen...

Line line;
line.setPoint(50, 50);        // Start point
line.setEndPoint(150, 150);   // End point
line.setColor(0xFFFF);        // White
line.draw(scr);
```

### Example 2: Using Constructor
```cpp
Line line(50, 50, 150, 150);  // From (50,50) to (150,150)
line.setColor(0xF800);         // Red
line.draw(scr);
```

### Example 3: Horizontal and Vertical Lines
```cpp
// Horizontal line
Line hLine(10, 50, 200, 50);
hLine.setColor(0x07E0);  // Green
hLine.draw(scr);

// Vertical line
Line vLine(100, 10, 100, 200);
vLine.setColor(0x001F);  // Blue
vLine.draw(scr);
```

### Example 4: Using lineTo() for Direction-Based Lines
```cpp
Line line(160, 120, 0, 0);  // Start at screen center

// Draw 12 lines radiating outward (clock pattern)
for (int i = 0; i < 12; i++) {
    line.lineTo(i * 30, 50);  // 30° increments, 50px radius
    line.draw(scr);
}
```

---

## Advanced Examples

### Example 5: Parallel Lines
```cpp
Screen* scr;

void setup() {
    scr->clear();

    Line line(50, 50, 75, 150);
    line.setColor(0xFFFF);  // White

    // Draw 5 parallel lines
    for (int i = 0; i < 5; i++) {
        line.draw(scr);
        line.move(90, 50);  // Move right 50 pixels
    }
}
```

**Output:** Five vertical-ish lines spaced 50 pixels apart

<img src="LineExample1.jpg" width="480" />

### Example 6: Star Pattern
```cpp
void drawStar(Screen* scr, int16_t cx, int16_t cy, int16_t radius) {
    Line line(cx, cy, 0, 0);
    line.setColor(0xFFE0);  // Yellow

    // Draw 8-pointed star
    for (int i = 0; i < 8; i++) {
        line.lineTo(i * 45, radius);
        line.draw(scr);
    }
}

void setup() {
    scr->clear();
    drawStar(scr, 160, 120, 80);
}
```

### Example 7: Grid Pattern
```cpp
void drawGrid(Screen* scr, int16_t spacing) {
    Line line;
    line.setColor(0x8410);  // Gray

    // Vertical lines
    for (int16_t x = 0; x < scr->getWidth(); x += spacing) {
        line.setPoint(x, 0);
        line.setEndPoint(x, scr->getHeight() - 1);
        line.draw(scr);
    }

    // Horizontal lines
    for (int16_t y = 0; y < scr->getHeight(); y += spacing) {
        line.setPoint(0, y);
        line.setEndPoint(scr->getWidth() - 1, y);
        line.draw(scr);
    }
}

void setup() {
    scr->clear();
    drawGrid(scr, 20);  // 20-pixel grid
}
```

### Example 8: Animated Line Rotation
```cpp
Line line(160, 120, 0, 0);  // Center of 320x240 screen
double angle = 0;

void loop() {
    scr->clear();
    
    line.setColor(0x07FF);  // Cyan
    line.lineTo(angle, 80);  // 80px radius
    line.draw(scr);
    
    angle += 5;  // Rotate 5 degrees per frame
    if (angle >= 360) angle = 0;
    
    delay(50);
}
```

### Example 9: Connecting Multiple Points (Polygon)
```cpp
void connectPoints(Screen* scr, Point points[], int count, uint16_t color) {
    Line line;
    line.setColor(color);

    for (int i = 0; i < count - 1; i++) {
        line.setPoint(points[i]);
        line.setEndPoint(points[i + 1]);
        line.draw(scr);
    }
}

void setup() {
    // Draw a pentagon
    Point pentagon[] = {
        Point(160, 50),
        Point(220, 100),
        Point(200, 170),
        Point(120, 170),
        Point(100, 100),
        Point(160, 50)  // Close the shape
    };
    
    connectPoints(scr, pentagon, 6, 0xF800);  // Red pentagon
}
```

### Example 10: Crosshair
```cpp
void drawCrosshair(Screen* scr, int16_t x, int16_t y, int16_t size) {
    Line hLine(x - size, y, x + size, y);
    Line vLine(x, y - size, x, y + size);
    
    hLine.setColor(0xFFFF);  // White
    vLine.setColor(0xFFFF);
    
    hLine.draw(scr);
    vLine.draw(scr);
}

void setup() {
    scr->clear();
    drawCrosshair(scr, 160, 120, 20);  // Center crosshair
}
```

---

## Performance Tips

### 1. Prefer Horizontal/Vertical Lines When Possible
Horizontal and vertical lines use optimized `fillRect()` which is much faster than Bresenham's algorithm.

```cpp
// Fast - uses fillRect()
Line hLine(10, 50, 200, 50);  // Horizontal

// Slower - uses Bresenham
Line dLine(10, 50, 200, 51);  // Nearly horizontal
```

### 2. Minimize Object Creation
Reuse Line objects instead of creating new ones:

```cpp
// ✅ Good - reuse object
Line line;
for (int i = 0; i < 10; i++) {
    line.setPoint(0, i * 10);
    line.setEndPoint(320, i * 10);
    line.draw(scr);
}

// ❌ Bad - creates 10 objects
for (int i = 0; i < 10; i++) {
    Line line(0, i * 10, 320, i * 10);
    line.draw(scr);
}
```

### 3. Use moveTo() for Parallel Lines
When drawing parallel lines, use `moveTo()` or `move()`:

```cpp
Line line(50, 50, 150, 150);
for (int i = 0; i < 5; i++) {
    line.draw(scr);
    line.move(90, 20);  // Efficient - moves existing line
}
```

### 4. Batch Similar Operations
Group lines by color to minimize color changes:

```cpp
// Draw all red lines first
line.setColor(0xF800);
for (int i = 0; i < redLineCount; i++) {
    // Draw red lines
}

// Then all green lines
line.setColor(0x07E0);
for (int i = 0; i < greenLineCount; i++) {
    // Draw green lines
}
```

---

## Common Patterns

### Pattern 1: Clock Hands
```cpp
void drawClockHand(Screen* scr, int16_t cx, int16_t cy, 
                   double angle, int16_t length, uint16_t color) {
    Line hand(cx, cy, 0, 0);
    hand.setColor(color);
    hand.lineTo(angle - 90, length);  // -90 to make 0° point up
    hand.draw(scr);
}

void drawClock(Screen* scr) {
    int16_t cx = 160, cy = 120;
    
    // Hour hand (short)
    drawClockHand(scr, cx, cy, 30, 40, 0xFFFF);   // 1 o'clock
    
    // Minute hand (long)
    drawClockHand(scr, cx, cy, 180, 60, 0xFFFF);  // 30 minutes
}
```

### Pattern 2: Box Outline
```cpp
void drawBox(Screen* scr, int16_t x, int16_t y, 
             int16_t w, int16_t h, uint16_t color) {
    Line line;
    line.setColor(color);
    
    // Top
    line.setPoint(x, y);
    line.setEndPoint(x + w - 1, y);
    line.draw(scr);
    
    // Bottom
    line.setPoint(x, y + h - 1);
    line.setEndPoint(x + w - 1, y + h - 1);
    line.draw(scr);
    
    // Left
    line.setPoint(x, y);
    line.setEndPoint(x, y + h - 1);
    line.draw(scr);
    
    // Right
    line.setPoint(x + w - 1, y);
    line.setEndPoint(x + w - 1, y + h - 1);
    line.draw(scr);
}
```

### Pattern 3: Arrow
```cpp
void drawArrow(Screen* scr, int16_t x1, int16_t y1, 
               int16_t x2, int16_t y2, uint16_t color) {
    Line shaft(x1, y1, x2, y2);
    shaft.setColor(color);
    shaft.draw(scr);
    
    // Calculate arrow head
    Line head(x2, y2, 0, 0);
    head.setColor(color);
    
    double angle = atan2(y2 - y1, x2 - x1) * 180 / PI;
    head.lineTo(angle + 150, 10);  // Left barb
    head.draw(scr);
    
    head.setEndPoint(x2, y2);
    head.lineTo(angle - 150, 10);  // Right barb
    head.draw(scr);
}
```

---

## Summary

The **Line** class provides:
- ✅ Three convenient constructors for different use cases
- ✅ Independent start and end point management
- ✅ Direction-based line creation with `lineTo()`
- ✅ Efficient rendering with automatic optimization
- ✅ Full integration with Point and Color functionality
- ✅ `const`-correct getter methods

**Key Methods:**
- **Constructors**: `Line()`, `Line(x0,y0,x1,y1)`, `Line(start,end)`
- **End Point**: `getEndX/Y()`, `setEndX/Y()`, `getEndPoint()`, `setEndPoint()`
- **Movement**: `move()`, `moveTo()`, `moveToX/Y()`, `lineTo()`
- **Rendering**: `draw()`

**Best Practices:**
- Use constructors for cleaner initialization
- Prefer horizontal/vertical lines for performance
- Reuse Line objects in loops
- Use `lineTo()` for polar/directional line creation
- Batch operations by color when possible
