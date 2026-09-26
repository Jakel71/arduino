// 4 Channel Receiver | 4 Kanal Alıcı
// PWM output on pins D2, D3, D4, D5 (Çıkış pinleri)

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

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

void ResetData()
{
  // Define the initial value of each data input. | Veri girişlerinin başlangıç değerleri
  // The middle position for Potentiometers. (254/2=127) | Potansiyometreler için orta konum
  data.throttle = 127; // Motor Stop | Motor Kapalı
  data.pitch = 127;    // Center | Merkez
  data.roll = 127;     // Center | Merkez
  data.yaw = 127;      // Center | Merkez
}

void setup()
{
  // Set the pins for each PWM signal | Her bir PWM sinyal için pinler belirleniyor.
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);

  // Configure the NRF24 module
  ResetData();
  radio.begin();
  radio.openReadingPipe(1, pipeIn);
  radio.startListening(); // Start the radio communication for receiver | Alıcı olarak sinyal iletişimi başlatılıyor
}

unsigned long lastRecvTime = 0;

void recvData()
{
  while (radio.available()) {
    radio.read(&data, sizeof(Signal));
    lastRecvTime = millis();   // Receive the data | Data alınıyor
  }
}

void loop()
{
  recvData();
  unsigned long now = millis();
  if (now - lastRecvTime > 1000) {
    ResetData(); // Signal lost.. Reset data | Sinyal kayıpsa data resetleniyor
  }

  ch_width_1 = map(data.throttle, 0, 255, 0, 255);     // pin D2 (PWM signal)
  ch_width_2 = map(data.pitch,    0, 255, 0, 255);     // pin D3 (PWM signal)
  ch_width_3 = map(data.roll,     0, 255, 0, 255);     // pin D4 (PWM signal)
  ch_width_4 = map(data.yaw,      0, 255, 0, 255);     // pin D5 (PWM signal)

  // Write the PWM signal | PWM sinyaller çıkışlara gönderiliyor
  analogWrite(2, ch_width_1);
  analogWrite(3, ch_width_2);
  analogWrite(4, ch_width_3);
  analogWrite(5, ch_width_4);
}
