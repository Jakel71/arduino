#include <FastLED.h>
#if defined(FASTLED_VERSION) && (FASTLED_VERSION < 3001000)
#warning "Requires FastLED 3.1 or later; check github for latest code."
#endif

#define LED_PIN 6
#define LED_TYPE WS2811
#define COLOR_ORDER BRG
#define NUM_LEDS 150

#define BRIGHTNESS 255
#define FRAMES_PER_SECOND 120

#define TEMPERATURE_1 Tungsten100W
#define TEMPERATURE_2 OvercastSky
#define DISPLAYTIME 20
#define UPDATES_PER_SECOND 100

static uint8_t hue = 0;

uint8_t gHue = 0;
int a = 0;
CRGB leds[NUM_LEDS];
void setup() {
  pinMode(12, OUTPUT);
  digitalWrite(12, HIGH);
  // put your setup code here, to run once:
   FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
  leds[NUM_LEDS] = CRGB::Black;
  
}

void loop() {
  // put your main code here, to run repeatedly:
FastLED.setBrightness(BRIGHTNESS);
  for (a = 0; a < NUM_LEDS; a + 15){
    leds[a] =CRGB::Red;
    delay(10000);
    FastLED.show();
  }
  
}
