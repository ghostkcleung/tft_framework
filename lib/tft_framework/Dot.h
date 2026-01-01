#ifndef DOT_H
#define DOT_H

/**
 * @class Dot
 * @brief Represents a single pixel on the screen.
 * 
 * Dot is the simplest drawable shape, implemented as a 1x1 rectangle.
 * It's used to draw individual pixels with a specific color and position.
 */
class Dot : public Shape {
   public:
	/**
	 * @brief Draw the dot (single pixel) on the screen
	 * @param scr Pointer to the Screen object to draw on
	 */
	void draw(Screen* scr);
};
#endif
