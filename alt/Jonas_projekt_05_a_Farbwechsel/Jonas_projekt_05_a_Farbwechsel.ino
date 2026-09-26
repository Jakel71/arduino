#include <FastLED.h>
#define LED_PIN 6
CRGB leds[64];
int a;
int b;
byte Farbton;

void setup() {
  // put your setup code here, to run once:
  FastLED.addLeds<NEOPIXEL, LED_PIN>(leds, 64);
  FastLED.setBrightness(  50 );
  Farbton = 0;

}

void loop() {
  for (a = 0; a < 8; a = a + 1) {
    Farbton+=2;
    for (b = 0; b < 8; b = b + 1) {
//      leds[8*((a+7)%8)+b] = CRGB::Black;
      leds[8*a+b] = CHSV( Farbton, 230, 130);
     }
  FastLED.show();
  delay(50);
  }


}
