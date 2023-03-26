#ifndef ILI9486_H
#define ILI9486_H

#include <tft_framework.h>

namespace tft_framework {

class ILI9486:public Screen
{
protected:

	ILI9486(uint16_t w, uint16_t h):Screen(w,h){};

    void writeCom ( uint8_t com );
	void writeCom ( uint8_t com, uint8_t data );
	void writeCom16 ( uint8_t com, uint16_t data ) ;
	
	virtual void writeComs ( uint8_t com, uint8_t *datas, unsigned int count ) = 0 ;
	virtual void setWindow ( Rectangle* r ) = 0;
};

}
#endif