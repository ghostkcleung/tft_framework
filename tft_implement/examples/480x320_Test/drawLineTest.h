void drawLineTest ( ) {
	scr -> setColor ( 0 ) ;
    scr -> setCursor ( 18,24 );
	scr -> clear ( ) ;

	scr -> println ( "Draw 200 lines randomly..." ) ;

	unsigned long elapsed = millis ( ) ;
	
	uint16_t w = scr -> getWidth ( ),
		h = scr -> getHeight ( );

	Line l;

	for ( int i = 0; i < 200; i ++ ) {
		l.setColor ( random ( 0xFFFF ) ) ;
		l.setPoint ( random ( w ), random ( h ) ) ;
		l.setEndPoint ( random ( w ), random ( h ) ) ;
		l.draw ( scr ) ;
	}

	elapsed = millis ( ) - elapsed ;

	scr -> print ( "Time elapsed: " ) ;
	scr -> print ( elapsed / 1000.0, 2 ) ;
	scr -> print ( "secs." ) ;
	delay ( 3000 ) ;
}
