
// 文字列の格納
char str[10];
int i;

void setup()
{
    Serial.begin(9600);
}
void loop()
{
    // データ受信したとき
    if (Serial.available())
    {
    str[i] = Serial.read();
    
        // 文字数が10文字以上、終端文字なら終了
        if(i > 10 || str[i] == "\0")
        {
      str[i] = "\0";
      Serial.write(str);
      Serial.write("\0");
            i = 0;
        }
        else
        {
            i++;
        }
    }
    return String(str);
}
