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
uint16_t Color::getColor() const { return color; }

void Color::setColor(uint16_t color) { this->color = color; }

void Color::setColor(const Color& c) { color = c.color; }

/**
 * @brief Extract red component from RGB565 format.
 * Converts 5-bit red to 8-bit by extracting and scaling properly.
 */
uint8_t Color::getR() const {
	uint8_t r5 = (color >> 11) & 0x1F;  // Extract 5-bit red (bits 11-15)
	return (r5 << 3) | (r5 >> 2);       // Scale to 8-bit: copy MSBs to LSBs
}

/**
 * @brief Extract green component from RGB565 format.
 * Converts 6-bit green to 8-bit by extracting and scaling properly.
 */
uint8_t Color::getG() const {
	uint8_t g6 = (color >> 5) & 0x3F;   // Extract 6-bit green (bits 5-10)
	return (g6 << 2) | (g6 >> 4);       // Scale to 8-bit: copy MSBs to LSBs
}

/**
 * @brief Extract blue component from RGB565 format.
 * Converts 5-bit blue to 8-bit by extracting and scaling properly.
 */
uint8_t Color::getB() const {
	uint8_t b5 = color & 0x1F;          // Extract 5-bit blue (bits 0-4)
	return (b5 << 3) | (b5 >> 2);       // Scale to 8-bit: copy MSBs to LSBs
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
uint32_t Color::getRGB() const {
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
	setRGB(r, g, b);
}

/**
 * @brief Set color using individual RGB components (more efficient).
 * Sets all three color components in one call, avoiding multiple bit operations.
 */
void Color::setRGB(uint8_t r, uint8_t g, uint8_t b) {
	// Convert 8-bit RGB to 5-6-5 format and combine in one operation
	uint16_t r565 = (r >> 3) & 0x1F;    // 5-bit red
	uint16_t g565 = (g >> 2) & 0x3F;    // 6-bit green
	uint16_t b565 = (b >> 3) & 0x1F;    // 5-bit blue
	color = (r565 << 11) | (g565 << 5) | b565;
}

// Static color constants (RGB565 values)
const Color Color::BLACK(0x0000);      // Black:   RGB(0, 0, 0)
const Color Color::WHITE(0xFFFF);      // White:   RGB(255, 255, 255)
const Color Color::RED(0xF800);        // Red:     RGB(255, 0, 0)
const Color Color::GREEN(0x07E0);      // Green:   RGB(0, 255, 0)
const Color Color::BLUE(0x001F);       // Blue:    RGB(0, 0, 255)
const Color Color::YELLOW(0xFFE0);     // Yellow:  RGB(255, 255, 0)
const Color Color::CYAN(0x07FF);       // Cyan:    RGB(0, 255, 255)
const Color Color::MAGENTA(0xF81F);    // Magenta: RGB(255, 0, 255)