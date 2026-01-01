# Other Shapes

This document covers additional geometric shapes supported by TFT Framework.

## Triangle

**Inherits:** Shape  
**Implements:** Fillable

A triangle is defined by three points: `Point` (base class), `P2`, and `P3`.

### Methods

```cpp
// First point inherited from Point class
void setPoint(Point p);
void setPoint(int16_t x, int16_t y);

// Second point
void setP2(Point p);
void setP2(int16_t x, int16_t y);
Point getP2();

// Third point
void setP3(Point p);
void setP3(int16_t x, int16_t y);
Point getP3();
```

### Example

```cpp
Triangle t;
t.setRGB(0xFF0000);      // Red
t.setPoint(75, 25);      // First point
t.setP2(25, 112);        // Second point
t.setP3(125, 112);       // Third point
t.draw(scr);             // Draw outline
t.fill(scr);             // Fill triangle
```

---

## Circle

**Inherits:** Shape  
**Implements:** Fillable

A circle is defined by a center point (inherited from Point) and a radius.

### Methods

```cpp
void setRadius(uint16_t r);
uint16_t getRadius();
```

### Example

```cpp
Circle c;
c.setRGB(0x00FF00);      // Green
c.setPoint(75, 200);     // Center point
c.setRadius(50);         // Radius
c.draw(scr);             // Draw outline
c.fill(scr);             // Fill circle
```

---

## Ellipse

**Inherits:** Shape  
**Implements:** Fillable

An ellipse is similar to a circle but has two radii: horizontal (Rx) and vertical (Ry).

### Methods

```cpp
void setRx(uint16_t rx);  // Horizontal radius
void setRy(uint16_t ry);  // Vertical radius
uint16_t getRx();
uint16_t getRy();
```

### Example

```cpp
Ellipse e;
e.setRGB(0x0000FF);      // Blue
e.setPoint(370, 70);     // Center point
e.setRx(80);             // Horizontal radius
e.setRy(40);             // Vertical radius
e.draw(scr);             // Draw outline
e.fill(scr);             // Fill ellipse
```

---

## Complete Example

```cpp
Screen* scr;

void setup() {
    // Initialize your screen...
    
    scr->clear();

    // Triangle
    Triangle t;
    t.setRGB(0xFF0000);
    t.setPoint(75, 25);
    t.setP2(25, 112);
    t.setP3(125, 112);
    t.draw(scr);

    t.move(90, 125);  // Move right
    t.fill(scr);

    // Circle
    Circle c;
    c.setRGB(0x00FF00);
    c.setPoint(75, 200);
    c.setRadius(50);
    c.draw(scr);

    c.move(90, 125);
    c.fill(scr);

    // Ellipse
    Ellipse e;
    e.setRGB(0x0000FF);
    e.setPoint(370, 70);
    e.setRx(80);
    e.setRy(40);
    e.draw(scr);

    e.move(180, 125);
    e.fill(scr);
}
```

### Output

<img src="OtherShape.jpg" width="480" />
