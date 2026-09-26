#include <FastLED.h>
#if defined(FASTLED_VERSION) && (FASTLED_VERSION < 3001000)
#warning "Requires FastLED 3.1 or later; check github for latest code."
#endif

#define DATA_PIN 6
//#define CLK_PIN   4
#define LED_TYPE WS2811
#define COLOR_ORDER GRB
#define NUM_LEDS 150
CRGB leds[NUM_LEDS];

#define BRIGHTNESS 255
#define FRAMES_PER_SECOND 120
uint8_t gHue = 1;
int time = 0;

void setup() {
  FastLED.addLeds<LED_TYPE, DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.setBrightness(BRIGHTNESS);
}

void loop() {
  time++;
  if (gHue == 1) {
    fadeToBlackBy(leds, NUM_LEDS, 20);
    int pos = beatsin16(13, 0, NUM_LEDS - 1);
    leds[pos] = CRGB(255, 0, 0);  //red=(255,0,0) Green = (0,255,0) Blue = (0,0,255)
  } else if (gHue == 2) {
    fadeToBlackBy(leds, NUM_LEDS, 20);
    int pos = beatsin16(13, 0, NUM_LEDS - 1);
    leds[pos] = CRGB(0, 0, 255);  //red=(255,0,0) Green = (0,255,0) Blue = (0,0,255)
  } else if (gHue == 3) {
    fadeToBlackBy(leds, NUM_LEDS, 20);
    int pos = beatsin16(13, 0, NUM_LEDS - 1);
    leds[pos] = CRGB(0, 255, 0);  //red=(255,0,0) Green = (0,255,0) Blue = (0,0,255)
  }

  FastLED.show();
  if (time > 1000) {
    gHue++;
    time = 0;
  }
  if (gHue > 3) {
    gHue = 1;
  }
}