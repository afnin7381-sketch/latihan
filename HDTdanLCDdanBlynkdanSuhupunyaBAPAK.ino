#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID "TMPL67AQ_Zibv"
#define BLYNK_TEMPLATE_NAME "IRIGASI"
#define BLYNK_AUTH_TOKEN "XePhuGqjuuya9zueWXkV2Mo9Fq8e_cWh"

#include <Wire.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <LiquidCrystal_I2C.h>
#include "DHT.h"

LiquidCrystal_I2C lcd(0x27, 20, 4);
 DHT dht (4, DHT11);

char ssid[] = "Ws-Eletronika";
char pass[] = "@bpvppdg25";

const int btnBack = 13;
const int btnDown = 12;
const int btnUp = 14;
const int btnOK = 27;
const int sensorPin = 36;

int menu = 0;
int totalMenu = 3;
bool inSubmenu = false;
bool firstEnter = true;

void setup() {
  Serial.begin(9600);
  Blynk.begin( BLYNK_AUTH_TOKEN, ssid, pass);
  dht.begin ();
  lcd.init();
  lcd.backlight();

  pinMode(btnBack, INPUT_PULLUP);
  pinMode(btnDown, INPUT_PULLUP);
  pinMode(btnUp, INPUT_PULLUP);
  pinMode(btnOK, INPUT_PULLUP);

  lcd.setCursor(0, 0);
  lcd.print(">Set Suhu");
}

void loop() {
  Blynk.run();
  if (!inSubmenu){
  if (digitalRead(btnDown) == LOW) {
    menu++;
    if (menu > totalMenu) menu = 0;
    tampilMenu();
    delay(200);
  }
  if (digitalRead(btnUp) == LOW) {
    menu--;
    if (menu < 0) menu = totalMenu;
    tampilMenu();
    delay(200);
  }
  if (digitalRead(btnOK) == LOW) {
    delay(200);
    inSubmenu = true;
    firstEnter = true;
  }
}
else {
  if (menu == 0) {
    tampilSuhu();
    delay(500);
  } else if (menu == 2) {
    if (firstEnter) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Run Program...");
      firstEnter = false;
    }
  }

  if (digitalRead(btnBack) == LOW) {
    delay(200);
    inSubmenu = false;
    tampilMenu();
  }
}
}


void tampilMenu() {
  lcd.clear();
  if (menu == 0) lcd.print(">Set Suhu");
  if (menu == 1) lcd.print(">Setting");
  if (menu == 2) lcd.print(">Run Program");
}

void tampilSet(String lebel, int nilai) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(lebel);
  lcd.setCursor(0, 1);
  lcd.print("Nilai: ");
  lcd.print(nilai);
  delay(2000);
  tampilMenu();
}

void tampilSuhu() {
  float temp = dht. readTemperature();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Suhu(ADC);");
  lcd.setCursor(0, 1);
  lcd.print(temp); 
  Blynk.virtualWrite(V0, temp);
}