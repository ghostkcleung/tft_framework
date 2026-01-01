/**
 * @file Image.cpp
 * @brief Implementation of the Image base class for file-based images.
 * 
 * Provides the interface for loading and rendering images from files
 * (SD card, SPIFFS, etc.). Derived classes implement specific image
 * formats like BMP, JPEG, PNG, etc.
 */

#include "tft_framework.h"
using namespace tft_framework;

uint32_t Image::getHeight() { return height; }

uint32_t Image::getWidth() { return width; }

uint16_t Image::getColorDepth() { return colorDepth; }

File Image::getFile() { return f; }

Rectangle Image::getViewport() { return viewport; }

void Image::setViewport(Rectangle viewport) { this->viewport = viewport; }