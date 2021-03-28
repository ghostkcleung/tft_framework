#include "tft_framework.h"
using namespace tft_framework;

int16_t Rectangle::getHeight()
{
    int16_t h = getEndY() - getY() ;
    if ( h < 0 )
    {
        h -- ;
    }
    else
    {
        h ++ ;
    }
    return h ;
}

int16_t Rectangle::getWidth()
{
    int16_t w = getEndX() - getX() ;
    if ( w < 0 )
    {
        w -- ;
    }
    else
    {
        w ++ ;
    }
    return w ;
}

void Rectangle::setHeight(int16_t h)
{
    if ( ! h )
    {
        return ;
    }
    if ( h < 0 )
    {
        h ++ ;
    }
    else
    {
        h -- ;
    }
    setEndY ( getY()+h );
}

void Rectangle::setWidth(int16_t w)
{
    if ( ! w )
    {
        return ;
    }
    if ( w < 0 )
    {
        w ++ ;
    }
    else
    {
        w -- ;
    }
    setEndX ( getX()+w );
}

void Rectangle::setSize(int16_t w, int16_t h)
{
    setWidth(w);
    setHeight(h);
}

void Rectangle::drawGeneric(Screen* scr)
{
	Rectangle viewPortRect ;
	viewPortRect.setPoint (*this);
	viewPortRect.setEndPoint (getEndPoint());
	viewPortRect.setColor (*this);
	
	sortRect(&viewPortRect, scr);

    Rectangle tmp;
    tmp.setColor(viewPortRect);
    tmp.setPoint(viewPortRect);
    tmp.setEndPoint(viewPortRect.getEndPoint());
    tmp.setHeight(1);
    tmp.fill ( scr ) ;

    tmp.move(180,viewPortRect.getHeight()-1);
    tmp.fill ( scr ) ;

    tmp.setY(viewPortRect.getY()+1);
    tmp.setWidth(1);
    tmp.setHeight(viewPortRect.getHeight()-2);
    tmp.fill ( scr ) ;

    tmp.move(90,viewPortRect.getWidth()-1);
    tmp.fill ( scr ) ;
	
	Serial.print ( "x1:" + String ( viewPortRect.getX ( ) ) ) ;
	Serial.print ( ", y1:" + String ( viewPortRect.getY ( ) ) ) ;
	Serial.print ( ", x2:" + String ( viewPortRect.getEndX ( ) ) ) ;
	Serial.println ( ", Y2:" + String ( viewPortRect.getEndY ( ) ) ) ;
}

void Rectangle::fillGeneric(Screen* scr)
{
	Rectangle tmp;
	tmp.setPoint(*this);
	tmp.setColor(*this);
	tmp.setEndPoint(getEndPoint());
	sortRect(&tmp,scr);

	int x0 = tmp.getX ( )
		, y0 = tmp.getY ( )
		, x1 = tmp.getEndX ( )
		, y1 = tmp.getEndY ( )
		, maxX = scr -> getWidth ( ) - 1
		, maxY = scr -> getHeight ( ) - 1 ;

	if ( x0 > maxX ) { return ; }
	if ( y0 > maxY ) { return ; }
	if ( x1 < 0 ) { return ; }
	if ( y1 < 0 ) { return ; }

	x0 = x0 < 0 ? 0 : x0;
	y0 = y0 < 0 ? 0 : y0;
	x1 = x1 > maxX ? maxX : x1;
	y1 = y1 > maxY ? maxY : y1;

    scr -> fillRect( &tmp );
}