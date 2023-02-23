#include "tft_framework.h"
using namespace tft_framework;

uint8_t Font::getWidth(){
  return w;
}

uint8_t Font::getHeight(){
  return h;
}

uint8_t Font::getTotalWidth(){
	return ( w + paddingLeft + paddingRight ) * scale;
}

uint8_t Font::getTotalHeight(){
	return ( h + paddingTop + paddingBottom ) * scale;
}

uint32_t Font::getChar (){
  return c;
}

void Font::setChar(uint32_t c){
  this->c = c;
}

uint8_t Font::getScale(){
  return scale;
}

void Font::setScale(uint8_t s){
  scale=s;
}

void Font::setPaddingTop(uint8_t paddingTop){
	this -> paddingTop = paddingTop ;
}

void Font::setPaddingLeft(uint8_t paddingLeft){
	this -> paddingLeft = paddingLeft ;
}

void Font::setPaddingBottom(uint8_t paddingBottom){
	this -> paddingBottom = paddingBottom ;
}

void Font::setPaddingRight(uint8_t paddingRight){
	this -> paddingRight = paddingRight ;
}

uint8_t Font::getPaddingTop(){
	return paddingTop;
}

uint8_t Font::getPaddingLeft(){
	return paddingLeft;
}

uint8_t Font::getPaddingBottom(){
	return paddingBottom;
}

uint8_t Font::getPaddingRight(){
	return paddingRight;
}

Font::~Font(){
	
}