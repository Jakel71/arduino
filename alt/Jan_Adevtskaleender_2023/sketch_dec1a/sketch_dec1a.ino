int a = 0;
int b = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(1, INPUT);
  pinMode(2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  a = digitalRead(1);
  if(a=LOW){
    
    switch (b){
      
      case 0:
        digitalWrite(2,LOW);
        b = 3;
      
      case 1:
       digitalWrite(2,HIGH);
        b = 2;
      
    }
    delay (100);
    if(b==2) {
      b = 0;
    }else if (b==3){
      b = 1;
    }
  }
}
