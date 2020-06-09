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
    fillImpl(&r);
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

void Screen::sortRect(Rectangle*r){
    int16_t x1 = r -> getX(),
            y1 = r -> getY(),
            x2 = r -> getEndX(),
            y2 = r -> getEndY(),
            h = getHeight (),
            w = getWidth ();

    if(x1>x2)
    {
        swap(x1,x2);
    }

    if(y1>y2)
    {
        swap(y1,y2);
    }

    if ( x1 >= w )
    {
        return ;
    }
    if ( y1 >= h )
    {
        return ;
    }

    if ( x2 < 0 )
    {
        return ;
    }
    if ( y2 < 0 )
    {
        return ;
    }

    if ( x1 < 0 )
    {
        x1 = 0 ;
    }
    if ( y1 < 0 )
    {
        y1 = 0 ;
    }

    if ( x2 >= w )
    {
        x2 = w-1 ;
    }
    if ( y2 >= h )
    {
        y2 = h-1 ;
    }

    r -> setPoint(x1, y1);
    r -> setEndPoint(x2, y2);	
}

void Screen::fillImpl(Rectangle*r)
{
	sortRect(r);

	int x0 = r -> getX ( )
		, y0 = r -> getY ( )
		, x1 = r -> getEndX ( )
		, y1 = r -> getEndY ( )
		, maxX = getWidth ( ) - 1
		, maxY = getHeight ( ) - 1 ;

	if ( x0 > maxX ) { return ; }
	if ( y0 > maxY ) { return ; }
	if ( x1 < 0 ) { return ; }
	if ( y1 < 0 ) { return ; }

	x0 = x0 < 0 ? 0 : x0;
	y0 = y0 < 0 ? 0 : y0;
	x1 = x1 > maxX ? maxX : x1;
	y1 = y1 > maxY ? maxY : y1;

    fillRect(r);
}

void Screen::drawImpl(Rectangle*r)
{
	sortRect(r);
    Rectangle tmp;
    tmp.setColor(*r);
    tmp.setPoint(*r);
    tmp.setEndPoint(r->getEndPoint());
    tmp.setHeight(1);
    fillImpl(&tmp);

    tmp.move(180,r -> getHeight()-1);
    fillImpl(&tmp);

    tmp.setY(r -> getY()+1);
    tmp.setWidth(1);
    tmp.setHeight(r -> getHeight()-2);
    fillImpl(&tmp);

    tmp.move(90,r -> getWidth()-1);
    fillImpl(&tmp);
}

void Screen::drawImpl(Dot* d)
{
    Rectangle r;
    r.setPoint(*d);
    r.setEndPoint(*d);
    r.setColor(*d);
    fillImpl(&r);
}

void Screen::drawImpl(Line* l)
{
    int16_t x0 = l->getX()
                 , y0 = l->getY()
                 , x1 = l->getEndX()
                 , y1 = l->getEndY();

    if ( ( x0==x1 )
            || ( y0==y1) )
    {
        Rectangle rect;
        rect.setPoint(*l);
        rect.setEndPoint(x1, y1);
        rect.setColor(*l);
        fillImpl(&rect);
        return;
    }

    bool steep = abs( y1-y0 )
                 > abs( x1-x0 );
    if (steep)
    {
        swap(x0, y0);
        swap(x1, y1);
    }

    if (x0 > x1)
    {
        swap(x0, x1);
        swap(y0, y1);
    }

    int16_t deltaX = x1 - x0;
    int16_t deltaY = abs( y1-y0 );
    int16_t error = deltaX / 2;

    uint16_t y = y0;

    uint16_t ystep
        = y0 < y1 ? 1 :- 1;

    Dot d;
    d.setColor(*l);

    for (int16_t x = x0; x<=x1; x++)
    {
        if (steep)
        {
            d.setPoint(y, x);
        }
        else
        {
            d.setPoint(x, y);
        }
        drawImpl(&d);
        error -= deltaY;

        if (error < 0)
        {
            y += ystep;
            error += deltaX;
        }
    }
}



void Screen::fillImpl(BufferScreen* buf)
{
    uint8_t scale = buf->getScale();

    if ( ! scale )
    {
        return ;
    }

    uint16_t w = buf -> getWidth (),
             h = buf -> getHeight(),
             x = buf -> getX(),
             y = buf -> getY();

    uint16_t *data = buf -> getData(), *col;

    Dot d;
    for ( uint16_t _y = 0; _y<h; _y++ )
    {
        for ( uint8_t sy = 0 ; sy < scale ; sy++ )
        {
            col = data ;
            for ( uint16_t _x = 0 ; _x < w; _x++ )
            {
                for (uint8_t sx = 0; sx < scale; sx ++ )
                {
                    d.setPoint (_x*scale+sx+x,_y*scale+sy+y);
                    d.setColor(*col);
                    drawImpl(&d);
                }
                col++;
            }
        }
        data += w;
    }

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

        fillImpl (bScr) ;

        f->setPoint(*bScr);

        delete bScr ;

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

void Screen::drawImpl(Circle* c)
{
	uint16_t r = c -> getRadius ( ) ;
	int16_t xc = c -> getX ( ), yc = c -> getY ( )
		, x = 0, y = r, d = 3-2*r;

	Dot dot;
	dot.setColor ( *c ) ;

	dot.setPoint(xc+r, yc); drawImpl(&dot);
	dot.setPoint(xc-r, yc); drawImpl(&dot);
	dot.setPoint(xc, yc+r); drawImpl(&dot);
	dot.setPoint(xc, yc-r); drawImpl(&dot);

	while (y >= x++) 
	{
		if (d > 0) 
        { 
            y--;  
            d += 4 * (x - y) + 10; 
        } 
        else
		{
			d += 4 * x + 6;
		}

		dot.setPoint(xc+x, yc+y); drawImpl(&dot); 
		dot.setPoint(xc-x, yc+y); drawImpl(&dot); 
		dot.setPoint(xc+x, yc-y); drawImpl(&dot);
		dot.setPoint(xc-x, yc-y); drawImpl(&dot);
		dot.setPoint(xc+y, yc+x); drawImpl(&dot);
		dot.setPoint(xc-y, yc+x); drawImpl(&dot);
		dot.setPoint(xc+y, yc-x); drawImpl(&dot);
		dot.setPoint(xc-y, yc-x); drawImpl(&dot);
	}
}

void Screen::fillImpl(Circle* c)
{	
    uint16_t r = c->getRadius();

    if ( ! r )
    {
        return ;
    }

    if ( r == 1 )
    {
        Dot d ;
        d.setPoint(*c);
        drawImpl(&d);
        return ;
    }

	int x = c -> getX ( )
		, y = c -> getY ( )
		, _y = 0;

	uint32_t sqr = r;
	sqr *= r ;

	Line l;
	l.setColor ( *c );
	l.setPoint ( *c ) ;
	l.move ( 270 , r-1 );
	l.lineTo ( 90 , r+r-2 );
	drawImpl ( &l ) ;

	while ( _y ++ < r - 1 ) {
		uint32_t sqrY = _y;
		sqrY *= _y ;
		
		uint32_t _x = sqr ;
		_x -= sqrY ;
		_x = sqrt ( _x ) ;
		
		l.setPoint ( -_x + x , _y + y );
		l.setEndPoint ( _x + x, _y + y );
		drawImpl ( &l );
        l.setY(y-_y);
        l.setEndY(y-_y);
        drawImpl(&l) ;
	}
}

void Screen::drawImpl(Triangle* t)
{
    Line l;
    l.setColor(*t);
    l.setPoint(*t);
    l.setEndPoint (t->getP2());
    drawImpl ( &l);
    l.setEndPoint (t->getP3());
    drawImpl ( &l);
    l.setPoint(t->getP2());
    drawImpl ( &l);
}

void Screen::fillImpl(Triangle* t)
{
    int16_t x0 = t->getX(), y0 = t-> getY(),
            x1 = t->getP2().getX(), y1 = t->getP2().getY(),
            x2 = t->getP3().getX(), y2 = t->getP3().getY(),
            a, b, y, last;

    Line l;
    l.setColor (*t);

    if (y0 > y1)
    {
        swap(y0, y1);
        swap(x0, x1);
    }
    if (y1 > y2)
    {
        swap(y2, y1);
        swap(x2, x1);
    }
    if (y0 > y1)
    {
        swap(y0, y1);
        swap(x0, x1);
    }

    if (y0 == y2)
    {
        a = b = x0;
        if (x1 < a)
            a = x1;
        else if (x1 > b)
            b = x1;
        if (x2 < a)
            a = x2;
        else if (x2 > b)
            b = x2;

        l.setPoint (a, y0);
        l.lineTo ( 90,b - a + 1 ) ;
        drawImpl(&l);
        return;
    }

    int16_t dx01 = x1 - x0, dy01 = y1 - y0, dx02 = x2 - x0, dy02 = y2 - y0,
            dx12 = x2 - x1, dy12 = y2 - y1;
    int32_t sa = 0, sb = 0;

    if (y1 == y2)
        last = y1;
    else
        last = y1 - 1;

    for (y = y0; y <= last; y++)
    {
        a = x0 + sa / dy01;
        b = x0 + sb / dy02;
        sa += dx01;
        sb += dx02;

        if (a > b)
            swap(a, b);
        l.setPoint (a, y);
        l.lineTo ( 90,b - a + 1 ) ;

        drawImpl(&l);
    }

    sa = (int32_t)dx12 * (y - y1);
    sb = (int32_t)dx02 * (y - y0);
    for (; y <= y2; y++)
    {
        a = x1 + sa / dy12;
        b = x0 + sb / dy02;
        sa += dx12;
        sb += dx02;

        if (a > b)
            swap(a, b);

        l.setPoint (a, y);
        l.lineTo ( 90,b - a + 1 ) ;

        drawImpl(&l);
    }
}

void Screen::drawImpl(Ellipse* e) {
	int16_t cx = e -> getX ( ),
		cy = e -> getY ( ),
		rx = e -> getRx ( ),
		ry = e -> getRy ( );

	if ( ! rx ) { return ; }
	if ( ! ry ) { return ; }

	int32_t x, y,
		xChange, yChange,
		error, aSqr, bSqr, sx, sy, cond;
		
	aSqr = (int32_t)2 * rx * rx ;
	bSqr = (int32_t)2 * ry * ry ;

	x = rx ;
	y = 0 ;

	xChange = 1 - 2*rx ; xChange *= ry; xChange *= ry;
	yChange = (int32_t) rx * rx ;
	error = 0;
	sx = (int32_t)bSqr * rx ;
	sy = 0;

	Dot d;
	d.setColor ( *e );

	while ( sx >= sy ) {
		d.setPoint ( cx+x, cy+y ); drawImpl ( &d );
		d.setPoint ( cx-x, cy+y ); drawImpl ( &d );
		d.setPoint ( cx-x, cy-y ); drawImpl ( &d );
		d.setPoint ( cx+x, cy-y ); drawImpl ( &d );
		
		y++ ;
		sy += aSqr ;
		error += yChange ;
		yChange += aSqr ;

		cond = error; cond *= 2; cond += xChange;
		if ( cond > 0 ) {
			x --;
			sx -= bSqr ;
			error += xChange ;
			xChange += bSqr ;
		}
	}
	
	x = 0;
	y = ry;
	xChange = (int32_t)ry * ry;
	yChange = 1 - 2*ry ; yChange *= rx; yChange *= rx;
	error = 0;
	sx = 0;
	sy = (int32_t)aSqr * ry ;

	while ( sx <= sy ) {
		d.setPoint ( cx+x, cy+y ); drawImpl ( &d );
		d.setPoint ( cx-x, cy+y ); drawImpl ( &d );
		d.setPoint ( cx-x, cy-y ); drawImpl ( &d );
		d.setPoint ( cx+x, cy-y ); drawImpl ( &d );
		
		x++;
		sx += bSqr;
		error += xChange;
		xChange += bSqr;
		
		cond = error; cond *= 2; cond += yChange;
		if ( cond > 0 ) {
			y --;
			sy -= aSqr ;
			error += yChange ;
			yChange += aSqr ;
		}
	}
}

void Screen::fillImpl(Ellipse* e) {
	int16_t cx = e -> getX ( ),
		cy = e -> getY ( ),
		rx = e -> getRx ( ),
		ry = e -> getRy ( );

	if ( ! rx ) { return ; }
	if ( ! ry ) { return ; }

	int32_t x, y,
		xChange, yChange,
		error, aSqr, bSqr, sx, sy, cond;
		
	aSqr = (int32_t)2 * rx * rx ;
	bSqr = (int32_t)2 * ry * ry ;

	x = rx ;
	y = 0 ;

	xChange = 1 - 2*rx ; xChange *= ry; xChange *= ry;
	yChange = (int32_t) rx * rx ;
	error = 0;
	sx = (int32_t)bSqr * rx ;
	sy = 0;

	Line l;
	l.setColor ( *e );

	while ( sx >= sy ) {
		l.setPoint ( cx+x, cy+y );
		l.setEndPoint ( cx-x, cy+y );
		drawImpl ( &l );

		l.setPoint ( cx-x, cy-y );
		l.setEndPoint ( cx+x, cy-y );
		drawImpl ( &l );
		
		y++ ;
		sy += aSqr ;
		error += yChange ;
		yChange += aSqr ;

		cond = error; cond *= 2; cond += xChange;
		if ( cond > 0 ) {
			x --;
			sx -= bSqr ;
			error += xChange ;
			xChange += bSqr ;
		}
	}
	
	x = 0;
	y = ry;
	xChange = (int32_t)ry * ry;
	yChange = 1 - 2*ry ; yChange *= rx; yChange *= rx;
	error = 0;
	sx = 0;
	sy = (int32_t)aSqr * ry ;

	while ( sx <= sy ) {
		l.setPoint ( cx+x, cy+y );
		l.setEndPoint ( cx-x, cy+y );
		drawImpl ( &l );

		l.setPoint ( cx-x, cy-y );
		l.setEndPoint ( cx+x, cy-y );
		drawImpl ( &l );
		
		x++;
		sx += bSqr;
		error += xChange;
		xChange += bSqr;
		
		cond = error; cond *= 2; cond += yChange;
		if ( cond > 0 ) {
			y --;
			sy -= aSqr ;
			error += yChange ;
			yChange += aSqr ;
		}
	}
}
