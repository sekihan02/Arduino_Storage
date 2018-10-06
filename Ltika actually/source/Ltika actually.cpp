#include "mariamole_auto_generated.h"

int LED_SOCKET = 10;

void setup() {
	pinMode(LED_SOCKET, OUTPUT);
}


void loop() {
	digitalWrite(LED_SOCKET, HIGH);
	delay(1000);
    digitalWrite(LED_SOCKET, LOW);
	delay(1000);
}

//---------------------------------------------------------------------------