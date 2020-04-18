#include "tft_framework.h"
using namespace tft_framework;


void Triangle::draw(Screen* scr)
{
    scr->drawImpl(this);
}

Point Triangle::getP2(){
	return p2;
}

Point Triangle::getP3(){
	return p3;
}

void Triangle::setP2 ( Point p2 ) {
	this -> p2 = p2;
}

void Triangle::setP2 ( int16_t x, int16_t y ) {
	this -> p2.setPoint ( x, y );
}

void Triangle::setP3 ( Point p3 ) {
	this -> p3 = p3 ;
}

void Triangle::setP3 ( int16_t x, int16_t y ) {
	this -> p3.setPoint ( x, y );
}

void Triangle::move ( double direction, double distance ){
	Point::move(direction, distance);
	p2.move(direction, distance);
	p3.move(direction, distance);
}

void Triangle::fill (Screen* scr)
{
    scr->fillImpl(this);
}