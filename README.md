- [Getting Start](./getting_start.md)
- [Tutorial](./tutorial.md)

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

# BufferScreen
The buffer is a virtual screen. You can draw something to it to store the content.
Then fill to the real screen. Sometimes it can be more efficiency. The buffer can be enlarge.
But be attention for the limitation of memory size. It need 2byte per pixel. There is 8k bytes inside the Arduino Mega 2560. That means the maxium bounds of buf can be about 60x60 only. And remember to deallocate it when not use. 
60x60x2 = 7200bytes

```cpp
BufferScreen *buf = new BufferScreen ( 40, 40 );      // Create the buffer with bounds 40x40.
buf -> setRGB ( 0xFFFF00 );                     // Set the background Color to yellow.
buf -> clear ( );

Triangle t;
t.setPoint ( 0,39 );
t.setP2 ( 19, 0 );
t.setP3 ( 39, 39);

t.draw ( buf );

buf -> setPoint ( 20, 20 );
buf -> fill ( scr );           // Fill the buffer to real screen

buf -> setScale ( 3 );         // Enlarge to 3x
buf -> setPoint ( 20, 100 );
buf -> fill ( scr );           // Fill the buffer to real screen

delete buf;                                     // Deallocate
```

# Implement you custom shape
https://github.com/ghostkcleung/tft_framework/blob/master/CustomShape.md

# Implement your own screen
https://github.com/ghostkcleung/tft_framework/blob/master/tft_implement/README.md


