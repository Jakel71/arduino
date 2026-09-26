#include <FastLED.h>

#define LED_PIN       3            // Pin, an dem die LEDs angeschlossen sind
#define LED_TYPE      WS2811       // Typ der LED (z. B. WS2812, WS2812B, WS2811)
#define COLOR_ORDER   GRB          // Farbreihenfolge der LEDs
#define NUM_LEDS      30           // Anzahl der LEDs
#define BRIGHTNESS    100          // Helligkeit der LEDs (0-255)

#define MIC_PIN       A5           // Mikrofon-Pin

#define MIC_THRESHOLD 100          // Schwellenwert für das Audiosignal
#define MIN_LED_COUNT 1            // Mindestanzahl der leuchtenden LEDs

CRGB leds[NUM_LEDS];

void setup() {
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS);
  FastLED.setBrightness(BRIGHTNESS);
  
  Serial.begin(9600);
}

void loop() {
  uint16_t micValue = analogRead(MIC_PIN) * 3;  // Lies den Wert des Mikrofons aus
  
  // Berechne die Anzahl der LEDs, die beleuchtet werden sollen
  int numLitLeds = max(map(micValue, 0, 1023, MIN_LED_COUNT, NUM_LEDS), MIN_LED_COUNT);
  
  // Aktualisiere die LEDs entsprechend der Anzahl der leuchtenden LEDs
  for (int i = 0; i < NUM_LEDS + 1; i++) {
    leds[i] = (i < numLitLeds) ? CRGB::White : CRGB::Black;
  }
  
  FastLED.show();  // Zeige die aktualisierten LEDs an

  delay(10);  // Kurze Pause, um die Verarbeitung zu verlangsamen
}

