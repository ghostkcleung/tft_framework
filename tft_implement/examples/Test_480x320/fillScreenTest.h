void fillScreenTest ( ) {
	scr -> setColor ( 0 ) ;
    scr -> setCursor ( 18,24 );
	scr -> clear ( ) ;

	scr -> print ( "Fill screen test..." ) ;
	delay ( 2000 ) ;

	uint32_t rgb[8] = {
		0xFFFFFF, 0xFFFF00, 0xFF00FF, 0xFF0000,
		0x00FFFF, 0x00FF00, 0x0000FF, 0x000000
	};

	unsigned long elapsed = millis ( ) ;
	
	for ( int i = 0; i < 8; i ++ ) {
		scr -> setRotate(i);
		scr -> setRGB ( rgb [ i ] ) ;
		scr -> clear ( ) ;
	}

	elapsed = millis ( ) - elapsed ;

	scr -> setRotate(0);	
	scr -> println ( "Filled screen for 8 times" ) ;
	scr -> print ( "Time elapsed: " ) ;
	scr -> print ( elapsed / 1000.0, 2 ) ;
	scr -> print ( "secs." ) ;
	delay ( 3000 ) ;
}
