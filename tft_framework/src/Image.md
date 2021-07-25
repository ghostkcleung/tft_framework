# Add Image Support

You can load and draw the Image file from the SD card as following. tft_framework is support BMP 24bit and 16bit format temporary. I will implement more type of image such as JPG, PNG ... in the future.

```cpp
Screen scr = /* YOUR SCREEN */
File f = SD.open ( /* YOUR_PATH */ ) ;
Image *img = new Image ( f ) ;
img -> fill ( scr ) ;

delete img;   // The file also is closed when allocate the image object
```

# Usage of Image
As the other Shape. You can set the position of the image with setPoint (x, y)
```cpp
img.setPoint ( 50, 100 ) ;
```

You can get the size of image
```cpp
uint16_t w = img -> getWidth ( );
uint16_t h = img -> getHeight ( );
```

# Viewport
When the image is loaded. You may draw the part of the image by setting of the viewport. For example the size of my image is 320x240. And I want to draw the part as following.
![image](./320x240.jpg)
```cpp
uint16_t w = img -> getWidth ( );
uint16_t h = img -> getHeight ( );
```
