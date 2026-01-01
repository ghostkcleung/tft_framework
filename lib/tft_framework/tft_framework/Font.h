#ifndef FONT_H
#define FONT_H

/**
 * @class Font
 * @brief Base class for rendering text characters on screen.
 * 
 * Font provides the interface for drawing individual characters with support for:
 * - Scaling (1x, 2x, 3x, etc.)
 * - Padding (internal spacing)
 * - Spacing (external spacing between characters)
 * 
 * The default implementation uses a 5×7 pixel matrix font stored in ROM.
 * Supported characters: ASCII 0x20 (space) to 0x7E (~)
 */
class Font : public Shape {
   public:
	/**
	 * @brief Constructor with font dimensions
	 * @param w Base character width in pixels
	 * @param h Base character height in pixels
	 */
	Font(uint8_t w, uint8_t h)
		: w(w),
		  h(h),
		  scale(1),
		  c('\0'),
		  paddingTop(0),
		  paddingLeft(0),
		  paddingBottom(0),
		  paddingRight(0),
		  spacingTop(0),
		  spacingLeft(0),
		  spacingBottom(0),
		  spacingRight(0) {};

	/**
	 * @brief Virtual destructor for proper cleanup
	 */
	virtual ~Font();

	/**
	 * @brief Get base character width
	 * @return Character width in pixels (before scaling)
	 */
	uint8_t getWidth();
	
	/**
	 * @brief Get base character height
	 * @return Character height in pixels (before scaling)
	 */
	uint8_t getHeight();

	/**
	 * @brief Get the current character
	 * @return Character code (uint32_t for UTF-8 support)
	 */
	uint32_t getChar();
	
	/**
	 * @brief Set the character to render
	 * @param c Character code to set
	 */
	virtual void setChar(uint32_t c);

	/**
	 * @brief Get the current scaling factor
	 * @return Scale multiplier (1 = normal, 2 = 2x, etc.)
	 */
	uint8_t getScale();
	
	/**
	 * @brief Set the scaling factor
	 * @param s Scale multiplier (1 = normal size, 2 = double size, etc.)
	 */
	void setScale(uint8_t s);

	/**
	 * @brief Set top padding
	 * @param paddingTop Padding in pixels (internal spacing)
	 */
	void setPaddingTop(uint8_t paddingTop);
	
	/**
	 * @brief Set left padding
	 * @param paddingLeft Padding in pixels (internal spacing)
	 */
	void setPaddingLeft(uint8_t paddingLeft);
	
	/**
	 * @brief Set bottom padding
	 * @param paddingBottom Padding in pixels (internal spacing)
	 */
	void setPaddingBottom(uint8_t paddingBottom);
	
	/**
	 * @brief Set right padding
	 * @param paddingRight Padding in pixels (internal spacing)
	 */
	void setPaddingRight(uint8_t paddingRight);

	/**
	 * @brief Get top padding
	 * @return Top padding in pixels
	 */
	uint8_t getPaddingTop();
	
	/**
	 * @brief Get left padding
	 * @return Left padding in pixels
	 */
	uint8_t getPaddingLeft();
	
	/**
	 * @brief Get bottom padding
	 * @return Bottom padding in pixels
	 */
	uint8_t getPaddingBottom();
	
	/**
	 * @brief Get right padding
	 * @return Right padding in pixels
	 */
	uint8_t getPaddingRight();

	/**
	 * @brief Set top spacing
	 * @param spacingTop Spacing in pixels (external spacing)
	 */
	void setSpacingTop(uint8_t spacingTop);
	
	/**
	 * @brief Set left spacing
	 * @param spacingLeft Spacing in pixels (external spacing)
	 */
	void setSpacingLeft(uint8_t spacingLeft);
	
	/**
	 * @brief Set bottom spacing
	 * @param spacingBottom Spacing in pixels (external spacing)
	 */
	void setSpacingBottom(uint8_t spacingBottom);
	
	/**
	 * @brief Set right spacing
	 * @param spacingRight Spacing in pixels (external spacing)
	 */
	void setSpacingRight(uint8_t spacingRight);

	/**
	 * @brief Get top spacing
	 * @return Top spacing in pixels
	 */
	uint8_t getSpacingTop();
	
	/**
	 * @brief Get left spacing
	 * @return Left spacing in pixels
	 */
	uint8_t getSpacingLeft();
	
	/**
	 * @brief Get bottom spacing
	 * @return Bottom spacing in pixels
	 */
	uint8_t getSpacingBottom();
	
	/**
	 * @brief Get right spacing
	 * @return Right spacing in pixels
	 */
	uint8_t getSpacingRight();

	/**
	 * @brief Get total character width including padding and spacing
	 * @return Total width in pixels (after scaling)
	 */
	virtual uint8_t getTotalWidth();
	
	/**
	 * @brief Get total character height including padding and spacing
	 * @return Total height in pixels (after scaling)
	 */
	virtual uint8_t getTotalHeight();

	/**
	 * @brief Render the character to screen
	 * @param scr Pointer to Screen object to draw on
	 */
	virtual void write(Screen* scr);

   protected:
	uint8_t w, h;  ///< Base character dimensions

   private:
	uint8_t scale;  ///< Scaling factor
	uint32_t c;     ///< Current character code
	uint8_t paddingTop, paddingLeft, paddingBottom, paddingRight, spacingTop,
		spacingLeft, spacingBottom, spacingRight;  ///< Padding and spacing values
};

#endif
