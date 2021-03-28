#include "tft_framework.h"
using namespace tft_framework;

void Dot::drawGeneric(Screen* scr)
{
	Rectangle r;
	r.setPoint(*this);
    r.setEndPoint(*this);
    r.setColor(*this);
    r.fill ( scr ) ;
}
