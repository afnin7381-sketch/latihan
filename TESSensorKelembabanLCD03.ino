int sensorPin = 36;
int nilaiSensor;
int kelembabanPersen;

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
}

void loop() {
  nilaiSensor = analogRead(sensorPin);
  kelembabanPersen = map(nilaiSensor, 2907, 1097, 0, 100);
  kelembabanPersen = constrain(kelembabanPersen, 0, 100);

  Serial.print("nilaiSensor : ");
  Serial.print(nilaiSensor);
  Serial.print("|kelembabanPersen :");
  Serial.print(kelembabanPersen);
  Serial.print("%");

  lcd.setCursor(0, 0);
  lcd.print("nilaiSensor: ");
  lcd.print(nilaiSensor);
  lcd.setCursor(0, 1);
  lcd.print("kelembaban: ");
  lcd.print(kelembabanPersen);
  lcd.print("% ");
  delay(1000);
}