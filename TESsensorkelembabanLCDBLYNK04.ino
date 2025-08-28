#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID "TMPL6AvwNNznI"
#define BLYNK_TEMPLATE_NAME "sensorkelembaban"
#define BLYNK_AUTH_TOKEN "KnVyfKVcC5J6xE8tWi6v6JQM4BSTBQ_p"

int sensorPin = 36;
int nilaiSensor;
int kelembabanPersen;

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);

char ssid[] = "Ws-Eletronika";
char pass[] = "@bpvppdg25";

void setup() {
  Serial.begin(9600);  // put your setup code here, to run once
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  lcd.init();
  lcd.backlight();
}

void loop() {
  Blynk.run();
  nilaiSensor = analogRead(sensorPin);
  kelembabanPersen = map(nilaiSensor, 2907, 1098, 0, 100);
  kelembabanPersen = constrain(kelembabanPersen, 0, 100);

  Serial.print("nilaiSensor:");
  Serial.print(nilaiSensor);
  Serial.print("|kelembaban:");
  Serial.print(kelembabanPersen);
  Serial.println("% ");

  Blynk.virtualWrite(V0, nilaiSensor);
  lcd.setCursor(0, 0);
  lcd.print("nilaiSensor:");
  lcd.print(nilaiSensor);

  Blynk.virtualWrite(V1, kelembabanPersen);
  lcd.setCursor(0, 1);
  lcd.print("kelembaban:");
  lcd.print(kelembabanPersen);
  lcd.println("% ");
  delay(500);
}
