# Usage of Point

Point is a simple X, Y coordinate concept. (0, 0) is the first point of top left side of a screen.

The Point class have 2 private property: int16_t x, y

Inside the tft_framework, most of property is declared as private so that we can access them by getter or setter only.

## Create Point Object
The easiest way to create a Point.
```cpp
Point p;          // p will initial x:0, y:0
```
We can provide the initial value at creation time
```cpp
Point p(10, 15);  // x:10, y:15
```
We can create a Point with the same as another Point.
```cpp
Point p1(20,30);
Point p2(p1);       // x:20, y:30
```
## The setter and getter
void setX ( int16_t x )
void setY ( int16_t y )
void setPoint ( int16_t x, int16_t y )
void setPoint ( Point p )

The 
