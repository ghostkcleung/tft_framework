void hello(){
	scr -> setFontScale ( 3 ) ;
    scr -> setCursor ( 18,24 );
	scr -> clear ( ) ;

	scr -> println ( "Hello, I am ..." );
	scr -> println (

#ifdef __AVR_ATmega2560__
	"Arduino Mega 2560"
#endif

#ifdef __SAM3X8E__
	"Arduino Due"
#endif

#ifdef ESP32
  "ESP32"
#endif

	) ;
	
	scr -> setFontScale ( 2 );

	delay ( 3000 ) ;
}
