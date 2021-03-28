#include "tft_framework.h"

using namespace tft_framework;

uint16_t Circle::getRadius(){
	return radius;
}

void Circle::setRadius ( uint16_t r ) {
	radius = r ;
}

void Circle::drawGeneric(Screen *scr) {
	uint16_t r = getRadius ( ) ;
	int16_t xc = getX ( ), yc = getY ( )
		, x = 0, y = r, d = 3-2*r;

	Dot dot;
	dot.setColor ( *this ) ;

	dot.setPoint(xc+r, yc); dot.draw(scr);
	dot.setPoint(xc-r, yc); dot.draw(scr);
	dot.setPoint(xc, yc+r); dot.draw(scr);
	dot.setPoint(xc, yc-r); dot.draw(scr);

	while (y >= x++) 
	{
		if (d > 0) 
        { 
            y--;  
            d += 4 * (x - y) + 10; 
        } 
        else
		{
			d += 4 * x + 6;
		}

		dot.setPoint(xc+x, yc+y); dot.draw(scr); 
		dot.setPoint(xc-x, yc+y); dot.draw(scr); 
		dot.setPoint(xc+x, yc-y); dot.draw(scr);
		dot.setPoint(xc-x, yc-y); dot.draw(scr);
		dot.setPoint(xc+y, yc+x); dot.draw(scr);
		dot.setPoint(xc-y, yc+x); dot.draw(scr);
		dot.setPoint(xc+y, yc-x); dot.draw(scr);
		dot.setPoint(xc-y, yc-x); dot.draw(scr);
	}
}

void Circle::fillGeneric(Screen *scr) {
    uint16_t r = getRadius();

    if ( ! r )
    {
        return ;
    }

    if ( r == 1 )
    {
        Dot d ;
        d.setPoint(*this);
        d.draw(scr);
        return ;
    }

	int x = getX ( )
		, y = getY ( )
		, _y = 0;

	uint32_t sqr = r;
	sqr *= r ;

	Line l;
	l.setColor ( *this );
	l.setPoint ( *this ) ;
	l.move ( 270 , r-1 );
	l.lineTo ( 90 , r+r-2 );
	l.draw(scr);

	while ( _y ++ < r - 1 ) {
		uint32_t sqrY = _y;
		sqrY *= _y ;
		
		uint32_t _x = sqr ;
		_x -= sqrY ;
		_x = sqrt ( _x ) ;
		
		l.setPoint ( -_x + x , _y + y );
		l.setEndPoint ( _x + x, _y + y );
		l.draw(scr);
        l.setY(y-_y);
        l.setEndY(y-_y);
        l.draw(scr);
	}
}