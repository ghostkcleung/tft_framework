# Usage of Point

Point is a simple X, Y coordinate concept. (0, 0) is the first point of top left side of a screen.
The Point class have 2 private property: uint16_t x, y
Inside the tft_framework, most of property is declared as private so that we can only access them by getter or setter.

## Create Point Object
```
Point p;    // p will initial x:0, y:0
```
