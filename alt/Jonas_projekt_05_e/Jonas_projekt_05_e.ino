#include <FastLED.h>
#define LED_PIN 6
CRGB leds[64];
CRGB EnterpriseLeds[16];
CRGB OnePixel;
int a;
int b;
int c;
int Richtung;
int buttonState = 0;
int LED_AN = 0;
int Trigger_OK = 0;
byte Farbton;
const int buttonPin = 5;

void setup() {
  // put your setup code here, to run once:

  //Enterprise raus
  FastLED.addLeds<NEOPIXEL, LED_PIN>(leds, 64);
  FastLED.setBrightness(  50 );
  Farbton = 0;
  b = 0;
  Richtung = 0;

  for (c = 0; c < 2; c = c + 1) {
    for (a = 0; a < 59; a = a + 1) {
      leds[a] = CRGB::White;
    }
    FastLED.show();
    delay(500);
    for (a = 0; a < 59; a = a + 1) {
      leds[a] = CRGB::Black;
    }
    FastLED.show();
    delay(500);
  }
  EnterpriseLeds[0] = CRGB::Blue; //
  EnterpriseLeds[1] = CRGB::Black;
  EnterpriseLeds[2] = CRGB::Black;
  EnterpriseLeds[3] = CRGB::Black;
  EnterpriseLeds[4] = CRGB::Blue; //
  EnterpriseLeds[5] = CRGB::Black;
  EnterpriseLeds[6] = CRGB::Black;
  EnterpriseLeds[7] = CRGB::Black;
  EnterpriseLeds[8] = CRGB::Blue; //
  EnterpriseLeds[9] = CRGB::Black;
  EnterpriseLeds[10] = CRGB::Black;
  EnterpriseLeds[11] = CRGB::Black;
  EnterpriseLeds[12] = CRGB::Blue; //
  EnterpriseLeds[13] = CRGB::Black;
  EnterpriseLeds[14] = CRGB::Black;
  EnterpriseLeds[15] = CRGB::Black;
  leds[0] = CRGB::Red;
  leds[1] = leds[0];
  leds[17] = leds[0];

  //Enterprise rein

  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);

}

void loop() {


  // 1.)
  //Enterprise rein
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH)
  {
    if (Trigger_OK == 1)
    {
      Trigger_OK = 0;
      if (Richtung == 1)
      {
        Richtung = 0;
      } else {
        Richtung = 1;
      }
    }
  } else  {
    Trigger_OK = 1;
  }

  // 2.)
  if (Richtung == 1) {
    leds[0] = CRGB::Red; leds[17] = CRGB::Red; leds[34] = CRGB::Red;
    for (a = 0; a < 16; a = a + 1) {
      leds[1 + a] = EnterpriseLeds[a];
      leds[18 + a] = EnterpriseLeds[15 - a];
    }
  } else {
    leds[0] = CRGB::Green; leds[17] = CRGB::Green; leds[34] = CRGB::Green;
    for (a = 0; a < 16; a = a + 1) {
      leds[1 + a] = EnterpriseLeds[a];
      leds[18 + a] = EnterpriseLeds[15 - a];
    }
  }

  // 3.)
  //Enterprise raus
  if (Richtung == 1) {
    OnePixel = EnterpriseLeds[0];
    for (a = 0; a < 15; a = a + 1) {
      EnterpriseLeds[a] = EnterpriseLeds[a + 1];
    }
    EnterpriseLeds[15] = OnePixel;
  } else {
    OnePixel = EnterpriseLeds[15];
    for (a = 15; a > 0; a = a - 1) {
      EnterpriseLeds[a] = EnterpriseLeds[a - 1];
    }
    EnterpriseLeds[0] = OnePixel;
  }
  FastLED.show();
  delay(300);
}
