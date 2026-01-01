#ifndef CIRCLE_H
#define CIRCLE_H

/**
 * @class Circle
 * @brief Represents a circular shape.
 * 
 * Circle is defined by a center point (inherited from Shape) and a radius.
 * It can be drawn as an outline or filled with solid color.
 */
class Circle : public Shape, public Fillable {
   private:
	uint16_t radius;  ///< Radius of the circle in pixels

   public:
	/**
	 * @brief Set the circle radius
	 * @param r Radius in pixels
	 */
	void setRadius(uint16_t r);
	
	/**
	 * @brief Get the circle radius
	 * @return Radius in pixels
	 */
	uint16_t getRadius();

	/**
	 * @brief Draw the circle outline on the screen
	 * @param scr Pointer to the Screen object to draw on
	 */
	void draw(Screen* scr);
	
	/**
	 * @brief Fill the circle with solid color
	 * @param scr Pointer to the Screen object to draw on
	 */
	void fill(Screen* scr);
};

#endif
