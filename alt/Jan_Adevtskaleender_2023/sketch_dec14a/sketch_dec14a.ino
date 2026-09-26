int a = 0;
void setup() {
  // put your setup code here, to run once:
  digitalWrite(5, INPUT);
  digitalWrite(2, OUTPUT);
  digitalWrite(2, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  a = digitalRead(5);
  if (a == HIGH) {
    digitalWrite(2, HIGH);
    delay(10);
  } else {
    digitalWrite(2, LOW);
  }
}
