#ifndef BUFFER_SCREEN_H
#define BUFFER_SCREEN_H

class BufferScreen :
    public Screen,
    public Point,
    public Fillable
{

private:
    uint16_t* data;
    uint8_t scale;
	uint16_t w, h ;

protected:
    void fillRect(Rectangle* rect);

public:

    uint8_t getScale();
    void setScale(uint8_t);
    void init ( ) ;

    BufferScreen(uint16_t w, uint16_t h);
    virtual ~BufferScreen();

	void fill(Screen* scr);
	void fillGeneric(Screen* scr);

    uint16_t* getData();
	void drawShape(Dot *d);
};

#endif
