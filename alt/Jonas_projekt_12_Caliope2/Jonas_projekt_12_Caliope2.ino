#include <FastLED.h>
#define LED_TYPE WS2812B
#define LED_PIN 8
#define COLOR_ORDER GRB
#define NUM_LEDS    65
CRGB leds[NUM_LEDS];

#define BRIGHTNESS          30
#define FRAMES_PER_SECOND  120

const int LEDs = 64;  //How Many LEDs
const int Virtuel_LEDs = 100;  //How Many LEDs

int mode = 1;
int i = 0;
int f = 0;
int x = 0;
int z = 0;
int l = 0;
int p = 0;
int d = 0;
int programm_aktiv = 0;

char Boot01[LEDs] =  "11020100"
                     "10202100"
                     "10222100"
                     "11202111"
                     "21112221"
                     "21012021"
                     "21012221"
                     "21112001";

char Boot02[LEDs] =  "01102020"
                     "01012020"
                     "01102220"
                     "01010200"
                     "01100200"
                     "00000000"
                     "00000000"
                     "00000000";

char Boot03[Virtuel_LEDs] =  "3330333030030030033300000"
                             "0030303033030303033300000"
                             "3030303030330333000300000"
                             "3330333030030303033300000";

char Menu01[LEDs] =  "00090000"
                     "00909000"
                     "09000900"
                     "09999900"
                     "09000900"
                     "09000900"
                     "09999900"
                     "00000000";

char Menu02[LEDs] =  "00000000"
                     "09999990"
                     "09000090"
                     "09090090"
                     "09099090"
                     "09000090"
                     "09999990"
                     "00000000";
                     
char Menu03[LEDs] =  "00000000"
                     "00099000"
                     "00099000"
                     "00099000"
                     "09099090"
                     "09099090"
                     "00999900"
                     "00099000";

char Menu04[LEDs] =  "00090000"
                     "00999000"
                     "00090000"
                     "00898000"
                     "08090800"
                     "00090000"
                     "00909000"
                     "00909000";

char Menu05[LEDs] =  "00000000"
                     "00000000"
                     "09000090"
                     "00099000"
                     "00099000"
                     "09000090"
                     "00999900"
                     "00000000";

char Menu06[LEDs] =  "00000000"
                     "00000000"
                     "09000090"
                     "00099000"
                     "00099000"
                     "09000090"
                     "00999900"
                     "00000000";

char Boot04[LEDs] =  "00000000"
                     "00000000"
                     "00000000"
                     "00000000"
                     "00000000"
                     "00000000"
                     "00000000"
                     "00000000";

void display(char data[LEDs], int z, int y) {
  for (i = 0; i < LEDs; i = i + 1) {
    switch (data[i]) {
      case '0' : leds[i] = CRGB::Black; break;
      case '1' : leds[i] = CRGB::Red; break;
      case '2' : leds[i] = CRGB::Green; break;
      case '3' : leds[i] = CRGB::Blue; break;
      case '4' : leds[i] = CRGB::Yellow; break;
      case '5' : leds[i] = CRGB::Purple; break;
      //case '6' : leds[i] = CRGB::Purple; break;
      //case '7' : leds[i] = CRGB::Grey; break;
      case '8' : leds[i] = CRGB::Grey; break;
      case '9' : leds[i] = CRGB::White; break;
      default  : leds[i] = CRGB::Yellow; break;
    }
    if (i == y) {
      delay(1000);
    }
    delay(z * 10);
    FastLED.show();
  }
}

void flow(char data[Virtuel_LEDs], int zeit, int laenge) {
  for (f = 0; f < laenge - 2; f = f + 1) { //pro frame
    for (l = 0; l < 4; l = l + 1) { //pro line
      for (p = 0; p < 8; p = p + 1) { //pro pixel
        switch (data[(f + l * 25 + p) % 100]) {
          case '0' : leds[p + (l + 2/*Startet in Zeile 2*/) * 8] = CRGB::Black; break;
          case '1' : leds[p + (l + 2) * 8] = CRGB::Red; break;
          case '2' : leds[p + (l + 2) * 8] = CRGB::Green; break;
          case '3' : leds[p + (l + 2) * 8] = CRGB::Blue; break;
          case '9' : leds[p + (l + 2) * 8] = CRGB::White; break;
          default  : leds[p + (l + 2) * 8] = CRGB::Yellow; break;
        }
      }
    }
    delay(zeit * 20);
    FastLED.show();
  }
}

void black(int zeit) {
  for (x = 30; x > 0; x = x - 1) {
    FastLED.setBrightness(x);
    delay(zeit * 50);
    FastLED.show();
  }
  for (i = 0; i < LEDs; i = i + 1) {
    leds[i] = CRGB::Black;
  }
  FastLED.setBrightness(BRIGHTNESS);
  FastLED.show();
}





int buttonState_Right = 0;
int buttonState_Left = 0;
int buttonState_Home = 0;

int trigger_OK_Right  = 0;
int trigger_OK_Left = 0;
int trigger_OK_Home = 0;

const int buttonPin_Right = 5;
const int buttonPin_Left = 6;
const int buttonPin_Home = 7;

int buttonLED_Right  = 0;
int buttonLED_Left = 0;
int buttonLED_Home = 0;


void setup() {
  FastLED.addLeds<NEOPIXEL, LED_PIN>(leds, NUM_LEDS);
  FastLED.setBrightness(BRIGHTNESS);

  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);

  pinMode(5, INPUT);
  pinMode(6, INPUT);
  pinMode(7, INPUT);

  display(Boot01, 2, 32);
  digitalWrite(2, HIGH);
  delay(500);

  digitalWrite(2, LOW);
  digitalWrite(4, HIGH);
  delay(500);

  digitalWrite(4, LOW);
  digitalWrite(3, HIGH);
  display(Boot02, 2, 100);
  delay(500);

  digitalWrite(3, LOW);
  delay(200);

  digitalWrite(4, HIGH);
  delay(200);
  digitalWrite(4, LOW);
  delay(200);
  digitalWrite(4, HIGH);
  delay(200);
  digitalWrite(4, LOW);
  black(1);
  flow(Boot03, 20, 20);
  black(0);

}


//Knöpfe:
void Right() {
  buttonState_Right = digitalRead(5);
  if (buttonState_Right == HIGH) {
    digitalWrite(2, LOW);
    delay(500);
    if (trigger_OK_Right == 1) {
      trigger_OK_Right = 0;
      mode = mode + 1;
    }
  } else  {
    trigger_OK_Right = 1;
    digitalWrite(2, HIGH);
  }
}
void Left() {
  buttonState_Left = digitalRead(6);
  if (buttonState_Left == HIGH) {
    digitalWrite(3, LOW);
    delay(500);
    if (trigger_OK_Left == 1) {
      trigger_OK_Left = 0;
      mode = mode - 1;
    }
  } else  {
    trigger_OK_Left = 1;
    digitalWrite(3, HIGH);
  }
}
void Home() {
  buttonState_Home = digitalRead(7);
  if (buttonState_Home == HIGH) {
    if (trigger_OK_Home == 1) {
      trigger_OK_Home = 0;
      if (programm_aktiv == 0) {
        programm_aktiv = 1;
      } else {
        programm_aktiv = 0;
      }
    }
  } else  {
    trigger_OK_Home = 1;
  }
}



//Setup:
void next() {
  mode = 5;
  programm_aktiv = 0;
}
void error() {

}




//Modes:
void start() {

}
void movie() {

}
void space_invaders() {

}
void score() {

}
void mario() {

}




void loop() {
  Right();
  Left();
  Home();


  switch (mode) {
    case 0:
      mode = 5;
      break;
    case 1:
      leds[64] = CRGB::Red;
      if (programm_aktiv == 1) {
        start();
      } else {
        display(Menu01, 0, 100);
      }
      break;
    case 2:
      leds[64] = CRGB::Green;
      if (programm_aktiv == 1) {
        movie();
      } else {
        display(Menu02, 0, 100);
      }
      break;
    case 3:
      leds[64] = CRGB::Blue;
      if (programm_aktiv == 1) {
        space_invaders();
      } else {
        display(Menu03, 0, 100);
      }
      break;
    case 4:
      leds[64] = CRGB::Yellow;
      if (programm_aktiv == 1) {
        mario();
      } else {
        display(Menu04, 0, 100);
      }
      break;
    case 5:
      leds[64] = CRGB::Purple;
      if (programm_aktiv == 1) {
        score();
      } else {
        display(Menu05, 0, 100);
      }
      break;
    case 6:
      mode = 1;
      break;
    default:
      error();
      break;
  }
  if (programm_aktiv == 0) {
    digitalWrite(4, HIGH);
  } else {
    digitalWrite(4, LOW);
  }
  FastLED.show();
  delay(10);
}
