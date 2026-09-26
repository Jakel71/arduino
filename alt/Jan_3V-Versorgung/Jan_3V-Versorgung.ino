const int outputPin = 7; // Wähle den gewünschten Pin

void setup() {
    pinMode(outputPin, OUTPUT); // Setze den Pin als Output
}

void loop() {
    digitalWrite(outputPin, HIGH); // Setze den Pin auf HIGH (3,3 V)
    delay(1000); // Warte 1 Sekunde
    //digitalWrite(outputPin, LOW); // Setze den Pin auf LOW (0 V)
    //delay(1000); // Warte 1 Sekunde
}
//funktioniert nicht!!!