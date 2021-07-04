#include "tft_framework.h"
using namespace tft_framework;

BufferScreen::BufferScreen(uint16_t w, uint16_t h)
    : Screen (w,h),scale(1), w(w), h(h) {
    data = new uint16_t[w*h];
};

void BufferScreen::init() {
    clear();
}

uint8_t BufferScreen::getScale() {
    return scale;
}

void BufferScreen::setScale(uint8_t s) {
    scale = s;
}

BufferScreen::~BufferScreen() {
    delete [] data;
}

uint16_t* BufferScreen::getData() {
    return data;
}


void BufferScreen::fillRect(Rectangle* rect) {

    int16_t x0 = rect -> getX()
                 , y0 = rect -> getY()
                 , x1 = rect -> getEndX()
                 , y1 = rect -> getEndY();

    uint16_t color = rect -> getColor();

	uint8_t r = getRotate ( ) ;

    for(int16_t y=y0; y<=y1; y++) {
		for(int16_t x=x0; x<=x1; x++) {
			switch ( r ) {
			case 0:
				data[y*w+x]=color;
				break;
			case 1:
				data[(y+1)*w-x-1]=color;
				break;
			case 2:
				data[(x+1)*w-y-1]=color;
				break;
			case 3:
				data[(h-x)*w-y-1]=color;
				break;
			case 4:
				data[(h-y)*w-x-1]=color;
				break;
			case 5:
				data[(h-y-1)*w+x]=color;
				break;
			case 6:
				data[(h-1-x)*w+y]=color;
				break;
			case 7:
				data[x*w+y]=color;
				break;
			}
		}
	}
}

void BufferScreen::fillGeneric(Screen* scr) {

    uint8_t scale = getScale();

    if ( ! scale ) {
		return ;
	}

    uint16_t x0 = getX(),
			y0 = getY(),
			_w = w * scale,
			_h = h * scale;

    uint16_t *data = getData();

	Rectangle rect ;

	for ( uint16_t y = 0 ; y < _h ; y += scale ) {
		for ( uint16_t x = 0 ; x < _w ; x += scale ) {
			rect.setPoint ( x + x0, y + y0 );
			rect.setSize ( scale, scale );
			rect.setColor ( *data ++ ) ;
			rect.fill ( scr ) ;
		}
	}
}

void BufferScreen::fill(Screen* scr)
{
	scr -> fillShape ( this ) ;
}

void BufferScreen::drawShape(Dot *d){
	uint16_t x = d -> getX(),
		y = d -> getY(),
		w = getWidth(),
		c = d -> getColor ();

		data[y*w+x]=c;
}