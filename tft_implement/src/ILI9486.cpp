#include <ILI9486.h>

using namespace tft_framework;

void ILI9486::writeCom16 ( uint8_t com, uint16_t data ) {
	uint8_t datas[] = { data >> 8, data } ;
    writeComs ( com, datas, 2 ) ;
}

void ILI9486::writeCom ( uint8_t com, uint8_t data )
{
	uint8_t datas[] = { data } ;
    writeComs ( com, datas, 1 ) ;
}

void ILI9486::writeCom ( uint8_t com )
{
    writeComs ( com, NULL, 0 ) ;
}