#ifndef TRIANGLE_H
#define TRIANGLE_H

/**
 * @class Triangle
 * @brief Represents a three-sided polygon.
 * 
 * Triangle is defined by three points: the base point (inherited from Shape),
 * p2, and p3. It can be drawn as an outline or filled with solid color.
 */
#include "Fillable.h"
#include "Point.h"
#include "Shape.h"

class Triangle : public Shape, public Fillable {
   private:
	Point p2, p3;  ///< Second and third vertices of the triangle

   public:
	/**
	 * @brief Draw the triangle outline on the screen
	 * @param scr Pointer to the Screen object to draw on
	 */
	void draw(Screen* scr);
	
	/**
	 * @brief Fill the triangle with solid color
	 * @param scr Pointer to the Screen object to draw on
	 */
	void fill(Screen* scr);
	
	/**
	 * @brief Set the second vertex from a Point object
	 * @param p2 Second vertex position
	 */
	void setP2(Point p2);
	
	/**
	 * @brief Set the second vertex coordinates
	 * @param x X coordinate of second vertex
	 * @param y Y coordinate of second vertex
	 */
	void setP2(int16_t x, int16_t y);
	
	/**
	 * @brief Set the third vertex from a Point object
	 * @param p3 Third vertex position
	 */
	void setP3(Point p3);
	
	/**
	 * @brief Set the third vertex coordinates
	 * @param x X coordinate of third vertex
	 * @param y Y coordinate of third vertex
	 */
	void setP3(int16_t x, int16_t y);
	
	/**
	 * @brief Get the second vertex
	 * @return Second vertex as Point object
	 */
	Point getP2() const;
	
	/**
	 * @brief Get the third vertex
	 * @return Third vertex as Point object
	 */
	Point getP3() const;
	
	/**
	 * @brief Move all three vertices by direction and distance
	 * @param direction Angle in degrees (0-359)
	 * @param distance Distance to move in pixels
	 */
	void move(double direction, double distance);
};
#endif
