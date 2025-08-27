
#include "DHT.h"
DHT dht (2, DHT11);

void setup() {
 Serial.begin(9600);
 dht.begin();

}

void loop() {
  // delay (2000);
  float kelembaban = dht.readHumidity();
  float suhu = dht.readTemperature(); // Dalam Celsius

  Serial.print("Kelembaban: ");
  Serial.println(kelembaban);
  Serial.print("Suhu: ");
  Serial.println (suhu);
  delay(2000);
 
}
