#include <FastLED.h>


#define LED_PIN 3
#define LED_TYPE WS2811
#define COLOR_ORDER GRB
#define NUM_LEDS 35

#define BRIGHTNESS 40

const int tasterPin = 1; // Taster an Pin 1

int tasterStatus = 0;
int vorherigerStatus = LOW;
int ledStatus = HIGH;
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
    if (ledStatus == HIGH) {
      ledStatus = LOW;
    } else {
      ledStatus = HIGH;
    }
    digitalWrite(2, ledStatus);
    for (i = 0; i < leds; i++) {
      digitalWrite(i, ledStatus);
      i++;
    }
  }

  vorherigerStatus = tasterStatus;
  delay(100);
}
