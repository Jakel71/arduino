#include <FastLED.h>
#define LED_PIN 6
CRGB leds[30];
int a=0; //whiche LED
int b=0;
int m=0; //m=Mode
int c=0;
byte Farbton;

void setup() {
  // put your setup code here, to run once:
  FastLED.addLeds<NEOPIXEL, LED_PIN>(leds, 30);
  FastLED.setBrightness(  50 );
  Farbton = 0;

    for (c = 0; c < 4 ; c = c + 1){
    for (a = 0; a < 30; a = a + 1) {
   leds[a] = CRGB::White;
    }
    FastLED.show();
    delay(500);
    for (a = 0; a < 30; a = a + 1) {
      leds[a] = CRGB::Black;
    }
//    FastLED.show();
    delay(500);
}
}

void loop() {
  // put your main code here, to run repeatedly:
  if (m==1) {
    for (a = 0; a < 8; a = a + 1) {
    Farbton+=2;
    for (b = 0; b < 8; b = b + 1) {
//      leds[8*((a+7)%8)+b] = CRGB::Black;
      leds[8*a+b] = CHSV( Farbton, 230, 130);
     }
    }
  }
  if (m<5){
    m=m+1;
    }
  else {
   m=0;
   }
   FastLED.show();
   delay(50);
}
