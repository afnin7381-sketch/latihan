#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID "TMPL6jJAz7knS"
#define BLYNK_TEMPLATE_NAME "sensor Suhu DHT11"
#define BLYNK_AUTH_TOKEN "eI2FACkbp5M1X8Mke5lNRfBBqfYiEKKP"

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "DHT.h"

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);

char ssid[] = "Ws-Eletronika";
char pass[] = "@bpvppdg25";

int sensorPin = 36;
int nilaiSensor;
int kelembabanPersen;
int ledPin = 2;

DHT dht(4, DHT11);


void setup() {
  Serial.begin(9600);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  pinMode(2, OUTPUT);
  dht.begin();
  lcd.init();
  lcd.backlight();
}

void loop() {
  float humidity = dht.readHumidity();
  float temp = dht.readTemperature();  // Dalam Celsius

  nilaiSensor = analogRead(sensorPin);
  kelembabanPersen = map(nilaiSensor, 2907, 1098, 0, 100);
  kelembabanPersen = constrain(kelembabanPersen, 0, 100);

  Blynk.run();
  Serial.print("humidity: ");
  Serial.print(humidity);
  Serial.print("|temp: ");
  Serial.println(temp);

  Blynk.virtualWrite(V2, nilaiSensor);
  Serial.print("nilaiSensor: ");
  Serial.print(nilaiSensor);
  Blynk.virtualWrite(V3, kelembabanPersen);
  Serial.print("|kelembaban: ");
  Serial.print(kelembabanPersen);
  Serial.println("% ");

  Blynk.virtualWrite(V0, humidity);
  lcd.setCursor(0, 0);
  lcd.print("humidity: ");
  lcd.print(humidity);
  delay(1000);

  lcd.setCursor(0, 1);
  lcd.print("temp: ");
  lcd.print(temp);
  delay(1000);
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("Sensor: ");
  lcd.print(nilaiSensor);
  delay(1000);

  lcd.setCursor(0, 1);
  lcd.print("kelembaban: ");
  lcd.print(kelembabanPersen);
  delay(1000);
  lcd.clear();

  if (temp > 35.00) {
    digitalWrite(2, HIGH);
    Blynk.virtualWrite(V4, 1);
  } else {
    digitalWrite(2, LOW);
    Blynk.virtualWrite(V4, 0);
    delay(1000);
  }
}
