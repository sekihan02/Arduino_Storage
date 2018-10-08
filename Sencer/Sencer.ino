const int PIN = 7;
const int R = 11;

void setup() {
  pinMode(R, OUTPUT);
  pinMode(PIN, INPUT);
  // Serial.begin(9600);
}

void loop() {
  if (digitalRead(PIN) == HIGH)
  {
    digitalWrite(R, HIGH);
  }
  else
  {
    digitalWrite(R, LOW);
  }
}
