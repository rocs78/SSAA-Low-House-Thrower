const int buttonPin = 2;     
const int ledPin =  9;
const int pwrPin = 8;
const int dip1 = 4;
const int dip2 = 5;
const int dip3 = 6;
const int dip4 = 7;
const int relay1 = 11;    
 
// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status
int dip1state = 0;
int dip2state = 0;
int dip3state = 0;
int dip4state = 0;
int holdtime = 0;
 
void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(pwrPin, OUTPUT);
  pinMode(relay1, OUTPUT);
  pinMode(buttonPin, INPUT);
  pinMode(dip1, INPUT_PULLUP);
  pinMode(dip2, INPUT_PULLUP);
  pinMode(dip3, INPUT_PULLUP);
  pinMode(dip4, INPUT_PULLUP);
  digitalWrite(pwrPin, HIGH);
 
  digitalWrite(buttonPin, HIGH);
  
}
 
void loop() {
  holdtime = 0;
  buttonState = digitalRead(buttonPin);
  dip1state = digitalRead(dip1);
  dip2state = digitalRead(dip2);
  dip3state = digitalRead(dip3);
  dip4state = digitalRead(dip4);
  if (dip1state == LOW) {
    holdtime = holdtime + 100;
  } else {
    holdtime = holdtime;
  }
  if (dip2state == LOW) {
    holdtime = holdtime + 200;
  } else {
    holdtime = holdtime;
  }  

    if (dip3state == LOW) {
    holdtime = holdtime + 400;
  } else {
    holdtime = holdtime;
  }

    if (dip4state == LOW) {
    holdtime = holdtime + 800;
  } else {
    holdtime = holdtime;
  }

  
  if (digitalRead(buttonPin)==LOW) {
    digitalWrite(ledPin, HIGH);
    digitalWrite(relay1, HIGH);
    delay(holdtime);
  } else {
    digitalWrite(ledPin, LOW);
    digitalWrite(relay1, LOW);
  }
}
