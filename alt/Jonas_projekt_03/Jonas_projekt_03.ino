int dauer = 100;
int richtung = 1;
int pin = 11;
int Knopf_1 = HIGH;


void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, INPUT);
  digitalWrite(9, HIGH);
  pinMode(8, INPUT);
  digitalWrite(8, HIGH);
}

void blitzen(int pin, int dauer) {
  digitalWrite(pin, HIGH);
  delay(dauer);
  digitalWrite(pin, LOW);
}

void loop() {
  if (digitalRead(9) == LOW)
  if (Knopf_1 == HIGH) {
      Knopf_1 = LOW;
      if(dauer == +10) {
        dauer= -10;
      } else {
        dauer = +10;
       else{Knopf_1=HIGH;
    }

  if (digitalRead(8) == LOW) {
    if (Knopf_1 == HIGH) {
      Knopf_1 = LOW;
      if (richtung == +1) {
        richtung = -1;
      } else {
        richtung = +1;
      }
    }

  } else {
    Knopf_1 = HIGH;
  }
  blitzen(pin, dauer);
  pin = pin + richtung;

  if (pin == 13) pin = 10;
  if (pin == 9)  pin = 12;


}
