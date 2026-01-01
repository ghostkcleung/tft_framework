/**
 * @file Dot.cpp
 * @brief Implementation of the Dot class for single pixel rendering.
 * 
 * A Dot represents a single pixel on the screen, implemented as
 * a 1x1 rectangle for simplicity and consistency.
 */

#include "tft_framework.h"
using namespace tft_framework;

void Dot::draw(Screen* scr) {
	if (getX() < 0 || getY() < 0 || getX() >= scr->getWidth() ||
		getY() >= scr->getHeight()) {
		return;
	}
	scr->drawShape(this);
}
