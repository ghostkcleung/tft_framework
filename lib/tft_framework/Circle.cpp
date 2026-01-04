/**
 * @file Circle.cpp
 * @brief Implementation of the Circle class using Midpoint Circle Algorithm.
 * 
 * Renders circles efficiently using the Bresenham-based midpoint algorithm,
 * which only uses integer arithmetic for speed.
 */

#include "tft_framework.h"

using namespace tft_framework;

uint16_t Circle::getRadius() const { return radius; }

void Circle::setRadius(uint16_t r) { radius = r; }

void Circle::draw(Screen* scr) {
	uint16_t r = getRadius();
	int16_t xc = getX(), yc = getY(), x = 0, y = r, d = 3 - 2 * r;

	Dot dot;
	dot.setColor(*this);

	dot.setPoint(xc + r, yc);
	dot.draw(scr);
	dot.setPoint(xc - r, yc);
	dot.draw(scr);
	dot.setPoint(xc, yc + r);
	dot.draw(scr);
	dot.setPoint(xc, yc - r);
	dot.draw(scr);

	while (y >= x++) {
		if (d > 0) {
			y--;
			d += 4 * (x - y) + 10;
		} else {
			d += 4 * x + 6;
		}

		dot.setPoint(xc + x, yc + y);
		dot.draw(scr);
		dot.setPoint(xc - x, yc + y);
		dot.draw(scr);
		dot.setPoint(xc + x, yc - y);
		dot.draw(scr);
		dot.setPoint(xc - x, yc - y);
		dot.draw(scr);
		dot.setPoint(xc + y, yc + x);
		dot.draw(scr);
		dot.setPoint(xc - y, yc + x);
		dot.draw(scr);
		dot.setPoint(xc + y, yc - x);
		dot.draw(scr);
		dot.setPoint(xc - y, yc - x);
		dot.draw(scr);
	}
}

void Circle::fill(Screen* scr) {
	uint16_t r = getRadius();

	if (!r) {
		return;
	}

	int16_t xc = getX(), yc = getY();
	int16_t x = 0, y = r;
	int16_t d = 3 - 2 * r;

	Line l;
	l.setColor(*this);

	auto drawSpan = [&](int16_t spanX, int16_t spanY) {
		l.setPoint(xc - spanX, yc + spanY);
		l.setEndPoint(xc + spanX, yc + spanY);
		l.draw(scr);
		if (spanY != 0) {
			l.setPoint(xc - spanX, yc - spanY);
			l.setEndPoint(xc + spanX, yc - spanY);
			l.draw(scr);
		}
	};

	while (y >= x) {
		drawSpan(x, y);
		if (x != y) {
			drawSpan(y, x);
		}

		x++;
		if (d > 0) {
			y--;
			d += 4 * (x - y) + 10;
		} else {
			d += 4 * x + 6;
		}
	}
}
