#include <Mega2560_16Bit_ILI9486.h>

using namespace tft_framework;

Screen* scr;

void setup()
{
    randomSeed(analogRead(A0));

    scr = new Mega2560_16Bit_ILI9486 ( ) ;
    scr -> init();
    scr -> setRotate(0);
    scr -> setFontPadding ( 1 ) ;
    scr -> setCursor ( 18,24 );
    scr -> setPrintBuffer ( true ) ;
}

void testFillFullScreen()
{

    scr -> setColor(0);
    scr -> clear ( ) ;
    scr -> setFontScale ( 2 ) ;
    scr -> resetCursor ( ) ;
    scr -> println("Fill screen test...");

    uint32_t rgb[] =
    {
        0xFFFFFF, 0xFFFF00, 0xFF00FF, 0xFF0000,
        0x00FFFF, 0x00FF00, 0x0000FF, 0x000000
    };

    delay ( 3000 ) ;

    uint8_t rotate=0;
    for ( int i = 0; i < 8; i ++ )
    {
        scr -> setRGB ( rgb [i] ) ;
        scr -> setRotate(rotate++);
        scr -> clear ( ) ;
        rotate %= 4 ;
    }

    scr -> setRotate ( 0 ) ;
}

void testDrawDot()
{
    scr -> setColor ( 0 ) ;
    scr -> clear ( ) ;

    Dot d;
    for ( int i = 0 ; i < 1000; i ++ )
    {
        d.setPoint(random(480),random(320));
        d.setColor((uint32_t)random(0xFFFF)+1);
        d.draw ( scr ) ;
    }

    scr -> resetCursor ( ) ;
    scr -> println ( "Drawn 1000 dots randomly." ) ;
    delay ( 5000 ) ;
}

void testDrawLine()
{
    scr -> clear ( ) ;

    Line l ;
    for ( int i = 0 ; i < 100; i ++ )
    {
        l.setPoint(random(480),random(320));
        l.setEndPoint(random(480),random(320));
        l.setColor((uint32_t)random(0xFFFF)+1);
        l.draw ( scr ) ;
    }

    scr -> resetCursor ( ) ;
    scr -> println ( "Drawn 100 lines randomly." ) ;
    delay ( 5000 ) ;
}

void testDrawRect ( )
{
    scr -> clear ( ) ;

    Rectangle r;
    for ( int i = 0 ; i < 100; i ++ )
    {
        r.setPoint(random(480),random(320));
        r.setEndPoint(random(480),random(320));
        r.setColor((uint32_t)random(0xFFFF)+1);
        r.draw(scr);
    }

    scr -> resetCursor ( ) ;
    scr -> println ( "Drawn 100 rectangles randomly." ) ;
    delay(5000);
}

void testFillRect ( )
{
    scr -> clear ( ) ;
    Rectangle r;
    for ( int i = 0 ; i < 50; i ++ )
    {
        r.setPoint(random(480),random(320));
        r.setEndPoint(random(480),random(320));
        r.setColor((uint32_t)random(0xFFFF)+1);
        r.fill(scr);
    }

    scr -> resetCursor ( ) ;
    scr -> println ( "Filled 50 rectangles randomly." ) ;
    delay ( 5000 ) ;
}

void testAllColor()
{
    scr -> clear ( ) ;
    scr -> resetCursor ( ) ;
    scr -> println ( "Show all color..." ) ;

    Line l;
    l.setPoint ( 183, 40 ) ;
    l.lineTo ( 180,80 ) ;
    for ( int r=0; r < 255; r ++ )
    {
        l.setR ( r ) ;
        l.draw ( scr ) ;
        l.move ( 90, 1 ) ;
    }

    l.setPoint ( 183, 120 ) ;
    l.lineTo ( 180,80 ) ;
    l.setColor ( 0 ) ;
    for ( int g=0; g < 255; g ++ )
    {
        l.setG ( g ) ;
        l.draw ( scr ) ;
        l.move ( 90, 1 ) ;
    }

    l.setPoint ( 183, 200 ) ;
    l.lineTo ( 180,80 ) ;
    l.setColor ( 0 ) ;
    for ( int b=0; b < 255; b ++ )
    {
        l.setB ( b ) ;
        l.draw ( scr ) ;
        l.move ( 90, 1 ) ;
    }

    delay ( 5000 ) ;
}

void testBuffer()
{
    scr -> clear ( ) ;

    scr -> resetCursor ( ) ;
    Point tmp = scr -> getCursor ( ) ;

    scr -> setCursor ( 137, 92 );
    scr -> print ( "Draw dot directly" ) ;

    scr -> setCursor ( 187, 212 );
    scr -> println ( "Draw to buffer." ) ;
    scr -> println ( "Enlarge to 2x." ) ;

    scr -> setCursor ( tmp ) ;

    Dot d;
    d.setY(75);
    for ( int y = 0 ; y < 50 ; y ++ )
    {
        d.setX(75);
        for ( int x = 0 ; x < 50 ; x ++ )
        {
            d.setColor((uint32_t)random(0xFFFF)+1);
            d.draw(scr);
            d.move(90,1);
        }
        d.move(180,1);
    }

    BufferScreen* buf = new BufferScreen(50,50);
    buf -> setScale ( 2 ) ;
    buf -> setPoint ( 75, 175 );

    d.setY(0);
    for ( int y = 0 ; y < 50 ; y ++ )
    {
        d.setX(0);
        for ( int x = 0 ; x < 50 ; x ++ )
        {
            d.setColor((uint32_t)random(0xFFFF)+1);
            d.draw(buf);
            d.move(90,1);
        }
        d.move(180,1);
    }

    buf -> fill ( scr ) ;

    delete ( buf ) ;
    delay ( 5000 ) ;
}

void testDrawFont ( )
{
    scr -> clear ( ) ;

    scr -> resetCursor ( ) ;
    scr -> print ( "Show all text" ) ;

    Font5X7 f;
    f.setColor ( 0xFFFF ) ;
    f.setPoint(15,53);
    f.setScale ( 2 ) ;

    for ( char ch = 33; ch < 126; ch++ )
    {
        f.setChar ( ch ) ;
        f.draw ( scr ) ;
        f.move ( 90, 18 );

        if ( ch % 10 == 0 )
        {
            f.move ( 180, 24 );
            f.setX ( 15 ) ;
        }
    }

    delay(5000);
}

void testPrint()
{
    scr -> clear ( ) ;
    scr -> resetCursor ( ) ;
    for ( int i = 1; i<=6; i++ )
    {
        scr->setFontScale(i);
        scr->println("println test");
    }
    delay ( 5000 ) ;
}

void testDrawCircle ( )
{
    scr -> clear ( ) ;

    Circle c;
    for ( int i = 0 ; i < 50; i ++ )
    {
        c.setPoint(random(480),random(320));
        c.setRadius(random(160));
        c.setColor((uint32_t)random(0xFFFF)+1);
        c.draw(scr);
    }

    scr -> resetCursor ( ) ;
    scr -> println ( "Drawn 50 circles randomly." ) ;
    delay(5000);
}

void testFillCircle ( )
{
    scr -> clear ( ) ;

    Circle c;
    for ( int i = 0 ; i < 50; i ++ )
    {
        c.setPoint(random(480),random(320));
        c.setRadius(random(160));
        c.setColor((uint32_t)random(0xFFFF)+1);
        c.fill(scr);
    }

    scr -> resetCursor ( ) ;
    scr -> println ( "Filled 50 circles randomly." ) ;
    delay(5000);
}


void testDrawTriangle ( )
{
    scr -> clear ( ) ;

    Triangle t;
    for ( int i = 0 ; i < 50; i ++ )
    {
        t.setPoint(random(480),random(320));
        t.setP2(Point(random(480),random(320)));
        t.setP3(Point(random(480),random(320)));
        t.setColor((uint32_t)random(0xFFFF)+1);
        t.draw(scr);
    }

    scr -> resetCursor ( ) ;
    scr -> println ( "Drawn 50 triangles randomly." ) ;
    delay(5000);
}

void testFillTriangle ( )
{
    scr -> clear ( ) ;

    Triangle t;
    for ( int i = 0 ; i < 50; i ++ )
    {
        t.setPoint(random(480),random(320));
        t.setP2(Point ( random(480),random(320)));
        t.setP3(Point(random(480),random(320)));
        t.setColor((uint32_t)random(0xFFFF)+1);
        t.fill(scr);
    }

    scr -> resetCursor ( ) ;
    scr -> println ( "Filled 50 triangles randomly." ) ;
    delay(5000);
}

void loop()
{
    testFillFullScreen();
    testDrawDot();
    testDrawLine();
    testDrawRect();
    testFillRect();
    testDrawCircle();
    testFillCircle();
    testDrawTriangle();
    testFillTriangle();
    testAllColor();
    testBuffer();
    testDrawFont();
    testPrint();
    delay(2000);

}
