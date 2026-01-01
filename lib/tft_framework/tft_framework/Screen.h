#ifndef SCREEN_H
#define SCREEN_H

/**
 * @class Screen
 * @brief Abstract base class for TFT display screens.
 * 
 * Screen provides the fundamental interface for all display operations including
 * drawing shapes, rendering text, and managing display properties. It inherits
 * from Color (for background color) and Print (for text output capabilities).
 * 
 * Derived classes must implement fillRect() to provide hardware-specific rendering.
 */
class Screen : public Color, public Print {
   private:
	uint16_t w, h;          ///< Screen width and height in pixels
	uint8_t rotate;         ///< Screen rotation (0, 1, 2, or 3 for 0°, 90°, 180°, 270°)
	Font* f;                ///< Pointer to current font object
	Point cursor;           ///< Current text cursor position
	bool printBuffer;       ///< Whether to use buffered printing
	uint8_t charLength;     ///< Character length for UTF-8 processing
	uint32_t ch;            ///< Current character being processed

   protected:
	/**
	 * @brief Protected constructor - initializes screen dimensions
	 * @param w Screen width in pixels
	 * @param h Screen height in pixels
	 */
	Screen(uint16_t w, uint16_t h);

   public:
	/**
	 * @brief Virtual destructor for proper cleanup
	 */
	virtual ~Screen();

	/**
	 * @brief Initialize the display hardware
	 * 
	 * This method should be called in setup() to prepare the display
	 * for rendering operations. Implementation is hardware-specific.
	 */
	virtual void init();

	/**
	 * @brief Set screen rotation
	 * @param rotation Rotation value (0=0°, 1=90°, 2=180°, 3=270°)
	 */
	virtual void setRotate(uint8_t rotation);
	
	/**
	 * @brief Get current screen rotation
	 * @return Current rotation value (0-3)
	 */
	uint8_t getRotate();

	/**
	 * @brief Get screen width
	 * @return Screen width in pixels
	 */
	uint16_t getWidth();
	
	/**
	 * @brief Get screen height  
	 * @return Screen height in pixels
	 */
	uint16_t getHeight();

	/**
	 * @brief Set text cursor position from Point object
	 * @param c New cursor position
	 */
	void setCursor(Point c);
	
	/**
	 * @brief Set text cursor position
	 * @param x X coordinate for cursor
	 * @param y Y coordinate for cursor
	 */
	void setCursor(int16_t x, int16_t y);
	
	/**
	 * @brief Get current cursor position
	 * @return Current cursor position as Point object
	 */
	Point getCursor();
	
	/**
	 * @brief Reset cursor to origin (0, 0)
	 */
	void resetCursor();
	
	/**
	 * @brief Enable or disable print buffering
	 * @param buf True to enable buffered printing, false for direct printing
	 * 
	 * Buffered printing renders text to a buffer first, preventing overlapping
	 * when drawing multiple lines of text.
	 */
	void setPrintBuffer(bool buf);
	
	/**
	 * @brief Check if print buffering is enabled
	 * @return True if buffering is enabled, false otherwise
	 */
	bool isPrintBuffer();

	/**
	 * @brief Get the current font object
	 * @return Pointer to current Font object
	 */
	Font* getFont();
	
	/**
	 * @brief Set a new font object
	 * @param f Pointer to Font object to use
	 */
	void setFont(Font* f);

	/**
	 * @brief Clear the entire screen
	 * 
	 * Fills the screen with the current background color (from Color class).
	 */
	virtual void clear();
	
	/**
	 * @brief Write a single character to screen (Print interface)
	 * @param data Character byte to write
	 * @return Number of bytes written (always 1)
	 * 
	 * This method is called by print(), println(), and printf() functions.
	 */
	size_t write(uint8_t data);

	/**
	 * @brief Draw a dot (single pixel) on the screen
	 * @param d Pointer to Dot object to draw
	 */
	virtual void drawShape(Dot* d);
	
	/**
	 * @brief Pure virtual method to fill a rectangle
	 * @param rect Pointer to Rectangle object to fill
	 * 
	 * This is the fundamental drawing operation that must be implemented
	 * by derived classes. All other drawing operations ultimately use this.
	 */
	virtual void fillRect(Rectangle* rect) = 0;
	
	/**
	 * @brief Fill a buffer screen onto this screen
	 * @param buf Pointer to BufferScreen object to render
	 */
	virtual void fillShape(BufferScreen* buf);
	
	/**
	 * @brief Draw a bitmap image on the screen
	 * @param bmp Pointer to Bitmap object to render
	 */
	virtual void fillShape(Bitmap* bmp);
};

#endif
