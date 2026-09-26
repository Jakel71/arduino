const int controlPin1A = 2;
const int controlPin2A = 5;
const int EnablePin = 9;
int motorSpeed = 200;
int motorDirection = 1;

void SetMotorControl() {
  if (motorDirection == 1) //Forward
  {
    digitalWrite (controlPin1A, HIGH);
    digitalWrite (controlPin2A, LOW);
   } else{
    digitalWrite (controlPin1A, LOW);
    digitalWrite (controlPin2A, HIGH);
   }
  analogWrite (EnablePin, motorSpeed);
}

void setup() {
  // put your setup code here, to run once:
 pinMode (controlPin1A, OUTPUT);
 pinMode (controlPin2A, OUTPUT);
 pinMode ( EnablePin, OUTPUT);

 digitalWrite(EnablePin, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay (500);
  //motorSpeed += 1; 
  //if (motorSpeed > 200)
  //{
    //motorSpeed = 0;
  //}
  SetMotorControl();
}
