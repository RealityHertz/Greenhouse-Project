#include <SPI.h>
#include <ArduinoBLE.h>

// Define the pins for SPI communication
const int sensorMISO = 30; // MISO pin
const int sensorSCK = 11; // Clock pin
const int sensorCS = 28; // Chip Select

uint8_t buffer[4];

BLEService customService("180E");
// Assuming you want a characteristic that can hold up to 4 bytes (e.g., a float)
BLECharacteristic ble_no2("2a57", BLERead | BLENotify, 4, true);

void readValues();

void setup() {
  Serial.begin(9600);

  SPI.begin();

  // Set SPI pins direction
  pinMode(sensorMISO, INPUT);
  pinMode(sensorSCK, OUTPUT);
  pinMode(sensorCS, OUTPUT);
  digitalWrite(sensorCS, HIGH); // Deselect the SPI device initially

  // Initialize the MIKROE 3700 sensor
  while(!Serial);
  if(!BLE.begin()){
    Serial.println("BLE Failed to Initiate");
    delay(500);
    while(1);
  }

    BLE.setLocalName("Arduino NO2 Sensor");
    
    // Setting BLE Service Advertisment
    BLE.setAdvertisedService(customService);
    
    // Adding characteristics to BLE Service Advertisment
    customService.addCharacteristic(ble_no2);

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

      ble_no2.writeValue(buffer, sizeof(buffer));

      Serial.println("Reading Sensors");
      Serial.print("\n");
      delay(1000);
    }
  }
}

void readValues(){
  digitalWrite(sensorCS, LOW);
  
  // Send command byte to start ADC conversion
  SPI.transfer(0x06); // Start bit
  SPI.transfer(0x00); // Null byte

  byte highByte = SPI.transfer(0x00);
  byte lowByte = SPI.transfer(0x00);

  float result = ((highByte << 8) | lowByte);
  
  // Deselect the SPI device
  digitalWrite(sensorCS, HIGH);

  memcpy(buffer, &result, sizeof(result));

  Serial.println(result);
}
