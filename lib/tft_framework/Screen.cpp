/**
 * @file Screen.cpp
 * @brief Implementation of the Screen base class for display management.
 * 
 * Provides core functionality for display initialization, text rendering,
 * shape drawing, and color management. Derived classes implement the
 * hardware-specific fillRect() method.
 */

#include "tft_framework.h"
using namespace tft_framework;

Screen::Screen(uint16_t w, uint16_t h) {
	this->w = w;
	this->h = h;
	rotate = 0;
	printBuffer = false;
	charLength = 0;
	ch = 0;
	f = new Font5X7();
	f->setColor(0xFFFF);
}

Screen::~Screen() { delete f; }

void Screen::init() {}

void Screen::setRotate(uint8_t rotate) {
	uint8_t r = this->rotate;

	this->rotate = rotate;

	r /= 2;
	r %= 2;
	rotate /= 2;
	rotate %= 2;

	if (r != rotate) {
		uint16_t tmp = w;
		w = h;
		h = tmp;
	}
}

uint8_t Screen::getRotate() { return rotate; }

uint16_t Screen::getWidth() { return w; }

uint16_t Screen::getHeight() { return h; }

void Screen::clear() {
	Rectangle r;
	r.setSize(w, h);
	r.setColor(*this);
	resetCursor();
	r.fill(this);
}

void Screen::setFont(Font* f) {
	f->setPoint(*this->f);
	this->f = f;
}

Font* Screen::getFont() { return f; }

Point Screen::getCursor() {
	Point p(*f);
	return p;
}

void Screen::setCursor(Point c) {
	cursor = c;
	f->setPoint(c);
}

void Screen::setCursor(int16_t x, int16_t y) {
	cursor.setPoint(x, y);
	f->setPoint(x, y);
}

bool Screen::isPrintBuffer() { return printBuffer; }

void Screen::setPrintBuffer(bool buf) { printBuffer = buf; }

size_t Screen::write(uint8_t data) {
	// ASCII (0xxxxxxx) - single byte character
	if ((data & 0x80) == 0x00) {
		f->setChar(data);
		f->write(this);
		return 1;
	}
	
	// Start of multi-byte UTF-8 sequence
	if ((data & 0xE0) == 0xC0) {
		// 110xxxxx - 2-byte sequence
		charLength = 1;
		ch = (data & 0x1F);
		return 1;
	} else if ((data & 0xF0) == 0xE0) {
		// 1110xxxx - 3-byte sequence
		charLength = 2;
		ch = (data & 0x0F);
		return 1;
	} else if ((data & 0xF8) == 0xF0) {
		// 11110xxx - 4-byte sequence
		charLength = 3;
		ch = (data & 0x07);
		return 1;
	}
	
	// Continuation byte (10xxxxxx)
	if ((data & 0xC0) == 0x80) {
		if (charLength > 0) {
			// Accumulate character code
			ch = (ch << 6) | (data & 0x3F);
			charLength--;
			
			// Complete character received
			if (charLength == 0) {
				f->setChar(ch);
				f->write(this);
				ch = 0;
				return 1;
			}
		}
		return 1;
	}
	
	// Invalid UTF-8 sequence - reset and ignore
	charLength = 0;
	ch = 0;
	return 0;
}

void Screen::resetCursor() { f->setPoint(cursor); }

void Screen::fillShape(BufferScreen* buf) { buf->fillGeneric(this); }

void Screen::drawShape(Dot* d) {
	Rectangle r;
	r.setPoint(*d);
	r.setEndPoint(*d);
	r.setColor(*d);
	fillRect(&r);
}

void Screen::fillShape(Bitmap* bmp) { bmp->fillGeneric(this); }