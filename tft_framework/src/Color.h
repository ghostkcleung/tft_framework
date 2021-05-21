#ifndef COLOR_H
#define COLOR_H


class Color
{

private:
    uint16_t color;

public:
    Color():color(0) {};
    Color(uint16_t color):color(color) {};
	Color(uint8_t r,uint8_t g,uint8_t b);

    void setColor(uint16_t color);
    uint16_t getColor();

    void setColor(Color c);

    uint8_t getR();
    uint8_t getG();
    uint8_t getB();

    void setR(uint8_t r);
    void setG(uint8_t g);
    void setB(uint8_t b);

    uint32_t getRGB ();
    void setRGB(uint32_t rgb);
};

#endif
