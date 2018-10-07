// #include "mariamole_auto_generated.h"

int buzer = 9;
void setup() {
    pinMode(buzer, OUTPUT);
}

void loop() {
    char i = 0;
    for(i = 0; i < 80; i++)
    {
        digitalWrite(buzer, HIGH);
        delay(1);
        digitalWrite(buzer, LOW);
        delay(1);
    }
    for(i = 0; i < 100; i++)
    {
        digitalWrite(buzer, HIGH);
        delay(10);
        digitalWrite(buzer, LOW);
        delay(10);
    }
}
