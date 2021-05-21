#ifndef FONT5X7_H
#define FONT5X7_H

class Font5X7:public Font {

public:
	Font5X7():Font(5,7){};
	void draw ( Screen* scr ) ;
	
private:

static const uint8_t Matrix[] PROGMEM ;
};



#endif