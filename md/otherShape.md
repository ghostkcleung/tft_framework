# Other Shapes
There are some shapes those we can draw or fill.

- Triangle
- Circle
- Ellipse

## Triangle
A triangle is composed of 3 points: Point, P2, P3

## Methods of Triangle
```cpp
void setPoint ( Point p );
void setPoint ( int16_t x, int16_t y );

void setP2 ( Point p );
void setP2 ( int16_t x, int16_t y );

void setP3 ( Point p );
void setP3 ( int16_t x, int16_t y );

Point getP2 ( );
Point getP3 ( );
```

## Circle
The Point property is the center point of a circle. And it have a radius property.

## Methods of Circle
```cpp
void setRadius ( uint16_t r ) ;
uint16_t getRadius ( ) ;
```

## Ellipse
Similar to Circle, Ellipse has Rx and Ry properties.

## Methods of Ellipse
```cpp
void setRx( uint16_t rx );
void setRy( uint16_t ry );
uint16_t getRx();
uint16_t getRy();
```
## Example
```cpp
Screen *scr ;

void setup ( ) {
  // Init your scr ...
  
  scr -> clear ( );

  Triangle t;
  t.setRGB ( 0xFF00000 ) ;
  t.setPoint ( 50, 25 );
  t.setP2 ( 25, 68 );
  t.setP3 ( 75, 68 );
  t.draw ( scr ) ;

  t.moveTo ( 100, 25 ) // move right, distance 100
  t.fill ( scr ) ;
}
```
