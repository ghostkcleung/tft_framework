#include "tft_framework.h"

using namespace tft_framework;

void Fillable::fill (Screen* scr) {
	scr -> fillShape ( this ) ;
}