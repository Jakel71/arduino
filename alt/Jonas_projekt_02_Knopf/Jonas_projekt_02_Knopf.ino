int a=0;

void setup() {
  // put your setup code here, to run once:
pinMode(15,INPUT);
digitalWrite(15,HIGH);
pinMode(13,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  a=digitalRead(15);
  if (a==HIGH) {
    digitalWrite(13, HIGH);
  } else {
    digitalWrite(13, LOW);
  }
}
