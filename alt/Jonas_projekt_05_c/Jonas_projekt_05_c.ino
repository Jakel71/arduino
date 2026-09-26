#include <FastLED.h>
#define LED_PIN 6
CRGB leds[64];
int a;
int b;
byte Farbton;
char Zeile1[] = "   XX   ";
char Zeile2[] = "  X  X  ";
char Zeile3[] = " X    X ";
char Zeile4[] = "X      X";
char Zeile5[] = "X      X";
char Zeile6[] = " X    X ";
char Zeile7[] = "  X  X  ";
char Zeile8[] = "   XX   ";


void setup() {
  // put your setup code here, to run once:
  FastLED.addLeds<NEOPIXEL, LED_PIN>(leds, 64);
  FastLED.setBrightness(  50 );
  Farbton = 0;

}

void loop() {
  FastLED.clear();
  for (a = 0; a < 8; a = a + 1) {
    if (Zeile1[a] != ' ') {
      leds[a] = CHSV( Zeile1[a], 230, 130);
    }
    if (Zeile2[a] != ' ') {
      leds[a + 8] = CHSV( Zeile2[a], 230, 130);
    }
    if (Zeile3[a] != ' ') {
      leds[a + 16] = CHSV( Zeile3[a], 230, 130);
    }
    if (Zeile4[a] != ' ') {
      leds[a + 24] = CHSV( Zeile4[a], 230, 130);
    }
    if (Zeile5[a] != ' ') {
      leds[a + 32] = CHSV( Zeile5[a], 230, 130);
    }
    if (Zeile6[a] != ' ') {
      leds[a + 40] = CHSV( Zeile6[a], 230, 130);
    }
    if (Zeile7[a] != ' ') {
      leds[a + 48] = CHSV( Zeile7[a], 230, 130);
    }
    if (Zeile8[a] != ' ') {
      leds[a + 56] = CHSV( Zeile8[a], 230, 130);
    }

    /*

      for (a = 0; a < 8; a = a + 1) {
        Farbton+=2;
        for (b = 0; b < 8; b = b + 1) {
          leds[8*((a+7)%8)+b] = CRGB::Black;
          leds[8*a+b] = CHSV( Farbton, 230, 130);
         }
    */
  }


  FastLED.show();
  delay(50);
}
