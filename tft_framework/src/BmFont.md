# Add BMFont Support

BMFont offical site: https://www.angelcode.com/products/bmfont/(https://www.angelcode.com/products/bmfont/)

As the offical site above, it is a software to convert bitmap from truetype font.


```cpp
Screen scr = /* YOUR SCREEN */
File path = /* YOUR_PATH */

BmFont *bmFont = new BmFont(path, "/*** Your fnt file ***/");

if (!bmFont->isValid()) {
  scr->println("File not found or parse error.");
  delay(1 << 31);
}

/*** Replace Font ***/
Font *oldFont = scr->getFont();
scr->setFont(bmFont);
delete oldFont;

scr->clear();
scr->println("Hello,world!");
scr->println("你好,世界!");
```
