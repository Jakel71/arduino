/*
 * Make-Magazin, https://www.heise.de/make/
 * 
 * Demo fuer Multi Function Shield
 * 
 * 7-Segment-Display
 */

const uint8_t LATCH = 4;
const uint8_t CLK = 7;
const uint8_t DATA = 8;
 
const uint8_t SEGMENT_MAP[] = {0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0X80,0X90};    // Segmente, die leuchten sollen pro Zahlwert (Low-Aktiv), & 0x7F Verknüpfen fuer Dezimalpunkt
const uint8_t SEGMENT_SELECT[] = {0xF1,0xF2,0xF4,0xF8};                               // Ziffernposition (gemeinsame Anode, LSB)

volatile uint8_t ActDigit = 0;
uint16_t DisplayValue = 0;

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
 * @brief   Ausgabe einer Zahl auf dem Display
 * @param   Zahl 0..9999
 * @return  none
 */
ISR(TIMER1_COMPA_vect)          // interrupt service routine that wraps a user defined function supplied by attachInterrupt
{
  switch (++ActDigit)
  {
    case 1 : WriteNumberToSegment(0, DisplayValue / 1000); break;     
    case 2 : WriteNumberToSegment(1, (DisplayValue / 100) % 10); break; 
    case 3 : WriteNumberToSegment(2, (DisplayValue / 10) % 10); break; 
    case 4 : WriteNumberToSegment(3, DisplayValue % 10); ActDigit = 0; break; 
  }
} 

void setup ()
{
  pinMode(LATCH,OUTPUT);
  pinMode(CLK,OUTPUT);
  pinMode(DATA,OUTPUT);

  TCCR1A = 0;                                           // Register loeschen
  OCR1A = 1000;                                         // Vergleichswert x = (CPU / (2 x Teiler x f)) - 1
  TCCR1B |= (1 << CS10) | (1 << CS11) | (1 << WGM12);   // CTC-Mode, Teiler = 64
  TIMSK1 |= (1 << OCIE1A);                              // Output Compare A Match Interrupt Enable
  sei();                                                // IRQ Enable
}
 
void loop()
{
  DisplayValue = 1234;
  delay (1000);
}

