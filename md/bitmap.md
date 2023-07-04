# Bitmap Image

You can show a bitmap image to the screen by the reading from File. Ususally it is read from SD card (or SPIFFS when using ESP32). For the usage of File I/O, you can see the following tutorials:

https://docs.arduino.cc/learn/programming/sd-guide

https://randomnerdtutorials.com/install-esp32-filesystem-uploader-arduino-ide/

## Example
```cpp

void setup ( ) {
  scr->init();
  scr->clear();

  // File file = PREPAIR YOUR FILE OBJECT

  Image *img = new Bitmap(file);

  img -> fill ( _scr ) ;

  delete img;
  file.close ( ) ;
}
```

The above example shows the image at the top left of the screen. As the other Shape. You can set the position of the image with setPoint (x, y)
```cpp
img -> setPoint ( 50, 100 ) ;
```
You can get the size of image
```cpp
uint16_t w = img -> getWidth ( );
uint16_t h = img -> getHeight ( );
```

# Viewport
When the image is loaded. You may draw the part of the image by setting of the viewport. For example I want to draw the part as following.

![image](/320x240.jpg)
```cpp
Rectangle viewport;
viewport.setPoint ( 40, 135 );
viewport.setSize ( 140, 80 );
img -> setViewport ( viewport );
img -> fill ( scr ) ;
```

The result will be

![image](/viewport.jpg)

