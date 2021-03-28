#include "tft_framework.h"
using namespace tft_framework;


void Triangle::drawGeneric(Screen* scr)
{
	Line l;
    l.setColor(*this);
    l.setPoint(*this);
    l.setEndPoint (getP2());
    l.draw ( scr );
    l.setEndPoint (getP3());
    l.draw ( scr );
    l.setPoint(getP2());
    l.draw ( scr );
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

void Triangle::fillGeneric (Screen* scr)
{
    int16_t x0 = getX(), y0 = getY(),
            x1 = getP2().getX(), y1 = getP2().getY(),
            x2 = getP3().getX(), y2 = getP3().getY(),
            a, b, y, last;

    Line l;
    l.setColor (*this);

    if (y0 > y1)
    {
        swap(y0, y1);
        swap(x0, x1);
    }
    if (y1 > y2)
    {
        swap(y2, y1);
        swap(x2, x1);
    }
    if (y0 > y1)
    {
        swap(y0, y1);
        swap(x0, x1);
    }

    if (y0 == y2)
    {
        a = b = x0;
        if (x1 < a)
            a = x1;
        else if (x1 > b)
            b = x1;
        if (x2 < a)
            a = x2;
        else if (x2 > b)
            b = x2;

        l.setPoint (a, y0);
        l.lineTo ( 90,b - a + 1 ) ;
        l.draw(scr);
        return;
    }

    int16_t dx01 = x1 - x0, dy01 = y1 - y0, dx02 = x2 - x0, dy02 = y2 - y0,
            dx12 = x2 - x1, dy12 = y2 - y1;
    int32_t sa = 0, sb = 0;

    if (y1 == y2)
        last = y1;
    else
        last = y1 - 1;

    for (y = y0; y <= last; y++)
    {
        a = x0 + sa / dy01;
        b = x0 + sb / dy02;
        sa += dx01;
        sb += dx02;

        if (a > b)
            swap(a, b);
        l.setPoint (a, y);
        l.lineTo ( 90,b - a + 1 ) ;

        l.draw(scr);
    }

    sa = (int32_t)dx12 * (y - y1);
    sb = (int32_t)dx02 * (y - y0);
    for (; y <= y2; y++)
    {
        a = x1 + sa / dy12;
        b = x0 + sb / dy02;
        sa += dx12;
        sb += dx02;

        if (a > b)
            swap(a, b);

        l.setPoint (a, y);
        l.lineTo ( 90,b - a + 1 ) ;

        l.draw(scr);
    }
}