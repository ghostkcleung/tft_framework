
#if defined ( __AVR_ATmega2560__ ) || defined ( __SAM3X8E__ )

#ifndef ILI9486_PARALLEL_16BIT_H
#define ILI9486_PARALLEL_16BIT_H

#include <PARALLEL_TFT_Controller.h>

namespace tft_framework {

class ILI9486_Parallel_16Bit:public Parallel_TFT_Controller, public Screen
{

public:

	ILI9486_Parallel_16Bit (uint16_t w, uint16_t h, uint8_t rs, uint8_t wr, uint8_t cs, uint8_t rst)
		:Parallel_TFT_Controller(rs,wr,cs,rst),Screen(w, h){};

	ILI9486_Parallel_16Bit ():Parallel_TFT_Controller(),Screen(480,320){};

    void init ( );
    void fillRect(Rectangle* r);
    void setRotate(uint8_t rotate);

    void fillShape(BufferScreen* buf);
	void drawShape(Dot *d);
	void fillShape(Bitmap* bmp);

};

}
#endif

#endif