void drawRectTest ( ) {
	scr -> setColor ( 0 ) ;
    scr -> setCursor ( 18,24 );
	scr -> clear ( ) ;

	scr -> print ( "Draw 1000 rectangles randomly..." ) ;

	unsigned long elapsed = millis ( ) ;
	
	uint16_t w = scr -> getWidth ( ),
		h = scr -> getHeight ( );

	Rectangle r;

	for ( int i = 0; i < 1000; i ++ ) {
		r.setColor ( random ( 0xFFFF ) ) ;
		r.setPoint ( random ( w ), random ( h ) ) ;
		r.setEndPoint ( random ( w ), random ( h ) ) ;
		r.draw ( scr ) ;
	}

	elapsed = millis ( ) - elapsed ;

	scr -> resetCursor ( ) ;
	scr -> println ( "Draw 1000 rectangles randomly..." ) ;
	scr -> print ( "Time elapsed: " ) ;
	scr -> print ( elapsed / 1000.0, 2 ) ;
	scr -> print ( "secs." ) ;
	delay ( 3000 ) ;
}
