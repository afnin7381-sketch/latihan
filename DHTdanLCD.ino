#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "DHT.h"

LiquidCrystal_I2C lcd(0x27, 16, 2);
DHT dht (4, DHT11);

void setup() {
 Serial.begin(9600);
 dht.begin();
 lcd.init ();
 lcd.backlight(); }

void loop() {
  // delay (2000);
  float kelembaban = dht.readHumidity();
  float suhu = dht.readTemperature(); // Dalam Celsius
  lcd.setCursor(0, 0);
  lcd.print ("kelembaban : ");
  lcd.print(kelembaban);
  lcd.setCursor(0, 1);
  lcd.print("Suhu : ");
  lcd.print (suhu);
  delay(200);
 
}
