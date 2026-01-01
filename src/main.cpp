#include <ST7796s_SPI_16Bit.h>

using namespace tft_framework;
Screen* scr;

void setup() {
	// Configure backlight
	uint8_t bl = 32;
	pinMode(bl, OUTPUT);
	digitalWrite(bl, HIGH);

	// Set data/command pin
	uint8_t dc = 27;

	// Initialize display
	scr = new ST_7796s_SPI_16Bit(dc);
	scr->init();
}

void loop() { delay(10000); }