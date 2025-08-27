#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID "TMPL67AQ_Zibv"
#define BLYNK_TEMPLATE_NAME "IRIGASI"
#define BLYNK_AUTH_TOKEN "XePhuGqjuuya9zueWXkV2Mo9Fq8e_cWh"


#include <Wire.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <LiquidCrystal_I2C.h>
#include "DHT.h"

LiquidCrystal_I2C lcd(0x27, 16, 2);
DHT dht (4, DHT11);

char ssid[] = "Ws-Eletronika";
char pass[] = "@bpvppdg25";

void setup() {
 Serial.begin(9600);
 Blynk.begin( BLYNK_AUTH_TOKEN, ssid, pass);
 dht.begin();
 lcd.init ();
 lcd.backlight();
}

void loop() {
  Blynk.run();
  float humidity = dht.readHumidity();
  float temp = dht.readTemperature(); // Dalam Celsius

  lcd.setCursor(0, 0);
  lcd.print ("humidity : ");
  lcd.print(humidity);
  Blynk.virtualWrite(V1, humidity);
  lcd.setCursor(0, 1);
  lcd.print("temp : ");
  lcd.print (temp);
  Blynk.virtualWrite(V0, temp);
  delay(2000);
 
}
