#include "tft_framework.h"
using namespace tft_framework;

void Dot::draw(Screen* scr)
{
	if ( getX() < 0 ) { return ; }
	if ( getY() < 0 ) { return ; }
	if ( getX() >= scr -> getWidth ( ) ) { return ; }
	if ( getY() >= scr -> getHeight ( ) ) { return ; }
	scr -> drawShape ( this ) ;
}
