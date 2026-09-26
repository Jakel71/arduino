#define MIC_PIN    A5                                       // Mikrofon

float micLev;


void setup() {
  Serial.begin(9600);
  analogReference(DEFAULT);                                 // Kommentiere diese Zeile für 3,3-V-Arduino's aus.
  delay(1000);
} // setup()



void loop() {
  getSample();                                              // Sample die Geräusche.
} // loop()



void getSample() {

  int16_t micIn;

  micIn = analogRead(MIC_PIN);                              // Probiere das Mikrofon aus. Der Bereich ergibt sich von 0 bis 1023.
  micLev = ((micLev * 31) + micIn) / 32;                    // Glätte es über die letzten 32 Proben.

  micIn = micIn - micLev;
  micIn = abs(micIn);
  micIn *= 10;                                                // Verstärke die Ausschläge.

  Serial.print(micIn); Serial.print(" ");
  Serial.print(0); Serial.print(" ");
  Serial.print(100); Serial.print(" ");
  Serial.println(" ");

} // getSample()