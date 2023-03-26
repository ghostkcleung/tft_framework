#ifndef CIRCLE_H
#define CIRCLE_H

class Circle : public Shape, public Fillable {

private:
uint16_t radius;

public:
void setRadius( uint16_t r );
uint16_t getRadius();

void draw(Screen* scr);
void fill(Screen* scr);
};


#endif
