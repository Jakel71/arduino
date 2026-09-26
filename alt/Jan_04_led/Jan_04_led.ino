#include <FastLED.h>
#if defined(FASTLED_VERSION) && (FASTLED_VERSION < 3001000)
#warning "Requires FastLED 3.1 or later; check github for latest code."
#endif

#define LED_PIN 12
#define LED_TYPE WS2811
#define COLOR_ORDER BRG
#define NUM_LEDS 25

#define BRIGHTNESS 255
#define FRAMES_PER_SECOND 120

#define TEMPERATURE_1 Tungsten100W
#define TEMPERATURE_2 OvercastSky
#define DISPLAYTIME 20
#define UPDATES_PER_SECOND 100

static uint8_t hue = 0;

uint8_t gHue = 0;

byte Farbton = 0;

int b = 0;
int c = 0;
int a = 0;
int d = 0;
int time = 0;
int mode = 0;
int np = 0;
int x = 0;
int s = 0;

CRGB leds[NUM_LEDS];

extern CRGBPalette16 myRedWhiteBluePalette;
extern const TProgmemPalette16 myRedWhiteBluePalette_p PROGMEM;

void setup() {
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.setBrightness(BRIGHTNESS);

  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  blitzen(7, 10);

  all_kill(CRGB::Red);
  FastLED.show();
  delay(500);

  mode = 1;
}

void loop() {
  // put your main code here, to run repeatedly:
  gHue++;
  time++;

  if (mode == 1) {  //rainbow
    digitalWrite(4, HIGH);
    fill_rainbow(leds, NUM_LEDS, gHue, 7);


  } else if (mode == 2) {  //glow
    all_kill(CHSV(gHue, 230, 255));
    delay(1000);
    time += 74;
    gHue = rand() % 256;
  } else if (mode == 3) {  //cylon
    for (int i = (NUM_LEDS - 1); i >= 0; i--) {
      leds[i] = CHSV(hue++, 255, 255);
      FastLED.show();
      fadeall();
      delay(15);
      time++;
    }
  } else if (mode == 4) {  // Zug
    Zug();
    delay(30);
    time++;
    time++;
  } else if (mode == 5) {  //confetti
    fadeToBlackBy(leds, NUM_LEDS - 1, 10);
    int posi = random16(NUM_LEDS - 1);
    leds[posi] += CHSV((gHue + random8(64)) % 255, 200, 255);
  } else if (mode == 6) {  //Lights
    all_kill(CRGB::White);
    lights();
    delay(1000);
    time = 1001;
  } else if (mode == 7) {  //Sinelon
    fadeToBlackBy(leds, NUM_LEDS, 20);
    int pos = beatsin16(13, 0, NUM_LEDS - 1, 0, 0);
    leds[(pos) % NUM_LEDS] += CHSV(gHue, 255, 192);
    Zug_lights_b(pos);

  } else if (mode == 8) {  //Halb
    Halb();
    delay(200);
    time += 9;
  } else if (mode == 9) {  //pride2015
    digitalWrite(6, LOW);
    digitalWrite(7, HIGH);
    static uint16_t sPseudotime = 0;
    static uint16_t sLastMillis = 0;
    static uint16_t sHue16 = 0;

    uint8_t sat8 = beatsin88(87, 220, 250);
    uint8_t brightdepth = beatsin88(341, 96, 224);
    uint16_t brightnessthetainc16 = beatsin88(203, (25 * 256), (40 * 256));
    uint8_t msmultiplier = beatsin88(147, 23, 60);

    uint16_t hue16 = sHue16;
    uint16_t hueinc16 = beatsin88(113, 1, 3000);

    uint16_t ms = millis();
    uint16_t deltams = ms - sLastMillis;
    sLastMillis = ms;
    sPseudotime += deltams * msmultiplier;
    sHue16 += deltams * beatsin88(400, 5, 9);
    uint16_t brightnesstheta16 = sPseudotime;

    for (uint16_t i = 0; i < NUM_LEDS; i++) {
      hue16 += hueinc16;
      uint8_t hue8 = hue16 / 256;

      brightnesstheta16 += brightnessthetainc16;
      uint16_t b16 = sin16(brightnesstheta16) + 32768;

      uint16_t bri16 = (uint32_t)((uint32_t)b16 * (uint32_t)b16) / 65536;
      uint8_t bri8 = (uint32_t)(((uint32_t)bri16) * brightdepth) / 65536;
      bri8 += (255 - brightdepth);

      CRGB newcolor = CHSV(hue8, sat8, bri8);

      uint16_t pixelnumber = i;
      pixelnumber = (NUM_LEDS - 1) - pixelnumber;

      nblend(leds[pixelnumber], newcolor, 64);
    }
  } else if (mode == 10) {  //bpm
    digitalWrite(4, HIGH);
    uint8_t BeatsPerMinute = 62;
    CRGBPalette16 palette = PartyColors_p;
    uint8_t beat = beatsin8(BeatsPerMinute, 64, 255);
    for (int i = 0; i < NUM_LEDS; i++) {  //9948
      leds[i] = ColorFromPalette(palette, gHue + (i * 2), beat - gHue + (i * 10));
    }
  } else if (mode == 11) {  //Blitzen
    Blitz();
    delay(40);
    time++;
  } else if (mode == 12) {  //color temparatur
    digitalWrite(4, HIGH);
    Temperature();
  } else if (mode == 13) {  //Unterbrechungen
    FarbwechselMitUnterbrechung();
    if (x = 1) {
      if (c == 0) {
        c = 1;
        digitalWrite(4, HIGH);
      } else {
        c = 0;
        digitalWrite(4, LOW);
      }
    }
    delay(1000);
    time += 74;
  } else if (mode == 14) {  //Bunter Zug
    BunterZug();
    delay(50);
    time += 4;
  }

  FastLED.show();
  delay(15);

  if (time > 1000) {
    mode++;
    time = 0;
    digitalWrite(4, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, HIGH);
  } else {
    x = 0;
  }
  if (mode > 14) {
    mode = 1;
  }

  digitalWrite(5, HIGH);
}
void fadeall() {
  for (int i = 0; i < NUM_LEDS; i++) { leds[i].nscale8(250); }
}
void all(CRGB color) {
  for (a = 0; a < NUM_LEDS; a = a + 1) {
    leds[a] = color;
  }
}

void all_kill(CRGB color) {
  //digitalWrite(5, HIGH);
  //digitalWrite(7, LOW);
  delay(20);
  for (b = BRIGHTNESS; b > 0; b = b - 2) {
    FastLED.setBrightness(b);
    all(color);
    FastLED.show();
    delay(10);
    if (b > 220) {
    } else if (b < 100) {
      b++;
    } else {
      digitalWrite(6, LOW);
      digitalWrite(7, HIGH);
    }
  }
  all(CRGB::Black);
  FastLED.setBrightness(BRIGHTNESS);
}
void blitzen(int x, int y) {
  if (x == 7) {
    digitalWrite(x, LOW);
    delay(y * 100);
    digitalWrite(x, HIGH);
    delay(10);
  } else if (x == 5) {

  } else {
    digitalWrite(x, HIGH);
    delay(y * 100);
    digitalWrite(x, LOW);
    delay(10);
  }
}

void blitzen_all(int y) {
  digitalWrite(4, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(7, LOW);
  delay(y * 100);
  digitalWrite(4, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, HIGH);
  delay(10);
}
void Zug() {
  if (b == 0) {
    if (a < NUM_LEDS) {
      a = a + 1;
    } else {
      b = 1;
    }
  } else {
    if (a > 0) {
      a = a - 1;
    } else {
      b = 0;
    }
  }
  leds[a - 1] = CRGB::Black;
  leds[a] = CRGB::White;
  leds[a + 1] = CRGB::Black;
  Zug_lights(a);
}

void Zug_lights(int a) {
  if (a == 0) {
    digitalWrite(6, HIGH);
  } else if (a == NUM_LEDS) {
    digitalWrite(7, LOW);
  } else if (a == 5 | a == 20) {

    digitalWrite(7, HIGH);
    digitalWrite(6, LOW);
  }
}

void Zug_lights_b(int a) {
  if (a == 0) {
    digitalWrite(6, HIGH);
  } else if (a == NUM_LEDS - 1) {
    digitalWrite(7, LOW);
  } else if (a == 5 | a == 20) {

    digitalWrite(7, HIGH);
    digitalWrite(6, LOW);
  }
}

void Temperature() {
  static uint8_t starthue = 0;
  fill_rainbow(leds, NUM_LEDS, --starthue, 20);
  uint8_t secs = (millis() / 1000) % (DISPLAYTIME * 2);
  if (secs < DISPLAYTIME) {
    FastLED.setTemperature(TEMPERATURE_1);
    leds[0] = TEMPERATURE_1;
  } else {
    FastLED.setTemperature(TEMPERATURE_2);
    leds[0] = TEMPERATURE_2;
  }
}
void FillNUM_LEDSFromPaletteColors(uint8_t colorIndex) {
  uint8_t brightness = 255;

  CRGBPalette16 currentPalette;
  currentPalette = RainbowColors_p;
  TBlendType currentBlending;
  currentBlending = LINEARBLEND;

  for (int i = 0; i < NUM_LEDS; ++i) {
    leds[i] = ColorFromPalette(currentPalette, colorIndex, brightness, currentBlending);
    colorIndex += 3;
  }
}
void ChangePalettePeriodically() {
  uint8_t secondHand = (millis() / 1000) % 60;
  static uint8_t lastSecond = 99;


  CRGBPalette16 currentPalette;
  currentPalette = RainbowColors_p;
  TBlendType currentBlending;
  currentBlending = LINEARBLEND;

  if (lastSecond != secondHand) {
    lastSecond = secondHand;

    if (secondHand == 0) {
      currentPalette = RainbowColors_p;
      currentBlending = LINEARBLEND;
    }

    if (secondHand == 5) {
      currentPalette = RainbowStripeColors_p;
      currentBlending = NOBLEND;
    }
    if (secondHand == 10) {
      currentPalette = RainbowStripeColors_p;
      currentBlending = LINEARBLEND;
    }
    if (secondHand == 15) {
      SetupPurpleAndGreenPalette();
      currentBlending = LINEARBLEND;
    }
    if (secondHand == 20) {
      SetupTotallyRandomPalette();
      currentBlending = LINEARBLEND;
    }
    if (secondHand == 25) {
      SetupBlackAndWhiteStripedPalette();
      currentBlending = NOBLEND;
    }
    if (secondHand == 30) {
      SetupBlackAndWhiteStripedPalette();
      currentBlending = LINEARBLEND;
    }
    if (secondHand == 35) {
      currentPalette = CloudColors_p;
      currentBlending = LINEARBLEND;
    }
    if (secondHand == 40) {
      currentPalette = PartyColors_p;
      currentBlending = LINEARBLEND;
    }
    if (secondHand == 45) {
      currentPalette = myRedWhiteBluePalette_p;
      currentBlending = NOBLEND;
    }
    if (secondHand == 50) {
      currentPalette = myRedWhiteBluePalette_p;
      currentBlending = LINEARBLEND;
    }
  }
}

void SetupTotallyRandomPalette() {
  CRGBPalette16 currentPalette;
  currentPalette = RainbowColors_p;
  TBlendType currentBlending;
  currentBlending = LINEARBLEND;

  for (int i = 0; i < 16; ++i) {
    currentPalette[i] = CHSV(random8(), 255, random8());
  }
}
void SetupBlackAndWhiteStripedPalette() {
  CRGBPalette16 currentPalette;
  currentPalette = RainbowColors_p;
  TBlendType currentBlending;
  currentBlending = LINEARBLEND;

  fill_solid(currentPalette, 16, CRGB::Black);
  currentPalette[0] = CRGB::White;
  currentPalette[4] = CRGB::White;
  currentPalette[8] = CRGB::White;
  currentPalette[12] = CRGB::White;
}
void SetupPurpleAndGreenPalette() {
  CRGBPalette16 currentPalette;
  currentPalette = RainbowColors_p;
  TBlendType currentBlending;
  currentBlending = LINEARBLEND;

  CRGB purple = CHSV(HUE_PURPLE, 255, 255);
  CRGB green = CHSV(HUE_GREEN, 255, 255);
  CRGB black = CRGB::Black;

  currentPalette = CRGBPalette16(
    green, green, black, black,
    purple, purple, black, black,
    green, green, black, black,
    purple, purple, black, black);
}
const TProgmemPalette16 myRedWhiteBluePalette_p PROGMEM = {
  CRGB::Red,
  CRGB::Gray,
  CRGB::Blue,
  CRGB::Black,

  CRGB::Red,
  CRGB::Gray,
  CRGB::Blue,
  CRGB::Black,

  CRGB::Red,
  CRGB::Red,
  CRGB::Gray,
  CRGB::Gray,
  CRGB::Blue,
  CRGB::Blue,
  CRGB::Black,
  CRGB::Black
};

void Halb() {
  for (a = 1; a < NUM_LEDS + 1; a = a + 1) {
    leds[a - 1] = CRGB::Black;
  }


  if (b == 0 | b == 2 | b == 4) {
    for (a = (NUM_LEDS / 2) + 1; a < NUM_LEDS + 1; a = a + 1) {
      leds[a - 1] = CRGB::White;
    }
  } else {
    if (b == 1 | b == 3 | b == 5) {
      for (a = 1; a < (NUM_LEDS / 2) + 1; a = a + 1) {
        leds[a - 1] = CRGB::White;
      }
    } else {
      if (b == 6 | b == 8 | b == 10 | b == 12 | b == 14 | b == 16 | b == 18 | b == 20 | b == 21 | b == 22) {
        Farbton = Farbton + 40;
        for (a = (NUM_LEDS / 2) + 1; a < NUM_LEDS + 1; a = a + 1) {
          leds[a - 1] = CHSV(Farbton, 230, 255);
        }
      } else {
        Farbton = Farbton + 40;
        for (a = 1; a < (NUM_LEDS / 2) + 1; a = a + 1) {
          leds[a - 1] = CHSV(Farbton, 230, 255);
        }
      }
    }
  }
  if (b < 22) {
    b = b + 1;
  } else {
    b = 0;
  }
}


void Blitz() {
  if (d == 0) {
    for (a = 1; a < NUM_LEDS + 1; a = a + 1) {
      leds[a - 1] = CRGB::Black;
      digitalWrite(7, HIGH);
      digitalWrite(6, LOW);
    }
    Farbton += 90;
    s = 50;
  } else {
    if (d < 4) {
      s = s + 5;
      for (a = 1; a < NUM_LEDS + 1; a = a + 1) {
        leds[a - 1] = CHSV(Farbton, 230, 130);
        FastLED.setBrightness(s);
      }
    } else {
      if (d < 6) {
        s = s - 5;
        for (a = 1; a < NUM_LEDS + 1; a = a + 1) {
          leds[a - 1] = CHSV(Farbton, 230, 130);
          FastLED.setBrightness(s);
        }
      } else {
        if (d < 7) {
          s = 50;
          for (a = 1; a < NUM_LEDS + 1; a = a + 1) {
            leds[a - 1] = CRGB::Black;
          }
          delay(150);
        } else {
          if (d < 12) {
            s = s + 5;
            for (a = 1; a < NUM_LEDS + 1; a = a + 1) {
              leds[a - 1] = CHSV(Farbton, 230, 255);
              FastLED.setBrightness(s);
            }
          } else {
            if (d < 13) {
              for (a = 1; a < NUM_LEDS + 1; a = a + 1) {
                leds[a - 1] = CHSV(Farbton, 230, 255);
                FastLED.setBrightness(140);
              }
            } else {
              if (d < 14) {
                for (a = 1; a < NUM_LEDS + 1; a = a + 1) {
                  leds[a - 1] = CHSV(Farbton, 230, 255);
                  FastLED.setBrightness(160);
                }
              } else {
                if (d < 15) {
                  for (a = 1; a < NUM_LEDS + 1; a = a + 1) {
                    leds[a - 1] = CRGB::White;
                    FastLED.setBrightness(180);
                    s = 5;
                  }
                  digitalWrite(6, HIGH);
                  digitalWrite(7, LOW);
                } else {
                  if (d < 16) {
                    for (a = 1; a < NUM_LEDS + 1; a = a + 1) {
                      leds[a - 1] = CRGB::Black;
                    }
                    digitalWrite(7, HIGH);
                    digitalWrite(6, LOW);
                    delay(30);
                  } else {
                    if (d < 17) {
                      for (a = 1; a < NUM_LEDS + 1; a = a + 1) {
                        leds[a - 1] = CRGB::White;
                      }
                      digitalWrite(6, HIGH);
                      digitalWrite(7, LOW);
                    } else {
                      if (d == 17) {
                        for (a = 1; a < NUM_LEDS + 1; a = a + 1) {
                          leds[a - 1] = CRGB::Black;
                        }
                        digitalWrite(7, HIGH);
                        digitalWrite(6, LOW);
                        delay(30);
                      } else {
                        if (d == 18) {
                          for (a = 1; a < NUM_LEDS + 1; a = a + 1) {
                            leds[a - 1] = CRGB::White;
                          }
                          digitalWrite(6, HIGH);
                          digitalWrite(7, LOW);
                        } else {
                          if (d == 19) {
                            for (a = 1; a < NUM_LEDS + 1; a = a + 1) {
                              leds[a - 1] = CRGB::Black;
                            }
                            digitalWrite(7, HIGH);
                            digitalWrite(6, LOW);
                            delay(30);
                          } else {
                            if (d == 20) {
                              for (a = 1; a < NUM_LEDS + 1; a = a + 1) {
                                leds[a - 1] = CRGB::White;
                              }
                              digitalWrite(6, HIGH);
                              digitalWrite(7, LOW);
                            } else {
                              if (d == 21) {
                                for (a = 1; a < NUM_LEDS + 1; a = a + 1) {
                                  leds[a - 1] = CRGB::Black;
                                }
                                digitalWrite(7, HIGH);
                                digitalWrite(6, LOW);
                                delay(30);
                              } else {
                                if (d == 22) {
                                  for (a = 1; a < NUM_LEDS + 1; a = a + 1) {
                                    leds[a - 1] = CRGB::White;
                                  }
                                  digitalWrite(6, HIGH);
                                  digitalWrite(7, LOW);
                                } else {
                                  if (d == 23) {
                                    for (a = 1; a < NUM_LEDS + 1; a = a + 1) {
                                      leds[a - 1] = CRGB::Black;
                                    }
                                    digitalWrite(7, HIGH);
                                    digitalWrite(6, LOW);
                                    delay(30);
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  if (d < 23) {
    d = d + 1;
  } else {
    d = 0;
  }
}

void FarbwechselMitUnterbrechung() {

  Farbton = Farbton + 10;


  if (b == 0) {
    for (a = 0; a < NUM_LEDS - 1; a = a + 1) {
      leds[a] = CHSV(Farbton, 230, 130);
      b = b + 1;
    }
  } else {
    for (a = 0; a < NUM_LEDS - 1; a = a + 1) {
      leds[a] = CRGB::Black;
      b = 0;
    }
    if (Farbton >= 245) {
      b = 0;
    }
  }
}

void BunterZug() {
  if (a < 9) {
    a = 9;
  }

  if (b == 0) {
    if (a < NUM_LEDS) {
      a = a + 1;
    } else {
      b = 1;
    }
  } else {
    if (a > 9) {
      a = a - 1;
    } else {
      b = 0;
    }
  }


  Farbton += 10;
  leds[a] = CRGB::Black;
  leds[a - 1] = CHSV(Farbton, 230, 130);
  leds[a - 2] = CHSV(Farbton - 5, 230, 130);
  leds[a - 3] = CHSV(Farbton - 10, 230, 130);
  leds[a - 4] = CHSV(Farbton - 15, 230, 130);
  leds[a - 5] = CHSV(Farbton - 20, 230, 130);
  leds[a - 6] = CHSV(Farbton - 25, 230, 130);
  leds[a - 7] = CHSV(Farbton - 30, 230, 130);
  leds[a - 8] = CHSV(Farbton - 35, 230, 130);
  leds[a - 9] = CHSV(Farbton - 40, 230, 130);
  leds[a - 10] = CRGB::Black;
}

void lights() {

  for (a = 4; a < 6; a = a + 1) {
    blitzen(a, 5);
    if (a == 8) {
      delay(100);
      blitzen(4, 10);
      blitzen(7, 1);
    }
  }
  for (b = 0; b < 3; b = b + 1) {
    delay(1000);
    blitzen(4, 10);
    blitzen(7, 1);
  }
  for (c = 0; c < 3; c = c + 1) {
    blitzen(7, 1);
    delay(100);
  }
  for (d = 0; d < 3; d = d + 1) {
    delay(1000);
    blitzen(7, 10);
    blitzen_all(20);
    blitzen(4, 3);
    blitzen(7, 10);
  }
  for (b = 0; b < 3; b = b + 1) {
    blitzen_all(50);
    blitzen(4, 10);
  }
  for (b = 0; b < 3; b = b + 1) {
    blitzen(7, 5);
    blitzen(4, 10);
  }

  for (b = 0; b < 3; b = b + 1) {
    blitzen(4, 50);
    blitzen_all(100);
  }
}