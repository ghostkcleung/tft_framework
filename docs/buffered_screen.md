# Buffer Screen

A `BufferScreen` is a virtual screen that stores drawing operations in memory before transferring them to the physical display. This can improve rendering efficiency for complex graphics.

## Memory Considerations

Buffer screens require 2 bytes per pixel:

**Example:** A 60×60 buffer = 60 × 60 × 2 = 7,200 bytes

**Arduino Mega 2560:** Has 8KB RAM, so a 60×60 buffer is near the maximum safe size.

**ESP32:** Has significantly more RAM and can handle larger buffers.

**Important:** Always deallocate buffers when done to free memory!

## Constructor

```cpp
BufferScreen* buf = new BufferScreen(width, height);
```

## Methods

BufferScreen inherits all Screen methods, including:

```cpp
// Drawing operations
void clear();
void fillRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color);

// Background color
void setRGB(uint32_t rgb);
void setColor(uint16_t color);

// Positioning
void setPoint(int16_t x, int16_t y);

// Scaling
void setScale(uint8_t scale);

// Transfer to physical screen
void fill(Screen* scr);
```

## Basic Example

```cpp
Screen* scr;
// Initialize your screen...

// Create 40×40 buffer
BufferScreen* buf = new BufferScreen(40, 40);
buf->setRGB(0xFFFF00);  // Yellow background
buf->clear();

// Draw to buffer
Triangle t;
t.setPoint(20, 30);
t.setP2(10, 5);
t.setP3(30, 5);
t.setRGB(0xFF0000);
t.fill(buf);

// Transfer buffer to screen at (50, 50)
buf->setPoint(50, 50);
buf->fill(scr);

// Clean up
delete buf;
```

## Complete Example: Scaled Triangle

```cpp
Screen* scr;

void setup() {
    // Initialize your screen...
    
    scr->clear();

    // Create buffer
    BufferScreen* buf = new BufferScreen(40, 40);
    buf->setRGB(0xFFFF00);  // Yellow background
    buf->clear();

    // Draw triangle in buffer
    Triangle t;
    t.setPoint(4, 34);
    t.setP2(19, 4);
    t.setP3(34, 34);
    t.draw(buf);

    // Draw at normal size
    buf->setPoint(20, 20);
    buf->fill(scr);

    // Draw at 3x size
    buf->setScale(3);
    buf->setPoint(20, 100);
    buf->fill(scr);

    // Clean up
    delete buf;
}
```

### Output

<img src="buffer.jpg" width="480" />

## Use Cases

### 1. Animation
Pre-render frames in a buffer, then quickly transfer to screen.

### 2. Complex Graphics
Build complex scenes in memory before displaying.

### 3. Flicker Reduction
Render complete images before showing them, preventing partial updates.

### 4. Scaling
Render once at small size, then scale up for display.

## Best Practices

1. **Calculate memory usage** before creating large buffers
2. **Always delete** buffers when finished: `delete buf;`
3. **Reuse buffers** when possible instead of creating new ones
4. **Clear buffers** before drawing new content: `buf->clear();`
5. **Consider ESP32** for applications requiring large buffers
