int PinTrig=7
int PinEcho=6
long dauer=0
long entfernung_in_cm=0

void setup() {
pinMode(PinTrig, OUTPUT);
pinMode(PinEcho, INPUT);

}
void loop() {
digitalWrite(PinTrig, HIGH);
delay(5);
digitalWrite(PinTrig, LOW);
delay(10);
digitalWrite(PinTrig, LOW);
dauer = pulseln(PinEcho, HIGH);
entfernug_in cm = (dauer/2)*0.03432;
if (entfernug_in_cm >= 500 || entfernung_in_cm <=0)

}
