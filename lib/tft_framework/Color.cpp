/**
 * @file Color.cpp
 * @brief Implementation of the Color class for RGB565 color management.
 * 
 * Handles conversion between 24-bit RGB (8 bits per channel) and
 * 16-bit RGB565 format (5-6-5 bits per channel).
 */

#include "tft_framework.h"
using namespace tft_framework;

// Basic getter/setter for 16-bit color value
uint16_t Color::getColor() { return color; }

void Color::setColor(uint16_t color) { this->color = color; }

void Color::setColor(Color c) { color = c.color; }

/**
 * @brief Extract red component from RGB565 format.
 * Converts 5-bit red to 8-bit by left-shifting and filling lower bits.
 */
uint8_t Color::getR() {
	uint8_t r = color >> 8;  // Extract top 5 bits (bits 11-15)
	return r;
}

/**
 * @brief Extract green component from RGB565 format.
 * Converts 6-bit green to 8-bit by shifting and filling lower bits.
 */
uint8_t Color::getG() {
	uint8_t g = color >> 3;  // Extract middle 6 bits (bits 5-10)
	return g;
}

/**
 * @brief Extract blue component from RGB565 format.
 * Converts 5-bit blue to 8-bit by left-shifting and filling lower bits.
 */
uint8_t Color::getB() {
	uint8_t b = color << 3;  // Extract bottom 5 bits (bits 0-4)
	return b;
}

/**
 * @brief Set red component in RGB565 format.
 * Converts 8-bit red to 5-bit by right-shifting (loses 3 LSBs).
 */
void Color::setR(uint8_t r) {
	uint16_t r565 = r >> 3;      // Convert 8-bit to 5-bit
	r565 <<= 11;                 // Shift to bits 11-15
	color &= 0x7FF;              // Clear existing red bits
	color |= r565;               // Set new red value
}

/**
 * @brief Set green component in RGB565 format.
 * Converts 8-bit green to 6-bit by right-shifting (loses 2 LSBs).
 */
void Color::setG(uint8_t g) {
	uint16_t g565 = g >> 2;      // Convert 8-bit to 6-bit
	g565 <<= 5;                  // Shift to bits 5-10
	color &= 0xF81F;             // Clear existing green bits
	color |= g565;               // Set new green value
}

/**
 * @brief Set blue component in RGB565 format.
 * Converts 8-bit blue to 5-bit by right-shifting (loses 3 LSBs).
 */
void Color::setB(uint8_t b) {
	uint16_t b565 = b >> 3;      // Convert 8-bit to 5-bit
	color &= 0xFFE0;             // Clear existing blue bits
	color |= b565;               // Set new blue value
}

/**
 * @brief Get color as 24-bit RGB value.
 * Converts RGB565 to RGB888 format (0x00RRGGBB).
 */
uint32_t Color::getRGB() {
	uint32_t rgb = (uint32_t)getR() << 16;
	rgb |= getG() << 8;
	rgb |= getB();
	return rgb;
}

/**
 * @brief Set color from 24-bit RGB value.
 * Extracts R, G, B components and converts to RGB565.
 */
void Color::setRGB(uint32_t rgb) {
	uint8_t r = rgb >> 16;   // Extract red (bits 16-23)
	uint8_t g = rgb >> 8;    // Extract green (bits 8-15)
	uint8_t b = rgb;         // Extract blue (bits 0-7)

	setR(r);
	setG(g);
	setB(b);
}

/**
 * @brief Constructor with RGB components.
 * Initializes color from 8-bit RGB values.
 */
Color::Color(uint8_t r, uint8_t g, uint8_t b) {
	setR(r);
	setG(g);
	setB(b);
}