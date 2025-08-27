void setup (){
pinMode (2, OUTPUT);// biru
pinMode (3, OUTPUT);// kuning
pinMode (4, OUTPUT);// hijau
pinMode (5, OUTPUT);// merah
digitalWrite (2, HIGH);// ON
digitalWrite (3, LOW);//
digitalWrite (4, LOW);//
digitalWrite (5, HIGH);//
delay (10000);
digitalWrite (2, LOW);
digitalWrite (3, HIGH);
digitalWrite (4, HIGH);
digitalWrite (5, LOW);
delay (10000);
digitalWrite (2, HIGH);
digitalWrite (3, LOW);
digitalWrite (4, HIGH);
digitalWrite (5, HIGH);
delay (10000);
digitalWrite (2, LOW);
digitalWrite (3, LOW);
digitalWrite (4, LOW);
digitalWrite (5, LOW);
delay (10000);
}

void loop() {
}