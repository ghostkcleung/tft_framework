# Bitmap Image

You can show a bitmap image to the screen by the reading from File. Ususally it is read from SD card (or SPIFFS when using ESP32). For the usage of File I/O, you can see the following tutorial:

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
