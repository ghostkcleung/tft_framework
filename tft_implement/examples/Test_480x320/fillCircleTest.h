void fillCircleTest ( ) {
	scr -> setColor ( 0 ) ;
    scr -> setCursor ( 18,24 );
	scr -> clear ( ) ;

	scr -> print ( "Fill 50 circles randomly..." ) ;

	unsigned long elapsed = millis ( ) ;
	
	uint16_t w = scr -> getWidth ( ),
		h = scr -> getHeight ( ),
		r = h / 2 ;

	Circle c;

	for ( int i = 0; i < 50; i ++ ) {
		c.setColor ( random ( 0xFFFF ) ) ;
		c.setPoint ( random ( w ), random ( h ) ) ;
		c.setRadius ( random ( r ) ) ;
		c.fill ( scr ) ;
	}

	elapsed = millis ( ) - elapsed ;

	scr -> resetCursor ( ) ;
	scr -> println ( "Fill 50 circles randomly..." ) ;
	scr -> print ( "Time elapsed: " ) ;
	scr -> print ( elapsed / 1000.0, 2 ) ;
	scr -> print ( "secs." ) ;
	delay ( 3000 ) ;
}
