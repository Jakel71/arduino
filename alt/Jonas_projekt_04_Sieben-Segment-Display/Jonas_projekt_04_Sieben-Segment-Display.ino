/*
   Make-Magazin, https://www.heise.de/make/

   Demo fuer Multi Function Shield

   7-Segment-Display
*/

const uint8_t LATCH = 4;
const uint8_t CLK = 7;
const uint8_t DATA = 8;
// 0    1    2    3   4    5     6    7   8     9
const uint8_t SEGMENT_MAP[] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90}; // Segmente, die leuchten sollen pro Zahlwert (Low-Aktiv), & 0x7F Verknüpfen fuer Dezimalpunkt
const uint8_t SEGMENT_SELECT[] = {0xF1, 0xF2, 0xF4, 0xF8};                            // Ziffernposition (gemeinsame Anode, LSB)

uint16_t uhrzeit = 2022;


/*
   @brief   Schiebt 8 Bits, MSB first raus. Als einfachere Ersatz fuer ShiftOut() von Arduino
   @param   Datenpin
            Taktpin
            Wert
   @return  none
*/
void MyShiftOut(uint8_t dataPin, uint8_t clockPin, uint8_t val)
{
  uint8_t i;

  for (i = 0; i < 8; i++)
  {
    digitalWrite(dataPin, !!(val & (1 << (7 - i))));

    digitalWrite(clockPin, HIGH);
    digitalWrite(clockPin, LOW);
  }
}

/*
   @brief   Ausgabe einer Zahl an einer Position auf dem Display
   @param   welche Position (0= links, 3=rechts)
            Zahlwert (0..9)
   @return  none
*/
void WriteNumberToSegment(uint8_t digit, uint8_t value)
{
  digitalWrite(LATCH, LOW);                       // Uebernahme-Takt: Ausgang Aus
  MyShiftOut(DATA, CLK, SEGMENT_MAP[value]);      // Segmente passend zum Zahlwert rausschieben. MSB zuerst
  MyShiftOut(DATA, CLK, SEGMENT_SELECT[digit]);   // Welche Stelle leuchten soll hinterher schieben
  digitalWrite(LATCH, HIGH);                      // Uebernahme-Takt: Ausgang Ein
}

/*
   @brief   Ausgabe einer Zahl auf dem Display
   @param   Zahl 0..9999
   @return  none
*/
void DisplayNumber (uint16_t value)
{
  for (int i = 0; i < 12000; i++) {
    WriteNumberToSegment(0, value / 1000);          // Tausender
    delay(1);
    WriteNumberToSegment(1, (value / 100) % 10);    // Hunderter (Modulo)
    delay(1);
    WriteNumberToSegment(2, (value / 10) % 10);     // Zehner
    delay(1);
    WriteNumberToSegment(3, value % 10);            // Einer
    delay(1);
  }
}

void setup ()
{
  pinMode(LATCH, OUTPUT);
  pinMode(CLK, OUTPUT);
  pinMode(DATA, OUTPUT);
}

void loop()
{
  DisplayNumber(uhrzeit);
  uhrzeit = uhrzeit + 1;
}
