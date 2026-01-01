#ifndef BITMAP_H
#define BITMAP_H

/**
 * @class Bitmap
 * @brief Handles BMP (Windows Bitmap) image file rendering.
 * 
 * Bitmap loads and displays .bmp image files from storage devices.
 * Supports standard uncompressed BMP format with 24-bit RGB color.
 * Colors are automatically converted from RGB888 to RGB565 for display.
 */
class Bitmap : public Image {
   private:
	bool bm;                 ///< Whether the file is a valid bitmap
	uint32_t dataOffset;     ///< Byte offset to pixel data in file

	/**
	 * @brief Reverse byte order (helper for BMP header parsing)
	 * @param ptr Pointer to byte array
	 * @param len Number of bytes to reverse
	 * @return Reversed value as uint32_t
	 */
	uint32_t _rev(byte* ptr, uint8_t len);

   public:
	/**
	 * @brief Constructor - loads BMP file
	 * @param f Reference to opened BMP File object
	 * 
	 * Reads and parses the BMP header to extract image dimensions,
	 * color depth, and data offset.
	 */
	Bitmap(File& f);

	/**
	 * @brief Get the offset to pixel data in the file
	 * @return Byte offset to start of pixel data
	 */
	uint32_t getDataOffset();
	
	/**
	 * @brief Render the bitmap to screen
	 * @param scr Pointer to Screen object to draw on
	 * 
	 * Renders the entire image or viewport (if set) at the position
	 * specified by the Point coordinates.
	 */
	void fill(Screen* scr);
	
	/**
	 * @brief Generic bitmap rendering method
	 * @param scr Pointer to Screen object to draw on
	 */
	void fillGeneric(Screen* scr);
};

#endif
