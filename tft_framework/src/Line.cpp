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
    scr -> drawImpl(this);
}