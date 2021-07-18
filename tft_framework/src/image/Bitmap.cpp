#include "tft_framework.h"
using namespace tft_framework;

uint32_t Bitmap::_rev ( byte *ptr, uint8_t len ) {
	uint32_t hex = 0 ;

	for ( int i = 0 ; i < len; i ++ ) {
		
		hex += (uint32_t)ptr [i] << i*8;
	}
	return hex;
}

Bitmap::Bitmap(File &f):Image(f){
	bm = false;

	byte header[14];
	f.read(header,14);

	if ( header [0] != 'B' ) { return ; }
	if ( header [1] != 'M' ) { return ; }

	uint32_t fileSize = _rev ( header + 2 , 4 );
	if ( fileSize != f.size()) { return ;}

	dataOffset = _rev ( header + 10 , 4 );

	byte meta[dataOffset - 14]; 
	f.read(meta,dataOffset - 14);

	if ( _rev ( meta , 4 ) + 14 != dataOffset ) { return ; }

	width = _rev ( meta + 4, 4 );
	height = _rev ( meta + 8, 4 );
	colorDepth = meta [14];

	viewport.setSize ( width, height);
	bm = true ;
}

void Bitmap::fill(Screen *scr) {
	if ( ! bm ) { return ; }

	scr -> fillShape ( this ) ;
}

void Bitmap::fillGeneric(Screen *scr) {
	Rectangle viewport = getViewport ( ) ;

	if ( ! sortRect ( &viewport, this ) ) { return ; }
	viewport.move ( 90 , getX ( ) ) ;
	viewport.move ( 180 , getY ( ) ) ;
	if ( ! sortRect ( &viewport, scr ) ) { return ; }

	uint16_t viewW = viewport.getWidth ( );

	int16_t viewX = viewport.getX ( ),
		viewY = viewport.getY ( ),
		viewEndY = viewport.getEndY ( ),
		imgX = getX ( ),
		imgW = getWidth ( ) ;

	Dot d ;

	BufferScreen *buf = new BufferScreen ( viewW, 1 ) ;
	buf -> setX ( viewX ) ;

	uint16_t bufLength = viewW * 3 ;
	byte bytes[ bufLength ] ;

	File f = getFile ( ) ;
	f.seek ( dataOffset + ( getY ( ) + getHeight ( ) - viewEndY - 1 ) * imgW * 3 )   ;

	for ( int16_t y = viewEndY; y >= viewY; y -- ) {
		f.seek ( f.position ( ) + ( viewX - imgX ) * 3 ) ;
		f.read ( bytes , bufLength ) ;

		for ( int16_t x = 0; x < viewW ; x ++ ) {
			d.setX ( x ) ;
			d.setB ( bytes [ x*3 ] ) ;
			d.setG ( bytes [ x*3 + 1 ] ) ;
			d.setR ( bytes [ x*3 + 2 ] ) ;
			d.draw ( buf ) ;
		}

		buf -> setY ( y ) ;
		buf -> fill ( scr ) ;
		
		f.seek ( f.position ( ) + ( imgX + imgW - viewX - viewW ) * 3 ) ;
	}

	delete buf ;
}

uint32_t Bitmap::getDataOffset ( ) {
	return dataOffset;
}