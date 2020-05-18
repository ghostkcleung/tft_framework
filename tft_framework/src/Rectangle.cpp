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

void Rectangle::draw(Screen* scr)
{
    scr->drawImpl(this);
}

void Rectangle::fill(Screen* scr)
{
    scr->fillImpl(this);
}
