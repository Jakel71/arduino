/*
 * Make-Magazin, https://www.heise.de/make/
 * 
 * Demo fuer Multi Function Shield
 * 
 * LED-Lauflicht
 */

const uint8_t LED1 = 13;
const uint8_t LED2 = 12;
const uint8_t LED3 = 11;
const uint8_t LED4 = 10;
const uint16_t SPEED = 300;    // Geschwindigkeit: ms die eine LED leuchtet
 
void setup()    // einmalige Ausfuehrung
{
  pinMode(LED1, OUTPUT);    // I/O-Pin als Ausgang
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
}
 
void loop()     // endlose Wiederholung
{
  digitalWrite(LED1, LOW);  // LEDs sind Low-Aktiv => leuchten bei LOW
  delay(SPEED);             // warte ms
  digitalWrite(LED1, HIGH); // LED aus

  digitalWrite(LED2, LOW);
  delay(SPEED);
  digitalWrite(LED2, HIGH);

  digitalWrite(LED3, LOW);
  delay(SPEED);
  digitalWrite(LED3, HIGH);

  digitalWrite(LED4, LOW);
  delay(SPEED);
  digitalWrite(LED4, HIGH);
}



