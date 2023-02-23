#ifndef FONT_H
#define FONT_H

class Font:public Shape{

public:
Font(uint8_t w,uint8_t h)
  :w(w),h(h),scale(1),c('\0')
  ,paddingTop(0),paddingLeft(0)
  ,paddingBottom(0),paddingRight(0)
  ,marginTop(0),marginLeft(0)
  ,marginBottom(0),marginRight(0){};

virtual ~Font();

uint8_t getWidth(), getHeight();

uint32_t getChar();
virtual void setChar(uint32_t c);

uint8_t getScale();
void setScale(uint8_t s);

void setPaddingTop(uint8_t paddingTop);
void setPaddingLeft(uint8_t paddingLeft);
void setPaddingBottom(uint8_t paddingBottom);
void setPaddingRight(uint8_t paddingRight);

uint8_t getPaddingTop();
uint8_t getPaddingLeft();
uint8_t getPaddingBottom();
uint8_t getPaddingRight();

void setMarginTop(uint8_t marginTop);
void setMarginLeft(uint8_t marginLeft);
void setMarginBottom(uint8_t marginBottom);
void setMarginRight(uint8_t marginRight);

uint8_t getMarginTop();
uint8_t getMarginLeft();
uint8_t getMarginBottom();
uint8_t getMarginRight();

virtual uint8_t getTotalWidth ( );
virtual uint8_t getTotalHeight ( );

virtual void write ( Screen *scr ) ;

protected:
uint8_t w, h;

private:
uint8_t scale;
uint32_t c;
uint8_t paddingTop, paddingLeft, paddingBottom, paddingRight
  , marginTop, marginLeft, marginBottom, marginRight;
};

#endif
