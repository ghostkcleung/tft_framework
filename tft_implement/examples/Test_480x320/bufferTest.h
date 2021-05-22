void bufferTest ( ) {
	scr -> setColor ( 0 ) ;
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
            d.setColor((uint32_t)random(0xFFFF));
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
            d.setColor((uint32_t)random(0xFFFF));
            d.draw(buf);
            d.move(90,1);
        }
        d.move(180,1);
    }

    buf -> fill ( scr ) ;

    delete ( buf ) ;

	delay ( 3000 ) ;
}
