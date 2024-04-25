#include <ArduinoBLE.h>

const int TRIGGER_PIN = 2;
const int ECHO_PIN = 3;

float distance_cm;

void readValues();

BLEService customService("180B");
// Assuming you want a characteristic that can hold up to 4 bytes (e.g., a float)
BLECharacteristic ble_waterLevel("2a57", BLERead | BLENotify, 16, true);

void setup() {
  // Initialize serial communication
  Serial.begin(9600);
  
  // Initialize the trigger and echo pins
  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  while(!Serial);
  if(!BLE.begin()){
    Serial.println("BLE Failed to Initiate");
    delay(500);
    while(1);
  }

    BLE.setLocalName("Arduino Water Level Sensor");
    
    // Setting BLE Service Advertisment
    BLE.setAdvertisedService(customService);
    
    // Adding characteristics to BLE Service Advertisment
    customService.addCharacteristic(ble_waterLevel);

    // Adding the service to the BLE stack
    BLE.addService(customService);

    // Start advertising
    BLE.advertise();
}

void loop() {
  BLEDevice central = BLE.central();
  if(central){
    Serial.print("Connected to central: ");
    Serial.println(central.address());
    while(central.connected()){
      delay(200);
      readValues();
      if(distance_cm <= 20){
        ble_waterLevel.writeValue("1");
      }
      else if(distance_cm > 20){
        ble_waterLevel.writeValue("0");
      }
      Serial.print("\n");
      delay(1000);
    }
  }
}

void readValues(){
  // Triggering the ultrasonic sensor
  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);
  
  // Calculating the duration for the sound to travel
  long duration = pulseIn(ECHO_PIN, HIGH);
  
  // Calculating the distance in centimeters
  distance_cm = duration * 0.034 / 2;
  
  // Sending the distance over serial communication
  Serial.print("Distance: ");
  Serial.print(distance_cm);
  Serial.println(" cm");
  
  // Wait before taking the next measurement
  delay(500);
}