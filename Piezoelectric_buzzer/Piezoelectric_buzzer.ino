int melody = 250;
int pin = 13;

void setup()
{
    
}
void loop()
{
    tone(pin,262,melody);  // ド
    delay(melody);         // 音がなっている間待機
    tone(pin,294,melody);  // レ
    delay(melody);
    tone(pin,330,melody);  // ミ
    delay(melody);
    tone(pin,349,melody);  // ﾌｧ
    delay(melody);
    tone(pin,392,melody);  // ソ
    delay(melody);
    tone(pin,440,melody);  // ラ
    delay(melody);
    tone(pin,494,melody);  // シ
    delay(melody);
    tone(pin,523,melody);  // ド
    delay(melody);
    delay(1000);         // 1秒待機
}
