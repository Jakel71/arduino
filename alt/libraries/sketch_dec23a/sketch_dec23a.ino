#include <FastLED.h>
#define LED_PIN 8
const int LEDs=64;    //How Many LEDs
CRGB leds[LEDs];
int mode = 1;
int a = 0;
int programm_aktiv = 0;

byte Farbton = 0;

char MyMatrix[LEDs] =  "00000000"
                     "00000000"
                     "00000000"
                     "09000090"
                     "00099000"
                     "09000090"
                     "00999900"
                     "00000000";


void setup() {
  // put your setup code here, to run once:
  FastLED.addLeds<NEOPIXEL, LED_PIN>(leds, LEDs);
  FastLED.setBrightness(  100 );
}

void loop() {
  // put your main code here, to run repeatedly:
  if (a < 11) {
    a = 11;
    Farbton = 20;
  }

  Farbton += 10;
  leds[a] = CRGB::Black;
  leds[a - 1] = CHSV( Farbton, 230, 130);
  leds[a - 2] = CHSV( Farbton - 5, 230, 130);
  leds[a - 3] = CHSV( Farbton - 10, 230, 130);
  leds[a - 4] = CHSV( Farbton - 15, 230, 130);
  leds[a - 5] = CHSV( Farbton - 20, 230, 130);
  leds[a - 6] = CHSV( Farbton - 25, 230, 130);
  leds[a - 7] = CHSV( Farbton - 30, 230, 130);
  leds[a - 8] = CHSV( Farbton - 35, 230, 130);
  leds[a - 9] = CHSV( Farbton - 40, 230, 130);
  leds[a - 10] = CRGB::Black;
  if (a < LEDs) {
    a = a + 1;
  }
  else {
  }
  
  FastLED.show();
  delay(100);
}
