# Rectangle

Drawing any graphics will be based on "fillRect()". for example, "Dot" is a 1x1 and a horizonal / vertical line is 1xN rectangle fill. We need to override "fillRect()" When we implement a Screen instance.

Similar to line, Rectangle has color, point and endPoint.
It inherit Shape and Fillable. we can draw and fill a rectangle.

## Methods
```cpp
void setSize ( uint16_t w, uint16_t h );
void setSize ( Rectangle r );
void setWidth ( uint16_t w );
void setHeight ( uint16_t h );

uint16_t getWidth ( );
uint16_t getHeight ( );
```
## Example:
```cpp
Screen *scr ;

void setup ( ) {
  // Init your scr ...
  
  scr -> clear ( );

  // red, green and blue
  uint32_t color[]={0xFF0000, 0x00FF00, 0x0000FF};

  Rectangle r;
  r.setPoint ( 50, 50 );
  r.setSize ( 100, 100 );

  for ( int i = 0; i < 3; i ++ ) {
    r.setRGB ( color[i] ) ;
    r.move ( 135, 30 );
    r.draw ( scr ) ;
  }

  r.moveTo ( 250, 50 );

  for ( int i = 0; i < 3; i ++ ) {
    r.setRGB ( color[i] ) ;
    r.move ( 135, 30 );
    r.fill ( scr ) ;
  }  
}
```

