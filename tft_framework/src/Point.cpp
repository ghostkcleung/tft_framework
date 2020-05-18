#include "tft_framework.h"

using namespace tft_framework;

int16_t Point::getX()
{
    return x;
}

int16_t Point::getY()
{
    return y;
}

void Point::setX(int16_t x)
{
    this->x = x ;
}

void Point::setY(int16_t y)
{
    this->y = y ;
}

void Point::setPoint(int16_t x, int16_t y)
{
    this->x = x ;
    this->y = y ;
}

void Point::setPoint(Point p)
{
    x = p.x;
    y = p.y;
}

void Point::move(double direction, double distance)
{
    if ( distance == 0 )
    {
        return ;
    }
    direction += 360 ;
    direction = fmod (direction, 360) ;

    if ( direction == 0 )
    {
        y -= distance ;
        return ;
    }
    if ( direction == 180 )
    {
        y += distance ;
        return ;
    }
    if ( direction == 270 )
    {
        x -= distance ;
        return ;
    }
    if ( direction == 90 )
    {
        x += distance ;
        return ;
    }

    x = x + round ( distance * sin( direction * M_PI / 180 ) ) ;
    y = y + round ( -distance * cos( direction * M_PI / 180 ) ) ;
}


bool Point::equals ( Point p ) {
	return ( x == p.x && y == p.y ) ;
}

bool Point::equals ( Point p[], uint16_t count ) {
	for ( int i = 0 ; i < count ; i ++ ) {
		if ( ! equals(p[i] )){
			return false ;
		}
	}
	return true ;
}