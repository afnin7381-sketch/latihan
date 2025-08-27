const int buttonPin1 = 13;  // the number of the pushbutton pin
const int buttonPin2 = 12;
const int ledPin = 5;  // the number of the LED pin

// variables will change:
int buttonState1 = 0;  // variable for reading the pushbutton status
int buttonState2 = 0;  // variable for reading the pushbutton status
  // variable for reading the pushbutton status
int p = 0;

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin1, INPUT_PULLUP);
  pinMode(buttonPin2, INPUT_PULLUP);
}

void loop() {
  // read the state of the pushbutton value:
  buttonState1 = digitalRead(buttonPin1);
  buttonState2 = digitalRead(buttonPin2);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState1 == LOW) {
    // turn LED on:
    digitalWrite(ledPin, HIGH);
  } else {
    // turn LED off:
    digitalWrite(ledPin, LOW);
  }

  if (buttonState2 == LOW) {
    p++;
    delay(200);
  }

  if (p == 1) {
    digitalWrite(ledPin, HIGH);
  }
  if (p == 2) {
    digitalWrite(ledPin, LOW);
    p = 0;
  }
}
