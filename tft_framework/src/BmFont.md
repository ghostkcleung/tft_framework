# Add BMFont Support

BMFont offical site: https://www.angelcode.com/products/bmfont/

As the offical site above, it is a software to convert bitmap from TrueType font.
So we can show the unicode text from our screen.

### Examples

Firstly, I use the font is called "Noto Sans Traditional Chinese" that can downloaded from google.

https://fonts.google.com/noto/specimen/Noto+Sans+TC

- In the BMFont, click [Options] -> [Font Settings] -> [Add font...]

- Charset: Must select "Unicode".

- Size: 64 ( I use 64 for this example )

- At the [Export options] -> [Font], must select "Text".



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
scr->println("Hello! 你好! こんにちは!");
scr->println("Hello! 你好! こんにちは!");
scr->println("Hello! 你好! こんにちは!");
```
![image](/BmFont.jpg)
