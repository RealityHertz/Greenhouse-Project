int lightPin = 9; // Pin connected to the external light

void setup() {
  pinMode(lightPin, OUTPUT);
}

void loop() {
  digitalWrite(lightPin, HIGH); // Turn on the external light
  delay(60000); // Wait for 10 seconds
  digitalWrite(lightPin, LOW); // Turn off the external light
  delay(60000); // Wait for 10 seconds
}
