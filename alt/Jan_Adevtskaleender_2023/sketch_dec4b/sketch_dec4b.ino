#include <FastLED.h>

#define LED_PIN 3
#define LED_TYPE WS2811
#define COLOR_ORDER GRB
#define NUM_LEDS 35
#define BRIGHTNESS 40

const int tasterPin = 1; // Taster an Pin 1

int tasterStatus = 0;
int vorherigerStatus = LOW;
bool ledStatus = false; // Geändert auf bool für LED-Status
int i = 0;

CRGB leds[NUM_LEDS];

void setup() {
  pinMode(tasterPin, INPUT);
  pinMode(2, OUTPUT);
  delay(100);
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.setBrightness(BRIGHTNESS);
}

void loop() {
  tasterStatus = digitalRead(tasterPin);

  if (tasterStatus == HIGH && vorherigerStatus == LOW) {
    // Wenn der Taster gedrückt wurde und vorher nicht gedrückt war (Flanke)
    ledStatus = !ledStatus; // Toggle-Funktion für LED-Status
    digitalWrite(2, ledStatus); // Schalte die externe LED ein/aus

    // Schalte alle LEDs ein/aus
    if (ledStatus) {
      fill_solid(leds, NUM_LEDS, CRGB::White); // Alle LEDs weiß einschalten
    } else {
      fill_solid(leds, NUM_LEDS, CRGB::Black); // Alle LEDs ausschalten
    }
    
    FastLED.show(); // Aktualisiere die LEDs
    delay(100);
  }

  vorherigerStatus = tasterStatus;
}
