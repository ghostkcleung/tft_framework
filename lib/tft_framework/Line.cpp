/**
 * @file Line.cpp
 * @brief Implementation of the Line class using Bresenham's line algorithm.
 * 
 * Renders straight lines between two points by calculating and drawing
 * intermediate pixels using an efficient integer-only algorithm.
 */

#include "tft_framework.h"
using namespace tft_framework;

Line::Line(int16_t x0, int16_t y0, int16_t x1, int16_t y1) : Shape(), endPoint(x1, y1) {
	setPoint(x0, y0);
}

Line::Line(const Point& start, const Point& end) : Shape(), endPoint(end) {
	setPoint(start);
}

int16_t Line::getEndX() const { return endPoint.getX(); }

int16_t Line::getEndY() const { return endPoint.getY(); }

void Line::setEndX(int16_t x) { endPoint.setX(x); }

void Line::setEndY(int16_t y) { endPoint.setY(y); }

Point Line::getEndPoint() const { return endPoint; }

void Line::setEndPoint(const Point& p) { endPoint = p; }

void Line::setEndPoint(int16_t x, int16_t y) { endPoint.setPoint(x, y); }

void Line::move(double direction, double distance) {
	Point::move(direction, distance);
	Point endPoint = getEndPoint();
	endPoint.move(direction, distance);
	setEndPoint(endPoint);
}

void Line::lineTo(double direction, double distance) {
	Point p = *this;
	p.move(direction, distance);
	setEndPoint(p);
}

void Line::draw(Screen* scr) {
	int16_t x0 = getX(), y0 = getY(), x1 = getEndX(), y1 = getEndY();

	if ((x0 == x1) || (y0 == y1)) {
		Rectangle rect;
		rect.setPoint(*this);
		rect.setEndPoint(x1, y1);
		rect.setColor(*this);
		rect.fill(scr);
		return;
	}

	bool steep = abs(y1 - y0) > abs(x1 - x0);
	if (steep) {
		swap_16(x0, y0);
		swap_16(x1, y1);
	}

	if (x0 > x1) {
		swap_16(x0, x1);
		swap_16(y0, y1);
	}

	int16_t deltaX = x1 - x0;
	int16_t deltaY = abs(y1 - y0);
	int16_t error = deltaX / 2;

	uint16_t y = y0;

	uint16_t ystep = y0 < y1 ? 1 : -1;

	Dot d;
	d.setColor(*this);

	for (int16_t x = x0; x <= x1; x++) {
		if (steep) {
			d.setPoint(y, x);
		} else {
			d.setPoint(x, y);
		}
		d.draw(scr);
		error -= deltaY;

		if (error < 0) {
			y += ystep;
			error += deltaX;
		}
	}
}

void Line::moveTo(const Point& p) {
	int16_t _x = p.getX() - getX() + getEndX();
	int16_t _y = p.getY() - getY() + getEndY();

	setPoint(p);
	setEndPoint(_x, _y);
}

void Line::moveTo(int16_t x, int16_t y) { moveTo(Point(x, y)); }

void Line::moveToX(int16_t x) { moveTo(x, getY()); }

void Line::moveToY(int16_t y) { moveTo(getX(), y); }