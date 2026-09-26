/*
 * Make-Magazin, https://www.heise.de/make/
 * 
 * Demo fuer Multi Function Shield
 * 
 * Tasten -> LEDs + Buzzer
 */

const uint8_t LED1 = 13;      // Pinbelegung
const uint8_t LED2 = 12;
const uint8_t LED3 = 11;
const uint8_t BUZZER = 3;
const uint8_t BUTTON1 = A1;
const uint8_t BUTTON2 = A2;
const uint8_t BUTTON3 = A3;
 
void setup()
{
  pinMode(LED1, OUTPUT);      // I/O-Pin als Ausgang
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  pinMode(BUTTON1, INPUT);    // I/O-Pin als Eingang
  pinMode(BUTTON2, INPUT);    
  pinMode(BUTTON3, INPUT);    

  digitalWrite(LED1, HIGH);   // LED aus
  digitalWrite(LED2, HIGH);   // LED aus
  digitalWrite(LED3, HIGH);   // LED aus
  digitalWrite(BUZZER, HIGH); // BUZZER aus (Low-Aktiv)
}
 
void loop()
{
  if (!digitalRead(BUTTON1))    // wenn Taster gedrueckt ist, dann ... (Low-Aktiv => gedrueckt = LOW)
    digitalWrite(LED1, LOW);    // LED ein
  else                          // ... andernfalls:
    digitalWrite(LED1, HIGH);   // LED aus

  if (!digitalRead(BUTTON2))    
    digitalWrite(LED2, LOW);    
  else
    digitalWrite(LED2, HIGH); 

  if (!digitalRead(BUTTON3)) 
  {   
    digitalWrite(BUZZER, LOW);    // BUZZER
    digitalWrite(LED3, LOW);    
  }
  else
  {
    digitalWrite(BUZZER, HIGH); 
    digitalWrite(LED3, HIGH);    
  }   
}

