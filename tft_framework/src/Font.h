#ifndef FONT_H
#define FONT_H

class Font:public Shape{

public:
Font(uint8_t w,uint8_t h)
  :w(w),h(h),scale(1),c('\0'){};

uint8_t getWidth(), getHeight();

char getChar();
void setChar(char c);

uint8_t getScale();
void setScale(uint8_t s);

private:
uint8_t w, h, scale;
char c;

};

#endif
