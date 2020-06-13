#include "tft_framework.h"
using namespace tft_framework;

void Font5X7::draw(Screen* scr){
	uint8_t scale = getScale();
	if ( scale==0 ) { return; }

	char ch = getChar();

	if ( ch < 33 || ch >126){
		return;
	}

	Rectangle rect;
	rect.setColor(*this);

	int16_t _x = getX(),
		_y = getY();

	uint16_t index = (ch-32)*5;

	for(int x=0;x<5;x++){

		#if !defined(__SAM3X8E__) && !defined(__SAMD21G18A__)
		ch = pgm_read_byte_near(Matrix[index++]);
		#else
		ch = Matrix[index++];
		#endif

		for(int y=0;y<7;y++){
			if(ch & (1<<y)){
				rect.setX(_x+x*scale);
				rect.setY(_y+y*scale);
				rect.setWidth(scale);
				rect.setHeight(scale);
				scr -> fillImpl(&rect);
			}
		}
	}
}

const uint8_t Font5X7::Matrix[] 
#if !defined(__SAM3X8E__) && !defined(__SAMD21G18A__)
PROGMEM
#endif
= {
	0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x5F, 0x00, 0x00,
	0x00, 0x07, 0x00, 0x07, 0x00,
	0x14, 0x7F, 0x14, 0x7F, 0x14,
	0x24, 0x2A, 0x7F, 0x2A, 0x12,
	0x23, 0x13, 0x08, 0x64, 0x62,
	0x36, 0x49, 0x55, 0x22, 0x50,
	0x00, 0x05, 0x03, 0x00, 0x00,
	0x00, 0x1C, 0x22, 0x41, 0x00,
	0x00, 0x41, 0x22, 0x1C, 0x00,
	0x08, 0x2A, 0x1C, 0x2A, 0x08,
	0x08, 0x08, 0x3E, 0x08, 0x08,
	0x00, 0x50, 0x30, 0x00, 0x00,
	0x08, 0x08, 0x08, 0x08, 0x08,
	0x00, 0x60, 0x60, 0x00, 0x00,
	0x20, 0x10, 0x08, 0x04, 0x02,
	0x3E, 0x51, 0x49, 0x45, 0x3E,
	0x00, 0x42, 0x7F, 0x40, 0x00,
	0x42, 0x61, 0x51, 0x49, 0x46,
	0x21, 0x41, 0x45, 0x4B, 0x31,
	0x18, 0x14, 0x12, 0x7F, 0x10,
	0x27, 0x45, 0x45, 0x45, 0x39,
	0x3C, 0x4A, 0x49, 0x49, 0x30,
	0x01, 0x71, 0x09, 0x05, 0x03,
	0x36, 0x49, 0x49, 0x49, 0x36,
	0x06, 0x49, 0x49, 0x29, 0x1E,
	0x00, 0x36, 0x36, 0x00, 0x00,
	0x00, 0x56, 0x36, 0x00, 0x00,
	0x00, 0x08, 0x14, 0x22, 0x41,
	0x14, 0x14, 0x14, 0x14, 0x14,
	0x41, 0x22, 0x14, 0x08, 0x00,
	0x02, 0x01, 0x51, 0x09, 0x06,
	0x32, 0x49, 0x79, 0x41, 0x3E,
	0x7E, 0x11, 0x11, 0x11, 0x7E,
	0x7F, 0x49, 0x49, 0x49, 0x36,
	0x3E, 0x41, 0x41, 0x41, 0x22,
	0x7F, 0x41, 0x41, 0x22, 0x1C,
	0x7F, 0x49, 0x49, 0x49, 0x41,
	0x7F, 0x09, 0x09, 0x01, 0x01,
	0x3E, 0x41, 0x41, 0x51, 0x32,
	0x7F, 0x08, 0x08, 0x08, 0x7F,
	0x00, 0x41, 0x7F, 0x41, 0x00,
	0x20, 0x40, 0x41, 0x3F, 0x01,
	0x7F, 0x08, 0x14, 0x22, 0x41,
	0x7F, 0x40, 0x40, 0x40, 0x40,
	0x7F, 0x02, 0x04, 0x02, 0x7F,
	0x7F, 0x04, 0x08, 0x10, 0x7F,
	0x3E, 0x41, 0x41, 0x41, 0x3E,
	0x7F, 0x09, 0x09, 0x09, 0x06,
	0x3E, 0x41, 0x51, 0x21, 0x5E,
	0x7F, 0x09, 0x19, 0x29, 0x46,
	0x46, 0x49, 0x49, 0x49, 0x31,
	0x01, 0x01, 0x7F, 0x01, 0x01,
	0x3F, 0x40, 0x40, 0x40, 0x3F,
	0x1F, 0x20, 0x40, 0x20, 0x1F,
	0x7F, 0x20, 0x18, 0x20, 0x7F,
	0x63, 0x14, 0x08, 0x14, 0x63,
	0x03, 0x04, 0x78, 0x04, 0x03,
	0x61, 0x51, 0x49, 0x45, 0x43,
	0x00, 0x00, 0x7F, 0x41, 0x41,
	0x02, 0x04, 0x08, 0x10, 0x20,
	0x41, 0x41, 0x7F, 0x00, 0x00,
	0x04, 0x02, 0x01, 0x02, 0x04,
	0x40, 0x40, 0x40, 0x40, 0x40,
	0x00, 0x01, 0x02, 0x04, 0x00,
	0x20, 0x54, 0x54, 0x54, 0x78,
	0x7F, 0x48, 0x44, 0x44, 0x38,
	0x38, 0x44, 0x44, 0x44, 0x20,
	0x38, 0x44, 0x44, 0x48, 0x7F,
	0x38, 0x54, 0x54, 0x54, 0x18,
	0x08, 0x7E, 0x09, 0x01, 0x02,
	0x08, 0x14, 0x54, 0x54, 0x3C,
	0x7F, 0x08, 0x04, 0x04, 0x78,
	0x00, 0x44, 0x7D, 0x40, 0x00,
	0x20, 0x40, 0x44, 0x3D, 0x00,
	0x00, 0x7F, 0x10, 0x28, 0x44,
	0x00, 0x41, 0x7F, 0x40, 0x00,
	0x7C, 0x04, 0x18, 0x04, 0x78,
	0x7C, 0x08, 0x04, 0x04, 0x78,
	0x38, 0x44, 0x44, 0x44, 0x38,
	0x7C, 0x14, 0x14, 0x14, 0x08,
	0x08, 0x14, 0x14, 0x18, 0x7C,
	0x7C, 0x08, 0x04, 0x04, 0x08,
	0x48, 0x54, 0x54, 0x54, 0x20,
	0x04, 0x3F, 0x44, 0x40, 0x20,
	0x3C, 0x40, 0x40, 0x20, 0x7C,
	0x1C, 0x20, 0x40, 0x20, 0x1C,
	0x3C, 0x40, 0x30, 0x40, 0x3C,
	0x44, 0x28, 0x10, 0x28, 0x44,
	0x0C, 0x50, 0x50, 0x50, 0x3C,
	0x44, 0x64, 0x54, 0x4C, 0x44,
	0x00, 0x08, 0x36, 0x41, 0x00,
	0x00, 0x00, 0x7F, 0x00, 0x00,
	0x00, 0x41, 0x36, 0x08, 0x00,
	0x02, 0x01, 0x02, 0x04, 0x02 };