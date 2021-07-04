void testDrawFont ( ) {
	scr -> setColor ( 0 ) ;
    scr -> clear ( ) ;

    scr -> setCursor ( 18,24 );
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

    delay(3000);
}
