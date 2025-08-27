void setup() {
pinMode (2, OUTPUT);
pinMode (3, OUTPUT);
pinMode (4, OUTPUT);
pinMode (5, OUTPUT);// BUZZER

}

void loop() {
digitalWrite (2, LOW);// MERAH
digitalWrite (3, HIGH);
digitalWrite (4, HIGH);
digitalWrite (5, HIGH);
delay (10);
digitalWrite (5, LOW);
delay (10);

digitalWrite (2, HIGH);// BIRU
digitalWrite (3, LOW);
digitalWrite (4, HIGH);
digitalWrite (5, HIGH);
delay (15);
digitalWrite (5, LOW);
delay (10);

digitalWrite (2, HIGH);// HIJAU
digitalWrite (3, HIGH);
digitalWrite (4, LOW);
digitalWrite (5, HIGH);
delay (20);
digitalWrite (5, LOW);
delay (10);

digitalWrite (2, LOW);// UNGU
digitalWrite (3, LOW);
digitalWrite (4, HIGH);
digitalWrite (5, HIGH);
delay (25);
digitalWrite (5, LOW);
delay (10);

digitalWrite (2, LOW);// KUNING
digitalWrite (3, HIGH);
digitalWrite (4, LOW);
digitalWrite (5, HIGH);
delay (30);
digitalWrite (5, LOW);
delay (10);

digitalWrite (2, HIGH);// CYAN
digitalWrite (3, LOW);
digitalWrite (4,LOW);
digitalWrite (5, HIGH);
delay (35);
digitalWrite (5, LOW);
delay (10);
}
