#include "tft_framework.h"
using namespace tft_framework;

void Dot::draw(Screen* scr)
{
	if ( getX() < 0 || getY() < 0
		|| getX() >= scr -> getWidth ( )
		|| getY() >= scr -> getHeight ( ) ) { return ; }
	scr -> drawShape ( this ) ;
}
