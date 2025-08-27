#include <Wire.h>
#include <RTClib.h>
// #include <Wire.h>

RTC_DS3231 rtc;

void setup() {
  Serial.begin(115200);

  // initializing the rtc
  if (!rtc.begin()) {
    Serial.println("RTC tidak terdeteksi!");
    while (1);
  }

  if (rtc.lostPower()) {
    Serial.println("RTC kehilangan daya, atur waktu sekarang?");
    // set waktu manual: rtc.adjust(DateTime(year, month, day, hour, minute, second));
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }
}

void loop() {
  DateTime now = rtc.now();  //ambil waktu sekarang

  Serial.print("tanggal: ");
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
  delay(1000);
}
