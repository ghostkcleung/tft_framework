#include "tft_framework.h"

using namespace tft_framework;

uint16_t Circle::getRadius(){
	return radius;
}

void Circle::setRadius ( uint16_t r ) {
	radius = r ;
}

void Circle::draw(Screen *scr) {
	scr -> drawImpl ( this );
}

void Circle::fill(Screen *scr) {
	scr -> fillImpl ( this ) ;
}