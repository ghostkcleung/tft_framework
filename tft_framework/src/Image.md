# Add Image Support

You can load and draw the Image file from the SD card as following.

```cpp
Screen scr = /* YOUR SCREEN */
File f = SD.open ( /* YOUR_PATH */ ) ;
Image *img = new Image ( f ) ;
img -> fill ( scr ) ;
