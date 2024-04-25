#include <Adafruit_AHTX0.h>
#include <ArduinoBLE.h>

// Create an instance of the AHTX0 class
Adafruit_AHTX0 aht;

String t, h;

BLEService customService("180c");
BLEStringCharacteristic ble_temperature("2a57", BLERead | BLENotify, 13);

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
  /*while (!aht.begin()) {
    Serial.println("Failed to initialize DHT20, please check if the sensor is connected properly.");
    delay(1000);
  }*/

    BLE.setLocalName("Arduino Temperature Sensor");
    
    // Setting BLE Service Advertisment
    BLE.setAdvertisedService(customService);
    
    // Adding characteristics to BLE Service Advertisment
    customService.addCharacteristic(ble_temperature);

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

      ble_temperature.writeValue("Temp: " + t);

      //ble_temperature.writeValue(h);

      Serial.print("\n");
      delay(1000);
    }
  }
}

void readValues(){
  sensors_event_t humidity, temp;

  aht.getEvent(&humidity, &temp);

  float temperature = temp.temperature;
  //float humidityValue = humidity.relative_humidity;

  t = String(temperature);
  //h = String(humidityValue);

  Serial.print("Temp: ");
  Serial.println(t);
  Serial.print("Humidity: ");
  Serial.println(h);

  delay(5000);
}