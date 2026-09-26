int heinz = 1000;
int a = HIGH;
void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, INPUT);
  digitalWrite(9, HIGH);
  pinMode(8, INPUT);
  digitalWrite(8, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:


  a = digitalRead(9);
  if (a == HIGH) {
    heinz = heinz + 20;

  } else {
    heinz = heinz - heinz / 8;

  }

  a = digitalRead(8);
  if (a == LOW) {
    digitalWrite(10, HIGH);   //    turn the LED on (HIGH is the voltage level)
    delay(heinz);
    digitalWrite(10, LOW);
    digitalWrite(11, HIGH);   //    turn the LED on (HIGH is the voltage level)
    delay(heinz);
    digitalWrite(11, LOW);
    digitalWrite(12, HIGH);   //    turn the LED on (HIGH is the voltage level)
    delay(heinz);
    digitalWrite(12, LOW);
  } else {
    digitalWrite(10, HIGH);   //    turn the LED on (HIGH is the voltage level)
    delay(heinz);
    digitalWrite(10, LOW);
    digitalWrite(12, HIGH);   //    turn the LED on (HIGH is the voltage level)
    delay(heinz);
    digitalWrite(12, LOW);
    digitalWrite(11, HIGH);   //    turn the LED on (HIGH is the voltage level)
    delay(heinz);
    digitalWrite(11, LOW);
  }

}
