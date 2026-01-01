# Bitmap Images

TFT Framework supports displaying BMP (bitmap) images loaded from file storage such as SD cards or ESP32's SPIFFS/LittleFS.

## File I/O Resources

For file system operations, refer to:

- **Arduino SD Card Guide:** [https://docs.arduino.cc/learn/programming/sd-guide](https://docs.arduino.cc/learn/programming/sd-guide)
- **ESP32 SPIFFS Guide:** [https://randomnerdtutorials.com/install-esp32-filesystem-uploader-arduino-ide/](https://randomnerdtutorials.com/install-esp32-filesystem-uploader-arduino-ide/)

## Basic Usage

### Loading and Displaying

```cpp
#include <SD.h>
#include <Bitmap.h>

void setup() {
    scr->init();
    scr->clear();

    // Open BMP file
    File file = SD.open("/image.bmp");
    
    // Create Bitmap object
    Image* img = new Bitmap(file);

    // Display at (0, 0)
    img->fill(scr);

    // Clean up
    delete img;
    file.close();
}
```

## Positioning

Like other shapes, you can set the image position:

```cpp
img->setPoint(50, 100);  // Display at (50, 100)
img->fill(scr);
```

## Getting Image Dimensions

```cpp
uint16_t w = img->getWidth();
uint16_t h = img->getHeight();
```

## Viewport

Display only a portion of the image using a viewport rectangle.

### Example

To display a 140×80 region starting at (40, 135) from the source image:

![Original Image](/docs/320x240.jpg)

```cpp
// Define viewport
Rectangle viewport;
viewport.setPoint(40, 135);    // Top-left corner of region
viewport.setSize(140, 80);     // Width and height

// Apply viewport
img->setViewport(viewport);
img->fill(scr);
```

### Result

![Viewport Result](docs//viewport.jpg)

## Complete Example

```cpp
Screen* scr;

void setup() {
    // Initialize screen
    scr->init();
    scr->clear();

    // Initialize SD card
    if (!SD.begin()) {
        return;  // SD card initialization failed
    }

    // Open BMP file
    File file = SD.open("/photo.bmp");
    if (!file) {
        return;  // File not found
    }

    // Create bitmap
    Image* img = new Bitmap(file);

    // Display full image at (10, 10)
    img->setPoint(10, 10);
    img->fill(scr);

    // Display cropped section
    Rectangle viewport;
    viewport.setPoint(50, 50);
    viewport.setSize(100, 100);
    img->setViewport(viewport);
    
    img->setPoint(200, 10);  // Display cropped version here
    img->fill(scr);

    // Clean up
    delete img;
    file.close();
}
```

## Supported Format

- **File Type:** BMP (Bitmap)
- **Color Depth:** Typically 24-bit RGB (converted to RGB565)
- **Compression:** Uncompressed BMP recommended

## Notes

1. **Large images** may consume significant memory during loading
2. **File format** must be valid BMP with proper headers
3. **Color conversion** from 24-bit to RGB565 happens automatically
4. **Viewport** allows efficient partial rendering without loading entire image
5. **Performance** depends on SD card speed and image size

## Troubleshooting

- **Image not displaying:** Check file path and BMP format
- **Colors wrong:** Ensure BMP is 24-bit RGB format
- **Memory errors:** Image may be too large for available RAM
- **Slow rendering:** SD card read speed may be limiting factor
