int a = 1;

void setup() {
  // put your setup code here, to run once:
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (a < 4) {
    digitalWrite(2, HIGH);delay(100);
    digitalWrite(3, HIGH);delay(100);
    digitalWrite(4, HIGH);delay(100);
    digitalWrite(5, HIGH);delay(100);
    digitalWrite(6, HIGH);delay(100);
    digitalWrite(7, HIGH);delay(100);
    digitalWrite(8, HIGH);delay(100);
    digitalWrite(9, HIGH);delay(100);
    digitalWrite(10, HIGH);delay(100);
    digitalWrite(11, HIGH);delay(500);
    digitalWrite(2, LOW);delay(100);
    digitalWrite(3, LOW);delay(100);
    digitalWrite(4, LOW);delay(100);
    digitalWrite(5, LOW);delay(100);
    digitalWrite(6, LOW);delay(100);
    digitalWrite(7, LOW);delay(100);
    digitalWrite(8, LOW);delay(100);
    digitalWrite(9, LOW);delay(100);
    digitalWrite(10, LOW);delay(100);
    digitalWrite(11, LOW);delay(500);
  }  else {
    if ((a>3) && (a<7)) {
      digitalWrite(2, HIGH);digitalWrite(3, HIGH);digitalWrite(4, HIGH);digitalWrite(5, HIGH);digitalWrite(6, HIGH);digitalWrite(7, HIGH);
      digitalWrite(8, HIGH);digitalWrite(9, HIGH);digitalWrite(10, HIGH);digitalWrite(11, HIGH);
      delay(200);
      digitalWrite(2, LOW);digitalWrite(3, LOW);digitalWrite(4, LOW);digitalWrite(5, LOW);digitalWrite(6, LOW);digitalWrite(7, LOW);
      digitalWrite(8, LOW);digitalWrite(9, LOW);digitalWrite(10, LOW);digitalWrite(11, LOW);
      delay(200);
    } else {
        if (a==7){ 
          digitalWrite(11, HIGH); delay(400); digitalWrite(11, LOW); delay(200);
          digitalWrite(2, HIGH); digitalWrite(10, HIGH); delay(200);
          digitalWrite(2, LOW); digitalWrite(10, LOW); delay(200);
          digitalWrite(3, HIGH); digitalWrite(9, HIGH); delay(200);
          digitalWrite(3, LOW); digitalWrite(9, LOW); delay(200);
          digitalWrite(4, HIGH); digitalWrite(8, HIGH); delay(200);
          digitalWrite(4, LOW); digitalWrite(8, LOW); delay(200);
          digitalWrite(5, HIGH); digitalWrite(7, HIGH); delay(200);
          digitalWrite(5, LOW); digitalWrite(7, LOW); delay(200);
          
          digitalWrite(6, HIGH);delay(200);digitalWrite(6, LOW);delay(200);
          
          digitalWrite(5, HIGH); digitalWrite(7, HIGH); delay(200);
          digitalWrite(5, LOW); digitalWrite(7, LOW); delay(200);
          digitalWrite(4, HIGH); digitalWrite(8, HIGH); delay(200);
          digitalWrite(4, LOW); digitalWrite(8, LOW); delay(200);
          digitalWrite(3, HIGH); digitalWrite(9, HIGH); delay(200);
          digitalWrite(3, LOW); digitalWrite(9, LOW); delay(200);
          digitalWrite(2, HIGH); digitalWrite(10, HIGH); delay(200);
          digitalWrite(2, LOW); digitalWrite(10, LOW); delay(200);
          digitalWrite(11, HIGH); delay(200); digitalWrite(11, LOW); delay(200);}
        else{
          digitalWrite(3, HIGH); digitalWrite(8, HIGH); delay(1000);
          digitalWrite(8, LOW); digitalWrite(10, HIGH);digitalWrite(4, HIGH); delay(1000);
          digitalWrite(3, LOW);digitalWrite(1, HIGH);digitalWrite(10, LOW); delay(1000);
          digitalWrite(9, HIGH);digitalWrite (6, HIGH);digitalWrite(4, LOW); delay(1000);
          digitalWrite(5, HIGH);digitalWrite(2, HIGH);digitalWrite(6, LOW);digitalWrite(1, LOW); delay(1000);
          digitalWrite(9, LOW); digitalWrite(2, LOW);digitalWrite(11, HIGH); delay(1000);
          digitalWrite(11, LOW);digitalWrite(7, HIGH);digitalWrite(5, LOW); delay(1000);
          digitalWrite(7, LOW);delay(1000);
        }
        }

    }
  

  if (a < 8)
  {
    a=a + 1;
  }
  else
  {
    a = 1;
  }
}
