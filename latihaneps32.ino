#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID "TMPL6Fq181F1p"
#define BLYNK_TEMPLATE_NAME "PROJECT1ESP32"
#define BLYNK_AUTH_TOKEN "85p-VsQ9EOg_0hHVzZFeFb8MLLIx0aJt"

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4); 


char ssid[] = "Ws-Eletronika";
char pass[] = "@bpvppdg25";


void setup() {
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  Serial.begin(115200);
  pinMode(2, OUTPUT);
  lcd.init();
  lcd.backlight();
}

void loop() {
  Blynk.run();

  digitalWrite(2, HIGH);
  lcd.print("ON");
  lcd.setCursor(4, 0);
  delay(1000);
  lcd.clear();

  digitalWrite(2, LOW);
  lcd.print("OFF");
  lcd.setCursor(4, 0);
  delay(1000);
  lcd.clear();
}
