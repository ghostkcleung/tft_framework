#ifndef BUFFER_SCREEN_H
#define BUFFER_SCREEN_H

/**
 * @class BufferScreen
 * @brief A virtual screen that stores rendering in memory before display.
 * 
 * BufferScreen creates an off-screen buffer where drawing operations are stored
 * in RAM before being transferred to the physical display. This is useful for:
 * - Reducing flicker in animations
 * - Pre-rendering complex graphics
 * - Scaling images (render small, display large)
 * 
 * Memory required: width × height × 2 bytes (RGB565 format)
 * Example: 60×60 buffer = 7,200 bytes
 * 
 * @warning Always delete BufferScreen objects to free memory when done!
 */
class BufferScreen : public Screen, public Point, public Fillable {
   private:
	uint16_t* data;  ///< Pointer to pixel data buffer
	uint8_t scale;   ///< Scaling factor when rendering to physical screen
	uint16_t w, h;   ///< Buffer dimensions in pixels

   protected:
	/**
	 * @brief Fill a rectangle in the buffer
	 * @param rect Pointer to Rectangle to fill
	 */
	void fillRect(Rectangle* rect);

   public:
	/**
	 * @brief Get the current scaling factor
	 * @return Scale multiplier (1 = normal size, 2 = 2x, etc.)
	 */
	uint8_t getScale();
	
	/**
	 * @brief Set the scaling factor for rendering
	 * @param scale Scale multiplier (1 = normal, 2 = double size, etc.)
	 */
	void setScale(uint8_t);
	
	/**
	 * @brief Initialize the buffer screen (allocates memory)
	 */
	void init();

	/**
	 * @brief Constructor - creates buffer with specified dimensions
	 * @param w Buffer width in pixels
	 * @param h Buffer height in pixels
	 * @warning Ensure sufficient RAM is available before creating large buffers
	 */
	BufferScreen(uint16_t w, uint16_t h);
	
	/**
	 * @brief Destructor - frees allocated buffer memory
	 */
	virtual ~BufferScreen();

	/**
	 * @brief Transfer buffer contents to physical screen
	 * @param scr Pointer to target Screen object
	 * 
	 * Renders the buffer at the position specified by Point (inherited),
	 * scaled by the current scale factor.
	 */
	void fill(Screen* scr);
	
	/**
	 * @brief Generic fill method for buffer rendering
	 * @param scr Pointer to target Screen object
	 */
	void fillGeneric(Screen* scr);

	/**
	 * @brief Get direct access to buffer data
	 * @return Pointer to pixel data array (RGB565 format)
	 */
	uint16_t* getData();
	
	/**
	 * @brief Draw a dot in the buffer
	 * @param d Pointer to Dot object to draw
	 */
	void drawShape(Dot* d);
};

#endif
