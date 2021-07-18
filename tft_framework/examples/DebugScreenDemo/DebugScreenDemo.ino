#include <tft_framework.h>

using namespace tft_framework;

class DebugScreen:public Screen {
private:
Print *outStream;

public:
  DebugScreen(Print *outStream, int width, int height):Screen(width, height){
    this -> outStream = outStream;
  }

  void fillRect(Rectangle *r){
    outStream -> println ( "x1: " + String ( r -> getX() )
      + ", y1: " + String ( r -> getY() )
      + ", x2: " + String ( r -> getEndX() )
      + ", y2: " + String ( r -> getEndY() )
      + ", color: " + String ( r -> getR(), HEX )
      + String ( r -> getG(), HEX ) + String ( r -> getB(), HEX ) );
  }
};

Screen *scr;

void setup(){
  Serial.begin ( 115200 );
  scr = new DebugScreen ( &Serial, 480, 320 ) ;
  scr -> print ( "Hello world !" );
}

void loop(){
  delay(10000);
}
