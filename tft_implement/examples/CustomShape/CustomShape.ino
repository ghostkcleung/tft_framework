#include <ILI9486_16Bit.h>

using namespace tft_framework;
Screen* scr;

class Star: public Shape {
	private:
	int len;

	public:
	void setLength (int len){
		this->len = len ;
	}

	int getSize ( ) {
		return len;
	}

	void drawGeneric ( Screen* scr ) {
		Line l;
		l.setPoint(240,160);
		l.setColor(*this);

		int degree = 0;

		for ( int i=0; i<5;i++){
			l.lineTo ( degree , len ) ;
			degree += 144 ;
			l.draw ( scr ) ;
			l.setPoint (l.getEndPoint());
		}
	}
} ;

void setup() {
    randomSeed(analogRead(A0));

    scr = new ILI9486_16Bit ( ) ;
    scr -> init();
    scr -> clear ( ) ;

	Star star ;
	star.setColor(0xFFFF);
	star.setLength ( 100 ) ;
	star.draw(scr);
}

void loop(){
	delay ( 10000 ) ;
}