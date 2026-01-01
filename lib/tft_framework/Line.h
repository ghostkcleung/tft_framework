#ifndef LINE_H
#define LINE_H

/**
 * @class Line
 * @brief Represents a straight line between two points.
 * 
 * The Line class draws a line from a start point (inherited from Point)
 * to an end point using Bresenham's line algorithm.
 */
class Line : public Shape
{

private:
    Point endPoint;  ///< End point of the line

public:

    /**
     * @brief Get the X coordinate of the line's end point
     * @return End point X coordinate
     */
    int16_t getEndX();
    
    /**
     * @brief Get the Y coordinate of the line's end point
     * @return End point Y coordinate
     */
    int16_t getEndY();

    /**
     * @brief Set the X coordinate of the line's end point
     * @param x New end point X coordinate
     */
    void setEndX(int16_t x);
    
    /**
     * @brief Set the Y coordinate of the line's end point
     * @param y New end point Y coordinate
     */
    void setEndY(int16_t y);

    /**
     * @brief Get the end point as a Point object
     * @return End point object
     */
    Point getEndPoint();
    
    /**
     * @brief Set the end point from a Point object
     * @param p New end point
     */
    void setEndPoint(Point p);
    
    /**
     * @brief Set the end point coordinates
     * @param x New end point X coordinate
     * @param y New end point Y coordinate
     */
    void setEndPoint(int16_t x, int16_t y);

    /**
     * @brief Move both start and end points by direction and distance
     * @param direction Angle in degrees (0-359)
     * @param distance Distance to move in pixels
     */
    void move(double direction, double distance);
    
    /**
     * @brief Move the line to a new start position (end point follows)
     * @param p New start point
     */
	void moveTo ( Point p );
	
	/**
	 * @brief Move the line to a new start position (end point follows)
	 * @param x New start X coordinate
	 * @param y New start Y coordinate
	 */
	void moveTo ( int16_t x, int16_t y);
	
	/**
	 * @brief Move the line horizontally (end point follows)
	 * @param x New start X coordinate
	 */
	void moveToX ( int16_t x ) ;
	
	/**
	 * @brief Move the line vertically (end point follows)
	 * @param y New start Y coordinate
	 */
	void moveToY ( int16_t y ) ;

    /**
     * @brief Set the end point relative to start point using direction and distance
     * @param direction Angle in degrees (0-359)
     * @param distance Distance from start point
     */
    void lineTo(double direction, double distance);

    /**
     * @brief Draw the line on the screen
     * @param scr Pointer to the Screen object to draw on
     */
    void draw(Screen* scr);
};

#endif
