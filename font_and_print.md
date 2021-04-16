# Font
```cpp
Font *f = new Font5X7();     // Usually the font is assigned to pointer.
f -> setChar ( 'A' );        // Set character
f -> setRGB ( 0x0000FF );    // Set to Blue
f -> setPoint ( 10, 20 );
f -> draw ( scr ) ;

f -> setScale ( 3 );         // Scale the font to 3x.
f -> setPoint ( 50, 20 );
f -> draw ( scr ) ;

delete f;                   // Deallocate
```

# Print
The Screen class is inherit offical Print class.
So you can print the text easier than draw each font.
The usage of print just like Serial.print()
```cpp

scr -> setFont ( new Font5X7() );               // It's not necessary when using default font.
scr -> setFontColor ( Color ( 0x0000FF ) ) ;    // Set the print color to blue.
scr -> setFontScale ( 3 );                      // Set the font size to 3x.
scr -> setFontPadding ( 1 ) ;                   // The distance of each char.
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
