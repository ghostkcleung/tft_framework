# Point Usage

The `Point` class represents a 2D coordinate in the display space. The origin `(0, 0)` is located at the top-left corner of the screen.

**Note:** Point is not a drawable object. To draw a single pixel, use the [Dot](DotUsage.md) class.

## Class Properties

The Point class has two private properties:
- `x` (int16_t) - Horizontal coordinate
- `y` (int16_t) - Vertical coordinate

All properties are accessed through getter and setter methods to maintain encapsulation.

## Creating a Point

### Default Constructor

```cpp
Point p;  // Initializes to (0, 0)
```

### Constructor with Initial Values

```cpp
Point p(10, 15);  // Creates point at x:10, y:15
```

## Accessing and Modifying Coordinates

### Getters

```cpp
int16_t getX();
int16_t getY();
```

### Setters

```cpp
void setX(int16_t x);
void setY(int16_t y);
void setPoint(int16_t x, int16_t y);
void setPoint(Point p);
```

## Moving Points

Move a point using polar coordinates (direction and distance):

```cpp
void move(double direction, double distance);
```

**Parameters:**
- `direction`: Angle in degrees (0-359)
  - 0° = North (upward)
  - 90° = East (right)
  - 180° = South (downward)
  - 270° = West (left)
- `distance`: Distance to move

### Example

```cpp
Point p(100, 100);  // Start at (100, 100)
p.move(120, 50);    // Move 120° at distance 50
                    // Result: x: 143, y: 125
```
