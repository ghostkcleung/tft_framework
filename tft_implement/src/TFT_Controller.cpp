#include <TFT_Controller.h>

using namespace tft_framework;

void TFT_Controller::writeCom16 ( uint8_t com, uint16_t data ) {
	uint8_t datas[] = { data >> 8, data } ;
    writeComs ( com, datas, 2 ) ;
}

void TFT_Controller::writeCom ( uint8_t com, uint8_t data )
{
	uint8_t datas[] = { data } ;
    writeComs ( com, datas, 1 ) ;
}

void TFT_Controller::writeCom ( uint8_t com )
{
    writeComs ( com, NULL, 0 ) ;
}
