#ifndef TRIANGLE_H
#define TRIANGLE_H

class Triangle : public Shape, public Fillable
{
private:
	Point p2, p3;

public:
    void draw(Screen* scr);
	void fill(Screen* scr);
	void setP2 ( Point p2 );
	void setP2 ( int16_t x, int16_t y );
	void setP3 ( Point p3 );
	void setP3 ( int16_t x, int16_t y );
	Point getP2 ( );
	Point getP3 ( );
	void move ( double direction, double distance );
} ;
#endif
