void allColorTest ( ) {
	scr -> setColor ( 0 ) ;
  scr -> setCursor ( 18,24 );
	scr -> clear ( ) ;

	scr -> println ( "All color test..." ) ;

	unsigned long elapsed = millis ( ) ;

  Line l;
  l.setY ( 60 );
  l.lineTo ( 90,80 ) ;

  for ( int i = 0; i < 255; i ++ ) {
    l.setR ( i ) ;
    l.draw ( scr ) ;
    l.move ( 180 , 1 ) ;
  }

  l.setY ( 60 );
  l.move ( 90, 80 ) ;
  l.lineTo ( 90,80 ) ;

  for ( int i = 0; i < 255; i ++ ) {
    l.setR ( i ) ;
    l.setG ( i ) ;
    l.draw ( scr ) ;
    l.move ( 180 , 1 ) ;
  }

  l.setY ( 60 );
  l.move ( 90, 80 ) ;
  l.lineTo ( 90,80 ) ;
  l.setColor ( 0 ) ;

  for ( int i = 0; i < 255; i ++ ) {
    l.setG ( i ) ;
    l.draw ( scr ) ;
    l.move ( 180 , 1 ) ;
  }

  l.setY ( 60 );
  l.move ( 90, 80 ) ;
  l.lineTo ( 90,80 ) ;

  for ( int i = 0; i < 255; i ++ ) {
    l.setG ( i ) ;
    l.setB ( i ) ;
    l.draw ( scr ) ;
    l.move ( 180 , 1 ) ;
  }

  l.setY ( 60 );
  l.move ( 90, 80 ) ;
  l.lineTo ( 90,80 ) ;
  l.setColor ( 0 ) ;

  for ( int i = 0; i < 255; i ++ ) {
    l.setB ( i ) ;
    l.draw ( scr ) ;
    l.move ( 180 , 1 ) ;
  }

  l.setY ( 60 );
  l.move ( 90, 80 ) ;
  l.lineTo ( 90,80 ) ;

  for ( int i = 0; i < 255; i ++ ) {
    l.setB ( i ) ;
    l.setR ( i ) ;
    l.draw ( scr ) ;
    l.move ( 180 , 1 ) ;
  }

	elapsed = millis ( ) - elapsed ;

	scr -> print ( "Time elapsed: " ) ;
	scr -> print ( elapsed / 1000.0, 2 ) ;
	scr -> print ( "secs." ) ;
	delay ( 3000 ) ;
}
