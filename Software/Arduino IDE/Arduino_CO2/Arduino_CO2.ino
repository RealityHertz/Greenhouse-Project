#include "Arduino.h"
#include <ArduinoBLE.h>
#include "MHZCO2.h"

#define RX_PIN 17                                          // Rx pin which the MHZ19 Tx pin is attached to
#define TX_PIN 16                                          // Tx pin which the MHZ19 Rx pin is attached to
#define BAUDRATE 9600

MHZ19B myMHZ19;
int CO2;

BLEService customService("180F");
// Assuming you want a characteristic that can hold up to 4 bytes (e.g., a float)
BLECharacteristic ble_co2("2a57", BLERead | BLENotify, 4, true);

void readValues();

void setup() {
  Serial.begin(9600);
  myMHZ19.begin(&Serial1);
  Serial1.begin(9600);

  // Initialize the MIKROE 3700 sensor
  while(!Serial);
  if(!BLE.begin()){
    Serial.println("BLE Failed to Initiate");
    delay(500);
    while(1);
  }

    BLE.setLocalName("Arduino CO2 Sensor");
    
    // Setting BLE Service Advertisment
    BLE.setAdvertisedService(customService);
    
    // Adding characteristics to BLE Service Advertisment
    customService.addCharacteristic(ble_co2);

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

      ble_co2.writeValue((uint32_t)CO2);

      delay(1000);
    }
  }
}

void readValues(){
  myMHZ19.measure();
  CO2 = myMHZ19.getCO2();
  Serial.print("CO2: ");
  Serial.print(CO2);
  delay(1000);
}

