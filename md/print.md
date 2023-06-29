# Screen print

The Screen class is inherit Print. Similar to Arduino Serial. We can call print(), println(), printf(), write(), flush() methods to output text to the screen.

## Example

```cpp
Screen *scr ;

void setup ( ) {
  // Init your scr ...
  
  scr -> clear ( );

  Font *fnt = scr -> getFont ( );
  fnt -> setScale ( 3 );

  scr -> println(78, BIN);      // gives "1001110"
  scr -> println(78, OCT);      // gives "116"
  scr -> println(78, DEC);      // gives "78"
  scr -> println(78, HEX);      // gives "4E"
  scr -> println(1.23456, 0)    // gives "1"
  scr -> println(1.23456, 2);   // gives "1.23"
  scr -> println(1.23456, 4);   // gives "1.2346"
}
```
