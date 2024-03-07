# *Detail Design: Nutrient Controller*
## **Function of the Subsystem:**
The function of this subsystem is to monitor the concentration of nutrients in the soil,
the pH balance of the soil, and the hydration level of the soil. This 
subsystem will use a sensor to detect hydration, pH balance, and nutrient concentration of the soil and relay that information to the 
PLC's Nano 33 IoT via BLE connection and then to the PLC itself via an ethernet cable from the connected Nano 33 IoT.
## **Constraints:**
- **Arduino Nano 33 IoT**

  1. The communication between the sensors and PLC must be wireless. This will save time and money on wiring, while also allowing the system to be scalable, meaning if the greenhouse was to be expanded then this subsystem would be easily expanded to account for more plants.
  2. The transfer of data between the sensors and the Arduino must be below 3 seconds for accurate and reliable monitoring of the different nutrient levels in the soil as well as the soil hydration and pH balance, and to allow plenty of time for communication with the PLC while looping in and out of sleep mode.
  3. 	The system needs to be capable of wirelessly communicating the collected data back to the PLC in an inexpensive, yet reliable way.
  4. 	The Arduino must support serial communication between itself and the rs485 translator.

- **Soil NPK and Moisture Sensor - CWT-SOIL-NPKPHCTH-S**

  1. The CWT-SOIL-NPKPHCTH-S needs between 4.5-30V to operate effectively.
  2. The sensor must turn on every 5 minutes in order to measure NPK levels, soil moisture, and pH balance.
  3. Must accurately measure soil moisture in a range of 0-100% to allow for optimum plant growth with ±3% to ±5% accuracy.
  4. Must accurately measure nitrogen levels in the soil within a range of 50-300mg/kg to allow for optimum plant growth with no more than ±10% accuracy. [1]
  5. Must accurately measure phosphorous levels in the soil within a range of 5-90mg/kg with no more than ±10% accuracy. [1]
  6. Must accurately measure potassium levels in the soil within a range of 50-240mg/kg with no more than ±10% accuracy. [1]
  7. Must accurately measure soil pH levels within a range of 5-8.5pH with an accuracy of ±0.01 pH to ±0.5 pH. [1]

## **Buildable Schematic:**
![Nutrient Schematic](https://github.com/RealityHertz/Greenhouse-Project/blob/main/Documentation/Images/Nutrient_Schematic_V7.png)

*Figure 1. Buildable Schematic for Powering Arduino and Sensors*

## **Analysis:**
- **Arduino Nano 33 IoT**
  
   1. The Arduino will communicate with the sensors via a serial connection through the UXCELL Max485 translator and then to the plc via a seperate connected Nano 33 IoT which will be communicated with through BLE.
   2. The Ardiuno will need to be cycled in and out of sleep mode to conserve battery life. This will be done by using the Arduino-Libraries Github and use the provided files and functions in the ArduinoLowPower folder. For example, we can use the function LowPower.sleep() and input the amount of time we want it to sleep in ms. Implementing this in a loop will then allow the microcontroller to continuously fall asleep and wake up for the desired time. We have decided to do a system where the Ardiuno runs for 10 seconds for every 5 minutes. [2]
   3. Using Bluetooth Low Energy (BLE) allows for a cost efficient manner to transmit data throughout the greenhouse. A disadvantage of BLE is the decreased distance that information can be transmitted. Most BLE devices can trasmit/recieve data at a max rate of 50 meters [3]. However, the distance between the Arduino and the PLC will only be 15 feet, or 4.57 meters.
   4. The Arduino Nano 33 IoT contains both USART Rx and Tx pins, connected as shown in the figure above, to support the serial connection to the rs485 translator.
 
- **Soil NPK and Moisture Sensor - CWT-SOIL-NPKPHCTH-S**
   1. The sensor will be supplied 5V from the Arduino pin 12, which provides a 5V output, this will allow the sensor to be enabled and disabled as the Arduino cycles through sleep cycles.
   2. The sensor has a response time of less than 1 second and it will be enabled for 10 seconds every 5 minutes to allow the system time to commumicate with the PLC.
   4. The sensor measures soil moisture with a range of 0-100% with an accuracy of ±2% within the 0-50% moisture range and ±3% within the 50-100% range and a resolution of 0.10%.
   5. The sensor measures nitrogen levels within a range of 1-1999mg/kg with an accuracy of ±2% full scale and a resolution of 1mg/kg.
   6. The sensor measures phosphorus levels within a range of 1-1999mg/kg with an accuracy of ±2% full scale and a resolution of 1mg/kg.
   7. The sensor measures potassium levels within a range of 1-1999mg/kg with an accuracy of ±2% full scale and a resolution of 1mg/kg.
   8. The sensor measures pH within a range of 3-9pH with an accuracy of ±0.3pH and a resolution of 0.01pH.

- **DC to DC Converter - Nisshinbo R1210N601D-TR-FE**
  
   1. The converter takes an input voltage range of 0.8-8V and produces a constant output of 6V ±0.15V.
   2. This is within the range of input voltage for the Arduino Nano 33 IoT and reduces the risk of having too little voltage for the Arduino as the battery charges dissipate.
   3. Since the minimum input voltage of the converter is 0.8V this means that the system will be able to operate until the power supply voltage drops below 0.2V per battery which means that roughly ((1.5V-0.2V)/1.5V) = 0.867 or 86.7% of the individual battery's supply is used before needing to be replaced.
 
- **Power Analysis**
  
    1. The power is routed through the Arduino so that the sensor may be cycled on and off as the Nano 33 IOT enters and exits sleep mode, while the Arduino is in sleep mode it does not produce a high enough voltage for any of the systems components to function so they are all essentially powered off.[4]
    2. The Arduino will be cycled out of sleep mode for 10 seconds every 5 minutes leading to the sensors using (10s/3600s) for the milliwatt hour calculations, or 10 seconds per hour, and (5min/60min) for the average power consumption calculations from the 5 minute cycle.
    3. The system is powered by 4 AA batteries each supplying 3500mAh and 1.5V.
    4. The uxcell MAX485 has a current draw of <5ma at 5V.
    5. The CWT-SOIL-NPKPHCTH-S has a max power usage of 500mW at 24V giving us (500mw/24V) = 20.83mA usage which in turn would give us a maximum power usage of (20.83mA x 5V) = 104.17mW at 5V when used continuously [5].
    6. The Nisshinbo R1210N601D-TR-FE uses 0.09mA at 6V.
    7. The R1210N601D-TR-FE would use (6V * 0.09mA) = 0.54mW.
    8. As shown in the figure below, since the system only uses a total of 28mA + 5mA + 20.83mA + 0.09mA = 53.92mA the batteries should last significantly longer than the shown dropoff of 2.2Ah.
  ![Battery Dropoff](https://github.com/RealityHertz/Greenhouse-Project/blob/main/Documentation/Images/AA-100mA.png)

*Figure 2. Duracell(DC) vs. Radio Shack(RS) AA battery voltage dropoff at 100mA current draw*

*Source: Adapted from [6]*
    
| Component | Current Draw @ 5V | MilliWatt Hours (10 seconds on) | Average Power Consumption (5 minute cycle) |
| :--- | :--- | :--- | :--- |
| Arduino Nano 33 IoT | 28mA | (28mA * 5V) * (10s/3600s) = 0.389mWh | (0.389mWh) / (5min/60min) = 4.67mW |
| Uxcell MAX485 | 5mA | (5mA * 5V) * (10s/3600s) = 0.0694mWh | (0.0694mWh) / (5min/60min) = 0.833mW |
| CWT-SOIL-NPKPHCTH-S | 20.83mA | (20.83mA * 5V) * (10s/3600s) = 0.289mWh | (0.389mWh) / (5min/60min) = 3.47mW |

| Battery MilliWatt Hours | Total Average Power Consumption | Time Until Battery Change |
| :--- | :--- | :---|
| (1.5V * 4 Batteries) * 3500mAh = 21,000mWh | 4.67mW + 0.833mW + 3.47mW + 0.54mW = 9.515mW | 21,000mWh / 9.515mW = 2,207.04 hours or 3.07 months|

 
## **Bill of Materials:**
| Brand/Manufacturer | Part Name | Supplier | Part/Model Number | Quantity | Units | Unit Cost | Cost |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| Arduino | Blue-tooth board | Arduino | Nano 33 IoT | 1 | 1 | $25.50 | $25.50 |
| ComWinTop | 7 in 1 Soil Probe | ComWinTop | CWT-SOIL-NPKPHCTH-S | 1 | 1 | $81.39 | $81.39 |
| Uxcell | RS485 Instrument Interface Module | Amazon | MAX485 TTL | 1 | 1 | $6.99 | $6.99 |
| LAMPVPATH | 4 AA Battery Holder | Amazon | B07L9M6VZK | 1 | 2 | $7.49 | $7.49 |
| Duracell | AA Batteries | Amazon | DURMN1500B10Z | 1 | 10 | $8.79 | $8.79 |
| Nisshinbo | 6V dc to dc converter | Arrow.com | R1210N601D-TR-FE | 5 | 5 | $0.48 | $2.39 |

## **References:**

[1] L.-Z. Liang et al., ‘Excessive application of nitrogen and phosphorus fertilizers induces soil acidification and phosphorus enrichment during vegetable production in Yangtze River Delta, China’, Soil Use and Management, vol. 29, 06 2013.

[2] “Arduino Low Power - Arduino Reference,” www.arduino.cc, Nov. 08, 2023).
‌<https://www.arduino.cc/reference/en/libraries/arduino-low-power/>

[3] “Advantages of BLE (Bluetooth Low Energy) | disadvantages of BLE (Bluetooth Low Energy),” www.rfwireless-world.com. https://www.rfwireless-world.com/Terminology/Advantages-and-Disadvantages-of-BLE-Bluetooth-Low-Energy.html

[4] O. Staquet, "Arduino-Nano-33-IoT-Ultimate-Guide," github.com [Online]. Available: https://github.com/ostaquet/Arduino-Nano-33-IoT-Ultimate-Guide/blob/master/SavePowerSleeping.md. [Accessed Feb. 14, 2024].

[5] ComWinTop, "RS485 4-20mA Soil Temperature Humidity Moisture Conductivity EC PH Sensor", ComWinTop, https://store.comwintop.com/products/rs485-4-20ma-soil-temperature-humidity-moisture-conductivity-ec-ph-sensor?variant=43435240358115

[6] PowerStream. "Discharge tests of AA Batteries, Alkaline and NiMH". (Feb. 7, 2023). Accessed: Mar. 7, 2024. [online]. Available: https://www.powerstream.com/AA-tests.htm
