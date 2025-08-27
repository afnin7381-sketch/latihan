#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int btnBack = 13;
const int btnDown = 12;
const int btnUp = 14;
const int btnOK = 27;
const int sensorPin = 36;

int menu = 0;
int totalMenu = 2;

bool setMenuState = false;

void setup() {
  lcd.init();
  lcd.backlight();

  pinMode(btnBack, INPUT_PULLUP);
  pinMode(btnDown, INPUT_PULLUP);
  pinMode(btnUp, INPUT_PULLUP);
  pinMode(btnOK, INPUT_PULLUP);
  tampilMenu();
}

void loop() {
  if (digitalRead(btnDown) == LOW) {
    menu++;
    if (menu > totalMenu) menu = 0;
    tampilMenu();
    delay(200);
  }
  else if (digitalRead(btnUp) == LOW) {
    menu--;
    if (menu < 0) menu = totalMenu;
    tampilMenu();
    delay(200);
  }
  else if (digitalRead(btnOK) == LOW) {
    delay (200);
    setMenuState = true;
  }
  else if (digitalRead(btnBack) == LOW) {
    delay(200);
    tampilMenu();
    if (setMenuState) setMenuState = false;
  }

  if (setMenuState){
    if (menu == 0) tampilSet("Suhu", analogRead(sensorPin));
    else if (menu == 1) tampilSet ("Setting", 700);
    else if (menu == 2) tampilSet ("Run Program", 0);
    delay (200);
  }
}

void tampilMenu() {
  lcd.clear();
  if (menu == 0) lcd.print(">Suhu");
  if (menu == 1) lcd.print(">Setting");
  if (menu == 2) lcd.print(">Run Program");
}

void tampilSet(String label, int nilai) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(label);
  lcd.setCursor(0, 1);
  lcd.print("Nilai:");
  lcd.print(nilai);
  // delay(2000);
  // tampilMenu();
}
