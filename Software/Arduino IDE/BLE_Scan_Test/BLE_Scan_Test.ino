#include <ArduinoBLE.h>

struct DeviceInfo {
  String address;
  String uuid;
};

// Define an array of devices you want to interact with
DeviceInfo devices[] = {
  //{"e0:5a:1b:7a:c4:0e", "180D"},
  {"78:21:84:ab:ef:26", "180C"} // DHT20 Sensor
  //{"e0:5a:1b:79:72:4e", "180E"} //NO2 Sensor
  //{"e0:5a:1b:79:72:4e", "180F"} //CO2 Sensor
  //{"e0:5a:1b:7a:c4:0e", "180A"} //NPK Sensor
  //{"e0:5a:1b:77:e7:e6", "180B"} //Water Level Sensor
};
int currentDeviceIndex = 0;

void setup() {
  Serial.begin(9600, SERIAL_8N1);
  while (!Serial);

  Serial1.begin(9600, SERIAL_8N1);
  while(!Serial1);

  if (!BLE.begin()) {
    Serial.println("starting Bluetooth® Low Energy module failed!");
    while (1);
  }    
  BLE.setLocalName("Central");
  Serial.println("Bluetooth® Low Energy Central scan");
  BLE.scanForAddress("78:21:84:ab:ef:26"); // Start scanning without specifying an address
}

void loop() {
  // Check if we've gone through all devices
  if (currentDeviceIndex >= (sizeof(devices) / sizeof(devices[0]))) {
    Serial.println("Processed all devices. Restarting...");
    currentDeviceIndex = 0; // Optionally restart or halt the program
    //return; // Uncomment to stop after processing all devices
  }

  BLEDevice peripheral = BLE.available();

  if (peripheral) {
    // Get the current target device info
    DeviceInfo& targetDevice = devices[currentDeviceIndex];

    // Check if the found peripheral matches the target address
    if(peripheral.address() == targetDevice.address) {
      Serial.println("Discovered a peripheral");
      Serial.println("-----------------------");
      Serial.print("Address: ");
      Serial.println(peripheral.address());

      Serial.print("Local Name: ");
      Serial.println(peripheral.localName());

      Serial.print("UUID: ");
      Serial.print(peripheral.advertisedServiceUuid());
      Serial.println();

      BLE.stopScan();

      // Assuming explorerPeripheral function is adapted to use DeviceInfo
      explorerPeripheral(peripheral, targetDevice.uuid);

      // Move to the next device
      currentDeviceIndex++;
      BLE.scan(); // Restart scanning for the next device
    }
  }
}

void explorerPeripheral(BLEDevice peripheral, String uuic) {
  // connect to the peripheral
  Serial.println("Connecting ...");

  if (peripheral.connect()) {
    Serial.println("Connected");
  } else {
    Serial.println("Failed to connect!");
    return;
  }

  // discover peripheral attributes
  Serial.println("Discovering attributes ...");
  if (peripheral.discoverAttributes()) {
    Serial.println("Attributes discovered");
  } else {
    Serial.println("Attribute discovery failed!");
    peripheral.disconnect();
    return;
  }

  // loop the services of the peripheral and explore each
  for (int i = 0; i < peripheral.serviceCount(); i++) {
    BLEService service = peripheral.service(i);
    exploreService(service);
  }

  Serial.println();

  // we are done exploring, disconnect
  Serial.println("Disconnecting ...");
  peripheral.disconnect();
  Serial.println("Disconnected");
}

void exploreService(BLEService service) {
  // Filter for services with UUIDs 180D and 180C
  const char* serviceUUID = service.uuid();
  if(strcmp(serviceUUID, "180c") == 0 || strcmp(serviceUUID, "180b") == 0){
    Serial.print("Service ");
    Serial.println(serviceUUID);

    // Loop the characteristics of the service and explore each
    for (int i = 0; i < service.characteristicCount(); i++) {
      BLECharacteristic characteristic = service.characteristic(i);
      // Filter for characteristic with UUID 2A57
      if(strcmp(characteristic.uuid(), "2a57") == 0){
        exploreCharacteristic(characteristic);
      }
    }
  }
}

void exploreCharacteristic(BLECharacteristic characteristic) {
  // Print the UUID and properties of the characteristic
  Serial.print("\tCharacteristic ");
  Serial.print(characteristic.uuid());

  // Check if the characteristic is readable
  if (characteristic.canRead()) {
    // Read the characteristic value
    characteristic.read();

    if (characteristic.valueLength() > 0) {
      // Print out the value of the characteristic
      Serial.print(", value 0x");
      printData(characteristic.value(), characteristic.valueLength());

      // Send the data to PLC
      sendDataToPLC(characteristic.value(), characteristic.valueLength());
      delay(2000);
    }
  }
  Serial.println();
}

// Define the function to send data to the PLC via TTL to RS232 Module
void sendDataToPLC(const unsigned char data[], int length) {
  // Send data to the PLC via TTL to RS232 Module connected to Rx/Tx
  Serial1.write(data, length); // Use Serial1 to send data
  Serial1.write('X'); //Cut Off

  // For debugging, you might want to print what you're sending to the Serial Monitor as well
  Serial.println("\n");
  Serial.println("Sending to PLC: ");
  for (int i = 0; i < length; i++) {
    unsigned char b = data[i];
    if (b < 16) {
      Serial.print("0");
    }
    Serial.print(b, HEX);
  }
  Serial.println();
}

void printData(const unsigned char data[], int length) {
  for (int i = 0; i < length; i++) {
    unsigned char b = data[i];

    if (b < 16) {
      Serial.print("0");
    }

    Serial.print(b, HEX);
  }
}


