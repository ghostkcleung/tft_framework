# Font

Font is a drawable shape (but not fillable). The 5x7 font is built-in at the framework as default font.

5x7 font is a matrix array. The dimension is 5 X 7 pixels.

It is stored at the program memories (ROM).

For example, matrix 'A' is \[0x7E\], \[0x11\], \[0x11\], \[0x11\], \[0x7E\]

It will be rendered as following:
```
01110
10001
10001
10001
11111
10001
10001
00000
```

## Methods
```cpp
uint32_t getChar();
virtual void setChar(uint32_t c);

uint8_t getScale();
void setScale(uint8_t s);

// Dimension
uint8_t getWidth();
uint8_t getHeight();

// Padding
uint8_t getPaddingTop();
uint8_t getPaddingLeft();
uint8_t getPaddingBottom();
uint8_t getPaddingRight();

void setPaddingTop(uint8_t paddingTop);
void setPaddingLeft(uint8_t paddingLeft);
void setPaddingBottom(uint8_t paddingBottom);
void setPaddingRight(uint8_t paddingRight);

// Spacing
uint8_t getSpacingTop();
uint8_t getSpacingLeft();
uint8_t getSpacingBottom();
uint8_t getSpacingRight();

void setSpacingTop(uint8_t spacingTop);
void setSpacingLeft(uint8_t spacingLeft);
void setSpacingBottom(uint8_t spacingBottom);
void setSpacingRight(uint8_t spacingRight);

// Total width is padding + spacing + width
virtual uint8_t getTotalWidth ( );
virtual uint8_t getTotalHeight ( );
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
    - 1: CW0 (Mirror)
    - 2: CW90
    - 3: CW90 (Mirror)
    - 4: CW180
    - 5: CW180 (Mirror)
    - 6: CW270
    - 7: CW270 (Mirror)

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
