#ifndef RECTANGLE_H
#define RECTANGLE_H

/**
 * @class Rectangle
 * @brief Represents a rectangular shape that can be drawn and filled.
 * 
 * Rectangle is the fundamental building block for all graphics operations.
 * It inherits from Line (which provides start and end points) and implements
 * the Fillable interface to support both outline drawing and solid filling.
 * 
 * All rendering operations ultimately use fillRect() as the base operation.
 */
class Rectangle : public Line, public Fillable {
   public:
	/**
	 * @brief Get the width of the rectangle
	 * @return Width in pixels (can be negative)
	 * @note Negative width places end point to the left of start point
	 */
	int16_t getWidth();
	
	/**
	 * @brief Get the height of the rectangle
	 * @return Height in pixels (can be negative)
	 * @note Negative height places end point above start point
	 */
	int16_t getHeight();

	/**
	 * @brief Set the width of the rectangle
	 * @param w Width in pixels
	 */
	void setWidth(int16_t w);
	
	/**
	 * @brief Set the height of the rectangle
	 * @param h Height in pixels
	 */
	void setHeight(int16_t h);

	/**
	 * @brief Set both width and height of the rectangle
	 * @param w Width in pixels
	 * @param h Height in pixels
	 */
	void setSize(int16_t w, int16_t h);
	
	/**
	 * @brief Set size from another Rectangle object
	 * @param rect Source Rectangle to copy dimensions from
	 */
	void setSize(Rectangle rect);
	
	/**
	 * @brief Fill the rectangle with solid color
	 * @param scr Pointer to the Screen object to draw on
	 */
	void fill(Screen* scr);
	
	/**
	 * @brief Draw the rectangle outline
	 * @param scr Pointer to the Screen object to draw on
	 */
	void draw(Screen* scr);
};

#endif
