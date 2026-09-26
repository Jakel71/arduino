#include <FastLED.h>

#define DATA_PIN 3
//#define CLK_PIN   4
#define LED_TYPE WS2811
#define COLOR_ORDER GRB
#define NUM_LEDS 30
#define BRIGHTNESS 40

CRGB leds[NUM_LEDS];

int analogPin = A5; // Pin, der gelesen werden soll: Pin A3
int val = 0; // Variable, die den gelesenen Wert speichert
int magic_leds = 0;

void setup() {
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.setBrightness(BRIGHTNESS);
  Serial.begin(9600); // Setup der seriellen Verbindung
}

void loop() {
  val = analogRead(analogPin); // Pin einlesen
  Serial.println(val); // Wert ausgeben
  magic_leds = val / 3;
  fill_solid(leds, NUM_LEDS, CRGB::Black);
  fill_solid(leds, magic_leds, CRGB::White);
  FastLED.show(); // Aktualisiere die LEDs
  delay(100);
}