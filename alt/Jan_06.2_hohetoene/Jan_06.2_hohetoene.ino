#include "pitches.h"

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
tone(8,NOTE_GS7);
delay(1000);
noTone(8);
tone(8,NOTE_C8);
delay(1000); 
noTone(8); 
}
