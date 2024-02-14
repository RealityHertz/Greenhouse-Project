# *Detail Design: Nutrient Controller*
## **Function of the Subsystem:**
The function of this subsystem is to monitor the concentration of nutrients in the soil,
the pH balance of the soil, the hydration level of the soil, the level of water in the water tanks,
fill a local reservoir with water for manual watering and regulate the plant watering cycle. This 
subsystem will use an array of sensors to detect the level of water in the tanks as well as the 
hydration, pH balance, and nutrient concentration of the soil and relay that information to the 
communications application via Bluetooth connection. This system will also use a pump and a 
timer to fill a local reserve tank and regulate the watering cycle of plants.
## **Constraints:**
- **Arduino Nano 33 IoT**

  1. The communication between the sensors and PLC must be wireless. This will save time and money on wiring, while also allowing the system to be scalable, meaning if the greenhouse was to be expanded then this subsystem would be easily expanded to account for more plants.
  2. The transfer of data between the sensors and the Arduino must be below 3 seconds for accurate and reliable monitoring of the different nutrient levels in the soil as well as the soil hydration and pH balance, and to allow plenty of time for communication with the PLC while looping in and out of sleep mode.
  3. 	The system needs to be capable of wirelessly communicating the collected data back to the PLC in an inexpensive, yet reliable way.
  4. 	The Arduino must support serial communication between itself and the rs485 translator.

- **Soil NPK and Moisture Sensor - Anggrek RS485**

  1. The anggrek rs485 needs between 12-24V to operate effectively.
  2. The sensor must turn on every 5 minutes in order to measure NPK levels, soil moisture, and pH balance.
  3. Must accurately measure soil moisture in a range of 0-100% to allow for optimum plant growth with ±3% to ±5% accuracy.
  4. Must accurately measure nitrogen levels in the soil within a range of 50-300mg/kg to allow for optimum plant growth with no more than ±10% accuracy. [1]
  5. Must accurately measure phosphorous levels in the soil within a range of 5-90mg/kg with no more than ±10% accuracy. [1]
  6. Must accurately measure potassium levels in the soil within a range of 50-240mg/kg with no more than ±10% accuracy. [1]
  7. Must accurately measure soil pH levels within a range of 5-8.5pH with an accuracy of ±0.01 pH to ±0.5 pH. [1]

- **Voltage Regulator - Murata CMR0515S3C**

  1. The regulator shall be able to increase the voltage from the source of 5V to a voltage within the range of 12-24V to power the sensor.
  2. The regulator shall be enabled at the start of the system in order to power the sensor.

## **Buildable Schematic:**
![Nutrient Schematic](https://github.com/RealityHertz/Greenhouse-Project/blob/main/Documentation/Images/Nutrient_Schematic_V5.png)

*Figure 1. Buildable Schematic for Powering Arduino and Sensors*

## **Analysis:**
- **Arduino Nano 33 IoT**
  
   1. The Arduino's BLE capabilities could be broadened by using an array of bluetooth extenders if required for larger projects.
   2. The Ardiuno will need to be cycled in and out of sleep mode to conserve battery life. This will be done by using the Arduino-Libraries Github and use the provided files and functions in the ArduinoLowPower folder. For example, we can use the function LowPower.sleep() and input the amount of time we want it to sleep in ms. Implementing this in a loop will then allow the microcontroller to continuously fall asleep and wake up for the desired time. We have decided to do a system where the Ardiuno runs for 10 seconds for every 5 minutes. [2]
   3. BLE (Bluetooth Low Energy) is lower in cost than the classic Bluetooth as BLE is currently rising in use and has market competition. BLE decreases the distance a signal can be transmitted, but the signals transmitted through the greenhouse will not be far apart. The use of BLE allows for a cost-eﬃcient alternative compared to standard Bluetooth.
   4. The Arduino Nano 33 IoT contains both USART Rx and Tx pins, connected as shown in the figure above, to support the serial connection to the rs485 translator.
 
- **Soil NPK and Moisture Sensor - Anggrek RS485**
   1. The sensor will be supplied 15V from the Arduino pin 12 which provides a 5V output and will be passed through the pololu step-up regulator to produce the required 15V this will allow the sensor to be enabled and disabled as the Arduino cycles through sleep cycles.
   2. The sensor has a response time of less than 1 second and it will be enabled for 10 seconds every 5 minutes to allow the system time to commumicate with the PLC.
   3. The sensor measures soil moisture with a range of 0-100% with an accuracy of ±3% within the 0-53% moisture range and ±5% within the 53-100% range and a resolution of 0.10%.
   4. The sensor measures nitrogen levels within a range of 0-1999mg/kg with an accuracy of ±2% full scale and a resolution of 1mg/kg.
   5. The sensor measures phosphorus levels within a range of 0-1999mg/kg with an accuracy of ±2% full scale and a resolution of 1mg/kg.
   6. The sensor measures potassium levels within a range of 0-1999mg/kg with an accuracy of ±2% full scale and a resolution of 1mg/kg.
   7. The sensor measures pH within a range of 3-9pH with an accuracy of ±0.3pH and a resolution of 0.01pH.
 
- **Power Supply for Anggrek RS485**
    1. The sensor requires a 12-24VDC power supply to operate.
    2. The Arduino will send a 5V signal through its 5V output pin to the Pololu U3V70F15 step-up voltage regulator to provide a constant 15VDC ±4% input for the sensor.
    3. The power is routed through the Arduino so that the sensor may be cycled on and off as the Nano 33 IOT enters and exits sleep mode, while the Arduino is in sleep mode it does not produce a high enough voltage for any of the systems components to function so they are all essentially turned off.[3]
    4. The murata CMR0515S3C has a current draw of 188mA at 5V.
    5. The murata would use (188mA x 5V) x (10s / 3600s) = 2.611mWh leading to an average power of 2.611mWh / (5min/60min) = 31.33mW.
    6. The system is powered by 4 AA batteries each supplying 3500mAh and 1.5V.
    7. This provides a total of (1.5Vx4)x3500mAh = 21,000mWh.
    8. The Arduino uses (28mA x 5V) x (10s/3600s) = 0.389mWh when active and (6mA x 5V) x (10s/3600s) = 0.0833mWh when in sleep mode, this leads to an average power consumption of (0.389mWh / (5min/60min)) + (0.0833mWh / (5min/60min)) = 5.33mW.
    9. The uxcell MAX485 has a current draw of <5ma at 5V.
    10. The uxcell MAX485 would use (5mA x 5V) x (10s/3600s) = 0.0694mWh leading to an average power of 0.0694mWh / (5min/60min) = 0.833mW
    11. The Anggrek RS485 has a current draw of 6mA at 5V.
    12. The Anggrek RS485 would use (6mA x 5V) x (10s/3600s) = 0.0833mWh leading to an averge power of 0.0833mWh / (5min/60min) = 1.000mW
    13. This results in a total power usage of 31.33 + 5.33 + 0.833 + 1.00 = 38.493 mW.
    14. This means the batteries will last (21,000mWh / 28.493 mw) = 545.55 hours or 22.73 days.
 
- **Voltage Regulator - Murata CMR0515S3C**
   1. The regulator takes an input voltage of range 5V with an input current of 188mA and produces a constant 15VDC output with 79% effeciency.
   2. The regulator is wired to be enabled by default as soon as it is powered.
  
## **Bill of Materials:**
| Brand/Manufacturer | Part Name | Supplier | Part/Model Number | Quantity | Units | Unit Cost | Cost |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| Arduino | Blue-tooth board | Arduino | Nano 33 IoT | 1 | 1 | $25.50 | $25.50 |
| ANGGREK | Soil NPK Sensor | Walmart | ANGGREK RS485 | 1 | 1 | $78.51 | $78.51 |
| Uxcell | RS495 Instrument Interface Module | Amazon | MAX485 TTL | 1 | 1 | $6.99 | $6.99 |
| LAMPVPATH | 4 AA Battery Holder | Amazon | B07L9M6VZK | 1 | 2 | $7.49 | $7.49 |
| Duracell | AA Batteries | Amazon | DURMN1500B10Z | 1 | 10 | $8.79 | $8.79 |
| Murata | Step-Up Voltage Regulator | Digikey | CMR0515S3C | 1 | 1 | $3.30 | $3.30 |

## **References:**

[1] L.-Z. Liang et al., ‘Excessive application of nitrogen and phosphorus fertilizers induces soil acidification and phosphorus enrichment during vegetable production in Yangtze River Delta, China’, Soil Use and Management, vol. 29, 06 2013.

[2] “Arduino Low Power - Arduino Reference,” www.arduino.cc, Nov. 08, 2023).
‌<https://www.arduino.cc/reference/en/libraries/arduino-low-power/>

[3] O. Staquet, "Arduino-Nano-33-IoT-Ultimate-Guide," github.com [Online]. Available: https://github.com/ostaquet/Arduino-Nano-33-IoT-Ultimate-Guide/blob/master/SavePowerSleeping.md. [Accessed Feb. 14, 2024].
