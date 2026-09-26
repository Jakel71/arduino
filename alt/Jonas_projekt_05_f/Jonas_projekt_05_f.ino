#include <FastLED.h>
#define LED_PIN 6
CRGB leds[64];
CRGB EnterpriseLeds[16];
CRGB LeuchtturmLeds[7];
CRGB OnePixel;
int a=0;
int b=0;
int c=0;
int d=0;
int e=0;
int Richtung;
int AnAus=0;
int Nacht=0;
int buttonState  = 0;
int buttonState2 = 0;
int buttonState3 = 0;
int LED_AN = 0;
int Trigger_OK  = 0;
int Trigger_OK2 = 0;
int Trigger_OK3 = 0;
byte Farbton;
const int buttonPin  = 5;
const int buttonPin2 = 4;
const int buttonPin3 = 3;
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

  LeuchtturmLeds[0] = CRGB::White; //
  LeuchtturmLeds[1] = CRGB::Black;
  LeuchtturmLeds[2] = CRGB::Black;
  LeuchtturmLeds[3] = CRGB::Black;
  LeuchtturmLeds[4] = CRGB::Black;
  LeuchtturmLeds[5] = CRGB::Black;
  LeuchtturmLeds[6] = CRGB::Black;

//  leds[0] = CRGB::Red;
//  leds[1] = leds[0];
//  leds[17] = leds[0];

  //Enterprise rein

  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
  pinMode(buttonPin2, INPUT);  
  pinMode(buttonPin3, INPUT);


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

  if (Richtung == 1) {
    leds[24] = CRGB::Red; leds[41] = CRGB::Red; leds[58] = CRGB::Red;
    for (a = 0; a < 16; a = a + 1) {
      leds[25 + a] = EnterpriseLeds[a];
      leds[42 + a] = EnterpriseLeds[15 - a];
    }
  } else {
    leds[24] = CRGB::Green; leds[41] = CRGB::Green; leds[58] = CRGB::Green;
    for (a = 0; a < 16; a = a + 1) {
      leds[25 + a] = EnterpriseLeds[a];
      leds[42 + a] = EnterpriseLeds[15 - a];
    }
  }

  // 2.)
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
// 3.)
//Party-Hütte
  buttonState2 = digitalRead(buttonPin2);
  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState2 == HIGH)
  {
    if (Trigger_OK2 == 1)
    {
      Trigger_OK2 = 0;
      if (AnAus == 1)
      {
        AnAus = 0;
      } else {
        AnAus = 1;
      }
    }
  } else  {
    Trigger_OK2 = 1;
  }
  if (AnAus == 1) {
     if (d < 250) {
       d=d+5;
       leds[59] = CHSV( d, 255, 255);
     }else{
     AnAus = 0;
     }
  } else {
    d=0;
    leds[59] = CRGB::White; 
  }
  //3.)Leuchturm 
  buttonState3 = digitalRead(buttonPin3);
  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState3 == HIGH)
  {
    if (Trigger_OK3 == 1)
    {
      Trigger_OK3 = 0;
      if (Nacht == 1)
      {
        Nacht = 0;
      } else {
        Nacht = 1;
      }
    }
  } else  {
    Trigger_OK3 = 1;
  }
  if (Nacht == 1) {
     leds[1] = LeuchtturmLeds[0];
     leds[2] = LeuchtturmLeds[1];
     leds[3] = LeuchtturmLeds[2];
     leds[4] = LeuchtturmLeds[3];
     leds[5] = LeuchtturmLeds[4];
     leds[6] = LeuchtturmLeds[5];
     leds[7] = LeuchtturmLeds[6];
     e=e+1;
    if (e == 3) {
     e=0;
     LeuchtturmLeds[0] = LeuchtturmLeds[1];
     LeuchtturmLeds[1] = LeuchtturmLeds[2];
     LeuchtturmLeds[2] = LeuchtturmLeds[3];
     LeuchtturmLeds[3] = LeuchtturmLeds[4];
     LeuchtturmLeds[4] = LeuchtturmLeds[5];
     LeuchtturmLeds[5] = LeuchtturmLeds[6];
     LeuchtturmLeds[6] = leds[1];
    }
     
  } else {
     leds[1] = CRGB::Black;
     leds[2] = CRGB::Black;
     leds[3] = CRGB::Black;
     leds[4] = CRGB::Black;
     leds[5] = CRGB::Black;
     leds[6] = CRGB::Black;
     leds[7] = CRGB::Black;
  }



  
  FastLED.show();
  delay(300);

}
