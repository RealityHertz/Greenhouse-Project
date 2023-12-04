# **Detail Design: Water Sensor**

## **Function of the Subsystem:**

The function of this subsystem is to relay the water levels to the Arduino via their respective sensors. The subsystem will use a sensor to determine whether the water reservoir is empty or not. If the reservoir is low on water, it will send data to the PLC for it to be refilled. The system is also able to be turned off for the user to manually water the plants.

## **Constraints:**

- **Arduino Nano 33 IoT**
  - The communication between the sensors and PLC must be wireless. This will save time and money on wiring, while also allowing the system to be scalable.
  - The transfer of data between the sensors and the Arduino must be nearly instantaneous for accurate and reliable monitoring of water level.
  - BLE (Bluetooth Low Energy) is lower in cost than the classic Bluetooth as BLE is currently rising in use and has market competition. BLE decreases the distance a signal can be transmitted, but the signals transmitted through the greenhouse will not be far. The use of BLE allows for a cost-efficient alternative compared to classic Bluetooth.
- **Silicon Conformal Coating**

  - Service temperature range of -40-200℃
  - Resistivity of 3.5 x 10^13 Ω·cm
  - Drying time of 15 minutes for 2 coats

## **Buildable Schematic:**

![Buildable Schematic Water Level](https://github.com/RealityHertz/Greenhouse-Project/blob/main/Documentation/Images/WaterLevelSchem.png)

_Figure 1. Wiring Schematic for Power to Sensor_ 
![Arduino Nano 33](https://github.com/RealityHertz/Greenhouse-Project/blob/main/Documentation/Images/ArduinoNano33.png)

_Figure 2. Arduino Nano 33 IoT Board Topology_

## **Analysis:**

- **Arduino Nano 33 IoT**
  1. The Arduino's BLE capabilities could be broadened by using an array of bluetooth extenders if required for larger projects.
  2. The Ardiuno will need to be cycled in and out of sleep mode to conserve battery life. This will be done by using the Arduino-Libraries Github and use the provided files and functions in the ArduinoLowPower folder. For example, we can use the function LowPower.sleep() and input the amount of time we want it to sleep in ms. Implementing this in a loop will then allow the microcontroller to continuously fall asleep and wake up for the desired time. We have decided to do a system where the Ardiuno runs for 10 seconds for every 5 minutes. [1]
  3. BLE (Bluetooth Low Energy) is lower in cost than the classic Bluetooth as BLE is currently rising in use and has market competition. BLE decreases the distance a signal can be transmitted, but the signals transmitted through the greenhouse will not be far apart. The use of BLE allows for a cost-eﬃcient alternative compared to standard Bluetooth.

  - **Power Supply for Arduino Nano 33 IoT**
    - The power used will need to supply 5 volts to the Pin 15 on the Nano 33 IoT.
    - The Pin 14 on the Nano 33 IoT will need to be connected to the ground from the power supply.
    - The Arduino will be powered by 4 AA batteries which supplies 3500mAh and 1.5V each
    - The total mWh supplied is equal to (1.5V x 4) x 3500 = 21,000mWh
    - Therefore, the energy used during the "while on" mode is (28mA x 5V) x (10s / 3600s) = .07778mWh
    - The average power is .07778 / (5min / 60min) = 0.933mW
    - The total power used by both sensors and the Arduino is .933mW + .33mW + .0828mW = 1.346mW
    - This means the batteries will last (21,000mWh / 1.346mW) = 15,601 hours or 21.7 months
- **Power Supply for M8**
  - The M8 will connect to the Nano 33 IoT's Pin 12 supplying 5 volts to the sensor, and the Nano 33 IoT's pin 19 for ground to complete the circuit.
  - The working voltage will be 4.5 ~ 5.5 V DC
  - Average Current \< 20 mA with a 5 V power supply
  - Peak Current 150 mA with a 5 V power supply
- **Communication for M8**
  - PWM Output consists of the following:
    - Cycle of 1004 ms ±5%
    - Cycle starts high level output of 2 ms, theoretically.
    - Middle Cycle of 1000 ms ±5%
    - Cycle end high level output of 2ms, theoretically.

![PWM Graph](https://github.com/RealityHertz/Greenhouse-Project/blob/main/Documentation/Images/PPM.png)

- **Water Levels**
  - The float sensor will float on the water and send a signal to the Arduino 33 IoT saying whether the water level is low or not.

## **Bill of Materials:**

|Brand/Manufacturer|Part Name|Supplier|Part/Model Number|Quantity|Individual Price|Total|
|----|-----------|-----------|------------|--------|----------------|-----|
|Arduino|Bluetooth Board|Arduino|Nano 33 IoT|1|$25.50|$25.50|
|MG Chemicals|Silicon Conformal Coating|DigiKey|422C-55MLCA|1|$23.94|$23.94|
|LAMPVPATH|4 AA Battery Holder|Amazon|B07L9M6VZK|1|$7.49|$7.49|
|Duracell|AA Batteries|Amazon|DURMN1500B10Z|1|$8.79|$8.79|
|Gikfun|Water Level Sensor|Amazon|M8|1|$9.88|$9.88|


**References**

[1] “Arduino Low Power - Arduino Reference,” www.arduino.cc, Nov. 08, 2023).
‌<https://www.arduino.cc/reference/en/libraries/arduino-low-power/>
