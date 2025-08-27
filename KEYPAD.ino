#include <Keypad.h>

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

char ssid[] = "Ws-Eletronika";
char pass[] = "@bpvppdg25";

const byte ROWS = 4; //four rows
const byte COLS = 4; //three columns

char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {32, 33, 25, 26}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {27, 14, 12, 13}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup(){
  Serial.begin(115200);
  lcd.init();
  lcd.backlight();
}
  
void loop(){
  char key = keypad.getKey();
  
  if (key){
    Serial.println(key);
    lcd.print(key);
  }
}
