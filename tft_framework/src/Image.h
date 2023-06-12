#ifndef IMAGE_H
#define IMAGE_H

class Image : public Point, public Fillable {

private:
File f;

protected:
uint32_t width, height;
uint16_t colorDepth;

public:
Image(File &f):f(f){};
Rectangle viewport;
Rectangle getViewport ();
void setViewport (Rectangle viewport);
virtual uint32_t getWidth();
virtual uint32_t getHeight();
virtual uint16_t getColorDepth();
File getFile();
};

#endif
