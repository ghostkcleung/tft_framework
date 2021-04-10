#include "tft_framework.h"
using namespace tft_framework;

int16_t Line::getEndX()
{
    return endPoint.getX();
}

int16_t Line::getEndY()
{
    return endPoint.getY();
}

void Line::setEndX(int16_t x)
{
    endPoint.setX(x);
}

void Line::setEndY(int16_t y)
{
    endPoint.setY(y);
}

Point Line::getEndPoint()
{
    return endPoint;
}

void Line::setEndPoint(Point p)
{
    endPoint = p ;
}

void Line::setEndPoint(int16_t x, int16_t y)
{
    endPoint.setPoint(x, y);
}

void Line::move(double direction, double distance)
{
    Point::move(direction, distance);
    Point endPoint=getEndPoint();
    endPoint.move(direction, distance);
    setEndPoint(endPoint);
}

void Line::lineTo(double direction, double distance)
{
    Point p = *this;
    p.move(direction, distance);
    setEndPoint(p);
}

void Line::draw(Screen* scr){
    int16_t x0 = getX()
		, y0 = getY()
		, x1 = getEndX()
		, y1 = getEndY();

    if ( ( x0==x1 )
            || ( y0==y1) )
    {
        Rectangle rect;
        rect.setPoint(*this);
        rect.setEndPoint(x1, y1);
        rect.setColor(*this);
		rect.fill(scr);
        return;
    }

    bool steep = abs( y1-y0 )
                 > abs( x1-x0 );
    if (steep)
    {
        swap(x0, y0);
        swap(x1, y1);
    }

    if (x0 > x1)
    {
        swap(x0, x1);
        swap(y0, y1);
    }

    int16_t deltaX = x1 - x0;
    int16_t deltaY = abs( y1-y0 );
    int16_t error = deltaX / 2;

    uint16_t y = y0;

    uint16_t ystep
        = y0 < y1 ? 1 :- 1;

    Dot d;
    d.setColor(*this);

    for (int16_t x = x0; x<=x1; x++)
    {
        if (steep)
        {
            d.setPoint(y, x);
        }
        else
        {
            d.setPoint(x, y);
        }
        d.draw ( scr ) ;
        error -= deltaY;

        if (error < 0)
        {
            y += ystep;
            error += deltaX;
        }
    }
}