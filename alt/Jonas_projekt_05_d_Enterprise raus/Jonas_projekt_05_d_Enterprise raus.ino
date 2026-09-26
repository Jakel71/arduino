#include <FastLED.h>
#define LED_PIN 6
CRGB leds[150];
CRGB EnterpriseLeds[16];
CRGB OnePixel;
int a;
int b;
int c;
int Richtung;
byte Farbton;

void setup() {
  // put your setup code here, to run once:
  FastLED.addLeds<NEOPIXEL, LED_PIN>(leds, 64);
  FastLED.setBrightness(  50 );
  Farbton = 0;
  b=0;
  Richtung=0;

  for (c = 0; c < 2; c = c + 1) {
    for (a = 0; a < leds-1; a = a + 1) {
      leds[a] = CRGB::White;
    }
    FastLED.show();
    delay(500);
    for (a = 0; a < leds-1; a = a + 1) {
      leds[a] = CRGB::Black;
    }
    FastLED.show();
    delay(500);
  }
  EnterpriseLeds[0] = CRGB::Blue; //
  EnterpriseLeds[1] = CRGB::Blue; //
  EnterpriseLeds[2] = CRGB::Black;
  EnterpriseLeds[3] = CRGB::Black;
  EnterpriseLeds[4] = CRGB::Black;
  EnterpriseLeds[5] = CRGB::Black;
  EnterpriseLeds[6] = CRGB::Black;
  EnterpriseLeds[7] = CRGB::Black;
  EnterpriseLeds[8] = CRGB::Blue; //
  EnterpriseLeds[9] = CRGB::Blue; //
  EnterpriseLeds[10] = CRGB::Black;
  EnterpriseLeds[11] = CRGB::Black;
  EnterpriseLeds[12] = CRGB::Black;
  EnterpriseLeds[13] = CRGB::Black;
  EnterpriseLeds[14] = CRGB::Black;
  EnterpriseLeds[15] = CRGB::Black;
  leds[0] = CRGB::Red;
  leds[17] = leds[0];
  leds[34] = leds[0];

}

void loop() {
  for (a = 0; a < 16; a = a + 1) {
    leds[1+a] = EnterpriseLeds[a];
    leds[18+a] = EnterpriseLeds[15-a];
  }

  OnePixel = EnterpriseLeds[0];
  for (a = 0; a < 15; a = a + 1) {
    EnterpriseLeds[a] = EnterpriseLeds[a+1];
  }
  EnterpriseLeds[15] = OnePixel;

  FastLED.show();
  delay(300);
}
