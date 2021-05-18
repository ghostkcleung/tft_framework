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
	int16_t cx = getX ( ),
		cy = getY ( ),
		rx = getRx ( ),
		ry = getRy ( );

	if ( ! rx ) { return ; }
	if ( ! ry ) { return ; }

	int32_t x, y,
		xChange, yChange,
		error, aSqr, bSqr, sx, sy, cond;
		
	aSqr = (int32_t)2 * rx * rx ;
	bSqr = (int32_t)2 * ry * ry ;

	x = rx ;
	y = 0 ;

	xChange = 1 - 2*rx ; xChange *= ry; xChange *= ry;
	yChange = (int32_t) rx * rx ;
	error = 0;
	sx = (int32_t)bSqr * rx ;
	sy = 0;

	Dot d;
	d.setColor ( *this );

	while ( sx >= sy ) {
		d.setPoint ( cx+x, cy+y ); d.draw ( scr ) ;
		d.setPoint ( cx-x, cy+y ); d.draw ( scr ) ;
		d.setPoint ( cx-x, cy-y ); d.draw ( scr ) ;
		d.setPoint ( cx+x, cy-y ); d.draw ( scr ) ;
		
		y++ ;
		sy += aSqr ;
		error += yChange ;
		yChange += aSqr ;

		cond = error; cond *= 2; cond += xChange;
		if ( cond > 0 ) {
			x --;
			sx -= bSqr ;
			error += xChange ;
			xChange += bSqr ;
		}
	}
	
	x = 0;
	y = ry;
	xChange = (int32_t)ry * ry;
	yChange = 1 - 2*ry ; yChange *= rx; yChange *= rx;
	error = 0;
	sx = 0;
	sy = (int32_t)aSqr * ry ;

	while ( sx <= sy ) {
		d.setPoint ( cx+x, cy+y ); d.draw ( scr ) ;
		d.setPoint ( cx-x, cy+y ); d.draw ( scr ) ;
		d.setPoint ( cx-x, cy-y ); d.draw ( scr ) ;
		d.setPoint ( cx+x, cy-y ); d.draw ( scr ) ;
		
		x++;
		sx += bSqr;
		error += xChange;
		xChange += bSqr;
		
		cond = error; cond *= 2; cond += yChange;
		if ( cond > 0 ) {
			y --;
			sy -= aSqr ;
			error += yChange ;
			yChange += aSqr ;
		}
	}
}

void Ellipse::fill(Screen *scr) {
	int16_t cx = getX ( ),
		cy = getY ( ),
		rx = getRx ( ),
		ry = getRy ( );

	if ( ! rx ) { return ; }
	if ( ! ry ) { return ; }

	int32_t x, y,
		xChange, yChange,
		error, aSqr, bSqr, sx, sy, cond;
		
	aSqr = (int32_t)2 * rx * rx ;
	bSqr = (int32_t)2 * ry * ry ;

	x = rx ;
	y = 0 ;

	xChange = 1 - 2*rx ; xChange *= ry; xChange *= ry;
	yChange = (int32_t) rx * rx ;
	error = 0;
	sx = (int32_t)bSqr * rx ;
	sy = 0;

	Line l;
	l.setColor ( *this );

	while ( sx >= sy ) {
		l.setPoint ( cx+x, cy+y );
		l.setEndPoint ( cx-x, cy+y );
		l.draw(scr);

		l.setPoint ( cx-x, cy-y );
		l.setEndPoint ( cx+x, cy-y );
		l.draw(scr);
		
		y++ ;
		sy += aSqr ;
		error += yChange ;
		yChange += aSqr ;

		cond = error; cond *= 2; cond += xChange;
		if ( cond > 0 ) {
			x --;
			sx -= bSqr ;
			error += xChange ;
			xChange += bSqr ;
		}
	}
	
	x = 0;
	y = ry;
	xChange = (int32_t)ry * ry;
	yChange = 1 - 2*ry ; yChange *= rx; yChange *= rx;
	error = 0;
	sx = 0;
	sy = (int32_t)aSqr * ry ;

	while ( sx <= sy ) {
		l.setPoint ( cx+x, cy+y );
		l.setEndPoint ( cx-x, cy+y );
		l.draw(scr);

		l.setPoint ( cx-x, cy-y );
		l.setEndPoint ( cx+x, cy-y );
		l.draw(scr);
		
		x++;
		sx += bSqr;
		error += xChange;
		xChange += bSqr;
		
		cond = error; cond *= 2; cond += yChange;
		if ( cond > 0 ) {
			y --;
			sy -= aSqr ;
			error += yChange ;
			yChange += aSqr ;
		}
	}
}