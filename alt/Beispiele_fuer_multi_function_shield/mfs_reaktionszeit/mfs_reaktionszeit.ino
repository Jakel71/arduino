/*
 * Make-Magazin, https://www.heise.de/make/
 * 
 * Demo fuer Multi Function Shield
 * 
 * 7-Segment-Display mit Timer
 * Reaktionszeittester: zeigt 1-3 und wartet auf Taste. Zeigt dann die Zeit in ms an
 * Poti liefert Analogwert fuer Zufallszahlenstartwert
 */

const uint8_t LATCH = 4;
const uint8_t CLK = 7;
const uint8_t DATA = 8;
const uint8_t BUZZER = 3;
const uint8_t BUTTON1 = A1;
const uint8_t BUTTON2 = A2;
const uint8_t BUTTON3 = A3;
const uint8_t POTI = A0;   
 
const uint8_t SEGMENT_MAP[] = {0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0X80,0X90};    // Segmente, die leuchten sollen pro Zahlwert (Low-Aktiv), & 0x7F Verknüpfen fuer Dezimalpunkt
const uint8_t SEGMENT_SELECT[] = {0xF1,0xF2,0xF4,0xF8};                               // Ziffernposition (gemeinsame Anode, LSB)

volatile uint8_t ActDigit = 0;
uint16_t DisplayValue = 0;
uint8_t i;   
uint32_t milli;

/*
 * @brief   Ausgabe einer Zahl an einer Position auf dem Display
 * @param   welche Position (0= links, 3=rechts)
 *          Zahlwert (0..9)
 * @return  none
 */
void WriteNumberToSegment(uint8_t digit, uint8_t value)
{
  digitalWrite(LATCH,LOW);                                // Uebernahme-Takt: Ausgang Aus
  shiftOut(DATA, CLK, MSBFIRST, SEGMENT_MAP[value]);      // Segmente passend zum Zahlwert rausschieben
  shiftOut(DATA, CLK, MSBFIRST, SEGMENT_SELECT[digit]);   // Welche Stelle leuchten soll hinterher schieben
  digitalWrite(LATCH,HIGH);                               // Uebernahme-Takt: Ausgang Ein
}

/*
 * @brief   Ausgabe einer Zahl auf dem Display ohne fuehrende Nullen
 * @param   Zahl 0..9999
 * @return  none
 */
ISR(TIMER1_COMPA_vect)          
{
  switch (++ActDigit)
  {
    case 1 : if (DisplayValue >= 1000) WriteNumberToSegment(0, DisplayValue / 1000); break;     
    case 2 : if (DisplayValue >= 100) WriteNumberToSegment(1, (DisplayValue / 100) % 10); break; 
    case 3 : if (DisplayValue >= 10) WriteNumberToSegment(2, (DisplayValue / 10) % 10); break; 
    case 4 : WriteNumberToSegment(3, DisplayValue % 10); ActDigit = 0; break; 
  }
} 

void setup ()
{
  pinMode(LATCH,OUTPUT);
  pinMode(CLK,OUTPUT);
  pinMode(DATA,OUTPUT);
  digitalWrite(BUZZER, HIGH);         // BUZZER aus. Einschaltknacken unterdruecken: Erst deaktivieren, dann Ausgang
  pinMode(BUZZER, OUTPUT);
  pinMode(BUTTON1, INPUT);    
  pinMode(BUTTON2, INPUT);    
  pinMode(BUTTON3, INPUT);    
  pinMode(POTI, INPUT);    

  // Timer1, f = 124,87 Hz
  TCCR1A = 0;                                           // Register loeschen
  OCR1A = 1000;                                         // Vergleichswert x = (CPU / (2 x Teiler x f)) - 1
  TCCR1B |= (1 << CS10) | (1 << CS11) | (1 << WGM12);   // CTC-Mode, Teiler = 64
  TIMSK1 |= (1 << OCIE1A);                              // Output Compare A Match Interrupt Enable
  sei();                                                // IRQ Enable

  randomSeed(analogRead(POTI));       // A/D-Wert vom Poti einlesen und als Zufallsgeneratorstartwert nutzen
}
 
void loop()
{
  for (i = 0; i <= random(40, 80); i++)     // "Wuerfeln" simulieren: 40-80 Durchgaenge
  {
    DisplayValue = i % 10;            // 0..9
    delay (40);
  }
  
  milli = millis();                   // Zeit seit Arduino Start
  DisplayValue = random(1, 4);        // Zufallszahl 1-3 anzeigen
  i = 0;

  while (digitalRead(BUTTON1) && digitalRead(BUTTON2) && digitalRead(BUTTON3));   // warte auf Tastendruck

  if ((!digitalRead(BUTTON1) && (DisplayValue == 1)) || (!digitalRead(BUTTON2) && (DisplayValue == 2)) || (!digitalRead(BUTTON3) && (DisplayValue == 3)))   // wenn Taster 1 gedrueckt und 1 angezeigt usw.
  {
    milli = millis() - milli;       // Reaktionszeit in ms berechnen
    if (milli > 9999)               // wenn laenger als 10 Sekunden
    {
        digitalWrite(BUZZER, LOW);  // ein
        delay (100);
        digitalWrite(BUZZER, HIGH); // aus
        DisplayValue = 0;
    }
    else
      DisplayValue = milli;
  }
  else
  {
      digitalWrite(BUZZER, LOW);    // ein
      delay (100);
      digitalWrite(BUZZER, HIGH);   // aus
  }

  delay (50);                       // prellen abwarten
  while (!digitalRead(BUTTON1));    // warte auf Taster 1 losgelassen (wenn dieser zuvor gedrueckt wurde) damit anschliessendes warten nicht uebersprungen wird
  while (digitalRead(BUTTON1));     // warte auf Taster 1 gedrueckt
  delay (50);                       // prellen abwarten
  while (!digitalRead(BUTTON1));    // warte auf Taster 1 losgelassen 
}

