#ifndef Ellipse_H
#define Ellipse_H

class Ellipse : public Shape, public Fillable {

private:
uint16_t rx, ry;

public:
void setRx( uint16_t rx );
void setRy( uint16_t ry );
uint16_t getRx();
uint16_t getRy();

void draw(Screen* scr);

void fill(Screen* scr);
};


#endif
