# Usage of Point

Point is a simple X, Y coordinate concept. (0, 0) is the first point of top left side of a screen. It is not a drawable object. You should use the [Dot](DotUsage.md) if you want to draw a pixel with color to a screen.

The Point class have 2 private properties: x, y (int16_t)

Inside the tft_framework, most of properties of classes are declared as private so that we can access them by getter or setter only.

## Create a Point Object
The easiest way to create a Point.
```cpp
Point p;          // p will be initialled as x:0, y:0
```
We can provide initial values at creation time
```cpp
Point p(10, 15);  // x:10, y:15
```
## Setter and getter
The following methods can get or change the properties of the Point object.
```cpp
int16_t getX();
int16_t getY();

void setX (int16_t x);
void setY (int16_t y);

void setPoint (int16_t x, int16_t y);
void setPoint (Point p);
```
## Move the Point
We can move the point by the move method.
```cpp
void move (double direction, double distance);

// Direction: 0 to 359 degree.
// 0 is North ( or upper side of the screen )
// 90 is the right side of the screen

// Example:
Point p(100,100);   // x:100, y:100
p.move(120,50);     // direction: 120 degree, distance.
                    // Finally, x: 143, y:125
```
