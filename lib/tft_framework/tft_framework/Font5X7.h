#ifndef FONT5X7_H
#define FONT5X7_H

/**
 * @class Font5X7
 * @brief Default 5×7 pixel matrix font.
 * 
 * Font5X7 is the built-in font stored in program memory (PROGMEM).
 * Each character is defined as a 5×7 pixel matrix, though the data
 * uses 5×8 bits for easier handling.
 * 
 * Supported characters: ASCII 0x20 (space) to 0x7E (~)
 * 
 * This is the default font used by Screen objects unless changed.
 */
class Font5X7 : public Font {
   public:
	/**
	 * @brief Constructor - initializes 5×7 font
	 */
	Font5X7();
	
	/**
	 * @brief Draw a character on the screen
	 * @param scr Pointer to Screen object to draw on
	 */
	void draw(Screen* scr);

   private:
	/**
	 * @brief Character bitmap data stored in program memory
	 * 
	 * Each character is represented by 5 bytes (one per column).
	 * Data is stored in PROGMEM to save RAM.
	 */
	static const uint8_t Matrix[] PROGMEM;
};

#endif