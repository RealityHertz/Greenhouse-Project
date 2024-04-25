#include <DFRobot_DHT20.h>
#include <ArduinoBLE.h>

// Create an instance of the DFRobot_DHT20 class
DFRobot_DHT20 dht20;

String t, h;

BLEService customService("180C");
BLEStringCharacteristic ble_temperature("2A57", BLERead | BLENotify, 13);

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
  while (!dht20.begin()) {
    Serial.println("Failed to initialize DHT20, please check if the sensor is connected properly.");
    delay(1000);
  }

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

      ble_temperature.writeValue(t);

      Serial.println("Reading Sensors");
      Serial.println(t);
      Serial.println(h);
      Serial.print("\n");
      delay(1000);
    }
  }

  //Serial.print("Disconnected from central: ");
  //Serial.println(central.address());
  // Read temperature and humidity values

}

void readValues(){
  float temperature = dht20.getTemperature();
  float humidity = dht20.getHumidity();

  // Check if any reads failed and exit early (to try again).
  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("Failed to read from DHT20 sensor!");
    return;
  }

  t = String(temperature) + " C";
  h = String(humidity) + " %rH";

}