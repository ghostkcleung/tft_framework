#ifndef MY_FONT_H
#define MY_FONT_H

#include <tft_framework.h>

using namespace tft_framework;

class BmFont : public Font
{

public:
    BmFont(File &path, String fntFileName);
    void draw(Screen *scr);
    ~BmFont();

    bool isValid();

    void setChar(uint32_t c);

    void setCacheSize(uint8_t size);
    uint8_t getCacheSize ( );

private:
    bool valid;

    File path;
    String fntFileName;

    uint16_t scaleW, scaleH;

    uint8_t pageCount;
    String **pages;
    uint16_t charCount;

    struct CharStruct
    {
        uint32_t id;
        uint8_t page;
        uint16_t x, y;
        uint16_t width, height;
        uint8_t yOffset;
        uint8_t *cache = NULL;
        uint16_t useTime = 0;
    };

    struct CharStruct **chars;
    struct CharStruct *selected;

    uint8_t cacheSize;
    uint8_t cacheCount;
};

#endif