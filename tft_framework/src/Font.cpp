#include "tft_framework.h"
using namespace tft_framework;

uint8_t Font::getWidth()
{
	return w;
}

uint8_t Font::getHeight()
{
	return h;
}

uint8_t Font::getTotalWidth()
{
	return (w + paddingLeft + paddingRight + marginLeft + marginRight) * scale;
}

uint8_t Font::getTotalHeight()
{
	return (h + paddingTop + paddingBottom + marginTop + marginBottom) * scale;
}

uint32_t Font::getChar()
{
	return c;
}

void Font::setChar(uint32_t c)
{
	this->c = c;
}

uint8_t Font::getScale()
{
	return scale;
}

void Font::setScale(uint8_t s)
{
	scale = s;
}

void Font::setPaddingTop(uint8_t paddingTop)
{
	this->paddingTop = paddingTop;
}

void Font::setPaddingLeft(uint8_t paddingLeft)
{
	this->paddingLeft = paddingLeft;
}

void Font::setPaddingBottom(uint8_t paddingBottom)
{
	this->paddingBottom = paddingBottom;
}

void Font::setPaddingRight(uint8_t paddingRight)
{
	this->paddingRight = paddingRight;
}

uint8_t Font::getPaddingTop()
{
	return paddingTop;
}

uint8_t Font::getPaddingLeft()
{
	return paddingLeft;
}

uint8_t Font::getPaddingBottom()
{
	return paddingBottom;
}

uint8_t Font::getPaddingRight()
{
	return paddingRight;
}

void Font::setMarginTop(uint8_t marginTop)
{
	this->marginTop = marginTop;
}

void Font::setMarginLeft(uint8_t marginLeft)
{
	this->marginLeft = marginLeft;
}

void Font::setMarginBottom(uint8_t marginBottom)
{
	this->marginBottom = marginBottom;
}

void Font::setMarginRight(uint8_t marginRight)
{
	this->marginRight = marginRight;
}

uint8_t Font::getMarginTop()
{
	return marginTop;
}

uint8_t Font::getMarginLeft()
{
	return marginLeft;
}

uint8_t Font::getMarginBottom()
{
	return marginBottom;
}

uint8_t Font::getMarginRight()
{
	return marginRight;
}

Font::~Font()
{
}