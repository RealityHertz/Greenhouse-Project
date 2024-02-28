# *Detail Design: PLC Subsystem*

## **Function of the Subsystem:**
The function of this subsystem is to receive data from the various sensors and relay that information to the HMI display. This system will also send commands to the various subsystems to change behaviors according to the PLC code.

## **Constraints:**

|Segment|Number|Constraint Description|
|--------|-|-------------------------------------------------|
|PLC|1|The PLC scan time shall be able to scan fast enough to accommodate the desired sampling rate for all subsystem sensors. These sensors will be sending data every 5 minutes|
|PLC|2|The PLC shall have a compatible communication ports to allow for avaliable programming|
|PLC|3|The PLC shall be able to operate in 30% to 95% relative non–condensing humidity to ensure its suitability for deployment in greenhouse environmental conditions without risking damage due to moisture [2]|
|PLC|4|The PLC shall be able to input data from at least 3 Arduino Nano 33 IoT|
|PLC|5|The PLC shall be able to log data every hour for at least 1 month|
|Power Supply|6|The power supply  shall incorporate overcurrent protection and overvoltage protection to provide protection mechanisms for safeguarding connected equipment and ensuring the reliability of the power distribution system|

## **Buildable Schematic:**

![PLC Design](https://github.com/RealityHertz/Greenhouse-Project/blob/main/Documentation/Images/CADPLCSubsystemSchematic.jpg)

*Figure 1. PLC Subsystem Design*

![PLC Subsystem](https://github.com/RealityHertz/Greenhouse-Project/blob/main/Documentation/Images/PLC%202D%20Model.png)

*Figure 2. PLC 2D Model*

![PLC Power Supply](https://github.com/RealityHertz/Greenhouse-Project/blob/main/Documentation/Images/PLCPowerSupply2DCAD.PNG)

*Figure 3. PLC Power Supply 2D Model*

## **Analysis:**

**PLC**
  1. The Automation Direct C2-03CPU has a scan time of < 1 ms and a contact execution of < 0.2 µs. This is more than sufficient to keep track of the sensor's data being sent every 5 minutes.
  2. The Automation Direct C2-03CPU is able to communicate through USB to USB to allow for programs to be installed. [2]
  3. The ambient humidity specifications in the PLC Datasheet show that when operating and non-condensing the relative humidity the PLC can handle is 30% to 95%. [2] This falls within our range for the greenhouse, with 80% being optimal for plant growth. [3] The PLC will also be able to monitor the humidity through communication with the Temperature/Humidity Subsystem's sensor to alert if the humidity is falling or rising to an unsafe range.
  4. In this communication setup, data collected by multiple Arduino Nano 33 IoT equipped with BLE capabilities is wirelessly transmitted to another Arduino Nano 33 IoT functioning as a gateway device. The sensor Arduinos gather data and transmit it to the gateway Arduino via Bluetooth Low Energy (BLE). Upon receiving the data, the gateway Arduino processes and formats it to align with the requirements for RS232 communication. Through a wired connection established by an RS232 cable, the gateway Arduino interfaces with the Programmable Logic Controller (PLC). It then relays the formatted data from the sensor Arduinos to the PLC via RS232, facilitating data transfer for real-time monitoring and control in the greenhouse environment. Here is example code of what it might look like to recieve/send data using this system.
```
#include <SoftwareSerial.h>
#include <ArduinoBLE.h>
#include <Ethernet.h>

#define RX_PIN 17 // RX pin of Arduino Nano 33 IoT
#define TX_PIN 16 // TX pin of Arduino Nano 33 IoT

SoftwareSerial RS232(RX_PIN, TX_PIN);

BLEService dataService("12345678-1234-5678-1234-56789abcdef0");
BLECharacteristic dataCharacteristic("0000abcd-0000-1000-8000-00805f9b34fb", BLERead | BLENotify, 20);

void setup() {
  Serial.begin(9600);
  RS232.begin(9600);
  while (!Serial);
  if (!BLE.begin()) {
    Serial.println("starting BLE failed!");
    while (1);
  }
  BLE.setLocalName("Nano33IoT");
  BLE.setAdvertisedService(dataService);
  dataService.addCharacteristic(dataCharacteristic);
  BLE.addService(dataService);
  dataCharacteristic.writeValue(0);
  BLE.advertise();
  Serial.println("BLE server is now running, waiting for connections...");
}

float parseData(String data) {
  int commaIndex = data.indexOf(',');
  if (commaIndex == -1) {
    return 0.0;
  }
  // Get the first part of the split
  String floatValue = data.substring(0, commaIndex); 
  // Convert the float value to a float and return it
  return floatValue.toFloat();
}

void sendDataToPLC(float data1, float data2, float data3, float data4) {
  String dataToSend = String(data1) + "," + String(data2) + "," + String(data3) + "," + String(data4);
  RS232.println(dataToSend);
}

float getDataFromArduino1() {
  String data = readSensorDataFromBLE();
  // Parse the data and return the value
  return parseData(data);
}

float getDataFromArduino2() {
  String data = readSensorDataFromBLE();
  // Parse the data and return the value
  return parseData(data);
}

float getDataFromArduino3() {
  String data = readSensorDataFromBLE();
  // Parse the data and return the value
  return parseData(data);
}

float getDataFromArduino4() {
  String data = readSensorDataFromBLE();
  // Parse the data and return the value
  return parseData(data);
}

void loop() {
  float data1 = getDataFromArduino1();
  float data2 = getDataFromArduino2();
  float data3 = getDataFromArduino3();
  float data4 = getDataFromArduino4();

  sendDataToPLC(data1, data2, data3, data4);
  
  delay(1000);
}
```
  5. The utilization of CLICK programming features with the PLC offers a solution for data logging requirements. By leveraging trigger bits in the ladder logic, CSV files containing data can be systematically generated and stored onto a micro SD card connected to the PLC. With a maximum file limit of 999 files and a data save interval set at every hour, calculations reveal that this setup enables the logging of data for an approximate duration of 41.625 days before reaching file capacity. This approach underscores the efficiency and reliability of the PLC subsystem, ensuring seamless data acquisition and storage over extended periods exceeding our 1 month minimum timeline. [4]
  6. In the system design the C0-01AC model power supply integrates essential protection features to ensure the safety of connected equipment. The power supply includes overcurrent protection with automatic recovery, activated at a threshold of 0.65 A, safeguarding against excessive current draw. Additionally, the system has overvoltage protection, by a Zener diode, which clamps voltage spikes at 27.6 V. These protective measures are fundamental in decreasing risks from electrical faults and keeping an uninterrupted operation from the power distribution system.
     
**Power Supply for PLC**
- The CLICK C0-01 AC will be the source used to power the PLC system, which has the ability to supply between 100-240 VAC. This supply gives a 1.3A and 25V DC source which is more than capable of supporting the PLC even with all I/O ports being used. The maximum start-up time is 1000ms, which allows plenty of time for the PLC to receive and send data to and from the other sub-systems. The humidity range allows up to 95% humidity which is ideal for the supply being used inside of a greenhouse. 
 
**HMI to PLC**
- We will use the PLC and code in "Ladder" to allow the ports to be read and sent to the HMI. The HMI then has the C-more Micro Programming Software that can be used to design and simulate the code to be used on the HMI to correctly display and customize the buttons. Here is the template to allow for communication between PLC and HMI.

![PLC Port Code](https://github.com/RealityHertz/Greenhouse-Project/blob/main/Documentation/Images/LadderLogicForPLC.PNG)

**Placement and Enclosure**
- Placement of the enclosure will be in the south eastern part of the building next to the greenhouse entrance and power outlet. The PLC will be enclosed in a 6.30 x 6.30 x 3.52 in weatherproof box and cable glands to allow for connection. The power supply will be enclosed in another 6.30 x 6.30 x 3.52 in enclosure with connections to the PLC and the power outlet.The cases will have 2 cable glands each to allow cables to input and output from each system.



## **Bill of Materials**
|Brand/Manufacturer|Part Name|Supplier|Part/Model Number|Quantity|Individual Price|Total|
|----|-----------|-----------|------------|--------|----------------|-----|
|CLICK PLUS|PLC|Automation Direct|C2-03CPU|1|$205.00|$205.00|
|CLICK|Power Supply|Automation Direct|C0-01AC|1|$63.00|$63.00|
|SanDisk|MicroSD|Amazon|SanDisk Ultra microSDHC 32GB|1|$7.65|$7.65|
|Polycase|Outdoor Enclosure|Ploycase|SK-18 Enclosure with Knockouts 7.09 x 5.12 x 3.31 in|2|$41.17|$82.34|
|Polycase|Cable Glands|Ploycase|CG3 Gray Cable Glands 1.53 x 1.19 x 1.19in|4|$2.86|$11.44|
|Polycase|Mounting Kit|Ploycase|SK-99 Mounting Kit for SK Series Enclosures 0.91 x 0.59 x 0.86 in|2|$3.36|$6.72|
|MAX3232|TTL to RS232 Module|Amazon|B07PFB4MHR|1|$15.99|$15.99|
|DTech|RS232 Cable|Amazon|DT-9006C 2M|1|$10.96|$10.96|

**References**

[1] AutomationDirect, "Click PLCs - CLICK PLUS Features," AutomationDirect, https://www.automationdirect.com/clickplcs/clickplus/features.

[2] AutomationDirect, "C20xCPU - CPU Module for C2000 Series PLCs," AutomationDirect, https://cdn.automationdirect.com/static/specs/c20xcpu.pdf.

[3] Atlas Scientific, "Ideal Greenhouse Temperature and Humidity," Atlas Scientific Blog, https://atlas-scientific.com/blog/ideal-greenhouse-temperature-and-humidity/#:~:text=Ideal%20Humidity%20For%20Greenhouses&text=The%20optimal%20relative%20humidity%20level,growth%20and%20lower%20quality%20yield.

[4] AutomationDirect, "CLICK PLC Data Logging | Do-more Designer 2.0.2 Logger", AutomationDirect, https://www.automationdirect.com/videos/video?videoToPlay=rkgwh-HfNKo
