#define BLYNK_TEMPLATE_ID "TMPL6HZby5POS"
#define BLYNK_TEMPLATE_NAME "ResistiveSensor"
#define BLYNK_AUTH_TOKEN "Nqwp_VQol8_CHXxZiNsVP8g3s_uf6PCD"

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

char ssid[] = "Ws-Eletronika";
char pass[] = "@bpvppdg25";

const int pinSoil = 36;
int nilaiADC;
int kelembabanPersen;

void setup() {
  Serial.begin (115200);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
   pinMode(2, OUTPUT);
  lcd.init();
  lcd.backlight();
}

void loop() {
  Blynk.run();
  nilaiADC = analogRead(pinSoil);
  kelembabanPersen = map (nilaiADC, 4095, 1775, 0, 100);
  kelembabanPersen = constrain (kelembabanPersen, 0, 100);

  Blynk.virtualWrite (V0, kelembabanPersen);
  Blynk.virtualWrite (V1, nilaiADC);

  Serial.print("Nilai ADC: ");
  Serial.print(nilaiADC);
  Serial.print(" | Kelembaban Tanah: ");
  Serial.print(kelembabanPersen);
  Serial.println("%");
  delay (1000);

  lcd.print("kelembaban: ");
  lcd.print(kelembabanPersen);
  lcd.print("% ");
  lcd.setCursor(0, 0);
  lcd.setCursor(0, 1);
  lcd.print("Nilai ADC: ");
  lcd.print(nilaiADC);
  lcd.print("% ");
  delay(1000);

}
