#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle : public Line, public Fillable
{
public:

    int16_t getWidth();
    int16_t getHeight();

    void setWidth(int16_t w);
    void setHeight(int16_t h);

    void setSize(int16_t w, int16_t h);
    void fillGeneric(Screen* scr);
    void drawGeneric(Screen* scr);
};

#endif
