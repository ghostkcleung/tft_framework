#ifndef COLOR_H
#define COLOR_H

/**
 * @class Color
 * @brief Represents a color in RGB565 format (16-bit).
 * 
 * The Color class manages colors using the RGB565 format:
 * - 5 bits for Red (0-31)
 * - 6 bits for Green (0-63)  
 * - 5 bits for Blue (0-31)
 * Total: 16 bits per color, allowing 65536 different colors.
 */
class Color {
   private:
	uint16_t color;  ///< Color value in RGB565 format

   public:
	/**
	 * @brief Default constructor - initializes to black (0x0000)
	 */
	Color() : color(0) {};
	
	/**
	 * @brief Constructor with 16-bit color value
	 * @param color RGB565 color value (0x0000 to 0xFFFF)
	 */
	Color(uint16_t color) : color(color) {};
	
	/**
	 * @brief Constructor with RGB components
	 * @param r Red component (0-255)
	 * @param g Green component (0-255)
	 * @param b Blue component (0-255)
	 * @note Values are converted from 24-bit RGB to 16-bit RGB565
	 */
	Color(uint8_t r, uint8_t g, uint8_t b);

	/**
	 * @brief Set color using 16-bit RGB565 value
	 * @param color RGB565 color value
	 */
	void setColor(uint16_t color);
	
	/**
	 * @brief Get the current 16-bit color value
	 * @return RGB565 color value
	 */
	uint16_t getColor() const;

	/**
	 * @brief Set color from another Color object
	 * @param c Source Color object to copy from
	 */
	void setColor(const Color& c);

	/**
	 * @brief Get the red component (8-bit)
	 * @return Red value (0-255)
	 * @note Converted from 5-bit to 8-bit with slight precision loss
	 */
	uint8_t getR() const;
	
	/**
	 * @brief Get the green component (8-bit)
	 * @return Green value (0-255)
	 * @note Converted from 6-bit to 8-bit with slight precision loss
	 */
	uint8_t getG() const;
	
	/**
	 * @brief Get the blue component (8-bit)
	 * @return Blue value (0-255)
	 * @note Converted from 5-bit to 8-bit with slight precision loss
	 */
	uint8_t getB() const;

	/**
	 * @brief Set the red component
	 * @param r Red value (0-255)
	 * @note Converted from 8-bit to 5-bit with slight precision loss
	 */
	void setR(uint8_t r);
	
	/**
	 * @brief Set the green component
	 * @param g Green value (0-255)
	 * @note Converted from 8-bit to 6-bit with slight precision loss
	 */
	void setG(uint8_t g);
	
	/**
	 * @brief Set the blue component
	 * @param b Blue value (0-255)
	 * @note Converted from 8-bit to 5-bit with slight precision loss
	 */
	void setB(uint8_t b);

	/**
	 * @brief Get 24-bit RGB color value
	 * @return 24-bit RGB value (0x00RRGGBB)
	 * @note Converted from RGB565 with slight precision loss
	 */
	uint32_t getRGB() const;
	
	/**
	 * @brief Set color using 24-bit RGB value
	 * @param rgb 24-bit RGB value (0x00RRGGBB)
	 * @note Converted to RGB565 with slight precision loss
	 */
	void setRGB(uint32_t rgb);

	/**
	 * @brief Set color using individual RGB components
	 * @param r Red value (0-255)
	 * @param g Green value (0-255)
	 * @param b Blue value (0-255)
	 * @note More efficient than calling setR(), setG(), setB() separately
	 */
	void setRGB(uint8_t r, uint8_t g, uint8_t b);

	// Operators
	/**
	 * @brief Equality operator
	 * @param other Color to compare with
	 * @return true if both colors have the same RGB565 value
	 */
	bool operator==(const Color& other) const;

	/**
	 * @brief Inequality operator
	 * @param other Color to compare with
	 * @return true if colors have different RGB565 values
	 */
	bool operator!=(const Color& other) const;

	// Static color constants
	static const Color BLACK;     ///< Black color (0x0000)
	static const Color WHITE;     ///< White color (0xFFFF)
	static const Color RED;       ///< Red color (0xF800)
	static const Color GREEN;     ///< Green color (0x07E0)
	static const Color BLUE;      ///< Blue color (0x001F)
	static const Color YELLOW;    ///< Yellow color (0xFFE0)
	static const Color CYAN;      ///< Cyan color (0x07FF)
	static const Color MAGENTA;   ///< Magenta color (0xF81F)
};

#endif
