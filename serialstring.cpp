// 文字列の格納
char str[10];
int i;

void setup()
{
    Serial.begin(9600);
    pinMode(13, OUTPUT);
    digitalWrite(13, HIGH);
    digitalWrite(13, LOW);
}
String serialRead()
{
    // データ受信したとき
    if (Serial.available())
    {
        // 文字数が10文字以上、終端文字なら終了
        if(i > 10 || str[i] == '\0')
        {
            i = 0;
        }
        else
        {
            i++;
        }
    }
    return String(str);
}
void loop()
{
    String cmd = serialRead();
    
    if (cmd == 'on') {
        digitalWrite(13, HIGH);
    }
    else if(cmd == 'off')
    {
        digitalWrite(13, LOW);
    }
}