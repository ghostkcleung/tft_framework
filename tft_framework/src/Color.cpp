#include "tft_framework.h"
using namespace tft_framework;

uint16_t Color::getColor()
{
    return color;
}

void Color::setColor(uint16_t color)
{
    this->color = color;
}

void Color::setColor(Color c)
{
    color = c.color;
}

uint8_t Color::getR()
{
    uint8_t r = color >> 8;
    return r;
}

uint8_t Color::getG()
{
    uint8_t g = color >> 3;
    return g;
}

uint8_t Color::getB()
{
    uint8_t b = color << 3 ;
    return b ;
}

void Color::setR(uint8_t r){
    uint16_t r565 = r >> 3  ;
    r565 <<= 11;
    color &= 0x7FF;
    color |= r565;
}

void Color::setG(uint8_t g)
{
    uint16_t g565 = g >> 2 ;
    g565 <<= 5 ;
    color &= 0xF81F;
    color |= g565;
}

void Color::setB(uint8_t b)
{
    uint16_t b565 = b >> 3 ;
    color &= 0xFFE0;
    color |= b565;
}

uint32_t Color::getRGB()
{
    uint32_t rgb = (uint32_t)getR()<<16;
    rgb |= getG()<<8;
    rgb |= getB();
    return rgb;
}

void Color::setRGB(uint32_t rgb)
{
    uint8_t r = rgb >> 16 ;
    uint8_t g = rgb >> 8 ;
    uint8_t b = rgb ;

    setR(r);
    setG(g);
    setB(b);
}


Color::Color(uint8_t r,uint8_t g,uint8_t b){
	setR(r);
	setG(g);
	setB(b);
}