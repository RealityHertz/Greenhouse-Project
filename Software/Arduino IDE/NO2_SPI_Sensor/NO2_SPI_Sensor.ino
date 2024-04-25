#include <SPI.h>
#include <ArduinoBLE.h>

// Define the pins for SPI communication
const int sensorMISO = 30; // MISO pin
const int sensorSCK = 11; // Clock pin
const int sensorCS = 28; // Chip Select

String s;

BLEService customService("180E");
BLEStringCharacteristic ble_no2("2A57", BLERead | BLENotify, 13);

void readValues();

void setup() {
  Serial.begin(9600);
  // Initialize the DHT20 sensor
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

      ble_no2.writeValue(s);

      Serial.println("Reading Sensors");
      Serial.println(s);
      Serial.print("\n");
      delay(1000);
    }
  }
}

void readValues(){
  digitalWrite(sensorCS, LOW);
  
  // Read data from the sensor via SPI
  byte sensorSPI = SPI.transfer(0x00);

  s = String(sensorSPI);

  digitalWrite(sensorCS, HIGH);

  delay(5000);
}