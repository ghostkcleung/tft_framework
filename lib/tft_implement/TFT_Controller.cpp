/**
 * @file TFT_Controller.cpp
 * @brief Implementation of the abstract base class for TFT display controllers
 */

#include <TFT_Controller.h>

using namespace tft_framework;

/**
 * @brief Send command and 16-bit data to TFT controller
 * 
 * This method splits the 16-bit data into two 8-bit bytes (high byte and low byte),
 * then sends them to the controller via the writeComs() method.
 * 
 * @param com Command byte
 * @param data 16-bit data
 */
void TFT_Controller::writeCom16(uint8_t com, uint16_t data) {
	uint8_t datas[] = {data >> 8, data};
	writeComs(com, datas, 2);
}

/**
 * @brief Send command and single data byte to TFT controller
 * 
 * @param com Command byte
 * @param data Data byte
 */
void TFT_Controller::writeCom(uint8_t com, uint8_t data) {
	uint8_t datas[] = {data};
	writeComs(com, datas, 1);
}

/**
 * @brief Send single command to TFT controller (without data)
 * 
 * @param com Command byte
 */
void TFT_Controller::writeCom(uint8_t com) { writeComs(com, NULL, 0); }
