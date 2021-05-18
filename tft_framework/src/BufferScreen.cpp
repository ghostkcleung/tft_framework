#include "tft_framework.h"
using namespace tft_framework;

BufferScreen::BufferScreen
(uint16_t w, uint16_t h)
    : Screen (w,h),scale(1)
{
    data = new uint16_t[w*h];
};

void BufferScreen::init()
{
    clear();
}

uint8_t BufferScreen::getScale()
{
    return scale;
}

void BufferScreen::setScale(uint8_t s)
{
    scale = s;
}

BufferScreen::~BufferScreen()
{
    delete [] data;
}

uint16_t* BufferScreen::getData()
{
    return data;
}


void BufferScreen::fillRect(Rectangle* rect)
{

    int16_t x0 = rect -> getX()
                 , y0 = rect -> getY()
                 , w = getWidth()
                 , x1 = rect -> getEndX()
                 , y1 = rect -> getEndY();

    uint16_t color = rect -> getColor();

    for(int16_t y=y0; y<=y1; y++)
    {
        for(int16_t x=x0; x<=x1; x++)
        {
            data[y*w+x]=color;
        }
    }
}

void BufferScreen::fillGeneric(Screen* scr)
{
    uint8_t scale = getScale();

    if ( ! scale )
    {
        return ;
    }

    uint16_t w = getWidth (),
             h = getHeight(),
             x = getX(),
             y = getY();

    uint16_t *data = getData(), *col;

    Dot d;
    for ( uint16_t _y = 0; _y<h; _y++ )
    {
        for ( uint8_t sy = 0 ; sy < scale ; sy++ )
        {
            col = data ;
            for ( uint16_t _x = 0 ; _x < w; _x++ )
            {
                for (uint8_t sx = 0; sx < scale; sx ++ )
                {
                    d.setPoint (_x*scale+sx+x,_y*scale+sy+y);
                    d.setColor(*col);
                    d.draw ( scr ) ;
                }
                col++;
            }
        }
        data += w;
    }
}

void BufferScreen::fill(Screen* scr)
{
	scr -> fillShape ( this ) ;
}

void BufferScreen::drawShape(Dot *d){
	uint16_t x = d -> getX(),
		y = d -> getY(),
		w = getWidth(),
		c = d -> getColor ();

		data[y*w+x]=c;
}