


#include <SPI.h>
#include <MFRC522.h>

#define RST_PIN   9
#define SS_PIN    10

int pin = 8;
int melody = 250;


MFRC522 mfrc522(SS_PIN, RST_PIN);

#define NEW_UID {0xDE, 0xAD, 0xBE, 0xEF}

MFRC522::MIFARE_Key key;

void setup() {
  Serial.begin(9600);
  while (!Serial);
  SPI.begin();
  mfrc522.PCD_Init();
  Serial.println(F("Warning: this example overwrites the UID of your UID changeable card, use with care!"));
  
  for (byte i = 0; i < 6; i++) {
    key.keyByte[i] = 0xFF;
  }
}

void loop()
{
  
  if ( ! mfrc522.PICC_IsNewCardPresent() || ! mfrc522.PICC_ReadCardSerial() ) {
    delay(50);
    return;
  }
  
  Serial.print(F("Card UID:"));
  for (byte i = 0; i < mfrc522.uid.size; i++) {
    Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
    Serial.print(mfrc522.uid.uidByte[i], HEX);
  } 
  Serial.println();

  byte newUid[] = NEW_UID;
  if ( mfrc522.MIFARE_SetUid(newUid, (byte)4, true) ) {
    Serial.println(F("Wrote new UID to card."));
  }

  // buzzer
  if( mfrc522.MIFARE_SetUid(newUid, (byte)4, true) )
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
  
  mfrc522.PICC_HaltA();
  if ( ! mfrc522.PICC_IsNewCardPresent() || ! mfrc522.PICC_ReadCardSerial() ) {
    return;
  }
  
  Serial.println(F("New UID and contents:"));
  mfrc522.PICC_DumpToSerial(&(mfrc522.uid));
  
  delay(2000);
  
}
