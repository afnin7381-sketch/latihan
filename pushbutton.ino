const int buttonPin = 4;
const int ledPin = 2;

int buttonState = 0;
int p;

void setup() {
  pinMode (ledPin, OUTPUT);
  pinMode (buttonPin, INPUT_PULLUP);

}

void loop() {
buttonState = digitalRead (buttonPin);
if (buttonState == LOW){
p++;
delay (200);
}

if (p==1){
  digitalWrite (2, HIGH);
}
if (p==2){
  digitalWrite (2, LOW);
  p=0;
}
}
