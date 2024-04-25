#include <ArduinoBLE.h>

const int TRIGGER_PIN = 2;
const int ECHO_PIN = 3;

String distanceStr;

BLEService customService("180F");
BLEStringCharacteristic ble_water_level("2A57", BLERead | BLENotify, 13);

void setup() {
  Serial.begin(9600);
  
  // Initialize the trigger and echo pins
  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  
  // Initialize BLE
  while (!Serial);
  if (!BLE.begin()) {
    Serial.println("BLE Failed to Initiate");
    while (1);
  }
  
  BLE.setLocalName("Water Level Sensor");
  BLE.setAdvertisedService(customService);
  customService.addCharacteristic(ble_water_level);
  BLE.addService(customService);
  BLE.advertise();
}

void loop() {
  BLEDevice central = BLE.central();
  if (central) {
    Serial.print("Connected to central: ");
    Serial.println(central.address());
    while (central.connected()) {
      delay(200);
      readWaterLevel();
      ble_water_level.writeValue("Water Level: " + distanceStr + " cm");
      delay(1000);
    }
  }
}

void readWaterLevel() {
  // Triggering the ultrasonic sensor
  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);
  
  // Calculating the duration for the sound to travel
  long duration = pulseIn(ECHO_PIN, HIGH);
  
  // Calculating the distance in centimeters
  float distance_cm = duration * 0.034 / 2;
  
  // Convert distance to string
  distanceStr = String(distance_cm);
  
  // Print water level for debugging
  Serial.print("Water Level: ");
  Serial.print(distance_cm);
  Serial.println(" cm");
}
