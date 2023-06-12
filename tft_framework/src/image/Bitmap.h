#ifndef BITMAP_H
#define BITMAP_H

class Bitmap : public Image {

private:
bool bm;
uint32_t dataOffset;

uint32_t _rev ( byte *ptr, uint8_t len );

public:

Bitmap(File &f);

uint32_t getDataOffset ( ) ;
void fill ( Screen *scr ) ;
void fillGeneric ( Screen *scr ) ;

};

#endif
