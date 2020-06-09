#ifndef POINT_H
#define POINT_H

class Point
{

private:
    int16_t x, y;

public:
    Point():x(0),y(0) {};
    Point(int16_t x, int16_t y):x(x),y(y) {};

    int16_t getX();
    int16_t getY();
    void setX(int16_t x);
    void setY(int16_t y);

    void setPoint(Point p);
    void setPoint(int16_t x, int16_t y);

    virtual void move(double direction, double distance);

};

#endif
