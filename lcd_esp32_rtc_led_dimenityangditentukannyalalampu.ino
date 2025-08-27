#include <Wire.h>
#include <RTClib.h>
#include <LiquidCrystal_I2C.h>

RTC_DS3231 rtc;
LiquidCrystal_I2C lcd(0x27, 16, 2); // Alamat I2C LCD

const int ledPin = 5; // Pin LED

void setup() {
  // Inisialisasi LCD
  lcd.init();
  lcd.backlight();
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
  
  // Inisialisasi RTC
  if (!rtc.begin()) {
    Serial.println("RTC tidak ditemukan!");
    while (1);
  }

}

void loop() {
  DateTime now = rtc.now();

  // Tampilkan waktu saat ini di LCD
  lcd.setCursor(0, 0);
  lcd.print("Waktu: ");
  lcd.print(now.hour());
  lcd.print(":");
  lcd.print(now.minute());
  lcd.print(":");
  lcd.print(now.second());

  // Nyalakan LED setiap detik ke-30
  if (now.second() == 37) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }

  // Jika waktu mencapai jam 18:00
  if (now.hour() == 14 && now.minute() == 0 && now.second() == 0) {
    lcd.clear();
    lcd.print("Waktu Habis");
    for (int i = 0; i < 10; i++) { // Berkedip selama 10 detik
      digitalWrite(ledPin, HIGH);
      delay(500); // LED hidup selama 0.5 detik
      digitalWrite(ledPin, LOW);
      delay(500); // LED mati selama 0.5 detik
    }
    delay(1000); // Tunggu 1 detik sebelum melanjutkan
  }

  delay(1000); // Cek setiap detik
}