#ifndef Ellipse_H
#define Ellipse_H

/**
 * @class Ellipse
 * @brief Represents an elliptical (oval) shape.
 * 
 * Ellipse is defined by a center point (inherited from Shape) and two radii:
 * horizontal radius (rx) and vertical radius (ry).
 * It can be drawn as an outline or filled with solid color.
 */
class Ellipse : public Shape, public Fillable {
   private:
	uint16_t rx, ry;  ///< Horizontal and vertical radii in pixels

   public:
	/**
	 * @brief Set the horizontal radius
	 * @param rx Horizontal radius in pixels
	 */
	void setRx(uint16_t rx);
	
	/**
	 * @brief Set the vertical radius
	 * @param ry Vertical radius in pixels
	 */
	void setRy(uint16_t ry);
	
	/**
	 * @brief Get the horizontal radius
	 * @return Horizontal radius in pixels
	 */
	uint16_t getRx();
	
	/**
	 * @brief Get the vertical radius
	 * @return Vertical radius in pixels
	 */
	uint16_t getRy();

	/**
	 * @brief Draw the ellipse outline on the screen
	 * @param scr Pointer to the Screen object to draw on
	 */
	void draw(Screen* scr);
	
	/**
	 * @brief Fill the ellipse with solid color
	 * @param scr Pointer to the Screen object to draw on
	 */
	void fill(Screen* scr);
};

#endif
