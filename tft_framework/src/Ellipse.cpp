#include "tft_framework.h"

using namespace tft_framework;

uint16_t Ellipse::getRx(){
	return rx;
}

uint16_t Ellipse::getRy(){
	return ry;
}

void Ellipse::setRx ( uint16_t rx ) {
	this -> rx = rx ;
}

void Ellipse::setRy ( uint16_t ry ) {
	this -> ry = ry ;
}

void Ellipse::draw(Screen *scr) {
	scr -> drawImpl ( this );
}

void Ellipse::fill(Screen *scr) {
	scr -> fillImpl ( this ) ;
}