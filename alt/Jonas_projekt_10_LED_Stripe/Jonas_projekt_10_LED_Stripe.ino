#include <FastLED.h>
#define LED_PIN 6 
CRGB leds[64];
int c = 0;      //Start
int LEDs=64;    //How Many LEDs
int a = 0;      //which LED
int b = 0;      //which order
int m = 0;      //m=Mode
int d = 0;      //Blitz
int s = 0;      //Stärke
int doInit = 0; //Initialisierung
int e = 0;
int f = 0;


int z = 0; //Zeit
byte Farbton = 0;

void setup() {
  // put your setup code here, to run once:
  FastLED.addLeds<NEOPIXEL, LED_PIN>(leds, LEDs);
  FastLED.setBrightness(  100 );

  for (c = 0; c < 3 ; c = c + 1) {
    for (a = 0; a < LEDs; a = a + 1) {
      leds[a] = CRGB::White;
    }
    FastLED.show();
    delay(500);
    for (a = 0; a < LEDs; a = a + 1) {
      leds[a] = CRGB::Black;
    }
    FastLED.show();
    delay(500);
    a = 1;
  }
}

void Next() {
  m = m + 1;
  a = 1;
  b = 0;
  d = 0;
  z = 100;
  Farbton = 0;
  e = 17;
}
void Zug() {
  if (b == 0) {
    if (a < LEDs-1) {
      a = a + 1;
    }
    else {
      b = 1;
    }
  } else {
    if (a > 1) {
      a = a - 1;
    }
    else {
      Next();
    }
  }
  leds[a - 1] = CRGB::Black;
  leds[a] = CRGB::White;
  leds[a + 1] = CRGB::Black;
  z = 30;
}

void BunterZug() {
  z = 50;
  if (a < 11) {
    a = 11;
    Farbton = 20;
  }

  Farbton += 10;
  leds[a] = CRGB::Black;
  leds[a - 1] = CHSV( Farbton, 230, 130);
  leds[a - 2] = CHSV( Farbton - 5, 230, 130);
  leds[a - 3] = CHSV( Farbton - 10, 230, 130);
  leds[a - 4] = CHSV( Farbton - 15, 230, 130);
  leds[a - 5] = CHSV( Farbton - 20, 230, 130);
  leds[a - 6] = CHSV( Farbton - 25, 230, 130);
  leds[a - 7] = CHSV( Farbton - 30, 230, 130);
  leds[a - 8] = CHSV( Farbton - 35, 230, 130);
  leds[a - 9] = CHSV( Farbton - 40, 230, 130);
  leds[a - 10] = CRGB::Black;
  if (a < LEDs) {
    a = a + 1;
  }
  else {
    z = 5;
    Next();
  }
}

void BunterAblauf() {
  if (a < LEDs) {
    a = a + 1;
  }
  else {
    Next();
  }
  Farbton += 10;
  leds[a - 1] = CHSV( Farbton, 230, 130);
  leds[a] = CRGB::Black;
  z = 50;
}

void Farbwechsel() {

  Farbton = Farbton + 10;
  z = 100;

  for (a = 1; a < LEDs; a = a + 1) {
    leds[a] = CHSV( Farbton, 230, 130);
  }

  if (Farbton >= 245) {
    Next();
  }
  leds [0] = CRGB::Blue;
}
void FarbwechselMitUnterbrechung() {

  Farbton = Farbton + 10;
  

  if (b == 0) {
    for (a = 1; a < LEDs; a = a + 1) {
      leds[a] = CHSV( Farbton, 230, 130);
      b = b + 1;
    }
    z = 300;
  } else {
    for (a = 1; a < LEDs; a = a + 1) {
      leds[a] = CRGB::Black;
      b = 0;
    }
    z = 100;
    if (Farbton >= 245) {
      Next();
    }

  }
}
void Blitz () {
  if (d == 0) {
    for (a = 1; a < LEDs+1; a = a + 1) {
      leds[a - 1] = CRGB::Black;
      z = 200;
    }
  } else {
    if (d < 4) {
      s = s + 5;
      for (a = 1; a < LEDs+1; a = a + 1) {
        leds[a - 1] = CRGB(30, 40, s * 10);
        z = 200;
        FastLED.setBrightness(  s );
      }
    } else {
      if (d < 6) {
        s = s - 5;
        for (a = 1; a < LEDs+1; a = a + 1) {
          leds[a - 1] = CRGB(30, 40, s * 10);
          z = 200;
          FastLED.setBrightness(  s );
        }
      } else {
        if (d < 7) {
          s = 0;
          for (a = 1; a < LEDs+1; a = a + 1) {
            leds[a - 1] = CRGB::Black;
            z = 500;
          }
        } else {
          if (d < 12) {
            s = s + 5;
            for (a = 1; a < LEDs+1; a = a + 1) {
              leds[a - 1] = CRGB(30, 40, s * 10);
              z = 200;
              FastLED.setBrightness(  s );
            }
          } else {
            if (d < 13) {
              for (a = 1; a < LEDs+1; a = a + 1) {
                leds[a - 1] = CRGB (150, 150, 250);
                FastLED.setBrightness(  40 );
              }
              z = 200;
            } else {
              if (d < 14) {
                for (a = 1; a < LEDs+1; a = a + 1) {
                  leds[a - 1] = CRGB(200, 200, 250);
                  FastLED.setBrightness(  60 );
                }
                z = 200;
              } else {
                if (d < 15) {
                  for (a = 1; a < LEDs+1; a = a + 1) {
                    leds[a - 1] = CRGB::White;
                    FastLED.setBrightness(  100 );
                    z = 200;
                    s = 5;
                  }
                } else {
                  if (d < 16) {
                    for (a = 1; a < LEDs+1; a = a + 1) {
                      leds[a - 1] = CRGB::Black;
                      z = 200;
                    }
                  } else {
                    if (d < 17) {
                      for (a = 1; a < LEDs+1; a = a + 1) {
                        leds[a - 1] = CRGB::White;
                        z = 200;
                      }
                    } else {
                      if (d == 17) {
                        for (a = 1; a < LEDs+1; a = a + 1) {
                          leds[a - 1] = CRGB::Black;
                          z = 200;
                        }
                      } else {
                        if (d == 18) {
                          for (a = 1; a < LEDs+1; a = a + 1) {
                            leds[a - 1] = CRGB::White;
                            z = 100;
                          }
                        } else {
                          if (d == 19) {
                            for (a = 1; a < LEDs+1; a = a + 1) {
                              leds[a - 1] = CRGB::Black;
                              z = 200;
                            }
                          } else {
                            if (d == 20) {
                              for (a = 1; a < LEDs+1; a = a + 1) {
                                leds[a - 1] = CRGB::White;
                                z = 100;
                              }
                            } else {
                              if (d == 21) {
                                for (a = 1; a < LEDs+1; a = a + 1) {
                                  leds[a - 1] = CRGB::Black;
                                  z = 200;
                                }
                              } else {
                                if (d == 22) {
                                  for (a = 1; a < LEDs+1; a = a + 1) {
                                    leds[a - 1] = CRGB::White;
                                    z = 100;
                                  }
                                }
                                else {
                                  if (d == 23) {
                                    for (a = 1; a < LEDs+1; a = a + 1) {
                                      leds[a - 1] = CRGB::Black;
                                      z = 100;
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
  }
  if (d < 23) {
    d = d + 1;
  } else {
    Next();
  }
}


void Halb() {
  for (a = 1; a < LEDs+1; a = a + 1) {
    leds[a - 1] = CRGB::Black;
  }


  if (b == 0 | b == 2 | b == 4) {
    for (a = (LEDs/2)+1; a < LEDs+1; a = a + 1) {
      leds[a - 1] = CRGB::White;
    }
  } else {
    if (b == 1 | b == 3 | b == 5) {
      for (a = 1; a < (LEDs/2)+1; a = a + 1) {
        leds[a - 1] = CRGB::White;
      }
    } else {
      if (b == 6 | b == 8 | b == 10 | b == 12 | b == 14 | b == 16) {
        Farbton = Farbton + 40;
        for (a = (LEDs/2)+1; a < LEDs+1; a = a + 1) {
          leds[a - 1] = CHSV( Farbton, 230, 130);
        }
      } else {
        Farbton = Farbton + 40;
        for (a = 1; a < (LEDs/2)+1; a = a + 1) {
          leds[a - 1] = CHSV( Farbton, 230, 130);
        }
      }
    }
  }
  if (b < 17) {
    b = b + 1;
  } else {
    Next();
  }
  z = 500;
}

void loop() {
  // put your main code here, to run repeatedly:
  switch (m) {
    case 1:
    case 2:
      BunterZug();
      m=4;
      leds [0] = CRGB::Red;
      break;

    case 4:
    case 5:
      Farbwechsel();
      leds [0] = CRGB::Green;
      break;

    case 7:
    case 8:
      Blitz();
      leds [0] = CRGB::Blue;
      break;

    case 10:
      FarbwechselMitUnterbrechung();
      leds [0] = CRGB::White;
      break;

    case 12:
      BunterAblauf();
      leds [0] = CRGB::Yellow;
      break;

    case 14:
      Halb();
      leds [0] = CRGB::Blue;
      break;
    case 15:
       for (a = 1; a < LEDs+1; a = a + 1) {
        leds[a - 1] = CRGB::Blue;
      }
      m = 0;
      break;

    default:
      Zug();
      break;
  }


  FastLED.show();
  delay (z);

}
