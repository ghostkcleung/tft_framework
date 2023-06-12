#ifndef FONT_H
#define FONT_H

class Font:public Shape{

public:
Font(uint8_t w,uint8_t h)
  :w(w),h(h),scale(1),c('\0')
  ,paddingTop(0),paddingLeft(0)
  ,paddingBottom(0),paddingRight(0)
  ,spacingTop(0),spacingLeft(0)
  ,spacingBottom(0),spacingRight(0){};

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

void setSpacingTop(uint8_t spacingTop);
void setSpacingLeft(uint8_t spacingLeft);
void setSpacingBottom(uint8_t spacingBottom);
void setSpacingRight(uint8_t spacingRight);

uint8_t getSpacingTop();
uint8_t getSpacingLeft();
uint8_t getSpacingBottom();
uint8_t getSpacingRight();

virtual uint8_t getTotalWidth ( );
virtual uint8_t getTotalHeight ( );

virtual void write ( Screen *scr ) ;

protected:
uint8_t w, h;

private:
uint8_t scale;
uint32_t c;
uint8_t paddingTop, paddingLeft, paddingBottom, paddingRight
  , spacingTop, spacingLeft, spacingBottom, spacingRight;
};

#endif
