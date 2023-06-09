#ifndef PARALLEL_TFT_CONTROLLER_H
#define PARALLEL_TFT_CONTROLLER_H

#include <TFT_Controller.h>

namespace tft_framework
{

#ifdef __AVR_ATmega2560__
	typedef volatile uint8_t RegType;
	typedef uint8_t RegSize;
#else #ifdef __SAM3X8E__
	typedef volatile uint32_t RegType;
	typedef uint32_t RegSize;
#endif

	class Parallel_TFT_Controller : public TFT_Controller
	{
	protected:
		RegType *ports[4];
		RegSize bitmasks[4];

		void sbi(RegType *port, RegSize bitmask);
		void pulseLow(RegType *port, RegSize bitmask);
		void feedValue(uint8_t h, uint8_t l);
		void cbi(RegType *port, RegSize bitmask);

		void writeComs(uint8_t com, uint8_t *datas, unsigned int count);
		void setWindow(Rectangle *r);

	public:
	    Parallel_TFT_Controller( uint8_t rs, uint8_t wr, uint8_t cs, uint8_t rst );
		Parallel_TFT_Controller():Parallel_TFT_Controller(38, 39, 40, 41) {};
	};

}

#endif