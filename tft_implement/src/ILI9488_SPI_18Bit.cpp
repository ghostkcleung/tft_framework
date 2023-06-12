#ifdef ESP32
#include <ILI9488_SPI_18Bit.h>

using namespace tft_framework;

void ILI9488_SPI_18Bit::init()
{

	pinMode(cs, OUTPUT);
	pinMode(dc, OUTPUT);
	digitalWrite(cs, HIGH);
	digitalWrite(dc, HIGH);

	writeCom(0x01);
	delay(150);

	writeCom(0x11);
	delay(120);

	writeCom(0x3A, 0x66);
	writeCom(0xC2, 0x44);

	{
		uint8_t datas[] = {
			0x00, 0x00, 0x00, 0x00};

		writeComs(0xC5, datas, sizeof(datas));
	}

	{
		uint8_t datas[] = {
			0x0F, 0x1F, 0x1C, 0x0C,
			0x0F, 0x08, 0x48, 0x98,
			0x37, 0x0A, 0x13, 0x04,
			0x11, 0x0D, 0x00};

		writeComs(0xE0, datas, sizeof(datas));
	}

	{
		uint8_t datas[] = {
			0x0F, 0x32, 0x2E, 0x0B,
			0x0D, 0x05, 0x47, 0x75,
			0x37, 0x06, 0x10, 0x03,
			0x24, 0x20, 0x00};

		writeComs(0xE1, datas, sizeof(datas));
	}
	writeCom(0x36, 0b00100000);

	writeCom(0x20);
	writeCom(0x29);
}

void ILI9488_SPI_18Bit::fillRect(Rectangle *r)
{
	setWindow(r);

	uint16_t w = r->getWidth(),
			 h = r->getHeight();

	GPIO.out_w1tc = (1 << cs);
	GPIO.out_w1ts = (1 << dc);

	uint8_t buf[] = {r->getR(), r->getG(), r->getB()};

	for (uint16_t y = 0; y < h; y++)
	{
		spi->writePattern(buf, 3, w);
	}

	GPIO.out_w1ts = (1 << cs);
};

void ILI9488_SPI_18Bit::setRotate(uint8_t rotate)
{
	rotate %= 8;
	if (getRotate() == rotate)
	{
		return;
	}

	Screen::setRotate(rotate);

	switch (rotate)
	{
	case 0:
		writeCom(0x36, 0b00100000);
		break;

	case 1:
		writeCom(0x36, 0b10100000);
		break;

	case 2:
		writeCom(0x36, 0b10000000);
		break;

	case 3:
		writeCom(0x36, 0b11000000);
		break;

	case 4:
		writeCom(0x36, 0b11100000);
		break;

	case 5:
		writeCom(0x36, 0b01100000);
		break;

	case 6:
		writeCom(0x36, 0b01000000);
		break;

	case 7:
		writeCom(0x36, 0b00000000);
		break;
	}
}

void ILI9488_SPI_18Bit::fillShape(BufferScreen *buf)
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
				Color c(*col++);

				sx = scale;

				while (sx-- > 0)
				{
					spi->transfer(c.getB());
					spi->transfer(c.getG());
					spi->transfer(c.getR());
				}
			}
		}
		data += w;
	}

	GPIO.out_w1ts = (1 << cs);
}

void ILI9488_SPI_18Bit::drawShape(Dot *d)
{

	uint16_t x = d->getX(), y = d->getY();

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

	spi->transfer(d->getB());
	spi->transfer(d->getG());
	spi->transfer(d->getR());

	GPIO.out_w1ts = (1 << cs);
}

void ILI9488_SPI_18Bit::fillShape(Bitmap *bmp)
{
	if (bmp->getColorDepth() == 24)
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

		uint16_t viewH = viewport.getHeight(), viewW = viewport.getWidth(), imgW = bmp->getWidth(), bufSize = viewW * 3;

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
		f.seek(bmp->getDataOffset() + (bmp->getHeight() - viewH - viewY) * imgW * 3);

		for (int y = 0; y < viewH; y++)
		{
			f.seek(f.position() + viewX * 3);
			f.read(bytes, bufSize);

			spi->transfer(bytes, bufSize);
			f.seek(f.position() + (imgW - viewX - viewW) * 3);
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