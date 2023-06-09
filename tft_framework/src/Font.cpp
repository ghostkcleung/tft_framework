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
	return (w + paddingLeft + paddingRight + spacingLeft + spacingRight) * scale;
}

uint8_t Font::getTotalHeight()
{
	return (h + paddingTop + paddingBottom + spacingTop + spacingBottom) * scale;
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

void Font::setSpacingTop(uint8_t spacingTop)
{
	this->spacingTop = spacingTop;
}

void Font::setSpacingLeft(uint8_t spacingLeft)
{
	this->spacingLeft = spacingLeft;
}

void Font::setSpacingBottom(uint8_t spacingBottom)
{
	this->spacingBottom = spacingBottom;
}

void Font::setSpacingRight(uint8_t spacingRight)
{
	this->spacingRight = spacingRight;
}

uint8_t Font::getSpacingTop()
{
	return spacingTop;
}

uint8_t Font::getSpacingLeft()
{
	return spacingLeft;
}

uint8_t Font::getSpacingBottom()
{
	return spacingBottom;
}

uint8_t Font::getSpacingRight()
{
	return spacingRight;
}

void Font::write(Screen *scr)
{
	uint32_t ch = getChar();
	Point p = *this;

	if (ch == '\r')
	{
		return;
	}

	if (ch == '\n')
	{
		scr->resetCursor();
		setY(p.getY());
		move(180, getTotalHeight());
		return;
	}

	if (getX() + getTotalWidth() >= scr->getWidth())
	{
		scr->resetCursor();
		setY(p.getY());
		move(180, getTotalHeight());
	}

	p = *this;
	uint8_t scale = getScale();

	uint8_t paddT = getPaddingTop(), paddL = getPaddingLeft();

	if (scr->isPrintBuffer())
	{
		uint16_t bufWidth = getWidth() + paddL + getPaddingRight(),
				 bufHeight = getHeight() + paddT + getPaddingBottom();

		if (bufWidth != 0 && bufHeight != 0)
		{
			BufferScreen *bScr = new BufferScreen(getWidth() + paddL + getPaddingRight(), getHeight() + paddT + getPaddingBottom());

			bScr->setColor(*scr);
			bScr->clear();

			bScr->setPoint(p);

			bScr->move(90, getSpacingLeft() * scale);
			bScr->move(180, getSpacingTop() * scale);

			bScr->setScale(scale);
			setScale(1);

			setPoint(paddL, paddT);
			draw(bScr);
			bScr->fill(scr);

			delete bScr;
			setScale(scale);
		}
	}
	else
	{
		move(90, paddL + getSpacingLeft() * scale);
		move(180, paddT + getSpacingTop() * scale);

		draw(scr);
	}

	p.move(90, getTotalWidth());
	setPoint(p);
}

Font::~Font()
{
}