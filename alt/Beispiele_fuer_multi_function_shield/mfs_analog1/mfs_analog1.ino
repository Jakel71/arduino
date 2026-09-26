/*
 * Make-Magazin, https://www.heise.de/make/
 * 
 * Demo fuer Multi Function Shield
 * 
 * Poti A/D-Wandler -> Serieller Monitor
 */

const uint8_t POTI = A0;      // Pinbelegung
uint16_t ADwert;

void setup()
{
  Serial.begin(9600);
}
 
void loop()
{
  ADwert = analogRead(POTI);                  // A/D-Wert einlesen 
  Serial.print("Potentiometer A/D-Wert: ");   // Textausgabe
  Serial.print(ADwert);                       // Wert ausgeben
  Serial.print(" = ");   
  Serial.print(double (ADwert * .0048828), 2);    // Spannung berechnen und mit 2 Nachkommastellen ausgeben
  Serial.println(" V");                           // Text mit Zeilenumbruch ("ln") ausgeben
  
  delay(500);
}
