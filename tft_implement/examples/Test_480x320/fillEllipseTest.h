void fillEllipseTest ( ) {
	scr -> setColor ( 0 ) ;
    scr -> setCursor ( 18,24 );
	scr -> clear ( ) ;

	scr -> print ( "Fill 50 ellipses randomly..." ) ;

	unsigned long elapsed = millis ( ) ;
	
	uint16_t w = scr -> getWidth ( ),
		h = scr -> getHeight ( ),
		rx = w / 2,
		ry = h / 2 ;

	Ellipse e;

	for ( int i = 0; i < 50; i ++ ) {
		e.setColor ( random ( 0xFFFF ) ) ;
		e.setPoint ( random ( w ), random ( h ) ) ;
		e.setRx ( random ( rx ) ) ;
		e.setRy ( random ( ry ) ) ;
		e.fill ( scr ) ;
	}

	elapsed = millis ( ) - elapsed ;

	scr -> resetCursor ( ) ;
	scr -> println ( "Fill 50 ellipses randomly..." ) ;
	scr -> print ( "Time elapsed: " ) ;
	scr -> print ( elapsed / 1000.0, 2 ) ;
	scr -> print ( "secs." ) ;
	delay ( 3000 ) ;
}
