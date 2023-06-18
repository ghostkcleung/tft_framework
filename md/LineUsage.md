# Line

When we set the start point and the end point, we can draw a line.

## Examples
```cpp
Screen *scr ;

void setup ( ) {
  // Init your scr ...
  
  scr -> clear ( );
  randomSeed(analogRead(0));

  Dot d;
  uint16_t w = scr -> getWidth ( );
  uint16_t h = scr -> getHeight ( );

  for ( int y = 0; y < h; y ++ ) {
    for ( int x = 0; x < w; x ++ ) {
      d.setPoint ( x, y );
      d.setColor ( random ( 0xFFFF ) ) ;
      d.draw ( scr ) ;
    }
  }
}
```

