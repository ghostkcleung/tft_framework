#ifdef ESP32
#include <ST7796s_SPI_16Bit.h>

using namespace tft_framework;

void ST_7796s_SPI_16Bit::init()
{

	pinMode(cs, OUTPUT);
	pinMode(dc, OUTPUT);
	digitalWrite(cs, HIGH);
	digitalWrite(dc, HIGH);

	writeCom(0x01);
	delay(150);

	writeCom(0x11);
	delay(120);

	writeCom(0xF0, 0xC3);
	writeCom(0xF0, 0x96);
	writeCom(0x36, 0b11101000);
	writeCom(0x3A, 0x55);
	writeCom(0xB4, 0x01);

	{
		uint8_t datas[] = {
			0x80, 0x02, 0x3B};

		writeComs(0xB6, datas, sizeof(datas));
	}

	{
		uint8_t datas[] = {
			0x40, 0x8A, 0x00, 0x00,
			0x29, 0x19, 0xA5, 0x33};

		writeComs(0xE8, datas, sizeof(datas));
	}

	writeCom(0xC1, 0x06);
	writeCom(0xC2, 0xA7);
	writeCom(0xC5, 0x18);

	delay(150);

	{
		uint8_t datas[] = {
			0xF0, 0x09, 0x0B, 0x06,
			0x04, 0x15, 0x2F, 0x54,
			0x42, 0x3C, 0x17, 0x14,
			0x18, 0x18};

		writeComs(0xE0, datas, sizeof(datas));
	}

	{
		uint8_t datas[] = {
			0xF0, 0x09, 0x0B, 0x06,
			0x04, 0x03, 0x2B, 0x43,
			0x42, 0x3B, 0x16, 0x14,
			0x17, 0x1B};

		writeComs(0xE1, datas, sizeof(datas));
	}

	delay(150);

	writeCom(0xF0, 0x3C);
	writeCom(0xF0, 0x69);
	delay(150);
	writeCom(0x29);
}

void ST_7796s_SPI_16Bit::fillRect(Rectangle *r)
{
	setWindow(r);

	uint16_t w = r->getWidth(),
			 h = r->getHeight();

	GPIO.out_w1tc = (1 << cs);
	GPIO.out_w1ts = (1 << dc);

	uint16_t color = r->getColor();
	uint8_t buf[] = {color >> 8, color & 0xFF};

	for (uint16_t y = 0; y < h; y++)
	{
		spi->writePattern(buf, 2, w);
	}

	GPIO.out_w1ts = (1 << cs);
};

void ST_7796s_SPI_16Bit::setRotate(uint8_t rotate)
{
	rotate %= 8;
	if (getRotate() == rotate)
	{
		return;
	}

	Screen::setRotate(rotate);

	switch (rotate)
	{
	case 4:
		writeCom(0x36, 0b00101000);
		break;

	case 5:
		writeCom(0x36, 0b10101000);
		break;

	case 6:
		writeCom(0x36, 0b10001000);
		break;

	case 7:
		writeCom(0x36, 0b11001000);
		break;

	case 0:
		writeCom(0x36, 0b11101000);
		break;

	case 1:
		writeCom(0x36, 0b01101000);
		break;

	case 2:
		writeCom(0x36, 0b01001000);
		break;

	case 3:
		writeCom(0x36, 0b00001000);
		break;
	}
}

void ST_7796s_SPI_16Bit::fillShape(BufferScreen *buf)
{

	uint8_t scale = buf->getScale();

	if (!scale)
	{
		return;
	}

	Rectangle r;
	r.setPoint(*buf);
	uint16_t w = buf->getWidth(),
			 h = buf->getHeight();

	if ((buf->getRotate() / 2) % 2)
	{
		uint16_t tmp = w;
		w = h;
		h = tmp;
	}

	r.setSize(w * scale, h * scale);

	setWindow(&r);

	GPIO.out_w1tc = (1 << cs);
	GPIO.out_w1ts = (1 << dc);

	uint16_t y = h, x;
	uint8_t sy, sx;
	uint16_t *data = buf->getData(), *col;

	while (y-- > 0)
	{
		sy = scale;
		while (sy-- > 0)
		{
			col = data;
			x = w;
			while (x-- > 0)
			{
				sx = scale;

				uint8_t buf[] = {*col >> 8, *col++ & 0xFF};
				spi->writePattern(buf, 2, sx);
			}
		}
		data += w;
	}

	GPIO.out_w1ts = (1 << cs);
}

void ST_7796s_SPI_16Bit::drawShape(Dot *d)
{

	uint16_t x = d->getX(), y = d->getY(), c = d->getColor();

	{
		uint8_t datas[] = {x >> 8, x, x >> 8, x};
		writeComs(0x2A, datas, 4);
	}

	{
		uint8_t datas[] = {y >> 8, y, y >> 8, y};
		writeComs(0x2B, datas, 4);
	}

	writeCom(0x2c);

	GPIO.out_w1tc = (1 << cs);
	GPIO.out_w1ts = (1 << dc);

	spi->transfer(c >> 8);
	spi->transfer(c & 0xFF);

	GPIO.out_w1ts = (1 << cs);
}

void ST_7796s_SPI_16Bit::fillShape(Bitmap *bmp)
{
	if (bmp->getColorDepth() == 16)
	{
		Rectangle viewport = bmp->getViewport();
		if (!sortRect(&viewport, bmp))
		{
			return;
		}

		viewport.moveTo(*bmp);
		if (!sortRect(&viewport, this))
		{
			return;
		}

		uint16_t viewH = viewport.getHeight(), viewW = viewport.getWidth(), imgW = bmp->getWidth(), bufSize = viewW * 2;

		int16_t viewY = viewport.getY();

		byte bytes[bufSize];

		viewport.moveToY(getHeight() - viewH - viewY);

		uint8_t rotate = getRotate();
		setRotate((rotate + 5) % 8);

		setWindow(&viewport);

		viewport.moveTo(bmp->getViewport());

		int16_t viewX = viewport.getX();
		viewY = viewport.getY();

		GPIO.out_w1tc = (1 << cs);
		GPIO.out_w1ts = (1 << dc);

		File f = bmp->getFile();
		f.seek(bmp->getDataOffset() + (bmp->getHeight() - viewH - viewY) * imgW * 2);

		for (int y = 0; y < viewH; y++)
		{
			f.seek(f.position() + viewX * 2);
			f.read(bytes, bufSize);

			for (int x = 0; x < bufSize; x += 2)
			{
				byte tmp=bytes[x];
				bytes[x] = bytes[x+ 1];
				bytes[x+ 1] = tmp;
			}

			spi->transfer(bytes, bufSize);
			f.seek(f.position() + (imgW - viewX - viewW) * 2);
		}

		GPIO.out_w1ts = (1 << cs);
		setRotate(rotate);
	}
	else
	{
		bmp->fillGeneric(this);
	}
}
#endif