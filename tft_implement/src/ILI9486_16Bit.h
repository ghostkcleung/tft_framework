#ifndef ILI9486_16Bit_H
#define ILI9486_16Bit_H

#include <tft_framework.h>
using namespace tft_framework;

#ifdef __AVR_ATmega2560__
	#include "Mega2560_ILI9486_16Bit.h"
	typedef Mega2560_ILI9486_16Bit ILI9486_16Bit ;
#endif

#ifdef __SAM3X8E__
	#include "Due_ILI9486_16Bit.h"
	typedef Due_ILI9486_16Bit ILI9486_16Bit ;
#endif

#endif