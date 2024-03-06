# **Detail Design: Water Sensor**

## **Function of the Subsystem:**

The function of this subsystem is to relay the water levels to the Arduino via their respective sensors. The subsystem will use a sensor to determine whether the water reservoir is empty or not. If the reservoir is low on water, it will send data to the PLC for it to be refilled. The system is also able to be turned off for the user to manually water the plants.

## **Constraints:**

- **Arduino Nano 33 IoT**
  - The communication between the sensors and PLC system must be wireless. This will save time and money on wiring, while also allowing the system to be scalable.
  - The transfer of data between the sensors and the Arduino must be below 3 seconds for accurate and reliable monitoring of water level.
  - BLE (Bluetooth Low Energy) is lower in cost than the classic Bluetooth as BLE is currently rising in use and has market competition. BLE decreases the distance a signal can be transmitted, but the signals transmitted through the greenhouse will not be far. The use of BLE allows for a cost-efficient alternative compared to classic Bluetooth.

- **Water Level Sensor**
  - The transfer of data between the sensors and the Arduino must be below 3 seconds for accurate and reliable monitoring of water level.
  - Must be able to accurately sense when water level drops below 1/3 of the max to signal more water is needed to be added to the reservoir.
  - Must be durable enough to continue function while wet for an indefinite amount of time.
  - Must be cheap and easily replacable in the chance the user requires a new sensor.

## **Buildable Schematic:**

![Buildable Schematic Water Level](https://github.com/RealityHertz/Greenhouse-Project/blob/main/Documentation/Images/WaterLevelSchem.png)

_Figure 1. Wiring Schematic for Power to Sensor_ 
![Arduino Nano 33](https://github.com/RealityHertz/Greenhouse-Project/blob/main/Documentation/Images/ArduinoNano33.png)

_Figure 2. Arduino Nano 33 IoT Board Topology_

## **Analysis:**

- **Arduino Nano 33 IoT**
  1. The Arduino's BLE capabilities could be broadened by using an array of bluetooth extenders if required for larger projects.
  2. The Ardiuno will need to be cycled in and out of sleep mode to conserve battery life. This will be done by using the Arduino-Libraries Github and use the provided files and functions in the ArduinoLowPower folder. For example, we can use the function LowPower.sleep() and input the amount of time we want it to sleep in ms. Implementing this in a loop will then allow the microcontroller to continuously fall asleep and wake up for the desired time. We have decided to do a system where the Ardiuno runs for 10 seconds for every 5 minutes. Sleep mode will lower current to virtually nothing. [1] [2]
  3. BLE (Bluetooth Low Energy) is lower in cost than the classic Bluetooth as BLE is currently rising in use and has market competition. BLE decreases the distance a signal can be transmitted, but the signals transmitted through the greenhouse will not be far apart. The use of BLE allows for a cost-eﬃcient alternative compared to standard Bluetooth.

  - **Power Supply for Arduino Nano 33 IoT**
    - The power used will need to supply 5 volts to the Pin 15 on the Nano 33 IoT.
    - The Pin 14 on the Nano 33 IoT will need to be connected to the ground from the power supply.
    - The JSN-SR04T dras 5mA at 5V.
    - The JSN-SR04T would use (30mA x 5V) x (10s / 3600s) = 0.4167mWh leading to an average power of 0.4167mWh / (5min/60min) = 5mW.
    - The Arduino will be powered by 4 AA batteries which supplies 3500mAh and 1.5V each
    - The total mWh supplied is equal to (1.5V x 4) x 3500 = 21,000mWh
    - Therefore, the energy used during the "while on" mode is (28mA x 5V) x (10s / 3600s) = .07778mWh
    - The average power is .07778 / (5min / 60min) = 0.933mW
    - The total power used by everything is .933mW + 5mW = 5.933mW.
    - This means the batteries will last (21,000mWh / 5.933mW) = 3540 hours or almost 5 months.
- **JSN-SR04T**
  1. In order for the sensor to work, the JSN-SR04T must be on for at least 10 ms, which is 1/100 of the time its planned to be briefly turn on.
  2. The sesnor has a range of 20cm - 4m
  3. The sensor will use ultra sonic waves to determine height from the top of the resevoir by reading how long it takes for an ultra sonic wave to return. (The height of the resevoir) - (measured distance) = water level.
    - distance = (high level time) x (speed of sound in medium) x 0.5.
        - The speed of sound 340 m/s.
        - Therefore, the distance calculated by code will end up being (the high level time) * 170 m/s, giving the result in meters. 
        - This being said, the data will be read in under the 3 second prerequisite, due to the speed at which the echo will be recieved.
        - The units of measurement may also be changed in code in order for an easier to read result such as cm or inches, given the unit for speed of sound in the medium is converted.
  4. The sensor is only 12.99 and waterproof making it a good fit for a durable and cheap option in the case of wear and tear or mishaps.
 
  - **Power Supply for JSN-SR04T**
    - The JSN-SR04T will connect to the Nano 33 IoT's Pin 12 supplying 5 volts to the sensor, the Nano 33 IoT's pin 19 for ground, and the Nano 33 IoT's pins 23 and 24 for sending data via pulse width modulation (PWM).
    - The working voltage will be 5V
- **Water Levels**
  - The sensor will float on the water and send a signal to the Arduino 33 IoT saying whether the water level is below 1/3 of the max or not.
  - When the JSN-SR04T reads a distance that is equal to or less than the target height of 1/3 max, this will flag the PLC system.

- **Placement and Enclosure**
  - The enclosure will be set up next to the resevoir using a cable gland to transport the wire out. Inside the enclosure will be the battery pack and the breadbaord. The wire for the senor will then run out and over the resevoir. Two wooden dowels will be ziptied toegther with the sensor in between to hold the sesor over the center of the resevoir. 



## **Bill of Materials:**

|Brand/Manufacturer|Part Name|Supplier|Part/Model Number|Quantity|Individual Price|Total|
|----|-----------|-----------|------------|--------|----------------|-----|
|Arduino|Bluetooth Board|Arduino|Nano 33 IoT|1|$25.50|$25.50|
|LAMPVPATH|4 AA Battery Holder|Amazon|B07L9M6VZK|1|$7.49|$7.49|
|Duracell|AA Batteries|Amazon|DURMN1500B10Z|1|$8.79|$8.79|
|DIYmore|Water Level Sensor|DIYmore|JSN-SR04T|1|$12.99|$12.99|
|Polycase|Enclosure|Polycase|SK-18 Enclosure with Knockouts 5.12 x 3.70 x 2.24 in|1|$20.92|$20.92|
|Polycase|Cable Gland|Ploycase|CG3 Gray Cable Glands 1.53 x 1.19 x 1.19in|1|$2.86|$2.86|
|Polycase|Mounting Kit|Ploycase|SK-99 Mounting Kit for SK Series Enclosures 0.91 x 0.59 x 0.86 in|1|$3.36|$3.36|
|Qunqi|Breadboard|Amazon|Qunqi 400 tie Point Experiment Mini Breadboard 5.5×8.2×0.85cm|1|$5.99|$5.99|
|Madison Mill|Dowel|Lowes|Madison Mill 0.75-in dia x 36-in L Square Poplar Dowel|2|$3.98|$7.96|
|Tin-N-Lock|Ziptiews|Amazon|Tie-N-Lock 8" Heavy Duty Nylon Cable Ties, 50 lb Test, 100 PC, Black|1|$1.21|$1.21|

**References**

[1] “Arduino Low Power - Arduino Reference,” www.arduino.cc, Nov. 08, 2023).
‌<https://www.arduino.cc/reference/en/libraries/arduino-low-power/>

[2] O. Staquet, "Arduino-Nano-33-IoT-Ultimate-Guide," github.com [Online]. Available: https://github.com/ostaquet/Arduino-Nano-33-IoT-Ultimate-Guide/blob/master/SavePowerSleeping.md. [Accessed Feb. 14, 2024].
