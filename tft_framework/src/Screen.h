#ifndef SCREEN_H
#define SCREEN_H

class Screen:public Color, public Print
{

private:
    uint16_t w, h;
    uint8_t rotate;
    Font* f;
    Point cursor;
    bool printBuffer;
	uint8_t charLength ;
	uint32_t ch;

protected:
    Screen(uint16_t w, uint16_t h);

public:
    virtual ~Screen();

    virtual void init();

    virtual void setRotate(uint8_t rotation);
    uint8_t getRotate();

    uint16_t getWidth()
    , getHeight();

    void setCursor ( Point c );
    void setCursor ( int16_t x, int16_t y );
    Point getCursor ( );
	void resetCursor( );
    void setPrintBuffer ( bool buf );
    bool isPrintBuffer ( ) ;

    Font* getFont();
    void setFont(Font* f);

    virtual void clear();
    size_t write(uint8_t data);

	virtual void drawShape ( Dot* d );
    virtual void fillRect(Rectangle* rect)=0;
    virtual void fillShape(BufferScreen* buf);
};

#endif
