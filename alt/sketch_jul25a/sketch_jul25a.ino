int a=0;
int b=0;

void setup() {
pinMode(12,INPUT);
digitalWrite(12,LOW);
pinMode(13,OUTPUT);
}

void loop(){
    a=digitalRead(12);

  if (a==HIGH) {
    if (b==0) {
      b=1;
    } else if (b==1) {
      b=0;
     }
     delay(100000);
  } if (b=0){
    digitalWrite(13, LOW);
  } else if (b=1){
    digitalWrite(13, HIGH);
  }
}





