#ifndef BM_FONT_H
#define BM_FONT_H

#include "tft_framework.h"

using namespace tft_framework;

/**
 * @class BmFont
 * @brief Bitmap font loader for custom fonts from files.
 * 
 * BmFont loads and renders bitmap fonts stored in files (typically .fnt format
 * with accompanying image files). Supports variable-width fonts with caching
 * for improved performance.
 * 
 * Font data is loaded from storage (SD card or SPIFFS) on demand.
 */
class BmFont : public Font {
   public:
	/**
	 * @brief Constructor - loads bitmap font from file
	 * @param path Reference to directory File containing font files
	 * @param fntFileName Name of the .fnt font definition file
	 */
	BmFont(File& path, String fntFileName);
	
	/**
	 * @brief Draw the current character on screen
	 * @param scr Pointer to Screen object to draw on
	 */
	void draw(Screen* scr);
	
	/**
	 * @brief Destructor - cleans up font data and cache
	 */
	~BmFont();

	/**
	 * @brief Check if font was loaded successfully
	 * @return True if font is valid and ready to use
	 */
	bool isValid();

	/**
	 * @brief Set the character to render
	 * @param c Character code (supports Unicode)
	 */
	void setChar(uint32_t c);

	/**
	 * @brief Set the character bitmap cache size
	 * @param size Number of characters to cache in memory
	 * 
	 * Larger cache improves performance but uses more RAM.
	 * Default cache size provides a balance.
	 */
	void setCacheSize(uint8_t size);
	
	/**
	 * @brief Get the current cache size
	 * @return Number of cached characters
	 */
	uint8_t getCacheSize();

   private:
	bool valid;  ///< Whether the font loaded successfully

	File path;           ///< Directory containing font files
	String fntFileName;  ///< Font definition file name

	uint16_t scaleW, scaleH;  ///< Font texture dimensions

	uint8_t pageCount;    ///< Number of font texture pages
	String** pages;       ///< Array of texture page filenames
	uint16_t charCount;   ///< Number of characters in font

	/**
	 * @struct CharStruct
	 * @brief Character definition and cache data
	 */
	struct CharStruct {
		uint32_t id;           ///< Character code (Unicode)
		uint8_t page;          ///< Texture page containing this character
		uint16_t x, y;         ///< Position in texture page
		uint16_t width, height;///< Character dimensions
		uint8_t yOffset;       ///< Vertical offset for baseline alignment
		uint8_t* cache = NULL; ///< Cached bitmap data (NULL if not cached)
		uint16_t useTime = 0;  ///< Last usage time for cache management
	};

	struct CharStruct** chars;     ///< Array of character definitions
	struct CharStruct* selected;   ///< Currently selected character

	uint8_t cacheSize;   ///< Maximum number of characters to cache
	uint8_t cacheCount;  ///< Current number of cached characters
};

#endif