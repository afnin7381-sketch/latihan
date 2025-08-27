const int buttonPin1 = 14;  // led
const int buttonPin2 = 27;  // sensor tanah
const int ledPin = 5;
const int pinSoil = 36;

int buttonState1 = 0;  // variable for reading the pushbutton status
int buttonState2 = 0;  // variable for reading the pushbutton status
int p = 0;

int nilaiADC;
int kelembabanPersen;

void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin1, INPUT_PULLUP);
  pinMode(buttonPin2, INPUT_PULLUP);
}

void loop() {
  buttonState1 = digitalRead(buttonPin1);
  buttonState2 = digitalRead(buttonPin2);

  nilaiADC = analogRead(pinSoil);
  kelembabanPersen = map(nilaiADC, 4095, 1775, 0, 100);
  kelembabanPersen = constrain(kelembabanPersen, 0, 100);

  if (buttonState1 == LOW) {
    // turn LED on:
    digitalWrite(ledPin, HIGH);
  } else {
    // turn LED off:
    digitalWrite(ledPin, LOW);
  }

  if (buttonState2 == LOW) {
    // turn sensor tanah on:
    digitalWrite(ledPin, HIGH);
    Serial.print(" | Kelembaban Tanah: ");
    Serial.print(kelembabanPersen);
    Serial.println("%");
    delay(100);
  }
}
