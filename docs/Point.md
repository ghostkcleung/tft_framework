# Point Class

The `Point` class represents a 2D coordinate point with comprehensive manipulation and calculation capabilities. It provides efficient coordinate management, movement functionality, distance calculations, and operator overloading for intuitive vector operations.

## Features

- **Efficient Coordinate Access**: Inline const getters for zero-overhead coordinate retrieval
- **Distance Calculations**: Both Euclidean and Manhattan distance methods
- **Operator Overloading**: Intuitive vector arithmetic with +, -, +=, -= operators
- **Movement System**: Polar coordinate-based movement with optimized cardinal directions
- **Comparison Operators**: Equality and inequality checking

## Constructors

```cpp
Point()                        // Create a point at origin (0, 0)
Point(int16_t x, int16_t y)   // Create a point at specified coordinates
```

## Member Functions

### Get Coordinates

```cpp
int16_t getX() const  // Get X coordinate (inline)
int16_t getY() const  // Get Y coordinate (inline)
```

These methods are marked as `const` and `inline` for optimal performance.

### Set Coordinates

```cpp
void setX(int16_t x)                     // Set X coordinate
void setY(int16_t y)                     // Set Y coordinate
void setPoint(int16_t x, int16_t y)      // Set both X and Y coordinates
void setPoint(const Point& p)            // Copy coordinates from another point
```

### Movement and Offset

```cpp
void move(double direction, double distance)
```

Move the point using polar coordinates:
- `direction`: Movement direction in degrees
  - 0° = North (Up)
  - 90° = East (Right)
  - 180° = South (Down)
  - 270° = West (Left)
- `distance`: Movement distance in pixels

**Optimizations**: Cardinal directions (0°, 90°, 180°, 270°) use integer arithmetic for better performance.

```cpp
void offset(int16_t dx, int16_t dy)
```
Offset the point by specified amounts in both X and Y directions. This is a simple, efficient way to move a point by a delta value.

```cpp
void offsetX(int16_t dx)
```
Offset the point only in the X direction. Useful when you need to move horizontally without affecting Y.

```cpp
void offsetY(int16_t dy)
```
Offset the point only in the Y direction. Useful when you need to move vertically without affecting X.

### Distance and Midpoint Calculations

```cpp
double distanceTo(const Point& other) const
```
Calculate the Euclidean distance to another point using the formula: $\sqrt{(x_2-x_1)^2 + (y_2-y_1)^2}$

```cpp
int16_t manhattanDistanceTo(const Point& other) const
```
Calculate the Manhattan distance (taxicab distance): $|x_2-x_1| + |y_2-y_1|$

Manhattan distance is faster to compute and useful for grid-based movement systems.

```cpp
Point midPoint(const Point& p) const
```
Calculate the midpoint between this point and another point. Returns a new Point object at the halfway position between the two points. Useful for finding centers, interpolation, or bisecting line segments.

### Operator Overloads

#### Comparison Operators
```cpp
bool operator==(const Point& other) const  // Equality comparison
bool operator!=(const Point& other) const  // Inequality comparison
```

#### Arithmetic Operators
```cpp
Point operator+(const Point& other) const   // Vector addition
Point operator-(const Point& other) const   // Vector subtraction
Point& operator+=(const Point& other)       // Add and assign
Point& operator-=(const Point& other)       // Subtract and assign
```

## Usage Examples

### Basic Usage

```cpp
using namespace tft_framework;

// Create points
Point p1;                    // Default at (0, 0)
Point p2(100, 200);         // At coordinates (100, 200)

// Get coordinates
int16_t x = p2.getX();      // x = 100
int16_t y = p2.getY();      // y = 200

// Set coordinates
p1.setX(50);
p1.setY(75);
// Or set both at once
p1.setPoint(50, 75);

// Copy from another point
p1.setPoint(p2);
```

### Movement Operations

```cpp
Point p(100, 100);

// Move in cardinal directions (optimized)
p.move(0, 10);              // Move up 10 pixels → (100, 90)
p.move(90, 20);             // Move right 20 pixels → (120, 90)
p.move(180, 5);             // Move down 5 pixels → (120, 95)
p.move(270, 15);            // Move left 15 pixels → (105, 95)

// Move at angles
p.move(45, 14);             // Move northeast ~14 pixels
p.move(135, 10);            // Move southeast ~10 pixels

// Offset operations
Point p2(50, 50);
p2.offset(10, -5);          // Move by delta → (60, 45)
p2.offsetX(20);             // Move right only → (80, 45)
p2.offsetY(10);             // Move down only → (80, 55)
```

### Distance Calculations

```cpp
Point p1(0, 0);
Point p2(30, 40);

// Euclidean distance
double dist = p1.distanceTo(p2);  // dist = 50.0

// Manhattan distance (faster)
int16_t manhattan = p1.manhattanDistanceTo(p2);  // manhattan = 70

// Find midpoint between two points
Point mid = p1.midPoint(p2);      // mid = (15, 20)

// Check if points are within range
if (p1.distanceTo(p2) < 100) {
    // Points are close enough
}
```

### Operator Overloading

```cpp
Point p1(10, 20);
Point p2(30, 40);

// Comparison
if (p1 == p2) {
    // Points are at the same location
}

if (p1 != p2) {
    // Points are at different locations
}

// Vector addition
Point p3 = p1 + p2;         // p3 = (40, 60)

// Vector subtraction
Point offset = p2 - p1;     // offset = (20, 20)

// Compound assignment
p1 += Point(5, 5);          // p1 = (15, 25)
p2 -= Point(10, 10);        // p2 = (20, 30)

// Practical example: offset an object
Point objectPos(100, 100);
Point offset(10, -5);
objectPos += offset;        // Move object to (110, 95)
```

### Advanced Examples

```cpp
// Calculate vector between two points
Point start(50, 50);
Point end(150, 100);
Point direction = end - start;  // direction = (100, 50)

// Check if point is within a bounding box
Point point(120, 80);
Point topLeft(100, 50);
Point bottomRight(200, 150);

if (point.getX() >= topLeft.getX() && 
    point.getX() <= bottomRight.getX() &&
    point.getY() >= topLeft.getY() && 
    point.getY() <= bottomRight.getY()) {
    // Point is inside the box
}

// Find the closest point from a list
Point target(100, 100);
Point points[] = {Point(50, 50), Point(120, 90), Point(80, 120)};
Point* closest = &points[0];
double minDist = target.distanceTo(points[0]);

for (int i = 1; i < 3; i++) {
    double dist = target.distanceTo(points[i]);
    if (dist < minDist) {
        minDist = dist;
        closest = &points[i];
    }
}

// Grid-based pathfinding (using Manhattan distance)
Point current(5, 5);
Point goal(10, 8);
int16_t stepsRemaining = current.manhattanDistanceTo(goal);  // = 8
```

## Performance Considerations

### Inline Getters
The `getX()` and `getY()` methods are inline and const, resulting in zero function call overhead.

### Move Optimization
The `move()` method detects cardinal directions and uses fast integer arithmetic instead of trigonometric functions:
- Cardinal directions: ~2-3 CPU cycles
- Arbitrary angles: ~50-100 CPU cycles (sin/cos calculation)

### Distance Calculations
- **Euclidean distance**: More accurate but requires `sqrt()` calculation
- **Manhattan distance**: Faster, only requires addition and absolute value

Use Manhattan distance for:
- Grid-based games
- Quick proximity checks
- A* pathfinding heuristics

Use Euclidean distance for:
- Precise circular range checks
- Physics calculations
- Smooth diagonal movement

## Implementation Details

### Coordinate System
- Origin (0, 0) is at the top-left corner
- X increases to the right
- Y increases downward
- Coordinates are stored as `int16_t` (range: -32,768 to 32,767)

### Movement Calculation
For non-cardinal directions, new coordinates are calculated using:
```
x_new = x + distance × sin(direction)
y_new = y - distance × cos(direction)
```
Note: Y is negated because screen coordinates increase downward.

### Memory Footprint
- Size: 4 bytes (2 × int16_t)
- Efficient for embedded systems with limited RAM
- Suitable for storing large arrays of points
