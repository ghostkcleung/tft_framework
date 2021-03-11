#include "tft_framework.h"
using namespace tft_framework;

uint8_t Font::getWidth(){
  return w;
}

uint8_t Font::getHeight(){
  return h;
}

char Font::getChar (){
  return c;
}

void Font::setChar(char c){
  this->c = c;
}

uint8_t Font::getScale(){
  return scale;
}

void Font::setScale(uint8_t s){
  scale=s;
}

Font::~Font(){
	
}