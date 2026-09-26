#include <FastLED.h>

#define LED_PIN 3
#define LED_TYPE WS2811
#define COLOR_ORDER GRB
#define NUM_LEDS 30
#define BRIGHTNESS 40

int Trig = 4;
int Echo = 5;
int magic_leds = 0;

long dauer = 0;
long entfernung_in_cm = 0;

const int tasterPin = 0; // Taster an Pin 1 / Klatschsensor an Pin 0 

int tasterStatus = 0;
int vorherigerStatus = LOW;
bool ledStatus = false; // Geändert auf bool für LED-Status
int i = 0;

CRGB leds[NUM_LEDS];

void setup () {
  pinMode(Trig, OUTPUT);
  pinMode(Echo, INPUT);
  pinMode(tasterPin, INPUT);
  pinMode(2, OUTPUT);
  delay(100);
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.setBrightness(BRIGHTNESS);
}

void loop() {
  digitalWrite(Trig, LOW);
  delay(5);
  digitalWrite(Trig, HIGH);
  delay(10);
  digitalWrite(Trig, LOW);
  dauer = pulseIn(Echo, HIGH);
  entfernung_in_cm = (dauer / 2) * 0.03432;
  if (entfernung_in_cm >= 500 || entfernung_in_cm <= 0) {
    entfernung_in_cm = 0;
  }
  magic_leds = entfernung_in_cm / 3;
  
  if (ledStatus){
  fill_solid(leds, NUM_LEDS, CRGB::Black);
  fill_solid(leds, magic_leds, CRGB::White);
  } else{
    fill_solid(leds, NUM_LEDS, CRGB::Black);
  }
  
  tasterStatus = digitalRead(tasterPin);

  if (tasterStatus == HIGH && vorherigerStatus == LOW) {
    // Wenn der Taster gedrückt wurde und vorher nicht gedrückt war (Flanke)
    ledStatus = !ledStatus; // Toggle-Funktion für LED-Status
    digitalWrite(2, ledStatus); // Schalte die externe LED ein/aus
    
    
  }
  FastLED.show(); // Aktualisiere die LEDs
  vorherigerStatus = tasterStatus;
}
