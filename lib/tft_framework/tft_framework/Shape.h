#ifndef SHAPE_H
#define SHAPE_H

/**
 * @class Shape
 * @brief Abstract base class for all drawable shapes.
 * 
 * Shape inherits from both Color and Point, providing position and color
 * properties to all derived shape classes. This class cannot be instantiated
 * directly; it serves as a base for specific shape implementations.
 * 
 * Derived classes include: Dot, Line, Rectangle, Triangle, Circle, Ellipse, Font
 */
class Shape : public Color, public Point {
   protected:
	/**
	 * @brief Protected constructor - prevents direct instantiation
	 */
	Shape() : Color(), Point() {};

   public:
	/**
	 * @brief Pure virtual function to draw the shape on screen
	 * @param scr Pointer to the Screen object to draw on
	 * 
	 * Each derived class must implement this method to define
	 * how the specific shape is rendered to the display.
	 */
	virtual void draw(Screen* scr) = 0;
};

#endif
