# Rectangle

Drawing any graphics will be based on "fillRect()". for example, "Dot" is a 1x1 and a horizonal / vertical line is 1xN rectangle fill. We need to override "fillRect()" When we implement a Screen instance.

Similar to line, Rectangle has color, point and endPoint.
It inherit Shape and Fillable. we can draw and fill a rectangle.

##Example:
```cpp
Screen *scr ;

void setup ( ) {
  // Init your scr ...
  
  scr -> clear ( );

  Rectangle r;
  r.setRGB ( 0xFF0000 );  // Red color
  l.setPoint ( 50, 50 );
  l.setEndPoint ( 75, 75 );

                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  
}
```
