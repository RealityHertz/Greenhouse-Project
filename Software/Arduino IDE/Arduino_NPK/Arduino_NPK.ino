#include <ArduinoRS485.h>
#include <ArduinoBLE.h>

#define NPK_SENSOR_ADDRESS 0x01 // Address of the NPK sensor on the RS485 network

const int RE_DE_PIN = 4; // RE and DE pins of RS485 to TTL translator
const int RD_PIN = 3;     // RD pin of RS485 to TTL translator (Receiver)
const int DI_PIN = 2;     // DI pin of RS485 to TTL translator (Transmitter)
float sensorValue;

BLEService customService("180A");
// Assuming you want a characteristic that can hold up to 4 bytes (e.g., a float)
BLECharacteristic ble_npk("2a57", BLERead | BLENotify, 16, true);

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
  if(!BLE.begin()){
    Serial.println("BLE Failed to Initiate");
    delay(500);
    while(1);
  }

    BLE.setLocalName("Arduino NPK Sensor");
    
    // Setting BLE Service Advertisment
    BLE.setAdvertisedService(customService);
    
    // Adding characteristics to BLE Service Advertisment
    customService.addCharacteristic(ble_npk);

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

      // Modify the way data is sent to BLE characteristic
      ble_npk.writeValue((uint8_t*)&sensorValue, sizeof(sensorValue));

      //Serial.println("Reading Sensors");
      //Serial.println(sensorValue);
      Serial.print("\n");
      delay(1000);
    }
  }
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
