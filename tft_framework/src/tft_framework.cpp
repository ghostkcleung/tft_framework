#include "tft_framework.h"

using namespace tft_framework;

void tft_framework::
swap(int16_t &x, int16_t &y)
{
    int16_t tmp = x;
    x = y;
    y = tmp;
}
