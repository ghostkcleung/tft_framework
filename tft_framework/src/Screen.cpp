#include "tft_framework.h"
using namespace tft_framework;

Screen::Screen(uint16_t w, uint16_t h)
{
    this->w = w;
    this->h = h;
    rotate = 0 ;
    printBuffer = false;
    f = new Font5X7();
    f -> setScale ( 1 );
    f -> setColor(0xFFFF);
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

Point Screen::getCursor()
{
    Point p;
    p.setPoint ( *f );
    return p;
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
    uint8_t _w = f->getTotalWidth(),
            _h = f->getTotalHeight();

    if ( data == '\r' ) {
        return 1;
    }

    if ( data == '\n' ) {

		if (f->getY()+_h < h) {
			f->move(180,_h);
		}

        f->setX(cursor.getX());
        return 1;
    }

	if ( data & 0b10000000 ) {
		if ( data & 0b01000000 ) {
			uint8_t mask = 0b11000000;
			charLength = 0;

			while ( ( data & mask ) == mask ) {
				charLength ++ ;
				mask >>= 1;
				mask |= 0b10000000;
			}
			
			ch = data << ( charLength * 8 ) ;
			return 0;
		} else {
			charLength -- ;
			ch += data << ( charLength * 8 ) ;

			if ( charLength ) {
				return 0 ;
			}
			f -> setChar ( ch ) ;
		}
	} else {
		f->setChar ( data ) ;
	}

    if (f->getX()+_w >= w) {
        write('\n');
    }

    if (printBuffer)
    {
        BufferScreen *bScr = new BufferScreen(f->getWidth()+f->getPaddingLeft()
			,f->getHeight()+f->getPaddingTop());
        bScr -> setColor ( *this ) ;
        bScr -> setPoint(*f);
        bScr -> clear ( ) ;
        f->setPoint(0,0);

		bScr->setScale ( f->getScale ( ) ) ;
        f->setScale(1);
        f->draw(bScr);
        bScr -> fill (this);

        f->setPoint(*bScr);
		f->setScale ( bScr -> getScale ( ));

        delete bScr ;
    } else {
        f->draw(this);
    }

    f->move(90,_w);

    return 1;
}

void Screen::resetCursor ( )
{
    f->setPoint(cursor);
}

void Screen::fillShape(BufferScreen *buf) {
	buf -> fillGeneric ( this ) ;
}

void Screen::drawShape(Dot *d){
	Rectangle r;
	r.setPoint ( *d );
	r.setEndPoint ( *d );
	r.setColor ( *d );
	fillRect ( &r ) ;
}