#ifndef SHAPE_H
#define SHAPE_H

class Shape : public Color, public Point
{
protected:
    Shape():Color(),Point() {};

public:
    virtual void draw(Screen* scr)=0;
};

#endif
