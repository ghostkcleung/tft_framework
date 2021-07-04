#include "tft_framework.h"
using namespace tft_framework;

uint32_t Bitmap::_rev ( byte *ptr, uint8_t len ) {
	uint32_t hex = 0 ;
	for ( int i = 0 ; i < len; i ++ ) {
		hex += ptr [i] << i*8;
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

	bm = true ;
}

void Bitmap::fill(Screen *scr) {
	uint8_t rotate = scr -> getRotate ( ) ;
	scr -> setRotate ( ( rotate + 5 ) % 8 ) ;
	scr -> fillShape ( this ) ;
	scr -> setRotate ( rotate ) ;
}

void Bitmap::fillGeneric(Screen *scr) {
	File f = getFile ( ) ;
	f.seek ( dataOffset ) ;
	Dot d;

	byte bytes[ width * 3 ] ;
	BufferScreen *buf = new BufferScreen ( width, 1 ) ;

	for ( uint16_t y = 0; y < height; y ++ ) {
		f.read ( bytes, width * 3 ) ;
		for ( uint16_t x = 0; x < width; x ++ ) {
			d.setX ( x ) ;
			d.setB ( bytes [x*3] );
			d.setG ( bytes [x*3+1] );
			d.setR ( bytes [x*3+2] );
			d.draw ( buf ) ;
		}
		buf -> setY ( y ) ;
		buf -> fill ( scr ) ;
	}
}

uint32_t Bitmap::getDataOffset ( ) {
	return dataOffset;
}
