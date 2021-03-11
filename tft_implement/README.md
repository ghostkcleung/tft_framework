# Implement your screen

You may implement your screen by inherit the "Screen" class. 

Just let the screen know how to "drawRect()".

```cpp
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
