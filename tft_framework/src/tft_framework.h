#ifndef TFT_FRAMEWORK_H
#define TFT_FRAMEWORK_H

#define _USE_MATH_DEFINES

#include <Arduino.h>
#include <math.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <Print.h>
#include <SD.h>

namespace tft_framework
{
class BufferScreen;
class Screen;
class Bitmap;

#include "Point.h"
#include "Color.h"
#include "Shape.h"
#include "Fillable.h"
#include "Line.h"
#include "Rectangle.h"
#include "Dot.h"
#include "Triangle.h"
#include "Circle.h"
#include "Ellipse.h"
#include "Font.h"
#include "Font5X7.h"
#include "Screen.h"
#include "BufferScreen.h"
#include "Image.h"
#include "image/Bitmap.h"
#include "BmFont.h"

void swap_16(int16_t &x, int16_t &y);
bool sortRect ( Rectangle *r, Rectangle rect ) ;
bool sortRect ( Rectangle *r, Image *img ) ;
bool sortRect ( Rectangle *r, Screen *scr ) ;
uint32_t toUTF8(uint32_t unicode);
}

#endif
