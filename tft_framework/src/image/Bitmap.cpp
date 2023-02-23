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


	width = _rev ( meta + 4, 4 );
	height = _rev ( meta + 8, 4 );
	colorDepth = meta [14];

	viewport.setSize (width, height);
	bm = true ;
}

void Bitmap::fill(Screen *scr) {
	if ( ! bm ) { return ; }
	scr -> fillShape ( this ) ;
}

void Bitmap::fillGeneric(Screen *scr) {

	Rectangle window = viewport = getViewport ( );

	if ( ! sortRect ( &window, this ) ) { return ; }

	window.moveTo ( *this ) ;
	if ( ! sortRect ( &window, scr ) ) { return ; }

	viewport.setSize ( window );

	uint8_t bytePerPixel = colorDepth / 8 ;

	uint16_t winW = window.getWidth ( )
		, imgW = getWidth ( )
		, bufSize = winW * bytePerPixel ;

	int16_t winX = window.getX ( )
		, winY = window.getY ( )
		, winEndY = window.getEndY ( )
		, viewX = viewport.getX ( ) ;

	Dot d;

	if ( colorDepth > 15 ) {
		BufferScreen *buf = new BufferScreen ( winW, 1 ) ;
		buf -> setX ( winX ) ;

		byte bytes[ bufSize ] ;

		File f = getFile ( ) ;
		f.seek ( dataOffset + ( getHeight ( ) - window.getHeight ( )
			- viewport.getY ( ) ) * imgW * bytePerPixel ) ;

		for ( int16_t y = winEndY; y >= winY; y -- ) {
			f.seek ( f.position ( ) + viewX * bytePerPixel ) ;
			f.read ( bytes, bufSize ) ;

			for ( int x = 0; x < winW; x ++ ) {
				d.setX ( x ) ;

				switch ( bytePerPixel ) {
					case 2:
					d.setColor ( bytes [x*2+1] << 8 | bytes [x*2] ) ;
					break;

					case 3:
					d.setB ( bytes[x*3] ) ;
					d.setG ( bytes[x*3+1] ) ;
					d.setR ( bytes[x*3+2] ) ;
					break;
				}
			
				d.draw ( buf ) ;
			}

			buf -> setY ( y ) ;
			buf -> fill ( scr ) ;
			f.seek ( f.position ( ) + ( imgW - viewX - winW ) * bytePerPixel ) ;
		}

		delete buf ;
	}


}

uint32_t Bitmap::getDataOffset ( ) {
	return dataOffset;
}