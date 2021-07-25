# Add Image Support

You can load and draw the Image file from the SD card as following. tft_framework is support BMP 24bit and 16bit format temporary. I will implement more type of image such as JPG, PNG ... in the future.

```cpp
Screen scr = /* YOUR SCREEN */
File f = SD.open ( /* YOUR_PATH */ ) ;
Image *img = new Image ( f ) ;
img -> fill ( scr ) ;
```

# Usage of Image
As the other Shape. You can set the position of the image with setPoint (x, y)
```cpp
img.setPoint ( 50, 100 ) ;
```
