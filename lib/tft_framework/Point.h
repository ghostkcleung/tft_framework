#ifndef POINT_H
#define POINT_H

/**
 * @class Point
 * @brief Represents a 2D coordinate point on the screen.
 * 
 * The Point class encapsulates X and Y coordinates for positioning objects on the display.
 * Origin (0, 0) is at the top-left corner of the screen.
 */
class Point {
   private:
	int16_t x, y;  ///< X and Y coordinates

   public:
	/**
	 * @brief Default constructor - initializes point at origin (0, 0)
	 */
	Point() : x(0), y(0) {};
	
	/**
	 * @brief Constructor with initial coordinates
	 * @param x X coordinate
	 * @param y Y coordinate
	 */
	Point(int16_t x, int16_t y) : x(x), y(y) {};

	/**
	 * @brief Get the X coordinate
	 * @return Current X coordinate value
	 */
	int16_t getX() const;
	
	/**
	 * @brief Get the Y coordinate
	 * @return Current Y coordinate value
	 */
	int16_t getY() const;
	
	/**
	 * @brief Set the X coordinate
	 * @param x New X coordinate value
	 */
	void setX(int16_t x);
	
	/**
	 * @brief Set the Y coordinate
	 * @param y New Y coordinate value
	 */
	void setY(int16_t y);

	/**
	 * @brief Set point coordinates from another Point object
	 * @param p Source Point object to copy coordinates from
	 */
	void setPoint(const Point& p);
	
	/**
	 * @brief Set point coordinates directly
	 * @param x New X coordinate
	 * @param y New Y coordinate
	 */
	void setPoint(int16_t x, int16_t y);

	/**
	 * @brief Offset the point by dx and dy
	 * @param dx Amount to offset in X direction
	 * @param dy Amount to offset in Y direction
	 */
	void offset(int16_t dx, int16_t dy);

	/**
	 * @brief Offset the point in X direction only
	 * @param dx Amount to offset in X direction
	 */
	void offsetX(int16_t dx);

	/**
	 * @brief Offset the point in Y direction only
	 * @param dy Amount to offset in Y direction
	 */
	void offsetY(int16_t dy);

	/**
	 * @brief Calculate the midpoint between this point and another point
	 * @param p The other point
	 * @return A new Point at the midpoint between the two points
	 */
	Point midPoint(const Point& p) const;

	/**
	 * @brief Move the point by a direction and distance
	 * @param direction Angle in degrees (0-359). 0° = North (up), 90° = East (right)
	 * @param distance Distance to move in pixels
	 */
	virtual void move(double direction, double distance);

	// Operators
	/**
	 * @brief Equality operator
	 * @param other Point to compare with
	 * @return true if both points have the same coordinates
	 */
	bool operator==(const Point& other) const;

	/**
	 * @brief Inequality operator
	 * @param other Point to compare with
	 * @return true if points have different coordinates
	 */
	bool operator!=(const Point& other) const;

	/**
	 * @brief Addition operator - returns a new point
	 * @param other Point to add
	 * @return New Point with summed coordinates
	 */
	Point operator+(const Point& other) const;

	/**
	 * @brief Subtraction operator - returns a new point
	 * @param other Point to subtract
	 * @return New Point with subtracted coordinates
	 */
	Point operator-(const Point& other) const;

	/**
	 * @brief Addition assignment operator
	 * @param other Point to add
	 * @return Reference to this point after addition
	 */
	Point& operator+=(const Point& other);

	/**
	 * @brief Subtraction assignment operator
	 * @param other Point to subtract
	 * @return Reference to this point after subtraction
	 */
	Point& operator-=(const Point& other);
};

#endif
