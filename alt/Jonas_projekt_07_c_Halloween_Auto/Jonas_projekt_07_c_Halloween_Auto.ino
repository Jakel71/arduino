int Bewegung    = 0;
int firstRun = 1;

void setup() {
  // put your setup code here, to run once:
  pinMode(2, INPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);

  digitalWrite(4,HIGH);
}

void blitzen() {
  digitalWrite(4, LOW);
  
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);  
  delay(100);               
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  delay(100);                
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);
  delay(100);               
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  delay(500);               
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);
  delay(100);               
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  delay(100);
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);
  delay(100);              
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  delay(500);
  
  digitalWrite(4, HIGH);
  }

void uebergang() {
  
  digitalWrite(6, HIGH);
  delay(200);
  digitalWrite(4, LOW);
  delay(200);
  digitalWrite(7, HIGH);
  delay(200);
  digitalWrite(6, LOW);
  delay(200);
  digitalWrite(4, HIGH);
  delay(200);
  digitalWrite(7, LOW);
  delay(200);
  }

void aus () {
  digitalWrite(4, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
}

void an () {
  digitalWrite(7, HIGH);
  digitalWrite(6, HIGH);
  delay(40);
  digitalWrite(4, HIGH);
  delay(10);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
}
  
void loop() {
  // put your main code here, to run repeatedly:
  blitzen();
  delay(2000);
  uebergang();
  delay(2000);
  aus();
  delay(2000);
  an();
  delay(10000);
  
  
}
