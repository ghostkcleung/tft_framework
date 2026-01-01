#ifndef FILLABLE_H
#define FILLABLE_H

/**
 * @interface Fillable
 * @brief Interface for shapes that can be filled with solid color.
 * 
 * The Fillable interface defines a fill() method that shapes must implement
 * if they support solid color filling. Not all shapes are fillable:
 * - Fillable: Rectangle, Triangle, Circle, Ellipse
 * - Not Fillable: Dot (already solid), Line (one-dimensional), Font (outline only)
 */
class Fillable {
   public:
	/**
	 * @brief Pure virtual method to fill the shape with solid color
	 * @param scr Pointer to the Screen object to draw on
	 * 
	 * Implementing classes must define how the shape is filled.
	 * The fill color is determined by the Shape's Color property.
	 */
	virtual void fill(Screen* scr) = 0;
};
#endif
