#ifndef IMAGE_H
#define IMAGE_H

/**
 * @class Image
 * @brief Abstract base class for image rendering from files.
 * 
 * Image provides the interface for loading and displaying image files
 * (such as BMP) from storage devices like SD cards or SPIFFS.
 * Supports viewport rendering to display portions of an image.
 */
class Image : public Point, public Fillable {
   private:
	File f;  ///< File handle for the image file

   protected:
	uint32_t width, height;  ///< Image dimensions in pixels
	uint16_t colorDepth;     ///< Bits per pixel (e.g., 24 for RGB)

   public:
	/**
	 * @brief Constructor with file reference
	 * @param f Reference to opened File object
	 */
	Image(File& f) : f(f) {};
	
	/**
	 * @brief Viewport rectangle for partial image rendering
	 * 
	 * When set, only the portion of the image within the viewport
	 * rectangle will be rendered to the screen.
	 */
	Rectangle viewport;
	
	/**
	 * @brief Get the current viewport
	 * @return Viewport rectangle
	 */
	Rectangle getViewport();
	
	/**
	 * @brief Set the viewport for partial rendering
	 * @param viewport Rectangle defining the visible portion
	 */
	void setViewport(Rectangle viewport);
	
	/**
	 * @brief Get image width
	 * @return Width in pixels
	 */
	virtual uint32_t getWidth();
	
	/**
	 * @brief Get image height
	 * @return Height in pixels
	 */
	virtual uint32_t getHeight();
	
	/**
	 * @brief Get image color depth
	 * @return Bits per pixel
	 */
	virtual uint16_t getColorDepth();
	
	/**
	 * @brief Get the associated file handle
	 * @return File object
	 */
	File getFile();
};

#endif
