Class: Dot

Inherit class: Shape

# Usage of Dot

Dot is a 1x1 Rectangle to draw to the screen.
After set the Point(position) and Color, you can draw a dot to the screen.

```cpp
Screen *scr;

void setup(){
  // ... init your screen

  Dot d;

  d.setRGB ( 0xFF0000 ) ;   // Set the dot to red
  d.setPoint ( 3, 4 ) ;

  d.draw ( scr ) ;
}

void loop(){
  delay ( 10000 ) ;
}
```
