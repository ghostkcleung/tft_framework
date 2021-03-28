# Implementation of custom shape

You may create your custom shape by inherit the Shape class. And Implement the drawGeneric() method. You may also inherit the Fillable class and implement the fillGeneric() method if you want to fill color into it.

For example:
```cpp
class MyShape: public Shape, public Fillable {
  public:
  void drawGeneric ( Screen *scr ) {
     // ...
  }
  
  void fillGeneric ( Screen *scr ) {
     // ...
  }
};
```

Demo: https://github.com/ghostkcleung/tft_framework/blob/master/tft_implement/examples/CustomShape/CustomShape.ino
