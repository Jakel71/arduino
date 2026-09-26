#include <Adafruit_CircuitPlayground.h>

#include "FastLED.h"

#define NUM_LEDS 38
#define LED_DATA_PIN 6
#define NUM_BYTES (NUM_LEDS*3) // 3 colors  

#define BRIGHTNESS 255
#define UPDATES_PER_SECOND 100

#define TIMEOUT 3000

#define MODE_ANIMATION 0
#ifdef __AVR__
#include <avr/power.h>
#endif
#define PIN 9 // Hier wird angegeben, an welchem digitalen Pin die WS2812 LEDs bzw. NeoPixel angeschlossen sind
#define NUMPIXELS 40 // Hier wird die Anzahl der angeschlossenen WS2812 LEDs bzw. NeoPixel angegeben

int pause=100; // 100 Millisekunden Pause bis zur Ansteuerung der nächsten LED.

void setup() 
{
  pixels.begin(); // Initialisierung der NeoPixel
}

void loop() 
{
pixels.setPixelColor(1, pixels.Color(0,255,0)); // Pixel1 leuchtet in der Farbe Grün
pixels.show(); // Durchführen der Pixel-Ansteuerung
delay (pause); // Pause, in dieser Zeit wird nichts verändert.
pixels.setPixelColor(2, pixels.Color(0,150,0)); // Pixel2 leuchtet in der Farbe Grün
pixels.show(); // Durchführen der Pixel-Ansteuerung
delay (pause); // Pause, in dieser Zeit wird nichts verändert.
pixels.setPixelColor(3, pixels.Color(0,50,0)); // Pixel3 leuchtet in der Farbe Grün
pixels.show(); // Durchführen der Pixel-Ansteuerung
delay (pause); // Pause, in dieser Zeit wird nichts verändert.
pixels.setPixelColor(4, pixels.Color(0,10,0)); // Pixel4 leuchtet in der Farbe Grün
pixels.show(); // Durchführen der Pixel-Ansteuerung
delay (pause); // Pause, in dieser Zeit wird nichts verändert.
pixels.setPixelColor(5, pixels.Color(0,1,0)); // Pixel5 leuchtet in der Farbe Grün
pixels.show(); // Durchführen der Pixel-Ansteuerung
delay (pause); // Pause, in dieser Zeit wird nichts verändert.

// Zurücksetzen aller Pixelfarben auf Stufe "0" (aus)
pixels.setPixelColor(1, pixels.Color(0,0,0)); 
pixels.setPixelColor(2, pixels.Color(0,0,0)); 
pixels.setPixelColor(3, pixels.Color(0,0,0)); 
pixels.setPixelColor(4, pixels.Color(0,0,0)); 
pixels.setPixelColor(5, pixels.Color(0,0,0)); 
pixels.show(); // Durchführen der Pixel-Ansteuerung
delay (pause); // Pause, die LEDs bleiben in dieser Zeit aus

}
