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

![Buildable Schematic Water Level](https://github.com/RealityHertz/Greenhouse-Project/blob/main/Documentation/Images/Water_Level_Schematic.png)

_Figure 1. Wiring Schematic for Power to Sensor_ 
![Arduino Nano 33](https://github.com/RealityHertz/Greenhouse-Project/blob/main/Documentation/Images/ArduinoNano33.png)

_Figure 2. Arduino Nano 33 IoT Board Topology_

![3D Artifact](https://github.com/RealityHertz/Greenhouse-Project/blob/6118d1c71d864b9eebc8de3b106a7ff571bb5395/Documentation/Images/3D-artifact-CAPSTONE.png).

_Figure 3. Set up for Subsystem_

![Mounting Model](https://github.com/RealityHertz/Greenhouse-Project/blob/6118d1c71d864b9eebc8de3b106a7ff571bb5395/Documentation/Images/Mounting-Model.png)

_Figure 4. 3D model  of desinged mount._

_For the model:  https://www.tinkercad.com/things/jwpPelM5zqh/edit?sharecode=Q2aPLBubOT7n5q68HoEgVgSHFNOAS2fjU0qmp6W8gsg_

![3D Artifact Top Down](https://github.com/RealityHertz/Greenhouse-Project/blob/6118d1c71d864b9eebc8de3b106a7ff571bb5395/Documentation/Images/3D-artifact-topdown-CAPSTONE.png).

_Figure 5. Top down view of subsystem set up_

![Holding Sensor](https://github.com/RealityHertz/Greenhouse-Project/blob/515b6fbf5c76c52fc5e037464497fa9066775a7c/Documentation/Images/3D-artifact-sensor-CAPSTONE.png).

_Figure 6. Side view of the two dowels ziptied together holding up the sensor_

## **Analysis:**

- **Arduino Nano 33 IoT**
  1. The Arduino's BLE capabilities could be broadened by using an array of bluetooth extenders if required for larger projects.
  2. The Ardiuno will need to be cycled in and out of sleep mode to conserve battery life. This will be done by using the Arduino-Libraries Github and use the provided files and functions in the ArduinoLowPower folder. For example, we can use the function LowPower.sleep() and input the amount of time we want it to sleep in ms. Implementing this in a loop will then allow the microcontroller to continuously fall asleep and wake up for the desired time. We have decided to do a system where the Ardiuno runs for 10 seconds for every 5 minutes. [1] [2]
  3. BLE (Bluetooth Low Energy) is lower in cost than the classic Bluetooth as BLE is currently rising in use and has market competition. BLE decreases the distance a signal can be transmitted, but the signals transmitted through the greenhouse will not be far apart. The use of BLE allows for a cost-eﬃcient alternative compared to standard Bluetooth.

  - **Power Supply for Arduino Nano 33 IoT**
    - The power used will need to supply 5 volts to the Pin 15 on the Nano 33 IoT.
    - The Pin 14 on the Nano 33 IoT will need to be connected to the ground from the power supply.
    - The Arduino uses 28mA in on mode and 6mA in sleep mode.
    - The JSN-SR04T draws 30mA at 5V while on and 5 mA in a dormancy state.
    - The converter has a current draw of 0.09mA.
    - The batteries would have a realistic voltage drop off point of 2200mAh according to the graph below.
    - The system is on for 10 seconds every 5 minutes leading to a duty cycle of (10s / (5min * 60s)) = 0.0333
    - In "on" mode the system uses a total of 28mA + 30mA + 0.09mA = 58.09mA when the duty cycle is applied this leads to an average current draw of 58.09mA * 0.0333 = 1.936mA.
    - In "sleep" mode the system uses a total of 6mA + 5mA + 0.09mA = 11.09mA when the duty cycle is applied this leads to an average current draw of 11.09 * 0.9667 = 10.72mA.
    - There would be a total average current draw of 10.72mA + 1.936mA = 12.657mA leading to a battery life of 2200mAh / 12.657mA = 173.821 hours.
    - Since we have an expected battery usage of 86.7% we will realistically see a battery life of (173.821 * 0.867) = 150.65 hours or 6.28 days.
   
- **DC to DC Converter - Nisshinbo R1210N601D-TR-FE**
  
   1. The converter takes an input voltage range of 0.8-8V and produces a constant output of 6V ±0.15V.
   2. This is within the range of input voltage for the Arduino Nano 33 IoT and reduces the risk of having too little voltage for the Arduino as the battery charges dissipate.
   3. Since the minimum input voltage of the converter is 0.8V this means that the system will be able to operate until the power supply voltage drops below 0.2V per battery which means that roughly ((1.5V-0.2V)/1.5V) = 0.867 or 86.7% of the individual battery's supply is used before needing to be replaced.

- **JSN-SR04T**
  1. In order for the sensor to work, the JSN-SR04T must be on for at least 10 ms, which is 1/100 of the time its planned to be briefly turn on.
  2. The sensor has a range of 25cm - 4m.
  3. The sensor will use a 40kHz ultra sonic waves to determine height from the top of the resevoir by reading how long it takes for an ultra sonic wave to return. (The height of the reservoir) - (measured distance) = water level.
    - When the wave is returned, a pulse will be sent to the arduino whos length is proportional to the distance. The pulseIn() function from the Ardunio library will read this pulse and do the distance calculations.
        - The pulseIn() function looks like so: pulseIn(X, Y) where X is the observed variable and Y is either HIGH or LOW. When the function is called it looks at variable X and waits for it to toggle to Y (in this case, we will use HIGH so it will look for a toggle from LOW to HIGH). When this happens, a timer is started in milliseconds. The timer stops when the variable is toggled again. The function then outputs the time in milliseconds the variable was toggled for. 
    - Distance = (high level time) x (speed of sound in medium) x 0.5.
        - The speed of sound 340 m/s.
        - Therefore, the distance calculated by code will end up being (the high level time) * 170 m/s, giving the result in meters.
        - The pulseIn function used to read the duration of the sound wave requires the pulse to be 10 microseconds - 3 minutes. It takes sound well over 10 microseconds to travel 25 cm and its fast enough to travel and return 4 m in under 3 minutes.
        - This being said, the data will be read in under the 3 second prerequisite, due to the speed at which the echo will be received.
        - The units of measurement may also be changed between centimeters and inches in order for an easy to read result. It will be changed in code, given the unit for speed of sound in the medium is converted.
  4. The sensor is only $12.99 and waterproof making it a good fit for a durable and cheap option in the case of wear, tear, or mishaps.
 
  - **Power Supply for JSN-SR04T**
    - The JSN-SR04T will connect to the Nano 33 IoT's Pin 12 supplying 5 volts to the sensor, the Nano 33 IoT's pin 19 for ground, and the Nano 33 IoT's pins 23 and 24 for sending data.
    - The working voltage will be 5V
- **Water Levels**
  - The sensor will float on the water and send a signal to the Arduino 33 IoT saying whether the water level is below 1/3 of the max or not.
  - When the JSN-SR04T reads a distance that is equal to or less than the target height of 1/3 max, this will flag the PLC system.

- **Placement and Enclosure**
  - The enclosure will be set up using a desgined mount on the side of the resevoir using a cable gland to transport the wire out. Inside the enclosure will be the battery pack and the breadbaord. The wire for the sensor will then run out and over the reservoir. Two wooden dowels will be ziptied toegther with the sensor in between to hold the sensor over the center of the reservoir. 

![Battery Dropoff](https://github.com/RealityHertz/Greenhouse-Project/blob/main/Documentation/Images/AA-100mA.png)

_Figure 7. Duracell(DC) vs. Radio Shack(RS) AA battery voltage dropoff at 100mA current draw_
_Source: Adapted from [3]_

## **Bill of Materials:**

|Brand/Manufacturer|Part Name|Supplier|Part/Model Number|Quantity|Individual Price|Total|
|----|-----------|-----------|------------|--------|----------------|-----|
|Arduino|Bluetooth Board|Arduino|Nano 33 IoT|1|$25.50|$25.50|
|LAMPVPATH|4 AA Battery Holder|Amazon|B07L9M6VZK|1|$7.49|$7.49|
|Duracell|AA Batteries|Amazon|DURMN1500B10Z|1|$8.79|$8.79|
|DIYmore|Water Level Sensor|DIYmore|JSN-SR04T|1|$12.99|$12.99|
|Polycase|Enclosure|Polycase|SK-18 Enclosure with Knockouts 5.12 x 3.70 x 2.24 in|1|$20.92|$20.92|
|Polycase|Cable Gland|Ploycase|CG3 Gray Cable Glands 1.53 x 1.19 x 1.19in|1|$2.86|$2.86|
|Qunqi|Breadboard|Amazon|Qunqi 400 tie Point Experiment Mini Breadboard 5.5×8.2×0.85cm|1|$5.99|$5.99|
|Madison Mill|Dowel|Lowes|Madison Mill 0.75-in dia x 36-in L Square Poplar Dowel|2|$3.98|$7.96|
|Tin-N-Lock|Ziptiews|Amazon|Tie-N-Lock 8" Heavy Duty Nylon Cable Ties, 50 lb Test, 100 PC, Black|1|$1.21|$1.21|
| Nisshinbo | 6V dc to dc converter | Arrow.com | R1210N601D-TR-FE | 5 | $0.48 | $2.39 |

**References**

[1] “Arduino Low Power - Arduino Reference,” www.arduino.cc, Nov. 08, 2023).
‌<https://www.arduino.cc/reference/en/libraries/arduino-low-power/>

[2] O. Staquet, "Arduino-Nano-33-IoT-Ultimate-Guide," github.com [Online]. Available: https://github.com/ostaquet/Arduino-Nano-33-IoT-Ultimate-Guide/blob/master/SavePowerSleeping.md. [Accessed Feb. 14, 2024].

[3] PowerStream. "Discharge tests of AA Batteries, Alkaline and NiMH". (Feb. 7, 2023). Accessed: Mar. 7, 2024. [online]. Available: https://www.powerstream.com/AA-tests.htm
