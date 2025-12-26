# Point Class

The `Point` class represents a 2D coordinate point and provides movement functionality.

## Constructors

```cpp
Point()                        // Create a point at (0, 0)
Point(int16_t x, int16_t y)   // Create a point at specified coordinates
```

## Member Functions

### Get Coordinates
```cpp
int16_t getX()  // Get X coordinate
int16_t getY()  // Get Y coordinate
```

### Set Coordinates
```cpp
void setX(int16_t x)                  // Set X coordinate
void setY(int16_t y)                  // Set Y coordinate
void setPoint(int16_t x, int16_t y)   // Set both X and Y coordinates
void setPoint(Point p)                // Copy coordinates from another point
```

### Move Point
```cpp
void move(double direction, double distance)
```
- `direction`: Movement direction (in degrees)
  - 0° = Up
  - 90° = Right
  - 180° = Down
  - 270° = Left
- `distance`: Movement distance (in pixels)

## Usage Example

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
// Or
p1.setPoint(50, 75);

// Move point
p2.move(0, 10);             // Move up 10 pixels
p2.move(90, 20);            // Move right 20 pixels
p2.move(45, 15);            // Move 15 pixels at 45° angle
```

## Implementation Details

The `move()` method uses trigonometry to calculate new coordinates based on direction and distance:
- For cardinal directions (0°, 90°, 180°, 270°), it uses optimized integer arithmetic
- For other angles, it uses sine and cosine functions with proper rounding
- Direction angles are normalized to 0-360° range
