#include <Wire.h>
#include <RTClib.h>
#include <LiquidCrystal_I2C.h>
bool alarmAktive = false;

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int ledPin = 5;

RTC_DS3231 rtc;
char daysOfTheWeek[7][12] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };

void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
  lcd.init();
  lcd.backlight();


  // initializing the rtc
  if (!rtc.begin()) {
    Serial.println("RTC tidak terdeteksi!");
    while (1)
      ;
  }

  if (rtc.lostPower()) {
    Serial.println("RTC kehilangan daya, atur waktu sekarang?");
    // set waktu manual: rtc.adjust(DateTime(year, month, day, hour, minute, second));
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }
}

void loop() {
  DateTime now = rtc.now();  //ambil waktu sekarang

  Serial.print(now.day());
  Serial.print("/");
  Serial.print(now.month());
  Serial.print(" / ");
  Serial.print(now.year());
  Serial.print("Waktu: ");
  Serial.print(now.hour());
  Serial.print(":");
  Serial.print(now.minute());
  Serial.print(":");
  Serial.println(now.second());
  delay(200);

  lcd.setCursor(0, 0);
  lcd.print(now.day());
  lcd.print("/");
  lcd.print(now.month());
  lcd.print(" / ");
  lcd.print(now.year());
  lcd.setCursor(0, 1);
  lcd.print(now.hour());
  lcd.print(":");
  lcd.print(now.minute());
  lcd.print(":");
  lcd.print(now.second());
  delay(200);

  if (now.hour() == 11 && now.minute() == 33) {
    alarmAktive = true;
  } else {
    alarmAktive = false;
  }

  if (alarmAktive) {
    digitalWrite(ledPin, HIGH);
    delay(100);
    digitalWrite(ledPin,E; LOW);
    delay(100);
  } else {
    // turn LED off:
    digitalWrite(ledPin, LOW);
    delay(1000);
  }



}
