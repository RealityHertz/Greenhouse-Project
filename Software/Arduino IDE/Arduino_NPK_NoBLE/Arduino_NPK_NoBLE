#include <ArduinoRS485.h>

#define NPK_SENSOR_ADDRESS 0x01 // Address of the NPK sensor on the RS485 network

const int RE_DE_PIN = 4; // RE and DE pins of RS485 to TTL translator
const int RD_PIN = 3;     // RD pin of RS485 to TTL translator (Receiver)
const int DI_PIN = 2;     // DI pin of RS485 to TTL translator (Transmitter)
float sensorValue;

void readValues();

void setup() {
  // Initialize Serial port for debugging
  Serial.begin(9600);
  
  // Initialize RS485 communication
  Serial1.begin(9600);
  pinMode(RE_DE_PIN, OUTPUT);
  digitalWrite(RE_DE_PIN, HIGH); // Enable transmitter mode
  pinMode(RD_PIN, INPUT);
  pinMode(DI_PIN, OUTPUT);
  digitalWrite(DI_PIN, HIGH); // Set to transmit mode

  while(!Serial);
}

void loop() {
      readValues();
      Serial.print("NPK Value: ");
      Serial.println(sensorValue);
      delay(1000);
}

void readValues(){
  uint8_t data[4]; // Array to store received data
  int i = 0;
  
  // Enable receiver mode
  digitalWrite(RE_DE_PIN, LOW);
  
  // Check if data is available to read
  while(Serial1.available() > 0 && i < 4){
    data[i] = Serial1.read();
    i++;
  }

  // Convert received bytes to float
  memcpy(&sensorValue, data, sizeof(sensorValue));
}