#ifndef SCREEN_H
#define SCREEN_H

class Screen:public Color, public Print
{

private:
    uint16_t w, h;
    uint8_t rotate;
    Font* f;
    Point cursor;
    uint8_t fontPadding, fontScale;
    bool printBuffer;
    Color fontColor;
	void sortRect(Rectangle* r);

protected:
    Screen(uint16_t w, uint16_t h);

    virtual void fillRect(Rectangle* rect)=0;

public:
    ~Screen();

    virtual void init();

    virtual void setRotate(uint8_t rotation);
    uint8_t getRotate();

    uint16_t getWidth()
    , getHeight();

    uint8_t getFontScale();
    void setFontScale(uint8_t scale);

    uint8_t getFontPadding();
    void setFontPadding(uint8_t scale);

	Color getFontColor ( );
	void setFontColor ( Color c );

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

    virtual void fillImpl(Rectangle* r);
    virtual void drawImpl(Rectangle* r);
    virtual void fillImpl(Circle* c);
    virtual void drawImpl(Circle* c);
    virtual void drawImpl(Dot* d);
    virtual void drawImpl(Line* l);
    virtual void fillImpl(BufferScreen* buf);
	virtual void drawImpl(Triangle* t);
	virtual void fillImpl(Triangle* t);
	virtual void drawImpl(Ellipse* e);
	virtual void fillImpl(Ellipse* e);
};

#endif
