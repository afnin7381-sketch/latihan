int sensorPin = 36;

void setup() {
Serial.begin (9600);
}

void loop() {
Serial.println(analogRead(sensorPin));
 // put your main code here, to run repeatedly:
delay (500);
}
