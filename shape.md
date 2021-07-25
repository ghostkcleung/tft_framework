# Shape
The following type is inherit Shape:
- Dot
- Line
- Rectangle
- Triangle
- Circle
- Ellipse
- Font

All of them have the properties of Point and Color.
They are Drawable. And most of them are Fillable except:

- Dot
- Line
- Font

# Usage of Dot
```cpp
Dot d;
d.setPoint ( 10, 20 );  // Set the position of the dot.
d.setRGB ( 0xFF0000 );  // Set the color of the dot.
d.draw ( scr ) ;        // Draw the dot to the screen.

while ( d.getX ( ) < 400 ) {
    d.move ( 90, 5 );   // Move to right, distance 5.
    d.draw ( scr );     // Draw each iterated dot.
}
```

# Usage of Line
```cpp
Line l;
l.setPoint ( 10, 20 );      // Start point
l.setEndPoint ( 50, 60 );   // End point
l.draw ( scr );

l.moveTo ( 100, 100 );  // Move the line to 100, 100
l.draw ( scr );         // The endPoint should be 140, 140

l.lineTo ( 135, 50 );   // Set the end to 135 degree of start point, distance 50
l.draw ( scr );
```

# Usage of Rectangle
```cpp
Rectangle r;
r.setPoint ( 10, 20 );       // Start Point
r.setEndPoint ( 60, 100 ) ;  // End Point
r.draw ( scr );              // Draw the rectangle to screen

r.setPoint ( 100, 50 );
r.setWidth ( 60 );           // End point of X: 159
r.setHeight ( 120 );         // End point of X: 169
// You may also write it as: r.setSize ( 60, 120 ) ;
r.fill ( scr );              // Fill to screen
```

# Usage of Triangle
```cpp
Triangle t;
t.setPoint ( 10, 10 );      // The first point
t.setP2 ( 10, 40 );         // The second point
t.setP3 ( 50, 40 );         // The third point
t.draw ( scr );             // There will be right angle triangle 30, 40, 50 
```

# Usage of Circle
```cpp
Circle c;
c.setPoint ( 150, 100 );    // Center point
c.setRadius ( 70 );         // Radius
c.fill ( scr );             // Fill to screen
```

# Usage of Ellipse
```cpp
Ellipse e;
c.setPoint ( 150, 150 );    // Center point
e.setRx ( 70 );             // Rx
e.setRy ( 100 );            // Ry
e.fill ( scr );
```
