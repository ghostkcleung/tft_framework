# Implement your screen

You may implement your own screen by inherit the "Screen" class. 

Just tell it the resolution and let it know how to "fillRect()".

There is an example
https://github.com/ghostkcleung/tft_framework/blob/master/tft_framework/examples/DebugScreenDemo/DebugScreenDemo.ino

```cpp
#include <tft_framework>

using namespace tft_framework;

class CustomScreen : public Screen {
public:
  CustomScreen(int w, int h):Screen(w, h){
    // your constructor here.
  }

  void fillRect(Rectangle *r){
    // Tell it how to fill the rectangle.
  }
};
```
