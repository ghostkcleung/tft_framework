void drawDotTest ( ) {
	scr -> setColor ( 0 ) ;
    scr -> setCursor ( 18,24 );
	scr -> clear ( ) ;

	scr -> println ( "Draw 5000 dots randomly..." ) ;

	unsigned long elapsed = millis ( ) ;
	
	Dot d;

	uint16_t w = scr -> getWidth ( ),
	  h = scr -> getHeight ( );

	for ( int i = 0; i < 5000; i ++ ) {
		d.setColor ( random ( 0xFFFF ) ) ;
		d.setPoint ( random ( w ), random ( h ) ) ;
		d.draw ( scr ) ;
	}

	elapsed = millis ( ) - elapsed ;

	scr -> print ( "Time elapsed: " ) ;
	scr -> print ( elapsed / 1000.0, 2 ) ;
	scr -> print ( "secs." ) ;
	delay ( 3000 ) ;
}
