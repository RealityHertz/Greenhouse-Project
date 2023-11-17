<a name="br1"></a> 

# *Detail Design: CO2 and NO2 Sensor*

## **Function of the Subsystem:**

  The function of this subsystem is to relay the CO<sub>2</sub> and NO<sub>2</sub> levels to the Arduino via their respective sensors. The subsystem will use a series of sensors to transfer the percentage levels of CO<sub>2</sub> and NO<sub>2</sub> in the air to the Arduino. The sensors will monitor the changes of the carbon dioxide and nitrogen dioxide levels in the greenhouse’s atmosphere and will report these numbers and changes to the Arduino.

## **Constraints:**

- **Carbon Dioxide Sensor – MH-Z19B**
  1. MH-Z19B needs between 4.5-5.5V and at least 20mA to operate eﬃciently.
  2. The sensor must turn on every 5 minutes to measure the amount of carbon dioxide present in the greenhouse.
  3. Must alert the communications applications when above or below 400-2000ppm to ensure proper plant growth. [1]

- **Arduino Nano 33 IoT**
  1. The communication between the sensors and PLC must be wireless. This will save time and money on wiring, while also allowing the system to be scalable, meaning if the greenhouse was to be expanded then this subsystem would be easily expanded to account for more plants.
  2. The transfer of data between the sensors and the Arduino must be below 3 seconds for accurate and reliable monitoring of the CO<sub>2</sub> and NO<sub>2</sub> levels in the atmosphere and to allow plenty of time for communication with the PLC while looping in and out of sleep mode.
  3. The system needs to be capable of wirelessly communicating the collected data back to the PLC in an inexpensive, yet reliable way.


- **Nitrogen Dioxide Sensor – MIKROE-3700**
  1. MIKROE-3700 needs between 3.3-5V to operate efficiently.
  2. Must alert when above Nitrogen Dioxide level exceeds 9 ppb. [2]

## **Buildable Schematic:**

![Buildable Schematic CO2 and NO2](https://github.com/RealityHertz/Greenhouse-Project/blob/main/Documentation/Images/CADSchematicNitrogenSubsystem.jpg)

*Figure 1. Wiring Schematic for Power to Sensors*

![Arduino Nano 33](https://github.com/RealityHertz/Greenhouse-Project/blob/main/Documentation/Images/ArduinoNano33.png)

*Figure 2. Arduino Nano 33 IoT Board Topology*

## **Analysis:**

- **Carbon Dioxide Sensor – MH-Z19B**
  1. The sensor will be supplied 5V from the AA battery pack.
  2. It will turn on for 10 seconds every 5 minutes, this gives the system enough time to send the data to the PLC.
  3. The sensor will be set with the detection range option of 400-2000ppm and will send alerts if carbon dioxide concentrations fall above or below that range.
     
  - **Power Supply for MH-Z19B**
    - The MH-Z19B will use Pin 4 connected to the Nano 33 IoT’s Pin 12 supplying 5 volts to the sensor.
    - MH-Z19B’s Pin 3 will be used as its ground and shall be connected to the Nano 33 IoT’s Pin 19, completing the power circuit, and powering the sensor.
    - The working voltage will be 4.5 ~ 5.5 V DC
    - Average Current < 20mA with a 5V power supply
    - Response Time of T<sub>90</sub> < 120 s
    - Working Humidity of 0 ~ 95% RH (No condensation)
    - The average current draw is 20mA
    - Therefore, the energy used during the "while on" mode is (20mA x 5V) x (10s / 3600s) = .028mWh
    - The average power drawn is .028 / (5min / 60min) = .33mW

  - **Communication for MH-Z19B**
    - MH-Z19B will use Pin 5 for UART (Rx) TTL Level data input which will be connected to the Nano 33 IoT’s Pin 17 which is used as an USART Digital Rx
    - MH-Z19B will use Pin 6 for UART (Tx) TTL Level data input which will be connected to the Nano 33 IoT’s Pin 16 which is used as an USART Digital Tx
    - The Carbon Dioxide detection range consists of options 400-2000ppm, 400-5000ppm, or 400-10,000ppm. It has an accuracy of ±(50ppm+5% reading value)
    - PWM Output consists of the following:
      - Cycle of 1004ms±5%
      - Cycle start high level output of 2ms, theoretically.
      - Middle Cycle of 1000ms±5%
      - Cycle end high level output of 2ms, theoretically.

  ![PWM Graph](https://github.com/RealityHertz/Greenhouse-Project/blob/main/Documentation/Images/PPM.png)

- **Arduino Nano 33 IoT**
  1. The Arduino's BLE capabilities could be broadened by using an array of bluetooth extenders if required for larger projects.
  2. The Ardiuno will need to be cycled in and out of sleep mode to conserve battery life. This will be done by using the Arduino-Libraries Github and use the provided files and functions in the ArduinoLowPower folder. For example, we can use the function LowPower.sleep() and input the amount of time we want it to sleep in ms. Implementing this in a loop will then allow the microcontroller to continuously fall asleep and wake up for the desired time. We have decided to do a system where the Ardiuno runs for 10 seconds for every 5 minutes. [3]
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

- **CO<sub>2</sub> and NO<sub>2</sub> Levels**
    - The average concentration of CO<sub>2</sub> found in the atmosphere is around 400 parts per million (ppm), but greenhouses often produce greater concentrations. This is due to a greater plant yield at higher levels. If the level of CO<sub>2</sub> in the greenhouse is between 400-2000 ppm, the plants are able to have a greater increase in growth. However, any ranges outside of these parameters result in a negative growth rate for the plants. [4]
    - According to the CDC, anything over 5ppm is considered dangerous for an extended period of time. [2]

- **MIKROE-3700**
  1. The sensor will receive an input voltage of 3.3V from the Arduino's output pin which is within the sensor's operating voltage range.
  2. In order to use the 12-bit ADC, which is the output of the sensor, a reference voltage of 3.3V will need to be used for calibration. We can use the following equation, V = ( D / 2^12 -1) x Vref. This is the analog voltage to digital value formula to compute that a digital value of .009 will be approximately 7.62mV. This signal will alert the Arduino of unsafe Nitrogen Dioxide levels. 
     
  - **Power Supply for MIKROE-3700**
    - The MIKROE-3700 will use Pin 10 connected to the Nano 33 IoT’s Pin 2 as a 3.3V power supply. This will run through a 10k ohm and 20k ohm voltage divider to ensure the voltage level is brought down.
    - MIKROE-3700’s Pin 8 will be connected to the Nano 33 IoT’s Pin 19 as a ground to complete the power circuit and be able to supply the 3.3V needed.
    - The measurement range has a minimum of 0ppm and a maximum of 10ppm.
    - The response time is 200s.
    - Operating Humidity Range is 5 ~ 95% RH (No condensation).
    - The time the sensor will be on is 10 seconds every 5 minutes
    - The average current draw is .5mA
    - Therefore, the energy used during the "while on" mode is (.5mA x 5V) x (10s / 3600s) = .0069mWh
    - The average power is .0069 / (5min / 60min) = .0828mW

  - **Communication for MIKROE-3700**
    - The MIKROE-3700’s Pin 5 will be used as a SPI Data Out connected to the Nano 33 IoT’s Pin 30 which is used as a Digital SPI MISO.
    - The MIKROE-3700’s Pin 4 will be used as a SPI Clock connected to the Nano 33 IoT’s Pin 11 which is used as a signal sent to mimic a clock and when to grab the data.
   
- **Silicon Conformal Coating**
  - Service temperature range of -40-200℃
  - Resistivity of 3.5 x 1013 Ω·cm
  - Drying time of 15 minutes for 2 coats
  - Will be used to keep electrical components safe from water

## **Bill of Materials**
|Brand/Manufacturer|Part Name|Supplier|Part/Model Number|Quantity|Individual Price|Total|
|----|-----------|-----------|------------|--------|----------------|-----|
|MikroElektronika|NO2 Sensor|DigiKey|1471-MIKROE-3700-ND|1|$39.00|$39.00|
|MiZOELEC|CO2 Sensor|Amazon|MH-Z19B|1|$35.00|$35.00|
|Arduino|Bluetooth Board|Arduino|Nano 33 IoT|1|$25.50|$25.50|
|MG Chemicals|Silicon Conformal Coating|DigiKey|422C-55MLCA|1|$23.94|$23.94|
|LAMPVPATH|4 AA Battery Holder|Amazon|B07L9M6VZK|1|$7.49|$7.49|
|Duracell|AA Batteries|Amazon|DURMN1500B10Z|1|$8.79|$8.79|

**References**

[1]“Supplemental carbon dioxide in greenhouses | ontario.ca,” www.ontario.ca. https://www.ontario.ca/page/supplemental-carbon-dioxide-greenhouses#:~:text=A%20typical%20greenhouse%20with%20a (accessed Nov. 09, 2023).
‌

[2] Q. Sheng and Z. Zhu, “Effects of Nitrogen Dioxide on Biochemical Responses in 41 Garden Plants,” Plants, vol. 8, no. 2, p. 45, Feb. 2019, doi: https://doi.org/10.3390/plants8020045.
‌

[3] “Arduino Low Power - Arduino Reference,” www.arduino.cc, Nov. 08, 2023).
‌<https://www.arduino.cc/reference/en/libraries/arduino-low-power/>

[4] “Greenhouse Carbon Dioxide Supplementation - Oklahoma State University,” extension.okstate.edu. 
<https://extension.okstate.edu/fact-sheets/greenhouse-carbon-dioxide-supplementation.html>


