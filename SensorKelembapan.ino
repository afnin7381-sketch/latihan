#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID "TMPL6gd9l01v4"
#define BLYNK_TEMPLATE_NAME "sensorkelembaban"
#define BLYNK_AUTH_TOKEN "HmGBKq5RDSLrTrvarfwlHVCp2hYMCBdt"

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

char ssid[] = "Ws-Eletronika";
char pass[] = "@bpvppdg25";

const int sensorPin = 36;
int nilaiADC;
int kelembabanPersen;

void setup() {
  Serial.begin(9600);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  pinMode(2, OUTPUT);
  lcd.init();
  lcd.backlight();
}

void loop() {
  Blynk.run();
  Serial.println(analogRead(sensorPin));
  nilaiADC = analogRead(sensorPin);
  kelembabanPersen = map(nilaiADC, 3027, 1023, 0, 100);
  kelembabanPersen = constrain(kelembabanPersen, 0, 100);

  Serial.print("Nilai ADC");
  Serial.print(nilaiADC);
  Serial.print("| kelembaban Tanah: ");
  Serial.print(kelembabanPersen);
  Serial.print("%");
  
  Blynk.virtualWrite (V0, kelembabanPersen);
  lcd.print("kelembaban:");
  lcd.print(kelembabanPersen);
  lcd.print("% ");
  lcd.setCursor(0, 0);
  delay(500);

if (kelembabanPersen > 50) {
digitalWrite (2, HIGH);
Blynk.virtualWrite (V1, 1);
}

else{
digitalWrite(2, LOW);
Blynk.virtualWrite (V1, 0);
}

}
