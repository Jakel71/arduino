void setup () 
{
  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(10,OUTPUT);
}

void loop() {
  digitalWrite(10,LOW);
  digitalWrite(13, HIGH);   
  delay(100);               
  digitalWrite(13, LOW);    
  delay(100);                
  digitalWrite(13, HIGH);   
  delay(100);               
  digitalWrite(13, LOW);    
  delay(100);               
  digitalWrite(13, HIGH);   
  delay(100);               
  digitalWrite(13, LOW);    
  delay(500);               
  }
