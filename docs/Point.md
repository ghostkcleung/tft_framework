# Point Class

The `Point` class represents a 2D coordinate point on the screen with comprehensive manipulation capabilities. It provides efficient coordinate management, polar movement, offset operations, operator overloading, and geometric calculations.

## Overview

- **Storage**: Lightweight 4-byte structure (2 × int16_t)
- **Coordinate System**: Origin (0,0) at top-left, X increases right, Y increases down
- **Range**: -32,768 to 32,767 for both X and Y coordinates
- **Inheritance**: Base class for Shape and Image classes

## Constructors

```cpp
Point()                        // Create point at origin (0, 0)
Point(int16_t x, int16_t y)   // Create point at specified coordinates
```

**Examples:**
```cpp
Point p1;                     // p1 is at (0, 0)
Point p2(100, 50);           // p2 is at (100, 50)
Point p3(-10, 200);          // Negative coordinates supported
```

## Coordinate Access

### Getters (const methods)

```cpp
int16_t getX() const          // Get X coordinate
int16_t getY() const          // Get Y coordinate
```

These methods are `const`, allowing access from const Point objects.

**Example:**
```cpp
Point p(150, 200);
int16_t x = p.getX();         // x = 150
int16_t y = p.getY();         // y = 200

const Point cp(50, 75);
int16_t cx = cp.getX();       // Works with const objects
```

### Setters

```cpp
void setX(int16_t x)                    // Set X coordinate only
void setY(int16_t y)                    // Set Y coordinate only
void setPoint(int16_t x, int16_t y)     // Set both coordinates
void setPoint(const Point& p)           // Copy from another point
```

**Example:**
```cpp
Point p;
p.setX(100);                  // p = (100, 0)
p.setY(50);                   // p = (100, 50)

p.setPoint(200, 150);         // p = (200, 150)

Point p2(10, 20);
p.setPoint(p2);               // p = (10, 20)
```

## Movement Methods

### Polar Movement

```cpp
virtual void move(double direction, double distance)
```

Move the point using polar coordinates with direction in degrees:
- **0°** = North (Up) - decreases Y
- **90°** = East (Right) - increases X
- **180°** = South (Down) - increases Y
- **270°** = West (Left) - decreases X

**Performance Optimization**: Cardinal directions (0°, 90°, 180°, 270°) use fast integer arithmetic instead of trigonometric functions.

**Example:**
```cpp
Point p(100, 100);

p.move(0, 10);                // Move up → (100, 90)
p.move(90, 20);               // Move right → (120, 90)
p.move(180, 15);              // Move down → (120, 105)
p.move(270, 30);              // Move left → (90, 105)

p.move(45, 10);               // Move northeast ~10 pixels
p.move(225, 14);              // Move southwest ~14 pixels
```

### Offset Methods

```cpp
void offset(int16_t dx, int16_t dy)    // Offset by delta X and Y
void offsetX(int16_t dx)               // Offset X only
void offsetY(int16_t dy)               // Offset Y only
```

Direct coordinate adjustment - faster than polar movement for simple translations.

**Example:**
```cpp
Point p(50, 50);

p.offset(10, -5);             // p = (60, 45)
p.offsetX(20);                // p = (80, 45)
p.offsetY(10);                // p = (80, 55)

// Negative offsets
p.offset(-30, -20);           // p = (50, 35)
```

## Geometric Calculations

### Midpoint

```cpp
Point midPoint(const Point& p) const
```

Calculate the midpoint between this point and another point. Returns a new Point object.

**Formula**: $\left(\frac{x_1 + x_2}{2}, \frac{y_1 + y_2}{2}\right)$

**Example:**
```cpp
Point p1(0, 0);
Point p2(100, 200);
Point mid = p1.midPoint(p2);  // mid = (50, 100)

Point a(50, 60);
Point b(70, 80);
Point center = a.midPoint(b); // center = (60, 70)
```

**Use Cases:**
- Finding centers of line segments
- Interpolation between points
- Bisecting distances
- Centering objects between two positions

## Operator Overloading

### Comparison Operators

```cpp
bool operator==(const Point& other) const    // Equality
bool operator!=(const Point& other) const    // Inequality
```

**Example:**
```cpp
Point p1(10, 20);
Point p2(10, 20);
Point p3(30, 40);

if (p1 == p2) {               // true - same coordinates
    // Points are at same location
}

if (p1 != p3) {               // true - different coordinates
    // Points are at different locations
}
```

### Arithmetic Operators

```cpp
Point operator+(const Point& other) const     // Vector addition
Point operator-(const Point& other) const     // Vector subtraction
Point& operator+=(const Point& other)         // Add and assign
Point& operator-=(const Point& other)         // Subtract and assign
```

**Example:**
```cpp
Point p1(10, 20);
Point p2(30, 40);

// Create new points
Point p3 = p1 + p2;           // p3 = (40, 60)
Point p4 = p2 - p1;           // p4 = (20, 20) - offset from p1 to p2

// Modify existing points
p1 += Point(5, 5);            // p1 = (15, 25)
p2 -= Point(10, 10);          // p2 = (20, 30)
```

## Usage Examples

### Basic Object Positioning

```cpp
// Position an object on screen
Point objectPos(100, 100);
Point velocity(5, -3);

// Update position each frame
objectPos += velocity;        // Move by velocity vector

// Center object in bounding box
Point topLeft(50, 50);
Point bottomRight(150, 150);
Point center = topLeft.midPoint(bottomRight);  // center = (100, 100)
```

### Distance-based Movement

```cpp
Point player(100, 100);
Point target(200, 150);

// Calculate direction vector
Point direction = target - player;  // (100, 50)

// Move towards target
player.offset(5, 0);          // Move 5 pixels right
player.offset(0, 3);          // Move 3 pixels down

// Or use polar coordinates
player.move(45, 10);          // Move northeast
```

### Grid Systems

```cpp
Point gridPos(5, 3);          // Grid cell (5, 3)
int16_t cellSize = 32;

// Convert to screen coordinates
Point screenPos(
    gridPos.getX() * cellSize,
    gridPos.getY() * cellSize
);                            // screenPos = (160, 96)

// Offset to center of cell
screenPos.offset(cellSize / 2, cellSize / 2);
```

### Collision Detection

```cpp
// Check if point is within a rectangular area
Point point(120, 80);
Point topLeft(100, 50);
Point bottomRight(200, 150);

bool inside = (point.getX() >= topLeft.getX() && 
               point.getX() <= bottomRight.getX() &&
               point.getY() >= topLeft.getY() && 
               point.getY() <= bottomRight.getY());
```

### Animation Paths

```cpp
Point start(50, 100);
Point end(250, 100);
float t = 0.5;                // 50% along path

// Linear interpolation using midpoint
Point current = start.midPoint(end);  // For t=0.5

// Or calculate manually for any t value
Point delta = end - start;
Point current2 = start;
current2.offset(delta.getX() * t, delta.getY() * t);
```

### Circular Movement

```cpp
Point center(160, 120);
Point object = center;
double angle = 0;
int16_t radius = 50;

// Rotate around center
object = center;              // Reset to center
object.move(angle, radius);   // Move out to circle
angle += 5;                   // Increment angle
```

## Advanced Techniques

### Vector Operations

```cpp
// Calculate direction vector
Point from(50, 50);
Point to(150, 100);
Point direction = to - from;  // (100, 50)

// Calculate reverse direction
Point reverse = from - to;    // (-100, -50)

// Scale movement (manual)
Point movement = direction;
movement.offset(direction.getX(), direction.getY());  // Double the vector
```

### Relative Positioning

```cpp
Point anchor(100, 100);
Point offset1(-20, 0);        // Left offset
Point offset2(20, 0);         // Right offset
Point offset3(0, -20);        // Top offset

Point left = anchor + offset1;     // (80, 100)
Point right = anchor + offset2;    // (120, 100)
Point top = anchor + offset3;      // (100, 80)
```

### Path Following

```cpp
Point waypoints[] = {
    Point(50, 50),
    Point(100, 75),
    Point(150, 50),
    Point(200, 100)
};

Point position = waypoints[0];
int currentWaypoint = 1;

// Simple waypoint following
Point target = waypoints[currentWaypoint];
Point direction = target - position;

if (direction.getX() != 0 || direction.getY() != 0) {
    // Move towards waypoint
    position.offset(
        direction.getX() > 0 ? 1 : (direction.getX() < 0 ? -1 : 0),
        direction.getY() > 0 ? 1 : (direction.getY() < 0 ? -1 : 0)
    );
}
```

### Boundary Clamping

```cpp
Point position(250, 180);
Point minBounds(0, 0);
Point maxBounds(320, 240);

// Clamp X coordinate
if (position.getX() < minBounds.getX()) {
    position.setX(minBounds.getX());
} else if (position.getX() > maxBounds.getX()) {
    position.setX(maxBounds.getX());
}

// Clamp Y coordinate
if (position.getY() < minBounds.getY()) {
    position.setY(minBounds.getY());
} else if (position.getY() > maxBounds.getY()) {
    position.setY(maxBounds.getY());
}
```

## Performance Considerations

### Method Efficiency

| Method | Performance | Notes |
|--------|------------|-------|
| `getX()`, `getY()` | Instant | Const methods, zero overhead |
| `offset*()` | Very Fast | Simple addition |
| `move()` cardinal | Fast | Integer arithmetic only |
| `move()` arbitrary | Moderate | Uses sin/cos |
| `midPoint()` | Fast | Division only |
| Operators | Fast | Simple arithmetic |

### Optimization Tips

1. **Use offset methods** for simple translations instead of `move()`
2. **Prefer cardinal directions** (0°, 90°, 180°, 270°) when using `move()`
3. **Use operators** for vector arithmetic - they're clear and efficient
4. **Const correctness** allows compiler optimizations
5. **Integer arithmetic** - all coordinates are int16_t for speed

**Example:**
```cpp
// Slower - uses trigonometry
point.move(90, 10);

// Faster - direct offset
point.offsetX(10);

// Both produce same result for cardinal directions
```

### Memory Footprint

- **Size**: 4 bytes per Point object
- **Efficient** for embedded systems with limited RAM
- **Suitable** for storing large arrays of points

```cpp
Point points[100];            // Only 400 bytes
Point grid[32][32];           // Only 4096 bytes
```

## Inheritance

The Point class is designed as a base class and is used by:
- **Shape** class (along with Color)
- **Image** class (along with Fillable)

The `move()` method is declared `virtual`, allowing derived classes to override movement behavior if needed.

**Example:**
```cpp
class CustomShape : public Point {
public:
    void move(double direction, double distance) override {
        // Custom movement logic
        Point::move(direction, distance);  // Call base implementation
        // Additional custom behavior
    }
};
```

## Technical Notes

### Coordinate System
- Origin (0, 0) is at the **top-left corner**
- X-axis increases to the **right**
- Y-axis increases **downward** (standard screen coordinates)

### Movement Calculation
For non-cardinal directions, `move()` uses trigonometry:
```
x_new = x + distance × sin(direction × π/180)
y_new = y - distance × cos(direction × π/180)
```
Note: Y component is negated because screen Y increases downward.

### Midpoint Calculation
The midpoint uses integer division, which truncates:
```
mid_x = (x1 + x2) / 2
mid_y = (y1 + y2) / 2
```
For odd sums, the result rounds down.

### Operator Semantics
- **Addition/Subtraction**: Treats points as 2D vectors
- **Comparison**: Checks coordinate equality
- **Assignment operators**: Modify the point in place, return reference for chaining

## Common Patterns

### Creating an offset from origin
```cpp
Point offset(10, 20);
Point position(100, 100);
Point newPos = position + offset;  // (110, 120)
```

### Calculating relative position
```cpp
Point anchor(50, 50);
Point object(80, 90);
Point relative = object - anchor;  // (30, 40)
```

### Symmetric positioning
```cpp
Point center(160, 120);
Point offset(30, 20);
Point topLeft = center - offset;      // (130, 100)
Point bottomRight = center + offset;  // (190, 140)
```

### Iterative movement
```cpp
Point pos(100, 100);
for (int i = 0; i < 10; i++) {
    pos.offsetX(5);           // Move right in steps
    // Draw or process position
}
```

### Ping-pong movement
```cpp
Point pos(100, 100);
Point velocity(2, 1);
Point minBounds(0, 0);
Point maxBounds(320, 240);

// Each frame
pos += velocity;

// Bounce off edges
if (pos.getX() <= minBounds.getX() || pos.getX() >= maxBounds.getX()) {
    velocity.setX(-velocity.getX());
}
if (pos.getY() <= minBounds.getY() || pos.getY() >= maxBounds.getY()) {
    velocity.setY(-velocity.getY());
}
```

## Method Reference Summary

### Construction
- `Point()` - Create at origin
- `Point(x, y)` - Create at coordinates

### Access
- `getX()` const - Get X coordinate
- `getY()` const - Get Y coordinate

### Modification
- `setX(x)` - Set X coordinate
- `setY(y)` - Set Y coordinate
- `setPoint(x, y)` - Set both coordinates
- `setPoint(p)` - Copy from another point

### Movement
- `move(direction, distance)` - Polar movement
- `offset(dx, dy)` - Offset both coordinates
- `offsetX(dx)` - Offset X only
- `offsetY(dy)` - Offset Y only

### Calculations
- `midPoint(p)` const - Calculate midpoint

### Operators
- `==` - Compare equality
- `!=` - Compare inequality
- `+` - Vector addition
- `-` - Vector subtraction
- `+=` - Add and assign
- `-=` - Subtract and assign

## See Also

- [Shape Class](shape.md) - Base class for drawable shapes
- [Image Class](Image.md) - Bitmap images with position
- [Line Class](LineUsage.md) - Lines use two points
- [Rectangle Class](RectangleUsage.md) - Uses point for position
- [Getting Started](getting_start.md) - Framework introduction
