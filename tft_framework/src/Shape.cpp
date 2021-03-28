#include "tft_framework.h"

using namespace tft_framework;

void Shape::draw (Screen* scr) {
	scr -> drawShape ( this ) ;
}