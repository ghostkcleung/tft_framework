#include "tft_framework.h"

using namespace tft_framework;

void tft_framework::
swap(int16_t &x, int16_t &y)
{
    int16_t tmp = x;
    x = y;
    y = tmp;
}

void tft_framework::
sortRect( Rectangle *r, Screen *scr ){
	    int16_t x1 = r -> getX(),
            y1 = r -> getY(),
            x2 = r -> getEndX(),
            y2 = r -> getEndY(),
            h = scr -> getHeight (),
            w = scr -> getWidth ();

    if(x1>x2)
    {
        swap(x1,x2);
    }

    if(y1>y2)
    {
        swap(y1,y2);
    }

    if ( x1 >= w )
    {
        return ;
    }
    if ( y1 >= h )
    {
        return ;
    }

    if ( x2 < 0 )
    {
        return ;
    }
    if ( y2 < 0 )
    {
        return ;
    }

    if ( x1 < 0 )
    {
        x1 = 0 ;
    }
    if ( y1 < 0 )
    {
        y1 = 0 ;
    }

    if ( x2 >= w )
    {
        x2 = w-1 ;
    }
    if ( y2 >= h )
    {
        y2 = h-1 ;
    }

    r -> setPoint(x1, y1);
    r -> setEndPoint(x2, y2);	
}