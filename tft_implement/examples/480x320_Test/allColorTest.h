void allColorTest ( ) {
	scr -> setColor ( 0 ) ;
    scr -> setCursor ( 18,24 );
	scr -> clear ( ) ;

	scr -> println ( "All color test..." ) ;

	unsigned long elapsed = millis ( ) ;
	
	Dot d;
	int color = 0;

	for ( int y = 60; y < 316 ; y ++ ) {
    for ( int x = 60; x < 316 ; x ++ ) {
      d.setColor ( color ++ ) ;
      d.setPoint ( x, y );
      d.draw ( scr ) ;
    }
	}

	elapsed = millis ( ) - elapsed ;

	scr -> print ( "Time elapsed: " ) ;
	scr -> print ( elapsed / 1000.0, 2 ) ;
	scr -> print ( "secs." ) ;
	delay ( 3000 ) ;
}
