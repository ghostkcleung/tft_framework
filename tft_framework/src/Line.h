#ifndef LINE_H
#define LINE_H

class Line : public Shape
{

private:
    Point endPoint;

public:

    int16_t getEndX();
    int16_t getEndY();

    void setEndX(int16_t x);
    void setEndY(int16_t y);

    Point getEndPoint();
    void setEndPoint(Point p);
    void setEndPoint(int16_t x, int16_t y);

    void move(double direction, double distance);

    void lineTo(double direction, double distance);

    void draw(Screen* scr);
};

#endif
