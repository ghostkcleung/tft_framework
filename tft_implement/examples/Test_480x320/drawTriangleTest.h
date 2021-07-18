void drawTriangleTest ( ) {
	scr -> setColor ( 0 ) ;
    scr -> setCursor ( 18,24 );
	scr -> clear ( ) ;

	scr -> println ( "Draw 50 triangles randomly..." ) ;

	unsigned long elapsed = millis ( ) ;
	
	uint16_t w = scr -> getWidth ( ),
		h = scr -> getHeight ( );

	Triangle t;

	for ( int i = 0; i < 50; i ++ ) {
		t.setColor ( random ( 0xFFFF ) ) ;
		t.setPoint ( random ( w ), random ( h ) ) ;
		t.setP2 ( random ( w ), random ( h ) ) ;
		t.setP3 ( random ( w ), random ( h ) ) ;
		t.draw ( scr ) ;
	}

	elapsed = millis ( ) - elapsed ;

	scr -> print ( "Time elapsed: " ) ;
	scr -> print ( elapsed / 1000.0, 2 ) ;
	scr -> print ( "secs." ) ;
	delay ( 3000 ) ;
}
