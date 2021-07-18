#include "tft_framework.h"

using namespace tft_framework;

void tft_framework::swap_16(int16_t &x, int16_t &y) {
    int16_t tmp = x;
    x = y;
    y = tmp;
}

bool tft_framework::sortRect ( Rectangle *r, Rectangle rect ) {
	int16_t x1 = r -> getX(),
		y1 = r -> getY(),
		x2 = r -> getEndX(),
		y2 = r -> getEndY(),
		h = rect.getHeight (),
		w = rect.getWidth ();

    if(x1>x2) { swap_16(x1,x2); }
    if(y1>y2) { swap_16(y1,y2); }
    if ( x1 >= w ) { return false ; }
    if ( y1 >= h ) { return false ; }
    if ( x2 < 0 ) { return false ; }
    if ( y2 < 0 ) { return false ; }

	if ( x1 < 0 ) { x1 = 0 ; }
	if ( y1 < 0 ) { y1 = 0 ; }
	if ( x2 >= w ) { x2 = w-1 ; }
	if ( y2 >= h ) { y2 = h-1 ; }

    r -> setPoint(x1, y1);
    r -> setEndPoint(x2, y2);
	return true ;
}

bool tft_framework::sortRect( Rectangle *r, Screen *scr ){
	Rectangle rect ;
	rect.setSize ( scr -> getWidth(), scr->getHeight());
	return sortRect ( r, rect ) ;
}

bool tft_framework::sortRect( Rectangle *r, Image *img ){
	Rectangle rect ;
	rect.setSize ( img -> getWidth(), img -> getHeight() );
	return sortRect ( r, rect ) ;
}