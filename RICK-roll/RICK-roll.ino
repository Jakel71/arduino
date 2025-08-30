#include "Keyboard.h"

void keyt (int KEY){
  Keyboard.press(KEY);
  delay(50);
  Keyboard.release(KEY);
}

void setup() {
  Serial.begin(9600);

  Keyboard.begin();
  delay(500);
  
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('r');
  Keyboard.releaseAll();
  
  delay(100);

  Keyboard.println("CMD");

  delay(1000);
  
  Keyboard.println("curl ASCII.live&can/zou/hear/me");
  
}

void loop (){

}