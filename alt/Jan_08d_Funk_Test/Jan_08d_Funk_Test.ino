#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

// Pins for motor control
const int controlPin1A = 2;
const int controlPin2A = 5;
const int EnablePin = 9;

// Motor settings
int motorSpeed = 200;
int motorDirection = 1;

// NRF24 module settings
int ch_width_1 = 0;
int ch_width_2 = 0;
int ch_width_3 = 0;
int ch_width_4 = 0;

struct Signal {
  byte throttle;      
  byte pitch;
  byte roll;
  byte yaw;
};

Signal data;
const uint64_t pipeIn = 0xE9E8F0F0E1LL;
RF24 radio(7, 8); 

void ResetData() {
  data.throttle = 127; // Motor Stop
  data.pitch = 127;    // Center
  data.roll = 127;     // Center
  data.yaw = 127;      // Center
}

void SetMotorControl() {
  if (motorDirection == 1) {
    digitalWrite(controlPin1A, HIGH);
    digitalWrite(controlPin2A, LOW);
  } else {
    digitalWrite(controlPin1A, LOW);
    digitalWrite(controlPin2A, HIGH);
  }
  analogWrite(EnablePin, motorSpeed);
}

void setup() {
  pinMode(controlPin1A, OUTPUT);
  pinMode(controlPin2A, OUTPUT);
  pinMode(EnablePin, OUTPUT);
  digitalWrite(EnablePin, LOW);

  // Set the pins for PWM signals
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);

  //sure that Arduino don't send something to Radio
  pinMode(7,INPUT);
  pinMode(8,INPUT);
  pinMode(11,INPUT);
  pinMode(12,INPUT);
  pinMode(13,INPUT);
 
  // Configure the NRF24 module
  ResetData();
  radio.begin();
  radio.openReadingPipe(1, pipeIn);
  radio.startListening();
}

unsigned long lastRecvTime = 0;

void recvData() {
  while (radio.available()) {
    radio.read(&data, sizeof(Signal));
    lastRecvTime = millis();
  }
}

void loop() {
  recvData();
  unsigned long now = millis();
  if (now - lastRecvTime > 1000) {
    ResetData(); // Signal lost.. Reset data
  }

  ch_width_1 = map(data.throttle, 0, 255, 0, 255);
  ch_width_2 = map(data.pitch,    0, 255, 0, 255);
  ch_width_3 = map(data.roll,     0, 255, 0, 255);
  ch_width_4 = map(data.yaw,      0, 255, 0, 255);

  // Set motor speed and direction based on received throttle data
  //motorSpeed = ch_width_1;
  motorDirection = ch_width_2 > 127 ? 1 : 0; // Example: use pitch for direction control
  SetMotorControl();

  // Optionally write the PWM signal to other pins
  analogWrite(3, ch_width_2);
  analogWrite(4, ch_width_3);
  analogWrite(5, ch_width_4);
}
