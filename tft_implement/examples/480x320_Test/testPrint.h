void testPrint ( ) {
	scr -> clear ( ) ;
    scr -> resetCursor ( ) ;

    for ( int i = 1; i<=6; i++ )
    {
        scr->setFontScale(i);
        scr->println("println test");
    }
    delay ( 3000 ) ;
}