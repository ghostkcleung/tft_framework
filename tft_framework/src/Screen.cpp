#include "tft_framework.h"
using namespace tft_framework;

Screen::Screen(uint16_t w, uint16_t h)
{
    this->w = w;
    this->h = h;
    rotate = 0 ;
    printBuffer = false;
    fontPadding = 0 ;
    fontScale = 1;
    fontColor.setColor(0xFFFF);
    f = new Font5X7();
}

Screen::~Screen()
{
    delete f;
}

void Screen::init()
{
}

void Screen::setRotate(uint8_t rotate)
{
    uint8_t r=this->rotate;
    this->rotate = rotate;

    r%=2;
    rotate %=2;

    if ( r != rotate )
    {
        uint16_t tmp = w;
        w = h;
        h = tmp;
    }
}

uint8_t Screen::getRotate()
{
    return rotate;
}

uint16_t Screen::getWidth()
{
    return w;
}

uint16_t Screen::getHeight()
{
    return h;
}

void Screen::clear()
{
    Rectangle r;
    r.setSize(w,h);
    r.setColor(*this);
	resetCursor();
    r.fill(this);
}

void Screen::setFont ( Font* f )
{
    delete this->f;
    this->f = f;
}

Font* Screen::getFont()
{
    return f;
}

uint8_t Screen::getFontScale()
{
    return fontScale;
}

void Screen::setFontScale(uint8_t scale)
{
    fontScale = scale;
}

uint8_t Screen::getFontPadding()
{
    return fontPadding;
}

void Screen::setFontPadding(uint8_t padding)
{
    fontPadding = padding;
}

Point Screen::getCursor()
{
    Point p;
    p.setPoint ( *f );
    return p;
}

void Screen::setFontColor(Color c)
{
    fontColor = c;
}

Color Screen::getFontColor ( ) {
	return fontColor;
}

void Screen::setCursor(Point c)
{
    cursor = c;
    f -> setPoint ( c );
}

void Screen::setCursor(int16_t x, int16_t y)
{
    cursor.setPoint(x,y);
    f -> setPoint ( x,y );
}

bool Screen::isPrintBuffer ( )
{
    return printBuffer;
}

void Screen::setPrintBuffer ( bool buf )
{
    printBuffer = buf;
}

size_t Screen::write(uint8_t data)
{
    uint8_t _w = f->getWidth(),
            _h = f->getHeight();

    if ( data == '\r' )
    {
        return 1;
    }

    if ( data == '\n' )
    {
        f->move(180,_h*fontScale+fontScale*fontPadding);

		if (f->getY()+_h*fontScale > h)
		{
			f->move(0,_h*fontScale+fontScale*fontPadding);
		}

        f->setX(cursor.getX());
        return 1;
    }

    f->setChar ( data ) ;
    f->setColor ( fontColor ) ;

    if (f->getX()+_w*fontScale > w)
    {
        write('\n');
    }

    if (printBuffer)
    {
        BufferScreen *bScr = new BufferScreen(_w,_h);
        bScr -> setColor ( *this ) ;
        bScr -> setScale ( fontScale ) ;
        bScr -> setPoint(*f);
        bScr -> clear ( ) ;
        f->setPoint(0,0);
        f->setScale(1);
        f->draw(bScr);

        bScr -> fill (this);

        f->setPoint(*bScr);

        delete bScr ;

	if ( fontPadding > 0 ) {
          Rectangle r;
          r.setColor(*this);
          r.setPoint(*f);
          r.move(90,_w*fontScale);
          r.setSize (fontScale*fontPadding, _h*fontScale);
          fillRect(&r);
          r.setPoint(*f);
          r.move(180,_h*fontScale);
          r.setSize(fontScale*(_w+fontPadding), fontScale*fontPadding);
          fillRect(&r);
	}
    }
    else
    {
        f->setScale(fontScale);
        f->draw(this);
    }

    f->move(90,_w*fontScale+fontPadding*fontScale);

    return 1;
}

void Screen::resetCursor ( )
{
    f->setPoint(cursor);
}

void Screen::drawShape(Shape *s) {
	s -> drawGeneric ( this ) ;
}

void Screen::fillShape(Fillable *f) {
	f -> fillGeneric ( this ) ;
}

void Screen::fillShape(BufferScreen *buf) {
	buf -> fillGeneric ( this ) ;
}