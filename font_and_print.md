# Font

Font is a drawable shape (but not fillable). The 5x7 font is built-in at the framework as default font.

```cpp
Font *f = new Font5X7();     // Usually the font is assigned to pointer.
f -> setChar ( 'A' );        // Set character
f -> setRGB ( 0x0000FF );    // Set to Blue
f -> setPoint ( 10, 20 );
f -> draw ( scr ) ;

f -> setScale ( 3 );         // Scale the font to 3x.
f -> setPoint ( 50, 20 );
f -> setPaddingTop ( 1 ) ;
f -> setPaddingLeft ( 1 ) ;
f -> draw ( scr ) ;

delete f;                   // Deallocate
```

# Print
The Screen class is inherit offical Print class.
So you can print the text easier than draw each font.
The usage of print just like Serial.print()
```cpp

scr -> setFont ( new Font5X7() );               // It's not necessary when using default font.
scr -> getFont ( ) -> setColor ( Color ( 0x0000FF ) ) ;    // Set the print color to blue.
scr -> getFont ( ) -> setScale ( 3 );           // Set the font size to 3x.
scr -> getFont ( ) -> setPaddingTop ( 1 ) ;     // Padding Top.
scr -> getFont ( ) -> setPaddingLeft ( 1 ) ;    // Padding Left.
scr -> setCursor ( 18, 24 );                    // Set the print cursor

scr -> println ( 78 );              // 78
scr -> println ( 1.23456 );         // 1.23
scr -> println ( 'N' );             // N
scr -> println ( "Hello world." );  // Hello world.

scr -> println(78, BIN);      // 1001110
scr -> println(78, OCT);      // 116
scr -> println(78, DEC);      // 78
scr -> println(78, HEX);      // 4E
scr -> println(1.23456, 0); // 1
scr -> println(1.23456, 2); // 1.23
scr -> println(1.23456, 4); // 1.2346
```

# Methods of Screen

- Usually we should call before start to draw everything
  - void init()

- Orientation of the screen
  - void setRotate(uint8_t rotate)
  - uint8_t setRotate()

  - Accept value (0-7)
    - 0: CW0

- The background color
  - void setColor (Color c)
  - Color getColor()
  - clear()

- Is the font drawn to the buffer before print
  - void setPrintBufferd(boolean b)
  - boolean isBuffered()
 
- The position to print
  - void setCursor(Point p)
  - Point getCursor()
  - void resetCursor()
