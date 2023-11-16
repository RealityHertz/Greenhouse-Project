# *Detail Design: Communications Application*

## **Function of the Subsystem:**

<div style="margin-left: 20px">The Communcations Application Subsystem 
will be designed to collect, organize, and process data that is recieved by the PLC which includes nutrient levels, humidity, temperature, CO2, and NO2 levels from sensors. All of these sensors will send the data to Arduino Nano 33 BLE chips to the PLC using Bluetooth LowEnergy. The purpose of the Communications subsystem to the make sure it can take in the undisturbed sensor data and reorganize it into the way that will be easy for a user to read and understand. The subsystem acts as bridge between the raw data and the visualization interface. It will be used to see real-time data and allow for proper decision-making. Essentially the data from the PLC will be taken and put on the NHD-5.0-800480FT-CSXP-CTP screen and shown in readings and graphs to allow for the data to be easy to understand.

## **Constraints:**

- **Arduino Nano 33 BLE**

  - **Arduino Nano 33 IoT**
  1. The communication between the Arduino and PLC must be wireless. This will save time and money on wiring, while also allowing the system to be scalable, meaning if the greenhouse was to be expanded then this subsystem would be easily expanded to account for more plants.

  2. The transfer of data between the PLC and the Arduino must be below 3 seconds for accurate and reliable monitoring of all sensor levels in the atmosphere and to allow plenty of time for grabbing information wirelessly from the PLC.

- **NHD-5.0-800480FT-CSXP-CTP**

  1. The NHD-5.0-800480FT-CSXP-CTP needs a voltage of 3.3-5V supplied in order to 
  operate and typically uses 100mA of current.

  2. Voltage supplied for LED Blacklight Driver shall be a minimum of 2.8V and a 
  maximum of 5.5V. Supply Current for LED Blacklight Driver for 3.3V is typically 770mA and for 5V is 350mA. The power system shall uphold this.

## **Buildable Schematic:**

![Buildable Schematic Communication & Display](https://github.com/RealityHertz/Greenhouse-Project/blob/main/Documentation/Images/CADCommunicationsSubsystem.jpg)

*Figure 1. Wiring Schematic for Communication and Display*

![Arduino Nano 33](https://github.com/RealityHertz/Greenhouse-Project/blob/main/Documentation/Images/ArduinoNano33.png)

*Figure 2. Arduino Nano 33 BLE Board Topology*

![NHD-5.0-800480FT-CSXP-CTP](https://github.com/RealityHertz/Greenhouse-Project/blob/main/Documentation/Images/Display%20Chip%20Schematic%20.png)

*Figure 3. NHD-5.0-800480FT-CSXP-CTP Board Topology*

## **Analysis:**

**Arduino Nano 33 IoT**
  1. The Arduino's BLE capabilities could be broadened by using an array of bluetooth extenders if required for larger projects. 

  2. The data that is needed to be able to turn this system into a useful tool will be recieved via BLE from the PLC. The PLC used in this system has BLE compatabilities so it will be easy to send over the required data that can then be turned into readable and useful data that the greenhouse employees will be able to use. The MISO pin will be the output of this data that will be sent onto the display.
  - **Power Supply for Arduino Nano 33 IoT**
    - The power will be USB from 110 volt wall outlet and will to supply 5 volts to the Pin 15 on the Nano 33 IoT. The Pin 14 on the Nano 33 IoT will need to be connected to the ground from the USB ground wire.

    - The USB cable and plug used have a max current of 1 amp and 2 amp respectively. This will allow for a safe current supply to the board.

**NHD-5.0-800480FT-CSXP-CTP**

  1. The NHD-5.0-800480FT-CSXP-CTP has a supply voltage of 3.0-3.6V and
  will have power supplied through a wall outlet with a USB 2.0 cord 
  powering the voltage in and ground
  
  2. The NHD-5.0-800480FT-CSXP-CTP will also be supplied the proper Idd from a Vdd of 3.3V or within the previous voltage parameters. The current should fall around 100mA. [1]

- **Communication for NHD-5.0-800480FT-CSXP-CTP**

  - The primary communication will come from the Arduino Nano 33 BLE 
  MISO pin connected the the MOSI pin on the NHD-5.0-800480FT-CSXP-CTP.
  - The communnication will be controlled by using the SCK digital pin 
  on the Arduino Nano 33 BLE which can be set up by putting code to 
  mimic a desired clock cycle. We will then take this digital signal 
  and send it through the SCK pin on the Arduino to the SCK recieving 
  pin on the NHD-5.0-800480FT-CSXP-CTP.
  - The Chip Select on the NHD-5.0-800480FT-CSXP-CTP will also be set 
  up to a digital pin on the Arduino so that can be configured as 
  desired.
  - Most of the communcation will be written as code on the Arduino which will recieve data from the PLC controller. It can then be reorganized into graphs and readable data on the display to make for ease of understanding for the greenhouse employees. [2]

## **Bill of Materials**
|Brand/Manufacturer|Part Name|Supplier|Part/Model Number|Quantity|Individual Price|Total|
|----|-----------|-----------|------------|--------|----------------|-----|
|Arduino|Bluetooth Board|Arduino|Nano 33 BLE|1|$26.30|$26.30|
|Newhaven Display Intl|LCD Display Module|DigiKey|NHD-5.0-800480FT-CSXP-CTP|1|$141.63|$141.63|
|CUI Devices|USB Cable|DigiKey|CBL-UA-ST-1|2|$3.12|6.24|
|GlobTek, Inc.|USB Plug|DigiKey|WR9RA2000USBMF(R6B)|1|$9.89|$9.89|




**References**

[1] "Title of the PDF Document," Abbrev. Month, year. [Online]. Available: 
<https://newhavendisplay.com/content/specs/NHD-5.0-800480FT-CSXP-CTP.pdf>

[2] M. Margolis and M. Fisher, "Chapter 4: Sensing the World," O'Reilly Media, 2011. [Online]. Available: 
<https://www.oreilly.com/library/view/arduino-cookbook/9781449399368/ch04.html> 
Accessed on: October 31, 2023.
