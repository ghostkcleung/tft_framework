#ifndef TFT_FRAMEWORK_H
#define TFT_FRAMEWORK_H

#define _USE_MATH_DEFINES

#include <Arduino.h>
#include <Print.h>
#include <SD.h>
#include <math.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

namespace tft_framework {
class BufferScreen;
class Screen;
class Bitmap;

#include "BmFont.h"
#include "BufferScreen.h"
#include "Circle.h"
#include "Color.h"
#include "Dot.h"
#include "Ellipse.h"
#include "Fillable.h"
#include "Font.h"
#include "Font5X7.h"
#include "Image.h"
#include "Line.h"
#include "Point.h"
#include "Rectangle.h"
#include "Screen.h"
#include "Shape.h"
#include "Triangle.h"
#include "image/Bitmap.h"

void swap_16(int16_t& x, int16_t& y);
bool sortRect(Rectangle* r, Rectangle rect);
bool sortRect(Rectangle* r, Image* img);
bool sortRect(Rectangle* r, Screen* scr);
uint32_t toUTF8(uint32_t unicode);
}  // namespace tft_framework

#endif