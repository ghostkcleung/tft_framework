#include "tft_framework.h"

using namespace tft_framework;

void tft_framework::swap_16(int16_t &x, int16_t &y)
{
	int16_t tmp = x;
	x = y;
	y = tmp;
}

bool tft_framework::sortRect(Rectangle *r, Rectangle rect)
{
	int16_t x1 = r->getX(),
			y1 = r->getY(),
			x2 = r->getEndX(),
			y2 = r->getEndY(),
			h = rect.getHeight(),
			w = rect.getWidth();

	if (x1 > x2)
	{
		swap_16(x1, x2);
	}
	if (y1 > y2)
	{
		swap_16(y1, y2);
	}
	if (x1 >= w)
	{
		return false;
	}
	if (y1 >= h)
	{
		return false;
	}
	if (x2 < 0)
	{
		return false;
	}
	if (y2 < 0)
	{
		return false;
	}

	if (x1 < 0)
	{
		x1 = 0;
	}
	if (y1 < 0)
	{
		y1 = 0;
	}
	if (x2 >= w)
	{
		x2 = w - 1;
	}
	if (y2 >= h)
	{
		y2 = h - 1;
	}

	r->setPoint(x1, y1);
	r->setEndPoint(x2, y2);
	return true;
}

bool tft_framework::sortRect(Rectangle *r, Screen *scr)
{
	Rectangle rect;
	rect.setSize(scr->getWidth(), scr->getHeight());
	return sortRect(r, rect);
}

bool tft_framework::sortRect(Rectangle *r, Image *img)
{
	Rectangle rect;
	rect.setSize(img->getWidth(), img->getHeight());
	return sortRect(r, rect);
}

uint32_t tft_framework::toUTF8(uint32_t unicode)
{
	uint32_t utf8;

	if (unicode < 0x80)
	{
		return unicode;
	}

	uint8_t arr[4];
	memcpy(arr, &unicode, 4);

	if (unicode < 0x800)
	{
		arr[1] <<= 2;
		arr[1] |= 0b11000000;
		arr[1] |= arr[0] >> 6;

		arr[0] &= 0b00111111;
		arr[0] |= 0b10000000;

		return *(uint32_t *)arr;
	}

	if (unicode < 0x10000)
	{
		arr[2] = 0b11100000;
		arr[2] |= arr[1]>>4;

		arr[1] <<= 2;
		arr[1] &= 0b00111100;
		arr[1] |= 0b10000000;
		arr[1] |= arr[0] >> 6;

		arr[0] &= 0b00111111 ;
		arr[0] |= 0b10000000 ;

		return *(uint32_t *)arr;
	}

	if (unicode < 0x200000 ) {
		arr[3] = 0b11110000;
		arr[3] |= arr[2] >> 2 ;

		arr[2] <<= 4;
		arr[2] &= 0b00110000;
		arr[2] |= 0b10000000;
		arr[2] |= arr[1] >> 4 ;

		arr[1] <<= 2 ;
		arr[1] &= 0b00111100 ;
		arr[1] |= 0b10000000 ;
		arr[1] |= arr[0] >> 6 ;

		arr[0] &= 0b00111111;
		arr[0] |= 0b10000000;

		return *(uint32_t *)arr;
	}


	uint8_t tmp;

	return 0;
}
