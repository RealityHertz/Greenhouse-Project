# Software Folder

This folder contains all of the software used in the Autonomous Greenhouse project. These files are required components representing background programming used in the subsystems within the greenhouse environment.

## Contents

- ArduinoIDE Folder
  -  Arduino_AHTXO
      -  File for DHT and AHT collection of data and BLE transmisson
  -  Arduino_CO2
      - File for MH-Z19B data collection and BLE transmisson
  -   Arduino_DHT
      - File for DHT20 data collection and BLE transmisson    
  -   Arduino_Lighting
      - Simple Digital Pin set high, delay, set low code to power the lighting   
  -   Arduino_NO2_w_ADC
      - File for MIKROE-3700 data collection and BLE transmisson   
  -   Arduino_NPK
      - File for NPK Sensor data collection and BLE transmisson
  -   Arduino_NPK_NoBLE
      - File for MH-Z19B data collection without BLE transmisson
  -   Arduino_NPK_NoBLE_From_Web
      - Test file for MH-Z19B data collection
  -   Arduino_RS232
      - File for transmisson through RS232 after data collection
  -   Arduino_Water_Level
      - File for distance sensor data collection and BLE transmisson and sends a true or false depending on how high or low the distance is
  -   Arduink_waterLevel
      - File for water level sensor data collection and BLE transmisson
  -   BLE_Scan_Test
      - File for the central Arduino that then sends the collected BLE data through RS232 to the PLC  
  -   NO2_SPI_Sensor
      -   File for MIKROE-3700 data collection and BLE transmisson through SPI.

## Usage

These software files represent the background programming that the subsystems need to function. This includes, but is not limited to, Arduino sleep pattern coding, sensor reading conversions, and sleep pattern timing. Refer to individual software directories for more information of each software's individual purpose and usage.

## File Formats

The software is provided in commonly used file formats compatible with the chosen arduino and sensors. Formats include `.c`, `.h`, and `.ino`.
