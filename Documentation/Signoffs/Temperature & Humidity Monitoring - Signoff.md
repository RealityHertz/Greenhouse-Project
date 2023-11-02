# *Detail Design: Temperature and Humidity Control*
## **Team 2 - Greenhouse Project**
### *Team Members: Jared Hooker and Noah Jones*

## **Function of the Subsystem:**
The function of this subsystem is to measure the temperature and the humidity levels in the greenhouse. The DHT11 sensor will measure both values, then relay the information to the Arduino Nano 33 BLE device. 

## **Constraints:**
- Bluetooth Low Energy (BLE) must be used to reduce power consumption.
- Arduino must turn on every 5 minutes to measure and update the temperature and humidity.

## **Buildable Schematic:**
![Buildable Schematic Temperature & Humidity Monitoring](https://github.com/RealityHertz/Greenhouse-Project/blob/main/Documentation/Images/Temp%26HumiditySchematic.png)
## **Analysis:**
- **Power Supply and Connection for Arduino Nano 33 BLE**
    - The power supply will be four AA batteries. Each battery contains 1.1-1.5 volts, which will give the Arduino the required 5 volts.
    - The 5V supply will be connected to pin 14 on the Arduino. The ground will be connected to the pin 19 on the Arduino.
    - The power supply will be connected to the LM7805 voltage regulator, which will be used to step down the voltage to 3.3 V for the 555 timer.
- **Power Supply and Connection for DHT11**
    - The DHT11 temperature and humidity sensor is powered by the Arduino. An output voltage of 5 V is sent to the DHT11 via the Arduino.
    - The data produced by the DHT11 is sent to the D8 pin of the Arduino.
- **555 Timer**
    - For the 555 timer to turn on every 5 minutes, certain resistor and capacitor values must be chosen to obtain the correct time. To determine the period of the timer, the equation t = 0.7(R1 + 2R2) x C is used [1]. Using resistor values of 330kΩ and 47kΩ with a 1mF capacitor results in a period of 296.8 seconds, which is sufficient to the desired period of 300 seconds (5 minutes).

## **Bill of Materials:**
|Brand/Manufacturer|Part Name|Supplier|Part/Model Number|Quantity|Individual Price|Total|
|----|-----------|-----------|------------|--------|----------------|-----|
|Songhe|Temperature and Humidity Sensor|Amazon|DHT11|5 (Pack)|$1.58|$7.88|
|Arduino|Bluetooth Board|Arduino|Nano 33 BLE|1|$26.30|$26.30|
|onsemi 555 Chip|DigiKey|NCV1455BDR2G|1|$0.62|$0.62|
|Texas Instruments|Voltage Regulator|DigiKey|296-47192-ND|1|$1.41|$1.41|
|LAMPVPATH|4 AA Battery Holder|Amazon|B07L9M6VZK|1|$7.49|$7.49|
|Duracell|AA Batteries|Amazon|DURMN1500B10Z|1|$8.79|$8.79|


## **References:**
[1] G. Lambert, "Introduction to the 555 Timer," Circuit Basics, Nov. 28, 2021. https://www.circuitbasics.com/what-is-a-555-timer/
