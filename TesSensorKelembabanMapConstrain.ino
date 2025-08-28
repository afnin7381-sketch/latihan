int sensorPin = 36;
int nilaiSensor;
int kelembabanPersen;

void setup() {
Serial.begin (9600);
}

void loop() {
nilaiSensor = analogRead(sensorPin); 
kelembabanPersen = map (nilaiSensor, 2907, 1098, 0, 100);
kelembabanPersen = constrain (kelembabanPersen, 0,100);


Serial.print ("nilaiSensor: ");
Serial.print (nilaiSensor );
Serial.print (" | kelembabanPersen: ");
Serial.print (kelembabanPersen );
Serial.print ("%");
delay (1000);
}
