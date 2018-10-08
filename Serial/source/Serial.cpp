//---------------------------------------------------------------------------

#include "mariamole_auto_generated.h"

//---------------------------------------------------------------------------

void setup() {                
	pinMode(13, OUTPUT);     
	// シリアルポートを9600bps[ビット/秒]で初期化
	Serial.begin(9600);
}

//---------------------------------------------------------------------------

void loop() {
	int inputchar;
	// シリアルポートより1文字読み込む
	inputchar = Serial.read();
	
	if(inputchar != -1){
		switch(inputchar){
			case'o':
				digitalWrite(13, HIGH);
				break;
			case'q':
				digitalWrite(13, LOW);
				break;
		}
	}
	else{
		
	}
	delay(10);
}

//---------------------------------------------------------------------------