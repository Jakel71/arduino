int Bewegung = 0;
int firstRun = 1;

void setup() {
  // put your setup code here, to run once:
  pinMode(2, INPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);

  digitalWrite(6, LOW);
  digitalWrite(4, HIGH);
}

void blitzen(int dauer) {
  digitalWrite(6, HIGH); delay (dauer); digitalWrite(6, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:

  Bewegung = digitalRead(2);
  digitalWrite(5, Bewegung);
  if (Bewegung == 1) {
    if (firstRun == 1) {
      digitalWrite(4, HIGH);
      firstRun = 0;
      delay(400); blitzen(20);
      delay (1000); blitzen(40);
      delay (400);  blitzen(40);
    }
  } else {
    digitalWrite(4, LOW);
    firstRun = 1;
  }
}
