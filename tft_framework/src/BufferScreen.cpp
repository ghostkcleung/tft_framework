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

void BufferScreen::
fillRect(Rectangle* rect)
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

void BufferScreen::fill(Screen* scr)
{
    scr -> fillImpl (this);
}
