# Add BMFont Support

BMFont offical site: https://www.angelcode.com/products/bmfont/

As the offical site above, it is a software to convert bitmap from TrueType font.
So we can show the unicode text from our screen.

### Examples
![image](/BmFont.jpg)
Firstly, let's use the font called "Noto Sans Traditional Chinese" that can downloaded from google.

https://fonts.google.com/noto/specimen/Noto+Sans+TC

- In the BMFont, click [Options] -> [Font Settings] -> [Add font...]

- Charset: Must select "Unicode".

- Size: 64 ( I use 64 for this example )

- At the [Export options] -> [Font], must select "Text".
- Textures: Must select "tga - Targa"
- Compressior: Must select "none"

Then select characters those you need. Usually we select all of the page of "000000 Latin". Save the bitmap font. For this example, we name it as "64_Noto_Sans_TC". You will get the file "64_Noto_Sans_TC.fnt", "64_Noto_Sans_TC_0.tga", "64_Noto_Sans_TC_1.tga" ...

Inside the tga file, there is informations of the chars those you saved. It is plain text file.

```cpp
Screen scr = /* YOUR SCREEN */
File path = /* YOUR_PATH */

BmFont *bmFont = new BmFont(path, "64_Noto_Sans_TC.fnt");

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

If you run it successfully, You can find that the lagacy at first line of strings. And there is smoother at the 2nd and 3rd line. It is because the pixel of chars are cached into the memory when reading at the 1st line.

The default cache size is 100. You can adjust the cache size by calling bmFont->setCacheSize(n)

When the cache is full. The program will delete the char that is the least commonly used.
