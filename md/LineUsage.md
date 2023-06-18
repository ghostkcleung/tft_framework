# Line

When we set the start point and the end point, we can draw a line.

## Methods
Basic point and color methods:
```cpp
void setPoint ( Point p );
void setPoint ( int16_t x, int16_t y );

Point getPoint ( );
```
## Examples
```cpp
Screen *scr ;

void setup ( ) {
  // Init your scr ...
  
  scr -> clear ( );

  Line l;
  l.setColor ( 0xFFFF );  // White color

  l.setPoint ( 50, 50 );
  
}
```

