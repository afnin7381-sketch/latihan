#define BLYNK_TEMPLATE_ID "TMPL6Bqckz382"
#define BLYNK_TEMPLATE_NAME "SUHU"
#define BLYNK_AUTH_TOKEN "f6oFyhkj3Y8H9amakZ_gZ96PKzgOOrEd"

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include "DHT.h"

DHT dht(4, DHT11);

char ssid[] = "Ws-Eletronika";
char pass[] = "@bpvppdg25";

int suhu;

void setup() {
  Serial.begin(115200);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  dht.begin();
}

void loop() {
  Blynk.run();
  float suhu = dht.readTemperature();  // Dalam Celsius
  Blynk.virtualWrite(V0, suhu);        

  if (suhu > 29) {
    Blynk.virtualWrite(V1, 1);  //led on
    Blynk.virtualWrite(V2, "Tolong Aku");
  } else {
    Blynk.virtualWrite(V1, 0);  //of
    Blynk.virtualWrite(V2, "");
    
  }
  delay(2000);
}
