void setup(){
pinMode  (2, OUTPUT);// merah
pinMode  (3, OUTPUT);//hijau
pinMode  (4, OUTPUT);// biru
pinMode  (5, OUTPUT);// orange
pinMode  (6, OUTPUT);
}

void loop() {
digitalWrite (6, HIGH);// lampu led ON
digitalWrite (2, HIGH);
digitalWrite (3, LOW);
digitalWrite (4, LOW);
digitalWrite (5, LOW);
delay (100);//
digitalWrite (6, LOW);
digitalWrite (2, LOW);// lampu led off
digitalWrite (3, HIGH);
digitalWrite (4, HIGH);
digitalWrite (5, HIGH);
delay (110);//
digitalWrite (6, HIGH);
digitalWrite (2, HIGH);// lampu led off
digitalWrite (3, LOW);
digitalWrite (4, LOW);
digitalWrite (5, HIGH);
delay (130);//
digitalWrite (6, LOW);
digitalWrite (2, HIGH);// lampu led off
digitalWrite (3, HIGH);
digitalWrite (4, HIGH);
digitalWrite (5, LOW);
delay (160);//
digitalWrite (6, HIGH);
digitalWrite (2, LOW);// lampu led off
digitalWrite (3, HIGH);
digitalWrite (4, LOW);
digitalWrite (5, HIGH);
delay (190);//
}