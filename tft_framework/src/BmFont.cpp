#include "tft_framework.h"
using namespace tft_framework;

BmFont::BmFont(File &path, String fntFileName)
    : path(path), fntFileName(fntFileName), Font(0, 0)
{

    cacheCount = 0;
    cacheSize = 100;

    valid = false;

    path.rewindDirectory();
    while (File f = path.openNextFile())
    {
        if (fntFileName.equals(f.name()))
        {
            f.findUntil("ht=", "ba");
            h = f.parseInt();

            f.findUntil("W=", "p");
            scaleW = f.parseInt();
            f.findUntil("=", " ");
            scaleH = f.parseInt();

            f.findUntil("=", " ");
            pageCount = f.parseInt();
            pages = new String *[pageCount];

            for (int i = 0; i < pageCount; i++)
            {
                f.findUntil("=\"", "\"");
                String *p = new String(f.readStringUntil('\"'));
                pages[i] = p;
            }

            f.findUntil("=", "h");
            charCount = f.parseInt();
            chars = new CharStruct *[charCount];

            for (int i = 0; i < charCount; i++)
            {
                chars[i] = new CharStruct();
                f.findUntil("d=", "x");
                chars[i]->id = toUTF8(f.parseInt());

                f.findUntil("=", " ");
                chars[i]->x = f.parseInt();
                f.findUntil("=", " ");
                chars[i]->y = f.parseInt();

                f.findUntil("=", " ");
                chars[i]->width = f.parseInt();
                f.findUntil("=", " ");
                chars[i]->height = f.parseInt();

                f.findUntil("yoffset=", "xa");
                chars[i]->yOffset = f.parseInt();

                f.findUntil("ge=", "ch");
                chars[i]->page = f.parseInt();
            }

            f.close();
            valid = true;
            break;
        }
        f.close();
    }
}

bool BmFont::isValid()
{
    return valid;
}

void BmFont::draw(Screen *scr)
{

    if (!selected)
    {
        return;
    }

    uint8_t scale = getScale();
    if (scale == 0)
    {
        return;
    }

    Dot d;
    d.setPoint(*this);
    d.move(180, selected->yOffset);

    uint8_t *pointer = selected->cache;
    int i = 0;
    for (int y = 0; y < selected->height; y++)
    {
        for (int x = 0; x < selected->width; x++)
        {
            i++;
            if (*pointer)
            {
                d.setR(*pointer);
                d.setG(*pointer);
                d.setB(*pointer);
                d.draw(scr);
            }
            pointer++;
            d.move(90, 1);
        }
        d.move(180, 1);
        d.setX(getX());
    }
}

BmFont::~BmFont()
{
    for (int i = 0; i < pageCount; i++)
    {
        delete pages[i];
    }
    delete[] pages;

    for (int i = 0; i < charCount; i++)
    {
        delete chars[i]->cache;
        delete chars[i];
    }
    delete[] chars;
}

void BmFont::setChar(uint32_t c)
{
    if (c == getChar())
    {
        selected->useTime++;
        return;
    }

    selected = NULL;
    w = 0;
    Font::setChar(c);

    if (!valid)
    {
        return;
    }

    for (int i = 0; i < charCount; i++)
    {
        if (chars[i]->id == c)
        {
            selected = chars[i];
            selected->useTime++;

            w = selected->width;

            if (!selected->cache)
            {
                setCacheSize(cacheSize - 1);
                cacheSize++;

                selected->cache = new uint8_t[selected->width * selected->height];
                uint8_t *pointer = selected->cache;

                path.rewindDirectory();
                while (File f = path.openNextFile())
                {
                    if (pages[selected->page]->equals(f.name()))
                    {
                        f.seek(18 + selected->y * scaleW + selected->x);

                        for (int y = 0; y < selected->height; y++)
                        {
                            f.read(pointer, selected->width);
                            pointer += selected->width;
                            f.seek(f.position() + scaleW - selected->width);
                        }

                        cacheCount++;

                        f.close();
                        break;
                    }
                    f.close();
                }
            }
        }
    }
}

void BmFont::setCacheSize(uint8_t size)
{
    cacheSize = size;

    struct CharStruct *min = NULL;
    while (cacheCount > size)
    {
        for (int i = 1; i < charCount; i++)
        {
            if (chars[i]->cache)
            {
                if (!min)
                {
                    min = chars[i];
                }
                if (chars[i]->useTime < min->useTime)
                {
                    min = chars[i];
                }
            }
        }

        delete min->cache;
        min->cache = NULL;

        cacheCount--;
    }
}

uint8_t BmFont::getCacheSize()
{
    return cacheSize;
}