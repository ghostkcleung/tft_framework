#ifndef TFT_FRAMEWORK_H
#define TFT_FRAMEWORK_H

#define _USE_MATH_DEFINES

#include <Arduino.h>
#include <math.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <Print.h>

namespace tft_framework
{
class BufferScreen;
class Screen;

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

void swap(int16_t &x, int16_t &y);

}

#endif
