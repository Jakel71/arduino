#include <FastLED.h>
#define LED_PIN 6
CRGB leds[60];
int a = 0; //whiche LED
int b = 0;
int m = 0; //m=Mode
int c = 0;
int d = 0;
int e = 0;
byte Farbton = 0;

void setup() {
  // put your setup code here, to run once:
  FastLED.addLeds<NEOPIXEL, LED_PIN>(leds, 60);
  FastLED.setBrightness(  50 );

  for (c = 0; c < 3 ; c = c + 1) {
    for (a = 0; a < 60; a = a + 1) {
      leds[a] = CRGB::White;
    }
    FastLED.show();
    delay(500);
    for (a = 0; a < 60; a = a + 1) {
      leds[a] = CRGB::Black;
    }
    FastLED.show();
    delay(500);
  }
}


void loop() {
  // put your main code here, to run repeatedly:
  if (m <= 406) {

    Farbton += 2;
    leds[b] = CHSV( Farbton, 230, 130);
    leds[b + 1] = CRGB::Black;
    leds[59] = CRGB::Yellow;
    if (b < 58) {
      b = b + 1;
    }
    else {
      b = 0;
    }
    FastLED.show();
    delay(50);
  }
  if (m > 406) { 
  
      Farbton += 5;
      for (e = 0; e < 59; e = e + 1) {
        leds[e] = CHSV( Farbton, 230, 130);
      }

    FastLED.show();
    delay(200);
  }
  if (m < 600) {
    m = m + 1;
  }
  else {
    m = 0;
  }
}
