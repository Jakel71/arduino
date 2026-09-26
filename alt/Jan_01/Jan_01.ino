int a = 0;
int b = 0;
int c = 0;
int d = 0;
int e = 0;
int f = 0;
int g = 0;
int h = 0;
int i = 0;
int j = 0;
int m = 0;



void setup() {
  // Erstelle ein Programm, dass ein Mal ausgeführt wird
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  digitalWrite(7, HIGH);
  digitalWrite(5, HIGH);
  //Zum Initialisieren der Pins
  
  delay(1000);
  for (i = 0; i < 3; i++) {
    blitzen(7, 10);
    delay(500);
    blitzen(6, 10);
    delay(100);
    blitzen(7, 10);
    delay(100);
    blitzen(6, 10);
    delay(100);
  }
  blitzen(4, 20);

  digitalWrite(5, HIGH);
}





void loop() {
  // put your main code here, to run repeatedly:

  
  for(a=0; a<5; a=a+1){
    blitzen(7, 10);
    delay(500);
  }
  
 
  for (a = 4; a < 9; a = a + 1) {
    blitzen(a, 5);
    if (a == 8) {
      delay(100);
      blitzen(4, 10);
      blitzen(7, 1);
    }
  }
  for (b = 0; b < 3; b = b + 1) {
    delay(1000);
    blitzen(4, 10);
    blitzen(7, 1);
  }
  for (c = 0; c < 3; c = c + 1) {
    blitzen(7, 1);
    delay(100);
  }
  for (d = 0; d < 3; d = d + 1) {
    delay(1000);
    blitzen(7, 10);
    blitzen_all(20);
    blitzen(4, 3);
    blitzen(7, 10);
  }
  for (e = 0; e < 3; e = e + 1) {
    blitzen_all(50);
    blitzen(4, 10);
  }
  for (f = 0; f < 3; f = f + 1) {
    blitzen(7, 5);
    blitzen(4, 10);
  }

  for (g = 0; g < 3; f = f + 1) {
    blitzen(4, 50);
    blitzen_all(100);
  }
  
  for (h = 0; h < 999; h = h + 1) {
    m = random(8);
    while (m < 4) {
      m = random(8);
    }
    blitzen(m, 10);
  }

  blitzen(4, 10);
  blitzen(7, 1);
  blitzen_all(10);
}












void blitzen(int x, int y) {
  if (x == 7) {
    digitalWrite(x, LOW);
    delay(y * 100);
    digitalWrite(x, HIGH);
    delay(10);
  } else {
    digitalWrite(x, HIGH);
    delay(y * 100);
    digitalWrite(x, LOW);
    delay(10);
  }
}

void blitzen_all(int y) {
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(7, LOW);
  delay(y * 100);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, HIGH);
  delay(10);
}