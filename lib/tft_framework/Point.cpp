/**
 * @file Point.cpp
 * @brief Implementation of the Point class for 2D coordinate management.
 */

#include "tft_framework.h"

using namespace tft_framework;

// Getter methods
int16_t Point::getX() const { return x; }

int16_t Point::getY() const { return y; }

// Setter methods
void Point::setX(int16_t x) { this->x = x; }

void Point::setY(int16_t y) { this->y = y; }

void Point::setPoint(int16_t x, int16_t y) {
	this->x = x;
	this->y = y;
}

void Point::setPoint(const Point& p) {
	x = p.x;
	y = p.y;
}

/**
 * @brief Move point using polar coordinates (direction and distance).
 * 
 * Calculates new position using trigonometry. Optimizes for cardinal
 * directions (0°, 90°, 180°, 270°) to avoid floating point calculations.
 * 
 * @param direction Angle in degrees (0-359), where 0° is North (up)
 * @param distance Distance to move in pixels
 */
void Point::move(double direction, double distance) {
	if (distance == 0) {
		return;
	}
	// Normalize direction to 0-359 range
	direction += 360;
	direction = fmod(direction, 360);

	// Optimize for cardinal directions
	if (direction == 0) {
		y -= distance;
		return;
	}
	if (direction == 180) {
		y += distance;
		return;
	}
	if (direction == 270) {
		x -= distance;
		return;
	}
	if (direction == 90) {
		x += distance;
		return;
	}

	// Calculate new position using trigonometry
	x = x + round(distance * sin(direction * M_PI / 180));
	y = y + round(-distance * cos(direction * M_PI / 180));
}

/**
 * @brief Offset the point by dx and dy.
 * 
 * @param dx Amount to offset in X direction
 * @param dy Amount to offset in Y direction
 */
void Point::offset(int16_t dx, int16_t dy) {
	x += dx;
	y += dy;
}

/**
 * @brief Offset the point in X direction only.
 * 
 * @param dx Amount to offset in X direction
 */
void Point::offsetX(int16_t dx) {
	x += dx;
}

/**
 * @brief Offset the point in Y direction only.
 * 
 * @param dy Amount to offset in Y direction
 */
void Point::offsetY(int16_t dy) {
	y += dy;
}

/**
 * @brief Calculate the midpoint between this point and another point.
 * 
 * @param p The other point
 * @return A new Point at the midpoint between the two points
 */
Point Point::midPoint(const Point& p) const {
	return Point((x + p.x) / 2, (y + p.y) / 2);
}